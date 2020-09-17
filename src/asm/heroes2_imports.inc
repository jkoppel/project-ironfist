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

;; main loop
IMPORT_?oldmain@@YIHXZ = 1
?oldmain@@YIHXZ_clone EQU ?oldmain_orig@@YIHXZ

;; executive
IMPORT_?AddManager@executive@@QAEHPAVbaseManager@@H@Z = 1
?AddManager@executive@@QAEHPAVbaseManager@@H@Z_clone EQU ?AddManager_orig@executive@@QAEHPAVbaseManager@@H@Z

;;init
IMPORT_?InitMainClasses@@YIXXZ = 1
IMPORT_?DeleteMainClasses@@YIXXZ = 1

;;allowing play without CD
IMPORT_?SetupCDDrive@@YIHXZ = 1
?SetupCDDrive@@YIHXZ_clone EQU ?SetupCDDrive_orig@@YIHXZ 
IMPORT_?SetupCDRom@@YIXXZ = 1
IMPORT_?SetupGame@game@@QAEHXZ = 1
?SetupGame@game@@QAEHXZ_clone EQU ?SetupGame_orig@game@@QAEHXZ

;; title screen
IMPORT_?IMHotSpots@@3PAY03GA = 1
IMPORT_?CheckShingleUpdate@@YIXXZ = 1

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

;;mouseManager
IMPORT_?SetPointer@mouseManager@@QAEXH@Z = 1

;;creatures

IMPORT_?cArmyFrameFileNames@@3PAPADA = 1
IMPORT_?cMonFilename@@3PAPADA = 1
IMPORT_?gArmyNames@@3PAPADA = 1
IMPORT_?gArmyNamesPlural@@3PAPADA = 1
IMPORT_?gMonsterDatabase@@3PAUtag_monsterInfo@@A = 1
IMPORT_?GetMonsterCost@@YIXHQAH@Z = 1
IMPORT_?GetMonsterName@@YIPADH@Z = 1

;;armies

IMPORT_??0armyGroup@@QAE@XZ = 1
IMPORT_?Walk@army@@QAEXHHH@Z = 1

;;game
IMPORT_?GetRandomNumTroops@game@@QAEHH@Z = 1
IMPORT_?NextPlayer@game@@QAEXXZ = 1
?NextPlayer@game@@QAEXXZ_clone EQU ?NextPlayer_orig@game@@QAEXXZ
IMPORT_?ClaimTown@game@@QAEXHHH@Z = 1
?ClaimTown@game@@QAEXHHH@Z_clone EQU ?ClaimTown_orig@game@@QAEXHHH@Z
IMPORT_?AddScoreToHighScore@@YIHHHHHPAD@Z = 1
?AddScoreToHighScore@@YIHHHHHPAD@Z_clone EQU ?AddScoreToHighScore_orig@@YIHHHHHPAD@Z
IMPORT_?HandleAppSpecificMenuCommands@@YIHH@Z = 1
?HandleAppSpecificMenuCommands@@YIHH@Z_clone EQU ?HandleAppSpecificMenuCommands_orig@@YIHH@Z
IMPORT_?UpdateDfltMenu@@YIXPAX@Z = 1
?UpdateDfltMenu@@YIXPAX@Z_clone EQU ?UpdateDfltMenu_orig@@YIXPAX@Z
IMPORT_?SetRandomHeroArmies@game@@QAEXHH@Z = 1
IMPORT_?GiveTroopsToNeutralTown@game@@QAEXH@Z = 1
IMPORT_?ProcessOnMapHeroes@game@@QAEXXZ = 1
IMPORT_?NewGameHandler@@YIHAAUtag_message@@@Z = 1
?NewGameHandler@@YIHAAUtag_message@@@Z_clone EQU ?NewGameHandler_orig@@YIHAAUtag_message@@@Z
IMPORT_?RandomizeTown@game@@QAEXHHH@Z = 1
IMPORT_?ShowScenInfo@game@@QAEXXZ = 1
IMPORT_?UpdateNewGameWindow@game@@QAEXXZ = 1
IMPORT_?ProcessRandomObjects@game@@QAEXXZ = 1
IMPORT_?GetLuck@game@@QAEHPAVhero@@PAVarmy@@PAVtown@@@Z = 1
?GetLuck@game@@QAEHPAVhero@@PAVarmy@@PAVtown@@@Z_clone EQU ?GetLuck_orig@game@@QAEHPAVhero@@PAVarmy@@PAVtown@@@Z
IMPORT_?GetMorale@armyGroup@@QAEHPAVhero@@PAVtown@@PAV1@@Z = 1
?GetMorale@armyGroup@@QAEHPAVhero@@PAVtown@@PAV1@@Z_clone EQU ?GetMorale_orig@armyGroup@@QAEHPAVhero@@PAVtown@@PAV1@@Z
IMPORT_?ShowLuckInfo@game@@QAEXPAVhero@@H@Z = 1
IMPORT_?ShowMoraleInfo@game@@QAEXPAVhero@@H@Z = 1

