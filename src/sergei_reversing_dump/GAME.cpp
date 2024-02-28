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

extern char puzzlePiecesRemoved[8];
extern advManager* gpAdvManager;
extern int MAP_HEIGHT;
extern int MAP_WIDTH;
extern char bMapInitialized;
extern searchArray* gpSearchArray;
extern char* mapRevealed;
extern char gText[768];
extern int iMaxMapExtra;
extern void** ppMapExtra;
extern short* pwSizeOfMapExtra;
extern bool xIsExpansionMap;
extern char gArtifactLevel[103];
extern bool xIsPlayingExpansionCampaign;
extern char gcColorToSetupPos[8];
extern char giGroundToTerrain[32 * 8];
extern short RandMineQty[7];
extern short giUARadius;
extern short giUABaseX;
extern short giUABaseY;
extern tag_monsterInfo gMonsterDatabase[66];
extern int giCurPlayer;
extern int* xPasswordStringsIndex;
extern SSpellInfo gsSpellInfo[48];
extern bool gbHumanPlayer[6];
extern int giCurTurn;
extern int gbInCampaign;
extern char* gMapName;
extern int gTownEligibleBuildMask[6];
extern int gbInNewGameSetup;
extern playerData* gpCurPlayer;
extern game* gpGame;
extern char giCurPlayerBit;
extern char giCurWatchPlayerBit;
extern int giCurWatchPlayer;
extern int giNumHumanPlayers;
extern char gbSetupGamePosToRealGamePos[8];
extern char gcColorToPlayerPos[8];
extern char giVisRange[8];
extern void* xCampaign;
extern int giPlayerInitialResourcesHuman[5][7];
extern int giPlayerInitialResourcesAI[5][7];
extern void* gpPhilAI;
extern int gbRemoteOn;
extern int giThisNetPos;
extern bool xNetHasOldPlayers;
extern heroWindowManager* gpWindowManager;
extern int glTimers;
extern char *cTextReceivedBuffer;
extern char byte_5111B0[33];
extern char* cNGKPCore;
extern char* cNGKPDisplay;
extern char byte_5111F4[4];
extern char byte_5111F8[4];
extern int NGKPcursorIndex;
extern icon* NGKPBkg;
extern int gbWaitForRemoteReceive;
extern char gsNetPlayerInfo[204];
extern int gbNewGameDialogOver;
extern resourceManager* gpResourceManager;
extern int iMPBaseType;
extern int gbNewGameShadowHidden;

int GetNumObelisks(int playerIdx);
int Random(int a, int b);
mapCell* advManager_GetCell(advManager* am, int col, int row);
void searchArray_Init(searchArray* sa);
void FileError(char* a1);
BOOL fullMap_Read(fullMap* map, int fd, BOOL isNewGame);
bool IsCursedItem(int art);
void fullMap_ChangeTilesetIndex(fullMap* fm, mapCell *cell, int x, int y, int a5, int a6, int a7, int a8);
void SendMapChange(char a1, char a2, unsigned char a3, unsigned char a4, int a5, char a6, char a7);
BOOL advManager_FindAdjacentMonster(advManager* advM, int xPoint, int yPoint, int* xMonster, int* yMonster, int xUnwanted, int yUnwanted);
int FindLastToken(const char *a1, char a2);
char StrEqNoCase(int *a1, int *a2);
void hero_CheckLevel(hero* hero_1);
char ExpCampaign_HasAward(void* xCampaign, int a2);
int ExpCampaign_CampaignID(void* xCampaign);
char* ExpCampaign_JosephName(void* xCampaign);
char* ExpCampaign_IvanName(void* xCampaign);
void town_GiveSpells(town* town_1, hero* captain);
int philAI_GetGameAIVars(void* philAI_1);
void advManager_CheckSetEvilInterface(advManager* advM, int a2, int a3);
heroWindow* heroWindow_heroWindow(heroWindow* ecx0, int xOff, int yOff, char* filnam);
void MemError();
int ExpStdGameHandler(tag_message* evt);
void heroWindowManager_DoDialog(heroWindowManager* hwm, heroWindow* window, int (*a3)(tag_message *), int a4);
icon* resourceManager_GetIcon(resourceManager* rm, char* filename);
void PollSound();
void* GetRemoteData(char relinquish);
int heroWindow_BroadcastMessage(heroWindow* hw, tag_message *evt);
signed int NewGameHandler(tag_message *a1);
void heroWindowManager_DoDialog(heroWindowManager* hwm, heroWindow* window, int (*a3)(tag_message *), int a4);
signed int GetMapHeader(char *name, SMapHeader *hdr);
int TransmitRemoteData(const void *a1, int a2, int a3, char a4, char a5, char a6, char a7);
void ShutDown(char a1);
void SetWinText(heroWindow* window, int screenIdx);
void resourceManager_Dispose(resourceManager* rm, resource* res);

// Проверяет конкретный бит в целом наборе байтов (а не в одном байте)
bool BitTest(char* bits, unsigned int i)
{
  return (bits[i >> 3] & (1 << (i & 7))) != 0;
}

// Sets the ith bit of bits
void BitSet(char* bits, unsigned int i)
{
  bits[i >> 3] |= 1 << (i & 7);
}

int game_GetLuck(hero* hero_1, armyGroup* armyGroup_1, town* town_1)
{
	int x;

	return x;
}

int game_SetupPuzzlePieces(game* gp, int playerIdx, bool isAi)
{
  int i, k, l;
  int result;
  int nVisitedObelisks = GetNumObelisks(playerIdx);
  int numToReveal = 48 - gp->numObelisks;
  int visitedPart = (float)nVisitedObelisks / (float)gp->numObelisks;

  // reducedVisitedPart меньше чем visitedPart. Однако зависимость получается почти линейная (что бы вы об этом не думали)
  float reducedVisitedPart = (visitedPart * visitedPart + visitedPart) / 2.0;
  // все эти ухищрения нужны в том случае, когда обелисков на карте мало - но все равно все приводится к 48 исходным обелискам
  int reducedNumVisitedObelisks = numToReveal * reducedVisitedPart + nVisitedObelisks;
  if(nVisitedObelisks == gp->numObelisks)
    reducedNumVisitedObelisks = 48;
  // возможно _3_1[0] содержит какое-то дополнительное кол-во фиктивных обелисков в качестве форы для ИИ
  int nPieces = gp->players[playerIdx]._3_1[0] + reducedNumVisitedObelisks;
  if(nPieces > 48)
    nPieces = 48;
  if(isAi)
  {
    result = nPieces;
  }
  else
  {
    for(i = 0; i < 6; i++)
      puzzlePiecesRemoved[i] = 0;
    srand(3 * gp->players[playerIdx].hasEvilFaction + gp->players[playerIdx].color);
    for(int j = 0; j < nPieces; j++)
    {
	  // как только находим 0 в puzzlePiecesRemoved (закрытый кусок карты-загадки) - останавливаем цикл, L указывает на этот кусок
      for(l = 0; l < 48 && BitTest(puzzlePiecesRemoved, l); l += Random(1, 5))
        ;
	  // как только находим 0 в puzzlePiecesRemoved (закрытый кусок карты-загадки) - останавливаем цикл, k указывает на этот кусок
      for(k = 0; ; k++)
      {
        if(k < 100)
        {
          i = Random(0, 47);
          if(BitTest(puzzlePiecesRemoved, i))
            continue;
        }
        break;
      }
	  // если ничего не нашли на предыдущем цикле - проходимся подряд по puzzlePiecesRemoved, без рандома
      if(k >= 100)
      {
        for(i = 0; i < 48 && BitTest(puzzlePiecesRemoved, i); i++)
          ;
      }
      if(i >= 48 )
        i = 0;
	  // выбираем конечный результат либо из L прогона, либо из i
      if(l >= 48 )
        BitSet(puzzlePiecesRemoved, i);
      else
        BitSet(puzzlePiecesRemoved, l);
    }
    result = nPieces;
  }
  return result;
}

int game_ExperienceValueOfStack(armyGroup* armyGroup_1, hero* hero_1)
{
	int x;
	// здесь должен быть код

	return x;
}

int game_GetTownId(game* gp, int x, int y)
{
  for(int i = 0; i < 72; i++)
  {
    if(gp->castles[i].x == x && gp->castles[i].y == y )
      return i;
  }
  return -1;
}

void game_ClaimTown(game* game_1, int castleIdx, int playerIdx, int processMapChange)
{
	// здесь должен быть код

}

void game_CheckHeroConsistency(game* gp_1)
{

}

signed int game_CreateBoat(game* gp_1, unsigned int x, unsigned int y, int doSend)
{

  return 1;
}

int game_GetBoatsBuilt(game* gp_1)
{

  return 1;
}

void game_RestoreCell(int x, int y, int underlyingObjType, short underlyingObjExtra, mapCell* cell, int unused)
{
  mapCell* currentCell;

  if(cell)
    currentCell = cell;
  else
    currentCell = advManager_GetCell(gpAdvManager, x, y);
  if(y <= 0 || underlyingObjType != (LOCATION_TOWN | TILE_HAS_EVENT)
	  || advManager_GetCell(gpAdvManager, x, y-1)->objType == LOCATION_TOWN)
  {
    currentCell->objType = underlyingObjType;
	// * 8 эквив. сдвигу влево на 3
    currentCell->extraInfo = 8 * underlyingObjExtra | currentCell->extraInfo & 7;
  }
  else
  {
    currentCell->objType = 0;
	currentCell->flags &= 7u; // обнуляются все флаги, кроме 3-х правых (младших)
  }
}

void game_ClaimMine(game* gp, int idx, int color)
{

  return;
}

void game_UpdateNewGameWindow(game* game_1)
{
	
}

void game_InitNewGame(game* game_1, void* a2)
{
  //return game_1;
}

void game_InitNewGameWindow(game* game_1)
{
	
}

int game_SetupNetPlayerNames()
{
	
  return 1;
}

void game_RandomizeHeroPool(game* game_1)
{
  /*
  for(int heroIdx = 0; heroIdx < 54; heroIdx++)
  {
    game_1->heroes[heroIdx].experience = Random(0, 50) + 40;
    game_SetRandomHeroArmies(game_1, heroIdx, 0);
    game_1->heroes[heroIdx].remainingMobility = hero_CalcMobility(&game_1->heroes[heroIdx]);
    game_1->heroes[heroIdx].mobility = game_1->heroes[heroIdx].remainingMobility;
    game_1->heroes[heroIdx].randomSeed = Random(1, 255);
    game_1->heroes[heroIdx].wisdomLastOffered = 1;
    switch ( game_1->heroes[heroIdx].factionID )
    {
      case FACTION_SORCERESS:
        game_1->heroes[heroIdx].spellsLearned[SPELL_BLESS] = 1;
        break;
      case FACTION_WARLOCK:
        game_1->heroes[heroIdx].spellsLearned[SPELL_CURSE] = 1;
        break;
      case FACTION_NECROMANCER:
        game_1->heroes[heroIdx].spellsLearned[SPELL_HASTE] = 1;
        break;
      case FACTION_WIZARD:
        game_1->heroes[heroIdx].spellsLearned[SPELL_STONESKIN] = 1;
        break;
    }
  }
  */
  
}

void* game_SetMapSize(game* game_1, int w, int h)
{
  if( MAP_HEIGHT != h || MAP_WIDTH != w || !bMapInitialized)
  {
    bMapInitialized = 1;
    MAP_WIDTH = w;
    MAP_HEIGHT = h;
    searchArray_Init(gpSearchArray);
  }
  if(mapRevealed)
    free(mapRevealed);
  mapRevealed = (char*)malloc(MAP_HEIGHT * MAP_WIDTH);
  return memset(mapRevealed, 0, MAP_HEIGHT * MAP_WIDTH);
}

