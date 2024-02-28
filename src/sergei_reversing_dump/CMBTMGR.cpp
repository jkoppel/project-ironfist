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

extern int giSeed;
extern advManager* gpAdvManager;
extern char giGroundToTerrain[32 * 8];
extern bool gbHumanPlayer[6];
extern char captainStats[6*4];
extern int giNextAction;
extern int giNextActionGridIndex;
extern searchGridArray* gpSearchGridArray;
extern bool bIsMoatSlowed[116];
extern float gfSSArcheryMod[4];
extern combatManager* gpCombatManager;

BOOL armyGroup_IsMember(armyGroup* army_1, int creatureType);
BOOL armyGroup_Add(armyGroup* army_1, int creatureType, short quantity, int stackIdx);
void armyGroup_Dismiss(armyGroup* army_1, int idx);
void SRand(int a1);
mapCell* advManager_GetCell(advManager* am, int col, int row);
int hero_HasArtifact(hero* hero_1, int artifact);
char hero_Stats(hero* hero_1, int skill);
void town_GiveSpells(town* town_1, hero* captain);
unsigned int army_Strength(army* army_1);
BOOL army_ValidPath(army* stack, int hexIdx, int flag);
int army_GetAttackMask(army* army_1, int hexIdx, int focusLevel, int targetHexIdx);
int army_ValidAttack(army* army_1, int hexIdx, int direction, int focusLevel, int targetHexIdx, int* neighborIdx);
int searchArray_QuickDistance(int x1, int y1, int x2, int y2);
int searchArray_FindCombatPath(searchGridArray* sa, int sourceHexIdx, int targetHexIdx, army* stack, BOOL isTargetSearch, int twoHexer);
int army_GetAdjacentCellIndex(army* army_1, int hexIdx, int direction);
void town_CalcNumLevelArchers(town* town_1, int* numArchers, int* attack);
bool ValidHex(int hexIdx);

char* combatManager_GetBackgroundName(combatManager* cm)
{
 char x;

 return &x;
}

// из армии 1 добавляется в армию 2
void combatManager_CombineGroups(armyGroup* army_1, armyGroup* army_2)
{
  if(army_1 && army_2)
  {
    for(int i = 0; i < 5; i++)
    {
      if(armyGroup_IsMember(army_2, army_1->creatureTypes[i]))
      {
	    // -1 означает что не в какой-то определенный слот
        armyGroup_Add(army_2, army_1->creatureTypes[i], army_1->quantities[i], -1);
        armyGroup_Dismiss(army_1, i);
      }
    }
	// если есть пустые слоты в армии 2, то туда добавляем
	// однако не видим, что из гарнизона что-то удаляется, если не находим слотов
	// возможно в случае выигрыша битвы гарнизон возвращается на свое место
	// за исключением отрядов, переданных оборонявшемуся герою
	// Также отметим, что первыми передаются отряды гарнизона слева
	// возможно самые сильные отряды следует поместить влево
    for(int i = 0; i < 5; i++)
    {
      if(army_1->creatureTypes[i] != -1)
      {
        for(int j = 0; j < 5; j++)
        {
          if(army_2->creatureTypes[j] == -1)
          {
            armyGroup_Add(army_2, army_1->creatureTypes[i], army_1->quantities[i], j);
            armyGroup_Dismiss(army_1, i);
          }
        }
      }
    }
  }

  return;
}