;;game loop - windows messaging (for lowering cpu usage)
IMPORT_?Process1WindowsMessage@@YIXXZ = 1
?Process1WindowsMessage@@YIXXZ_clone EQU ?Process1WindowsMessage_orig@@YIXXZ

;; Timing
IMPORT_?DelayTilMilli@@YIXJ@Z = 1

;;sound
;;IMPORT___imp__AIL_redbook_play@12 = 1
IMPORT_?CDPlay@soundManager@@QAEXHHHH@Z = 1
?CDPlay@soundManager@@QAEXHHHH@Z_clone EQU CDPlay_orig@soundManager@@QAEXHHHH@Z
IMPORT_?CDStop@soundManager@@QAEXXZ = 1
?CDStop@soundManager@@QAEXXZ_clone EQU ?CDStop_orig@soundManager@@QAEXXZ
IMPORT_?CDSetVolume@soundManager@@QAEXHH@Z = 1
?CDSetVolume@soundManager@@QAEXHH@Z_clone EQU ?CDSetVolume_orig@soundManager@@QAEXHH@Z
IMPORT_?ConvertVolume@soundManager@@QAEHHH@Z = 1
?ConvertVolume@soundManager@@QAEHHH@Z_clone EQU ?ConvertVolume_orig@soundManager@@QAEHHH@Z
IMPORT_?CDStartup@soundManager@@QAEXXZ = 1
?CDStartup@soundManager@@QAEXXZ_clone EQU ?CDStartup_orig@soundManager@@QAEXXZ
IMPORT_?CDShutdown@soundManager@@QAEXXZ = 1
?CDShutdown@soundManager@@QAEXXZ_clone EQU ?CDShutdown_orig@soundManager@@QAEXXZ
IMPORT_?CDIsPlaying@soundManager@@QAEHXZ = 1
?CDIsPlaying@soundManager@@QAEHXZ_clone EQU ?CDIsPlaying_orig@soundManager@@QAEHXZ
useOpera EQU ?useOpera@@3HA
IMPORT_?Open@soundManager@@UAEHH@Z = 1
?Open@soundManager@@UAEHH@Z_clone EQU ?Open_orig@soundManager@@QAEHH@Z
IMPORT_?SetupGridForArmy@combatManager@@QAEXPAVarmy@@@Z = 1
?SetupGridForArmy@combatManager@@QAEXPAVarmy@@@Z_clone EQU ?SetupGridForArmy_orig@combatManager@@QAEXPAVarmy@@@Z
IMPORT_?townTheme@@3PACA = 1

;;hero
IMPORT_??0hero@@QAE@XZ = 1
IMPORT_?AddSpell@hero@@QAEXHH@Z = 1
IMPORT_?HasSpell@hero@@QAEHH@Z = 1
IMPORT_?GetNumSpells@hero@@QAEHH@Z = 1
IMPORT_?GetNthSpell@hero@@QAEHHH@Z = 1
IMPORT_?CheckLevel@hero@@QAEXXZ = 1
?CheckLevel@hero@@QAEXXZ_clone EQU ?CheckLevel_orig@hero@@QAEXXZ
IMPORT_?CalcMobility@hero@@QAEHXZ = 1
?CalcMobility@hero@@QAEHXZ_clone EQU ?CalcMobility_orig@hero@@QAEHXZ
IMPORT_?GetManaCost@@YIHHPAVhero@@@Z = 1
?GetManaCost@@YIHHPAVhero@@@Z_clone EQU ?GetManaCost_orig@@YIHHPAVhero@@@Z

