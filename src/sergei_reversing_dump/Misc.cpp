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

extern game* gpGame;
extern int iLastSeed;
extern SBuildingCost gDwellingBuildingCosts[12 * 6];
extern SBuildingCost gSpecialBuildingCosts[6];
extern SBuildingCost gNeutralBuildingCosts[20];
extern SBuildingCost gMageBuildingCosts[6];
extern SBuildingCost xShrineBuildingCost;
extern int gDwellingBaseResourceValues[12 * 6];
extern int gSpecialBuildingBaseResourceValues[6];
extern int gNeutralBaseResourceValues[20];
extern int gMageBaseResourceValues[6];
extern tag_monsterInfo gMonsterDatabase[66];
extern char* mapRevealed;
extern int MAP_WIDTH;
extern int MAP_HEIGHT;
extern bool bStopOnTrigger[128];
extern char giGroundToTerrain[32 * 8];
extern int giTerrainCost[80];

int game_SetupPuzzlePieces(game* gp, int playerIdx, bool isAi);

int SRandom(int low, int high)
{

  return 1;
}

int Random(int a, int b)
{
	// здесь должен быть код

	return 1;
}

void SRand(int a1)
{
  iLastSeed = a1;
  return srand(a1);
}

int GetManaCost(int spell, hero* hero_1)
{
	int x;
	// здесь должен быть код

	return x;
}

int GetNumObelisks(int playerIdx)
{
  int numVisited = 0;
  for(int i = 0; i < 48; ++i )
  {
    if(gpGame->obeliskVisitedMasks[i] & (1 << playerIdx))
      ++numVisited;
  }
  return numVisited;
}

void GetMonsterCost(int mon, int* costs)
{

  for(int i = 0; i < NUM_RESOURCES; i++)
    costs[i] = 0;
  costs[6] = gMonsterDatabase[mon].cost;
  switch(mon)
  {
    case CREATURE_GENIE:
      costs[5] = 1;
      break;
    case CREATURE_PHOENIX:
      costs[1] = 1;
      break;
    case CREATURE_CYCLOPS:
      costs[4] = 1;
      break;
    case CREATURE_GREEN_DRAGON:
    case CREATURE_RED_DRAGON:
      costs[3] = 1;
      break;
    case CREATURE_BLACK_DRAGON:
      costs[3] = 2;
      break;
    case CREATURE_GIANT:
      costs[5] = 1;
      break;
    case CREATURE_TITAN:
      costs[5] = 2;
      break;
    default:
      return;
  }
}

int CheckDoMain(int a1, int a2)
{

  return a1;
}

bool OnMySide(int a)
{
	// здесь должен быть код

	return true;
}

