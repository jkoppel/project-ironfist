#include "../../include2023/patcher_x86.hpp"
#include "../../include2023/gui.h"
#include "../../include2023/managers.h"
#include "../../include2023/map.h"
#include "../../include2023/game.h"
#include "../../include2023/combat.h"

#include <math.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

Patcher* _P;
PatcherInstance* _PI;

static _bool_ plugin_On = 0;

// 0x4F3D90 for En 2.1
creatureUpgrades gpCreatureUpgrades[6];

int giLimitPlayer;
bool gbGameOver;
bool gbRetreatWin;
bool gbIAmGreatest;
int giShowComputerRoute;
game* gpGame = new game();
hero* gpCurAIHero = new hero();
combatManager* gpCombatManager = new combatManager();
heroWindowManager* gpWindowManager = new heroWindowManager();
resourceManager* gpResourceManager = new resourceManager();
SSpellInfo gsSpellInfo[48];
int giCurPlayer;
playerData* gpCurPlayer = new playerData();
mouseManager* gpMouseManager = new mouseManager();
bool gbHumanPlayer[6];
float gfAttackHumanBonus;
float gfAttackComputerBonus;
int gArtifactBaseRV[103];
tag_monsterInfo gMonsterDatabase[66];
float gfSSAIArcheryMod[4];
float gfStatPower[40];
float maxAIDurationMod = 1.74;
float maxAISpellPowerMod = 6.15;
float gfPhilAIDurationMod[12];
float gfPhilAISpellPowerMod[12];
float gfSpellCastNumMod[12];
float gfSpellTypeNumMod[12];
int iAlphaMale;
int giCurTurn;
int gSSValues[13][3];
void* gpPhilAI;
advManager* gpAdvManager = new advManager();
char* mapRevealed;
char giGroundToTerrain[32 * 8];
char gDwellingType[12 * 6];

int gDwellingBaseResourceValues[12 * 6];
int gSpecialBuildingBaseResourceValues[6];
int gNeutralBaseResourceValues[20];
int gMageBaseResourceValues[6];

SBuildingCost gDwellingBuildingCosts[12 * 6];
SBuildingCost gSpecialBuildingCosts[6];
SBuildingCost gNeutralBuildingCosts[20];
SBuildingCost gMageBuildingCosts[6];
SBuildingCost xShrineBuildingCost;

bool gbPossibleShipyardFound;
bool gbActualShipyardFound;
int giBestShipyardDist;
int giBestShipyardId;
int giBuildShipyard[6];
int giBuildBoat[6];
int giBuildBoatStuffTurn[6];

bool gbTroopReload;
bool gbBerserk;
int iCurHourGlassPhase;
int iSandAnim;
int iDummy;
bool gbReduceByReload;
bool gbReduceByBerserk;

int gResourceBaseValue[7];
float gafAITurnCostResource[7];
float gfHeroInteractionBonus[54];
int giMaxHeroesForThisPlayer;

float fFirstWeekTownFV;

int MAP_WIDTH;
int MAP_HEIGHT;

searchArray SVSearchArray;
searchArray* gpSearchArray = new searchArray();
searchGridArray* gpSearchGridArray = new searchGridArray();

int gaiHeroLiveChance[54];

bool bHeroBuiltThisTurn;
bool bSVSearchArrayInUse;
bool bStopOnTrigger[128];

bool* gaiEnemyHeroReachable;
short* gaiLiveChanceOfPos;
short* gaiHeroStrategicRVOfPos;
short* gaiHeroEventStratRVOfPos;
char* gaiTurnValueOfMine;

float fReduceFactor;
float fBerserkFactor;

char normalDirTable[32];

int giCurAIHeroMorale;
int giCurAIHeroLuck;
int giHumanTownConquered = -1;
int iCurPlaceToVisit = 0;
char giCurPlayerBit;

int blackoutComputer;
int gbRemoteOn;
int giThisNetPos;
bool xNetHasOldPlayers = false;
char giCurWatchPlayerBit;
bool bShowIt;

placesVisited iPlacesVisited[1248];

int giCurTempMobility;

int giAdjacentMonsterUpperBoundX;
int giAdjacentMonsterUpperBoundY;
int giAdjacentMonsterX;
int giAdjacentMonsterY;
int giAdjacentMonsterLowerBoundX;
int giAdjacentMonsterLowerBoundY;

int giFullySeeded;
int giSeedingValid;

bool gbActualBoatFound;
char puzzlePiecesRemoved[8];
int gHeroGoldCost;

armyGroup* gpMonGroup;

int giTerrainCost[80];

int iLastSeed;
int giSeed;
char captainStats[6*4];
bool bIsMoatSlowed[116];
unsigned char moatHexIdxInRow[9] = { 8u, 21u, 33u, 46u, 58u, 72u, 85u, 99u, 112u};

float gfSSArcheryMod[4] = {1.0, 1.1, 1.25, 1.5};

int giNextAction;
int giNextActionGridIndex;

bool xIsExpansionMap;
int glTimers;
char *cTextReceivedBuffer;
char byte_5111B0[33];
char *cNGKPCore;
char byte_5111F4[4] = {0,0,0,0};
char *cNGKPDisplay;
char byte_5111F8[4] = {0,0,0,0};
int NGKPcursorIndex;
icon* NGKPBkg;
int gbWaitForRemoteReceive;
int giNumHumanPlayers;
int gbNewGameDialogOver;
char gsNetPlayerInfo[204];
char *gMapName;
int iMPBaseType;
int gbNewGameShadowHidden;

// примеры label:
// "Build improvement:", "Speed", "Monster Info", "Mouse Cursor", "Spell Power", "Best Hero:"
SWinSetup gWinSetup[73];

int gTownEligibleBuildMask[] = { 1073266591, 469286815, 267960223, 1777909663, 905494431, 536395675 };
int gbInNewGameSetup;
char gcColorToPlayerPos[] = {0,1,2,3,4,5,0,0};
char gcColorToSetupPos[8];
char gbSetupGamePosToRealGamePos[8];
char gText[768];
char bMapInitialized;
int iMaxMapExtra;
void** ppMapExtra;
short* pwSizeOfMapExtra;
char gArtifactLevel[103];
short giUARadius;
short giUABaseX;
short giUABaseY;
short RandMineQty[7];
bool xIsPlayingExpansionCampaign;
int giCurWatchPlayer;
int* xPasswordStringsIndex;
char giVisRange[8] = {4, 5, 6, 7, 0, 0, 0, 0};

int giPlayerInitialResourcesHuman[5][7] =
{
  { 30, 10, 30, 10, 10, 10, 10000 },
  { 20, 5, 20, 5, 5, 5, 7500 },
  { 10, 2, 10, 2, 2, 2, 5000 },
  { 5, 0, 5, 0, 0, 0, 2500 },
  { 0, 0, 0, 0, 0, 0, 0 }
};
int giPlayerInitialResourcesAI[5][7] =
{
  { 20, 5, 20, 5, 5, 5, 7500 },
  { 20, 5, 20, 5, 5, 5, 7500 },
  { 30, 10, 30, 10, 10, 10, 10000 },
  { 30, 10, 30, 10, 10, 10, 10000 },
  { 30, 10, 30, 10, 10, 10, 10000 }
};

int gbInCampaign;
void* xCampaign;

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if ( DLL_PROCESS_ATTACH == ul_reason_for_call)
    {
        if (!plugin_On)
        {
            plugin_On = 1;       
            _P = GetPatcher();
            _PI = _P->CreateInstance("H2_FullReverse");

        }
    }

   return TRUE;
}