void game_LoadMap(game* game_1, char* mapname)
{
  char buf[2];
  char y;
  char x;
  char castleOrMineData;

  sprintf(gText, "%s%s", ".\\MAPS\\", mapname);
  int fd = open(gText, O_BINARY);//FILE* fd = fopen(gText, "b");

  if(fd == -1)
    FileError(gText);
  // читаем инфу из хедера карты в структуру игры
  _read(fd, &game_1->mapHeader, 420);
  // читаем высоту и ширину карты, клетки карты и extras
  fullMap_Read(&game_1->map, fd, 1);
  game_SetMapSize(game_1, game_1->map.width, game_1->map.height);
  // замки
  for(int i = 0; i < MAX_TOWNS; i++)
  {
    _read(fd, &x, 1);
    _read(fd, &y, 1);
    _read(fd, &castleOrMineData, 1);
    if((signed char)x != -1)
    {
      game_1->castles[i].exists = 1;
      game_1->castles[i].x = x;
      game_1->castles[i].y = y;
      game_1->castles[i].factionID = castleOrMineData & 0x7F; // первые 7 бит - фракция
      if ( castleOrMineData >= 0 ) // если старший бит равен 0
        game_1->castles[i].buildingsBuiltFlags |= BUILDING_TENT_BUILT;
      else // если старший бит равен 1
        game_1->castles[i].buildingsBuiltFlags |= BUILDING_CASTLE_BUILT;
    }
  }
  // шахты
  for(int i = 0; i < 144; i++)
  {
	// только половина если field_0 равно 90
    if(game_1->mapHeader.field_0 != 90 || i < 72)
    {
      _read(fd, &x, 1);
      _read(fd, &y, 1);
      _read(fd, &castleOrMineData, 1);
    }
    else
    {
      x = -1;
      y = -1;
      castleOrMineData = -1;
    }
    if((signed char)x != -1)
    {
      game_1->mines[i].guardianType = -1;
      game_1->mines[i].x = x;
      game_1->mines[i].y = y;
      game_1->mines[i].type = castleOrMineData;
    }
  }
  game_1->mapHeader.field_0 = 92;
  _read(fd, &game_1->numObelisks, 1);
  _read(fd, game_1->rumorIndices, 2 * game_1->mapHeader.numRumors);
  game_1->numRumors = game_1->mapHeader.numRumors;
  _read(fd, game_1->eventIndices, 2 * game_1->mapHeader.numEvents);
  game_1->numEvents = game_1->mapHeader.numEvents;
  _read(fd, &iMaxMapExtra, 4);
  ppMapExtra = (void**)malloc(4 * iMaxMapExtra);
  pwSizeOfMapExtra = (short*)malloc(2 * iMaxMapExtra);
  memset(ppMapExtra, 0, 4 * iMaxMapExtra);
  memset(pwSizeOfMapExtra, 0, 2 * iMaxMapExtra);
  for(int i = 1; i < iMaxMapExtra; i++)
  {
    _read(fd, &pwSizeOfMapExtra[i], 2);
    ppMapExtra[i] = malloc(pwSizeOfMapExtra[i]);
    _read(fd, ppMapExtra[i], pwSizeOfMapExtra[i]);
  }
  _read(fd, &buf, 2);
  _close(fd);

}

void game_InitRandomArtifacts(game* game_1)
{
  memset(game_1->artifactGeneratedRandomly, 0, 103);
  for(int i = 0; i < MAP_WIDTH; i++)
  {
    for(int j = 0; j < MAP_HEIGHT; j++)
    {
      if(game_1->map.tiles[j * game_1->map.width + i].objType == LOCATION_ARTIFACT | TILE_HAS_EVENT)
        game_1->artifactGeneratedRandomly[game_1->map.tiles[j * game_1->map.width + i].objectIndex >> 1] = 1;
    }
  }
}

int game_GetRandomArtifactId(game* game_1, char allowedLevels, int allowNegatives)
{
  int randArtifact;
  int tries = 0;
  while(1)
  {
    if(xIsExpansionMap)
      randArtifact = Random(0, MAX_EXPANSION_ARTIFACT);
    else
      randArtifact = Random(0, MAX_BASE_ARTIFACT);
    if((gArtifactLevel[randArtifact] & allowedLevels)
      && randArtifact != ARTIFACT_NONE1
      && randArtifact != ARTIFACT_NONE2
      && randArtifact != ARTIFACT_NONE3
      && randArtifact != ARTIFACT_NONE4
      && randArtifact != ARTIFACT_SPELL_SCROLL
      && (!xIsPlayingExpansionCampaign // в кампании аддона эти арты не выпадают
       || randArtifact != ARTIFACT_BREASTPLATE_OF_ANDURAN
       && randArtifact != ARTIFACT_BATTLE_GARB_OF_ANDURAN
       && randArtifact != ARTIFACT_HELMET_OF_ANDURAN
       && randArtifact != ARTIFACT_SWORD_OF_ANDURAN
       && randArtifact != ARTIFACT_SPHERE_OF_NEGATION) )
    {
      tries++;
	  // если такой арт еще не генерировался либо tries >= 100
      if ( tries >= 100 || !game_1->artifactGeneratedRandomly[randArtifact] )
      {
        if((!IsCursedItem(randArtifact) || allowNegatives && Random(0, 100) >= 30)
		// если случайный артефакт является условием победы, то он не выпадает
          && (game_1->mapHeader.winConditionType != WIN_CONDITION_FIND_ARTIFACT
           || game_1->mapHeader.winConditionArgumentOrLocX - 1 != randArtifact))
          break;
      }
    }
  }
  // ставим метку, что данный арт уже выпадал
  game_1->artifactGeneratedRandomly[randArtifact] = 1;
  return randArtifact;
}

void game_ConvertObject(game* game_1, int x1, int y1, int x2, int y2, int fromObjTileset, signed int fromObjIndexLow, signed int fromObjIndexHigh, char toObjTileset, char toObjectIndexLow, int fromObjType, char toObjType)
{

}

void game_RandomizeTown(game *game_1, int argX, int argY, BOOL isCastle)
{
  int townID;
  TownExtra* randomTownExtra;
  char faction;

  townID = game_GetTownId(game_1, argX, argY);
  randomTownExtra = (TownExtra*)ppMapExtra[game_1->map.tiles[argY * game_1->map.width + argX].extraInfo];
  if ( randomTownExtra->color == -1 )
    faction = Random(0, 5);
  else
    faction = game_1->newGameSelectedFaction[gcColorToSetupPos[randomTownExtra->color]];
  game_1->castles[townID].field_55 = 10;
  game_ConvertObject(game_1, argX - 5, argY - 3, argX + 2, argY + 1, 38, 0, 31, 35, 32 * faction, 48, 35);
  game_ConvertObject(game_1, argX - 5, argY - 3, argX + 2, argY + 1, 38, 32, 255, 37, 32 * faction, 48, 35);
  game_ConvertObject(game_1, argX - 5, argY - 3, argX + 2, argY + 1, 38, 0, 31, 35, 32 * faction, 49, 35);
  game_ConvertObject(game_1, argX - 5, argY - 3, argX + 2, argY + 1, 38, 32, 255, 37, 32 * faction, 49, 35);

  game_1->castles[townID].factionID = faction;

}

int game_GetMineId(game *game_1, int a2, int a3)
{

  for(int i = 0; i < 144; i++)
  {
    if(game_1->mines[i].x == a2 && game_1->mines[i].y == a3)
      return i;
  }
  return -1;
}

void game_RandomizeMine(game *game_1, int coordX, int coordY)
{
  char *v3; // ecx@47
  mapCell *v4; // ST4C_4@57
  mapCell *result; // eax@60

  char mineObjectIndex;
  int mineID;
  char mineObjectType;
  int mineType;
  int terrainIdx;
  char mineOverlayIndex;

  terrainIdx = giGroundToTerrain[game_1->map.tiles[coordY * game_1->map.width + coordX].groundIndex];

  for(int i = 0; i < 30; i++)
  {
    switch(terrainIdx)
    {
      case TERRAIN_IDX_GRASS:
      case TERRAIN_IDX_DIRT:
        mineType = Random(RESOURCE_MERCURY, RESOURCE_GOLD); // все, кроме ртути
        if ( mineType == RESOURCE_MERCURY )
          mineType = RESOURCE_WOOD;
        break;
      case TERRAIN_IDX_SNOW:
        mineType = Random(RESOURCE_ORE, RESOURCE_GOLD); // все, кроме ртути и дерева
        break;
      case TERRAIN_IDX_SWAMP:
        mineType = Random(RESOURCE_WOOD, RESOURCE_GOLD); // все
        break;
      case TERRAIN_IDX_LAVA:
        mineType = RESOURCE_MERCURY; // только ртуть
        break;
      default:
        mineType = Random(RESOURCE_MERCURY, RESOURCE_GOLD); // все кроме дерева
        break;
    }
    if(!RandMineQty[mineType])
      i = 30;
  }
  ++RandMineQty[mineType];
  if(mineType != RESOURCE_WOOD)
  {
    if(mineType == RESOURCE_MERCURY)
    {
      mineOverlayIndex = 25;
    }
    else if(terrainIdx == TERRAIN_IDX_GRASS)
    {
      mineOverlayIndex = 15;
    }
    else if(terrainIdx == TERRAIN_IDX_SNOW)
    {
      mineOverlayIndex = 19;
    }
    else
    {
      mineOverlayIndex = 9;
    }
  }
  else
  {
    mineOverlayIndex = 5;
  }
  if(mineType)
  {
    if(mineType == RESOURCE_MERCURY)
    {
      if(terrainIdx == TERRAIN_IDX_SWAMP)
      {
        mineObjectIndex = 43;
      }
      else if(terrainIdx == TERRAIN_IDX_LAVA)
      {
        mineObjectIndex = 35;
      }
      else
      {
        mineObjectIndex = 27;
      }
    }
    else
    {
      switch (terrainIdx)
      {
        case TERRAIN_IDX_GRASS:
          mineObjectIndex = 17;
          break;
        case TERRAIN_IDX_SNOW:
          mineObjectIndex = 21;
          break;
        case TERRAIN_IDX_SNOW|TERRAIN_IDX_GRASS:
          mineObjectIndex = 23;
          break;
        case 5:
          mineObjectIndex = 13;
          break;
        default:
          mineObjectIndex = 11;
          break;
      }
    }
  }
  else
  {
    mineObjectIndex = 7;
  }
  
  game_1->map.tiles[coordY * game_1->map.width + coordX].objectIndex = mineObjectIndex;
  game_1->map.tiles[coordY * game_1->map.width + coordX + 1].objectIndex = mineObjectIndex + 1;
  game_1->map.tiles[(coordY - 1) * game_1->map.width + coordX].overlayIndex = mineOverlayIndex;
  game_1->map.tiles[(coordY - 1) * game_1->map.width + coordX + 1].overlayIndex = mineOverlayIndex + 1;

  if(mineType == RESOURCE_MERCURY)
  {
    game_1->map.tiles[coordY * game_1->map.width + coordX + 1].animObject = 1;
    mineObjectType = LOCATION_ALCHEMIST_LAB;
  }
  else if(mineType)
  {
    fullMap_ChangeTilesetIndex(
      &game_1->map,
      (mapCell*)&game_1->map.tiles[coordY * game_1->map.width + coordX + 1],
      coordX + 1,
      coordY,
      29,
      mineType - 2,
      0,
      -1);
    mineObjectType = LOCATION_MINE;
  }
  else
  {
    mineObjectType = LOCATION_SAWMILL;
  }
  mineID = game_GetMineId(game_1, coordX, coordY);
  for(int relativeY = 0; relativeY < 2; relativeY++)
  {
    for(int relativeX = 0; relativeX < 2; relativeX++)
    {
      if(game_1->map.tiles[(coordY - relativeY) * game_1->map.width + coordX + relativeX].objType & ~TILE_HAS_EVENT <= 0
        || game_1->map.tiles[(coordY - relativeY) * game_1->map.width + coordX + relativeX].objType & ~TILE_HAS_EVENT > 48)
      {
        game_1->map.tiles[(coordY - relativeY) * game_1->map.width + coordX + relativeX].extraInfo = mineID;
        game_1->map.tiles[(coordY - relativeY) * game_1->map.width + coordX + relativeX].objType  = mineObjectType;
      }
    }
  }
  game_1->map.tiles[coordY * game_1->map.width + coordX].objType |= TILE_HAS_EVENT;
  game_1->mines[mineID].type = mineType;

}

