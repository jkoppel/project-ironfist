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

extern tag_monsterInfo gMonsterDatabase[66];

int hero_HasArtifact(hero* hero_1, int artifact);
int SRandom(int low, int high);

BOOL armyGroup_IsMember(armyGroup* army_1, int creatureType)
{
  for(int i = 0; i < 5; i++)
  {
    if(army_1->creatureTypes[i] == creatureType)
      return 1;
  }
  return 0;
}

// возвращает 0, если передали ошибочное число в stackIdx
BOOL armyGroup_Add(armyGroup* army_1, int creatureType, short quantity, int stackIdx)
{
  BOOL result;

  if(stackIdx == -1)
  {
    for(int i = 0; i < 5; i++)
    {
      if(army_1->creatureTypes[i] == creatureType)
      {
        stackIdx = i;
        break;
      }
    }
  }
  // добавляем в пустой слот
  if(stackIdx == -1)
  {
    for(int j = 0; j < 5; j++)
    {
      if(army_1->creatureTypes[j] == -1 || army_1->creatureTypes[j] == creatureType)
      {
        stackIdx = j;
        break;
      }
    }
  }
  // замещаем имеющийся отряд, если слот непустой
  if(stackIdx < 5 && stackIdx >= 0)
  {
    army_1->creatureTypes[stackIdx] = creatureType;
    if(army_1->quantities[stackIdx] < 0)
      army_1->quantities[stackIdx] = 0;
    army_1->quantities[stackIdx] += quantity;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

void armyGroup_Dismiss(armyGroup* army_1, int idx)
{
  army_1->creatureTypes[idx] = -1;
  army_1->quantities[idx] = 0;

  return;
}

bool  armyGroup_CanJoin(armyGroup* armyGroup_1, int creatureType)
{

	return true;
}

BOOL armyGroup_HasAllUndead(armyGroup* army_1)
{
  for(int i = 0; i < 5; i++)
  {
    if(army_1->creatureTypes[i] != -1
	  // берется старший байт creature_flags
      && !((gMonsterDatabase[army_1->creatureTypes[i]].creature_flags >> 8) & ATTR_UNDEAD))
      return 0;
  }
  return 1;
}

BOOL armyGroup_HasSomeUndead(armyGroup* army_1)
{
  for(int i = 0; i < 5; i++)
  {
    // берется старший байт creature_flags
    if(army_1->creatureTypes[i] != -1 && (gMonsterDatabase[army_1->creatureTypes[i]].creature_flags >> 8) & ATTR_UNDEAD)
      return 1;
  }
  return 0;
}

BOOL armyGroup_IsHomogeneous(armyGroup* army_1, int a2)
{
  int alignment;
  int result;
  char numOfEachAlignment[8];
  int lastCreatureID;
  int numAlignments;
  int numCreatureIDsSeen = 0;

  memset(numOfEachAlignment, 0, 7u);
  lastCreatureID = -1;
  for(int i = 0; i < 5; i++)
  {
    if(army_1->creatureTypes[i] != -1)
    {
      if(a2 == -1)
      {
        alignment = gMonsterDatabase[army_1->creatureTypes[i]].faction;
        ++numOfEachAlignment[alignment];
      }
      if(army_1->creatureTypes[i] != lastCreatureID)
      {
        ++numCreatureIDsSeen;
        lastCreatureID = army_1->creatureTypes[i];
      }
    }
  }
  if(numCreatureIDsSeen > 1)
  {
    numAlignments = 0;
    for(int i = 0; i < 7; i++)
    {
      if(numOfEachAlignment[i])
        ++numAlignments;
    }
    switch(numAlignments)
    {
      case 1:
        result = 1;
        break;
      case 3:
        result = -1;
        break;
      case 4:
        result = -2;
        break;
      default:
        if(numAlignments < 5)
          result = 0;
        else
          result = -3;
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

int armyGroup_GetMorale(armyGroup* army_1, hero* hero_1, town* town_1, char* enemyCreaturesList)
{
  int artifactMorale = 0;
  bool hasUndead = 0;
  BOOL isHomogenous = armyGroup_IsHomogeneous(army_1, -1);
  if(armyGroup_HasAllUndead(army_1))
    return 0;
  if(armyGroup_HasSomeUndead(army_1))
    hasUndead = 1;
  bool enemyHasBoneDragon = 0;
  int totMorale;

  if(enemyCreaturesList)
  {
    for(int i = 0; i < 5; i++)
    {
      if(enemyCreaturesList[i] == CREATURE_BONE_DRAGON)
        enemyHasBoneDragon = 1;
    }
  }
  if(enemyHasBoneDragon)
    artifactMorale = -1;
  if(hero_1)
  {
    if(hero_HasArtifact(hero_1, ARTIFACT_BATTLE_GARB_OF_ANDURAN))
      return 3;
    artifactMorale += hero_1->tempMoraleBonuses + hero_1->secondarySkillLevel[SECONDARY_SKILL_LEADERSHIP];
    if(hero_HasArtifact(hero_1, ARTIFACT_MEDAL_OF_VALOR))
      ++artifactMorale;
    if(hero_HasArtifact(hero_1, ARTIFACT_MEDAL_OF_COURAGE) )
      ++artifactMorale;
    if(hero_HasArtifact(hero_1, ARTIFACT_MEDAL_OF_HONOR) )
      ++artifactMorale;
    if(hero_HasArtifact(hero_1, ARTIFACT_MEDAL_OF_DISTINCTION) )
      ++artifactMorale;
    if(hero_HasArtifact(hero_1, ARTIFACT_FIZBIN_OF_MISFOURTUNE) )
      artifactMorale -= 2;
    if(hero_HasArtifact(hero_1, ARTIFACT_ARM_OF_THE_MARTYR))
      hasUndead = 1;
    if(hero_HasArtifact(hero_1, ARTIFACT_MASTHEAD) && hero_1->flags & HERO_AT_SEA )
      ++artifactMorale;
  }
  if(hasUndead)
    --artifactMorale;
  if(hasUndead && isHomogenous > 0)
    isHomogenous = 0;
  totMorale = isHomogenous + artifactMorale;
  if(town_1 && town_1->factionID != FACTION_NECROMANCER &&
	  town_1->buildingsBuiltFlags & BUILDING_TAVERN_BUILT)
    ++totMorale;
  if(town_1 && town_1->factionID == FACTION_BARBARIAN &&
	  (town_1->buildingsBuiltFlags & BUILDING_SPECIAL_BUILT))
    totMorale += 2;
  if(totMorale >= -3)
  {
    if(totMorale > 3)
      totMorale = 3;
  }
  else
  {
    totMorale = -3;
  }
  return totMorale;
}

// слишком большие риски для высокоуровневых существ
// лучше просто использовать мат.ожидание
void armyGroup_DamageGroup(armyGroup* army_1, float chance)
{
  int numKilled;
  int mustSpareACreature;

  mustSpareACreature = 1;
  for(int i = 0; i < 5; i++)
  {
    if(army_1->creatureTypes[i] == -1)
    {
      army_1->quantities[i] = 0;
    }
    else
    {
      numKilled = 0;
      for(int j = 0; j < army_1->quantities[i]; j++)
      {
        if(SRandom(0, 100) < chance * 100.0)
          ++numKilled;
      }
	  // только для одного отряда, дальше mustSpareACreature обнуляется
      if(mustSpareACreature && army_1->quantities[i] == numKilled && chance < 0.999)
        numKilled = numKilled - 1;
      army_1->quantities[i] -= numKilled;
      if(army_1->quantities[i] <= 0 || chance >= 1.0)
      {
        army_1->quantities[i] = 0;
        army_1->creatureTypes[i] = -1;
      }
      mustSpareACreature = 0;
    }
  }
}
