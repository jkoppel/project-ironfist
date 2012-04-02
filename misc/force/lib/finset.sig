signature FINITE_SET =
sig

  structure Elem : ORDERED
  
  type set

  val empty  : set
  val insert : set -> Elem.t -> set
  val remove : set -> Elem.t -> set
  val member : set -> Elem.t -> bool

  val toList   : set -> Elem.t list
  val fromList : Elem.t list -> set
  
  val map : (Elem.t -> Elem.t) -> set -> set

end