void game_ProcessRandomObjects(game* game_1)
{

  char randomArtifactID;
  char randomArtifactIDTreasure;
  char randomArtifactIDMinor;
  char randomArtifactIDMajor;
  int randomResource;
  mapCell *cell;
  int minFightValue;
  int maxFightValue;

  giUABaseX = -1;
  giUABaseY = -1;
  giUARadius = 0;
  
  for(int resourceIdx = 0; resourceIdx < 7; resourceIdx++)
    RandMineQty[resourceIdx] = 0;

  for(int cellYCoord = 0; cellYCoord < MAP_HEIGHT; cellYCoord++)
  {
    for(int cellXCoord = 0; cellXCoord < MAP_WIDTH; cellXCoord++)
    {
      cell = &game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord];
      switch(cell->objType)
      {
        case TILE_HAS_EVENT | LOCATION_ULTIMATE_ARTIFACT:
          giUABaseX = cellXCoord;
          giUABaseY = cellYCoord;
          giUARadius = cell->extraInfo;
          cell->objType = 0;
          cell->objTileset = 0;
          cell->objectIndex = -1;
          continue; // идем к след. клетке
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN:
          game_RandomizeTown(game_1, cellXCoord, cellYCoord, 0);
          continue; // идем к след. клетке
        case TILE_HAS_EVENT|LOCATION_RANDOM_CASTLE:
          game_RandomizeTown(game_1, cellXCoord, cellYCoord, 1);
          continue; // идем к след. клетке
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER:
          minFightValue = 80;
          maxFightValue = 2000;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_WEAK:
          minFightValue = 0;
          maxFightValue = 400;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_MEDIUM:
          minFightValue = 400;
          maxFightValue = 1000;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_STRONG:
          minFightValue = 1000;
          maxFightValue = 2500;
		// слишком большой диапазон
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_VERY_STRONG:
          minFightValue = 2500;
          maxFightValue = 100000;

          if(cell->objTileset == TILESET_MONSTER
            && cell->objectIndex >= 67
            && cell->objectIndex <= 70)
          {
            switch(cell->objectIndex)
            {
              case 67:
                minFightValue = 0;
                maxFightValue = 400;
                break;
              case 68:
                minFightValue = 400;
                maxFightValue = 1000;
                break;
              case 69:
                minFightValue = 1000;
                maxFightValue = 2500;
                break;
              case 70:
                minFightValue = 2500;
                maxFightValue = 100000;
                break;
              default:
                break;
            }
          }
	      cell->objType = TILE_HAS_EVENT | LOCATION_ARMY_CAMP;
		  // Пробуем типы монстров, пока не попадем в диапазон от minFightValue до maxFightValue
          for(cell->objectIndex = Random(0, 65);
                gMonsterDatabase[cell->objectIndex].fight_value <= minFightValue
             || gMonsterDatabase[cell->objectIndex].fight_value >= maxFightValue;
                cell->objectIndex = Random(0, 65) )
            ;
	      // закончили с монстром, переходим к новой клетке
          break;
		  
        case TILE_HAS_EVENT | LOCATION_RANDOM_RESOURCE:
          cell->objType = TILE_HAS_EVENT | LOCATION_RESOURCE;
          randomResource = Random(0, 6);
          game_ConvertObject(
            game_1,
            cellXCoord - 1,
            cellYCoord,
            cellXCoord - 1,
            cellYCoord,
            46, // fromObjTileset (TILESET_OBJECT_RESOURCE)
            16, // fromObjIndexLow
            16, // fromObjIndexHigh
            46, // toObjTileset (TILESET_OBJECT_RESOURCE)
            2 * randomResource, // toObjectIndexLow
            -1, // fromObjType
            -1); // fromObjType
          game_ConvertObject(
            game_1,
            cellXCoord,
            cellYCoord,
            cellXCoord,
            cellYCoord,
            46,
            17,
            17,
            46,
            2 * randomResource + 1,
            -1,
            -1);
          if(randomResource != RESOURCE_WOOD && randomResource != RESOURCE_ORE)
          {
            if(randomResource == RESOURCE_GOLD)
              cell->extraInfo = Random(5, 10);
            else
              cell->extraInfo = Random(3, 7);
          }
          else
          {
            cell->extraInfo = Random(8, 16);
          }
          break;
        
		case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT:
		  // 14 = 8 + 4 + 2 - артефакт любого типа
          randomArtifactID = game_GetRandomArtifactId(game_1, 14, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          game_ConvertObject(
            game_1,
            cellXCoord - 1,
            cellYCoord,
            cellXCoord - 1,
            cellYCoord,
            11, // TILESET_ARTIFACT
            162,
            162,
            11,
            2 * randomArtifactID,
            -1,
            -1);
          game_ConvertObject(
            game_1,
            cellXCoord,
            cellYCoord,
            cellXCoord,
            cellYCoord,
            11, // TILESET_ARTIFACT
            163,
            163,
            11,
            2 * randomArtifactID + 1,
            -1,
            -1);
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_TREASURE:
          randomArtifactIDTreasure = game_GetRandomArtifactId(game_1, 8, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          game_ConvertObject(
            game_1,
            cellXCoord - 1,
            cellYCoord,
            cellXCoord - 1,
            cellYCoord,
            11, // TILESET_ARTIFACT
            166,
            166,
            11,
            2 * randomArtifactIDTreasure,
            -1,
            -1);
          game_ConvertObject(
            game_1,
            cellXCoord,
            cellYCoord,
            cellXCoord,
            cellYCoord,
            11, // TILESET_ARTIFACT
            167,
            167,
            11,
            2 * randomArtifactIDTreasure + 1,
            -1,
            -1);
          break;
        
		case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MINOR:
          randomArtifactIDMinor = game_GetRandomArtifactId(game_1, 4, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          game_ConvertObject(
            game_1,
            cellXCoord - 1,
            cellYCoord,
            cellXCoord - 1,
            cellYCoord,
            11, // TILESET_ARTIFACT
            168,
            168,
            11,
            2 * randomArtifactIDMinor,
            -1,
            -1);
          game_ConvertObject(
            game_1,
            cellXCoord,
            cellYCoord,
            cellXCoord,
            cellYCoord,
            11, // TILESET_ARTIFACT
            169,
            169,
            11,
            2 * randomArtifactIDMinor + 1,
            -1,
            -1);
          break;
        
		case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MAJOR:
          randomArtifactIDMajor = game_GetRandomArtifactId(game_1, 2, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          game_ConvertObject(
            game_1,
            cellXCoord - 1,
            cellYCoord,
            cellXCoord - 1,
            cellYCoord,
            11, // TILESET_ARTIFACT
            170,
            170,
            11,
            2 * randomArtifactIDMajor,
            -1,
            -1);
          game_ConvertObject(
            game_1,
            cellXCoord,
            cellYCoord,
            cellXCoord,
            cellYCoord,
            11, // TILESET_ARTIFACT
            171,
            171,
            11,
            2 * randomArtifactIDMajor + 1,
            -1,
            -1);
          break;
        
		case TILE_HAS_EVENT | LOCATION_RANDOM_MINE:
          game_RandomizeMine(game_1, cellXCoord, cellYCoord);
          break;
        default:
          continue;
      }
    }
  }
}

BOOL game_HasLateOverlay(game *game_1, int x, int y)
{
  BOOL result;
  mapCell *cell;
  mapCellExtra *cellExtra;

  cell = &game_1->map.tiles[y * game_1->map.width + x];
  if(cell->hasLateOverlay)
  {
    result = 1;
  }
  else
  {
    if(cell->extraIdx)
      cellExtra = &game_1->map.cellExtras[cell->extraIdx];
    else
      cellExtra = 0;
    while(cellExtra)
    {
      if(cellExtra->hasLateOverlay)
        return 1;
      if(cellExtra->nextExtraIdx)
        cellExtra = &game_1->map.cellExtras[cellExtra->nextExtraIdx];
      else
        cellExtra = 0;
    }
    result = 0;
  }
  return result;
}

void game_ConvertFlagToLateOverlay(game *game_1, int x, int y)
{
	
}

void game_ConvertAllToLateOverlay(game *game_1, int x, int y)
{
  mapCell *cell;
  mapCellExtra *cellExtra;

  cell = &game_1->map.tiles[y * game_1->map.width + x];
  if(cell->overlayIndex != 255)
    cell->hasLateOverlay = 1;
  if(cell->extraIdx)
    cellExtra = &game_1->map.cellExtras[cell->extraIdx];
  else
    cellExtra = 0;
  while(cellExtra)
  {
    if(cellExtra->overlayIndex != 255)
      cellExtra->hasLateOverlay = 1;
    if(cellExtra->nextExtraIdx)
      cellExtra = &game_1->map.cellExtras[cellExtra->nextExtraIdx];
    else
      cellExtra = 0;
  }	
}

void game_ProcessMapExtra(game *game_1)
{
  
  mapCell *cell;
  int townID;

  for(int townYCoord = 0;  townYCoord < MAP_HEIGHT; townYCoord++)
  {
    for(int townXCoord = 0; townXCoord < MAP_WIDTH; townXCoord++)
    {
      cell = &game_1->map.tiles[townYCoord * game_1->map.width + townXCoord];
      if(cell->objType == LOCATION_TOWN | TILE_HAS_EVENT ||
	    cell->objType >= LOCATION_RANDOM_TOWN | TILE_HAS_EVENT && cell->objType <= LOCATION_RANDOM_CASTLE | TILE_HAS_EVENT)
      {
        townID = game_GetTownId(game_1, townXCoord, townYCoord);
        game_1->castles[townID].extraIdx = cell->extraInfo;
        cell->extraInfo = townID;
      }
    }
  }
  for(int objYCoord = 0; objYCoord < MAP_HEIGHT; objYCoord++)
  {
    for(int objXCoord = 0; objXCoord < MAP_WIDTH; objXCoord++)
    {
      cell = &game_1->map.tiles[objYCoord * game_1->map.width + objXCoord];
      if(cell->objType == LOCATION_MINE | TILE_HAS_EVENT && objYCoord > 0 && game_HasLateOverlay(game_1, objXCoord, objYCoord - 1))
        game_ConvertFlagToLateOverlay(game_1, objXCoord, objYCoord);
      if(cell->objType == LOCATION_ALCHEMIST_LAB | TILE_HAS_EVENT)
      {
        if(objYCoord > 0)
          game_ConvertFlagToLateOverlay(game_1, objXCoord, objYCoord - 1);
        if(objYCoord > 1)
          game_ConvertFlagToLateOverlay(game_1, objXCoord, objYCoord - 2);
      }
    }
  }
  for(int coordY = 0; coordY < MAP_HEIGHT; coordY++)
  {
    for(int coordX = 0; coordX < MAP_WIDTH; coordX++)
    {
      if(game_HasLateOverlay(game_1, coordX, coordY))
        game_ConvertAllToLateOverlay(game_1, coordX, coordY);
    }
  }
}

void game_SetupTowns(game *game_1)
{
	
}

void game_InitializePasswords()
{
	
}

int game_Scan(game *game_1, signed char *a1, int start, int len)
{
  for(int i = start; i < start + len; i++)
  {
    if (a1[i] == -1)
      return i;
  }
  return -1;
}

int game_CreateBoat(game *game_1, int x, int y, int doNotSendMap)
{
  boat *boat;
  mapCell *cell;

  // ищем в массиве непостроенную лодку
  int boatIdx = game_Scan(game_1, (signed char*)&game_1->boatBuilt, 0, 48);
  if(boatIdx != -1)
  {
    if(!doNotSendMap)
      SendMapChange(4, 0, x, y, -999, 0, 0);
    game_1->boatBuilt[boatIdx] = boatIdx;
    boat = &game_1->boats[boatIdx];
    boat->idx = boatIdx;
    boat->x = x;
    boat->y = y;
    boat->direction = 2; // вправо
    boat->owner = giCurPlayer;
    cell = &game_1->map.tiles[y * game_1->map.width + x];
    boat->underlyingObjType = cell->objType;
    boat->underlyingObjExtra = cell->extraInfo;
    cell->objType = LOCATION_BOAT | TILE_HAS_EVENT;
    cell->extraInfo = boatIdx;
  }
  return boatIdx;
}

BOOL game_HasObjectTilesetIndex(game *game_1, int x, int y, int tileset, int index)
{
  BOOL result;
  mapCell *cell;
  mapCellExtra *cellExtra;

  cell = &game_1->map.tiles[y * game_1->map.width + x];
  if(cell->objTileset != tileset || cell->objectIndex != index)
  {
    if(cell->extraIdx)
      cellExtra = &game_1->map.cellExtras[cell->extraIdx];
    else
      cellExtra = 0;
    while(cellExtra)
    {
      if(cellExtra->objTileset == tileset && cellExtra->objectIndex == index)
        return 1;
      if(cellExtra->nextExtraIdx)
        cellExtra = &game_1->map.cellExtras[cellExtra->nextExtraIdx];
      else
        cellExtra = 0;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

int game_GetRandomNumTroops(game *game_1, int creature)
{
  int result;

  switch(creature)
  {
    case CREATURE_PEASANT:
      result = Random(40, 80);
      break;
    case CREATURE_ARCHER:
      result = Random(20, 30);
      break;
    case CREATURE_RANGER:
      result = Random(20, 30);
      break;
    case CREATURE_PIKEMAN:
      result = Random(20, 30);
      break;
    case CREATURE_VETERAN_PIKEMAN:
      result = Random(20, 30);
      break;
    case CREATURE_SWORDSMAN:
      result = Random(12, 25);
      break;
    case CREATURE_MASTER_SWORDSMAN:
      result = Random(12, 25);
      break;
    case CREATURE_CAVALRY:
      result = Random(10, 18);
      break;
    case CREATURE_CHAMPION:
      result = Random(8, 16);
      break;
    case CREATURE_PALADIN:
      result = Random(6, 12);
      break;
    case CREATURE_CRUSADER:
      result = Random(6, 10);
      break;
    case CREATURE_GOBLIN:
      result = Random(25, 40);
      break;
    case CREATURE_ORC:
      result = Random(15, 30);
      break;
    case CREATURE_ORC_CHIEF:
      result = Random(15, 30);
      break;
    case CREATURE_WOLF:
      result = Random(20, 35);
      break;
    case CREATURE_OGRE:
      result = Random(12, 25);
      break;
    case CREATURE_OGRE_LORD:
      result = Random(10, 20);
      break;
    case CREATURE_TROLL:
      result = Random(7, 10);
      break;
    case CREATURE_WAR_TROLL:
      result = Random(7, 10);
      break;
    case CREATURE_CYCLOPS:
      result = Random(5, 7);
      break;
    case CREATURE_SPRITE:
      result = Random(25, 45);
      break;
    case CREATURE_DWARF:
      result = Random(12, 25);
      break;
    case CREATURE_BATTLE_DWARF:
      result = Random(10, 22);
      break;
    case CREATURE_ELF:
      result = Random(15, 30);
      break;
    case CREATURE_GRAND_ELF:
      result = Random(12, 28);
      break;
    case CREATURE_DRUID:
      result = Random(10, 25);
      break;
    case CREATURE_GREATER_DRUID:
      result = Random(10, 20);
      break;
    case CREATURE_UNICORN:
      result = Random(8, 15);
      break;
    case CREATURE_PHOENIX:
      result = Random(7, 12);
      break;
    case CREATURE_CENTAUR:
      result = Random(20, 50);
      break;
    case CREATURE_GARGOYLE:
      result = Random(15, 30);
      break;
    case CREATURE_GRIFFIN:
      result = Random(12, 25);
      break;
    case CREATURE_MINOTAUR:
      result = Random(10, 16);
      break;
    case CREATURE_MINOTAUR_KING:
      result = Random(9, 16);
      break;
    case CREATURE_HYDRA:
      result = Random(7, 10);
      break;
    case CREATURE_GREEN_DRAGON:
      result = Random(4, 7);
      break;
    case CREATURE_RED_DRAGON:
      result = Random(3, 7);
      break;
    case CREATURE_BLACK_DRAGON:
      result = Random(3, 7);
      break;
    case CREATURE_HALFLING:
      result = Random(20, 50);
      break;
    case CREATURE_BOAR:
      result = Random(15, 30);
      break;
    case CREATURE_IRON_GOLEM:
      result = Random(10, 25);
      break;
    case CREATURE_STEEL_GOLEM:
      result = Random(10, 22);
      break;
    case CREATURE_ROC:
      result = Random(10, 16);
      break;
    case CREATURE_MAGE:
      result = Random(8, 12);
      break;
    case CREATURE_ARCHMAGE:
      result = Random(7, 11);
      break;
    case CREATURE_GIANT:
      result = Random(5, 8);
      break;
    case CREATURE_TITAN:
      result = Random(3, 7);
      break;
    case CREATURE_SKELETON:
      result = Random(20, 50);
      break;
    case CREATURE_ZOMBIE:
      result = Random(15, 30);
      break;
    case CREATURE_MUTANT_ZOMBIE:
      result = Random(15, 30);
      break;
    case CREATURE_MUMMY:
      result = Random(10, 25);
      break;
    case CREATURE_ROYAL_MUMMY:
      result = Random(10, 25);
      break;
    case CREATURE_VAMPIRE:
      result = Random(8, 12);
      break;
    case CREATURE_VAMPIRE_LORD:
      result = Random(8, 12);
      break;
    case CREATURE_LICH:
      result = Random(6, 10);
      break;
    case CREATURE_POWER_LICH:
      result = Random(6, 10);
      break;
    case CREATURE_BONE_DRAGON:
      result = Random(4, 8);
      break;
    case CREATURE_ROGUE:
      result = Random(20, 40);
      break;
    case CREATURE_NOMAD:
      result = Random(12, 25);
      break;
    case CREATURE_GHOST:
      result = Random(10, 20);
      break;
    case CREATURE_GENIE:
      result = Random(5, 10);
      break;
    case CREATURE_MEDUSA:
      result = Random(12, 20);
      break;
    case CREATURE_EARTH_ELEMENTAL:
      result = Random(13, 25);
      break;
    case CREATURE_AIR_ELEMENTAL:
      result = Random(13, 25);
      break;
    case CREATURE_FIRE_ELEMENTAL:
      result = Random(13, 25);
      break;
    case CREATURE_WATER_ELEMENTAL:
      result = Random(13, 25);
      break;
    default:
      result = 3;
      break;
  }
  return result;
}

void game_RandomizeBarrier(game *game_1, mapCell *cell)
{
  cell->extraInfo = 8 * xPasswordStringsIndex[cell->extraInfo];
}

void game_RandomizePassword(game *game_1, mapCell *cell)
{

  game_RandomizeBarrier(game_1, cell);
}

void game_WeeklyGenericSite(mapCell *cell)
{
  if(cell->extraInfo & 0x3F == 4)
  {
    cell->extraInfo &= 0x3F;
  }
}

void game_WeeklyRecruitSite(mapCell* cell)
{
  int nCreatures = cell->extraInfo >> 3; // 4-й бит и старше - имеющееся кол-во существ
  switch(cell->extraInfo & 7) // первые 3 бита - тип существа
  {
    case 0:
      nCreatures += Random(2, 5);
      break;
    case 1:
      nCreatures += Random(2, 5);
      break;
    case 2:
      nCreatures += Random(2, 5);
      break;
    case 3:
      nCreatures += Random(2, 5);
      break;
    case 4:
      nCreatures += Random(2, 5);
      break;
    default:
      break;
  }
  if(nCreatures > 1000)
    nCreatures = 1000;
  cell->extraInfo = (cell->extraInfo & 7) | 8 * nCreatures;
}

void game_RandomizeEvents(game *game_1)
{
  mapCell* cell;
  int nObelisk = 1;
  int nGazebo = 1;
  int nFort = 1;
  int nWitchDoctorHut = 1;
  int nMercenaryCamp = 1;
  int nStandingStone = 1;
  int nKnowledgeTree = 1;
  int nXanadu = 1;
  game_1->numMapEvents = 0;
  memset(game_1->mapEventIndices, 0, 100);
  
  sphinxMapExtra* sphinxExtra;
  EventExtra* evExtra;
  
  int dice;
  int artExtraInfo[10];
  int artId;
  int townID;
  town* town_1;
  int mineID;
  
  for(int cellYCoord = 0; cellYCoord < MAP_HEIGHT; cellYCoord++)
  {
    for(int cellXCoord = 0; cellXCoord < MAP_WIDTH; cellXCoord++)
    {
      cell = &game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord];
      switch ( cell->objType )
      {
        case TILE_HAS_EVENT | LOCATION_WITCH_HUT:
		  // получаем любой втор. навык, кроме 6 (SECONDARY_SKILL_LEADERSHIP) и 12 (SECONDARY_SKILL_NECROMANCY)
          for(cell->extraInfo = SECONDARY_SKILL_NECROMANCY;
              cell->extraInfo == SECONDARY_SKILL_NECROMANCY || cell->extraInfo == SECONDARY_SKILL_LEADERSHIP;
              cell->extraInfo = Random(0, 13))
            ;
          break;
        case TILE_HAS_EVENT | LOCATION_BOAT:
          cell->objTileset = 0;
          cell->objectIndex = -1;
          cell->extraInfo = 0;
          cell->objType = 0;
          game_CreateBoat(game_1, cellXCoord, cellYCoord, 1);
          break;
        case TILE_HAS_EVENT | LOCATION_SPHINX:
          sphinxExtra = (sphinxMapExtra*)ppMapExtra[cell->extraInfo];
          sphinxExtra->unclaimed = strlen((char*)&sphinxExtra->riddle) > 1 && sphinxExtra->numAnswers >= 1;
          break;
        case TILE_HAS_EVENT | LOCATION_EVENT:
          game_1->mapEventIndices[game_1->numMapEvents] = cell->extraInfo;
          evExtra = (EventExtra*)ppMapExtra[cell->extraInfo];
          evExtra->x = cellXCoord;
          evExtra->y = cellYCoord;
          evExtra->unclaimed = 1;
          cell->extraInfo = 0;
          cell->objType = 0;
          cell->objectIndex = -1;
          cell->objTileset = 0;
          ++game_1->numMapEvents;
          break;
        case TILE_HAS_EVENT | LOCATION_GAZEBO:
          cell->extraInfo = nGazebo++;
          break;
        case TILE_HAS_EVENT | LOCATION_FORT:
          cell->extraInfo = nFort++;
          break;
        case TILE_HAS_EVENT | LOCATION_WITCH_DOCTORS_HUT:
          cell->extraInfo = nWitchDoctorHut++;
          break;
        case TILE_HAS_EVENT | LOCATION_MERCENARY_CAMP:
          cell->extraInfo = nMercenaryCamp++;
          break;
		// 2 точки входа. сначала обрабатывается левая, потом правая
        case TILE_HAS_EVENT | LOCATION_STANDING_STONES:
          if(cellXCoord <= 0
            || game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord - 1].objType != LOCATION_STANDING_STONES | TILE_HAS_EVENT)
            cell->extraInfo = nStandingStone++;
          else
            cell->extraInfo = game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord - 1].extraInfo;
          break;
		case TILE_HAS_EVENT|LOCATION_XANADU:
          cell->extraInfo = nXanadu++;
          break;
        case LOCATION_WHIRLPOOL:
          cell->objType |= TILE_HAS_EVENT;
          break;
        case TILE_HAS_EVENT | LOCATION_OBELISK:
          cell->extraInfo = nObelisk++;
          break;
        case TILE_HAS_EVENT | LOCATION_FLOTSAM:
          cell->extraInfo = Random(0, 3);
          break;
        case TILE_HAS_EVENT | LOCATION_SKELETON:
          if(game_HasObjectTilesetIndex(game_1, cellXCoord, cellYCoord, 55, 84))
          {
            if(Random(0, 9) <= 2)
            {
              cell->extraInfo = game_GetRandomArtifactId(game_1, 14, 1) + 2;
            }
            else
            {
              cell->extraInfo = 1;
            }
          }
          else
          {
            cell->objType &= ~TILE_HAS_EVENT;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_WAGON:
          dice = Random(0, 100);
          if(dice >= 40)
          {
            if(dice >= 50)
            {
              cell->extraInfo = Random(0, 5) + 16 * Random(2, 5) + 1;
            }
            else
            {
              cell->extraInfo = game_GetRandomArtifactId(game_1, 12, 1) | 0x80;
            }
          }
          else
          {
            cell->extraInfo = 0;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_LEAN_TO:
          cell->extraInfo = Random(0, 5) + 16 * Random(1, 4) + 1;
          break;
        case TILE_HAS_EVENT | LOCATION_DAEMON_CAVE:
          switch(Random(0, 99) % 10)
          {
            case 0:
            case 1:
            case 2:
              cell->extraInfo = 2;
              break;
            case 3:
              cell->extraInfo = 3;
              break;
            case 4:
            case 5:
            case 6:
              cell->extraInfo = 4;
              break;
            case 7:
            case 8:
            case 9:
              cell->extraInfo = 5;
              break;
            default:
              continue;
          }
          continue; // сразу переходим к новой клетке
        case TILE_HAS_EVENT | LOCATION_TREASURE_CHEST:
          if(giGroundToTerrain[cell->groundIndex]) // если не море
          {
            dice = Random(0, 100);
            if(dice >= 32)
            {
              if(dice >= 64)
              {
                if(dice >= 95)
                {
                  cell->extraInfo = game_GetRandomArtifactId(game_1, ARTIFACT_LEVEL_TREASURE, 1) | 0x100; // артефакт-безделушка + 9-й бит в 1
                }
                else
                {
                  cell->extraInfo |= 4; // 3-й бит в 1
                }
              }
              else
              {
                cell->extraInfo |= 3; // 1-й и 2-й бит в 1
              }
            }
            else
            {
              cell->extraInfo |= 2; // 2-й бит в 1
            }
          }
          else
          {
            cell->objType = LOCATION_STUMP; // floatsam
            dice = Random(0, 100);
            if(dice >= 20)
            {
              if(dice >= 90)
              {
                cell->extraInfo = game_GetRandomArtifactId(game_1, ARTIFACT_LEVEL_TREASURE, 1) | 0x100; // артефакт-безделушка + 9-й бит в 1
              }
              else
              {
                cell->extraInfo |= 1;
              }
            }
            else
            {
              cell->extraInfo = 0;
            }
          }
          break;
        case TILE_HAS_EVENT | LOCATION_CAMPFIRE:
          cell->extraInfo = Random(4, 6) << 4;
          cell->extraInfo = cell->extraInfo | Random(0, 5);
          break;
        case TILE_HAS_EVENT | LOCATION_ANCIENT_LAMP:
          cell->extraInfo = Random(0, 2) + 2;
          break;
        case TILE_HAS_EVENT | LOCATION_SHIPWRECK_SURVIVOR:
          dice = Random(0, 100);
          if(dice >= 60)
          {
            if(dice >= 80)
            {
              cell->extraInfo = game_GetRandomArtifactId(game_1, ARTIFACT_LEVEL_MAJOR, 1); // старший артефакт
            }
            else
            {
              cell->extraInfo = game_GetRandomArtifactId(game_1, ARTIFACT_LEVEL_MINOR, 1); // младший артефакт
            }
          }
          else
          {
            cell->extraInfo = game_GetRandomArtifactId(game_1, ARTIFACT_LEVEL_TREASURE, 1); // артефакт-безделушка
          }
          break;
        case TILE_HAS_EVENT | LOCATION_GRAVEYARD:
        case TILE_HAS_EVENT | LOCATION_SHIPWRECK:
        case TILE_HAS_EVENT | LOCATION_DERELICT_SHIP:
          switch(Random(0, 99) % 10)
          {
            case 0:
            case 1:
            case 2:
              cell->extraInfo |= 2;
              break;
            case 3:
            case 4:
            case 5:
              cell->extraInfo |= 3;
              break;
            case 6:
            case 7:
            case 8:
              cell->extraInfo |= 4;
              break;
            case 9:
              cell->extraInfo |= 5;
              break;
            default:
              continue;
          }
          continue;
		case TILE_HAS_EVENT | LOCATION_ARCHERS_HOUSE:
          cell->extraInfo = Random(10, 25);
          break;
        case TILE_HAS_EVENT | LOCATION_GOBLIN_HUT:
          cell->extraInfo = Random(15, 40);
          break;
        case TILE_HAS_EVENT | LOCATION_DWARF_COTTAGE:
          cell->extraInfo = Random(0, 20) + 1;
          break;
        case TILE_HAS_EVENT | LOCATION_PEASANT_HUT:
          cell->extraInfo = Random(0, 40) + 1;
          break;
        case TILE_HAS_EVENT | LOCATION_LOG_CABIN:
          cell->extraInfo = Random(20, 50);
          break;
        case TILE_HAS_EVENT|LOCATION_WATERWHEEL:
          cell->extraInfo |= 1;
          break;
        case TILE_HAS_EVENT|LOCATION_ARTESIAN_SPRING:
          cell->extraInfo |= 1;
          break;
        case TILE_HAS_EVENT|LOCATION_MAGIC_GARDEN:
          if(Random(0, 1))
          {
            cell->extraInfo = RESOURCE_GOLD + 1;
          }
          else
          {
            cell->extraInfo = RESOURCE_GEMS + 1;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_TREE_OF_KNOWLEDGE:
          cell->extraInfo = nKnowledgeTree++ | Random(1, 3) << 6;
          break;
        case TILE_HAS_EVENT | LOCATION_ARMY_CAMP:
          if(!cell->extraInfo) // если пока нет информации о числе и лояльности монстров
          {
            cell->extraInfo = game_GetRandomNumTroops(game_1, cell->objectIndex);
            if(cell->objectIndex != CREATURE_GHOST)
            {
              if ( cell->objectIndex != CREATURE_EARTH_ELEMENTAL
                && cell->objectIndex != CREATURE_AIR_ELEMENTAL
                && cell->objectIndex != CREATURE_FIRE_ELEMENTAL
                && cell->objectIndex != CREATURE_WATER_ELEMENTAL
                && Random(0, 100) < 20)
                cell->extraInfo = cell->extraInfo | 0x1000; // 13-й бит - бит лояльности (20% шанс)
            }
          }
          break;
        case TILE_HAS_EVENT | LOCATION_RESOURCE:
          cell->extraInfo = cell->objectIndex >> 1;
          if(cell->extraInfo != RESOURCE_WOOD && cell->extraInfo != RESOURCE_ORE)
          {
            if(cell->extraInfo == RESOURCE_GOLD)
              cell->extraInfo = Random(5, 10);
            else
              cell->extraInfo = Random(3, 6);
          }
          else
          {
            cell->extraInfo = Random(5, 10);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_SHRINE_FIRST_ORDER:
          for(cell->extraInfo = Random(0, 64) + 1;
              gsSpellInfo[cell->extraInfo - 1].level != 1;
              cell->extraInfo = Random(0, 64) + 1)
            ;
          break;
        case TILE_HAS_EVENT | LOCATION_SHRINE_SECOND_ORDER:
          for(cell->extraInfo = Random(0, 64) + 1;
              gsSpellInfo[cell->extraInfo - 1].level != 2;
              cell->extraInfo = Random(0, 64) + 1)
            ;
          break;
        case TILE_HAS_EVENT | LOCATION_SHRINE_THIRD_ORDER:
          for(cell->extraInfo = Random(0, 64) + 1;
              gsSpellInfo[cell->extraInfo - 1].level != 3;
              cell->extraInfo = Random(0, 64) + 1)
            ;
          break;
        case TILE_HAS_EVENT | LOCATION_PYRAMID:
          for(cell->extraInfo = Random(0, 64) + 1;
              gsSpellInfo[cell->extraInfo - 1].level != 5;
              cell->extraInfo = Random(0, 64) + 1)
            ;
          break;
        case TILE_HAS_EVENT | LOCATION_TREE_HOUSE:
          cell->extraInfo = Random(15, 25);
          break;
        case TILE_HAS_EVENT | LOCATION_DWARF_CABIN:
          cell->extraInfo = Random(10, 20);
          break;
        case TILE_HAS_EVENT | LOCATION_WATCH_TOWER:
          cell->extraInfo = Random(7, 10);
          break;
        case TILE_HAS_EVENT | LOCATION_RUINS:
          cell->extraInfo = Random(3, 5);
          break;
        case TILE_HAS_EVENT | LOCATION_TREE_CITY:
          cell->extraInfo = Random(20, 40);
          break;
        case TILE_HAS_EVENT | LOCATION_HALFLING_HOLE:
          cell->extraInfo = Random(20, 40);
          break;
        case TILE_HAS_EVENT | LOCATION_TROLL_BRIDGE:
          cell->extraInfo = Random(4, 6) | 0x100;
          break;
        case TILE_HAS_EVENT | LOCATION_CITY_OF_DEAD:
          cell->extraInfo = Random(4, 6) | 0x100;
          break;
        case TILE_HAS_EVENT | LOCATION_DRAGON_CITY:
          cell->extraInfo = 0x102;
          break;
        case TILE_HAS_EVENT | LOCATION_CAVE:
          cell->extraInfo = Random(10, 20);
          break;
        case TILE_HAS_EVENT | LOCATION_EXCAVATION:
          cell->extraInfo = Random(10, 25);
          break;
        case TILE_HAS_EVENT | LOCATION_DESERT_TENT:
          cell->extraInfo = Random(10, 20);
          break;
        case TILE_HAS_EVENT | LOCATION_WAGON_CAMP:
          if(game_HasObjectTilesetIndex(game_1, cellXCoord, cellYCoord, 41, 129))
            cell->extraInfo = Random(30, 50);
          else
            cell->objType &= ~TILE_HAS_EVENT;
          break;
        case TILE_HAS_EVENT | LOCATION_ARTIFACT:
          dice = Random(0, 99);
          artId = cell->objectIndex >> 1;
          if(artId != ARTIFACT_SPELL_SCROLL)
          {
            if(dice >= 60)
            {
              if(dice >= 80)
              {
                artExtraInfo[0] = CREATURE_PALADIN;
                artExtraInfo[1] = CREATURE_CRUSADER;
                artExtraInfo[2] = CREATURE_CYCLOPS;
                artExtraInfo[3] = CREATURE_GENIE;
                artExtraInfo[4] = CREATURE_GREEN_DRAGON;
                artExtraInfo[5] = CREATURE_RED_DRAGON;
                artExtraInfo[6] = CREATURE_BLACK_DRAGON;
                artExtraInfo[7] = CREATURE_BONE_DRAGON;
                artExtraInfo[8] = CREATURE_GIANT;
                artExtraInfo[9] = CREATURE_TITAN;
                cell->extraInfo = 0x100;
                if(gArtifactLevel[artId] == ARTIFACT_LEVEL_TREASURE)
                {
                  cell->extraInfo = cell->extraInfo | 0x39;
                }
                else if(gArtifactLevel[artId] == ARTIFACT_LEVEL_MINOR)
                {
                  cell->extraInfo = cell->extraInfo | artExtraInfo[Random(0, 3)];
                }
                else
                {
                  cell->extraInfo = cell->extraInfo | artExtraInfo[Random(0, 5) + 4];
                }
              }
              else
              {
                switch(gArtifactLevel[artId])
                {
                  case ARTIFACT_LEVEL_TREASURE:
                    cell->extraInfo = 3;
                    break;
                  case ARTIFACT_LEVEL_MINOR:
                    cell->extraInfo = (16 * Random(0, 5)) | 6;
                    break;
                  case ARTIFACT_LEVEL_MAJOR:
                    cell->extraInfo = (16 * Random(0, 5)) | 7;
                    break;
                }
              }
            }
            else if(dice % 10 == 1)
            {
              cell->extraInfo = 4;
            }
            else if(dice % 10 == 2)
            {
              cell->extraInfo = 5;
            }
            else
            {
              cell->extraInfo = 1;
            }
          }
          break;
        case TILE_HAS_EVENT | LOCATION_TOWN:
          townID = game_GetTownId(game_1, cellXCoord, cellYCoord);
          for(int i = cellYCoord - 3; i <= cellYCoord + 1; i++)
          {
            for(int j = cellXCoord - 2; j <= cellXCoord + 2; j++)
            {
              if(!game_1->map.tiles[i * game_1->map.width + j].extraInfo)
              {
                game_1->map.tiles[i * game_1->map.width + j].extraInfo = townID;
              }
            }
          }
          town_1 = &game_1->castles[townID];
          game_1->castles[townID].boatY = -1;
          town_1->boatX = town_1->boatY;
          if(cellYCoord <= MAP_HEIGHT - 3)
          {
			// пытаемся найти место для верфи - сначала слева от ворот, если не нашли, то справа от ворот
            cell = advManager_GetCell(gpAdvManager, cellXCoord - 1, cellYCoord + 2);
            if(giGroundToTerrain[cell->groundIndex])
            {
              cell = advManager_GetCell(gpAdvManager, cellXCoord + 1, cellYCoord + 2);
              if(!giGroundToTerrain[cell->groundIndex])
              {
                town_1->boatX = cellXCoord + 1;
                town_1->boatY = cellYCoord + 2;
              }
            }
            else
            {
              town_1->boatX = cellXCoord - 1;
              town_1->boatY = cellYCoord + 2;
            }
          }
          break;
        case TILE_HAS_EVENT | LOCATION_LIGHTHOUSE:
          game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord].extraInfo = game_GetMineId(game_1, cellXCoord, cellYCoord);
          break;
        case TILE_HAS_EVENT | LOCATION_ABANDONED_MINE:
          game_1->mines[game_GetMineId(game_1, cellXCoord, cellYCoord)].guardianType = CREATURE_GHOST;
          game_1->mines[game_GetMineId(game_1, cellXCoord, cellYCoord)].guardianQty = Random(30, 60);
          mineID = game_GetMineId(game_1, cellXCoord, cellYCoord);
          for(int i = cellYCoord - 1; i <= cellYCoord; i++)
          {
            for(int j = cellXCoord - 2; j <= cellXCoord + 1; j++)
            {
              //if((j != cellXCoord - 2 || cell->objType == LOCATION_ALCHEMIST_LAB | TILE_HAS_EVENT)
			  if((j != cellXCoord - 2)
                && (!game_1->map.tiles[i * game_1->map.width + j].extraInfo // если extraInfo пусто либо если objType одинаковы
                || !((cell->objType & ~TILE_HAS_EVENT) ^ (game_1->map.tiles[game_1->map.width + j].objType & ~TILE_HAS_EVENT))))
              {
                game_1->map.tiles[i * game_1->map.width + j].extraInfo = mineID;
              }
            }
          }
          break;		  
        case TILE_HAS_EVENT | LOCATION_ALCHEMIST_LAB:
        case TILE_HAS_EVENT | LOCATION_MINE:
        case TILE_HAS_EVENT | LOCATION_SAWMILL:
          mineID = game_GetMineId(game_1, cellXCoord, cellYCoord);
          for(int i = cellYCoord - 1; i <= cellYCoord; i++)
          {
            for(int j = cellXCoord - 2; j <= cellXCoord + 1; j++)
            {
              if((j != cellXCoord - 2 || cell->objType == LOCATION_ALCHEMIST_LAB | TILE_HAS_EVENT)
                && (!game_1->map.tiles[i * game_1->map.width + j].extraInfo // если extraInfo пусто либо если objType одинаковы
                || !((cell->objType & ~TILE_HAS_EVENT) ^ (game_1->map.tiles[game_1->map.width + j].objType & ~TILE_HAS_EVENT))))
              {
                game_1->map.tiles[i * game_1->map.width + j].extraInfo = mineID;
              }
            }
          }
          break;
        case TILE_HAS_EVENT | LOCATION_WINDMILL:
          cell->extraInfo = Random(1, 5);
          break;
        case TILE_HAS_EVENT | LOCATION_BARRIER:
          game_RandomizeBarrier(game_1, cell);
          break;
        case TILE_HAS_EVENT | LOCATION_TRAVELLER_TENT:
          game_RandomizePassword(game_1, cell);
          break;
        case TILE_HAS_EVENT | LOCATION_ALCHEMIST_TOWER:
          game_WeeklyGenericSite(cell);
          break;
        case TILE_HAS_EVENT | LOCATION_EXPANSION_DWELLING:
          game_WeeklyRecruitSite(cell);
          break;
        default:
          continue;
      }
    }
  }

  mapCellExtra* extra;
  int nCellIndices;
  mapCell* cellBelow;
  int nCellBelowIndices;
  
  int cellTileset[5];
  int cellBelowTileset[5];
  int cellIndex[5];
  int cellBelowIndex[5];
  
  for(int cellYCoord = 0; cellYCoord < MAP_HEIGHT; cellYCoord++)
  {
    for(int cellXCoord = 0;  cellXCoord < MAP_WIDTH; cellXCoord++)
    {
      cell = &game_1->map.tiles[cellYCoord * game_1->map.width + cellXCoord];
      if((cell->objType & ~TILE_HAS_EVENT) == LOCATION_ROCK && cell->objTileset == TILESET_OBJECT_EXPANSION_2)
        cell->flags |= MAP_CELL_UNPASSABLE;
	  // если в клетке есть объект + есть оверлей + тайл неактивен + флаг MAP_CELL_OBJECT_WAS_ERASED то MAP_CELL_UNPASSABLE
      if(cell->objectIndex != 255 && !(cell->objType & TILE_HAS_EVENT) && !(cell->flags & MAP_CELL_OBJECT_WAS_ERASED) && cell->overlayIndex != 255)
        cell->flags |= MAP_CELL_UNPASSABLE;
      nCellIndices = 0;
      nCellBelowIndices = 0;
      if(!(cell->flags & MAP_CELL_UNPASSABLE)
        && cellYCoord < MAP_HEIGHT - 1 // если не в самом низу карты
        && cell->objectIndex != 255 // в клетке есть объект
        && !(cell->objType & TILE_HAS_EVENT) // клетка неактивна
        && !(cell->flags & MAP_CELL_OBJECT_WAS_ERASED) // нет флага 0x80
        && game_1->map.tiles[(cellYCoord + 1) * game_1->map.width + cellXCoord].objectIndex != 255 // в клетке выше есть объект
        && !(game_1->map.tiles[(cellYCoord + 1) * game_1->map.width + cellXCoord].objType & TILE_HAS_EVENT) // клетка выше неактивна
        && !(game_1->map.tiles[(cellYCoord + 1) * game_1->map.width + cellXCoord].flags & MAP_CELL_OBJECT_WAS_ERASED)) // клетка выше не имеет флага 0x80
      {
        if(!cell->isShadow) // если клетка - не тень объекта
        {
          cellTileset[nCellIndices] = cell->objTileset;
          cellIndex[nCellIndices] = cell->objectIndex;
		  nCellIndices++;
        }
        if(cell->extraIdx)
          extra = &game_1->map.cellExtras[cell->extraIdx];
        else
          extra = 0;
        while(nCellIndices < 5 && extra)
        {
          if(extra->objectIndex != 255 && !extra->isShadow)
          {
            cellTileset[nCellIndices] = extra->objTileset;
            cellIndex[nCellIndices] = extra->objectIndex;
			nCellIndices++;
          }
          if(extra->nextExtraIdx)
            extra = &game_1->map.cellExtras[extra->nextExtraIdx];
          else
            extra = 0;
        }
        cellBelow = &game_1->map.tiles[(cellYCoord + 1) * game_1->map.width + cellXCoord];
        if(!cellBelow->isShadow) // если клетка выше - не тень объекта
        {
          cellBelowTileset[nCellBelowIndices] = cellBelow->objTileset;
          cellBelowIndex[nCellBelowIndices] = cellBelow->objectIndex;
		  nCellBelowIndices++;
        }
        if(cellBelow->extraIdx)
          extra = &game_1->map.cellExtras[cellBelow->extraIdx];
        else
          extra = 0;
        while(nCellBelowIndices < 5 && extra)
        {
          if(extra->objectIndex != 255 && !extra->isShadow)
          {
            cellBelowTileset[nCellBelowIndices] = extra->objTileset;
            cellBelowIndex[nCellBelowIndices] = extra->objectIndex;
			nCellBelowIndices++;
          }
          if(extra->nextExtraIdx)
            extra = &game_1->map.cellExtras[extra->nextExtraIdx];
          else
            extra = 0;
        }
        for(int n = 0; n < nCellIndices; n++)
        {
          for(int  m = 0; m < nCellBelowIndices; m++)
          {
			// если одинаков хотя бы один tileset у 2 клеток - то верхняя непроходима
			// либо если клетка - город и клетка ниже - город
            if(cellBelowTileset[m] == cellTileset[n] || (cellTileset[n] >= 35 && cellTileset[n] <= 38 && cellBelowTileset[m] >= 35 && cellBelowTileset[m] <= 38))
              cell->flags |= MAP_CELL_UNPASSABLE;
          }
        }
      }
      if(cellYCoord < MAP_HEIGHT - 1
        && (game_1->map.tiles[(cellYCoord + 1) + cellXCoord].objType == LOCATION_TOWN | TILE_HAS_EVENT
         || game_1->map.tiles[(cellYCoord + 1) + cellXCoord].objType == LOCATION_RANDOM_TOWN | TILE_HAS_EVENT
         || game_1->map.tiles[(cellYCoord + 1) + cellXCoord].objType == LOCATION_RANDOM_CASTLE | TILE_HAS_EVENT))
        cell->flags |= MAP_CELL_UNPASSABLE;
      if(cell->objectIndex != 255
        && !(cell->objType & TILE_HAS_EVENT)
        && !(cell->flags & MAP_CELL_OBJECT_WAS_ERASED)
        && (cellYCoord == MAP_HEIGHT - 1
         || game_1->map.tiles[(cellYCoord + 1) + cellXCoord].flags & MAP_CELL_SEA2BEACH_RELATED_1))
        cell->flags |= MAP_CELL_UNPASSABLE;
    }
  }	  
		  
}

void game_ProcessOnMapHeroes(game *game_1)
{

}

void game_SetVisibility(game *game_1, int x, int y, int playerIdx, signed int radius)
{

  char playerBit = 1 << playerIdx;
  // ИИ получает еще и доп. радиус видимости
  if(!gbHumanPlayer[playerIdx])
  {
    if(giCurTurn <= 40)
    {
      if(giCurTurn <= 20)
        ++radius;
      else
        radius += 2;
    }
    else
    {
      radius += 3;
    }
  }
  int minDelta;
  if(radius < 5)
    minDelta = 2;
  else
    minDelta = 3;
  if(radius < 10)
  {
    for(int pointY = y - radius; pointY <= y + radius; pointY++)
    {
      for(int pointX = x - radius; pointX <= x + radius; pointX++)
      {
		// видимость - не квадрат, хотя и не идеальный круг
        if(minDelta <= 2 * radius - abs(y - pointY) - abs(x - pointX) && pointX >= 0 && pointY >= 0 && pointX < MAP_WIDTH && pointY < MAP_HEIGHT)
          *(&mapRevealed[pointY * MAP_WIDTH + pointX]) |= playerBit;
      }
    }
  }
  else
  {
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
      for(int j = 0; j < MAP_WIDTH; j++)
      {
        if(sqrt((double)((y - i) * (y - i) + (x - j) * (x - j))) < radius)
          *(&mapRevealed[j] + i * MAP_WIDTH) |= playerBit;
      }
    }
  }
}

int game_GetNewHeroId(game* game_1, int playerIdx, int faction, int getPowerfulHero)
{

  int heroIdx = -1;
  int tries = 0;
  while(tries < 2000)
  {
    ++tries;
    heroIdx = Random(0, 53);
    if(game_1->heroOwner[heroIdx] == -1 || game_1->heroOwner[heroIdx] == 64)
    {
	  // особые герои с owner 64 выпадают только если число попыток >= 1500
      if((game_1->heroOwner[heroIdx] != 64 || tries >= 1500)
        && (faction < 0 || faction > 5 || tries >= 100 || game_1->heroes[heroIdx].factionID == faction)
        && (!getPowerfulHero
         || tries >= 40
         || game_1->heroes[heroIdx].experience >= 1000
         || game_1->heroes[heroIdx].artifacts[0] != -1 && game_1->heroes[heroIdx].artifacts[0] != ARTIFACT_MAGIC_BOOK
         || game_1->heroes[heroIdx].artifacts[1] != -1 && game_1->heroes[heroIdx].artifacts[1] != ARTIFACT_MAGIC_BOOK))
      {
        if(!gbInCampaign || tries >= 500 || game_1->heroes[heroIdx].heroID < 54 || game_1->heroes[heroIdx].heroID > 59)
          break;
      }
    }
  }
  return heroIdx;
}

void game_SetupAdjacentMons(game* game_1)
{
  int monsterCoordY;
  int monsterCoordX;
  unsigned char bitMask = 0x7Fu;

  for(int x = 0; x < MAP_WIDTH; ++x)
  {
    for(int y = 0; y < MAP_HEIGHT; ++y)
    {
      if(advManager_FindAdjacentMonster(gpAdvManager, x, y, &monsterCoordX, &monsterCoordY, -1, -1))
        *(&mapRevealed[x + MAP_WIDTH * y]) |= 0x80;
      else
        *(&mapRevealed[x + MAP_WIDTH * y]) &= bitMask;
    }
  }
}

void game_SetupNewRumour(game* game_1)
{

}

void game_NewMap(game* game_1, char* mapname)
{

  char* expansionCampaignHeroName;
  char expansionCampaignHeroID;

  int dotAddress = FindLastToken(gMapName, 46);
  if(dotAddress && StrEqNoCase((int*)(dotAddress + 1), (int*)"MX2"))
    xIsExpansionMap = 1;
  // то что разрешено строить
  if(xIsExpansionMap)
	// для Некромантов разрешено строить Shrine
    gTownEligibleBuildMask[FACTION_NECROMANCER] |= 4u; // 3-й бит в 1
  else
	// для Некромантов запрещено строить Shrine
    gTownEligibleBuildMask[FACTION_NECROMANCER] &= 0xFFFFFFFBu; // 3-й бит в 0
  gbInNewGameSetup = 1;
  giCurPlayer = 0;
  gpCurPlayer = gpGame->players;
  giCurPlayerBit = 1;
  giCurWatchPlayerBit = 1;
  giCurWatchPlayer = 0;
  int randomFaction = Random(0, 5);
  int relatedToNumHumanPlayers = giNumHumanPlayers;
  for(int playerIdx = 0; playerIdx < 6; playerIdx++)
  {
    if(playerIdx < gpGame->mapHeader.numPlayers)
    {
      if(game_1->somePlayerCodeOr10IfMayBeHuman[playerIdx] == 10)
        gbSetupGamePosToRealGamePos[playerIdx] = relatedToNumHumanPlayers++;
      else
        gbSetupGamePosToRealGamePos[playerIdx] = game_1->somePlayerCodeOr10IfMayBeHuman[playerIdx];
    }
    else
    {
      gbSetupGamePosToRealGamePos[playerIdx] = -1;
    }
  }
  
  for(int playerIdxa = 0; playerIdxa < 6; playerIdxa++)
  {
    game_1->players[playerIdxa].color = -1;
    gcColorToPlayerPos[playerIdxa] = -1;
    gcColorToSetupPos[playerIdxa] = -1;
    if(gpGame->newGameSelectedFaction[playerIdxa] == FACTION_RANDOM)
      gpGame->newGameSelectedFaction[playerIdxa] = randomFaction;
    randomFaction = (randomFaction + 1) % 6;
  }
  for(int playerIdxb = 0;  playerIdxb < game_1->numPlayers; playerIdxb++)
    gcColorToSetupPos[game_1->relatedToPlayerPosAndColor[playerIdxb]] = playerIdxb;
  for(int playerIdxc = 0; playerIdxc < game_1->numPlayers; playerIdxc++)
    game_1->players[gbSetupGamePosToRealGamePos[playerIdxc]].color = game_1->relatedToPlayerPosAndColor[playerIdxc];
  for(int playerIdxd = 0;  playerIdxd < game_1->numPlayers; playerIdxd++)
    gcColorToPlayerPos[game_1->players[playerIdxd].color] = playerIdxd;

  for(int playerIdxe = 0; playerIdxe < game_1->numPlayers; playerIdxe++)
  {
    game_1->players[playerIdxe].numCastles = 0;
    game_1->players[playerIdxe].relatedToUnknown = 0;
    game_1->players[playerIdxe].curCastleIdx = -1;
    game_1->players[playerIdxe].numHeroes = 0;
    game_1->players[playerIdxe].relatedToSomeSortOfHeroCountOrIdx = 0;
    game_1->players[playerIdxe].curHeroIdx = -1;
  }
  game_RandomizeHeroPool(game_1);                // Check this function (design question; hardcoded, faction-specific data; SetupRandomHeroArmies does this as well)
  strcpy(gMapName, mapname);
  game_LoadMap(game_1, gMapName);
  game_InitRandomArtifacts(game_1);
  game_ProcessRandomObjects(game_1);             // Check this function (Creature limit constants; within RandomizeTown: faction limit constants)
  game_ProcessMapExtra(game_1);
  game_SetupTowns(game_1);                       // Check this function (design question; as the faction Idx increases, the chances of getting certain spells increases; this happens because faction ordering represents their aptitudes for magic)
  game_InitializePasswords();
  for(int playerIdxf = 0; playerIdxf < 6; playerIdxf++)
    game_1->players[playerIdxf].barrierTentsVisited = 0;
  game_RandomizeEvents(game_1);
  game_ProcessOnMapHeroes(game_1);
  game_1->couldBeNumDefeatedPlayers = 0;
  for(int playerIdxg = game_1->numPlayers; playerIdxg < 6; playerIdxg++)
    game_1->playerDead[playerIdxg] = 1;
  if(game_1->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_COLOR
    || game_1->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_HERO)
  {
    game_1->mapHeader.relatedToWinConditionType = 1;
    game_1->mapHeader.allowDefeatAllVictory = 0;
  }
  int numPlayers;
  if(game_1->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_COLOR)
  {
    numPlayers = 0;
    for(int playerIdxh = 0; playerIdxh < 6; playerIdxh++)
    {
      if(game_1->mapHeader.hasPlayer[playerIdxh] )
        ++numPlayers;
      if(game_1->mapHeader.winConditionArgumentOrLocX + 1 == numPlayers)
      {
        game_1->mapHeader.winConditionDefeatedColor = playerIdxh;
        playerIdxh = 99;
      }
    }
  }
  if(game_1->mapHeader.winConditionType == WIN_CONDITION_FIND_ARTIFACT)
    game_1->mapHeader.relatedToWinConditionType = 1;

  int castleIdxWithHero;
  int heroIdx;
  for(int playerIdxi = 0;  playerIdxi < game_1->numPlayers; playerIdxi++)
  {
    game_1->players[playerIdxi].aiNumberPuzzlePieces = 0;
    game_1->players[playerIdxi].aiProbableUltimateArtifactX = -1;
    game_1->players[playerIdxi].aiProbableUltimateArtifactY = -1;
    castleIdxWithHero = -1;
    if(!game_1->mapHeader.noStartingHeroInCastle && game_1->players[playerIdxi].numCastles > 0)
    {
      for(int passage = 0; passage < 2; passage++)
      {
        for(int castleIdx = 0;  castleIdx < game_1->players[playerIdxi].numCastles; castleIdx++)
        {
          if ( castleIdxWithHero == -1
            && game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdx]].visitingHeroIdx == -1
            && (game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdx]].buildingsBuiltFlags & BUILDING_CASTLE_BUILT
             || passage == 1)) // сначала пытаемся найти замок для героя-гостя (1-й проход), затем деревню (2-й проход)
            castleIdxWithHero = castleIdx;
        }
      }
    }
    if(castleIdxWithHero != -1)
    {
	  // первый герой на карте
	  heroIdx = game_GetNewHeroId(game_1, playerIdxi, game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdxWithHero]].factionID, 0);
      game_1->players[playerIdxi].heroesOwned[game_1->players[playerIdxi].numHeroes] = heroIdx;
      game_1->heroOwner[heroIdx]= playerIdxi;
      game_1->heroes[heroIdx].ownerIdx = playerIdxi;
      game_1->heroes[heroIdx].x = game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdxWithHero]].x;
      game_1->heroes[heroIdx].y = game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdxWithHero]].y;
      game_1->castles[game_1->players[playerIdxi].castlesOwned[castleIdxWithHero]].visitingHeroIdx = heroIdx;

      game_SetVisibility(
        game_1,
        game_1->heroes[heroIdx].x,
        game_1->heroes[heroIdx].y,
        playerIdxi,
        giVisRange[game_1->heroes[game_1->players[playerIdxi].heroesOwned[0]].secondarySkillLevel[SECONDARY_SKILL_SCOUTING]]);
      ++game_1->players[playerIdxi].numHeroes;
    }
  }
  
  bool someCampaign;
  bool someExpCampaign;
  int factionSorceressOrNecromancer;
  int faction;
  int offsetForNextFaction;

  for(int playerIdxj = 0; playerIdxj < game_1->numPlayers; playerIdxj++)
  {
    if(playerIdxj || !gbInCampaign || !game_1->maybeIsGoodCampaign && !game_1->field_84)
		someCampaign = false;
	else
		someCampaign = true;

	if(someCampaign == true)
	{
      factionSorceressOrNecromancer = game_1->maybeIsGoodCampaign ? FACTION_SORCERESS : FACTION_NECROMANCER;
	  // Перебираем свободных (некупленых) героев, ищем Sorc. или Necro (что-то одно)
      for(heroIdx = 0;
           heroIdx < 54
           && (game_1->heroes[heroIdx].factionID != factionSorceressOrNecromancer
           || game_1->heroOwner[heroIdx] != -1);
          ++heroIdx)
      ;
	}
	// если нашли героя для нашей кампании
    if(someCampaign == true && heroIdx < 54)
    {
      if(game_1->maybeIsGoodCampaign)
      {
        game_1->heroes[heroIdx].experience += 5000;
        hero_CheckLevel(&game_1->heroes[heroIdx]);
		// Делаем героя Элизой с id 56
        strcpy(game_1->heroes[heroIdx].name, "Sister Eliza");
        game_1->heroes[heroIdx].heroID = 56;
      }
      else
      {
        game_1->heroes[heroIdx].experience += 5000;
        hero_CheckLevel(&game_1->heroes[heroIdx]);
		// Делаем героя Браксом с id 59
        strcpy(game_1->heroes[heroIdx].name, "Brother Brax");
        game_1->heroes[heroIdx].heroID = 59;
      }
      game_1->players[0].heroesForPurchase[0] = heroIdx;
      game_1->heroOwner[heroIdx] = 64; // кодируем не номером игрока, а 64
      faction = game_1->heroes[heroIdx].factionID;
    }
    if(someCampaign == false || heroIdx >= 54)
    {
      if(!xIsPlayingExpansionCampaign || playerIdxj)
		  someExpCampaign = false;
	  else
		  someExpCampaign = true;

	  if(someExpCampaign == true)
	  {
        faction = -1;
        if(ExpCampaign_HasAward(&xCampaign, 6))
        {
          faction = FACTION_WIZARD;
          expansionCampaignHeroName = ExpCampaign_JosephName(&xCampaign);
          expansionCampaignHeroID = 64;
        }
        else if ( ExpCampaign_HasAward(&xCampaign, 7) )
        {
          faction = FACTION_BARBARIAN;
          expansionCampaignHeroName = ExpCampaign_IvanName(&xCampaign);
          expansionCampaignHeroID = 63;
        }
	  }
      if(someExpCampaign == true && faction != -1)
	  {
        for(heroIdx = 0;
              heroIdx < 54
              && (game_1->heroes[heroIdx].factionID != faction || game_1->heroOwner[heroIdx] != -1);
              ++heroIdx)
          ;
	  }
      if(heroIdx >= 54 || faction == -1 || someExpCampaign == false)
      {
        faction = Random(0, 5);
        if(game_1->newGameSelectedFaction[gcColorToSetupPos[game_1->players[playerIdxj].color]] < 6)
          faction = game_1->newGameSelectedFaction[gcColorToSetupPos[game_1->players[playerIdxj].color]];
        game_1->players[playerIdxj].heroesForPurchase[0] = game_GetNewHeroId(game_1, playerIdxj, faction, 0);
        game_1->heroOwner[game_1->players[playerIdxj].heroesForPurchase[0]] = 64;
      }
      else
      {
        game_1->heroes[heroIdx].experience = 5000;
        hero_CheckLevel(&game_1->heroes[heroIdx]);
        strcpy(game_1->heroes[heroIdx].name, expansionCampaignHeroName);
        game_1->heroes[heroIdx].heroID = expansionCampaignHeroID;
        game_1->players[0].heroesForPurchase[0] = heroIdx;
        game_1->heroOwner[game_1->players[0].heroesForPurchase[0]] = 64;
        faction = game_1->heroes[heroIdx].factionID;
      }
    }
    offsetForNextFaction = Random(1, 5);
    game_1->players[playerIdxj].heroesForPurchase[1] = game_GetNewHeroId(
                                                       game_1,
                                                       playerIdxj,
                                                       (faction + offsetForNextFaction) % 6,
                                                       0);
    game_1->heroOwner[game_1->players[playerIdxj].heroesForPurchase[1]] = 64;
  }
  
  int heroLocationX;
  int heroLocationY;
  mapCell* heroCell;
  
  for(int playerIdxk = 0; playerIdxk < game_1->numPlayers; playerIdxk++)
  {
    for(int heroIdx = 0;  heroIdx < game_1->players[playerIdxk].numHeroes; heroIdx++)
    {
      heroLocationX = game_1->heroes[game_1->players[playerIdxk].heroesOwned[heroIdx]].x;
      heroLocationY = game_1->heroes[game_1->players[playerIdxk].heroesOwned[heroIdx]].y;
      game_1->heroes[game_1->players[playerIdxk].heroesOwned[heroIdx]].occupiedObjType = game_1->map.tiles[heroLocationY * game_1->map.width + heroLocationX].objType;
      game_1->heroes[game_1->players[playerIdxk].heroesOwned[heroIdx]].occupiedObjVal = game_1->map.tiles[heroLocationY * game_1->map.width + heroLocationX].extraInfo;
      game_1->map.tiles[heroLocationY * game_1->map.width + heroLocationX].objType = LOCATION_HERO | TILE_HAS_EVENT;
      heroCell = &game_1->map.tiles[heroLocationY * game_1->map.width + heroLocationX];
      heroCell->extraInfo = game_1->players[playerIdxk].heroesOwned[heroIdx];
    }
    if(game_1->players[playerIdxk].numHeroes <= 0)
    {
      if(game_1->players[playerIdxk].numCastles > 0)
        game_1->players[playerIdxk].curCastleIdx = game_1->players[playerIdxk].castlesOwned[0];
    }
    else
    {
      game_1->players[playerIdxk].curHeroIdx = game_1->players[playerIdxk].heroesOwned[0];
    }
  }
  int ultimateArtifactLocX = -1;
  int ultimateArtifactLocY = -1;
  int loopCount = 0;
  int randomVal1 = Random(1, 30);
  int randomVal2 = Random(1, 20) + randomVal1;
  int randomVal3 = Random(1, 20) + randomVal2;
  int randomDeltaX;
  int randomDeltaY;
  int distanceY;
  
  while(1)
  {
    if(ultimateArtifactLocX >= 9)
    {
      if(ultimateArtifactLocY >= 9)
      {
        if(ultimateArtifactLocX <= MAP_WIDTH - 10)
        {
          if(ultimateArtifactLocY <= MAP_HEIGHT - 10)
          {
            if(game_1->map.tiles[ultimateArtifactLocY * game_1->map.width + ultimateArtifactLocX].objectIndex == 255)
            {
              if(game_1->map.tiles[ultimateArtifactLocY * game_1->map.width + ultimateArtifactLocX].overlayIndex == 255)
              {
                if(giGroundToTerrain[game_1->map.tiles[ultimateArtifactLocY * game_1->map.width + ultimateArtifactLocX].groundIndex])
                {
				  // неужели в мультиплеере нет UA ? Тогда не нужны обелиски ?
                  if(giNumHumanPlayers != 1)
                    break;
                  if(loopCount >= 200)
                    break;
                  distanceY = abs(ultimateArtifactLocY - game_1->heroes[game_1->players[0].heroesOwned[0]].y);
                  if(abs(ultimateArtifactLocX - game_1->heroes[game_1->players[0].heroesOwned[0]].x) + distanceY > randomVal3)
                    break;
                }
              }
            }
          }
        }
      }
    }

    if(loopCount >= 400 || giUABaseX <= 0)
    {
      ultimateArtifactLocX = Random(9, MAP_WIDTH - 10);
      ultimateArtifactLocY = Random(9, MAP_HEIGHT - 10);
    }
    else
    {
      if(giUARadius)
        randomDeltaX = Random(-giUARadius, giUARadius);
      else
        randomDeltaX = 0;
      ultimateArtifactLocX = randomDeltaX + giUABaseX;
      if(giUARadius)
        randomDeltaY = Random(-giUARadius, giUARadius);
      else
        randomDeltaY = 0;
      ultimateArtifactLocY = randomDeltaY + giUABaseY;
    }
    randomVal1 = Random(1, 30);
    randomVal2 = Random(1, 20) + randomVal1;
    randomVal3 = Random(1, 20) + randomVal2;
    ++loopCount;
  }
  
  game_1->ultimateArtifactLocX = ultimateArtifactLocX;
  game_1->ultimateArtifactLocY = ultimateArtifactLocY;
  game_1->ultimateArtifactIdx = Random(0, 7);
  if(gbInCampaign
    && (game_1->relatedToCampaign == 0 && game_1->relatedToCampaignMap == 7
     || game_1->relatedToCampaign == 1 && game_1->relatedToCampaignMap == 8) )
    game_1->ultimateArtifactIdx = ARTIFACT_ULTIMATE_CROWN;
	
  float resourceMultiplierFromHandicap;
  
  for(int playerIdxm = 0;  playerIdxm < game_1->numPlayers; playerIdxm++)
  {
    if(gbHumanPlayer[playerIdxm])
    {
      game_1->players[playerIdxm].personality = PERSONALITY_HUMAN;
      memcpy(game_1->players[playerIdxm].resources, giPlayerInitialResourcesHuman[game_1->difficulty], 28);
	  
	  // если установлен гандикап
      if(game_1->playerHandicap[playerIdxm])
      {
        for(int resourceType = 0; resourceType < NUM_RESOURCES; resourceType++)
        {
          if(game_1->playerHandicap[playerIdxm] == 1)
            resourceMultiplierFromHandicap = 0.85;
          else
            resourceMultiplierFromHandicap = 0.7;
          game_1->players[playerIdxm].resources[resourceType] = game_1->players[playerIdxm].resources[resourceType] * resourceMultiplierFromHandicap;
        }
      }
    }
    else
    {
      game_1->players[playerIdxm].personality = Random(0, 2);
      memcpy(game_1->players[playerIdxm].resources, giPlayerInitialResourcesAI[game_1->difficulty], 28);
    }
  }
  
  int lossConditionArgumentLocX;
  int lossConditionArgumentLocY;
  
  game_SetupAdjacentMons(game_1);
  if(game_1->mapHeader.lossConditionType == LOSS_CONDITION_LOSE_HERO)
  {
    lossConditionArgumentLocX = game_1->mapHeader.lossConditionArgumentOrLocX;
    lossConditionArgumentLocY = game_1->mapHeader.lossConditionArgumentOrLocY;
    game_1->mapHeader.lossConditionArgumentOrLocX = 0;
    if(game_1->map.tiles[lossConditionArgumentLocY * game_1->map.width + lossConditionArgumentLocX].objType == LOCATION_HERO | TILE_HAS_EVENT)
    {
	  // номер героя
      game_1->mapHeader.lossConditionArgumentOrLocX = game_1->map.tiles[lossConditionArgumentLocY * game_1->map.width + lossConditionArgumentLocX].extraInfo;
    }
	// ищем героя клеткой выше
    else if(game_1->map.tiles[(lossConditionArgumentLocY - 1) * game_1->map.width + lossConditionArgumentLocX].objType == LOCATION_HERO | TILE_HAS_EVENT)
    {
      game_1->mapHeader.lossConditionArgumentOrLocX = game_1->map.tiles[(lossConditionArgumentLocY - 1) * game_1->map.width + lossConditionArgumentLocX].extraInfo;
    }
	// если не нашли героя то нет спецусловия поражения
    else
    {
      game_1->mapHeader.lossConditionType = 0;
    }
  }
  
  int winConditionArgumentLocX;
  int winConditionArgumentLocY;
  
  if(game_1->mapHeader.winConditionType == WIN_CONDITION_DEFEAT_HERO)
  {
    winConditionArgumentLocX = game_1->mapHeader.winConditionArgumentOrLocX;
    winConditionArgumentLocY = game_1->mapHeader.winConditionArgumentOrLocY;
    game_1->mapHeader.winConditionArgumentOrLocX = 0;
    if(game_1->map.tiles[winConditionArgumentLocY * game_1->map.width + winConditionArgumentLocX].objType == LOCATION_HERO | TILE_HAS_EVENT)
    {
      game_1->mapHeader.winConditionArgumentOrLocX = game_1->map.tiles[winConditionArgumentLocY * game_1->map.width + winConditionArgumentLocX].extraInfo;
    }
    else if(game_1->map.tiles[(winConditionArgumentLocY - 1) * game_1->map.width + winConditionArgumentLocX].objType == LOCATION_HERO | TILE_HAS_EVENT)
    {
      game_1->mapHeader.winConditionArgumentOrLocX = game_1->map.tiles[(winConditionArgumentLocY - 1)* game_1->map.width + winConditionArgumentLocX].extraInfo;
    }
    else
    {
      game_1->mapHeader.winConditionType = 0;
    }
  }  
  
  for(int playerIdxn = 0; playerIdxn < game_1->numPlayers; playerIdxn++)
  {
    faction = 0;
	// если фракция пока не определена, то ищем сначала по замку, потом по герою
    if(game_1->newGameSelectedFaction[gcColorToSetupPos[game_1->players[playerIdxn].color]] < 0
      || game_1->newGameSelectedFaction[gcColorToSetupPos[game_1->players[playerIdxn].color]] >= 6 )
    {
      if(game_1->players[playerIdxn].numCastles)
      {
        faction = gpGame->castles[game_1->players[playerIdxn].castlesOwned[0]].factionID;
      }
      else if(game_1->players[playerIdxn].numHeroes)
      {
        faction = gpGame->heroes[game_1->players[playerIdxn].heroesOwned[0]].factionID;
      }
    }
    else
    {
      faction = game_1->newGameSelectedFaction[gcColorToSetupPos[game_1->players[playerIdxn].color]];
    }
    game_1->players[playerIdxn].hasEvilFaction = faction == FACTION_BARBARIAN
                                            || faction == FACTION_WARLOCK
                                            || faction == FACTION_NECROMANCER;
    if(gbInCampaign && !playerIdxn)
      game_1->players[0].hasEvilFaction = game_1->relatedToCampaign == 1;
    for(int castleOwnedIdx = 0;  castleOwnedIdx < gpGame->players[playerIdxn].numCastles; castleOwnedIdx++)
      town_GiveSpells(&gpGame->castles[gpGame->players[playerIdxn].castlesOwned[castleOwnedIdx]], 0);
    gpGame->players[playerIdxn].startingNumHeroes = gpGame->players[playerIdxn].numHeroes;
  }
  philAI_GetGameAIVars(gpPhilAI);
  gbInNewGameSetup = 0;
  game_SetupNewRumour(game_1);
  advManager_CheckSetEvilInterface(gpAdvManager, 0, -1);  
  
}

