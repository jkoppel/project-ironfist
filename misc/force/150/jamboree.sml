functor Jamboree (G : GAME) : PLAYER =
struct
  structure Game = G

  type value = real
  type alphabeta = value * value
  type edge = Game.move * value

  fun chooseBy prefer (x, y) = case prefer (x, y) of true => x | false => y

  (* returns whether x is at least as good an outcome as y for given player *)
  fun prefers player (x : value, y : value) : bool =
      case player
       of G.Minnie => x < y
        | G.Maxie => x > y

  fun preferredEdge player edges =
      chooseBy (fn ((_, val1), (_, val2)) => prefers player (val1, val2)) edges

  fun minmax player = chooseBy (prefers player)
  val min = minmax G.Minnie
  val max = minmax G.Maxie

  fun updateAB player (alpha, beta) value =
      case player
       of G.Minnie => (alpha, min (beta, value))
        | G.Maxie => (max (alpha, value), beta)

  (* tells us when we should prune *)
  fun cutoff ((alpha, beta) : alphabeta) = alpha >= beta

  val search_depth = 1

  fun seqReduce (f : 'a * 'a -> 'a) (x : 'a) (s : 'a Seq.seq) : 'a =
      case Seq.showl s of
          Seq.Nil => x
        | Seq.Cons (y, s') => f (y, seqReduce f x s')

  val minmove = fn player => seqReduce (preferredEdge player)

  fun evaluate (depth : int) (ab as (alpha, beta)) (state : G.state) : real =
      case (case depth of 0 => SOME (Game.evaluate state)
                           | _ => case G.status state of G.Over v => SOME v
                                                       | _ => NONE)
          of SOME v => v
           | NONE => case search (depth-1) ab state
                      of (move, value) => value

  and search (depth : int) (ab as (alpha, beta)) (state : Game.state) : edge =
      let val player = G.player state
          fun eval ab move = evaluate depth ab (G.make_move (state, move))
      in case Seq.showl (G.moves state)
          of Seq.Nil => raise Fail "no legal moves!"
           | Seq.Cons (move1, moves) =>
             let val move1_val = eval ab move1
                 val ab = updateAB player ab move1_val
             in case cutoff ab
                 of true => (move1, move1_val)
                  | false =>
                     seqReduce
                       (preferredEdge player)
                       (move1, move1_val)
                       (Seq.map (fn move => (move, eval ab move)) moves)
             end
      end 

  fun next_move state =
      let val (move, _) = search search_depth (Real.negInf, Real.posInf) state
      in move
      end
end
