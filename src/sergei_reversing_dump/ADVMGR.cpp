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

extern int MAP_WIDTH;
extern int MAP_HEIGHT;
extern int giAdjacentMonsterUpperBoundX;
extern int giAdjacentMonsterUpperBoundY;
extern int giAdjacentMonsterX;
extern int giAdjacentMonsterY;
extern int giAdjacentMonsterLowerBoundX;
extern int giAdjacentMonsterLowerBoundY;
extern char normalDirTable[32];
extern game* gpGame;
extern char giCurPlayerBit;
extern int giCurPlayer;
extern bool gbHumanPlayer[6];

void game_RestoreCell(int x, int y, int underlyingObjType, short underlyingObjExtra, mapCell* cell, int unused);
bool philAI_CombatMonsterEvent(hero* hero_1, char creatureId, int* nCreatures, mapCell* cell);
void hero_CheckLevel(hero* hero_1);
void game_ClaimMine(game* gp, int idx, int color);
int hero_HasSpell(hero* hero_1, int spell);
int GetManaCost(int spell, hero* hero_1);
char hero_Stats(hero* hero_1, int skill);
int hero_NumArtifacts(hero* hero_1);
int GiveArtifact(hero* hero_1, int a2, int a3, char scrollSpell);
bool philAI_ChooseGoldOrExperience(int gold, int experience);
void CheckEndGame(int a1, int a2);

mapCell* advManager_GetCell(advManager* am, int col, int row)
{
	mapCell* mc;

	return mc;
}

BOOL advManager_FindAdjacentMonster(advManager* advM, int xPoint, int yPoint, int* xMonster, int* yMonster, int xUnwanted, int yUnwanted)
{
  giAdjacentMonsterUpperBoundX = xPoint + 2; // dword_524CFC changed to giAdjacentMonsterUpperBoundX
  giAdjacentMonsterUpperBoundY = yPoint + 2; // dword_524CE0 changed to giAdjacentMonsterUpperBoundY
  if(xPoint > 0 && yPoint > 0 && xPoint < MAP_WIDTH - 1 && yPoint < MAP_HEIGHT - 1)
  {
    for(giAdjacentMonsterX = xPoint - 1; giAdjacentMonsterX < giAdjacentMonsterUpperBoundX; giAdjacentMonsterX++)// dword_524CF0 changed to giAdjacentMonsterX
    {
      for(giAdjacentMonsterY = yPoint - 1; giAdjacentMonsterY < giAdjacentMonsterUpperBoundY; giAdjacentMonsterY++)// dword_524D0C changed to giAdjacentMonsterY
      {
        if(advM->map->tiles[giAdjacentMonsterX + 12 * giAdjacentMonsterY * advM->map->width].objType == (LOCATION_ARMY_CAMP | TILE_HAS_EVENT))
        {
          if(yPoint <= giAdjacentMonsterY)
          {
            if(giAdjacentMonsterX != xUnwanted || giAdjacentMonsterY != yUnwanted)
			{
              *xMonster = giAdjacentMonsterX;
              *yMonster = giAdjacentMonsterY;
              return 1;			  
			}
          }
          else if((advManager_GetCell(advM, xPoint, yPoint)->objectIndex == -1
   || ((advManager_GetCell(advM, xPoint, yPoint)->objTileset) & 0x3F) == TILESET_OBJECT_DUMMY
   || advManager_GetCell(advM, xPoint, yPoint)->flags & 0x80)
  && (giAdjacentMonsterX != xUnwanted || giAdjacentMonsterY != yUnwanted))
          {
              *xMonster = giAdjacentMonsterX;
              *yMonster = giAdjacentMonsterY;
              return 1;
          }
        }
      }
    }
    return 0;
  }
  if(xPoint == MAP_WIDTH - 1)
    giAdjacentMonsterUpperBoundX = xPoint + 1;
  if(yPoint == MAP_HEIGHT - 1)
    giAdjacentMonsterUpperBoundY = yPoint + 1;
  if(xPoint)
    giAdjacentMonsterLowerBoundX = xPoint - 1;    // dword_524E7C changed to adjacentMonsterLowerBoundX
  else
    giAdjacentMonsterLowerBoundX = 0;
  if(yPoint)
    giAdjacentMonsterLowerBoundY = yPoint - 1;    // dword_524EBC changed to adjacentMonsterLowerBoundY
  else
    giAdjacentMonsterLowerBoundY = 0;

  giAdjacentMonsterX = giAdjacentMonsterLowerBoundX;

  if(giAdjacentMonsterUpperBoundX <= giAdjacentMonsterX)
    return 0;
  for(giAdjacentMonsterY = giAdjacentMonsterLowerBoundY; ;giAdjacentMonsterY++)
  {
    if(giAdjacentMonsterY >= giAdjacentMonsterUpperBoundY)
    {
      giAdjacentMonsterX++;
      if(giAdjacentMonsterUpperBoundX <= giAdjacentMonsterX)
        return 0;
    }
    if(advM->map->tiles[giAdjacentMonsterX + 12 * giAdjacentMonsterY * advM->map->width].objType != (LOCATION_ARMY_CAMP | TILE_HAS_EVENT))
      continue;
    if(yPoint > giAdjacentMonsterY)
      if ( advManager_GetCell(advM, xPoint, yPoint)->objectIndex != -1
      && ((advManager_GetCell(advM, xPoint, yPoint)->objTileset) & 0x3F) != TILESET_OBJECT_DUMMY
      && !(advManager_GetCell(advM, xPoint, yPoint)->flags & 0x80)
      || giAdjacentMonsterX == xUnwanted && giAdjacentMonsterY == yUnwanted)
        continue;	
      else		
        break;
    if(giAdjacentMonsterX != xUnwanted || giAdjacentMonsterY != yUnwanted)
	{
      *xMonster = giAdjacentMonsterX;
      *yMonster = giAdjacentMonsterY;
      return 1;		
	}
  }

  *xMonster = giAdjacentMonsterX;
  *yMonster = giAdjacentMonsterY;
  return 1;
}