;;artifacts
IMPORT_?gArtifactNames@@3PAPADA = 1
IMPORT_?gArtifactDesc@@3PAPADA = 1
IMPORT_?gArtifactEvents@@3PAPADA = 1
IMPORT_?gArtifactLevel@@3PAEA = 1
IMPORT_?IsCursedItem@@YIHH@Z = 1
IMPORT_?InitRandomArtifacts@game@@QAEXXZ = 1
IMPORT_?GetRandomArtifactId@game@@QAEHHH@Z = 1
IMPORT_?GiveTakeArtifactStat@@YIXPAVhero@@HH@Z = 1
?GiveTakeArtifactStat@@YIXPAVhero@@HH@Z_clone EQU ?GiveTakeArtifactStat_orig@@YIXPAVhero@@HH@Z

;;combat
IMPORT_?gCombatFxNames@@3PAPADA = 1
IMPORT_?giNumPowFrames@@3PAEA = 1
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
IMPORT_?PowEffect@army@@QAEXHHHH@Z = 1
IMPORT_?OppositeDirection@@YIHH@Z = 1
IMPORT_?LowerDoor@combatManager@@QAEXXZ = 1
IMPORT_?FlyTo@army@@QAEHH@Z = 1
IMPORT_?BuildTempWalkSeq@@YIXPAUSMonFrameInfo@@HH@Z = 1
IMPORT_?DamageEnemy@army@@QAEXPAV1@PAH1HH@Z = 1
IMPORT_?DecrementSpellRounds@army@@QAEXXZ = 1
IMPORT_?SetSpellInfluence@army@@QAEHHH@Z = 1
IMPORT_?CancelIndividualSpell@army@@QAEXH@Z = 1
IMPORT_?CastSpell@combatManager@@QAEXHHHH@Z = 1
IMPORT_?InitClean@army@@QAEXXZ = 1
IMPORT_?ShowSpellMessage@combatManager@@QAEXHHPAVarmy@@@Z = 1
IMPORT_?WalkTo@army@@QAEHH@Z = 1
IMPORT_?ValidPath@army@@QAEHHH@Z = 1
IMPORT_?FindPath@army@@QAEHHHHHH@Z = 1
?FindPath@army@@QAEHHHHHH@Z_clone EQU ?FindPath_orig@army@@QAEHHHHHH@Z
IMPORT_?SetupCombat@combatManager@@QAEXHHPAVhero@@PAVarmyGroup@@PAVtown@@01HHH@Z = 1
?SetupCombat@combatManager@@QAEXHHPAVhero@@PAVarmyGroup@@PAVtown@@01HHH@Z_clone EQU ?SetupCombat_orig@combatManager@@QAEXHHPAVhero@@PAVarmyGroup@@PAVtown@@01HHH@Z
IMPORT_?ResetRound@combatManager@@QAEXXZ = 1
?ResetRound@combatManager@@QAEXXZ_clone EQU ?ResetRound_orig@combatManager@@QAEXXZ
IMPORT_?Init@army@@QAEXHHHHHH@Z = 1
?Init@army@@QAEXHHHHHH@Z_clone EQU ?Init_orig@army@@QAEXHHHHHH@Z
IMPORT_?AttackTo@army@@QAEHH@Z = 1
IMPORT_?CombatMessage@combatManager@@QAEXPADHHH@Z = 1
?CombatMessage@combatManager@@QAEXPADHHH@Z_clone EQU ?CombatMessage_orig@combatManager@@QAEXPADHHH@Z
?AttackTo@army@@QAEHH@Z_clone EQU ?AttackTo_orig@army@@QAEHH@Z
IMPORT_?GetCommand@combatManager@@QAEHH@Z = 1
?GetCommand@combatManager@@QAEHH@Z_clone EQU ?GetCommand_orig@combatManager@@QAEHH@Z
IMPORT_?SetCombatDirections@combatManager@@QAEXH@Z = 1
?SetCombatDirections@combatManager@@QAEXH@Z_clone EQU ?SetCombatDirections_orig@combatManager@@QAEXH@Z
IMPORT_?MeteorShower@combatManager@@QAEXH@Z = 1
IMPORT_?HandleCastSpell@@YIHAAUtag_message@@@Z = 1
IMPORT_?CastMassSpell@combatManager@@QAEXHH@Z = 1
IMPORT_?ViewSpells@combatManager@@QAEHH@Z = 1
IMPORT_?DrawToBuffer@army@@QAEXHHH@Z = 1
IMPORT_?DrawFrame@combatManager@@QAEXHHHHHHH@Z = 1
IMPORT_?CycleCombatScreen@combatManager@@QAEXXZ = 1
?CycleCombatScreen@combatManager@@QAEXXZ_clone EQU ?CycleCombatScreen_orig@combatManager@@QAEXXZ
IMPORT_?GetNextArmy@combatManager@@QAEHH@Z = 1
IMPORT_?KeepAttack@combatManager@@QAEXH@Z = 1
IMPORT_?CheckWin@combatManager@@QAEHPAUtag_message@@@Z = 1
?CheckWin@combatManager@@QAEHPAUtag_message@@@Z_clone EQU ?CheckWin_orig@combatManager@@QAEHPAUtag_message@@@Z
IMPORT_?DoHydraAttack@army@@QAEXH@Z = 1
IMPORT_?ProcessNextAction@combatManager@@QAEHAAUtag_message@@@Z = 1
?ProcessNextAction@combatManager@@QAEHAAUtag_message@@@Z_clone EQU ?ProcessNextAction_orig@combatManager@@QAEHAAUtag_message@@@Z

