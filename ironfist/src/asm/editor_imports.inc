;;; Compatibility. See comments in compat.cpp

IMPORT__exit = 1

;; Avoiding name conflicts
IMPORT__stricmp = 1

___xi_a EQU ___xi_a_asm
___xc_a EQU ___xc_a_asm
___xc_z EQU ___xc_z_asm

;; Requiring assembly to use new runtime's file operations
IMPORT__open = 1
IMPORT__close = 1
IMPORT__tell = 1
IMPORT___read = 1
IMPORT___write = 1
IMPORT___lseek = 1

;; Preventing the startup routines' names from clashing
_WinMainCRTStartup EQU _start_asm
_WinMain@16 EQU  _WinMain_asm@16

;; Hooking app exit
IMPORT_?AppExit@@YIXXZ = 1

;; Requiring assembly to put C++ objects on new heap
??2@YAPAXI@Z EQU _op_new
IMPORT_??2@YAPAXI@Z = 1
??3@YAXPAX@Z EQU _op_del
IMPORT_??3@YAXPAX@Z = 1

;;init
IMPORT_?InitMainClasses@@YIXXZ = 1
IMPORT_?DeleteMainClasses@@YIXXZ = 1

;;;resourceManager

IMPORT_??_7resourceManager@@6B@ = 1
IMPORT_??0resourceManager@@QAE@XZ = 1
IMPORT_?GetBackdrop@resourceManager@@QAEXPADPAVbitmap@@H@Z = 1
IMPORT_?GetPalette@resourceManager@@QAEPAVpalette@@PAD@Z = 1
IMPORT_?GetBitmap@resourceManager@@QAEPAVbitmap@@PAD@Z = 1
IMPORT_?GetIcon@resourceManager@@QAEPAVicon@@PAD@Z = 1
IMPORT_?GetIcon@resourceManager@@QAEPAVicon@@K@Z = 1
IMPORT_?GetTileset@resourceManager@@QAEPAVtileset@@PAD@Z = 1
IMPORT_?GetFont@resourceManager@@QAEPAVfont@@PAD@Z = 1
IMPORT_?GetSample@resourceManager@@QAEPAVsample@@PAD@Z = 1
IMPORT_?GetMIDIWrap@resourceManager@@QAEPAVMIDIWrap@@PAD@Z = 1
IMPORT_?Dispose@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?AddResource@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?Expunge@resourceManager@@QAEXXZ = 1
IMPORT_?Query@resourceManager@@QAEPAVresource@@K@Z = 1
IMPORT_?Main@resourceManager@@UAEHAAUtag_message@@@Z = 1
IMPORT_?Open@resourceManager@@UAEHH@Z = 1
IMPORT_?RemoveResource@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?Close@resourceManager@@UAEXXZ = 1
IMPORT_?LoadAggregateHeader@resourceManager@@QAEHPAD@Z = 1
IMPORT_?PointToFile@resourceManager@@QAEXK@Z = 1
IMPORT_?GetFileSize@resourceManager@@QAEKK@Z = 1
IMPORT_?SavePosition@resourceManager@@QAEXXZ = 1
IMPORT_?RestorePosition@resourceManager@@QAEXXZ = 1
IMPORT_?ReadWord@resourceManager@@QAEFXZ = 1
IMPORT_?ReadLong@resourceManager@@QAEJXZ = 1
IMPORT_?MakeId@resourceManager@@QAEKPADH@Z = 1
IMPORT_?Read13@resourceManager@@QAEXPAC@Z = 1
IMPORT_?ReadBlock@resourceManager@@QAEXPACK@Z = 1

;;creatures

IMPORT_?cArmyFrameFileNames@@3PAPADA = 1
IMPORT_?cMonFilename@@3PAPADA = 1
IMPORT_?gArmyNames@@3PAPADA = 1
IMPORT_?gArmyNamesPlural@@3PAPADA = 1
IMPORT_?gMonsterDatabase@@3PAUtag_monsterInfo@@A = 1

;;artifacts
IMPORT_?gArtifactNames@@3PAPADA = 1
IMPORT_?gArtifactDesc@@3PAPADA = 1
IMPORT_?gArtifactEvents@@3PAPADA = 1
IMPORT_?gArtifactLevel@@3PAEA = 1

;;overlays
IMPORT_?gOverlayDatabase@@3PAUoverlay@@A = 1
IMPORT_?FillInOverlayTiles@@YAXXZ = 1

;;gui
IMPORT_?EditTown@eventsManager@@QAEHHH@Z = 1
?EditTown@eventsManager@@QAEHHH@Z_clone EQU ?EditTown_orig@eventsManager@@QAEHHH@Z
IMPORT_?AppWndProc@@YGJPAXIIJ@Z = 1
?AppWndProc@@YGJPAXIIJ@Z_clone EQU ?AppWndProc_orig@@YGJPAXIIJ@Z
IMPORT_@PollSound@0 =1
@PollSound@0_clone EQU @PollSound_orig@0