combatManager* combatManager_SetupCombat(combatManager* cm, int x, int y, hero* hero_1, armyGroup* army_1, town* town_1, hero* hero_2, armyGroup* army_2, int a8, int a9, int a10)
{
  char* backgroundName;

  giSeed = a10;
  SRand(a9 + 100 * a8);
  cm->field_F4FB = a8;
  cm->field_F4FF = a9;
  if(x < 0)
	cm->combatMapCell = 0;
  else
    cm->combatMapCell = advManager_GetCell(gpAdvManager, x, y);
  cm->terrainType = giGroundToTerrain[cm->combatMapCell->groundIndex];
  backgroundName = combatManager_GetBackgroundName(cm);
  sprintf(cm->combatBackgroundFilename, backgroundName);

  if(hero_1)
  {
	cm->playerID[0] = hero_1->ownerIdx;
	army_1 = &hero_1->army;
  }
  else
  {
    cm->playerID[0] = -1;
  }
  if(hero_2)
  {
    cm->playerID[1] = hero_2->ownerIdx;
    army_2 = &hero_2->army;
  }
  else if(town_1)
  {
	cm->playerID[1] = town_1->ownerIdx;
    army_2 = &town_1->garrison;
  }
  else
  {
    cm->playerID[1] = -1;
  }
  for(int side = 0; side < 2; side++)
  {
    if(cm->playerID[side] < 0)
      cm->involvedInBadMorale[side] = 0;
    else
      cm->involvedInBadMorale[side] = gbHumanPlayer[cm->playerID[side]];
    if(side)
      cm->heroes[side] = (hero*)hero_2;
    else
      cm->heroes[0] = (hero*)hero_1;
    if(cm->heroes[side])
      cm->heroes[side]->isCaptain = 0;
    if(side)
      cm->armies[side] = (armyGroup*)army_2;
    else
      cm->armies[0] = (armyGroup*)army_1;
    cm->timesCatapultMustFire[side] = 1;
    cm->_11[side] = cm->timesCatapultMustFire[side];
    if(cm->heroes[side] && hero_HasArtifact(cm->heroes[side], ARTIFACT_BALLISTA_OF_QUICKNESS))
    {
      cm->timesCatapultMustFire[side] = 2;
      cm->_11[side] = cm->timesCatapultMustFire[side];
    }
    if(cm->heroes[side])
    {
      if(cm->heroes[side]->secondarySkillLevel[SECONDARY_SKILL_BALLISTICS] >= 2)
      {
        ++cm->_11[side];
        ++cm->timesCatapultMustFire[side];
      }
    }
    cm->timesGarrisonMustFire[side] = 1;
    cm->_12[side] = 0;
    cm->field_353F[side] = 0;
  }
  cm->hasMoat = 0;
  if(town_1)
  {
	if(town_1->visitingHeroIdx == -1)
    {
      cm->_12[1] = 0;
    }
    else
    {
      cm->armies[1] = &cm->heroes[1]->army;
	  combatManager_CombineGroups(&town_1->garrison, &cm->heroes[0]->army);
      cm->_12[1] = 1;
    }
    if(town_1->buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
      cm->isCastleBattle = 1;
    else
      cm->isCastleBattle = 0;
    if(cm->isCastleBattle)
    {
      if(town_1->buildingsBuiltFlags & BUILDING_MOAT_BUILT)
        cm->hasMoat = 1;
      else
        cm->hasMoat = 0;
    }
    cm->drawBridgePosition = 4;
    cm->castles[1] = town_1;
    cm->field_31E6 = (int)cm->castles[1];
    if(!cm->heroes[1] && town_1->buildingsBuiltFlags & BUILDING_CAPTAIN_BUILT)
    {
      cm->heroes[1] = &cm->captain;
      memset(&cm->captain, 0, 0xFAu);
      for(int skill = 0; skill < 4; skill++)
        cm->captain.primarySkills[skill] = captainStats[4 * cm->castles[1]->factionID + skill];
      cm->captain.spellpoints = 10 * hero_Stats(&cm->captain, PRIMARY_SKILL_KNOWLEDGE);
      cm->captain.factionID = cm->castles[1]->factionID;
      cm->captain.heroID = cm->castles[1]->factionID + 90;
      strcpy(cm->captain.name, "Captain");
      for(int stack = 0; stack < 5; stack++)
        cm->captain.army.creatureTypes[stack] = -1;
      for(int artSlot = 0; artSlot < 14; artSlot++)
        cm->captain.artifacts[artSlot] = -1;
      cm->captain.artifacts[0] = ARTIFACT_MAGIC_BOOK;
      town_GiveSpells(cm->castles[1], &cm->captain);
      cm->captain.isCaptain = 1;
    }
  }
  else
  {
    cm->isCastleBattle = 0;
    cm->castles[1] = 0;
  }
  cm->castles[0] = 0;
  return cm;
}

void combatManager_SetupAdjacencyArray(combatManager* cm)
{
//   5  0
// 4  -   1
//   3  2

  int row; // row от 0
  int neighborIndex;

  // на самом деле поле состоит из 117 клеток, а не из 99 (+18 клеток)
  for(int i = 0; i < 117; i++)
  {
    row = i / 13;
	// проходимся по соседям
    for(int j = 0; j < 6; j++)
    {
	  // если не крайний (левый или правый) ряд
      if(i % 13 && i % 13 != 12)
      {
        switch(j)
        {
          case 0:
		    // если ряд нечетный
            if(row & 1)
              neighborIndex = i - 13;
			// если ряд четный
            else
              neighborIndex = i - 12;
            break;
          case 2:
            if(row & 1)
              neighborIndex = i + 13;
            else
              neighborIndex = i + 14;
            break;
          case 3:
            if(row & 1)
              neighborIndex = i + 12;
            else
              neighborIndex = i + 13;
            break;
          case 5:
            if(row & 1)
              neighborIndex = i - 14;
            else
              neighborIndex = i - 13;
            break;
          case 1:
            neighborIndex = i + 1;
            break;
          case 4:
            neighborIndex = i - 1;
            break;
          default:
            break;
        }
		// если рассматриваемый сосед не в крайнем ряду
        if(neighborIndex % 13 && neighborIndex % 13 != 12 &&
			neighborIndex >= 0 && neighborIndex < 117)
        {
          cm->hexNeighbors[i][j] = neighborIndex;
        }
        else
        {
          cm->hexNeighbors[i][j] = -1;
        }
      }
	  //  если рассматриваемый гекс не в крайнем ряду 
      else
      {
        cm->hexNeighbors[i][j] = -1;
      }
    }
  }
  return;
}

int combatManager_GetWorstArmy(combatManager* cm, int side, int targetStacksMask)
{

  int currentStackMask = 1;
  int minStackStrength = 0;
  int worstStackIdx = -1;
  int stackStrength;
  
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(currentStackMask & targetStacksMask)
    {
      stackStrength = army_Strength(&cm->creatures[side][i]);
      if(stackStrength < minStackStrength)
      {
        worstStackIdx = i;
        minStackStrength = stackStrength;
      }
    }
    currentStackMask = currentStackMask << 1;
  }
  return worstStackIdx;
}

