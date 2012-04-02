signature SEQUTILS =
sig
  (* assume sequence is non-empty; uses the first element as the nil case *)
  val reduce1 : ('a * 'a -> 'a) -> 'a Seq.seq -> 'a
  val look_and_say : ('a * 'a -> bool) -> 'a Seq.seq
                     -> (int * 'a) Seq.seq
end

structure SeqUtils : SEQUTILS =
struct
  fun reduce1 (c : 'a * 'a -> 'a) (s : 'a Seq.seq) : 'a =
      case (Seq.showl s)
       of Seq.Nil => raise Fail "applied reduce1 to an empty sequence"
        | Seq.Cons(x,xs) => Seq.reduce c x xs

  fun look_and_say (eq : 'a * 'a -> bool) (s : 'a Seq.seq)
      : (int * 'a) Seq.seq =
      let
        fun lasHelp (s : 'a Seq.seq, x : 'a, acc : int) : 'a Seq.seq * int =
            case Seq.showl s of
              Seq.Nil => (Seq.hidel Seq.Nil, acc)
            | Seq.Cons (y, s') =>
              (case eq (x, y) of
                 true => lasHelp (s', x, acc + 1)
               | false => (s, acc))
      in
        case Seq.showl s of
          Seq.Nil => Seq.hidel Seq.Nil
        | Seq.Cons (x, s') =>
          let
            val (tail, total) = lasHelp (s', x, 1)
          in
            Seq.hidel (Seq.Cons((total, x), look_and_say eq tail))
          end
      end
end

functor XRealOrder (X : sig type left end) : ORDERED =
struct
    type t = X.left * real
    fun compare ((_ , x) , (_ , y)) = Real.compare (x,y)
end

functor OrderUtils (O : ORDERED) : sig
                                       structure O : ORDERED
                                       val min : O.t * O.t -> O.t
                                       val max : O.t * O.t -> O.t
                                   end =
struct
    structure O = O
    fun min (x,y) = case O.compare(x,y) of LESS => x | _ => y
    fun max (x,y) = case O.compare(x,y) of LESS => y | _ => x
end

structure TestLAS =
struct

  val las = SeqUtils.look_and_say (fn (x : int, y : int) => x = y)

  val t1 = Seq.tabulate (fn x => x div 2) 10
  val s1 = Seq.tabulate (fn x => (2, x)) 5

  val t2 = Seq.tabulate (fn 0 => 3 | 1 => 3 | 2 => 3 | 3 => 2 | 4 => 1 | _ => 0)
                        10
  val s2 = Seq.tabulate (fn 0 => (3, 3) | 1 => (1, 2) | 2 => (1, 1)
                          | _ => (5, 0))
                        4

  val t3 = Seq.tabulate (fn 0 => 3 | 1 => 3 | 2 => 3 | 3 => 2 | 4 => 2 | _ => 0)
                        10
  val s3 = Seq.tabulate (fn 0 => (3, 3) | 1 => (2, 2) | _ => (5, 0))
                        3

  val t4 : int Seq.seq = Seq.empty()
  val s4 : (int * int) Seq.seq = Seq.empty()

  fun seqAll (f : 'a -> bool) (s : 'a Seq.seq) : bool =
      Seq.mapreduce f true (fn (b1, b2) => b1 andalso b2) s

  fun seqEq (aEq : 'a * 'a -> bool) (s1 : 'a Seq.seq, s2 : 'a Seq.seq) : bool =
      case Int.compare (Seq.length s1, Seq.length s2) of
          EQUAL => (seqAll aEq (Seq.zip (s1, s2)))
        | _ => false

  val intpaireq = (fn ((x1,y1), (x2,y2)) =>
                      case (Int.compare (x1, x2), Int.compare (y1, y2)) of
                          (EQUAL, EQUAL) => true
                        | (_, _) => false)

  val true = seqEq intpaireq (las t1, s1)
  val true = seqEq intpaireq (las t2, s2)
  val true = seqEq intpaireq (las t3, s3)
  val true = seqEq intpaireq (las t4, s4)

end