;;heroes
IMPORT_?cHeroTypeInitial@@3PADA = 1
IMPORT_?sCmbtHero@@3PAUSCmbtHero@@A = 1
IMPORT_?gAlignmentNames@@3PAPADA = 1
IMPORT_?gHeroSkillBonus@@3PAY113CA = 1
IMPORT_?cHeroTypeShortName@@3PAPADA = 1
IMPORT_?captainStats@@3PAY03CA = 1
IMPORT_?iGetSSByAlignment@@3PAY0N@EA = 1

;; adventure map
IMPORT_?SetVisibility@game@@QAEXHHHH@Z = 1
?SetVisibility@game@@QAEXHHHH@Z_clone EQU ?SetVisibility_orig@game@@QAEXHHHH@Z
IMPORT_?MakeAllWaterVisible@game@@QAEXH@Z = 1
?MakeAllWaterVisible@game@@QAEXH@Z_clone EQU ?MakeAllWaterVisible_orig@game@@QAEXH@Z

IMPORT_?MoveHero@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z = 1
?MoveHero@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z_clone EQU ?MoveHero_orig@advManager@@QAEPAVmapCell@@HHPAH00H0H@Z

IMPORT_?DoEvent@advManager@@QAEXPAVmapCell@@HH@Z = 1
?DoEvent@advManager@@QAEXPAVmapCell@@HH@Z_clone EQU ?DoEvent_orig@advManager@@QAEXPAVmapCell@@HH@Z
IMPORT_?QuickInfo@advManager@@QAEXHH@Z = 1
?QuickInfo@advManager@@QAEXHH@Z_clone EQU ?QuickInfo_orig@advManager@@QAEXHH@Z
IMPORT_?adventureMapLocations@@3PAPADA = 1

IMPORT_?UpdateTownLocators@advManager@@QAEXHH@Z = 1
IMPORT_?TownQuickView@advManager@@QAEXHHHH@Z = 1
IMPORT_?DrawCell@advManager@@QAEXHHHHHH@Z = 1
?DrawCell@advManager@@QAEXHHHHHH@Z_clone EQU ?DrawCell_orig@advManager@@QAEXHHHHHH@Z
IMPORT_?DrawCursor@advManager@@QAEXXZ = 1
IMPORT_?PuzzleDraw@advManager@@QAEXHHHH@Z = 1
?PuzzleDraw@advManager@@QAEXHHHH@Z_clone EQU ?PuzzleDraw_orig@advManager@@QAEXHHHH@Z

;;hero movement reminder
IMPORT_?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z = 1
?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z_clone EQU ?ProcessDeSelect_orig@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z

