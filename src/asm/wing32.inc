;; This file was created solely for use in the reassembly of HEROES2W.EXE.
;; As such, it does not contain prototypes for all wing32 functions, and
;; is not suitable for general-purpose use of wing32.dll without modification.

IFNDEF WING32_INC
WING32_INC EQU <1>

WinGBitBlt PROTO syscall :dword
WinGStretchBlt PROTO  syscall :dword
WinGSetDIBColorTable PROTO syscall :dword
WinGRecommendDIBFormat PROTO syscall :dword
WinGCreateDC PROTO syscall :dword
WinGCreateBitmap PROTO syscall :dword
ELSE
echo --------------------------------------------------------
echo ----------Duplicate include wing32.inc------------------
echo --------------------------------------------------------
ENDIF