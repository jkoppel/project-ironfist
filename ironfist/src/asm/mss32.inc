;; This file was created solely for use in the reassembly of HEROES2W.EXE.
;; It is not intended for general programming purposes without modification.

IFNDEF MSS32_INC
MSS32_INC EQU <1>
_AIL_end_sample@4 PROTO syscall :dword
_AIL_set_sequence_loop_count@8 PROTO syscall :dword
_AIL_start_sequence@4 PROTO syscall :dword
_AIL_set_XMIDI_master_volume@8 PROTO syscall :dword
_AIL_init_sequence@12 PROTO syscall :dword
_AIL_allocate_sequence_handle@4 PROTO syscall :dword
_AIL_get_preference@4 PROTO syscall :dword
_AIL_serve@0 PROTO syscall :dword
_AIL_init_sample@4 PROTO syscall :dword
_AIL_set_sample_type@12 PROTO syscall :dword
_AIL_set_sample_playback_rate@8 PROTO syscall :dword
_AIL_set_sample_loop_count@8 PROTO syscall :dword
_AIL_set_sample_address@12 PROTO syscall :dword
_AIL_sample_volume@4 PROTO syscall :dword
_AIL_set_sample_volume@8 PROTO syscall :dword
_AIL_start_sample@4 PROTO syscall :dword
_AIL_sample_status@4 PROTO syscall :dword
_AIL_resume_sequence@4 PROTO syscall :dword
_AIL_digital_handle_release@4 PROTO syscall :dword
_AIL_digital_handle_reacquire@4 PROTO syscall :dword
_AIL_shutdown@0 PROTO syscall :dword
_AIL_allocate_sample_handle@4 PROTO syscall :dword
_AIL_startup@0 PROTO syscall :dword
_AIL_set_preference@8 PROTO syscall :dword
_AIL_waveOutOpen@16 PROTO syscall :dword
_AIL_last_error@0 PROTO syscall :dword
_AIL_redbook_play@12 PROTO syscall :dword
_AIL_redbook_close@4 PROTO syscall :dword
_AIL_redbook_open@4 PROTO syscall :dword
_AIL_redbook_tracks@4 PROTO syscall :dword
_AIL_redbook_track_info@16 PROTO syscall :dword
_AIL_redbook_position@4 PROTO syscall :dword
_AIL_redbook_status@4 PROTO syscall :dword
_AIL_redbook_stop@4 PROTO syscall :dword
_AIL_stop_sequence@4 PROTO syscall :dword
_AIL_sequence_status@4 PROTO syscall :dword
_AIL_release_sequence_handle@4 PROTO syscall :dword
_AIL_midiOutClose@4 PROTO syscall :dword
_AIL_midiOutOpen@12 PROTO syscall :dword

ELSE
echo --------------------------------------------------------
echo ----------Duplicate include MSS32.inc------------------
echo --------------------------------------------------------
ENDIF