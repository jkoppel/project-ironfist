signature GRAPH_EDGE =
sig

  structure Node : ORDERED

  type t

  val compare : t * t -> order
  val makeEdge : Node.t * Node.t -> t
  val succEdge : t -> Node.t -> Node.t option

end


functor GraphFn (Edge : GRAPH_EDGE)
  : FINITE_GRAPH where type node = Edge.Node.t =
struct

  open Edge

  structure NodeSet = DictSet (Node)
  structure EdgeSet = DictSet (Edge)

  type node = Node.t
  type edge = Edge.t

  type graph = NodeSet.set * EdgeSet.set
            (* all nodes,    all edges *)

  fun nodes (ns, _) = NodeSet.toList ns
  fun edges (_, es) = EdgeSet.toList es

  (*
    Inputs: a graph and a pair of nodes
    Returns: a graph with the edge representing that pair of nodes in it.
    Assumptions: both nodes in the pair are already in the graph.
  *)
  fun addEdge (ns, es) e =
    let
      val e' = makeEdge e
    in
      (ns, EdgeSet.insert es e')
    end

  fun addNode (ns, es) n = (NodeSet.insert ns n, es)

  fun containsEdge (_, es) e = EdgeSet.member es (makeEdge e)

  fun containsNode (ns, _) n = NodeSet.member ns n

  fun successors (ns, es) n =
    let
      val edgeList = EdgeSet.toList es
      val nodesFromHere =
        List.mapPartial (fn e => succEdge e n) edgeList
    in
      nodesFromHere
    end

  fun graph ns es =
    (NodeSet.fromList ns, EdgeSet.fromList (List.map makeEdge es))

  fun map f (ns, es) = (NodeSet.map f ns, es)

end
