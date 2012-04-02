structure ForceEdgeArg =
struct
  datatype player = Minnie | Maxie
  type p = player option
  type gen = bool
end

structure ForceEdge = ForceEdgeFn (ForceEdgeArg)
structure ForceGraph = GraphFn (ForceEdge)

signature FORCE_ARGS =
sig

  val f : int * int -> int
  val start_graph : ForceGraph.graph

end

structure Default_Args : FORCE_ARGS =
struct

  fun f (m,n) = m - (n * n) div m
  val start_graph = ForceGraph.graph [] [] (* empty for now because I am lazy *)

end

(*

  "And then places r counters on a force generator of his color"

  Does that mean you choose one generator and put them there? Or can you
  distribute them among your generators as you choose?

  Allowing for flying units is possible, but requires a more sophisticated
  graph interface. Same with taking terrain/unit bonuses into account - have a
  function from nodes to units to power, for example.

  Actually, tweaks like that should only be a small addition to the graph 
  library now that I used, uh, abstraction. Right now, it can represent graphs
  (directed or nondirected) with unlabeled edges, but it shouldn't be too hard
  to functorize over a label set, too.

*)

functor Force (A : FORCE_ARGS) : GAME =
struct

  open ForceEdgeArg
  datatype status = Over of player option | In_play
  datatype estimate = Winner of player | Guess of IntInf.int

  structure NodeMap = TreeDict (ForceEdge.Node)

  open A
  open ForceGraph

  type state = graph * player
  type move = (int * node * node) list * node 
              (* mode x units from n1 to n2, then regenerate on n3 *)

  fun upto x y = if x = y then [x] else x :: (upto (x + 1) y)

  fun vfilter p = Vector.foldr (fn (x, acc) => if p x then x :: acc else acc) []

  fun lflatten l = List.foldr (op @) [] l

  (* All lists of length l that sum to n *)
  fun lists_of_sum 0 n = [] (* makes my life easier *)
    | lists_of_sum 1 n = [[n]]
    | lists_of_sum l n =
        List.foldr (op @) []
          (List.map
            (fn x => List.map
                      (fn l' => x :: l')
                      (lists_of_sum (l - 1) (n - x)))
            (upto 0 n))

  val start = (start_graph, Minnie)

  fun player (_, p) = p

  fun switch_player Minnie = Maxie
    | switch_player Maxie = Minnie
  
  fun mem x [] = false
    | mem x (y :: L) = x = y orelse mem x L

  (* XXX: uses of lflatten in here are dubious! *)

  fun moves ((g, p) : state) : move list =
    let
      fun moves_from_node (n : node as (_, (res, gen, p')), ms) =
        case p' of
          NONE => ms
        | SOME p'' =>
            case p'' = p of
              false => ms
            | true => (* we can move stuff from here! *)
                let
                  val succs = successors g n
                  val dists = lists_of_sum (List.length succs) res
                  val dists' = List.map (fn l => ListPair.zip (l, succs)) dists
                  val dists'' = (* all possible displacements from here *)
                    List.map (List.map (fn (x, n2) => (x, n, n2))) dists'
                  val dists'' = (* get rid of trivial displacements *)
                    List.map (List.filter (fn (x, _, _) => x <> 0)) dists''
                in
                  (lflatten
                    (List.map
                      (fn d => List.map
                                  (fn m => d @ m)
                                  ms)
                      dists''))
                  @ ms
                end

      val gnodes = nodes g

      val gens =
        List.mapPartial
          (fn n as (_, (_, true,  _)) => SOME n
            | n as (_, (_, false, _)) => NONE)
          gnodes
        
      val all_displacements = List.foldr moves_from_node [] gnodes
    in
      lflatten (List.map (fn g => List.map (fn d => (d, g)) all_displacements) gens)
    end

  (* Check to make sure a move is valid *)
  (* TODO: need to make sure *total* of the move is less than the thing *)
  fun valid_move (g, p) (ms, regen) =
    let
      fun valid_relocation [] = true
        | valid_relocation ((x, n1, n2) :: ms) =
            (let
              val (_, (res1, _, owner1)) = n1
              val (_, (res2, _, owner2)) = n2
            in
              mem n2 (successors g n1)    andalso
              x <= res1           andalso
              valid_relocation ms
            end)
              handle Subscript => false

      val regen_player =
        let
          val (_, is_gen, p) = regen
        in
          if is_gen then SOME p else NONE
        end
    in
      case regen_player of
        NONE => false
      | SOME p' => p' = p andalso valid_relocation ms
    end

  (*
    Precondition for make_move (s, m) is valid_move s m
    XXX: should we assume no self-loops in graph?
  *)

  fun make_move ((g, p) : state, (ms, regen) : move) : state =
    let
      val succ = successors g

      fun one_move_map ((x, n1, n2), moves_so_far) =
        let
          val n1res = NodeMap.lookup moves_so_far n1
          val n2res = NodeMap.lookup moves_so_far n2

          val n1new =
            case n1res of
              NONE => ~x
            | SOME x' => x' - x

          val n2new =
            case n1res of
              NONE => x
            | SOME x' => x' + x
        in
          NodeMap.insert
            (NodeMap.insert moves_so_far (n1, n1new)) (n2, n2new)
        end

      val total_move = List.foldl one_move_map NodeMap.empty ms

      fun resolve_conflict (s as (i, (res, gen, p'))) =
        case NodeMap.lookup total_move s of
          NONE => s (* nothing was changed *)
        | SOME x => (* things were moved to/away from here! *)
            (i, case (SOME p = p') of
              true => (res + x, gen, p')
            | false =>
                case Int.compare (x, res) of
                  EQUAL => (0, gen, p')
                | GREATER => (f (x, res), gen, SOME p)
                | LESS => (f (res, x), gen, p'))
    in
       ((ForceGraph.map resolve_conflict g), switch_player p)
    end

  fun evaluate ((g, _) : state)= 
    case
      List.foldr
        (fn ((_, (x,_,p)), (m,n)) =>
          case p of
            NONE => (m,n)
          | SOME (Maxie) => (IntInf.+ (m, IntInf.fromInt x), n)
          | SOME (Minnie) => (m, IntInf.+ (n, IntInf.fromInt x)))
        (0,0)
        (ForceGraph.nodes g)
    of
      (0, x) => Winner (Minnie)
    | (x, 0) => Winner (Maxie)
    | (x, y) => Guess (IntInf.- (x, y))

  fun status s =
    case evaluate s of
      Winner p => Over (SOME p)
    | Guess _ => In_play


end