void GetBuildingCost(int faction, int building, SBuildingCost* cost, int currentMagicGuildLevel)
{

  if(building != BUILDING_TAVERN || faction != FACTION_NECROMANCER)
  {
    // если не двеллинг
    if(building < 19 || building > 30)
    {
      if(building)
      {
        if(building == BUILDING_SPECIAL)
        {
			cost->wood = gSpecialBuildingCosts[faction].wood;
			cost->mercury = gSpecialBuildingCosts[faction].mercury; 
			cost->ore = gSpecialBuildingCosts[faction].ore;
			cost->sulfur = gSpecialBuildingCosts[faction].sulfur;
			cost->crystal = gSpecialBuildingCosts[faction].crystal;
			cost->gems = gSpecialBuildingCosts[faction].gems;
			cost->gold = gSpecialBuildingCosts[faction].gold;
        }
        else if(building < 16)
        {
			cost->wood = gNeutralBuildingCosts[building].wood;
			cost->mercury = gNeutralBuildingCosts[building].mercury; 
			cost->ore = gNeutralBuildingCosts[building].ore;
			cost->sulfur = gNeutralBuildingCosts[building].sulfur;
			cost->crystal = gNeutralBuildingCosts[building].crystal;
			cost->gems = gNeutralBuildingCosts[building].gems;
			cost->gold = gNeutralBuildingCosts[building].gold;
        }
      }
      else
      {
			cost->wood = gMageBuildingCosts[currentMagicGuildLevel+1].wood;
			cost->mercury = gMageBuildingCosts[currentMagicGuildLevel+1].mercury; 
			cost->ore = gMageBuildingCosts[currentMagicGuildLevel+1].ore;
			cost->sulfur = gMageBuildingCosts[currentMagicGuildLevel+1].sulfur;
			cost->crystal = gMageBuildingCosts[currentMagicGuildLevel+1].crystal;
			cost->gems = gMageBuildingCosts[currentMagicGuildLevel+1].gems;
			cost->gold = gMageBuildingCosts[currentMagicGuildLevel+1].gold;
      }
    }
    else
    {
		cost->wood = gDwellingBuildingCosts[12*faction + building - 19].wood;
		cost->mercury = gDwellingBuildingCosts[12*faction + building - 19].mercury; 
		cost->ore = gDwellingBuildingCosts[12*faction + building - 19].ore;
		cost->sulfur = gDwellingBuildingCosts[12*faction + building - 19].sulfur;
		cost->crystal = gDwellingBuildingCosts[12*faction + building - 19].crystal;
		cost->gems = gDwellingBuildingCosts[12*faction + building - 19].gems;
		cost->gold = gDwellingBuildingCosts[12*faction + building - 19].gold;
    }
  }
  else
  {
	cost->wood = xShrineBuildingCost.wood;
	cost->mercury = xShrineBuildingCost.mercury; 
	cost->ore = xShrineBuildingCost.ore;
	cost->sulfur = xShrineBuildingCost.sulfur;
	cost->crystal = xShrineBuildingCost.crystal;
	cost->gems = xShrineBuildingCost.gems;
	cost->gold = xShrineBuildingCost.gold;
  }

}

