;; This file was created solely for use in the reassembly of HEROES2W.EXE.
;; It is not intended for general programming purposes without modification.

IFNDEF SMACKW32_INC
SMACKW32_INC EQU <1>

_SmackSummary@8 PROTO syscall :dword
_SmackSoundUseDirectSound@4 PROTO syscall :dword
_SmackSoundUseMSS@4 PROTO syscall :dword
_SmackToBufferRect@8 PROTO syscall :dword
_SmackNextFrame@4 PROTO syscall :dword
_SmackToBuffer@28 PROTO syscall :dword
_SmackWait@4 PROTO syscall :dword
_SmackClose@4 PROTO syscall :dword
_SmackDoFrame@4 PROTO syscall :dword
_SmackOpen@12 PROTO syscall :dword
ELSE
echo --------------------------------------------------------
echo ----------Duplicate include SMACKW32.inc------------------
echo --------------------------------------------------------
ENDIF