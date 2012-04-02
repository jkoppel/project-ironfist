functor MiniMax (G : GAME) : PLAYER = 
struct
    structure Game = G

    type edge = (G.move option * real)

    fun seqReduce (f : 'a * 'a -> 'a) (x : 'a) (s : 'a Seq.seq) : 'a =
        case Seq.showl s of
            Seq.Nil => x
          | Seq.Cons (y, s') => f (y, seqReduce f x s')

    (* assume seqs are non-empty *)
    val minEdge = fn (x as (_, r1), y as (_, r2)) => (case Real.compare (r1,r2) of
                                                          LESS => x
                                                        | _ => y)

    val maxEdge = fn (x as (_, r1), y as (_, r2)) => (case Real.compare (r1,r2) of
                                                          GREATER => x
                                                        | _ => y)

    val maxmove : edge Seq.seq -> edge = seqReduce maxEdge (NONE, Real.negInf)
    val minmove : edge Seq.seq -> edge = seqReduce minEdge (NONE, Real.posInf)

    fun search (d : int) (s : Game.state) : edge = 
        case d of 
            0 => (NONE , Game.evaluate s)
          | _ => (case Game.status s of
                      Game.Over v => (NONE , v)
                    | Game.In_play => 
                          let val choose : edge Seq.seq -> edge = case Game.player s of Game.Maxie => maxmove | Game.Minnie => minmove
                          in 
                              choose (Seq.map 
                                      (fn m => 
                                       let val (_ , value) = search (d - 1) (Game.make_move (s,m))
                                       in 
                                           (SOME m , value)
                                       end)
                                      (Game.moves s))
                          end)
    
    val search_depth = 2

    fun next_move state = 
        case search search_depth state of 
            (SOME bestMove , _) => bestMove
          | _ => raise Fail "called next move without any moves"

end