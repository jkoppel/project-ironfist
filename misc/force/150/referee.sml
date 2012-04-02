
signature TWO_PLAYERS =
sig
    structure Maxie  : PLAYER
    structure Minnie : PLAYER
    sharing type Maxie.Game.state = Minnie.Game.state
    sharing type Maxie.Game.move = Minnie.Game.move
end

functor Referee (P : TWO_PLAYERS) : sig val go : unit -> unit end =
  struct
    structure Game = P.Maxie.Game

    fun play state =
      case Game.status state of
          Game.Over score =>
              let val () = print ((Game.state_to_string state) ^ "\n")
                  val () = print ("Game over! Final score: " ^ Real.toString(score) ^ "\n")
              in
                  ()
              end
        | Game.In_play =>
           let
             val () = print ((Game.state_to_string state) ^ "\n")
             val t0 = Time.now ()
             val move =
                 case Game.player state of
                   Game.Maxie => P.Maxie.next_move state
                 | Game.Minnie => P.Minnie.next_move state
             val t1 = Time.now ()

             val () = print ((case Game.player state of
                                Game.Maxie => "Maxie"
                              | Game.Minnie => "Minnie")
                             ^ " decides to make the move "
                             ^ (Game.move_to_string move)
                             ^ " in " ^
                             IntInf.toString(Time.toSeconds(Time.-(t1,t0))) ^
                                   " seconds.\n")
           in
             play (Game.make_move (state,move))
	   end


    fun go () = play (Game.start)
  end

