functor DictSet (E : ORDERED) : FINITE_SET =
struct

  structure Elem = E
  structure D = TreeDict(E)

  type set = unit D.dict

  val empty = D.empty
  fun insert d e = D.insert d (e, ())
  fun member d e = Option.isSome (D.lookup d e)
  fun remove d e = D.remove d e

  fun toList d = List.map #1 (D.toList d)
  fun fromList l = D.fromList (List.map (fn x => (x, ())) l)

  fun map f d = D.keymap f d

end
