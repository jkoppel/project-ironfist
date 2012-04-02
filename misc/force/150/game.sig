signature GAME =
sig
    datatype player = Minnie | Maxie
    datatype status = Over of real | In_play

    type state (* state of the game; e.g. board and player *)
    type move (* moves *)

    (* views of the state: *)
    val moves : state -> move Seq.seq (* assumes state is not Over; 
                                         generates moves that are valid in that state; 
                                         always generates at least one move *)
    val status : state -> status
    val player : state -> player

    (* initial state and transitions: *)
    val start : state
    val make_move : (state * move) -> state (* assumes move is valid in that state *)

    (* approximate the value of the state.
       Uses the same "sign" for each player:
       negative values are better for Minnie       
       and positive values are better for Maxie. *)
    val evaluate : state -> real

    val move_to_string : move -> string
    val state_to_string : state -> string
    val parse_move : state -> string -> move option (* ensures move is valid in
                                                       that state; string is a
                                                       single line, and *not*
                                                       newline terminated *)
end
