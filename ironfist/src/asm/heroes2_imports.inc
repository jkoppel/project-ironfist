;;; Compatibility. See comments in compat.cpp

IMPORT__exit = 1

;; Avoiding name conflicts
IMPORT__stricmp = 1
IMPORT__strnicmp = 1

___xi_a EQU ___xi_a_asm
___xc_a EQU ___xc_a_asm
___xc_z EQU ___xc_z_asm
___xt_a EQU ___xt_a_asm
___xp_a EQU ___xp_a_asm

;; Requiring assembly to use new runtime's file operations
IMPORT__open = 1
IMPORT__close = 1
IMPORT__tell = 1
IMPORT___read = 1
IMPORT___write = 1
IMPORT___lseek = 1

;; Statically linking runtime

__CIexp EQU __CIexp_asm
__CIatan2 EQU __CIatan2_asm
__indefinite EQU __indefinite_asm
__infinity EQU __infinity_asm
__OP_EXPjmptab EQU __OP_asm
__CIacos EQU __CIacos_asm
___argc EQU ___argc_asm
___argv EQU ___argv_asm
__acmdln EQU __acmbdln_asm
__pgmptr EQU __pgmptr_asm
__CIatan EQU __CIatan_asm
__pctype EQU __pctype_asm
___badioinfo EQU ___badioinfo_asm
___pioinfo EQU ___pioinfo_asm
__nhandle EQU __nhandle_asm
__CIlog EQU __CIlog_asm
__CIlog10 EQU __CIlog10_asm
___mbcodepage EQU ___mbcodepage_asm
___mbulinfo EQU ___mbulinfo_asm
__mbctype EQU __mbctype_asm
__commode EQU __commode_asm
__CIpow EQU __CIpow_asm
__sys_nerr EQU __sys_asm
_tolower EQU _tolower_asm
_toupper EQU _toupper_asm
___mb_cur_max EQU ___mb_cur_max_asm
__d_inf EQU __d_inf_asm
__d_ind EQU __d_ind_asm
__d_max EQU __d_max_asm
__d_mzero EQU __d_asm
__nstream EQU __nstream_asm
___piob EQU ___piob_asm
__cflush EQU __cflush_asm
__iob EQU __iob_asm
___from_strstr_to_strchr EQU ___from_strstr_to_strchr_asm
__NLG_Dispatch EQU __NLG_Dispatch_asm
__NLG_Return2 EQU __NLG_Return2_asm
__NLG_Destination EQU __NLG_Destination_asm
__NLG_Notify1 EQU __NLG_Notify1_asm


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

;;allowing play without CD
IMPORT_?SetupCDRom@@YIXXZ = 1
IMPORT_?SetupGame@game@@QAEHXZ = 1
?SetupGame@game@@QAEHXZ_clone EQU ?SetupGame_orig@game@@QAEHXZ

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
IMPORT_?GetMonsterCost@@YIXHQAH@Z = 1

;;armies

IMPORT_??0armyGroup@@QAE@XZ = 1

;;game
IMPORT_?GetRandomNumTroops@game@@QAEHH@Z = 1
IMPORT_?NextPlayer@game@@QAEXXZ = 1
?NextPlayer@game@@QAEXXZ_clone EQU ?NextPlayer_orig@game@@QAEXXZ

;;game loop - windows messaging (for lowering cpu usage)
IMPORT_?Process1WindowsMessage@@YIXXZ = 1
?Process1WindowsMessage@@YIXXZ_clone EQU ?Process1WindowsMessage_orig@@YIXXZ

;;hero
IMPORT_??0hero@@QAE@XZ = 1
IMPORT_?AddSpell@hero@@QAEXHH@Z = 1
IMPORT_?HasSpell@hero@@QAEHH@Z = 1
IMPORT_?GetNumSpells@hero@@QAEHH@Z = 1
IMPORT_?GetNthSpell@hero@@QAEHHH@Z = 1

;;artifacts
IMPORT_?gArtifactNames@@3PAPADA = 1
IMPORT_?gArtifactDesc@@3PAPADA = 1
IMPORT_?gArtifactEvents@@3PAPADA = 1
IMPORT_?gArtifactLevel@@3PAEA = 1

;;combat
IMPORT_?InitNonVisualVars@combatManager@@QAEXXZ = 1
?InitNonVisualVars@combatManager@@QAEXXZ_clone EQU ?InitNonVisualVars_orig@combatManager@@QAEXXZ
IMPORT_?LoadResources@army@@QAEXXZ = 1
?LoadResources@army@@QAEXXZ_clone EQU ?LoadResources_orig@army@@QAEXXZ
IMPORT_?MoveAttack@army@@QAEXHH@Z = 1
?MoveAttack@army@@QAEXHH@Z_clone EQU ?MoveAttack_orig@army@@QAEXHH@Z
IMPORT_?sElevationOverlay@@3PAUSElevationOverlay@@A = 1
IMPORT_?DoAttack@army@@QAEXH@Z = 1
?DoAttack@army@@QAEXH@Z_clone EQU ?DoAttack_orig@army@@QAEXH@Z
IMPORT_?SpecialAttack@army@@QAEXXZ = 1
?SpecialAttack@army@@QAEXXZ_clone EQU ?SpecialAttack_orig@army@@QAEXXZ

