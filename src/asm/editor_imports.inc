;;; Compatibility. See comments in compat.cpp

IMPORT__exit = 1

;; Avoiding name conflicts
IMPORT__stricmp = 1

___xi_a EQU ___xi_a_asm
___xc_a EQU ___xc_a_asm
___xc_z EQU ___xc_z_asm
___xt_a EQU ___xt_a_asm
___xp_a EQU ___xp_a_asm

;; Statically linking runtime
___argc EQU ___argc_asm
___argv EQU ___argv_asm
__acmdln EQU __acmdln_asm
__pgmptr EQU __pgmptr_asm
__pctype EQU __pctype_asm
___badioinfo EQU ___badioinfo_asm
__nhandle EQU __nhandle_asm
___mbcodepage EQU ___mbcodepage_asm
___mbulinfo EQU ___mbulinfo_asm
__mbctype EQU __mbctype_asm
__commode EQU __commode_asm
___pioinfo EQU ___pioinfo_asm
___mb_cur_max EQU ___mb_cur_max_asm
_strnicmp EQU _strnicmp_asm
_tolower EQU _tolower_asm
_toupper EQU _toupper_asm
__nstream EQU __nstream_asm
___piob EQU ___piob_asm
__cflush EQU __cflush_asm
__iob EQU __iob_asm
___from_strstr_to_strchr EQU ___from_strstr_to_strchr_asm
__NLG_Dispatch EQU __NLG_Dispatch_asm
__NLG_Return2 EQU __NLG_Return2_asm
__NLG_Destination EQU __NLG_Destination_asm
__NLG_Notify1 EQU __NLG_Notify1_asm


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
IMPORT_?MAKEFILEID@@YIKPAD@Z = 1

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
IMPORT_?PlaceOverlay@@YIHPAUoverlay@@HHH@Z = 1

;;map
IMPORT_?CopyMap@@YAPAXXZ = 1
IMPORT_?Clone@fullMap@@QAEPAXPAV1@@Z = 1

;;mapExtra
IMPORT_?DeleteExtraObjectData@@YIXI@Z = 1

;;gui
IMPORT_?EditTown@eventsManager@@QAEXHH@Z = 1
IMPORT_?EditHero@eventsManager@@QAEHHHH@Z = 1
?EditHero@eventsManager@@QAEHHHH@Z_clone EQU ?EditHero_orig@eventsManager@@QAEHHHH@Z
IMPORT_?EditEvent@eventsManager@@QAEHH@Z = 1
?EditEvent@eventsManager@@QAEHH@Z_clone EQU ?EditEvent_orig@eventsManager@@QAEHH@Z
IMPORT_?ShowErrorMessage@@YIXPBD@Z = 1
?ShowErrorMessage@@YIXPBD@Z_clone EQU ?ShowErrorMessage_orig@@YIXPBD@Z

;;editManager
IMPORT_?InitializeMap@editManager@@QAEXHHH@Z = 1
?InitializeMap@editManager@@QAEXHHH@Z_clone EQU ?InitializeMap_orig@editManager@@QAEXHHH@Z
IMPORT_?GetOverlayID@editManager@@QAEHHH@Z = 1
IMPORT_?SpellScrollEditDialog@editManager@@QAEXPAH@Z = 1
?SpellScrollEditDialog@editManager@@QAEXPAH@Z_clone EQU ?SpellScrollEditDialog_orig@editManager@@QAEXPAH@Z
IMPORT_?SpellScrollEditDialogCallback@@YIHAAUtag_message@@@Z = 1
?SpellScrollEditDialogCallback@@YIHAAUtag_message@@@Z_clone EQU ?SpellScrollEditDialogCallback_orig@@YIHAAUtag_message@@@Z

IMPORT_?EditHeroHandler@@YIHAAUtag_message@@@Z = 1
?EditHeroHandler@@YIHAAUtag_message@@@Z_clone EQU  ?EditHeroHandler_orig@@YIHAAUtag_message@@@Z
IMPORT_?FillInHeroEdit@@YGXPAVHeroExtra@@@Z = 1
?FillInHeroEdit@@YGXPAVHeroExtra@@@Z_clone EQU ?FillInHeroEdit_orig@@YGXPAVHeroExtra@@@Z
IMPORT_?FillInEventEdit@@YGXPAVEventExtra@@@Z = 1
?FillInEventEdit@@YGXPAVEventExtra@@@Z_clone EQU ?FillInEventEdit_orig@@YGXPAVEventExtra@@@Z
IMPORT_?WinConditionHandler@@YAHXZ = 1
?WinConditionHandler@@YAHXZ_clone EQU ?WinConditionHandler_orig@@YAHXZ
IMPORT_?FillInWinCondition@@YIHH@Z = 1
?FillInWinCondition@@YIHH@Z_clone EQU ?FillInWinCondition_orig@@YIHH@Z
IMPORT_?CalculatePlayerNumbers@@YIXXZ = 1
IMPORT_?ResetPlayerAvailability@@YIXXZ = 1

;;overlayManager
IMPORT_?SetupOverlayWindow@overlayManager@@QAEXH@Z = 1
IMPORT_?PopulateAvailOverlays@overlayManager@@QAEHH@Z = 1
IMPORT_?SelectOverlayMain@overlayManager@@QAEHAAUtag_message@@@Z = 1
?SelectOverlayMain@overlayManager@@QAEHAAUtag_message@@@Z_clone EQU ?SelectOverlayMain_orig@overlayManager@@QAEHAAUtag_message@@@Z

;;spells
IMPORT_?gSpellNames@@3PAPADA = 1

;;towns
IMPORT_?gTownEligibleBuildMask@@3PAKA = 1
IMPORT_?gTownObjNames@@3PAPADA = 1
IMPORT_?gDwellingType@@3PAY0M@EA = 1
IMPORT_?gWellExtraNames@@3PAPADA = 1
IMPORT_?gSpecialBuildingNames@@3PAPADA = 1
IMPORT_?gBuildingInfoSpecial@@3PAPADA = 1
IMPORT_?gTownPrefixNames@@3PAPADA = 1

IMPORT_?sub_42AAF9@@YGHPAH0HHD@Z = 1
IMPORT_?AppCommand@@YIJPAXIIJ@Z = 1
?AppCommand@@YIJPAXIIJ@Z_clone EQU ?AppCommand_orig@@YIJPAXIIJ@Z
IMPORT_?UpdateDfltMenu@@YIXPAX@Z = 1
?UpdateDfltMenu@@YIXPAX@Z_clone EQU ?UpdateDfltMenu_orig@@YIXPAX@Z

;; main loop
IMPORT_?oldmain@@YIHXZ = 1
?oldmain@@YIHXZ_clone EQU ?oldmain_orig@@YIHXZ