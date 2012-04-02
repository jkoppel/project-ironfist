signature FINITE_DICT =
sig

  structure Key : ORDERED
  type 'v dict

  val empty  : 'v dict
  val insert : 'v dict -> (Key.t * 'v) -> 'v dict
  val lookup : 'v dict -> Key.t -> 'v option
  val remove : 'v dict -> Key.t -> 'v dict

  val toList : 'v dict -> (Key.t * 'v) list
  val fromList : (Key.t * 'v) list -> 'v dict

  val map : ('a -> 'b) -> 'a dict -> 'b dict
  val keymap : (Key.t -> Key.t) -> 'a dict -> 'a dict
end