;;heroes
IMPORT_?cHeroTypeInitial@@3PADA = 1
IMPORT_?sCmbtHero@@3PAUSCmbtHero@@A = 1
IMPORT_?gAlignmentNames@@3PAPADA = 1

;; adventure map
IMPORT_?SetVisibility@game@@QAEXHHHH@Z = 1
?SetVisibility@game@@QAEXHHHH@Z_clone EQU ?SetVisibility_orig@game@@QAEXHHHH@Z
IMPORT_?MakeAllWaterVisible@game@@QAEXH@Z = 1
?MakeAllWaterVisible@game@@QAEXH@Z_clone EQU ?MakeAllWaterVisible_orig@game@@QAEXH@Z

IMPORT_?MoveHero@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z = 1
?MoveHero@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z_clone EQU ?MoveHero_orig@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z

IMPORT_?DoEvent@advManager@@QAEXPAVmapCell@@HH@Z = 1
?DoEvent@advManager@@QAEXPAVmapCell@@HH@Z_clone EQU ?DoEvent_orig@advManager@@QAEXPAVmapCell@@HH@Z

;;hero movement reminder
IMPORT_?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z = 1
?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z_clone EQU ?ProcessDeSelect_orig@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z


;;;; border guards
IMPORT_?BarrierEvent@advManager@@QAEHPAVmapCell@@PAVhero@@@Z = 1
IMPORT_?PasswordEvent@advManager@@QAEXPAVmapCell@@PAVhero@@@Z = 1

;;saving
IMPORT_?LoadGame@game@@QAEXPADHH@Z = 1
?LoadGame@game@@QAEXPADHH@Z_clone EQU ?LoadGame_orig@game@@QAEXPADHH@Z
IMPORT_?SaveGame@game@@QAEHPADHC@Z = 1
IMPORT_?Read@hero@@QAEXHC@Z = 1
IMPORT_?RandomizeHeroPool@game@@QAEXXZ = 1

;;maps
IMPORT_?NewMap@game@@QAEXPAD@Z = 1
?NewMap@game@@QAEXPAD@Z_clone EQU ?NewMap_orig@game@@QAEXPAD@Z

;;spells
IMPORT_?gsSpellInfo@@3PAUSSpellInfo@@A = 1
IMPORT_?gSpellDesc@@3PAPADA = 1
IMPORT_?gSpellNames@@3PAPADA = 1
IMPORT_?CastSpell@advManager@@QAEXH@Z = 1
?CastSpell@advManager@@QAEXH@Z_clone EQU ?CastSpell_orig@advManager@@QAEXH@Z
IMPORT_?Resurrect@combatManager@@QAEXHHH@Z = 1
IMPORT_?DimensionDoor@advManager@@QAEXXZ = 1
IMPORT_?SpellCastWorkChance@army@@QAEMH@Z = 1
?SpellCastWorkChance@army@@QAEMH@Z_clone EQU ?SpellCastWorkChance_orig@army@@QAEMH@Z

;;towns
IMPORT_?SetupTowns@game@@QAEXXZ = 1
IMPORT_?SetupMage@townManager@@QAEXPAVheroWindow@@@Z = 1
IMPORT_?RecruitHero@townManager@@QAEHHH@Z = 1
?RecruitHero@townManager@@QAEHHH@Z_clone EQU ?RecruitHero_orig@townManager@@QAEHHH@Z
IMPORT_?GetBuildingName@@YIPADHH@Z = 1
?Open@townManager@@UAEHH@Z_clone EQU ?Open_orig@townManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?Open@recruitUnit@@UAEHH@Z = 1
?Open@recruitUnit@@UAEHH@Z_clone EQU ?Open_orig@recruitUnit@@QAEHH@Z

;;scripting hooks
IMPORT_?PerDay@game@@QAEXXZ = 1
?PerDay@game@@QAEXXZ_clone EQU ?PerDay_orig@game@@QAEXXZ
IMPORT_?Open@advManager@@UAEHH@Z = 1
?Open@advManager@@UAEHH@Z_clone EQU ?Open_orig@advManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?Open@townManager@@UAEHH@Z = 1
?Open@townManager@@UAEHH@Z_clone EQU ?Open_orig@townManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?CheckEndGame@@YIXHH@Z = 1
?CheckEndGame@@YIXHH@Z_clone EQU ?CheckEndGame_orig@@YIXHH@Z

;; AI
IMPORT_?RedistributeTroops@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z = 1
?RedistributeTroops@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z_clone EQU ?RedistributeTroops_orig@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z