;; will join
IMPORT_?PlayerMonsterInteract@advManager@@QAEXPAVmapCell@@0PAVhero@@PAHHHHHH@Z = 1
?PlayerMonsterInteract@advManager@@QAEXPAVmapCell@@0PAVhero@@PAHHHHHH@Z_clone EQU ?PlayerMonsterInteract_orig@advManager@@QAEXPAVmapCell@@0PAVhero@@PAHHHHHH@Z
IMPORT_?ComputerMonsterInteract@advManager@@QAEXPAVmapCell@@PAVhero@@PAH@Z = 1
?ComputerMonsterInteract@advManager@@QAEXPAVmapCell@@PAVhero@@PAH@Z_clone EQU ?ComputerMonsterInteract_orig@advManager@@QAEXPAVmapCell@@PAVhero@@PAH@Z

;; forced ai chase
IMPORT_?EvaluateHeroEvent@philAI@@QAEHHHHHPAH@Z = 1
?EvaluateHeroEvent@philAI@@QAEHHHHHPAH@Z_clone EQU ?EvaluateHeroEvent_orig@philAI@@QAEHHHHHPAH@Z
IMPORT_?ValueOfEventAtPosition@philAI@@QAEHHHHPAH@Z = 1
?ValueOfEventAtPosition@philAI@@QAEHHHHPAH@Z_clone EQU ?ValueOfEventAtPosition_orig@philAI@@QAEHHHHPAH@Z

;;;; border guards
IMPORT_?BarrierEvent@advManager@@QAEHPAVmapCell@@PAVhero@@@Z = 1
IMPORT_?PasswordEvent@advManager@@QAEXPAVmapCell@@PAVhero@@@Z = 1

;;saving
IMPORT_?LoadGame@game@@QAEXPADHH@Z = 1
?LoadGame@game@@QAEXPADHH@Z_clone EQU ?LoadGame_orig@game@@QAEXPADHH@Z
IMPORT_?SaveGame@game@@QAEHPADHC@Z = 1
IMPORT_?SaveGame@@YIHXZ = 1
IMPORT_?Read@hero@@QAEXHC@Z = 1
IMPORT_?Write@hero@@QAEXHC@Z = 1
IMPORT_?RandomizeHeroPool@game@@QAEXXZ = 1
IMPORT_?PickLoadGame@game@@QAEHXZ = 1

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
IMPORT_?SpellMessage@combatManager@@QAEXHH@Z = 1
IMPORT_?ValidSpellTarget@combatManager@@QAEHHH@Z = 1

;;towns
IMPORT_?gTownEligibleBuildMask@@3PAKA = 1
IMPORT_?gTownObjNames@@3PAPADA = 1
IMPORT_?gDwellingType@@3PAY0M@EA = 1
IMPORT_?gWellExtraNames@@3PAPADA = 1
IMPORT_?gSpecialBuildingNames@@3PAPADA = 1
IMPORT_?gBuildingInfoSpecial@@3PAPADA = 1
IMPORT_?gBuildingsToDraw@@3PAY0CA@W4BUILDING_CODE@@A = 1
IMPORT_?gTownPrefixNames@@3PAPADA = 1
IMPORT_?gSpecialBuildingCosts@@3PAUSBuildingCost@@A = 1
IMPORT_?gDwellingCosts@@3PAY0M@USBuildingCost@@A = 1
IMPORT_?gStartingHeroStats@@3PAUstartingPrimarySkills@@A = 1
IMPORT_??0townObject@@QAE@HHPAD@Z = 1
IMPORT_?SetupExtraStuff@townManager@@QAEXXZ = 1