int combatManager_GetBestArmy(combatManager* cm, int side, int targetStacksMask)
{

  int currentStackMask = 1;
  int bestStackIdx = -1;
  int maxStackStrength = 0;
  int stackStrength;
  
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(currentStackMask & targetStacksMask)
    {
      stackStrength = army_Strength(&cm->creatures[side][i]);
      if(cm->creatures[side][i].effectStrengths[EFFECT_BLIND]
        || cm->creatures[side][i].effectStrengths[EFFECT_PARALYZE]
        || cm->creatures[side][i].effectStrengths[EFFECT_PETRIFY]
        || cm->creatures[side][i].effectStrengths[EFFECT_BERSERKER]
        || cm->creatures[side][i].effectStrengths[EFFECT_HYPNOTIZE])
        stackStrength /= 2;
      if(maxStackStrength < stackStrength)
      {
        bestStackIdx = i;
        maxStackStrength = stackStrength;
      }
    }
    currentStackMask = currentStackMask << 1;
  }
  return bestStackIdx;
}

BOOL combatManager_AttemptAttack(combatManager* cm, army* stack, int passiveSide, int targetStacksMask)
{

  int targetStackIdx;
  int secondHexIdx;
  int hexIdx;
  
  while(targetStacksMask)
  {
    if(stack->creatureIdx == CREATURE_GHOST)
      targetStackIdx = combatManager_GetWorstArmy(cm, passiveSide, targetStacksMask);
    else
      targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, targetStacksMask);
    if(targetStackIdx == -1)
      return 0;
    stack->targetOwner = passiveSide;
    stack->targetStackIdx = targetStackIdx;
    hexIdx = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
    stack->targetHex = hexIdx;
    if(army_ValidPath(stack, hexIdx, 0))
    {
      giNextAction = 2;
      giNextActionGridIndex = hexIdx;
      return 1;
    }
	// может, этот if вынести перед предыдущим ?
    if(cm->creatures[passiveSide][targetStackIdx].creature.creature_flags & TWO_HEXER)
    {
      secondHexIdx = cm->creatures[passiveSide][targetStackIdx].facingRight ? hexIdx + 1 : hexIdx - 1;
      stack->targetHex = secondHexIdx;
      if(army_ValidPath(stack, secondHexIdx, 0))
      {
        giNextAction = 2;
        giNextActionGridIndex = secondHexIdx;
        return 1;
      }
    }
	// записываем 0 по цели, которую уже пытались обработать
    targetStacksMask &= ~(1 << targetStackIdx);
  }
  return 0;
}

