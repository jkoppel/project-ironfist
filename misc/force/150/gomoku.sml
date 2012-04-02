(* the signature of game specifications. *)
signature BOARD_SIZE =
  sig
    val width : int
    val height : int
  end

structure NormalBoard : BOARD_SIZE =
  struct
    val width = 7
    val height = 7
  end

structure Board98 : BOARD_SIZE =
  struct
    val width = 9
    val height = 8
  end

structure Board10 : BOARD_SIZE =
  struct
    val width = 10
    val height = 11
  end

functor Gomoku (Dim : BOARD_SIZE) : GAME
    where type move = int * int =
  struct
    datatype player = Minnie | Maxie
    datatype status = Over of real | In_play

    datatype position = Min | Max | Empty

    structure SM = SeqMatrix (Seq)

    datatype absstate = B of (position SM.matrix) * player
    type state = absstate

    type move = int * int

    fun move_to_string (i, j) =
        "(" ^ (Int.toString i) ^ ", " ^ (Int.toString j) ^ ")"

    fun parse_move (B (m, _)) s =
        case String.tokens (fn #" " => true | _ => false) s of
            [si, sj] =>
              (case (Int.fromString si, Int.fromString sj) of
                   (SOME i, SOME j) =>
                       ((case SM.sub m (i, j) of
                             Empty => SOME (i,j)
                           | _ => NONE)
                        handle Seq.Range => NONE)
                 | (_, _) => NONE)
          | _ => NONE


    val start = B (SM.repeat Empty (Dim.width, Dim.height), Maxie)

    fun seqMax (cmp : 'a * 'a -> order) (min : 'a) (s : 'a Seq.seq) =
        Seq.reduce (fn (x, y) => (case cmp (x, y) of
                                      LESS => y
                                    | _ => x))
                   min
                   s

    fun max_streak (streaks : (int * position) Seq.seq) =
        let
          val streak_cmp = fn ((_, Empty), _) => LESS
                            | (_, (_, Empty)) => GREATER
                            | ((x, _), (y, _)) => Int.compare (x, y)
        in
          seqMax streak_cmp (0, Empty) streaks
        end

    fun pos_streaks (ps : position Seq.seq) =
        let
          val eq_pos = fn (Max, Max) => true
                        | (Min, Min) => true
                        | (_, _) => false
        in
          SeqUtils.look_and_say eq_pos ps
        end

    fun bordered_streak (streaks : (int * position) Seq.seq)
        : (int * position * (bool * bool)) Seq.seq =
        let
          val len = Seq.length streaks

          fun isempty (i : int) =
              (case Seq.nth streaks i of
                   (_, Empty) => true
                 | (_, _) => false)
              handle Seq.Range => false

          fun ineighbors (i : int) =
              let
                val (slen, stp) = Seq.nth streaks i
              in
                (slen, stp, (isempty (i-1), isempty (i+1)))
              end
        in
          Seq.tabulate ineighbors len
        end

    fun matrix_lines (m : position SM.matrix) : (position Seq.seq Seq.seq) =
        Seq.flatten (Seq.tabulate (fn 0 => SM.rows m
                                    | 1 => SM.cols m
                                    | 2 => SM.diags1 m
                                    | 3 => SM.diags2 m
                                    | _ => raise Fail "unspecified") 4)

    fun longest_streak (m : position SM.matrix) =
        let
          val lines = matrix_lines m

          val streaks = Seq.map pos_streaks lines
        in
          max_streak (Seq.map max_streak streaks)
        end

    fun moves (B (m, _)) =
        SM.matching_subs (fn Empty => true | _ => false) m

    fun status (board as (B (m, _))) =
      let
        val (streak_len, streak_type) = longest_streak m
      in
        case Int.compare (streak_len, 5) of
            LESS => (case Seq.length (moves board) of
                         0 => Over 0.0
                       | _ => In_play)
          | _ => (case streak_type of
                      Min => Over Real.negInf
                    | Max => Over Real.posInf
                    | Empty => raise Fail "Internal State Exception")
      end

    val flip_player = fn Minnie => Maxie | Maxie => Minnie

    fun update_pos (m, i, j, player) =
      let
        val fill = case player of Maxie => Max | Minnie => Min
      in
        SM.update m ((i, j), fill)
      end

    fun make_move (board as (B (m, player)), (i, j)) =
        (case SM.sub m (i, j) of
             Empty => B (update_pos (m, i, j, player),
                         flip_player player)
           | _ => raise Fail "Illegal Move: Non-empty space")
        handle Seq.Range => raise Fail "Illegal Move: Out of range"

    fun player (B (_, player)) = player

    fun streak_val (slen : int, stype : position, (lempty, rempty)) : real =
        let
          val bonus = case (lempty, rempty) of
                          (true, true) => 4
                        | (false, false) => 0
                        | (_, _) => 1

          val abs_val = case (slen, bonus) of
                            (4, 4) => 50000.0
                          | (4, 1) => 15000.0
                          | (3, 4) => 2000.0
                          | _ => Real.Math.pow (4.0, Real.fromInt slen) *
                                 (Real.fromInt bonus)
        in
          case stype of
              Empty => 0.0
            | Min => ~abs_val
            | Max => abs_val
        end

    fun line_val (ps : position Seq.seq) : real =
        let
          fun fivesubseqs (s : position Seq.seq) : (position Seq.seq) Seq.seq =
              case Seq.showl s of
                  Seq.Nil => Seq.empty()
                | Seq.Cons(x, xs) =>
                  case Seq.length s < 5 of
                      true => Seq.empty()
                    | false => Seq.cons (Seq.head s 5, fivesubseqs xs)

          fun fiveval (s : position Seq.seq) (p : position) : int =
              let
                fun fivevalHelp (s : position Seq.seq) (acc : int) : int =
                    case Seq.showl s of
                        Seq.Nil => acc
                      | Seq.Cons (x, xs) =>
                        case x = p of
                            true => fivevalHelp xs (acc + 1)
                          | false => case x of
                                         Empty => fivevalHelp xs acc
                                       | _ => 0
              in
                fivevalHelp s 0
              end

          fun powInt (x : int, y : int) : real =
              Math.pow (Real.fromInt x, Real.fromInt y)
        in
          Seq.mapreduce (fn five => case (fiveval five Max, fiveval five Min) of
                                        (0, 0) => 0.0
                                      | (0, y) => ~(powInt(4, y))
                                      | (x, 0) => powInt(4, x)
                                      | (_, _) => raise Fail "fiveval bad")
                        0.0
                        op+
                        (fivesubseqs ps)
        end

    fun matrix_val (m : position SM.matrix) =
        Seq.mapreduce line_val 0.0 op+ (matrix_lines m)

    fun evaluate (board as (B (m, _))) =
        (case status board of
             Over v => v
           | In_play => matrix_val m
        )

    fun state_to_string (board as (B (m, _))) =
        let
          val rows = SM.rows m

          fun print_row s =
              "\n" ^ (Seq.toString(s, (fn Min => "O"
                                        | Max => "X"
                                        | Empty => " ")))
        in
          Seq.toString(rows, print_row) ^ "\n"
        end

  end

structure Gom = Gomoku(Board10)

structure TestGom =
struct

  structure Gom2 = Gomoku(struct
                              val width = 7
                              val height = 7
                          end)

  val state0 = Gom.start

  fun make_moves state nil = state
    | make_moves state (m1::ms) =
      make_moves (Gom.make_move (state, m1)) ms

  fun make_moves2 state nil = state
    | make_moves2 state (m1::ms) =
      make_moves2 (Gom2.make_move (state, m1)) ms

  val mvs1 = List.tabulate (49, (fn x =>
                                   (case Int.compare (x, 28) of
                                        EQUAL => (6,6)
                                      | LESS => (x div 7, x mod 7)
                                      | GREATER => ((x-1) div 7, (x-1) mod 7))))

  val state1 = make_moves state0 [(5, 5), (4, 5), (5, 4), (4, 4),
                                  (5, 3), (4, 3), (5, 2), (4, 2)]

  val state2 = Gom.make_move (state1, (5, 1))
  val state3 = Gom.make_move ((Gom.make_move (state1, (3, 1))), (4, 1))

  val state4 = make_moves2 Gom2.start mvs1

  fun statusEq (Gom.In_play, Gom.In_play) = true
    | statusEq (Gom.Over r1, Gom.Over r2) = Real.==(r1, r2)
    | statusEq (_, _) = false

  fun statusEq2 (Gom2.In_play, Gom2.In_play) = true
    | statusEq2 (Gom2.Over r1, Gom2.Over r2) = Real.==(r1, r2)
    | statusEq2 (_, _) = false

  val true = statusEq (Gom.status state0, Gom.In_play)
  val true = statusEq (Gom.status state1, Gom.In_play)
  val true = statusEq (Gom.status state2, Gom.Over Real.posInf)
  val true = statusEq (Gom.status state3, Gom.Over Real.negInf)
  val true = statusEq2 (Gom2.status state4, Gom2.Over 0.0)

  val true = Real.==(Gom.evaluate state2, Real.posInf)
  val true = Real.==(Gom.evaluate state3, Real.negInf)

end