int advManager_GiveExperience(hero* hero_1, int addedExperience, int a)
{
	int x;
	// здесь должен быть код

	return x;
}

void advManager_TransferArtifacts(hero* heroSource, hero* heroDest)
{
	// здесь должен быть код

}

int advManager_ValidMove(advManager* am_1, int a2, int a3)
{

  return 1;
}

int advManager_TeleportTo(advManager* am, hero* hero_1, int x, int y, int a5, int a6)
{

  return 1;
}

// normalDirTable - 8 по 4 байта. 1-й байт - сдвиг по X (-1/0/1), 2-й - сдвиг по Y (-1/0/1)
// 3-й байт всегда - 0x10, 4-й - 0
// i соответствует направлениям так:
//  6  5  4
//  7  0  3
//  8  1  2
// Точнее:
//  5  4  3
//  6  -  2
//  7  0  1
// Еще точнее:
//  7  0  1
//  6  -  2
//  5  4  3
// здесь в основном проверяется возможный выход за границы карты
int advManager_ValidMoveWithEvent(advManager* gpAdvManager, hero* hero_1, int i)
{
  int isValidMove;
  int afterStepX = normalDirTable[4 * i] + hero_1->x;
  int afterStepY = normalDirTable[4 * i + 1] + hero_1->y;
  if(afterStepX >= 0 && afterStepX <= MAP_WIDTH - 1 && afterStepY >= 0 && afterStepY <= MAP_HEIGHT - 1)
  {
    mapCell* cell = (mapCell*)&gpAdvManager->map->tiles[afterStepY * gpAdvManager->map->width + afterStepX];

    if((cell->objType & (TILE_HAS_EVENT - 1))== LOCATION_HERO)
    {
	  if(hero_1->flags & HERO_AT_SEA)
      // этот герой отличается от нашего. если наш герой на море, то если другой тоже на море то возвращаем 1
      // поскольку инициирует битву или встречу герой с суши, а с моря - нельзя
	  // а если наш на суше то результат всегда 1 (то есть будет либо битва, либо встреча ?)
        isValidMove = (gpGame->heroes[cell->extraInfo].flags & HERO_AT_SEA) != 0;
      else
        isValidMove = true;
    }
    else
    {
	  // возвращает 0 если нельзя пройти
      isValidMove = advManager_ValidMove(gpAdvManager, i, 1);
    }
  }
  else
  {
    isValidMove = false;
  }
  return isValidMove;  
}

void advManager_SetHeroContext(advManager* am, int heroIdx, int a3)
{

}

playerData* advManager_DeactivateCurrHero(advManager* am)
{
  playerData *result;

  return result;
}

int advManager_ProcessSearch(advManager* am, int x, int y)
{

}

void advManager_UpdateScreen(advManager* am, int a2, int a3)
{

}

int advManager_GetCursorBaseFrame(int direction)
{

  return 1;
}

void advManager_CheckAdjacentMon(advManager* advM, BOOL* isMonsterFound)
{

}