BOOL combatManager_AttemptAdjacentAttack(combatManager* cm, army* stack)
{

  // обратная маска. единицы - куда можно бить
  int directionMask = ~army_GetAttackMask(stack, stack->occupiedHex, 1, -1);
  int direction;
  int targetStacksMask;
  int targetStackIdx;
  int neighborIdx;
  BOOL result;
  
  if(directionMask)
  {
    direction = 1;
    targetStacksMask = 0;
    for(int directionIdx = 0; directionIdx < 8; directionIdx++)
    {
      if((direction & directionMask) && army_ValidAttack(stack, stack->occupiedHex, directionIdx, 1, -1, &neighborIdx))
      {
        if(neighborIdx >= 0)
          targetStacksMask |= 1 << cm->combatGrid[neighborIdx].stackIdx;
      }
      direction = direction << 1;
    }
    if(stack->creatureIdx == CREATURE_GHOST)
      targetStackIdx = combatManager_GetWorstArmy(cm, 1 - cm->currentActionSide, targetStacksMask);
    else
      targetStackIdx = combatManager_GetBestArmy(cm, 1 - cm->currentActionSide, targetStacksMask);
    if(targetStackIdx == -1)
    {
      result = 0;
    }
    else
    {
      giNextAction = 2;
	  giNextActionGridIndex = cm->creatures[1 - cm->currentActionSide][targetStackIdx].occupiedHex;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

// Это должно быть заменено на честный поиск пути
int combatManager_GetClosestArmy(combatManager* cm, army *stack, int passiveSide, int targetStacksMask)
{

  int currentStackMask = 1;
  int minWeight = 9999999;
  int closestStackIdx = -1;
  int pixelDistance;
  int hp;
  
  for(int i = 0; i < cm->numCreatures[passiveSide]; i++)
  {
    if(currentStackMask & targetStacksMask)
    {
      pixelDistance = searchArray_QuickDistance(
               cm->combatGrid[stack->occupiedHex].centerX,
               cm->combatGrid[stack->occupiedHex].occupyingCreatureBottomY,
               cm->combatGrid[cm->creatures[passiveSide][i].occupiedHex].centerX,
               cm->combatGrid[cm->creatures[passiveSide][i].occupiedHex].occupyingCreatureBottomY);
      hp = cm->creatures[passiveSide][i].creature.hp;
	  // забавный принцип - кроме дистанции еще учитываем hp цели
      if(minWeight > 1000 * pixelDistance - cm->creatures[passiveSide][i].quantity * hp)
      {
        closestStackIdx = i;
        minWeight = 1000 * pixelDistance - cm->creatures[passiveSide][i].quantity * hp;
      }
    }
    currentStackMask = currentStackMask << 1;
  }
  return closestStackIdx;
}

BOOL combatManager_WalkTowardArmy(combatManager* cm, army* stack, int passiveSide, int targetStacksMask)
{
  BOOL result;
  int targetStackIdx = combatManager_GetClosestArmy(cm, stack, passiveSide, targetStacksMask);
  army* targetStack;
  int targetHexIdx;
  int saveSpeed;
  int remainingMovements;
  int stepIdx;
  
  if(targetStackIdx == -1)
  {
    result = 0;
  }
  else
  {
	targetStack = &cm->creatures[passiveSide][targetStackIdx];
    targetHexIdx = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
    stack->targetOwner = passiveSide;
    stack->targetStackIdx = targetStackIdx;
	// если некого атаковать рядом (все направления равны 1)
    if(army_GetAttackMask(stack, stack->occupiedHex, 0, -1) == 255)
    {
      saveSpeed = stack->creature.speed;
      stack->creature.speed = 127;
	  // если не нашли путь к двугексовому существу, то пробуем найти другой его гекс
      if(!searchArray_FindCombatPath(gpSearchGridArray, stack->occupiedHex, targetHexIdx, stack, -1, 0)
        && targetStack->creature.creature_flags & TWO_HEXER)
      {
        if(targetStack->facingRight)
        {
          if(targetStack->facingRight == 1)
            ++targetHexIdx;
        }
        else
        {
          --targetHexIdx;
        }
        if(targetHexIdx != -1)
          searchArray_FindCombatPath(gpSearchGridArray, stack->occupiedHex, targetHexIdx, stack, -1, 0);
      }
      stack->creature.speed = saveSpeed;
	  // то есть отрабатываем только если минимум 2 шага
      if(gpSearchGridArray->nSteps <= 1)
      {
        result = 0;
      }
      else
      {
        giNextAction = 2;
        remainingMovements = stack->creature.speed;
        stepIdx = gpSearchGridArray->nSteps - 1;
        giNextActionGridIndex = stack->occupiedHex;
        while(stepIdx >= 1 && remainingMovements)
        {
          giNextActionGridIndex = army_GetAdjacentCellIndex(
                                    stack,
                                    giNextActionGridIndex,
                                    gpSearchGridArray->directionToTarget[stepIdx--]);
          --remainingMovements;
          if(giNextActionGridIndex > 0)
          {
            if(bIsMoatSlowed[giNextActionGridIndex])
              remainingMovements = 0;
          }
        }
        result = 1;
      }
    }
    else
    {
      giNextAction = 3;
      result = 1;
    }
  }
  return result;
}

BOOL combatManager_WalkTowardArmyFront(combatManager* cm, army* stack, int passiveSide, int targetStacksMask)
{
  BOOL result;

  return result;
}

int combatManager_GetMirrorImageMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int mirrorImageMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD))
    {
      if (cm->creatures[side][i].creature.creature_flags & MIRROR_IMAGE)
        mirrorImageMask |= currentStackMask;
    }
    currentStackMask = currentStackMask << 1;
  }
  return mirrorImageMask;
}

