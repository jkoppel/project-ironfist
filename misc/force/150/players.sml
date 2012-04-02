signature PLAYER =
sig
    structure Game : GAME

    (* assumes game is not Over *)
    val next_move : Game.state -> Game.move
end

(* The HumanPlayer just gets moves from what the user types in.
 * It is a functor that takes a game so that it knows how to 
 * represent moves and the game state and knows how to find out if 
 * a move is legal and whose turn it is.
 * We've written this one for you so you can use it to test your game.
 *)
functor HumanPlayer (G : GAME) : PLAYER =
struct
    structure Game = G

    fun next_move state =
        let val () = 
            (print ((case (Game.player state) of 
                         Game.Maxie => "Maxie" 
                       | Game.Minnie => "Minnie")
                    ^ ", please type your move: "))
        in 
            case TextIO.inputLine TextIO.stdIn of
                NONE => raise Fail "Tried to read a line of input from stdin and failed"
              | SOME input =>
                    let val input = 
                        (* eat the newline character from the end of user's input *)
                        String.substring(input, 0, String.size(input) - 1)
                    in
                        case Game.parse_move state input of
                            SOME m => m
                          | NONE => 
                                let val () = print ("Bad move for this state: " 
                                                    ^ input ^ "\n")
                                in next_move state end
                    end
        end
end

(* functor MiniMax (G : GAME) : PLAYER = 
 * struct
 *     structure Game = G
 * 
 *     type edge = (G.move option * real)
 * 
 *     structure Ut : sig
 *                        (* ordered by the real, ignoring the move *)
 *                        val min : edge * edge -> edge
 *                        val max : edge * edge -> edge
 *                    end = OrderUtils(XRealOrder(struct type left = G.move option end))
 * 
 *     (* assume seqs are non-empty *)
 *     val maxmove : edge Seq.seq -> edge = SeqUtils.reduce1 Ut.max 
 *     val minmove : edge Seq.seq -> edge = SeqUtils.reduce1 Ut.min 
 * 
 *     fun search (d : int) (s : Game.state) : edge = 
 *         case d of 
 *             0 => (NONE , Game.evaluate s)
 *           | _ => (case Game.status s of
 *                       Game.Over v => (NONE , v)
 *                     | Game.In_play => 
 *                           let val choose : edge Seq.seq -> edge = case Game.player s of Game.Maxie => maxmove | Game.Minnie => minmove
 *                           in 
 *                               choose (Seq.map 
 *                                       (fn m => 
 *                                        let val (_ , value) = search (d - 1) (Game.make_move (s,m))
 *                                        in 
 *                                            (SOME m , value)
 *                                        end)
 *                                       (Game.moves s))
 *                           end)
 *     
 *     val search_depth = 3
 * 
 *     fun next_move state = 
 *         case search search_depth state of 
 *             (SOME bestMove , _) => bestMove
 *           | _ => raise Fail "called next move without any moves"
 * 
 * end *)
