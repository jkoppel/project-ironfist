
signature TWO_DIFF_PLAYERS =
sig
    structure Maxie  : PLAYER where type Game.move = int * int
    structure Minnie : PLAYER where type Game.move = int * int
(*    sharing type Maxie.Game.move = Minnie.Game.move *)
end

functor DiffReferee (P : TWO_DIFF_PLAYERS) : sig val go : unit -> real option end =
  struct
    structure Game1 = P.Maxie.Game
    structure Game2 = P.Minnie.Game

    fun play (state1 : Game1.state, state2 : Game2.state) =
      case (Game1.status state1, Game2.status state2) of
          (Game1.Over score1, Game2.Over score2) =>
              (case Real.== (score1, score2) of
                   true =>
                       let val () = print ((Game1.state_to_string state1) ^ "\n")
                           val () = print ("Game over! Final score: " ^ Real.toString(score1) ^ "\n")
                       in
                         SOME score1
                       end
                 | false =>
                       let val () = print ((Game1.state_to_string state1) ^ "\n")
                           val () = print ("Game over! Final score disputed\n")
                       in
                         NONE
                       end)
        | (Game1.In_play, Game2.In_play) =>
           let
             val () = print ((Game1.state_to_string state1) ^ "\n")
             val t0 = Time.now ()
             val moveop =
                 case (Game1.player state1, Game2.player state2) of
                   (Game1.Maxie, Game2.Maxie) => SOME (P.Maxie.next_move state1)
                 | (Game1.Minnie, Game2.Minnie) => SOME (P.Minnie.next_move state2)
                 | (_, _) => NONE
             val t1 = Time.now ()

             val () = case moveop of
                          NONE => print "Player dispute\n"
                        | SOME move =>
                              print ((case Game1.player state1 of
                                Game1.Maxie => "Maxie"
                              | Game1.Minnie => "Minnie")
                             ^ " decides to make the move "
                             ^ (Game1.move_to_string move)
                             ^ " in " ^
                             IntInf.toString(Time.toSeconds(Time.-(t1,t0))) ^
                                   " seconds.\n")
           in
             case moveop of
                 NONE => NONE
               | SOME move => play (Game1.make_move (state1,move), Game2.make_move (state2,move))
	   end
        | (_, _) => NONE


    fun go () = play (Game1.start, Game2.start)
  end