void game_LoadGame(game* game_1, char *filnam, int isNewGame, int a4)
{
	
}

void game_GetMap(game* game_1)
{

}


bool game_NewGame(game* game_1)
{

  bool isOk = 1;
  game_1->newGameWindow = 0;
  heroWindow* pickWindow;
  heroWindow* pickWindow2;
  heroWindow* pickWindow3;
  heroWindow* pickWindow4;
  heroWindow* pickWindow5;
  heroWindow* window;
  int pressedButton;

  if((!gbRemoteOn || !giThisNetPos) && (!gbRemoteOn || !xNetHasOldPlayers))
  {
    pickWindow = new heroWindow();
    if ( pickWindow )
      window = heroWindow_heroWindow(pickWindow, 405, 8, "x_mapmnu.bin");
    else
      window = 0;
    if ( !window )
      MemError();
    heroWindowManager_DoDialog(gpWindowManager, window, (int (*)(tag_message*))ExpStdGameHandler, 0);
    delete(window);
    pressedButton = gpWindowManager->buttonPressedCode;
    switch ( pressedButton )
    {
      case 1:
        xIsExpansionMap = 0;
        break;
      case 2:
        xIsExpansionMap = 1;
        break;
      case BUTTON_CANCEL:
        return 0;
    }
  }
  game_SetupNetPlayerNames();
  glTimers = 0;
  for(int i = 0; i < 3; i++)
  {
    (&cTextReceivedBuffer)[4 * i] = (char*)malloc(101);
    strcpy((&cTextReceivedBuffer)[4 * i], byte_5111B0);
  }
  cNGKPCore = (char*)malloc(105);
  cNGKPDisplay = (char*)malloc(105);
  strcpy(cNGKPCore, byte_5111F4);
  strcpy(cNGKPDisplay, byte_5111F8);
  NGKPcursorIndex = 0;
  // значки выбора замка, цвета, гандикапа + кнопка Select
  NGKPBkg = resourceManager_GetIcon(gpResourceManager, "ngextra.icn");
  int hostGuestInteractionCode;

  void* getRemoteDataResult;
  BOOL stopAfterGettingNetData_1;
  BOOL stopAfterGettingNetData_2;

  int dotAddress;
  BOOL wrongMapExtension;
  BOOL isMapHeaderOk;

  char mapHeaderToNet[116];
  char gsNetPlayerInfoCopy[204];
  int transmitResult;


  // Net Guest
  if ( gbWaitForRemoteReceive )
  {
    stopAfterGettingNetData_1 = 0;
    stopAfterGettingNetData_2 = 0;
    do
    {
      do
      {
        do
        {
          PollSound();
          getRemoteDataResult = GetRemoteData(1);
        }
        while(!getRemoteDataResult);
      }
      while(*((char*)getRemoteDataResult + 5) != 2);
      hostGuestInteractionCode = *((char*)getRemoteDataResult + 6);
	  // 52 - получение хедера карты
      if(hostGuestInteractionCode == 52)
      {
        memset(&game_1->mapHeader, 0, 0x1A4);
        memcpy(&game_1->mapHeader, (char*)getRemoteDataResult + 9, 116);
        stopAfterGettingNetData_1 = 1;
      }
	  // 55 - получение инфы о сетевых игроках
      else if(hostGuestInteractionCode == 55)
      {
        memcpy(&gsNetPlayerInfo, (char *)getRemoteDataResult + 9, 204);
        game_SetupNetPlayerNames();
        stopAfterGettingNetData_2 = 1;
      }
    }
    while ( !stopAfterGettingNetData_1 || !stopAfterGettingNetData_2 );

	//heroWindow* pickWindow2;
    pickWindow2 = new heroWindow();
	// выбор сложности и тд
    if(pickWindow2)
      game_1->newGameWindow = heroWindow_heroWindow(pickWindow2, 190, 4, "ngmp.bin");
    else
      game_1->newGameWindow = 0;
    game_InitNewGame(game_1, &game_1->mapHeader);
    game_InitNewGameWindow(game_1);
    game_UpdateNewGameWindow(game_1);

	GUIMessage evt;
    evt.eventCode = INPUT_GUI_MESSAGE_CODE;
    evt.fieldID = 54;

    evt.messageType = GUI_MESSAGE_ADD_FLAGS;
	evt.inputTypeBitmask = 4096; // 1 000 000 000 000
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    evt.messageType = GUI_MESSAGE_REMOVE_FLAGS;
    evt.inputTypeBitmask = 2;
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    evt.fieldID = 30722; // Ok

    evt.messageType = GUI_MESSAGE_ADD_FLAGS;
    evt.inputTypeBitmask = 4096;
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    evt.messageType = GUI_MESSAGE_REMOVE_FLAGS;
    evt.inputTypeBitmask = 2;
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    evt.fieldID = 30721; // Cancel

    evt.messageType = GUI_MESSAGE_ADD_FLAGS;
    evt.inputTypeBitmask = 4096;
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    evt.messageType = GUI_MESSAGE_REMOVE_FLAGS;
    evt.inputTypeBitmask = 2;
    heroWindow_BroadcastMessage(game_1->newGameWindow, (tag_message*)&evt);

    gbNewGameDialogOver = 0;
    heroWindowManager_DoDialog(
      gpWindowManager,
      game_1->newGameWindow,
      (int (*)(tag_message *))NewGameHandler,
      0);
    delete(game_1->newGameWindow);
    isOk = gpWindowManager->buttonPressedCode != BUTTON_CANCEL;
  }
  else
  {
    while(true)
    {
      wrongMapExtension = 0;
      dotAddress = FindLastToken(game_1->mapFilename, 46);
      if(dotAddress)
      {
        if ( StrEqNoCase((int *)dotAddress, (int *)".MX2") && xIsExpansionMap )
          wrongMapExtension = 1;
        if ( StrEqNoCase((int *)dotAddress, (int *)".MP2") && !xIsExpansionMap )
          wrongMapExtension = 1;
      }
      if ( !wrongMapExtension )
      {
        if ( xIsExpansionMap )
          strcpy(gpGame->mapFilename, "arrax.mx2");
        else
          strcpy(gpGame->mapFilename, "brokena.mp2");
        game_1->relatedToNewGameSelection = 0;
        game_1->relatedToNewGameInit = giNumHumanPlayers;
      }
      if(giNumHumanPlayers > 3)
      {
        if(!(stricmp(gpGame->mapFilename, "brokena.mp2")))
          strcpy(gpGame->mapFilename, "slugfest.mp2");
      }
      if(giNumHumanPlayers > 1)
      {
        if(!(stricmp(gpGame->mapFilename, "arrax.mx2")))
          strcpy(gpGame->mapFilename, "fullhse.mx2");
      }
      strcpy(gMapName, game_1->mapFilename);
      isMapHeaderOk = GetMapHeader(game_1->mapFilename, &game_1->mapHeader);
      isMapHeaderOk = GetMapHeader(game_1->mapFilename, &game_1->mapHeader);
      if(isMapHeaderOk)
      {
        if(game_1->mapHeader.minHumans <= giNumHumanPlayers
          && game_1->mapHeader.maxHumans >= giNumHumanPlayers)
          break;
      }
      game_GetMap(gpGame);
    }
    if(gbRemoteOn)
    {
	  // копируется хедер карты до поля description
      memcpy(&mapHeaderToNet, &gpGame->mapHeader, 116);
	  // 127 - всем игрокам (7 бит)
      transmitResult = TransmitRemoteData(&mapHeaderToNet, 127, 116, 52, 1, 1, -1);
      if(!transmitResult)
        ShutDown(0);
      memcpy(&gsNetPlayerInfoCopy, &gsNetPlayerInfo, 204);
	  // 127 - всем игрокам (7 бит)
      transmitResult = TransmitRemoteData(&gsNetPlayerInfoCopy, 127, 204, 55, 1, 1, -1);
      if(!transmitResult)
        ShutDown(0);
    }

	//heroWindow* pickWindow3;
    game_LoadGame(game_1, "origdata.bin", 1, 0);
	// синглплеер
    if(giNumHumanPlayers <= 1)
    {
      pickWindow3 = new heroWindow();
      if(pickWindow3)
        game_1->newGameWindow = heroWindow_heroWindow(pickWindow3, 190, 33, "ngsp.bin");
      else
        game_1->newGameWindow = 0;
    }
	// хост
    else if(iMPBaseType == 2)
    {
      pickWindow4 = new heroWindow();
      if ( pickWindow4 )
        game_1->newGameWindow = heroWindow_heroWindow(pickWindow4, 190, 4, "nghs.bin");
      else
        game_1->newGameWindow = 0;
    }
	// гуест
    else
    {
      pickWindow5 = new heroWindow();
      if(pickWindow5)
        game_1->newGameWindow = heroWindow_heroWindow(pickWindow5, 190, 4, "ngmp.bin");
      else
        game_1->newGameWindow = 0;
    }
    if(!game_1->newGameWindow)
      MemError();
    SetWinText(game_1->newGameWindow, 7);
    game_InitNewGame(game_1, 0);
    game_InitNewGameWindow(game_1);
    game_UpdateNewGameWindow(game_1);
    gbNewGameShadowHidden = 0;
    gbNewGameDialogOver = 0;
    heroWindowManager_DoDialog(
      gpWindowManager,
      game_1->newGameWindow,
      (int (*)(tag_message *))NewGameHandler,
      0);
    delete(game_1->newGameWindow);
    if(gpWindowManager->buttonPressedCode == BUTTON_CANCEL)
    {
      isOk = 0;
    }
    else
    {
      game_1->numPlayers = game_1->mapHeader.numPlayers;
      game_NewMap(game_1, gMapName);
    }
  }
  for(int i = 0; i < 3; i++)
    free((&cTextReceivedBuffer)[4 * i]);
  free(cNGKPCore);
  free(cNGKPDisplay);
  resourceManager_Dispose(gpResourceManager, (resource*)NGKPBkg);
  return isOk;

}