void advManager_GiveResource(advManager* advM, hero* hero_1, int type, int amt)
{
  if(type >= 0 && type <= 6)
  {
    gpGame->players[hero_1->ownerIdx].resources[type] += amt;
  }
  if(type == RESOURCE_GOLD)
  {
    if(gbHumanPlayer[hero_1->ownerIdx])
      CheckEndGame(0, 0);
  }
}

void advManager_DoAIEvent(advManager* advM, mapCell* cell, hero* hero_1, int x, int y)
{
  int v71 = 0;
  int objectType = cell->objType & (TILE_HAS_EVENT - 1);
  int v58 = 0;
  int v65 = 0;
  int playerIdx = giCurPlayer;

  BOOL isMonsterFound;
  BOOL isAttackerWin;
  bool mineIsNotGuarded;
  
  bool eraseObject = false;

  if(hero_1->oldTargetX == x && hero_1->oldTargetY == y)
  {
    hero_1->oldTargetY = -1;
    hero_1->oldTargetX = -1;
  }

  // только 1, не 100 ?
  --hero_1->remainingMobility;

  boat* boat_1;
  int nMineMonsters;
  int heroSpellpower;

  switch(objectType)
  {
    case LOCATION_SHORE:
      if(hero_1->flags & HERO_AT_SEA)
      {
        hero_1->flags &= 0xFFFFFF7Fu; // обнуляется флаг HERO_AT_SEA
        hero_1->remainingMobility = 0;
        hero_1->directionFacing = advM->mobilizedHeroDirection;
        advM->mobilizedHeroFactionOrBoat = hero_1->factionID;
        advM->mobilizedHeroBaseFrameBit8IsFlip = advManager_GetCursorBaseFrame(advM->mobilizedHeroDirection);
        advM->field_272 = 1;
        advManager_CheckAdjacentMon(advM, &isMonsterFound);
      }
      //goto LABEL_308;
    case LOCATION_BOAT:
      boat_1 = &gpGame->boats[cell->extraInfo];
	  // последний аргумент (3) не используется в game_RestoreCell вообще
      game_RestoreCell(-1, -1, boat_1->underlyingObjType, boat_1->underlyingObjExtra, cell, 3);
      hero_1->flags |= HERO_AT_SEA;
      hero_1->remainingMobility = 0;
      boat_1->heroIdx = hero_1->idx;
	  boat_1->isEmpty = 0;
      boat_1->owner = hero_1->ownerIdx;
      advM->mobilizedHeroFactionOrBoat = 6;
      advM->mobilizedHeroDirection = boat_1->direction;
      advM->mobilizedHeroBaseFrameBit8IsFlip = advManager_GetCursorBaseFrame(advM->mobilizedHeroDirection);
      advM->field_272 = 1;
      //goto LABEL_308;
    case LOCATION_ALCHEMIST_LAB:
    case LOCATION_MINE:
    case LOCATION_SAWMILL:
      if(gpGame->mineOwner[cell->extraInfo] == giCurPlayer)
        //goto LABEL_308;
      if(gpGame->mines[cell->extraInfo].guardianType == -1)
        mineIsNotGuarded = true;
	  else
		mineIsNotGuarded = false;
	
	  if(!mineIsNotGuarded)
	  {
        nMineMonsters = gpGame->mines[cell->extraInfo].guardianQty;
        isAttackerWin = philAI_CombatMonsterEvent(
              hero_1,
              gpGame->mines[cell->extraInfo].guardianType,
              &nMineMonsters,
              cell);
	  }
        
	  if(isAttackerWin && !mineIsNotGuarded)
      {
        gpGame->mines[cell->extraInfo].guardianType = -1;
        gpGame->mines[cell->extraInfo].guardianQty = 0;
        hero_CheckLevel(hero_1);
      }
      
	  if(isAttackerWin || mineIsNotGuarded)
        game_ClaimMine(
          gpGame,
          cell->extraInfo,
          giCurPlayer);
		  
      if(objectType == LOCATION_MINE)
      {
		// баг, должно быть 65, а не 64
        for(int spell = 61; spell < 64; spell++)
        {
          if(hero_HasSpell(hero_1, spell) && GetManaCost(spell, hero_1) < hero_1->spellpoints)
          {
            hero_1->spellpoints -= GetManaCost(spell, hero_1);
            gpGame->mines[cell->extraInfo].guardianType = spell + 1;
            heroSpellpower = hero_Stats(hero_1, PRIMARY_SKILL_SPELLPOWER);
            if(heroSpellpower > 51)
              heroSpellpower = 51;
			// а это чит ИИ - коэф. д быть 4 а не 5
            gpGame->mines[cell->extraInfo].guardianQty = 5 * heroSpellpower;
            spell = 999; // выход из цикла
          }
        }
      }
      //goto LABEL_308;
    case LOCATION_LIGHTHOUSE:
      if(gpGame->mineOwner[cell->extraInfo] != giCurPlayer)
        game_ClaimMine(
          gpGame,
          cell->extraInfo,
          giCurPlayer);
      //goto LABEL_308;

	case LOCATION_TREASURE_CHEST:
      if((cell->extraInfo >> 8) & 1 && hero_NumArtifacts(hero_1) < 14)
	  {
	    // номер артефакта - в младших 8 битах
        GiveArtifact(hero_1, (unsigned char)cell->extraInfo, 1, -1);
      }
      else if(cell->extraInfo)
      {
        // если нет места для артефакта, то записываем что в сундуке будет 1000 золота
        // инфа об артефакте стирается
        cell->extraInfo = 2;
	  }

      if(!(cell->extraInfo >> 8 & 1))
        if(philAI_ChooseGoldOrExperience(
               500 * cell->extraInfo,
               125 * (4 * cell->extraInfo - 4)))
        {
          advManager_GiveResource(
            advM,
            hero_1,
            RESOURCE_GOLD,
            500 * cell->extraInfo);
        }
        else
        {
          advManager_GiveExperience(
            hero_1,
            125 * (4 * cell->extraInfo - 4),
            1);
          hero_CheckLevel(hero_1);
        }
        eraseObject = 1;
        //goto LABEL_308;

    case LOCATION_WATERING_HOLE:
      if(!(hero_1->flags & HERO_WATERING_HOLE_VISITED))
      {
        hero_1->mobility += 400;
        hero_1->remainingMobility += 400;
        hero_1->flags |= HERO_WATERING_HOLE_VISITED;
        ++hero_1->tempMoraleBonuses;
      }
      //goto LABEL_308;
    case LOCATION_BUOY:
      if(!(hero_1->flags & HERO_BUOY_VISITED))
      {
        hero_1->flags |= HERO_BUOY_VISITED;
        ++hero_1->tempMoraleBonuses;
      }
      //goto LABEL_308;
    case LOCATION_FAERIE_RING:
      if(!(hero_1->flags & HERO_FAIRY_RING_VISITED))
      {
        hero_1->flags |= HERO_FAIRY_RING_VISITED;
        ++hero_1->tempLuckBonuses;
      }
      //goto LABEL_308;
    case LOCATION_IDOL:
      if(!(hero_1->flags & HERO_IDOL_VISITED))
      {
        hero_1->flags |= HERO_IDOL_VISITED;
        ++hero_1->tempLuckBonuses;
      }
      //goto LABEL_308;
    case LOCATION_FOUNTAIN:
      if(!(hero_1->flags & HERO_FOUNTAIN_VISITED))
      {
        hero_1->flags |= HERO_FOUNTAIN_VISITED;
        ++hero_1->tempLuckBonuses;
      }
      //goto LABEL_308;	
	case LOCATION_OASIS:
      if(!(hero_1->flags & HERO_OASIS_VISITED))
      {
        hero_1->flags |= HERO_OASIS_VISITED;
        ++hero_1->tempMoraleBonuses;
        hero_1->mobility += 800;
        hero_1->remainingMobility += 800;
      }
      //goto LABEL_308;
    case LOCATION_TEMPLE:
      if (!(hero_1->flags & HERO_TEMPLE_VISITED))
      {
        hero_1->flags |= HERO_TEMPLE_VISITED;
        hero_1->tempMoraleBonuses += 2;
      }
      //goto LABEL_308;
    case LOCATION_SKELETON:
      if(cell->extraInfo != 1)
      {
        GiveArtifact(
          hero_1,
          cell->extraInfo - 2,
          1,
          -1);
		// ставим бит, что пусто
        cell->extraInfo = 1;
      }
      //goto LABEL_308;
    case LOCATION_MAGIC_GARDEN:
	  // extraInfo содержит 7 если деньги и 6 если гемы
      if(cell->extraInfo)
      {
        advManager_GiveResource(
          advM,
          hero_1,
          cell->extraInfo - 1,
          (cell->extraInfo - 7 < 1 ? 500 : 5));
        cell->extraInfo = 0;
      }
      //goto LABEL_308;
    case LOCATION_LEAN_TO:
      if(cell->extraInfo)
      {
		// первые (правые) 4 бита в extraInfo - тип ресурса, левые - количество
        advManager_GiveResource(advM, hero_1, (cell->extraInfo & 0xF) - 1, (cell->extraInfo & 0xF0u) >> 4);
        cell->extraInfo = 0;
      }
      //goto LABEL_308;
	case LOCATION_WAGON:
      if(cell->extraInfo)
      {
		// 8-й бит
        if(cell->extraInfo & 0x80)
        {
          if(hero_NumArtifacts(hero_1) != 14)
          {
            // первые 7 бит cell->extraInfo
            GiveArtifact(hero_1, (cell->extraInfo & 0x7F), 1, -1);
          }
          cell->extraInfo = 0;
        }
        else
        {
		  // первые (правые) 4 бита в extraInfo - тип ресурса, левые - количество
		  // с учетом нулевого 8-го бита кол-во ресурса видимо не больше 7
          advManager_GiveResource(advM, hero_1, (cell->extraInfo & 0xF) - 1, (cell->extraInfo & 0xF0u) >> 4);
          cell->extraInfo = 0;
        }
      }
      //goto LABEL_308;
    case LOCATION_SEA_CHEST:
      if((cell->extraInfo >> 8) & 1 && hero_NumArtifacts(hero_1) < 14)
      {
        GiveArtifact(hero_1, (unsigned char)cell->extraInfo, 1, -1);
        advManager_GiveResource(advM, hero_1, RESOURCE_GOLD, 1000);
      }
      else if(cell->extraInfo)
      {
        advManager_GiveResource(advM, hero_1, RESOURCE_GOLD, 1500);
      }
      eraseObject = 1;
      //goto LABEL_308;
    case LOCATION_FLOTSAM:
      switch(cell->extraInfo)
      {
        case 1u:
          advManager_GiveResource(advM, hero_1, RESOURCE_WOOD, 5);
          break;
        case 2u:
          advManager_GiveResource(advM, hero_1, RESOURCE_WOOD, 5);
          advManager_GiveResource(advM, hero_1, RESOURCE_GOLD, 200);
          break;
        case 3u:
          advManager_GiveResource(advM, hero_1, RESOURCE_WOOD, 10);
          advManager_GiveResource(advM, hero_1, RESOURCE_GOLD, 500);
          break;
        case 0u:
          break;
      }
      eraseObject = 1;
      //goto LABEL_308;
    case LOCATION_CAMPFIRE:
      advManager_GiveResource(
        advM,
        hero_1,
        RESOURCE_GOLD,
        100
      * (cell->extraInfo >> 4));
      advManager_GiveResource(
        advM,
        hero_1,
        cell->extraInfo & 0xF,
        cell->extraInfo >> 4);
      eraseObject = 1;
      //goto LABEL_308;
    case LOCATION_FORT:
      if(!((1 << (cell->extraInfo)) & hero_1->fortsVisited))
      {
        ++hero_1->primarySkills[PRIMARY_SKILL_DEFENSE];
        hero_1->fortsVisited |= 1 << cell->extraInfo;
      }
      //goto LABEL_308;
    case LOCATION_XANADU:
      if(!((1 << cell->extraInfo) & hero_1->xanadusVisited)
        && hero_1->oldLevel + 2 * hero_1->secondarySkillLevel[SECONDARY_SKILL_DIPLOMACY] >= 10)
      {
        ++hero_1->primarySkills[PRIMARY_SKILL_ATTACK];
        ++hero_1->primarySkills[PRIMARY_SKILL_DEFENSE];
        ++hero_1->primarySkills[PRIMARY_SKILL_KNOWLEDGE];
        ++hero_1->primarySkills[PRIMARY_SKILL_SPELLPOWER];
        hero_1->xanadusVisited |= 1 << cell->extraInfo;
      }
      //goto LABEL_308;
    case LOCATION_STANDING_STONES:
      if(!((1 << cell->extraInfo) & hero_1->standingStonesVisited))
      {
        ++hero_1->primarySkills[PRIMARY_SKILL_SPELLPOWER];
        hero_1->standingStonesVisited |= 1 << cell->extraInfo;
      }
      //goto LABEL_308;	  
	  

  }
  
  return;
}

bool advManager_GetMoveShowIt(hero* hero_1, int direction)
{

  return true;
}

mapCell* advManager_MoveHero(advManager* am, int direction, int stop1, int* trigX, int* trigY, int* stop2, int arg14, int* hasAdjMonster, int a9)
{
  mapCell* mc;

  return mc;
}

void advManager_UpdateRadar(advManager* am, int a2, int a3)
{

}

void advManager_CheckSetEvilInterface(advManager* advM, int a2, int a3)
{

}