int combatManager_GetShooterMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int shooterMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD)
      && cm->creatures[side][i].creature.creature_flags & SHOOTER
      && cm->creatures[side][i].creature.shots > 0
      && !cm->creatures[side][i].effectStrengths[EFFECT_BLIND]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PARALYZE]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PETRIFY]
      && !cm->creatures[side][i].effectStrengths[EFFECT_BERSERKER])
    {
      if(!cm->creatures[side][i].effectStrengths[EFFECT_HYPNOTIZE])
        shooterMask |= currentStackMask;
    }
    currentStackMask = currentStackMask << 1;
  }
  return shooterMask;
}

int combatManager_GetFlyerMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int flyerMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD)
      && cm->creatures[side][i].creature.creature_flags & FLYER
      && !cm->creatures[side][i].effectStrengths[EFFECT_BLIND]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PARALYZE]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PETRIFY]
      && !cm->creatures[side][i].effectStrengths[EFFECT_BERSERKER])
    {
      if(!cm->creatures[side][i].effectStrengths[EFFECT_HYPNOTIZE])
        flyerMask |= currentStackMask;
    }
    currentStackMask = currentStackMask << 1;
  }
  return flyerMask;
}

int combatManager_GetWalkerMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int walkerMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD)
      && !(cm->creatures[side][i].creature.creature_flags & FLYER)
      && (!(cm->creatures[side][i].creature.creature_flags & SHOOTER)	  
      || cm->creatures[side][i].creature.shots <= 0))
    {
      if(!cm->creatures[side][i].effectStrengths[EFFECT_BLIND]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PARALYZE]
      && !cm->creatures[side][i].effectStrengths[EFFECT_PETRIFY]
      && !cm->creatures[side][i].effectStrengths[EFFECT_BERSERKER])
      {
        if(!cm->creatures[side][i].effectStrengths[EFFECT_HYPNOTIZE])
          walkerMask |= currentStackMask;
      }
    }
    currentStackMask = currentStackMask << 1;
  }
  return walkerMask;
}

int combatManager_GetOutOfItMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int outOfItMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD)
      && (cm->creatures[side][i].effectStrengths[EFFECT_BLIND]
       || cm->creatures[side][i].effectStrengths[EFFECT_PARALYZE]
       || cm->creatures[side][i].effectStrengths[EFFECT_PETRIFY]))
      outOfItMask |= currentStackMask;
    currentStackMask = currentStackMask << 1;
  }
  return outOfItMask;
}

int combatManager_GetTraitorMask(combatManager* cm, int side)
{

  int currentStackMask = 1;
  int traitorMask = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if(&cm->creatures[side][i] != 0
      && !(cm->creatures[side][i].creature.creature_flags & DEAD)
      && (cm->creatures[side][i].effectStrengths[EFFECT_BERSERKER] || cm->creatures[side][i].effectStrengths[EFFECT_HYPNOTIZE]))
      traitorMask |= currentStackMask;
    currentStackMask = currentStackMask << 1;
  }
  return traitorMask;
}

int combatManager_DoLichShot(combatManager* cm, army* stack)
{
  int result = 1;

  return result;
}

int combatManager_GetStrength(combatManager* cm, int side, int stacksMask)
{

  int currentStackMask = 1;
  int strength = 0;
  for(int i = 0; i < cm->numCreatures[side]; i++)
  {
    if((currentStackMask & stacksMask) && (&cm->creatures[side][i] != 0))
    {
      if(!(cm->creatures[side][i].creature.creature_flags & DEAD))
		strength += army_Strength(&cm->creatures[side][i]);
    }
    currentStackMask = currentStackMask << 1;
  }
  return strength;
}

