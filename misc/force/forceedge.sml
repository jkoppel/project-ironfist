signature FORCE_GRAPH_ARGS =
sig
  type p
  type gen
end

functor ForceEdgeFn (FGA : FORCE_GRAPH_ARGS)
  : GRAPH_EDGE where type Node.t = int * (int * FGA.gen * FGA.p) =
struct

  open FGA

  (*
    Keep a unique identifier, then the amount of resource, whether you're a
    generator, and the player controlling the node
  *)

  fun nodecomp ((n1, _), (n2, _)) = Int.compare (n1, n2)

  structure Node =
  struct
    type t = int * (int * gen * p)
    val compare = nodecomp
  end

  type node = Node.t
  type t = node * node (* Left edge always leq right edge *)

  fun makeEdge ((n1 : Node.t), (n2 : Node.t)) : t =
    case Node.compare (n1, n2) of
      GREATER => (n2, n1)
    | _ => (n1, n2)

  fun compare ((n11, n12), (n21, n22)) = 
    case (nodecomp (n11, n21), nodecomp (n12, n22)) of
      (EQUAL, EQUAL) => EQUAL
    | (EQUAL, o2) => o2
    | (o1, _) => o1

  fun succEdge (n1, n2) n =
    case nodecomp (n, n1) of
      EQUAL => SOME n2
    | LESS => NONE (* short-circuit *)
    | GREATER =>
        case nodecomp (n, n2) of
          EQUAL => SOME n1
        | _ => NONE

end
