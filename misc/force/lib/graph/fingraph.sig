(*
  TODO: All uses of 'list' here should probably be replaced with something more
  reasonable, like seq, vector, set, etc., but lists are easy to deal with and
  well-supported, so I'm going with them for now.
*)


signature FINITE_GRAPH =
sig

  type graph
  type node
  type edge

  val edges : graph -> edge list
  val nodes : graph -> node list

  val addEdge : graph -> (node * node) -> graph
  val addNode : graph -> node -> graph (* overwrites if already in *)

  val containsEdge : graph -> (node * node) -> bool
  val containsNode : graph -> node -> bool
  val successors   : graph -> node -> node list

  (* graph (nodes g) (edges g) should be equivalent to g *)

  val graph : node list -> (node * node) list -> graph

  (* Kind of a boring map, but handy *)
  val map : (node -> node) -> graph -> graph

end
