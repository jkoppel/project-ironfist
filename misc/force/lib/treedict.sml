functor TreeDict (K : ORDERED) : FINITE_DICT =
struct

  structure Key = K

  (* Invariant: BST *)
  datatype ('k, 'v) tree =
    Leaf
  | Node of ('k, 'v) tree * ('k * 'v) * ('k, 'v) tree

  type 'v dict = (Key.t, 'v) tree

  val empty = Leaf

  fun insert d (k, v) =
      case d of
          Leaf => Node (empty, (k, v), empty)
        | Node (L, (k', v'), R) =>
          case Key.compare (k, k') of
              EQUAL => Node (L, (k, v), R)
            | LESS => Node (insert L (k, v), (k', v'), R)
            | GREATER => Node (L, (k', v'), insert R (k, v))

  fun lookup d k =
      case d of
          Leaf => NONE
        | Node (L, (k', v'), R) =>
          case Key.compare (k, k') of
              EQUAL => SOME v'
            | LESS => lookup L k
            | GREATER => lookup R k
  local
    fun rightmost (T : ('k, 'v) tree) : (('k * 'v) * ('k, 'v) tree) option =
        case T of
            Leaf => NONE
          | Node (L, (k, v), R) =>
            case rightmost R of
                NONE => SOME ((k, v), L)
              | SOME (p, R') => SOME (p, Node (L, (k, v), R'))
  in
    fun remove d k =
        case d of
            Leaf => Leaf
          | Node (L, (k', v'), R) =>
            (case Key.compare (k, k') of
                 EQUAL =>
                 (case rightmost L of
                      NONE => R
                    | SOME ((kr, vr), L') => Node (L', (kr, vr), R))
               | LESS => Node (remove L k, (k', v'), R)
               | GREATER => Node (L, (k', v'), remove R k))
  end

  fun toList d =
    case d of
      Leaf => []
    | Node (L, kv, R) => (toList L) @ (kv :: (toList R))

  fun fromList l = foldr (fn (x, s) => insert s x) empty l

  fun map f t =
    case t of
      Leaf => Leaf
    | Node (left, (k, v), right) =>
        Node (map f left, (k, f v), map f right)

  fun keymap f t =
    case t of
      Leaf => Leaf
    | Node (left, (k, v), right) =>
        Node (keymap f left, (f k, v), keymap f right)
      

end