// рейтинги полезности построек
int GetBuildingBaseResourceValue(int faction, int building, int buildingMagicGuildCode)
{
  int result;

  if(faction != FACTION_NECROMANCER || building != BUILDING_TENT)
  {
    if(building >= 19 && building <= 30)
    {
      result = gDwellingBaseResourceValues[12 * faction + building - 19];
    }
    else if(building <= BUILDING_CAPTAIN)
    {
      if(building)
      {
        if(building == BUILDING_SPECIAL)
          result = gSpecialBuildingBaseResourceValues[faction];
        else
          result = gNeutralBaseResourceValues[building];
      }
      else
      {
        result = gMageBaseResourceValues[buildingMagicGuildCode];
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 1000;
  }
  return result;
}

void ShowStatus()
{

}

// провер€ет, не выход€т ли за границы клетки, соседние с данной клеткой
// возвр. истину, если точка "валидна€"
// но плюс еще провер€етс€ giCurWatchPlayerBit
int MapExtraPosAndAdjacentsSet(int x, int y, char giCurWatchPlayerBitCopy)
{
  int result;

  if(mapRevealed[x + y * MAP_WIDTH] & giCurWatchPlayerBitCopy)
  {
    result = true;
  }
  else
  {
    for(int i = x - 1; i <= x + 1; i++)
    {
      if(i >= 0 && i < MAP_WIDTH)
      {
        for(int j = y - 1; j <= y + 1; j++)
        {
          if(j >= 0 && j < MAP_HEIGHT && (mapRevealed[i + j * MAP_WIDTH] & giCurWatchPlayerBitCopy))
            return true;
        }
      }
    }
    result = false;
  }
  return result;
}

bool ValidHex(int hexIdx)
{
  return hexIdx >= 0 && hexIdx < 117;
}

int OppositeDirection(int direction)
{
  int result;

  if(direction >= 6)
  {
    if(direction == 6)
      result = 7;
    else
      result = 6;
  }
  else
  {
    result = (direction + 3) % 6;
  }
  return result;
}

char StopOnTrigger(mapCell* cell)
{
  int objectTypeExact = cell->objType & 0x7F;
  int genericType;
  char result;

  if(objectTypeExact == LOCATION_ALCHEMIST_TOWER)
  {
    genericType = cell->extraInfo & 0x3F;
    result = genericType >= 5 && genericType <= 6;
  }
  else
  {
    result = bStopOnTrigger[objectTypeExact];
  }
  return result;
}

int GiveArtifact(hero* hero_1, int a2, int a3, char scrollSpell)
{

	return 1;
}

// проверка на наличие у геро€ существ.
// довольно странна€
int ValidateHero(hero* hero_1)
{
  int result;
  for(int i = 0; i < 5; i++)
  {
    result = hero_1->army.creatureTypes[i];
    if(result != -1)
    {
      result = hero_1->army.creatureTypes[i];
      if(result >= 0)
        result = hero_1->army.creatureTypes[i];
    }
  }
  return result;
}

void CheckEndGame(int a1, int a2)
{

  return;	
}

void* GetRemoteData(char relinquish)
{
  void* v1;
  return v1;
}

int FindLastToken(const char *a1, char a2)
{

  return 1;	
}

void FileError(char* a1)
{
	
}

bool IsCursedItem(int art)
{
  return art == ARTIFACT_FIZBIN_OF_MISFOURTUNE
      || art == ARTIFACT_HIDEOUS_MASK
      || art == ARTIFACT_TAX_LIEN
      || art == ARTIFACT_ARM_OF_THE_MARTYR
      || art == ARTIFACT_BROACH_OF_SHIELDING
      || art == ARTIFACT_HEART_OF_FIRE
      || art == ARTIFACT_HEART_OF_ICE;
}

void SendMapChange(char a1, char a2, unsigned char a3, unsigned char a4, int a5, char a6, char a7)
{
	
}

int ExpStdGameHandler(tag_message* evt)
{

  return 1;
}

char StrEqNoCase(int *a1, int *a2)
{

  return 1;	
}

int TransmitRemoteData(const void *a1, int a2, int a3, char a4, char a5, char a6, char a7)
{
	return 1;
}

void MemError()
{

}

signed int GetMapHeader(char *name, SMapHeader *hdr)
{

  return 1;
}

void ShutDown(char a1)
{

}

signed int NewGameHandler(tag_message *a1)
{

  return 1;
}

void ComputeUALoc(int playerIdx)
{

  int nPieces = game_SetupPuzzlePieces(gpGame, playerIdx, 1);
  int nPiecesReduced;

  int i, j;

  int x, y, iSearch;

  int dice_1, dice_2;

  if(nPieces >= 8 && gpGame->ultimateArtifactIdx != -1)
  {
    // вот почему nPieces д быть не меньше 8
    nPiecesReduced = 4 * nPieces - 32;
    if(nPiecesReduced > 100)
      nPiecesReduced = 100;
    if(nPiecesReduced < 1)
      nPiecesReduced = 1;
    gpGame->players[playerIdx].aiNumberPuzzlePieces = nPiecesReduced;
	// чем больше aiNumberPuzzlePieces тем больше шанс, что этот код не сработает
	// и это хорошо, потому что скорее всего координаты √лавного артефакта будут даны неверные
    if(gpGame->players[playerIdx].aiNumberPuzzlePieces < Random(1, 100))
    {
      x = -1;
      y = -1;
      iSearch = 0;
	  // ищем, чтобы x было между 0 и MAP_WIDTH, y - между 0 и MAP_HEIGHT
	  // тип объекта стал нулем, индекс объекта -1, индекс оверле€ -1 и чтобы была суша, а не вода
	  // короче нам нужна пуста€ клетка суши
      while(x < 0
           || x >= MAP_WIDTH
           || y < 0
           || y >= MAP_HEIGHT
           || gpGame->map.tiles[x + y * gpGame->map.width].objType
           || gpGame->map.tiles[x + y * gpGame->map.width].objectIndex != -1
           || gpGame->map.tiles[x + y * gpGame->map.width].overlayIndex != -1
           || !giGroundToTerrain[gpGame->map.tiles[x + y * gpGame->map.width].groundIndex])
      {
        ++iSearch;
		// нам нужно i которое отличалось бы от 0, оно м быть от 3 до -6
        for(i = 0; i == 0; i = dice_2 - Random(0, 2)) // i = 3 - Random(0, 2) - Random(0, 2) - Random(0, 2)
        {
          dice_1 = 3 - Random(0, 2); // v2 принимает значени€ от 1 до 3 случайно
          dice_2 = dice_1 - Random(0, 2); // v3 принимает значени€ от -1 до 3 случайно
        }
        x = i + gpGame->ultimateArtifactLocX;
        for(j = 0; j == 0; j = dice_2 - Random(0, 2))
        {
          dice_1 = 3 - Random(0, 2);
          dice_2 = dice_1 - Random(0, 2);
        }
        y = j + gpGame->ultimateArtifactLocY;
        if(iSearch >= 200)
        {
          x = gpGame->ultimateArtifactLocX;
          y = gpGame->ultimateArtifactLocY;
          break;
        }
      }
      gpGame->players[playerIdx].aiProbableUltimateArtifactX = x;
      gpGame->players[playerIdx].aiProbableUltimateArtifactY = y;
    }
	// то есть если aiNumberPuzzlePieces достаточно большое или если почаще запускать ComputeUALoc
	// то √лавный артефакт будет быстро найден. ѕравда если ComputeUALoc ошибаетс€, то это заставл€ет тратить день на копку
	// (наверн€ка неизвестно, правильные ли координаты выдал ComputeUALoc)
    else
    {
      gpGame->players[playerIdx].aiProbableUltimateArtifactX = gpGame->ultimateArtifactLocX;
      gpGame->players[playerIdx].aiProbableUltimateArtifactY = gpGame->ultimateArtifactLocY;
    }
  }
  else
  {
    gpGame->players[playerIdx].aiProbableUltimateArtifactX = 0;
    gpGame->players[playerIdx].aiProbableUltimateArtifactY = -1;
    gpGame->players[playerIdx].aiNumberPuzzlePieces = -1;
  }
}

int CalcTerrainCost(int terrain, char direction, int remainingMobility, int pathfindingSSLevel, int fromRoad, int toRoad)
{
//  чет - нечет, чет - нечет, чет - нечет, чет - нечет  |  чет - нечет, чет - нечет, чет - нечет, чет - нечет 
//   Ѕез навыка   Ѕазовый     ѕродвинутый   Ёксперт     |   Ѕез навыка   Ѕазовый     ѕродвинутый   Ёксперт
//               “ип почвы 1                            |                  “ип почвы 2

// ¬ конце массива дорога как особый тип почвы - 8 элементов (4 навыка на 2 типа направлени€)

  int cost;
  int index = 2 * (pathfindingSSLevel + 4 * terrain);
  // направление 1 диагональное
  if(giTerrainCost[index + 1] <= remainingMobility)
  {
    if(fromRoad && toRoad)
      terrain = 9;
    return giTerrainCost[2 * (pathfindingSSLevel + 4 * terrain) + direction & 1];
  }
  cost = giTerrainCost[2 * (pathfindingSSLevel + 4 * terrain)];
  // направление 0 пр€мое
  if(giTerrainCost[index] <= remainingMobility)
    if(fromRoad)
      return giTerrainCost[2 * (pathfindingSSLevel + 36)];
  
  if(!fromRoad)
    return giTerrainCost[2 * (pathfindingSSLevel + 4 * terrain) + direction & 1];

  if(giTerrainCost[2 * pathfindingSSLevel + 72] > remainingMobility)
  {
    if(fromRoad && toRoad)
      terrain = 9;
    return giTerrainCost[2 * (pathfindingSSLevel + 4 * terrain) + direction & 1];
  }

  if(fromRoad)
    cost = giTerrainCost[2 * pathfindingSSLevel + 72];
  return cost;
}
