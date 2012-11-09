;;; Compatibility. See comments in compat.cpp

IMPORT__exit = 1

;; Avoiding name conflicts
IMPORT__stricmp = 1
IMPORT__strnicmp = 1

___xi_a EQU ___xi_a_asm
___xc_a EQU ___xc_a_asm
___xc_z EQU ___xc_z_asm

;; Requiring assembly to use new runtime's file operations
IMPORT__open = 1
IMPORT__close = 1
IMPORT__tell = 1
IMPORT___read = 1
IMPORT___write = 1

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

;;game
IMPORT_?GetRandomNumTroops@game@@QAEHH@Z = 1

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
IMPORT_?MoveAttack@army@@QAEXHH@Z = 1
?MoveAttack@army@@QAEXHH@Z_clone EQU ?MoveAttack_orig@army@@QAEXHH@Z

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

;;towns
IMPORT_?SetupTowns@game@@QAEXXZ = 1

;;scripting hooks
IMPORT_?PerDay@game@@QAEXXZ = 1
?PerDay@game@@QAEXXZ_clone EQU ?PerDay_orig@game@@QAEXXZ