void combatManager_DoCompAI(combatManager* cm, int side)
{

  cm->field_F2B7 = 0;
  army* stack = &cm->creatures[cm->activeStackOwner][cm->activeStack];
  int fighterType = 0;
  int passiveSide = 1 - cm->currentActionSide;
  int mirrorImageMask[2];
  int shooterMask[2];
  int flyerMask[2];
  int walkerMask[2];
  int outOfItMask[2];
  int traitorMask[2];
  
  int shooterStrength[2];
  int traitorStrength;
  int reducedTraitorStrength;
  
  mirrorImageMask[cm->currentActionSide] = combatManager_GetMirrorImageMask(cm, cm->currentActionSide);
  mirrorImageMask[passiveSide] = combatManager_GetMirrorImageMask(cm, passiveSide);
  shooterMask[cm->currentActionSide] = combatManager_GetShooterMask(cm, cm->currentActionSide);
  shooterMask[passiveSide] = combatManager_GetShooterMask(cm, passiveSide);
  flyerMask[cm->currentActionSide] = combatManager_GetFlyerMask(cm, cm->currentActionSide);
  flyerMask[passiveSide] = combatManager_GetFlyerMask(cm, passiveSide);
  walkerMask[cm->currentActionSide] = combatManager_GetWalkerMask(cm, cm->currentActionSide);
  walkerMask[passiveSide] = combatManager_GetWalkerMask(cm, passiveSide);
  outOfItMask[cm->currentActionSide] = combatManager_GetOutOfItMask(cm, cm->currentActionSide);
  outOfItMask[passiveSide] = combatManager_GetOutOfItMask(cm, passiveSide);
  traitorMask[cm->currentActionSide] = combatManager_GetTraitorMask(cm, cm->currentActionSide);
  traitorMask[passiveSide] = combatManager_GetTraitorMask(cm, passiveSide);
  shooterStrength[cm->currentActionSide] = combatManager_GetStrength(
                                    cm,
                                    cm->currentActionSide,
                                    shooterMask[cm->currentActionSide]);
  shooterStrength[passiveSide] = combatManager_GetStrength(cm, passiveSide, shooterMask[passiveSide]);
  int activeSideAllStrength = combatManager_GetStrength(
          cm,
          cm->currentActionSide,
          traitorMask[cm->currentActionSide] | outOfItMask[cm->currentActionSide] | walkerMask[cm->currentActionSide] | flyerMask[cm->currentActionSide] | shooterMask[cm->currentActionSide]);
  int reducedActiveSideAllStrength = (activeSideAllStrength + 4) / 5;
  bool isOurStrongShooters = 0;
  bool isEnemyShootersStronger = 0;
  // лишнее
  int activeSideShooterStrength = combatManager_GetStrength(cm, cm->currentActionSide, shooterMask[cm->currentActionSide]);
  int passiveSideShooterStrength = combatManager_GetStrength(cm, passiveSide, shooterMask[passiveSide]);
  
  int numArchers;
  int attack;
  town* town_1;
  int addArchers;
  int archersStrength;

  int row;
  
  if(cm->isCastleBattle)
  {
	// слишком упрощенно
    if(!cm->heroes[0]->secondarySkillLevel[SECONDARY_SKILL_ARCHERY] && !hero_HasArtifact(cm->heroes[0], ARTIFACT_GOLDEN_BOW))
    {
      if(cm->currentActionSide)
        shooterStrength[passiveSide] /= 2;
      else
        shooterStrength[cm->currentActionSide] /= 2;
    }
    if(!cm->ballistaDestroyed)
    {
      town_1 = cm->castles[1];
      town_CalcNumLevelArchers(cm->castles[1], &numArchers, &attack);
      addArchers = 0;
      if(cm->turretStatus[0] == 1)
        addArchers += numArchers / 2;
      if ( cm->turretStatus[3] == 1 )
        addArchers += numArchers / 2;
      numArchers += addArchers;
      archersStrength = ((float)attack * 0.1 + 1.0) * (float)(300 * numArchers);
	  // лишнее
      //v16 = !cm->heroes[0] || !hero_HasArtifact(cm->heroes[0], ARTIFACT_GOLDEN_BOW) && !cm->heroes[0]->secondarySkillLevel[SECONDARY_SKILL_ARCHERY];
      if(cm->currentActionSide == 1 )
        activeSideShooterStrength += archersStrength;
      else
        passiveSideShooterStrength += archersStrength;
    }
  }
  if(cm->heroes[cm->currentActionSide])
    activeSideShooterStrength = (double)activeSideShooterStrength * gfSSArcheryMod[cm->heroes[cm->currentActionSide]->secondarySkillLevel[SECONDARY_SKILL_ARCHERY]];
  if(cm->heroes[1 - cm->currentActionSide])
    passiveSideShooterStrength = (double)passiveSideShooterStrength
                         * gfSSArcheryMod[cm->heroes[1 - cm->currentActionSide]->secondarySkillLevel[SECONDARY_SKILL_ARCHERY]];

  if((activeSideAllStrength + 4) / 5 < activeSideShooterStrength)
    isOurStrongShooters = 1;
  if(activeSideShooterStrength < passiveSideShooterStrength)
    isEnemyShootersStronger = 1;

  if(stack->creature.creature_flags & SHOOTER)
  {
    if(stack->creature.shots <= 0)
      fighterType = 3;
    else
      fighterType = 1;
  }
  else if(stack->creature.creature_flags & FLYER)
  {
    fighterType = 2;
  }
  else
  {
    fighterType = 3;
  }
  int targetStackIdx;
  char moatHexIdx[9];
  
  //bool attackTarget = false;
  //bool targetNotFound = false;
  
  // если стрелок
  if(fighterType == 1)
  {
    //if(combatManager_AttemptAdjacentAttack(cm, stack))
    //  attackTarget = true;//goto LABEL_104;
    if(!(combatManager_AttemptAdjacentAttack(cm, stack)))//else
	{
		if(stack->creatureIdx != CREATURE_LICH && stack->creatureIdx != CREATURE_POWER_LICH)
		{
		  targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, mirrorImageMask[passiveSide]);
		  if(targetStackIdx == -1)
		  {
			targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, shooterMask[passiveSide]);
			if(targetStackIdx == -1)
			{
			  targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, flyerMask[passiveSide]);
			  if(targetStackIdx == -1)
			  {
				if(walkerMask[passiveSide] && (targetStackIdx = combatManager_GetClosestArmy(cm, stack, passiveSide, walkerMask[passiveSide]), targetStackIdx != -1))
				{
				  giNextAction = 2; // атаковать
				  giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
				}
				else
				{
				  targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, outOfItMask[passiveSide]);
				  if(targetStackIdx == -1)
				  {
					// ну да, может быть и такое, что во всей вражеской армии остались только существа "под контролем"
					targetStackIdx = combatManager_GetBestArmy(cm, passiveSide, traitorMask[passiveSide]);
					if(targetStackIdx == -1)
					  giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
					else
					{
					giNextAction = 2;
					giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
					}
				  }
				  else
				  {
					giNextAction = 2;
					giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
				  }
				}
			  }
			  else
			  {
				giNextAction = 2;
				giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
			  }
			}
			else
			{
			  giNextAction = 2;
			  giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
			}
		  }
		  else
		  {
			giNextAction = 2;
			giNextActionGridIndex = cm->creatures[passiveSide][targetStackIdx].occupiedHex;
		  }
		}
		else
		{
		  combatManager_DoLichShot(cm, stack);
		}
	}
  }
  // Летуны
  else if(fighterType == 2)
  {
    if(!isOurStrongShooters || isEnemyShootersStronger)
    {
      if(!combatManager_AttemptAttack(cm, stack, passiveSide, mirrorImageMask[passiveSide])
        && !combatManager_AttemptAttack(cm, stack, passiveSide, shooterMask[passiveSide])
        && !combatManager_AttemptAttack(cm, stack, passiveSide, flyerMask[passiveSide])
        && !combatManager_AttemptAttack(cm, stack, passiveSide, walkerMask[passiveSide])
        && !combatManager_AttemptAttack(cm, stack, passiveSide, outOfItMask[passiveSide])
        && !combatManager_AttemptAttack(cm, stack, passiveSide, traitorMask[passiveSide]))
          giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
    } 
	// здесь то же самое что и в предыдущем if. В этом и проблема -
	// нужно придумать более оптимальную стратегию для случая когда у нас сильные стрелки
	// здесь идет именно попытка атаки (а не просто движение в сторону противника)
	// нужно для случая защиты в крепости проверять на какой гекс мы идем в случае атаки -
	// допустимо только внутри крепости
    else if(!combatManager_AttemptAttack(cm, stack, passiveSide, mirrorImageMask[passiveSide])
  && !combatManager_AttemptAttack(cm, stack, passiveSide, shooterMask[passiveSide])
  && !combatManager_AttemptAttack(cm, stack, passiveSide, flyerMask[passiveSide])
  && !combatManager_AttemptAttack(cm, stack, passiveSide, walkerMask[passiveSide])
  && !combatManager_AttemptAttack(cm, stack, passiveSide, outOfItMask[passiveSide])
  && !combatManager_AttemptAttack(cm, stack, passiveSide, traitorMask[passiveSide]))
    {
       giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
    }
  }
  else
  {
    if(fighterType != 3)
    {
//LABEL_103:
      giNextAction = 3; // если не стрелки, не летуны и не файтеры, то остается развести руками
      //goto LABEL_104;
    }
	else// итак, если файтеры
	{
		if(!isOurStrongShooters || isEnemyShootersStronger)
		{
		  if ( !combatManager_AttemptAttack(cm, stack, passiveSide, mirrorImageMask[passiveSide])
			&& !combatManager_AttemptAttack(cm, stack, passiveSide, shooterMask[passiveSide])
			&& !combatManager_AttemptAttack(cm, stack, passiveSide, flyerMask[passiveSide])
			&& !combatManager_AttemptAttack(cm, stack, passiveSide, walkerMask[passiveSide])
			&& !combatManager_AttemptAttack(cm, stack, passiveSide, outOfItMask[passiveSide])
			&& !combatManager_AttemptAttack(cm, stack, passiveSide, traitorMask[passiveSide])
			&& !combatManager_WalkTowardArmy(cm, stack, passiveSide, shooterMask[passiveSide])
			&& !combatManager_WalkTowardArmy(cm, stack, passiveSide, walkerMask[passiveSide])
			&& !combatManager_WalkTowardArmy(cm, stack, passiveSide, flyerMask[passiveSide])
			&& !combatManager_WalkTowardArmy(cm, stack, passiveSide, outOfItMask[passiveSide])
			&& !combatManager_WalkTowardArmy(cm, stack, passiveSide, traitorMask[passiveSide]))
		  {
			moatHexIdx[0] = 8;
			moatHexIdx[1] = 21;
			moatHexIdx[2] = 33;
			moatHexIdx[3] = 46;
			moatHexIdx[4] = 58;
			moatHexIdx[5] = 72;
			moatHexIdx[6] = 85;
			moatHexIdx[7] = 99;
			moatHexIdx[8] = 112;
			row = stack->occupiedHex / 13;
			// если защищающиеся, то не найдя атаку - ничего не делать
			if(cm->currentActionSide)
			  giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
			// если атакующие и не осада, то не найдя атаку - ничего не делать
			if(!cm->isCastleBattle)
			  giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
			// если стек правее рва (причем даже без проверки на осаду), то не найдя атаку - ничего не делать
			if(moatHexIdx[row] <= stack->occupiedHex)
			  giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
			// если во рву никакой цели нет, то не найдя атаку - ничего не делать		
			if(!ValidHex(moatHexIdx[row]) || gpCombatManager->combatGrid[moatHexIdx[row]].unitOwner != -1 || gpCombatManager->combatGrid[moatHexIdx[row]].isBlocked)
			  giNextAction = 3; //targetNotFound = true;//goto LABEL_103;
			if(giNextAction != 3)
			{
				giNextAction = 2;
				giNextActionGridIndex = moatHexIdx[row];
			}
		  }
		}
		else if ( !combatManager_AttemptAttack(cm, stack, passiveSide, mirrorImageMask[passiveSide])
	  && !combatManager_AttemptAttack(cm, stack, passiveSide, shooterMask[passiveSide])
	  && !combatManager_AttemptAttack(cm, stack, passiveSide, flyerMask[passiveSide])
	  && !combatManager_AttemptAttack(cm, stack, passiveSide, walkerMask[passiveSide])
	  && !combatManager_AttemptAttack(cm, stack, passiveSide, outOfItMask[passiveSide])
	  && !combatManager_AttemptAttack(cm, stack, passiveSide, traitorMask[passiveSide])
	  && !combatManager_WalkTowardArmyFront(cm, stack, cm->currentActionSide, shooterMask[cm->currentActionSide]) )
		{
		  giNextAction = 3;
		}
	}
  }
//LABEL_104:
// если выбрано действие "бить" но цели в ячейке нет
  int newHexIdx;
  if(giNextAction == 2
    && giNextActionGridIndex > 0
    && giNextActionGridIndex < 117
    && gpCombatManager->combatGrid[giNextActionGridIndex].unitOwner == -1)
  {
    for(int direction = 0; direction < 6; direction++)
    {
      newHexIdx = army_GetAdjacentCellIndex(stack, giNextActionGridIndex, direction);
	  // то атакуем ячейку рядом с прежней
      if(newHexIdx > 0 && newHexIdx < 117 && gpCombatManager->combatGrid[newHexIdx].unitOwner == 1 - cm->currentActionSide )
      {
        giNextActionGridIndex = newHexIdx;
        return;
      }
    }
  }
}