IMPORT_??_7recruitUnit@@6B@ = 1
IMPORT_??0recruitUnit@@QAE@PAVarmyGroup@@HPAF@Z = 1
IMPORT_??0recruitUnit@@QAE@PAVtown@@HH@Z = 1
IMPORT_?Update@recruitUnit@@QAEXXZ = 1
IMPORT_?SetupRecruitWin@@YIXPAVheroWindow@@HHHHH@Z = 1
IMPORT_?SetupTowns@game@@QAEXXZ = 1
IMPORT_?SetupMage@townManager@@QAEXPAVheroWindow@@@Z = 1
IMPORT_?SetupWell@townManager@@QAEXPAVheroWindow@@@Z = 1
?SetupWell@townManager@@QAEXPAVheroWindow@@@Z_clone EQU ?SetupWell_orig@townManager@@QAEXPAVheroWindow@@@Z
IMPORT_?RecruitHero@townManager@@QAEHHH@Z = 1
?RecruitHero@townManager@@QAEHHH@Z_clone EQU ?RecruitHero_orig@townManager@@QAEHHH@Z
IMPORT_?GetBuildingName@@YIPADHH@Z = 1
?Open@townManager@@UAEHH@Z_clone EQU ?Open_orig@townManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?Open@recruitUnit@@UAEHH@Z = 1
?Open@recruitUnit@@UAEHH@Z_clone EQU ?Open_orig@recruitUnit@@QAEHH@Z
IMPORT_?GetBuildingInfo@@YIPADHHH@Z = 1
?GetBuildingInfo@@YIPADHHH@Z_clone EQU ?GetBuildingInfo_orig@@YIPADHHH@Z
IMPORT_?Main@townManager@@UAEHAAUtag_message@@@Z = 1
IMPORT_?SetupCastle@townManager@@QAEXPAVheroWindow@@H@Z = 1
IMPORT_?gHierarchyMask@@3PAY0M@KA = 1
IMPORT_?CanBuild@@YIHPAVtown@@H@Z = 1
IMPORT_?getCastleOwnedIdx@@YAHPAVplayerData@@H@Z = 1
IMPORT_?BuyBuild@townManager@@QAEHHHH@Z = 1
?BuyBuild@townManager@@QAEHHHH@Z_clone EQU ?BuyBuild_orig@townManager@@QAEHHHH@Z

;;scripting hooks
IMPORT_?PerDay@game@@QAEXXZ = 1
?PerDay@game@@QAEXXZ_clone EQU ?PerDay_orig@game@@QAEXXZ
IMPORT_?PerWeek@game@@QAEXXZ = 1
?PerWeek@game@@QAEXXZ_clone EQU ?PerWeek_orig@game@@QAEXXZ
IMPORT_?PerMonth@game@@QAEXXZ = 1
?PerMonth@game@@QAEXXZ_clone EQU ?PerMonth_orig@game@@QAEXXZ
IMPORT_?Open@advManager@@UAEHH@Z = 1
IMPORT_?Open@townManager@@UAEHH@Z = 1
?Open@townManager@@UAEHH@Z_clone EQU ?Open_orig@townManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?CheckEndGame@@YIXHH@Z = 1
?CheckEndGame@@YIXHH@Z_clone EQU ?CheckEndGame_orig@@YIXHH@Z
IMPORT_?InitNewGame@game@@QAEXPAUSMapHeader@@@Z = 1
?InitNewGame@game@@QAEXPAUSMapHeader@@@Z_clone EQU ?InitNewGame_orig@game@@QAEXPAUSMapHeader@@@Z

;; AI
IMPORT_?RedistributeTroops@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z = 1
?RedistributeTroops@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z_clone EQU ?RedistributeTroops_orig@philAI@@QAEXPAVarmyGroup@@0HHHHH@Z

;; Campaigns
IMPORT_?InitNewCampaign@ExpCampaign@@QAEXH@Z = 1
IMPORT_?InitMap@ExpCampaign@@QAEXXZ = 1
IMPORT_?Autosave@ExpCampaign@@QAEXXZ = 1
IMPORT_?UpdateInfo@ExpCampaign@@QAEXH@Z = 1
IMPORT_?SmackManagerMain@@YIXXZ = 1
IMPORT_?ExpansionCampaignRect@@YIHHH@Z = 1
IMPORT_?HandleVictory@ExpCampaign@@QAEHXZ = 1
IMPORT_?ShowInfo@ExpCampaign@@QAEXHH@Z = 1
IMPORT_?PlaySmacker@@YIHH@Z = 1
?PlaySmacker@@YIHH@Z_clone EQU ?PlaySmacker_orig@@YIHH@Z
IMPORT_?ReplaySmacker@ExpCampaign@@QAEXXZ = 1