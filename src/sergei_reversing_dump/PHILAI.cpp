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

extern int iAlphaMale;
extern int giCurPlayer;
extern playerData* gpCurPlayer;
extern game* gpGame;
extern tag_monsterInfo gMonsterDatabase[66];
extern float gfSSAIArcheryMod[4];
extern float gfStatPower[40];
extern float maxAIDurationMod;
extern float maxAISpellPowerMod;
extern float gfPhilAIDurationMod[12];
extern float gfPhilAISpellPowerMod[12];
extern SSpellInfo gsSpellInfo[48];
extern float gfSpellCastNumMod[12];
extern float gfSpellTypeNumMod[12];
extern int gArtifactBaseRV[103];
extern int gHeroGoldCost;
extern bool bHeroBuiltThisTurn;
extern char gDwellingType[12 * 6];
extern int MAP_WIDTH;
extern int MAP_HEIGHT;
extern bool* gaiEnemyHeroReachable;
extern short* gaiLiveChanceOfPos;
extern short* gaiHeroStrategicRVOfPos;
extern short* gaiHeroEventStratRVOfPos;
extern char* gaiTurnValueOfMine;
extern advManager* gpAdvManager;
extern bool bSVSearchArrayInUse;
extern searchArray SVSearchArray;
extern hero* gpCurAIHero;
extern int iDummy;
extern int gaiHeroLiveChance[54];
extern bool gbHumanPlayer[6];
extern char giGroundToTerrain[32 * 8];
extern searchArray* gpSearchArray;
extern int giCurTurn;
extern float gfHeroInteractionBonus[54];
extern bool gbReduceByReload;
extern bool gbReduceByBerserk;
extern bool gbIAmGreatest;
extern char giCurPlayerBit;
extern float gfAttackHumanBonus;
extern float gfAttackComputerBonus;
extern bool gbPossibleShipyardFound;
extern bool gbActualShipyardFound;
extern bool gbActualBoatFound;
extern int giBestShipyardDist;
extern int giBestShipyardId;
extern int giBuildShipyard[6];
extern int giBuildBoat[6];
extern int giBuildBoatStuffTurn[6];
extern float fFirstWeekTownFV;
extern int giHumanTownConquered;
extern bool gbTroopReload;
extern char* mapRevealed;
extern int gSSValues[13][3];
extern char normalDirTable[32];
extern float fReduceFactor;
extern float fBerserkFactor;
extern int giMaxHeroesForThisPlayer;
extern creatureUpgrades gpCreatureUpgrades[6];
extern float gafAITurnCostResource[7];
extern bool gbRetreatWin;
extern armyGroup* gpMonGroup;
extern bool gbBerserk;
extern int iCurHourGlassPhase;
extern bool gbGameOver;
extern int giLimitPlayer;
extern int giCurAIHeroMorale;
extern int giCurAIHeroLuck;
extern int iCurPlaceToVisit;
extern int giShowComputerRoute;
extern int blackoutComputer;
extern int gbRemoteOn;
extern char giCurWatchPlayerBit;
extern bool bShowIt;
extern int iSandAnim;
extern placesVisited iPlacesVisited[1248];
extern mouseManager* gpMouseManager;
extern int gResourceBaseValue[7];

char hero_Stats(hero* hero_1, int skill);
int game_GetLuck(hero* hero_1, armyGroup* armyGroup_1, town* town_1);
int armyGroup_GetMorale(armyGroup* army_1, hero* hero_1, town* town_1, char* enemyCreaturesList);
town* hero_GetOccupiedTown(hero* hero_1);
char hero_Stats(hero* hero_1, int skill);
void town_CalcNumLevelArchers(town* town_1, int* numArchers, int* attack);
int hero_HasArtifact(hero* hero_1, int artifact);
int hero_HasSpell(hero* hero_1, int spell);
int GetManaCost(int spell, hero* hero_1);
int game_SetupPuzzlePieces(game* gp, int playerIdx, bool isAi);
void GetMonsterCost(int mon, int* costs);
signed int CanBuy(town* a1, int a2);
mapCell* advManager_GetCell(advManager* am, int col, int row);
searchArray* searchArray_searchArray(searchArray *sa);
void searchArray_Init(searchArray* sa);
void searchArray_SeedPosition(searchArray* sa, int x0, int y0, int directionFacing, int limitDistance, BOOL heroAtSea, BOOL proceedAfterWeakEvent, int mobility, int pathfindingSSLevel, int xTarget, int yTarget, BOOL useOldSearch, int toggleEventsAroundMonsters);
int CheckDoMain(int a1, int a2);
void searchArray_underline_searchArray(searchArray *sa);
BOOL advManager_FindAdjacentMonster(advManager* advM, int xPoint, int yPoint, int* xMonster, int* yMonster, int xUnwanted, int yUnwanted);
char StopOnTrigger(mapCell* cell);
int GiveArtifact(hero* hero_1, int a2, int a3, char scrollSpell);
void town_GiveSpells(town* town_1, hero* captain);
BOOL armyGroup_Add(armyGroup* army_1, int creatureType, short quantity, int stackIdx);
bool  armyGroup_CanJoin(armyGroup* armyGroup_1, int creatureType);
bool OnMySide(int a);
int town_HasGarrison(town* town_1);
int game_ExperienceValueOfStack(armyGroup* armyGroup_1, hero* hero_1);
void advManager_TransferArtifacts(hero* heroSource, hero* heroDest);
int advManager_ValidMoveWithEvent(advManager* gpAdvManager, hero* hero_1, int i);
int Random(int a, int b);
void game_CheckHeroConsistency(game* gp_1);
int game_GetBoatsBuilt(game* gp_1);
signed int game_CreateBoat(game* gp_1, unsigned int x, unsigned int y, int doSend);
bool CanBuild(town* castle, int buildingCode);
int GetBuildingBaseResourceValue(int faction, int building, int buildingMagicGuildCode);
int playerData_BuildingsOwned(playerData* plData, int faction, int building, int magicGuildLevel);
void GetBuildingCost(int faction, int building, SBuildingCost* cost, int currentMagicGuildLevel);
int advManager_GiveExperience(hero* hero_1, int addedExperience, int a);
int hero_ApplyBattleWinTemps(hero* hero_1);
int hero_ApplyBattleLossTemps(hero* hero_1);
void hero_CheckLevel(hero* hero_1);
char hero_GetSSLevel(hero* hero_1, int secondary_skill);
void game_ClaimTown(game* game_1, int castleIdx, int playerIdx, int processMapChange);
int advManager_TeleportTo(advManager* am, hero* hero_1, int x, int y, int a5, int a6);
void hero_UseSpell(hero* hero_1, int spell);
int playerData_HasMobileHero(playerData* pd);
void PollSound();
void InitAIMapVars();
void ShowStatus();
int ValidateHero(hero* hero_1);
int MapExtraPosAndAdjacentsSet(int x, int y, char giCurWatchPlayerBitCopy);
void advManager_SetHeroContext(advManager* am, int heroIdx, int a3);
int game_GetTownId(game* gp, int x, int y);
void ResetHeroRVs(int a1, int x, int y);
playerData* advManager_DeactivateCurrHero(advManager* am);
int advManager_ProcessSearch(advManager* am, int x, int y);
int searchArray_BuildPath(searchArray* sa, int startX, int startY, int targetX, int targetY, int remainingMobility);
void advManager_UpdateScreen(advManager* am, int a2, int a3);
void advManager_DoAIEvent(advManager* advM, mapCell* cell, hero* hero_1, int x, int y);
void mouseManager_HideColorPointer(mouseManager* mm);
mapCell* advManager_MoveHero(advManager* am, int direction, int stop1, int* trigX, int* trigY, int* stop2, int arg14, int* hasAdjMonster, int a9);
bool advManager_GetMoveShowIt(hero* hero_1, int direction);
void mouseManager_ShowColorPointer(mouseManager* mm);
void advManager_UpdateRadar(advManager* am, int a2, int a3);
void CloseAIMapVars();

int philAI_FightValueOfStack(armyGroup* armyGroup_1, hero* hero_1, int isEstimationOnly, int isSiegeDefender, int castleIdx, int isSiegeAttacker)
{
  int overallFightValue = 0;
  int spellsFightValue;
  int turretsFightValue;
  // ��� 3 ����. - ��� �������
  float shooterValueCoef = 0.89999998; 
  float flyerValueCoef = 1.1;
  float nonflyerValueCoef = 0.75; // ������������ ��� ���� �� �������� � �� �������, � ��� ��� ������� ������������� ?
  town* townBattled;

  if(isSiegeAttacker)
  {
    // ������ SPELL_EARTHQUAKE - ����� �������� ������� ������� ���� ���� �� �� 1 ����������
    if(hero_HasArtifact(hero_1, ARTIFACT_BALLISTA_OF_QUICKNESS) || hero_HasSpell(hero_1, SPELL_EARTHQUAKE)
		|| hero_1->secondarySkillLevel[SECONDARY_SKILL_BALLISTICS])
    {
      flyerValueCoef = 1.05;
      nonflyerValueCoef = 0.94999999;
	  // ����� �������� shooterValueCoef = 0.95
    }
	// ���� � ���� SS Archery �� ������� ����� ��������, �� ��������� �� �������
    if(hero_1->secondarySkillLevel[SECONDARY_SKILL_ARCHERY] || hero_HasArtifact(hero_1, ARTIFACT_GOLDEN_BOW))
      shooterValueCoef = 1.05;
  }

  if(isSiegeDefender)
  {
    townBattled = &gpGame->castles[castleIdx];
    if(!(gpGame->castles[castleIdx].buildingsBuiltFlags & BUILDING_CASTLE_BUILT))
      isSiegeDefender = 0;
  }

  int fightValue;
  float quantityDependentCoef;

  for(int i = 0; i < 5; i++)
  {
    if(armyGroup_1->creatureTypes[i] != -1)
    {
      fightValue = armyGroup_1->quantities[i] * gMonsterDatabase[armyGroup_1->creatureTypes[i]].fight_value;
      if(isEstimationOnly)
      {
		if ( armyGroup_1->quantities[i] <= 500 )
		{
		  if ( armyGroup_1->quantities[i] <= 300 )
		  {
			if ( armyGroup_1->quantities[i] <= 180 )
			{
			  if ( armyGroup_1->quantities[i] <= 140 )
			  {
				if ( armyGroup_1->quantities[i] <= 100 )
				{
				  if ( armyGroup_1->quantities[i] <= 75 )
				  {
					if ( armyGroup_1->quantities[i] <= 50 )
					{
					  if ( armyGroup_1->quantities[i] <= 35 )
					  {
						if ( armyGroup_1->quantities[i] <= 23 )
						{
						  if ( armyGroup_1->quantities[i] <= 16 )
						  {
							if ( armyGroup_1->quantities[i] <= 11 )
							{
							  if ( armyGroup_1->quantities[i] <= 8 )
							  {
								if ( armyGroup_1->quantities[i] <= 5 )
								{
								  if ( armyGroup_1->quantities[i] <= 3 )
								  {
									if ( armyGroup_1->quantities[i] <= 2 )
									{
									  if ( armyGroup_1->quantities[i] <= 2 )
										quantityDependentCoef = -0.57999998;
									  else
										quantityDependentCoef = -0.40000001;
									}
									else
									{
									  quantityDependentCoef = -0.30000001;
									}
								  }
								  else
								  {
									quantityDependentCoef = -0.1;
								  }
								}
								else
								{
								  quantityDependentCoef = 0.0;
								}
							  }
							  else
							  {
								quantityDependentCoef = 0.20999999;
							  }
							}
							else
							{
							  quantityDependentCoef = 0.31999999;
							}
						  }
						  else
						  {
							quantityDependentCoef = 0.5;
						  }
						}
						else
						{
						  quantityDependentCoef = 0.75;
						}
					  }
					  else
					  {
						quantityDependentCoef = 1.0;
					  }
					}
					else
					{
					  quantityDependentCoef = 1.4;
					}
				  }
				  else
				  {
					quantityDependentCoef = 1.63;
				  }
				}
				else
				{
				  quantityDependentCoef = 2.0999999;
				}
			  }
			  else
			  {
				quantityDependentCoef = 2.4200001;
			  }
			}
			else
			{
			  quantityDependentCoef = 3.0799999;
			}
		  }
		  else
		  {
			quantityDependentCoef = 3.9000001;
		  }
		}
		else
		{
		  quantityDependentCoef = 4.4000001;
		}
		// ������
        if ( gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & SHOOTER
          || armyGroup_1->creatureTypes[i] == CREATURE_VAMPIRE
          || armyGroup_1->creatureTypes[i] == CREATURE_VAMPIRE_LORD
          || armyGroup_1->creatureTypes[i] == CREATURE_SPRITE
          || armyGroup_1->creatureTypes[i] == CREATURE_ROGUE
          || armyGroup_1->creatureTypes[i] == CREATURE_HYDRA
          || armyGroup_1->creatureTypes[i] == CREATURE_TROLL )
        {
          quantityDependentCoef = quantityDependentCoef * 0.7;
        }
		// ������
        else if(armyGroup_1->creatureTypes[i] == CREATURE_WOLF)
        {
          quantityDependentCoef = quantityDependentCoef * 0.85;
        }
		// ������
        else if(armyGroup_1->creatureTypes[i] == CREATURE_GRIFFIN || armyGroup_1->creatureTypes[i] == CREATURE_GHOST)
        {
          quantityDependentCoef = quantityDependentCoef * 1.2;
        }
        fightValue = (quantityDependentCoef + 1.0) * fightValue;
        if(isSiegeDefender)
        {
          if(gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & SHOOTER)
            fightValue = fightValue * 1.18;
		  // ����� ����� 0.9
          if(gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & FLYER)
            fightValue = fightValue * 0.95;
        }

        if(gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & SHOOTER 
			&& hero_1 && hero_1->secondarySkillLevel[SECONDARY_SKILL_ARCHERY])
          fightValue = fightValue * gfSSAIArcheryMod[hero_1->secondarySkillLevel[SECONDARY_SKILL_ARCHERY]];
        if(isSiegeAttacker)
        {
          if(gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & SHOOTER)
            fightValue = fightValue * shooterValueCoef;
		  // �������� else (����� ������� �� �������� ��� ��������� ��� nonflyer ����)
          if(gMonsterDatabase[armyGroup_1->creatureTypes[i]].creature_flags & FLYER)
            fightValue = fightValue * flyerValueCoef;
          else
            fightValue = fightValue * nonflyerValueCoef;
        }
	  }
	  overallFightValue += fightValue;
	}
  }

  if(isSiegeDefender)
  {
    int numArchersTurrets = 0;
	int numArchers;
	int attack;
    town_CalcNumLevelArchers(townBattled, &numArchers, &attack);
    if (townBattled->buildingsBuiltFlags & BUILDING_LEFT_TURRET)
      numArchersTurrets += numArchers / 2;
    if (townBattled->buildingsBuiltFlags & BUILDING_RIGHT_TURRET)
      numArchersTurrets += numArchers / 2;
    numArchers += numArchersTurrets;
    turretsFightValue = (attack * 0.1 + 1.0) * 400 * numArchers;
  }

  town* occupiedTown;
  if(isEstimationOnly && hero_1)
  {
    int heroAttack = hero_Stats(hero_1, PRIMARY_SKILL_ATTACK);
    int heroStatsIndex = hero_Stats(hero_1, PRIMARY_SKILL_DEFENSE) + heroAttack + 20;
    if (heroStatsIndex < 0 )
      heroStatsIndex = 0;
    if ( heroStatsIndex > 40 )
      heroStatsIndex = 40;
    overallFightValue = overallFightValue * gfStatPower[heroStatsIndex];
	// ������, ������ - ������������� ����� �� ������� �� ������ �����
	// � ��. ������� - ��� ������ ������, ��� ������ ����������� ��������,
	// ������, ��� ������ ��������� ������� �����. ��� ��� ����� �������� ��� ����
    turretsFightValue = turretsFightValue * gfStatPower[heroStatsIndex];
    occupiedTown = hero_GetOccupiedTown(hero_1);
    int morale = armyGroup_GetMorale(&hero_1->army, hero_1, occupiedTown, 0);
    if(morale <= 0)
    {
      if( morale < 0)
	  // ��������, ������� 24 �� 16
        overallFightValue = overallFightValue * (morale + 24) / 24;
    }
    else
    {
	  // ��������, ������� 48 �� 32
      overallFightValue = overallFightValue * (morale + 48) / 48;
    }
	// �������, ��� ����� ���� ������ ��������� ������ ������ hero_GetOccupiedTown
    if(isSiegeDefender)
      occupiedTown = townBattled;
    else
      occupiedTown = 0;
    int luck = game_GetLuck(hero_1, 0, occupiedTown);
    if(luck)
	// ������� 16 �� 32
      overallFightValue = overallFightValue * (luck + 16) / 16;

    if(hero_1->spellpoints >= 3)
    {
      int nSpells = 0;
	  float aiDurationMod;
	  float aiSpellPowerMod;
      if ( hero_Stats(hero_1, PRIMARY_SKILL_SPELLPOWER) > 10 )
      {
        aiDurationMod = maxAIDurationMod;
        aiSpellPowerMod = maxAISpellPowerMod;
      }
      else
      {
        aiDurationMod = gfPhilAIDurationMod[hero_Stats(hero_1, PRIMARY_SKILL_SPELLPOWER)];
        aiSpellPowerMod = gfPhilAISpellPowerMod[hero_Stats(hero_1, PRIMARY_SKILL_SPELLPOWER)];
      }
	  int spellStrength;
	  int spellEffectivnessArray[46]; // ��� - ������ ���� 47 (��� Earthquake)
	  int nSpellCharges;
	  int spellEffectivness;
      for(int spell = 0; spell < 46; spell++)
      {
        if(hero_HasSpell(hero_1, spell))
        {
          spellStrength = gsSpellInfo[spell].appearingChance;
          if(gsSpellInfo[spell].attributes & ATTR_DURATIONED_SPELL)
          {
            spellStrength = spellStrength * aiDurationMod;
          }
          else if(gsSpellInfo[spell].attributes & ATTR_COMMON_SPELL)
          {
            spellStrength = spellStrength * aiSpellPowerMod;
          }
          nSpellCharges = hero_1->spellpoints / GetManaCost(spell, hero_1);
          if(nSpellCharges > 10)
            nSpellCharges = 10;
		  // �� ����� ���� ����� 2 ������ gfSpellCastNumMod ��� Durationed spells
		  // (��� �����, ���� ��� ��������) � ��� ������� spells
          spellEffectivness = spellStrength * gfSpellCastNumMod[nSpellCharges];
          if(spellEffectivness <= 0 )
            spellEffectivness = 1;
          spellEffectivnessArray[nSpells++] = spellEffectivness;
        }
      }

	  int bestSpellsIndex;
	  int bestSpellsEffectivness;
      for(int bestSpells = 0; bestSpells < 7 && bestSpells < nSpells; bestSpells++)
      {
        bestSpellsEffectivness = 0;
        for(int i = 0; i < nSpells; i++)
        {
          if(spellEffectivnessArray[i] > bestSpellsEffectivness)
          {
            bestSpellsEffectivness = spellEffectivnessArray[i];
            bestSpellsIndex = i;
          }
        }
		// ��������� �������. ������� ����� ���������� (��� ����� ������) ���������
		// �������������, �� ��� ������ � ������ ����� ����������� (����. 7)
        spellsFightValue += bestSpellsEffectivness * gfSpellTypeNumMod[bestSpells];
        spellEffectivnessArray[bestSpellsIndex] = 0;
      }
	}
  }

  // ������������ ��� spellsFightValue � turretsFightValue - ���� ������ ����� ������ ���� -
  // � ���� ������ �� �����, �� ������. ����� �� �������
  if(2 * overallFightValue >= spellsFightValue)
  {
    if(spellsFightValue <= overallFightValue * 1.5)
    {
      if(overallFightValue < spellsFightValue)
        spellsFightValue = overallFightValue * 0.75;
    }
    else
    {
      spellsFightValue = overallFightValue;
    }
  }
  else
  {
    spellsFightValue = overallFightValue * 1.25;
  }
  if(2 * overallFightValue >= turretsFightValue)
  {
    if(turretsFightValue <= overallFightValue * 1.5)
    {
      if(overallFightValue < turretsFightValue)
        turretsFightValue = overallFightValue * 0.9;
    }
    else
    {
      turretsFightValue = overallFightValue * 1.25;
    }
  }
  else
  {
    turretsFightValue = overallFightValue * 1.5;
  }

  overallFightValue += spellsFightValue;
  overallFightValue += turretsFightValue;
  return overallFightValue;

}

int philAI_SetupRelativeHeroStrengths()
{
  int alphaArmyValue = -1;
  int heroArmyValue;
  iAlphaMale = -1;
  hero* hero_1;

  for(int i = 0; i < gpCurPlayer->numHeroes; i++)
  {
    hero_1 = (hero*)&gpGame->heroes[gpCurPlayer->heroesOwned[i]];
    heroArmyValue = philAI_FightValueOfStack(&gpGame->heroes[gpCurPlayer->heroesOwned[i]].army, hero_1, 1, 0, -1, 0);
    if(heroArmyValue > alphaArmyValue)
    {
      alphaArmyValue = heroArmyValue;
      iAlphaMale = hero_1->idx;
    }
  }
  return gpCurPlayer->numHeroes;
}

int philAI_ManaRefreshValue(hero* hero_1, int a2)
{

	return 1;
}

int philAI_DamageGroup(armyGroup* armyDamaged, hero* heroDamaged, hero* heroOpposite, float casualties)
{
	// ����� ������ ���� ���

	return 1;
}

int philAI_MeanRVOfUnexploredTerritory(int playerIndex)
{

	return 0;
}

float philAI_TurnValueOfObelisk(int playerIdx)
{

  bool isAi = true;
  int nPieces;
  float result;
  int ultimateArtifactValue = gArtifactBaseRV[gpGame->ultimateArtifactIdx];
  if(gpGame->mapHeader.winConditionType == WIN_CONDITION_FIND_ARTIFACT)
    ultimateArtifactValue *= 2;
  if(gpGame->ultimateArtifactIdx == -1 )
  {
    result = 0.0;
  }
  else
  {
    gpGame->players[playerIdx].aiObeliskValue = 48 * (ultimateArtifactValue / 110) / gpGame->numObelisks; // 110 �������� ��������
    if(gpCurPlayer->personality == AI_EXPLORER)
      gpGame->players[playerIdx].aiObeliskValue *= 1.4;
    nPieces = game_SetupPuzzlePieces(gpGame, giCurPlayer, isAi);
	// ���� ����� �������� ��������, �� aiObeliskValue ������
	// � ���� ����� ����������� ���� nPieces ������ 48, �� �� 48
    gpGame->players[playerIdx].aiObeliskValue *= (1.5 - abs(48 - nPieces) / 48.0);
	// �� ������ ��������� ����, ������ ������
    gpGame->players[playerIdx].aiObeliskValue = (gpGame->players[playerIdx].aiTurnAttentionValueHeroes + 0.66) * gpGame->players[playerIdx].aiObeliskValue;
    result = gpGame->players[playerIdx].aiObeliskValue;
  }
  return result;
}

void philAI_BuildBuilding(town* a1, int a2)
{

}

bool philAI_CanBuyBHC(int* bhcResults)
{
  int bhcType = bhcResults[1];
  int cost[7];

  if(bhcType == BHC_BUILDING)
  {
    if(CanBuy((town*)bhcResults[0], bhcResults[2]))
      return true;
    return false;
  }

  if(bhcType == BHC_HERO)
  {
    if(gpCurPlayer->resources[RESOURCE_GOLD] >= gHeroGoldCost && ((town*)bhcResults[0])->visitingHeroIdx == -1 && !bHeroBuiltThisTurn)
      return true;
    return false;
  }

  if(bhcType != BHC_CREATURE)
    return 0;
  if(((town*)bhcResults[0])->numCreaturesInDwelling[bhcResults[2]] >= bhcResults[3])
  {
    GetMonsterCost(gDwellingType[12 * ((town*)bhcResults[0])->factionID + bhcResults[2]], cost);
    for(int i = 0; i < 7; i++)
    {
      if(bhcResults[3] * cost[i] > gpCurPlayer->resources[i])
        return false;
    }
    return true;
  }
  else
    return false;

}

void philAI_BuildHero(void* philAI_1, town* a1, int a2)
{

}

void philAI_BuildCreature(town* town_1, int a2, int a3)
{

}

int philAI_ValueOfEventAtPosition(void* phil_AI, int x, int y, int typeOfEstimation, int* a3)
{
  int result;
  // ������ ���������� ������ ��� ������ (����������������) ������ ���� ��� �������������� ������ ���
  // ��� �����, ��� ������� ��� �� �������� ���������. ������
  if(typeOfEstimation || gaiHeroEventStratRVOfPos[ x + y * MAP_WIDTH] == -32001)
  {

  }
  else
  {
    result = gaiHeroEventStratRVOfPos[x + y * MAP_WIDTH];
  }
  return result;
}

int philAI_StrategicValueOfPosition(void* philAI_1, int heroX, int heroY, BOOL a4, BOOL argC, int *liveChance, int remainingMobility)
{
  // -32001 �������� ��� ������, ��� ������� ��� �� ���� �������
  // �������, ��� ������ �������� short ����� -32768
  if(!remainingMobility && !a4 && gaiHeroStrategicRVOfPos[heroX + MAP_WIDTH * heroY] != -32001)
  {
    *liveChance = gaiLiveChanceOfPos[heroX + MAP_WIDTH * heroY];
    return gaiHeroStrategicRVOfPos[heroX + MAP_WIDTH * heroY];
  }

  int valueSum = 0;
  bool shouldMakeNewSearchArray = 0;
  bool isMyCastle = false;
  mapCell* cell = advManager_GetCell(gpAdvManager, heroX, heroY);
  if(cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT)
    && gpGame->castles[cell->extraInfo].ownerIdx == giCurPlayer
    && gpGame->castles[cell->extraInfo].buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
    isMyCastle = true;
  *liveChance = 100;
  if(argC && !gaiEnemyHeroReachable[heroX + MAP_WIDTH * heroY])
  {
    if(a4)
      return 0;
    argC = 0;
  }
  searchArray* v12;
  searchArray* searchArray_1;
  if(bSVSearchArrayInUse)
  {
    shouldMakeNewSearchArray = 1;
    v12 = new searchArray();
    if(v12)
      searchArray_1 = searchArray_searchArray(v12);
    else
      searchArray_1 = 0;
    //if ( !this )
    //  MemError();
    searchArray_Init(searchArray_1);
  }
  else // ���� SVSearchArray �� �����, �� ���������� ���
  {
    bSVSearchArrayInUse = 1;
    searchArray_1 = &SVSearchArray;
  }
  bool isHeroAtSea = gpCurAIHero->flags & HERO_AT_SEA;
  // ���������, ��� ��� �� ������ ��� ������� 28
  // ��� ��������� !
  if(isHeroAtSea && advManager_GetCell(gpAdvManager, heroX, heroY)->objType == LOCATION_SHORE)
    isHeroAtSea = 0;
  // ��� ����� ��������
  int searchDistance;
  if(a4 || argC)
    searchDistance = 1700;
  else
    searchDistance = 700;
  searchArray_SeedPosition(searchArray_1, heroX, heroY, 2, searchDistance, isHeroAtSea, 0, 59999,
	  gpCurAIHero->secondarySkillLevel[SECONDARY_SKILL_PATHFINDING], -1, -1, 0, 0);
  pointInfo* pfInfo = &searchArray_1->pointMap[heroX + MAP_WIDTH * heroY];
  pfInfo->field_4 &= 0xFEu; // (���������� ����� ������� ��� - ��� �����, �� ������� ����� �����. ��� ������, ��� ��� ����� "�����������")

  float value;
  int enemyMobility;
  float enemyHeroChance;
  int penaltyCloseFriendlyHero;

  for(int col = 0; col < MAP_WIDTH; col++)
  {
    for(int row = 0; row < MAP_HEIGHT; row++)
    {
      if(searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].field_4 & 1) // ��������� ������� ��� - ��������� �� �����
      {
        cell = advManager_GetCell(gpAdvManager, col, row);
        if(!a4
          && cell->objType & TILE_HAS_EVENT

		  // ���������� �� ���. ����� - ����� �� ����� ������ �����������, ������� ����� �����������������

		  // �� ���� �� ������� ������� � ������� 700 �� ������ �����, ���������
		  // �������� � �������� �������������� ���������� ������ �����
          && searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint <= 700
		  // ��� ������ �������� ���������� �� ����������. ��������, ����� � ��� ������� ������� ?
          || argC && cell->objType == (LOCATION_HERO | TILE_HAS_EVENT))
        {
          CheckDoMain(0, 0);
		  // ��� ������ ���������� �� ����, ��� ������ value
		  // � iDummy ������ ������������ ����������� ������. ������, ������ ��� �� ����������� ?
          value = 25 * philAI_ValueOfEventAtPosition(philAI_1, col, row, 0, &iDummy)
                       / (float)(searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint + 50.0);
          if(!isMyCastle || cell->objType != LOCATION_HERO || value >= 0)
            valueSum += value;
        }
		// ������ ����� ��������� ��������, ��������� ����. ����� ���������
        if(cell->objType == (LOCATION_HERO | TILE_HAS_EVENT))
        {
		  // ������, cell->extraInfo �������� ����� �����
          if(gaiHeroLiveChance[cell->extraInfo] == -32001)
		    // ������ �� �������� ���� � gaiHeroLiveChance - ��� ������ �����
            philAI_ValueOfEventAtPosition(philAI_1, col, row, 0, &iDummy);
          if(gaiHeroLiveChance[cell->extraInfo] != -32001
            && gaiHeroLiveChance[cell->extraInfo] < 100
            && !isMyCastle)
          {
            enemyMobility = gpGame->heroes[cell->extraInfo].mobility;
            if(gbHumanPlayer[gpGame->heroOwner[cell->extraInfo]])
            {
              if(remainingMobility + searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint > enemyMobility)
              {
                enemyHeroChance = (100 - gaiHeroLiveChance[cell->extraInfo]) * 0.2;
              }
              else if (remainingMobility + searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint > 500)
              {
                enemyHeroChance = (100 - gaiHeroLiveChance[cell->extraInfo]) *
					(enemyMobility - (remainingMobility + searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint) + 250)
                    / enemyMobility;
              }
			  // ���� �� ����� ������ ��������, �� ����� �������
              else
              {
                enemyHeroChance = 100 - gaiHeroLiveChance[cell->extraInfo];
              }
		    }
			// ������ ������ �� �� ������� - � ����, ������ ��� ��� �� ������� ?
            else
            {
              enemyHeroChance = (100 - gaiHeroLiveChance[cell->extraInfo])
                  * (enemyMobility + 500 - (remainingMobility + searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint))
                  / (enemyMobility + 500);
            }
			// ������ ��� liveChance ������ �����
            *liveChance = *liveChance * (100 - enemyHeroChance) / 100;
		  }
		}
        if(gpCurAIHero->idx != iAlphaMale && (heroX != col || heroY != row))
        {
		  // ���� �� ������� ������ �� �������������� ����� � ��� ����� - �� �������, ��...
		  // �������� �������� - ������, �� ����� ��������� ������
          if(searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint < 1024
            && advManager_GetCell(gpAdvManager, col, row)->objType == (LOCATION_HERO | TILE_HAS_EVENT)
            && advManager_GetCell(gpAdvManager, col, row)->extraInfo != gpCurAIHero->idx
            && gpGame->heroOwner[advManager_GetCell(gpAdvManager, col, row)->extraInfo] == gpCurAIHero->ownerIdx)
          {
            penaltyCloseFriendlyHero = 600 * (1024 - searchArray_1->pointMap[heroX + MAP_WIDTH * heroY].distanceFromSourcePoint) / 1024;
            if(penaltyCloseFriendlyHero > 0)
              valueSum -= penaltyCloseFriendlyHero;
		  }
		}
	  }
	}
  }
  // ������, ������ Terrain ����� ��������� groundIndex
  int terrain_1 = giGroundToTerrain[advManager_GetCell(gpAdvManager, heroX, heroY)->groundIndex];
  int delta, deltaY;
  int groundIndex;
  for(int i = 0; i < gpCurPlayer->numHeroes; i++)
  {
    if(gpCurPlayer->heroesOwned[i] != gpCurAIHero->idx)
    {
      deltaY = abs(gpGame->heroes[gpCurPlayer->heroesOwned[i]].oldTargetY - heroY);
      delta = abs(gpGame->heroes[gpCurPlayer->heroesOwned[i]].oldTargetX - heroX) + deltaY;
	  // ���� �� ������ ������� ������ � ������ ��� ��� ��� ��������
      if(delta < 9)
      {
        groundIndex = advManager_GetCell(
                gpAdvManager,
                gpGame->heroes[gpCurPlayer->heroesOwned[i]].oldTargetX,
                gpGame->heroes[gpCurPlayer->heroesOwned[i]].oldTargetY)->groundIndex;
        if(terrain_1 || giGroundToTerrain[groundIndex] <= 0)
        {
          if(terrain_1 <= 0 || giGroundToTerrain[groundIndex])
            valueSum -= 600 * (9 - delta) / 9;
        }
      }
    }
  }
  if(shouldMakeNewSearchArray)
  {
    if(searchArray_1)
    {
      searchArray_underline_searchArray(searchArray_1);
      free(searchArray_1);
    }
  }
  else
  {
    // ����� ������������ ������ - "��������"
    bSVSearchArrayInUse = 0;
  }

  // ��� ���� �� ��������� �������� ������� ����������� �����
  // ... � ����������� �� ������� (+ � -)
  // �����, ��������, ����������, � ��� 2500 - ��� ����, �������
  // ����� �� ������ ��������������
  // �� � ��������� � 700 ������ ��������
  // ��, ������, � ���� ��������� ������ ��������� ?
  // � *liveChance ������ ���� - ��� ��� ??
  if(*liveChance < 100)
    valueSum -= 2500 * (100 - *liveChance) / 100;
  valueSum = valueSum * 1.25;
  if(valueSum > 32000)
    valueSum = 32000;
  if (!a4 && !remainingMobility)
  {
    gaiHeroStrategicRVOfPos[heroX + MAP_WIDTH * heroY] = valueSum;
    gaiLiveChanceOfPos[heroX + MAP_WIDTH * heroY] = *liveChance;
  }
  return valueSum;

}

// a10 - ��� �� �������� ? �� ����� ��� philAI_ValueOfEventAtPosition
//2 - ��� ������ ������� ��� Dimension Door. ����� 2 � ��������� philAI_DetermineTargetPosition
//������, ��� philAI::RVOfPosition ����� ������ ���������� 2.
//������ ������ ��� ����� ���������� � philAI_ValueOfEventAtPosition. ��� ��� ���������� �����������,
//��� ��� ������������ ��� � ����� ����� ��������� ��������.

//��� ������ philAI_ValueOfEventAtPosition �� philAI_StrategicValueOfPosition ���������� 0.
//����� ������� ��� ���������� ������. ��� ������ �� philAI_GoodAdjacent ���������� 2.
//��� ������ �� philAI_RVOfPosition ���������� 1 (����� 1 ������, ����� ���������� 2 - ������ ��� ������� ������).
// ��� ���� ��� ��� ������, ��� � ��� �������� ���� �������� �� ����� ������. ����� ����� ������ ��� ������
// ������� � ������

//�������� ����� ������� ���� �������� isNotStrategicEstimation
//0 == Strategic_Estimation
//1 == RV_Estimation
//2 == Usual
//����� ���� �������� ���������� � philAI_EvaluateTownEvent � philAI_EvaluateHeroEvent

// � Strategic_Estimation value ������� �� ������ ��������� ������� ������ ����������
// � � RV_Estimation ������ ������ �����. ������


int philAI_RVOfPosition(void* phil_AI, int x, int y, int arg8, int x_2, int y_2, int a7, int x_3, int y_3, int typeOfEstimation, int remainingMobility)
{
  int strategicValue = 0;
  int v18 = 100;
  int liveChance_3 = 100;
  int objectType = advManager_GetCell(gpAdvManager, x, y)->objType;
  int objectTypeExact = objectType & 0x7F;
  int liveChance_4 = 100;
  int liveChance_2 = 100;
  int liveChanceMonPos = 100;
  int currentLiveChance;
  int pointLiveChance;
  int currentValue;
  int pointValue;
  int profitValue;
  int monsterX, monsterY;
  mapCell* cell;
  float nMoves;

  // ���� ��������������� ����� �� ��������� � ������������ �����
  if(abs(x - gpCurAIHero->x) > 1 || abs(y - gpCurAIHero->y) > 1)
  {
    currentValue = philAI_StrategicValueOfPosition(phil_AI, gpCurAIHero->x, gpCurAIHero->y, 0, 1, &currentLiveChance, 0);
    pointValue = philAI_StrategicValueOfPosition(phil_AI, x, y, 0, 1, &pointLiveChance, remainingMobility);
    profitValue = pointValue - currentValue;
  }
  else
  {
    currentValue = 0;
    profitValue = 0;
  }
  // ���� ��� ����� �����������
  if(objectTypeExact == LOCATION_BOAT && profitValue < 0)
    profitValue = 0;
  int valueSum = 0;
  int value;
  if(arg8)
  {
    value = philAI_ValueOfEventAtPosition(phil_AI, x_2, y_2, RV_ESTIMATION, &liveChance_2);
    valueSum += value;
  }

  if(a7)
  {
    strategicValue = philAI_StrategicValueOfPosition(phil_AI, x_3, y_3, 1, 1, &liveChance_3, 0);
    if(strategicValue < 0)
      valueSum += strategicValue;
  }

  int valueEvent;
  if(advManager_FindAdjacentMonster(gpAdvManager, x, y, &monsterX, &monsterY, -1, -1))
  {
    cell = advManager_GetCell(gpAdvManager, x, y);
    if(StopOnTrigger(cell))
    {
      valueEvent = philAI_ValueOfEventAtPosition(phil_AI, monsterX, monsterY, RV_ESTIMATION, &liveChanceMonPos);
      if(valueEvent < 0)
        valueSum += valueEvent;
      if(liveChanceMonPos == 100)
        liveChance_2 = liveChanceMonPos;
      else
        liveChance_2 = liveChanceMonPos * liveChance_2 / 100;
    }
  }

  if(objectType & TILE_HAS_EVENT || gpCurPlayer->aiProbableUltimateArtifactX == x && gpCurPlayer->aiProbableUltimateArtifactY == y)
  // typeOfEstimation ����� ORDINARY_ESTIMATION - � philAI_RVOfPosition ������ ���������� typeOfEstimation ������ 2
    valueEvent = philAI_ValueOfEventAtPosition(phil_AI, x, y, typeOfEstimation, &liveChance_4);
  else
    valueEvent = 0;
  if(liveChance_4 < 100)
    profitValue = liveChance_4 * profitValue / 100;

  if(liveChance_4 >= 30)
  {
    if(liveChance_4 < 100)
    {
      valueEvent = valueEvent * liveChance_4 / 100;
      profitValue = liveChance_4 * profitValue / 100;
    }
    if(liveChance_3 >= 30)
    {
      if(liveChance_3 < 100)
      {
        valueEvent = valueEvent * liveChance_3 / 100;
        profitValue = liveChance_3 * profitValue / 100;
      }
      if(liveChance_2 >= 100)
      {
        valueSum += valueEvent;
      }
      else if (valueSum <= 0)
      {
        valueSum += liveChance_2 * (valueEvent + profitValue) / 100;
      }
      else
      {
        valueSum = liveChance_2 * (valueEvent + valueSum + profitValue) / 100;
      }

      nMoves = gpSearchArray->pointMap[x + MAP_WIDTH * y].distanceFromSourcePoint
          / (float)gpCurAIHero->mobility;
	  // ������
      if(gpCurAIHero->flags & HERO_AT_SEA)
      {
        nMoves = nMoves * 0.5 + 0.5;
      }
      else if (nMoves <= 5.0)
      {
        if(nMoves <= 4.0 )
        {
          if(nMoves <= 3.0 )
          {
            if(nMoves <= 2.0 )
            {
              if(nMoves <= 1.5 )
              {
                if(nMoves > 1.0 )
                  nMoves = nMoves * 1.2;
              }
              else
              {
                nMoves = nMoves * 1.4;
              }
            }
            else
            {
              nMoves = nMoves * 1.7;
            }
          }
          else
          {
            nMoves = nMoves * 2.0;
          }
        }
        else
        {
          nMoves = nMoves * 2.5;
        }
      }
      else
      {
        nMoves = nMoves * 3.0;
      }

      valueSum = valueSum / (nMoves + 0.2);
      profitValue = 2 * profitValue / (nMoves + 1.0);

      if(liveChance_2 == 100)
        valueSum += profitValue;
      if(gpCurAIHero->flags & HERO_AT_SEA && objectType == LOCATION_SHORE)
        valueSum += 40;
	}
	else
	{
      valueSum = -100;
	}
  }
  else
  {
    valueSum = -100;
  }

  return valueSum;
}

void philAI_ProbableOutcomeOfBattle(armyGroup* armyGroupA, hero* heroA,
	armyGroup* armyGroupD, hero* heroD, armyGroup* armyGroupGarrisonIfUnitedWithHero,
	int isSiegeBattle, int castleIndex, int ownerD, float* probWinnerA,
	int* probableApproxCasualtiesA, int* probableApproxCasualtiesD,
	int* probablePreciseCasualtiesA, int* probablePreciseCasualtiesD,
	int* adjustedProfitA)
{
  int attackerHeroValue = 0;
  int defenderHeroValue = 0;

  float strengthA = (float)philAI_FightValueOfStack(armyGroupA, heroA, 1, 0, 0, isSiegeBattle);
  float strengthD = (float)philAI_FightValueOfStack(armyGroupD, heroD, 1, isSiegeBattle, castleIndex, 0);

  if(armyGroupGarrisonIfUnitedWithHero)
    strengthD += (float)philAI_FightValueOfStack(armyGroupGarrisonIfUnitedWithHero, 0, 1, 0, 0, 0);

  float simpleStrengthA = (float)philAI_FightValueOfStack(armyGroupA, heroA, 0, 0, 0, 0);
  float simpleStrengthD = (float)philAI_FightValueOfStack(armyGroupD, heroD, 0, 0, 0, 0);

  if(armyGroupGarrisonIfUnitedWithHero)
    simpleStrengthD += (float)philAI_FightValueOfStack(armyGroupGarrisonIfUnitedWithHero, 0, 0, 0, 0, 0);

  if(isSiegeBattle)
    simpleStrengthD = simpleStrengthD * 1.11;

  float adjustedStrengthA;
  float adjustedStrengthD = strengthD;

  if(ownerD == -1)
  {
    adjustedStrengthA = ((float)gpGame->difficulty * 0.15 + 0.7) * strengthA;
    if ( !gpCurPlayer->personality )
      adjustedStrengthA = adjustedStrengthA * 1.08;
  }
  else
  {
    adjustedStrengthA = strengthA;
    if(gbHumanPlayer[ownerD])
    {
      adjustedStrengthD = strengthD * 1.14;
    }
    else if(!gpCurPlayer->personality)
    {
      adjustedStrengthA = strengthA * 1.08;
    }
  }

  if(adjustedStrengthA < 1.0)
    adjustedStrengthA = 1.0;
  if(adjustedStrengthD < 1.0)
    adjustedStrengthD = 1.0;

  float mathPower;
  if(adjustedStrengthA > 1000000.0)
	  mathPower = 2.0;
  else
  {
    if(adjustedStrengthD > 1000000.0)
	  mathPower = 2.0;
	else
	  mathPower = 2.75;
  }
  adjustedStrengthA = pow((double)adjustedStrengthA, (double)mathPower);
  adjustedStrengthD = pow((double)adjustedStrengthD, (double)mathPower);

  *probWinnerA = adjustedStrengthA / (adjustedStrengthD + adjustedStrengthA);
  if(*probWinnerA >= 0.08 )
  {
    if(*probWinnerA >= 0.12 )
    {
      if(*probWinnerA >= 0.2 )
      {
        if(*probWinnerA >= 0.3 )
        {
          if(*probWinnerA < 0.4 )
            *probWinnerA -= 0.02;
        }
        else
        {
          *probWinnerA -= 0.04;
        }
      }
      else
      {
        *probWinnerA -= 0.05;
      }
    }
    else
    {
      *probWinnerA -= 0.07000000000000001;
    }
  }
  else
  {
    probWinnerA = 0;
  }

  *probableApproxCasualtiesA = (1.0 - *probWinnerA) * simpleStrengthA;
  *probableApproxCasualtiesD = *probWinnerA * simpleStrengthD;
  *probablePreciseCasualtiesA = (1.0 - *probWinnerA * *probWinnerA) * simpleStrengthA;
  *probablePreciseCasualtiesD = (1.0 - (1 - *probWinnerA)*(1 - *probWinnerA)) * simpleStrengthD;

  float attackerArmyValueCoef = 1.33 - *(float*)&gpCurPlayer->aiTurnAttentionValueCreatures;
  *adjustedProfitA = - *probablePreciseCasualtiesA * attackerArmyValueCoef * attackerArmyValueCoef;

  if(ownerD >= 0)
  {
    float defenderArmyValueCoef = *(float*)&gpCurPlayer->aiTurnAttentionValueCreatures + 0.66;
    if(gbHumanPlayer[ownerD])
      *adjustedProfitA += *probablePreciseCasualtiesD * defenderArmyValueCoef * defenderArmyValueCoef * gfAttackHumanBonus;
    else
      *adjustedProfitA += *probablePreciseCasualtiesD * defenderArmyValueCoef * defenderArmyValueCoef * gfAttackComputerBonus;
  }
  *adjustedProfitA = *adjustedProfitA * gpCurPlayer->aiIncomeToFightValueRatio;

  if(heroA)
  {
    for(int i=0; i < 14; i++)
    {
	  if(heroA->artifacts[i] >= 0)
      {
		// ��� - ���������� �� 37, � 103 - ������ ��� ���� �� ������ 1
	    // � �� ����������� (��� ��� ��� 37 ����������)
        if(heroA->artifacts[i] < 37)
          attackerHeroValue += gArtifactBaseRV[heroA->artifacts[i]];
      }
    }
	if(gpGame->mapHeader.winConditionType == 2 && heroA->idx == gpGame->mapHeader.winConditionArgumentOrLocX)
      attackerHeroValue += 50000;
    *adjustedProfitA = *adjustedProfitA - (1.0 - *probWinnerA) * (attackerHeroValue + 1400);
    *adjustedProfitA += game_ExperienceValueOfStack(armyGroupD, heroD)
		* heroA->aiParamFV * *probWinnerA * 0.8;
  }

  if(heroD)
  {
    for(int i=0; i < 14; i++)
    {
	  if(heroD->artifacts[i] >= 0)
      {
	    // ��� - ���������� �� 37, � 103
        if(heroD->artifacts[i] < 37)
          defenderHeroValue += gArtifactBaseRV[heroD->artifacts[i]];
      }
    }
	if(gpGame->mapHeader.winConditionType == 2 && heroD->idx == gpGame->mapHeader.winConditionArgumentOrLocX)
      defenderHeroValue += 50000;
	float attackBonus;
	if(gbHumanPlayer[heroD->ownerIdx])
      attackBonus = gfAttackHumanBonus;
    else
      attackBonus = gfAttackComputerBonus;
	*adjustedProfitA += (defenderHeroValue + 1250) * attackBonus * *probWinnerA;
  }

}

// ���������� ��������� � ���, ��� ������ ����������� ����� ��� �������� ������ � �����-������
// ��� ������� �������� ������������ ����� �� �����-����������
// !!! ������� ������ ���� ������� �������� "������" ���� �� �����-���������� �� ���-�� ������
// (��� ����� ���� � ����� �� ��������� ������, ��������� �����-��������� ������ �������� ���. fight_value)
// � ��� ����� ��������, ��� ����� ������ ������� �� �����-������
void philAI_RedistributeTroops(void* philAI_1, armyGroup* armyGroupSource, armyGroup* armyGroupDest,
	int isGivingTroopsFromHero, int isGivingTroopsToHero, float armyValueSource, float armyValueDest, int redistributedArmyValue)
{	
  int doCycle = true;
  gbTroopReload = 0;

  int armySourceQuantity;
  int joinCreatureSlotIndex;
  int maxTroopFightValue;
  int creatureExtremeSpeed;
  int joinedQuantity;

  while(doCycle)
  {
    if(isGivingTroopsFromHero)
    {
      armySourceQuantity = 0;
      for(int i = 0; i < 5; i++)
      {
        if(armyGroupSource->creatureTypes[i] != -1)
          armySourceQuantity += armyGroupSource->quantities[i];
      }
      if(armySourceQuantity <= 1 )
        break;
    }
    joinCreatureSlotIndex = -1;
    for(int j = 0; j < 5; j++)
    {
      if(joinCreatureSlotIndex == -1)
      {
        for(int k = 0; k < 5; k++)
        {
          if(armyGroupSource->creatureTypes[j] != -1 &&
			 armyGroupDest->creatureTypes[k] == armyGroupSource->creatureTypes[j])
          {
            joinCreatureSlotIndex = j;
            break;
          }
        }
      }
    }
    if(joinCreatureSlotIndex == -1)
    {
      maxTroopFightValue = -9999;
      if(isGivingTroopsToHero)
        creatureExtremeSpeed = 1;
      else
        creatureExtremeSpeed = 9;

	  // ���������� �� ��������� � ����� � �������� ����� �������, ���� �������� �����,
	  // � ����� ���������, ���� �������� ������
      for(int l = 0; l < 5; l++)
      {
        if(armyGroupSource->creatureTypes[l] != -1)
        {
		  if((isGivingTroopsToHero && gMonsterDatabase[armyGroupSource->creatureTypes[l]].speed > creatureExtremeSpeed)
		    || (!isGivingTroopsToHero && gMonsterDatabase[armyGroupSource->creatureTypes[l]].speed < creatureExtremeSpeed))
          {
            creatureExtremeSpeed = gMonsterDatabase[armyGroupSource->creatureTypes[l]].speed;
            maxTroopFightValue = armyGroupSource->quantities[l] *
				gMonsterDatabase[armyGroupSource->creatureTypes[l]].fight_value;
            joinCreatureSlotIndex = l;
		  }
		  else // ��� ��������� ��������� �������� �������� � ������� fight_value
		  {
            if(gMonsterDatabase[armyGroupSource->creatureTypes[l]].speed == creatureExtremeSpeed &&
				armyGroupSource->quantities[l] * gMonsterDatabase[armyGroupSource->creatureTypes[l]].fight_value > maxTroopFightValue)
			{
              maxTroopFightValue = armyGroupSource->quantities[l] *
				  gMonsterDatabase[armyGroupSource->creatureTypes[l]].fight_value;
              joinCreatureSlotIndex = l;
			}
		  }
		}
	  }
    }

    if(joinCreatureSlotIndex == -1)
    {
	  doCycle = false;
    }
    else if(armyGroup_CanJoin(armyGroupDest, armyGroupSource->creatureTypes[joinCreatureSlotIndex]))
    {
	  joinedQuantity = (float)redistributedArmyValue /
		  (float)gMonsterDatabase[armyGroupSource->creatureTypes[joinCreatureSlotIndex]].fight_value + 0.5;

	  if(joinedQuantity <= 0)
      {
        doCycle = false;
      }
	  else
	  {
        if(armyGroupSource->quantities[joinCreatureSlotIndex] >= joinedQuantity)
        {
          doCycle = false;
		  // �������� ���� ������� ��� ��������� ��������
          if(((float)joinedQuantity >= (float)armyGroupSource->quantities[joinCreatureSlotIndex] *
			0.65 || armyGroupSource->quantities[joinCreatureSlotIndex] - 1 <= joinedQuantity)
            && (float)((armyGroupSource->quantities[joinCreatureSlotIndex] - joinedQuantity)
            * gMonsterDatabase[armyGroupSource->creatureTypes[joinCreatureSlotIndex]].fight_value)
			< (float)(armyValueSource - redistributedArmyValue) * 0.2 )
				joinedQuantity = armyGroupSource->quantities[joinCreatureSlotIndex];
        }
        else
        {
          joinedQuantity = armyGroupSource->quantities[joinCreatureSlotIndex];
        }
        if(isGivingTroopsFromHero && armySourceQuantity <= joinedQuantity)
        {
          joinedQuantity = armySourceQuantity - 1;
          doCycle = false;
        }
		// ���� ����������� ����� ����������� �� ������� ��� ������� (>20%, �� ����� ������ ��� ��� ��������)
        if((float)redistributedArmyValue >= (float)(joinedQuantity *
			gMonsterDatabase[armyGroupSource->creatureTypes[joinCreatureSlotIndex]].fight_value) * 1.2 )
          redistributedArmyValue -= joinedQuantity *
			gMonsterDatabase[armyGroupSource->creatureTypes[joinCreatureSlotIndex]].fight_value;
        else
          doCycle = false;
        armyGroup_Add(armyGroupDest, armyGroupSource->creatureTypes[joinCreatureSlotIndex], joinedQuantity, -1);
        armyGroupSource->quantities[joinCreatureSlotIndex] -= joinedQuantity;
        if(!armyGroupSource->quantities[joinCreatureSlotIndex])
          armyGroupSource->creatureTypes[joinCreatureSlotIndex] = -1;
	  }
    }
    else
    {
	  doCycle = false;
    }
  }
}

int philAI_ValueOfTown(town* town_1)
{

  return 1;
}

void philAI_HeroInteractionAtTown(void *philAI_1, hero* hero_1, town* town_1, bool isEstimationOnly, int* townMeetingValue)
{
  *townMeetingValue = 0;

  if(isEstimationOnly)
  {
	if(town_1->buildingsBuiltFlags & BUILDING_DOCK_BUILT && town_1->idx != giBestShipyardId)
    {
      int deltaX = abs(town_1->x - hero_1->x);
      int simpleDist = abs(town_1->y - hero_1->y) + deltaX;
      if(gbActualShipyardFound)
      {
        if(simpleDist < giBestShipyardDist)
        {
          giBestShipyardDist = simpleDist;
          giBestShipyardId = town_1->idx;
        }
      }
      else
      {
        giBestShipyardDist = simpleDist;
        giBestShipyardId = town_1->idx;
      }
      gbPossibleShipyardFound = 1;
      gbActualShipyardFound = 1;
	}
    else if(town_1->buildingsBuiltFlags & BUILDING_CASTLE_BUILT
  && !giGroundToTerrain[advManager_GetCell(gpAdvManager, town_1->x - 1, town_1->y + 1)->groundIndex]
  && !gbActualShipyardFound && town_1->idx != giBestShipyardId)
    {
      int deltaX = abs(town_1->x - hero_1->x);
      int simpleDist = abs(town_1->y - hero_1->y) + deltaX;
      if(gbPossibleShipyardFound)
      {
        if(simpleDist < giBestShipyardDist)
        {
          giBestShipyardDist = simpleDist;
          giBestShipyardId = town_1->idx;
        }
      }
      else
      {
        giBestShipyardDist = simpleDist;
        giBestShipyardId = town_1->idx;
      }
      gbPossibleShipyardFound = 1;

    }
  }
  else
  {
    hero_1->aiLastTownInteractionTurn = giCurTurn;
	hero_1->aiLastTownInteractionIdx = town_1->idx;
	if(!hero_HasArtifact((hero*)hero_1, ARTIFACT_MAGIC_BOOK) && town_1->buildingsBuiltFlags & BUILDING_MAGE_GUILD_BUILT)
    {
      if(gpCurPlayer->resources[RESOURCE_GOLD] < 500)
      {
		  hero_1->remainingMobility = 0;
      }
      else
      {
        GiveArtifact((hero*)hero_1, ARTIFACT_MAGIC_BOOK, 1, -1);
        gpCurPlayer->resources[RESOURCE_GOLD] -= 500;
      }
    }
    if(town_1->buildingsBuiltFlags & BUILDING_MAGE_GUILD_BUILT
      && hero_HasArtifact((hero*)hero_1, ARTIFACT_MAGIC_BOOK)
	  && 10 * hero_Stats((hero*)hero_1, PRIMARY_SKILL_KNOWLEDGE) > hero_1->spellpoints)
      hero_1->remainingMobility = 0;
  }

  if(town_1->buildingsBuiltFlags & BUILDING_MAGE_GUILD_BUILT &&
	  (isEstimationOnly || hero_HasArtifact((hero *)hero_1, ARTIFACT_MAGIC_BOOK)))
  {
    *townMeetingValue += philAI_ManaRefreshValue(hero_1, 1);
	int knowledgeFactor;
	for(int i = 1; i <= hero_1->secondarySkillLevel[SECONDARY_SKILL_WISDOM] + 2; i++)
    {
	  for(int j = 0; j < town_1->numSpellsOfLevel[i-1]; j++)
      {
		if(!hero_HasSpell((hero *)hero_1, town_1->mageGuildSpells[i-1][j]))
        {
          if(gsSpellInfo[town_1->mageGuildSpells[i-1][j]].attributes & ATTR_COMMON_SPELL)
            knowledgeFactor = hero_Stats((hero *)hero_1, PRIMARY_SKILL_KNOWLEDGE);
          else
            knowledgeFactor = 1;
		  // ����� ������������ �������. ��-������, ������ ������ ������, � ��� �����. ���� ?
		  // ��-������ ATTR_COMMON_SPELL - �����-�� ������������ �����

		  // ����� ������ �� ���� ��� � philAI_FightValueOfStack !!
          *townMeetingValue += knowledgeFactor * gsSpellInfo[town_1->mageGuildSpells[i-1][j]].appearingChance;
        }
      }
    }
  }

  int heroArmyFightValue = philAI_FightValueOfStack((armyGroup*)&hero_1->army, 0, 0, 0, 0, 0);
  int townGarrisonFightValue = philAI_FightValueOfStack((armyGroup*)&town_1->garrison, 0, 0, 0, 0, 0);
  float actualTownFV = (float)townGarrisonFightValue / (float)(townGarrisonFightValue + heroArmyFightValue);
  
  int heroMightFactor = hero_Stats((hero*)hero_1, PRIMARY_SKILL_ATTACK);
  heroMightFactor += hero_Stats((hero*)hero_1, PRIMARY_SKILL_DEFENSE);
  if(heroMightFactor > 10)
    heroMightFactor = 10;

  if(heroMightFactor > 10)
    heroMightFactor = 10;

  float optimalTownFV;
  if(town_1->buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
    optimalTownFV = 0.54 - heroMightFactor * 0.02;
  else
    optimalTownFV = 0.33 - heroMightFactor * 0.01;

  if(giCurTurn > 7)
  {
    if(giCurTurn > 14)
    {
      if(giCurTurn <= 21)
        optimalTownFV = optimalTownFV * 0.8;
    }
    else
    {
      optimalTownFV = optimalTownFV * 0.5;
    }
  }
  else
  {
    optimalTownFV = fFirstWeekTownFV;
  }

  // ����� ������ 2 ����������, ���� ������� 2 � �����
  // ���� ��������� ��������� �����������, ���� ������� 2 � �����
  // �� ����� � ������� � optimal redistribution ����� �������
  if(hero_1->idx == iAlphaMale)
    optimalTownFV = optimalTownFV * 0.5;
  if( gpGame->mapHeader.winConditionType == 1
    && gpGame->mapHeader.winConditionArgumentOrLocX == town_1->x
    && gpGame->mapHeader.winConditionArgumentOrLocY == town_1->y)
    optimalTownFV = 0.80000001;

  float redistributedFV;
  if(optimalTownFV < actualTownFV)
    redistributedFV = actualTownFV - optimalTownFV;
  else
    redistributedFV = optimalTownFV - actualTownFV;

  if(optimalTownFV * 0.15 <= redistributedFV && redistributedFV >= 0.08)
  {
    int isGivingTroopsToHero = false;
    if(optimalTownFV < actualTownFV)
      isGivingTroopsToHero = true;
    if(isEstimationOnly)
    {
	  float multFactor;
      if(heroArmyFightValue >= townGarrisonFightValue)
        multFactor = 0.13;
      else
        multFactor = 0.25;
      float adjustedRedistributedFV = redistributedFV + 1.0 - 0.22;
      int redistributionValue = ((adjustedRedistributedFV * adjustedRedistributedFV - 1.0) *
		  gpCurPlayer->aiIncomeToFightValueRatio * (float)(townGarrisonFightValue + heroArmyFightValue) * multFactor);

      if(redistributionValue < 0)
        redistributionValue = 0;
      int hasFreeSlots = false;

      if(isGivingTroopsToHero)
      {
        for(int k = 0; k < 5; k++)
        {
			if(hero_1->army.quantities[k] <= 0)
            hasFreeSlots = true;
        }
      }
      else
      {
        for(int l = 0; l < 5; l++)
        {
			if(town_1->garrison.quantities[l] <= 0)
            hasFreeSlots = true;
        }
      }

      if(!hasFreeSlots)
      {
        for(int m = 0; m < 5; m++)
        {
          for(int n = 0; n < 5; n++)
          {
			if(hero_1->army.creatureTypes[n] == town_1->garrison.creatureTypes[m])
            {
              hasFreeSlots = true;
              break;
            }
          }
        }
      }

      if(!hasFreeSlots)
        redistributionValue = 0;
      *townMeetingValue += redistributionValue;
	  // �������, 500 - ��� ���� ����
	  if(town_1->aiInDanger && town_1->visitingHeroIdx == -1)
        *townMeetingValue += 500;
    }
    else
    {
      town_GiveSpells(town_1, 0);
	  // ������ ?
      if(isGivingTroopsToHero)
        redistributedFV += 0.04;
	  armyGroup* armySource;
	  armyGroup* armyDest;

      if(isGivingTroopsToHero)
		  armySource = (armyGroup*)&town_1->garrison;
      else
		  armySource = (armyGroup*)&hero_1->army;

      if(isGivingTroopsToHero)
		  armyDest = (armyGroup*)&hero_1->army;
      else
		  armyDest = (armyGroup*)&town_1->garrison;

	  int armyFightValueSource;
	  int armyFightValueDest;

      if(isGivingTroopsToHero)
      {
        armyFightValueSource = townGarrisonFightValue;
        armyFightValueDest = heroArmyFightValue;
      }
      else
      {
        armyFightValueSource = heroArmyFightValue;
        armyFightValueDest = townGarrisonFightValue;
      }
      philAI_RedistributeTroops(
        philAI_1,
        (armyGroup*)armySource,
        (armyGroup*)armyDest,
        !isGivingTroopsToHero,
        isGivingTroopsToHero,
        armyFightValueSource,
        armyFightValueDest,
        (float)((townGarrisonFightValue + heroArmyFightValue) * redistributedFV));
	  if(town_1->idx == giHumanTownConquered && hero_1->remainingMobility <= 20 )
        hero_1->remainingMobility = 0;
    }
  }
}

void philAI_HeroInteractionAtHero(void* philAI_1, hero* hero_1, hero* hero_2, bool isEstimationOnly, int* heroMeetingValue)
{
  *heroMeetingValue = 0;

  // �� ���� ������ ������ ��� ������� iAlphaMale - ������ � ���� ������ ������� ������ ����� �����
  // �� ������, ��� ��� ���������� ������
  if(!isEstimationOnly || hero_1->idx == iAlphaMale || hero_2->idx == iAlphaMale )
  {
    if(!isEstimationOnly)
    {
      hero_1->aiLastHeroInteractionTurn = giCurTurn;
	  hero_1->aiLastHeroInteractionIdx = hero_2->idx;
      hero_2->aiLastHeroInteractionTurn = giCurTurn;
	  hero_2->aiLastHeroInteractionIdx = hero_1->idx;
    }

	hero* heroCurrent;
	int heroValue[2];
    for(int i = 0; i < 2; i++)
    {
      if(i)
        heroCurrent = hero_2;
      else
        heroCurrent = hero_1;
      heroValue[i] = 0;
	  // ����������� � �������� - ��� �����. � ������� ���������� ������. ������
	  // �� �������� �� �����������
      for(int primarySkill = 0; primarySkill < 4; primarySkill++)
      {
        if(primarySkill < 2 || hero_HasArtifact(heroCurrent, ARTIFACT_MAGIC_BOOK) )
          heroValue[i] += 800 * hero_Stats(heroCurrent, primarySkill);
      }
      for(int secSkill = 0; secSkill < 14; secSkill++)
      {
        if(secSkill != SECONDARY_SKILL_ESTATES && heroCurrent->secondarySkillLevel[secSkill])
          heroValue[i] += gSSValues[secSkill][heroCurrent->secondarySkillLevel[secSkill]];
      }
	}

	float strengthMightHero = (float)heroValue[0] / (float)(heroValue[0] + heroValue[1]);
	hero* heroMight;
	hero* heroWeak;
    if(heroValue[1] >= heroValue[0])
    {
      heroMight = hero_2;
      heroWeak = hero_1;
      strengthMightHero = 1.0 - strengthMightHero;
    }
    else
    {
      heroMight = hero_1;
      heroWeak = hero_2;
    }

	// ���� �� ��� ��������� (���� ��� ����� ������, �� ���������� - ���)
	if(isEstimationOnly && heroWeak->idx == iAlphaMale && strengthMightHero < 0.6)
      heroWeak = heroMight;
	int armyHeroMightFightValue = philAI_FightValueOfStack((armyGroup*)&heroMight->army, 0, 0, 0, 0, 0);
    int armyHeroWeakFightValue = philAI_FightValueOfStack((armyGroup*)&heroWeak->army, 0, 0, 0, 0, 0);

	float heroMightArmyFV = (float)armyHeroMightFightValue / (float)(armyHeroMightFightValue + armyHeroWeakFightValue);
	float redistributedFV;

	// ����������� � �������� - ��� �����. � ������� ���� ����� ������ �-��
	// ������������� �������� �� ����������� �����
    if(heroMightArmyFV > 0.69999999)
      redistributedFV = heroMightArmyFV - 0.69999999;
    else
      redistributedFV = 0.69999999 - heroMightArmyFV;

    if(redistributedFV >= 0.15)
    {
      *heroMeetingValue = (armyHeroMightFightValue + armyHeroWeakFightValue) * redistributedFV
		  * gpCurPlayer->aiIncomeToFightValueRatio;
      if(isEstimationOnly)
      {
        for(int i = 0; i < 14; i++)
        {
		  int artIndex = heroWeak->artifacts[i];
          if(artIndex != -1 && artIndex != 81)
            *heroMeetingValue += gArtifactBaseRV[artIndex];
        }
	  }
      else
      {
        advManager_TransferArtifacts(heroWeak, heroMight);
        if(heroMightArmyFV <= 0.69999999)
          philAI_RedistributeTroops(
            philAI_1,
			(armyGroup*)&heroWeak->army,
            (armyGroup*)&heroMight->army,
            1,
            1,
            armyHeroWeakFightValue,
            armyHeroMightFightValue,
            (float)((armyHeroWeakFightValue + armyHeroMightFightValue) * redistributedFV));
        else
          philAI_RedistributeTroops(
            philAI_1,
            (armyGroup*)&heroMight->army,
            (armyGroup*)&heroWeak->army,
            1,
            1,
            armyHeroMightFightValue,
            armyHeroWeakFightValue,
            (float)((armyHeroWeakFightValue + armyHeroMightFightValue) * redistributedFV));
        philAI_SetupRelativeHeroStrengths();
      }
	  *heroMeetingValue = *heroMeetingValue * 0.1;
	}
  }
}

int philAI_EvaluateTownEvent(void* phil_AI, int townIdx, int x, int y, int typeOfEstimation, int* probOfSuccess)
{
  town* town_1 = &gpGame->castles[townIdx];
  int value;
  int townValue;

  float probWinnerA;
  int probableApproxCasualtiesA;
  int probableApproxCasualtiesD;
  int probablePreciseCasualtiesA;
  int probablePreciseCasualtiesD;
  int adjustedProfitA;
  hero* heroD;
  float attackBonus;

  if(gpGame->townOwner[townIdx] == gpCurAIHero->ownerIdx)
  {
    if(town_1->visitingHeroIdx == -1 )
    {
      value = 0;
      if(giCurTurn - gpCurAIHero->aiLastTownInteractionTurn >= 4 || gpCurAIHero->aiLastTownInteractionIdx != town_1->idx )
      {
        philAI_HeroInteractionAtTown(phil_AI, gpCurAIHero, town_1, 1, &value);
        value = value * gfHeroInteractionBonus[gpCurAIHero->idx]; // gfHeroInteractionBonus ��� ���� 1.0
      }
    }
    else if(typeOfEstimation)
    {
      value = -500; // RV_ESTIMATION, ORDINARY_ESTIMATION
    }
    else
    {
      value = 0; // STRATEGIC_ESTIMATION
    }
    gbReduceByReload = 0;
  }
  else if(OnMySide(gpGame->townOwner[townIdx]))
  {
    if(typeOfEstimation)
      value = -1500; // RV_ESTIMATION, ORDINARY_ESTIMATION
    else
      value = 0; // STRATEGIC_ESTIMATION
  }
  // ������������ �������. ���� �� ��� ��������
  else if(!gbIAmGreatest || gpGame->townOwner[townIdx] < 0 || gbHumanPlayer[gpGame->townOwner[townIdx]])
  {
    // ����� ���������� ���-�� ����� � ������ ���� ������������ ������� ������� ��� ��
    if(gpGame->difficulty >= 3
      || 40 - 8 * gpGame->difficulty <= giCurTurn
      || (mapRevealed[x + y * MAP_WIDTH] & giCurPlayerBit))
    {
      townValue = philAI_ValueOfTown(town_1);
      if(gpGame->castles[townIdx].visitingHeroIdx == -1)
      {
        if(town_HasGarrison(town_1))
        {
          philAI_ProbableOutcomeOfBattle(
            (armyGroup*)&gpCurAIHero->army,
            gpCurAIHero,
            (armyGroup*)&gpGame->castles[townIdx].garrison,
			0,
            0,
            1,
            townIdx,
            town_1->ownerIdx,
			&probWinnerA,
			&probableApproxCasualtiesA,
			&probableApproxCasualtiesD,
			&probablePreciseCasualtiesA,
			&probablePreciseCasualtiesD,
            &adjustedProfitA);
        }
        else
        {
          probWinnerA = 1.0;
          adjustedProfitA = 0;
        }
      }
      else
      {
		heroD = (hero*)&gpGame->heroes[town_1->visitingHeroIdx];
        philAI_ProbableOutcomeOfBattle(
            (armyGroup*)&gpCurAIHero->army,
            gpCurAIHero,
            (armyGroup*)&heroD->army,
            heroD,
			(armyGroup*)&town_1->garrison,
			1,
			townIdx,
            town_1->ownerIdx,
			&probWinnerA,
			&probableApproxCasualtiesA,
			&probableApproxCasualtiesD,
			&probablePreciseCasualtiesA,
			&probablePreciseCasualtiesD,
            &adjustedProfitA);
	  }

      *probOfSuccess = probWinnerA * 100.0;
      if(town_1->ownerIdx >= 0)
      {
        if(gbHumanPlayer[town_1->ownerIdx])
          attackBonus = gfAttackHumanBonus;
        else
          attackBonus = gfAttackComputerBonus;
        townValue = ((5 - gpGame->numPlayers) * 0.25 + 0.9) * attackBonus * townValue;
      }
      value = townValue * probWinnerA + value;
	  if(gpGame->townOwner[townIdx] != -1)
        gbReduceByBerserk = 0;
    }
    else
    {
      value = 0;
    }
  }
  else
  {
    value = 0;
  }

  if(town_1->ownerIdx != -1 && gbHumanPlayer[town_1->ownerIdx] && value > 200)
  {
    if(gpCurPlayer->personality != AI_WARRIOR)
      value = value * 1.3;
    else
      value = value * 1.6;
  }
  return value;

}

int philAI_EvaluateHeroEvent(void* phil_AI, int heroIdx, int x, int y, int typeOfEstimation, int* probOfSuccess)
{
  int value;
  int townValue;
  armyGroup* garrison;
  town* town_1;
  float attackBonus;
  hero* heroD;
  int townIdx;

  float probWinnerA;
  int probableApproxCasualtiesA;
  int probableApproxCasualtiesD;
  int probablePreciseCasualtiesA;
  int probablePreciseCasualtiesD;

  if(gpGame->heroOwner[heroIdx] == gpCurAIHero->ownerIdx )
  {
    if(typeOfEstimation)
    {
      if(typeOfEstimation == RV_ESTIMATION)
        // RV Estimation ������ ����� ������� ����� - ������, �� ���� �����������
		// �� ������ ������� ��� ����������. �����, ����� "�� �����" ���� � ����� ?
        value = -20000; // RV_ESTIMATION
      else
        value = -500; // ORDINARY_ESTIMATION
    }
    else
    {
      value = 0; // STRATEGIC_ESTIMATION
    }
	// ���� �� � ���� ����� ������ ����� �� �����������, �� ������� value
	// ���� �� ����������� ������������, �� value �������� ������ ������������� (��. ����)
    if(giCurTurn - gpCurAIHero->aiLastHeroInteractionTurn >= 4 || gpGame->heroes[heroIdx].idx != gpCurAIHero->aiLastHeroInteractionIdx)
      philAI_HeroInteractionAtHero(phil_AI, gpCurAIHero, &gpGame->heroes[heroIdx], 1, &value);
    gaiHeroLiveChance[heroIdx] = 100;
  }
  else if(OnMySide(gpGame->heroOwner[heroIdx]))
  {
    if(typeOfEstimation)
    {
      if(typeOfEstimation == RV_ESTIMATION)
        value = -20000; // RV_ESTIMATION
      else
        value = -1500; // ORDINARY_ESTIMATION
    }
    else
    {
      value = 0; // STRATEGIC_ESTIMATION
    }
  } 
  // ������������ �������. ���� �� ��� ��������
  else if(!gbIAmGreatest || gbHumanPlayer[gpGame->heroOwner[heroIdx]])
  {
   // value �������� �����-�� ��������
    value = 0;
    townValue = 0;
	garrison = 0;
	heroD = (hero*)&gpGame->heroes[heroIdx];
    if(gpGame->heroes[heroIdx].occupiedObjType == (LOCATION_TOWN | TILE_HAS_EVENT))
    {
      town_1 = (town*)&gpGame->castles[gpGame->heroes[heroIdx].occupiedObjVal];
      garrison = (armyGroup*)&gpGame->castles[gpGame->heroes[heroIdx].occupiedObjVal].garrison;
      townValue = philAI_ValueOfTown(&gpGame->castles[gpGame->heroes[heroIdx].occupiedObjVal]);
	  townIdx = town_1->idx;
	  if(town_1->ownerIdx >= 0)
      {
        if(gbHumanPlayer[town_1->ownerIdx])
          attackBonus = gfAttackHumanBonus;
        else
          attackBonus = gfAttackComputerBonus;
        value = ((5 - gpGame->numPlayers) * 0.25 * attackBonus + 1.0) * value;
      }
    }
	else
	{
      townIdx = -1;
	}
    philAI_ProbableOutcomeOfBattle(
      (armyGroup*)&gpCurAIHero->army,
      gpCurAIHero,
	  (armyGroup*)&heroD->army,
	  heroD,
      garrison,
      (unsigned int)garrison >= 1,
      townIdx,
	  town_1->ownerIdx,
  	  &probWinnerA,
	  &probableApproxCasualtiesA,
	  &probableApproxCasualtiesD,
	  &probablePreciseCasualtiesA,
	  &probablePreciseCasualtiesD,
      &value);
    *probOfSuccess = probWinnerA * 100.0;
    if(townValue > 0)
      value = townValue * probWinnerA + value;
    if(gbHumanPlayer[heroD->ownerIdx] && value > 200)
    {
      if(gpCurPlayer->personality != AI_WARRIOR)
        value = value * 1.5;
      else
        value *= 2;
    }
    if(probWinnerA <= 0.75)
    {
      if(probWinnerA <= 0.5 )
      {
        if(probWinnerA <= 0.4)
        {
          if(probWinnerA <= 0.3)
          {
            if(probWinnerA <= 0.2)
              gaiHeroLiveChance[heroIdx] = probWinnerA * 100.0;
            else
              gaiHeroLiveChance[heroIdx] = probWinnerA * 113.0;
          }
          else
          {
            gaiHeroLiveChance[heroIdx] = probWinnerA * 125.0;
          }
        }
        else
        {
          gaiHeroLiveChance[heroIdx] = probWinnerA * 130.0;
        }
      }
      else
      {
        gaiHeroLiveChance[heroIdx] = probWinnerA * 136.0;
      }
    }
    else
    {
      gaiHeroLiveChance[heroIdx] = 100;
    }
    if(gaiHeroLiveChance[heroIdx] > 100)
      gaiHeroLiveChance[heroIdx] = 100;
	// ��� STRATEGIC_ESTIMATION ��� ����� ������������ ������
	// value ����������� �������������
	// �������� �������. ����� ���� �� ������, ���� �� ��� �������� ������
	// ��������� ������� "�� �����������" - ����� ����� �� ����� � ���������� �����
    // � ����� ��� ���� �� ��������. ��� value � ������ ������ ������������� ? - ����� ����� ��������
    if(typeOfEstimation == STRATEGIC_ESTIMATION && probWinnerA < 0.4)
      value = (3.0 - probWinnerA * 2.0) * value;
    if (typeOfEstimation == STRATEGIC_ESTIMATION && probWinnerA < 0.2)
      value = (2.0 - probWinnerA * 2.0) * value;
    if(value < 0)
      gbReduceByReload = 0;
    gbReduceByBerserk = 0;
	// ����� ���������� ���-�� ����� � ������ ���� ������������ ������� ������� ��� ��
    if(value > 0
      && 70 - 5 * gpGame->difficulty > giCurTurn
      && (!mapRevealed[x + y * MAP_WIDTH] & giCurPlayerBit))
      value = 0;
  }
  else
  {
    value = 0;
    *probOfSuccess = 100;
  }
  return value;
}

int philAI_GoodAdjacent(void* philAI_1, int* pBestDirection)
{
  int bestDirection = -1;
  float reduceFactorSave = fReduceFactor;
  float berserkFactorSave = fBerserkFactor;
  fReduceFactor = 1.0;
  fBerserkFactor = 1.0;
  int bestAdjacentValue = 100;
  int isGoodAdjacentFound;
  int probabilityOfSuccess;
  int adjacentValue;

  // �������� �� ����������
  // �� ������ �� ���������� ��, ��� ����� � ���������� ?
  if((advManager_GetCell(gpAdvManager, gpCurAIHero->x, gpCurAIHero->y)->objType & (TILE_HAS_EVENT - 1)) == LOCATION_STONE_LITHS)
  {
    isGoodAdjacentFound = false;
  }
  else
  {
	int col;
	int row;
    for(int i = 0; i < 8; i++)
    {
      if(advManager_ValidMoveWithEvent(gpAdvManager, gpCurAIHero, i))
      {
        col = gpCurAIHero->x + normalDirTable[4 * i];
        row = gpCurAIHero->y + normalDirTable[4 * i + 1];
        if(advManager_GetCell(
               gpAdvManager,
               gpCurAIHero->x + normalDirTable[4 * i],
               gpCurAIHero->y + normalDirTable[4 * i + 1])->objType & TILE_HAS_EVENT)
        {
		  // �� ������������ ����������� ���� ������, ���� � ���� ���� ��� ���� �������������� � ���
		  // ��� ��� �������� ��������
		  // 0x80 - ������� ��� � ����� mapRevealed - ��� �� �������� ?
          if(!(mapRevealed[col + row * MAP_WIDTH] & 0x80)
            && (advManager_GetCell(gpAdvManager, col, row)->objType & (TILE_HAS_EVENT - 1)) != LOCATION_STONE_LITHS
            && (advManager_GetCell(gpAdvManager, col, row)->objType & (TILE_HAS_EVENT - 1)) != LOCATION_WHIRLPOOL
			&& (advManager_GetCell(gpAdvManager, col, row)->objType != (LOCATION_TOWN | TILE_HAS_EVENT) // ��������� 3 ������� ���� ������
             || gpGame->castles[advManager_GetCell(gpAdvManager, col, row)->extraInfo].ownerIdx != giCurPlayer
             || gpCurAIHero->aiLastTownInteractionTurn != giCurTurn))
          {
			  // ���������� � ���������-�������
			  if(!(advManager_GetCell(gpAdvManager, col, row)->objType == (LOCATION_HERO | TILE_HAS_EVENT))
              || gpGame->heroes[advManager_GetCell(gpAdvManager, col, row)->extraInfo].ownerIdx != giCurPlayer
              || gpCurAIHero->aiLastHeroInteractionTurn != giCurTurn)
            {
              adjacentValue = philAI_ValueOfEventAtPosition(philAI_1, row, col, ORDINARY_ESTIMATION, &probabilityOfSuccess);
              if(probabilityOfSuccess > 80)
              {
			    if(adjacentValue > bestAdjacentValue)
				{
                  bestAdjacentValue = adjacentValue;
				  bestDirection = i;
				}
			  }
			}
		  }
		}
	  }
	}
    fReduceFactor = reduceFactorSave;
    fBerserkFactor = berserkFactorSave;
    if(bestDirection == -1)
    {
      isGoodAdjacentFound = false;
    }
    else
    {
      *pBestDirection = bestDirection;
      isGoodAdjacentFound = true;
    }
  }
  return isGoodAdjacentFound;
}

void philAI_LikelihoodOfEnemyAttacking(town* town_1, int a2, float* a3, float* a4, int* a5, float* a6, int* a7, float* a8)
{
  *a3 = 0.15;
  *a4 = 0.6;
  *a5 = 3000;
  *a6 = *a5 * *a3;
  *a7 = 6;
  *a8 = *a4 * *a3;
}

float philAI_TurnsToBuy(SBuildingCost* cost)
{
  float result = 0.0;
  float nDays;
  float maxDays;
  for(int i = 0; i < 7; i++)
  {
    if(gpCurPlayer->resources[i] < *(int*)((int)&cost + 4*i))
    {
	  if(gpCurPlayer->resourcesIncome[i] <= 0)
      nDays = 99.0;
      else
        nDays = (*(int*)((int)&cost + 4*i) - gpCurPlayer->resources[i]) / gpCurPlayer->resourcesIncome[i] + 1;
      maxDays = nDays;
      if(result >= nDays)
        maxDays = result;
      result = maxDays;
    }
  }
  return result;
}

// 3-4 ��� �������� � ������������� ���������� � ������ �������� value
float philAI_FutureDeflator(SBuildingCost* cost)
{
  float result = 1.0 - philAI_TurnsToBuy(cost) * 0.15000001;
  if(result < 0)
    result = 0.0;
  return result;
}

int philAI_RVConversion(SBuildingCost* cost)
{
  return (cost->gems * gafAITurnCostResource[RESOURCE_GEMS]
	  + cost->mercury * gafAITurnCostResource[RESOURCE_MERCURY]
      + cost->gold * gafAITurnCostResource[RESOURCE_GOLD]
      + cost->ore * gafAITurnCostResource[RESOURCE_ORE]
	  + cost->sulfur * gafAITurnCostResource[RESOURCE_SULFUR]
	  + cost->crystal * gafAITurnCostResource[RESOURCE_CRYSTAL]
      + cost->wood * gafAITurnCostResource[RESOURCE_WOOD]);
}

int philAI_ValueOfBuyingBuilding(town* town_1, int building, int* buildingFinalValue, float* buildingFinalProfit)
{
  int faction = town_1->factionID;
  int numberOfDwellings = 0;
  int maxDwellingIndex = -1;
  for(int i = 19; i < 30; i++)
  {
	if((1 << i) & town_1->buildingsBuiltFlags)
    {
      ++numberOfDwellings;
      maxDwellingIndex = i;
    }
  }

  int numberOfGarrisonTroops = 0;
  for(int i = 0; i < 5; i++)
  {
	if(town_1->garrison.quantities[i] > 0)
      ++numberOfGarrisonTroops;
  }

  int buildingMagicGuildCode;
  if(building)
    buildingMagicGuildCode = 1;
  else
	buildingMagicGuildCode = town_1->mageGuildLevel + 1;

  // ������� ���������� ���������
  float buildingValue;

  buildingValue = GetBuildingBaseResourceValue(faction, building, buildingMagicGuildCode);
  // ���� ��������� - ��� �������, �� �������� ���� ������� ���������
  if(building >= 25 && building <= 29)
    buildingValue = buildingValue - GetBuildingBaseResourceValue(faction, building - 5, 1);
  // ���� ������ ������ �����
  if(building == 30)
    buildingValue = buildingValue - GetBuildingBaseResourceValue(faction, 29, 1);
  if(!building && town_1->mageGuildLevel > 1 )
    buildingValue = buildingValue - GetBuildingBaseResourceValue(faction, 0, town_1->mageGuildLevel);

  bool isFreeSlot;
  int dwellingIndex;
  int creatureId;

  switch(building)
  {
    case BUILDING_CASTLE:
      if(town_1->disabledUpgradeToCastle)
        buildingValue = -99.0;
      break;
    case BUILDING_MAGE_GUILD:
	  // ���� �� ������ � �� ������
      // ���������� ������ � ���, ��� ��� ������� �� �� ���� �����, � �� ���� �������� ������� ������ ������
	  // ���� � ����� ����� � ���� ������ ����� ������ ����
	  if(town_1->factionID && town_1->factionID != 1 )
      {
		if(town_1->mageGuildLevel)
        {
          if(town_1->mageGuildLevel >= 4 && giCurTurn < 35
            || town_1->mageGuildLevel >= 3 && giCurTurn < 25
            || town_1->mageGuildLevel >= 2 && giCurTurn < 15)
            buildingValue = buildingValue * 0.55;
        }
        else
        {
          buildingValue = buildingValue * 1.2; // ���� �� ���, �� ���� �� ������� �� ���������
        }
      }
	  // ��� ������ � �������
      else if((town_1->mageGuildLevel < 4 || giCurTurn >= 40)
  && (town_1->mageGuildLevel < 3 || giCurTurn >= 30)
  && (town_1->mageGuildLevel < 2 || giCurTurn >= 20))
      {
        buildingValue = buildingValue * 0.65;
      }
      else
      {
        buildingValue = buildingValue * 0.4;
      }
      break;
    case BUILDING_THIEVES_GUILD:
	  // ����� ����� ���� ������� ������� (������ ��������)
	  if(town_1->factionID == FACTION_NECROMANCER && town_1->buildingsBuiltFlags & BUILDING_DWELLING_3_BUILT)
      {
        buildingValue = 1500.0;
      }
      else if(giCurTurn < 21)
      {
        buildingValue = 0.0;
      }
      break;
    case BUILDING_STATUE:
      if(giCurTurn < 3 && !(town_1->buildingsBuiltFlags & BUILDING_DWELLING_3_BUILT))
        buildingValue = 0.0;
      break;
    case BUILDING_MARKET:
	  // ������ ������ �� ����� ������ �� �����, � �� ������ � ������ 3 ������, ���� �� �� ����� �� ������������
      if(giCurTurn < 21)
        buildingValue = 0.0;
      break;
    case BUILDING_SPECIAL_GROWTH:
	  // ���� ����� ����� ������ � ����� ������
      if(gpGame->day < 6)
        buildingValue = 0.0;
      break;
    case BUILDING_LEFT_TURRET:
    case BUILDING_RIGHT_TURRET:
    case BUILDING_MOAT:
    case BUILDING_CAPTAIN:
		// � ��� ��� ������ ������
        if(giCurTurn < 16)
          buildingValue = 0.0;
		break;
    case BUILDING_SPECIAL:
	  // ���������� ���� ��� ����, ��������� ����� �� ����� ��������, ����� ������ �����
      if(town_1->factionID == FACTION_KNIGHT || town_1->factionID == FACTION_BARBARIAN ||
		  town_1->factionID == FACTION_SORCERESS || town_1->factionID == FACTION_NECROMANCER)
        if(giCurTurn < 16)
          buildingValue = 0.0;
      break;
    case BUILDING_DOCK:
	  // �����, ������, �������� �� ���������� ���������
      buildingValue = 0.0;
      break;
    case BUILDING_WELL:
      buildingValue = (gpCurPlayer->aiTurnAttentionValueBuildings + 0.66) * buildingValue; // ��������, aiTurnAttentionValueBuildings ��������� � ����������, � aiTurnAttentionValueCreatures � ������
      buildingValue = (gpCurPlayer->aiTurnAttentionValueCreatures * 2.0 + 0.33) * buildingValue; // ������, ��� ������ ��� aiParam, ��� ������ �����
      buildingValue = (numberOfDwellings * 0.33 + 0.66) * buildingValue;
	  if((town_1->factionID || !(town_1->buildingsBuiltFlags & BUILDING_DWELLING_2_BUILT)) && gpGame->day < 6)
        buildingValue = 0.0;
      break;
    case BUILDING_TAVERN:
      if(town_1->factionID != FACTION_NECROMANCER)
      {
	    // ����� ����� ����������� - BUILDING_DWELLING_3_BUILT ��� ���-���� ���-�� ������
        if(town_1->factionID == FACTION_KNIGHT && town_1->buildingsBuiltFlags & BUILDING_DWELLING_3_BUILT || 
			town_1->factionID == FACTION_SORCERESS && town_1->buildingsBuiltFlags & BUILDING_DWELLING_3_BUILT)
        {
          buildingValue = 1000.0;
        }
        else
        {
          if(giCurTurn < 16)
            buildingValue = 0.0;
        }
      }
      break;
    case BUILDING_DWELLING_1:
    case BUILDING_DWELLING_2:
    case BUILDING_DWELLING_3:
    case BUILDING_DWELLING_4:
    case BUILDING_DWELLING_5:
    case BUILDING_DWELLING_6:
    case BUILDING_UPGRADE_1:
    case BUILDING_UPGRADE_2:
    case BUILDING_UPGRADE_3:
    case BUILDING_UPGRADE_4:
    case BUILDING_UPGRADE_5:
    case BUILDING_UPGRADE_5B:
      if(numberOfGarrisonTroops == 5)
      {
        isFreeSlot = false;
        for(int i = 0; i < 5; i++)
        {
		  if(gDwellingType[building - 19 + 12 * town_1->factionID] == town_1->garrison.creatureTypes[i])
            isFreeSlot = true;
        }
        if(!isFreeSlot)
          break;
      }
      buildingValue = (gpCurPlayer->aiTurnAttentionValueBuildings + 0.66) * buildingValue;;
      buildingValue = (gpCurPlayer->aiTurnAttentionValueCreatures * 2.0 + 0.33) * buildingValue; // ������, ��� ������ ��� aiParam, ��� ������ �����
	  // ������ - �� �� ����� ������� ������� ���� ? � �� ��� ������ ������ + � �� -
      buildingValue = (1.0 - playerData_BuildingsOwned(gpCurPlayer, faction, building, 0) * 0.05) * buildingValue;
	  // ������, ������ - �� ������� �������� 19 (BUILDING_DWELLING_1)
      if(building - BUILDING_DWELLING_1 < maxDwellingIndex)
	    // ����� ����������� ���������� - ���� �������� buildingValue ����� �������
        // ������, �������� ��-�� ���� �������� ����
        buildingValue = (1.66 - numberOfDwellings * 0.33) * buildingValue;
	  if(town_1->buildingsBuiltFlags & BUILDING_WELL_BUILT)
        buildingValue = buildingValue * 1.1;
      dwellingIndex = 0;
	  // ���������� �� ���������� ����� - ���� ���� ��� ����������� ��������
	  // � ���������� �������� ����������, ������, ��������������, �� ������ �����,
	  // ��� ��� ���� �������� ��� ���� �� �����
	  while(dwellingIndex < 12)
	  {
        creatureId = gDwellingType[town_1->factionID * 12 + dwellingIndex];
		if((1 << (dwellingIndex + 19)) & town_1->buildingsBuiltFlags
		  && town_1->numCreaturesInDwelling[dwellingIndex] > 0
		  && gMonsterDatabase[gDwellingType[building - 19 + 12 * town_1->factionID]].fight_value_aux < gMonsterDatabase[creatureId].fight_value_aux * 1.2)
		{
		  buildingValue = 0.0;
		  break;
		}
		++dwellingIndex;
	  }
      break;
    case BUILDING_BOAT:
      break;
  }
  float v30, v28, v25, v34;
  int v26, v23;
  // ��� ��������� �� ��������, ���� ������������ ����� "��������"
  // v34 �������� �������� 0.09 (��� ����� ����������� ��������� ����� �� �����)
  philAI_LikelihoodOfEnemyAttacking(town_1, 0, &v30, &v28, &v26, &v25, &v23, &v34);
  // ��� ������ ����������� ����� �� �����, ��� ������ buildingValue
  // ������, ��� ������ ��� ��������� ���. �����, ���, �������� - ��� � ���� ��������
  // - � ��� ������, ���� ��������� ������� ������ �����
  // �� ��������� ����������� ��� ��� ������, ����� ����������� � ������������ ��������
  buildingValue = (1.0 - v34 * 3.0) * buildingValue;
  // ���������, ��� ����� playerPos - ����� �� � ����� ��������� ����� � ����� � ����� ?
  if(town_1->playerPos != giCurPlayer )
    buildingValue = buildingValue * 0.85;
  if(buildingValue < 0.0)
    buildingValue = 0.0;

  int currentMagicGuildLevel;
  if(building)
    currentMagicGuildLevel = 0;
  else
	currentMagicGuildLevel = town_1->mageGuildLevel;

  SBuildingCost* cost;

  GetBuildingCost(faction, building, cost, currentMagicGuildLevel);

  // ������� �� ����� ������ �� ������� ��������� � �������� ��������� ������ � ������� ?
  // ���� �� ����� �������, ��� 3-4 ��� �������� � ������������� ���������� � ������ �������� value
  float deflator = philAI_FutureDeflator(cost);
  buildingValue = deflator * buildingValue;
  *buildingFinalValue = buildingValue;
  int costRV = philAI_RVConversion(cost);
  float buildingProfit = (float)buildingValue / (float)costRV;
  *buildingFinalProfit = buildingProfit;

}

void philAI_GetBestBuilding(void* philAI_1, town* town_1, int* bhcData, float* bhcValue)
{
  float bestProfit = -99.0;
  float bestRandomizedProfit = -99.0;
  int bestBuilding = -1;

  int buildingValue;
  float buildingProfit;

  int randomCoef;
  float buildingRandomizedProfit;

  for(int building = 0; building < 32; building++)
  {
    // ���� ������� �������� ��� ��� � �� �� ���������� ������� �����. ������� ���� 5 ������
	if((!((1 << building) & town_1->buildingsBuiltFlags) || !building && town_1->mageGuildLevel < 5)
      && CanBuild(town_1, building) )
    {
      philAI_ValueOfBuyingBuilding(town_1, building, &buildingValue, &buildingProfit);

	  // ������, buildingValue ������ ����� �� ������������ (��� ?)
	  // ������ �� ����. 1.3 ����� �������� buildingProfit
	  // ������, � ����� ����� �������� ��� bestProfit
      if(gpCurPlayer->personality == AI_BUILDER)
      {
        buildingValue = buildingValue * 1.3;
      }
      randomCoef = Random(1, 5) + 95;
      buildingRandomizedProfit = randomCoef * buildingProfit / 100.0;

      if(buildingRandomizedProfit > bestRandomizedProfit)
      {
        bestBuilding = building;
        bestProfit = buildingProfit;
        bestRandomizedProfit = buildingRandomizedProfit;
      }
	}
  }

  bhcData[0] = (int)town_1;
  bhcData[1] = 0;
  bhcData[2] = bestBuilding;
  *bhcValue = bestProfit;

}

int philAI_MaxBuyableCreatures(int creatureId)
{
  int monsterCost[7];
  int result;
  GetMonsterCost(creatureId, monsterCost);

  // ������, ����� ���. ����� �������� �� ������,
  // �������� ������� (������������ ������ �� �������)
  for(int i = 0; i < 7; i++)
  {
    if(monsterCost[i])
    {
      if(gpCurPlayer->resources[i] <= 0)
        result = 0;
      else
        result = gpCurPlayer->resources[i] / monsterCost[i];
    }
    else
    {
      result = 9999;
    }
  }
  return result;
}

int philAI_CreaturesToBuy(int creatureId, int maxCreatures)
{
  int result;
  int maxBuyableCreatures = philAI_MaxBuyableCreatures(creatureId);

  // ������ ����� ������ ������ �������� ������� - ���������
  if(maxBuyableCreatures > 1 )
    maxBuyableCreatures = maxBuyableCreatures / 2;
  if(maxCreatures < maxBuyableCreatures)
    maxBuyableCreatures = maxCreatures;

  // �������� ������� - ���� ��� ������ ������ 1 ��������, �� �� ��������
  // ��������, ����� ����� ��� ������� ������ �������, �� �� ��� �������
  if(maxBuyableCreatures <= 1 )
    result = 0;
  else
    result = maxBuyableCreatures;
  return result;
}

int philAI_CreaturesToBuy(void* philAI_1, town* town_1, int dwellingIdx)
{
  return philAI_CreaturesToBuy(gDwellingType[town_1->factionID + dwellingIdx], town_1->numCreaturesInDwelling[dwellingIdx]);
}

void philAI_ValueOfBuyingCreature(town* town_1, int creatureId, float* creatureValue, int nCreaturesToBuy, float* creatureProfit)
{
  int nShootersInArmy = 0;
  int monsterCost[7];
  GetMonsterCost(creatureId, monsterCost);
  int costRV = nCreaturesToBuy * philAI_RVConversion((SBuildingCost*)monsterCost);
  float value = nCreaturesToBuy * gMonsterDatabase[creatureId].fight_value * gpCurPlayer->aiIncomeToFightValueRatio;

  // ���� � ����� �����
  hero* hero_1;
  if(town_1->visitingHeroIdx != -1)
  {
	hero_1 = (hero*)&gpGame->heroes[town_1->visitingHeroIdx];
    value = value * 1.1;
	// �� ����� � ���� ����� ������ ���� ����� ���������� �������� ����� �������
	// ��� ������ ��� �������������
	if(gMonsterDatabase[creatureId].faction == hero_1->factionID)
      value = value * 1.1;
    if(gMonsterDatabase[creatureId].creature_flags & SHOOTER)
    {
      for(int i = 0; i < 5; i++)
      {
		if(hero_1->army.creatureTypes[i] != -1)
        {
          if(gMonsterDatabase[hero_1->army.creatureTypes[i]].creature_flags & SHOOTER)
            nShootersInArmy++;
        }
      }
	  // ��� ������ � ����� ��������, ��� ������ value �������, �������� �� ����� ������
	  // �������� ������, ���� ����� ������ �� ������
      value = (1.18 - nShootersInArmy * 0.06) * value;
    }
	value = (gpGame->players[town_1->ownerIdx].aiTurnAttentionValueCreatures + 0.66) * value; // ��� ������ aiTurnAttentionValueCreatures ��� ����� ����� �����
  }

  if(gMonsterDatabase[creatureId].creature_flags & SHOOTER)
  {
    for(int j = 0; j < 5; j++)
    {
	  if(town_1->garrison.creatureTypes[j] != -1 && gMonsterDatabase[town_1->garrison.creatureTypes[j]].creature_flags & SHOOTER)
        nShootersInArmy++;
    }
	// �� ���� ���-�� ���������� ������� � ����� ����� ��� � ������������ � ���-��� ������� � ���������
	// ���� ������� �����-��. ����... �������� ��� ����� ��� ������ ��������. � �������� ��� ��� � �� �����
    value = (1.18 - nShootersInArmy * 0.06) * value;
  }
  float v19, v17, v14, v21;
  int v16, v13;
  // ��� ��������� �� ��������, ���� ������������ ����� "��������"
  // v21 �������� �������� 0.09 (��� ����� ����������� ��������� ����� �� �����)
  philAI_LikelihoodOfEnemyAttacking(town_1, 0, &v19, &v17, &v16, &v14, &v13, &v21);
  float likelihoodOfAttack = v21 + 0.96;
  // value ����� ������ ������� �� ����������� ����� ����������
  // � �� �� ����� �� ����� �������, ����� ��� �����, ���� �� ��� ��������� ���� aiInDanger,
  // �������, ������, �������� ���������� �������, � ������� �� ���������� philAI_LikelihoodOfEnemyAttacking
  value = likelihoodOfAttack * likelihoodOfAttack * likelihoodOfAttack * value;
  // ���� ���������� ������ ������� "����������"
  float deflator = philAI_FutureDeflator((SBuildingCost*)monsterCost);
  value = deflator * value;
  *creatureValue = value;
  *creatureProfit = *creatureValue / costRV;
}

void philAI_GetBestCreature(void* philAI_1, town* town_1, int* bhcData, float* bhcValue)
{
  int bestDwellingToBuy = -1;
  int bestNCreaturesToBuy = -1;
  float bestRandomizedProfit = -99.0;
  float bestProfit = -99.0;
  int creatureId;
  int minFightValue;
  bool isFreeSlot;
  int nCreaturesToBuy;
  float creatureProfit;
  float creatureRandomizedProfit;
  float creatureValue;

  for(int i = 0; i < 12; i++)
  {
	creatureId = gDwellingType[12*town_1->factionID + i];
    minFightValue = 999999;
	//���� ���� ���� ��������
	if ((1 << (i + 19)) & town_1->buildingsBuiltFlags && town_1->numCreaturesInDwelling[i] > 0)
    {
      isFreeSlot = 0;
      for(int j = 0; j < 5; j++)
      {
		if(town_1->garrison.creatureTypes[j] == -1
		|| town_1->garrison.creatureTypes[j] == creatureId)
          isFreeSlot = 1;
      }
      for(int j = 0; j < 5; j++)
      {
        if(town_1->garrison.creatureTypes[j] != -1 &&
		gMonsterDatabase[town_1->garrison.creatureTypes[j]].fight_value < minFightValue)
          minFightValue = gMonsterDatabase[town_1->garrison.creatureTypes[j]].fight_value;
      }
	  // ��������, ��������� �� ����������� ����������.
	  // �� ���� ����� ���� ������ ����� � ������� ���-��� �������, � �������
	  // ��������� fight_value
      if(gMonsterDatabase[creatureId].fight_value > minFightValue && gMonsterDatabase[creatureId].fight_value > 1000)
        isFreeSlot = 1;
	  // ���� � ����� ���� ����� � ��������� �������� ������,
	  // �� ������� 1-�� ������ �� �������� (���������)
	  if(!i && town_1->visitingHeroIdx != -1
        && (*(char*)((int)&town_1 + 27) & 0x10 // BUILDING_UPGRADE_4 == 1
         || *(char*)((int)&town_1 + 26) & 0x80 // BUILDING_UPGRADE_3 == 1
         || *(char*)((int)&town_1 + 27) & 0x20 // BUILDING_UPGRADE_5 == 1
         || *(char*)((int)&town_1 + 27) & 0x40 // BUILDING_UPGRADE_5B == 1
         || *(char*)((int)&town_1 + 27) & 1)) // BUILDING_DWELLING_6 == 1
        isFreeSlot = 0;
      if(isFreeSlot)
      {
        nCreaturesToBuy = philAI_CreaturesToBuy(philAI_1, town_1, i);
        if(nCreaturesToBuy > 0)
        {
          philAI_ValueOfBuyingCreature(town_1, creatureId, &creatureValue, nCreaturesToBuy, &creatureProfit);
          if(gpCurPlayer->personality == AI_WARRIOR)
            creatureValue = creatureValue * 1.3;
          // �������, � ���� ���� ������. �� ����� �� ��� �������� ������������ ������ ��� ����� ��� ?
		  // ��, ���. ������, ����� ������������ �� ��, ��� ��� GetBestBuilding -
		  // � ����� ����� �������� ��� bestProfit (� ��� ��������� �� 1.3 ����)
		  if(town_1->aiInDanger)
            creatureValue *= 2;
          creatureRandomizedProfit = (Random(1, 10) + 90) * creatureProfit / 100.0;

          if(creatureRandomizedProfit > bestRandomizedProfit)
          {
			bestDwellingToBuy = i;
			bestNCreaturesToBuy = nCreaturesToBuy;
            bestProfit = creatureProfit;
            bestRandomizedProfit = creatureRandomizedProfit;
          }
		}
	  }
	}
  }
  bhcData[0] = (int)town_1;
  bhcData[1] = 2;
  bhcData[2] = bestDwellingToBuy;
  bhcData[3] = nCreaturesToBuy;
  *bhcValue = bestProfit;

}

void philAI_ValueOfBuyingHero(town* town_1, hero* hero_1, float* heroValue, float* heroProfit)
{
  int heroCost[7];
  heroCost[1] = 0;
  heroCost[2] = 0;
  heroCost[3] = 0;
  heroCost[4] = 0;
  heroCost[5] = 0;
  heroCost[6] = 0;
  heroCost[7] = 2500;
  int costRV = philAI_RVConversion((SBuildingCost*)heroCost);
  float value = hero_1->experience + 2000;
  for(int i = 0; i < 14; i++)
  {
    // ������. ������ ���� 103 � �� 82
	if(hero_1->artifacts[i] >= 0 && hero_1->artifacts[i] < 82)
    {
	  // �����. ����� �� ���������. ���� ������ ���������� ��� ?
      if(hero_1->artifacts[i] != 81)
        heroValue += gArtifactBaseRV[hero_1->artifacts[i]];
    }
  }

  // aiTurnAttentionValueBuildings - ��� ��������, aiTurnAttentionValueCreatures - ��� �������, aiTurnAttentionValueHeroes - ��� ������
  value = (gpCurPlayer->aiTurnAttentionValueHeroes + 1.0 - gpCurPlayer->aiTurnAttentionValueCreatures)
                      * (hero_1->experience / 2 + value);

  bool isMagicHero = hero_1->factionID == FACTION_SORCERESS || hero_1->factionID == FACTION_WARLOCK ||
	  hero_1->factionID == FACTION_WIZARD || hero_1->factionID == FACTION_NECROMANCER;
  // ������, ��� � � ������ � �������� �������
  if(town_1->factionID == hero_1->factionID)
  {
    value = (0.16 + 1.0) * value;
  }
  // ����������� ���� ������� ������� � �����. ����� ���� ������ ������� � �����. �����
  // value �������� �����������
  else if((town_1->mageGuildLevel < 2 || !isMagicHero) && (town_1->mageGuildLevel >= 2 || isMagicHero))
  {
    value = ((1.0 - 0.16 / 2.0) * value);
  }
  // value �������� �������������
  else
  {
    value = ((0.16 / 2.0 + 1.0) * value);
  }

  value = philAI_FutureDeflator((SBuildingCost*)heroCost) * value;
  *heroProfit = value / costRV;
  *heroValue = value;

}

void philAI_GetBestHero(town* town_1, int* bhcData, float* bhcValue)
{
  int bestHero = -1;
  float bestRandomizedProfit = -99.0;
  float bestProfit = -99.0;
  hero* hero_1;
  float heroValue;
  float heroProfit;
  float heroRandomizedValue;
  float heroRandomizedProfit;

  // ����� �� 2-� ������ �� �������
  for(int i = 0; i < 2; i++)
  {
    hero_1 = &gpGame->heroes[gpCurPlayer->heroesForPurchase[i]];
    philAI_ValueOfBuyingHero(town_1, hero_1, &heroValue, &heroProfit);
    heroRandomizedProfit = (Random(1, 10) + 90.0) * heroProfit / 100.0;
    if(heroRandomizedProfit > bestRandomizedProfit)
    {
      bestHero = i;
      bestProfit = heroProfit;
      bestRandomizedProfit = heroRandomizedProfit;
    }
  }

  bhcData[0] = (int)town_1;
  bhcData[1] = 1;
  bhcData[2] = bestHero;
  *bhcValue = bestProfit;
  int tileIdx = town_1->x + gpGame->map.width * town_1->y;

  // ��� ��� �������� ? ���� � ����� ��� ���� �����, �� value �����������
  // � ����� ������ ����� ������ �����, ���� ��� �������� ��� ������ ?
  if ((gpGame->map.tiles[tileIdx].objType & (TILE_HAS_EVENT - 1))== LOCATION_HERO)
  {
    *bhcValue = *bhcValue - 200.0;
  }
}

void philAI_GetBestBHC(void* philAI_1, int playerIdx, int* bhcResults)
{
  float currentValue = 1.0;
  float bestValue = -99.0;
  int townsOverallValue = 0;
  int castlesFactor = 0;
  town* currentTown;

  int currentGarrisonValue;
  int townsValue[72];
  for(int i = 0; i < gpCurPlayer->numCastles; i++)
  {
    currentTown = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
    currentGarrisonValue = philAI_FightValueOfStack((armyGroup*)(&currentTown->garrison), 0, 0, 0, 0, 0);
    townsValue[i] = currentGarrisonValue + 400;
    townsOverallValue += townsValue[i];
    if(currentTown->buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
      castlesFactor += 10;
    else
      castlesFactor += 7;
  }
  if(castlesFactor < 1)
    castlesFactor = 1;
  int averageValuePerTown;
  averageValuePerTown = townsOverallValue / castlesFactor;

  int averageTownsValueWithCastleFactor[72];
  for(int i = 0; i < gpCurPlayer->numCastles; i++)
  {
    currentTown = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
	// ������ 400 ����� ������
	averageTownsValueWithCastleFactor[i] = averageValuePerTown * (currentTown->buildingsBuiltFlags & BUILDING_CASTLE_BUILT < 1 ? 7 : 10) + 400;
  }

  int bhcData[4];
  for(int i = 0; i < gpCurPlayer->numCastles; i++)
  {
    currentTown = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
	// field_55 - ������� ���� ����� ������ ������ ?
    if(giCurTurn <= 3 || currentTown->field_55 >= 3)
    {
	  // technical / graphical things
      CheckDoMain(0, 0);
      philAI_GetBestBuilding(philAI_1, currentTown, bhcData, &currentValue);
      currentValue = (100 - Random(0, 10)) / 100.0 * currentValue;
      if(currentValue > bestValue)
      {
        bestValue = currentValue;
        bhcResults[0] = bhcData[0];
        bhcResults[1] = bhcData[1];
        bhcResults[2] = bhcData[2];
        bhcResults[3] = bhcData[3];
      }
	  // technical / graphical things
      CheckDoMain(0, 0);
      philAI_GetBestCreature(philAI_1, currentTown, bhcData, &currentValue);
	  // ��� ������ ������ � ������ �����, ��� ������ ������ �������� ����� �������
      currentValue = (averageTownsValueWithCastleFactor[i] / townsValue[i] / 3.0 + 0.66) * currentValue;
      currentValue = (100 - Random(0, 10)) / 100.0 * currentValue;
      if(currentValue > bestValue)
      {
        bestValue = currentValue;
        bhcResults[0] = bhcData[0];
        bhcResults[1] = bhcData[1];
        bhcResults[2] = bhcData[2];
        bhcResults[3] = bhcData[3];
      }
      CheckDoMain(0, 0);
      if(gpCurPlayer->numHeroes < giMaxHeroesForThisPlayer && (currentTown->buildingsBuiltFlags & BUILDING_CASTLE_BUILT))
      {
        philAI_GetBestHero(currentTown, bhcData, &currentValue);
        currentValue = (100 - Random(0, 10)) / 100.0 * currentValue;
        if(bHeroBuiltThisTurn || giCurTurn <= 5 || currentValue <= 0.0)
        {
		  // ���� ��� ������ ��� ������������� ������� ����, ������� ���������� ������� �����
          if(!gpCurPlayer->numHeroes)
            currentValue = currentValue + 500.0;
        }
		// ���������� �������
        else if((gpCurPlayer->resourcesIncome[RESOURCE_GOLD] < 1250 || gpCurPlayer->numHeroes >= giMaxHeroesForThisPlayer - 2)
  && gpCurPlayer->numHeroes > 1)
        {
          if(gpCurPlayer->resourcesIncome[RESOURCE_GOLD] >= 1500 && gpCurPlayer->numHeroes < giMaxHeroesForThisPlayer - 1)
            currentValue = currentValue * 1.3;
        }
		// � ����� ������� ����������� �� 500, �� ����� �������
        else
        {
          currentValue = currentValue + 500.0;
        }
        if(bestValue < currentValue)
        {
          bestValue = currentValue;
          bhcResults[0] = bhcData[0];
          bhcResults[1] = bhcData[1];
          bhcResults[2] = bhcData[2];
          bhcResults[3] = bhcData[3];
        }
      }
    }
  }
  if(bestValue < 0.02)
    bhcResults[1] = -1;

}

// �������������� ������ � ��������, � ������� ��� �������� �������
int philAI_DoAllHeroInteractions(void* philAI_1)
{
  int nCastles;
  town* town_1;

  for(int i = 0; ;i++)
  {
    // ���. �������, ��� ����� ����� ������ - ���� ���.
    nCastles = gpCurPlayer->numCastles;
    if(i >= nCastles)
      break;
    if(gpGame->castles[gpCurPlayer->castlesOwned[i]].visitingHeroIdx != -1)
    {
      town_1 = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
      philAI_HeroInteractionAtTown(philAI_1, (hero*)&gpGame->heroes[gpGame->castles[gpCurPlayer->castlesOwned[i]].visitingHeroIdx], town_1, 0, &iDummy);
    }
  }
  return nCastles;
}

// �� ����� ��� �� ������ ��������, � ��� ������� ����� ����� ��������
int philAI_CheckForCreatureUpgrades()
{
  int creatureAfterUpgradeIdx = -1;
  int numCastles = gpCurPlayer->numCastles;
  town* town_1;
  armyGroup* army_1;

  int isUpgradePossible;
  int goldCost;
  int resourceIdx;
  int resourceCost;

  if(numCastles > 0)
  for(int townIdx = 0; townIdx < numCastles; townIdx++)
  {
	town_1 = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[townIdx]];
	for(int i = 0; ;i++)
	{
	  if(i <= 1)
	  {
		if(i == 1)
		{
		  if(town_1->visitingHeroIdx == -1 )
		    continue;
		  army_1 = (armyGroup*)&gpGame->heroes[town_1->visitingHeroIdx].army;
		}
		else
		{
		  army_1 = (armyGroup*)&town_1->garrison;
		}
		for(int j = 0; j < 5; j++)
		{
		  if(army_1->creatureTypes[j] != -1)
		  {
		    isUpgradePossible = false;
			for(int k = 0; k < 5; k++)
			{
			  if(gpCreatureUpgrades[town_1->factionID].baseCreature[k] == army_1->creatureTypes[j])
			  {
			    // 1 ���������� ����� �� k + BUILDING_UPGRADE_1
				if((1 << (k + BUILDING_UPGRADE_1)) & town_1->buildingsBuiltFlags)
				{
				  isUpgradePossible = true;
				  creatureAfterUpgradeIdx = army_1->creatureTypes[j] + 1;
				}
			  }
			}
			if(army_1->creatureTypes[j] == CREATURE_GREEN_DRAGON || army_1->creatureTypes[j] == CREATURE_RED_DRAGON
				&& town_1->buildingsBuiltFlags & BUILDING_UPGRADE_5B_BUILT)
			{
			  isUpgradePossible = true;
			  creatureAfterUpgradeIdx = CREATURE_BLACK_DRAGON;
			}
            if(isUpgradePossible)
            {
              goldCost = 2 * army_1->quantities[j] * (gMonsterDatabase[creatureAfterUpgradeIdx].cost
				- gMonsterDatabase[army_1->creatureTypes[j]].cost);
              if(creatureAfterUpgradeIdx == CREATURE_BLACK_DRAGON)
              {
                resourceIdx = RESOURCE_SULFUR;
                resourceCost = 2 * army_1->quantities[j];
              }
              else if(creatureAfterUpgradeIdx == CREATURE_TITAN)
              {
                resourceIdx = RESOURCE_GEMS;
                resourceCost = 2 * army_1->quantities[j];
              }
              else
              {
                resourceIdx = -1;
                resourceCost = 0;
              }
              if( gpCurPlayer->resources[RESOURCE_GOLD] >= goldCost &&
				(resourceIdx == -1 || gpCurPlayer->resources[resourceIdx] >= resourceCost) )
              {
                gpCurPlayer->resources[RESOURCE_GOLD] -= goldCost;
                if(resourceIdx != -1 )
                  gpCurPlayer->resources[resourceIdx] -= resourceCost;
                army_1->creatureTypes[j] = creatureAfterUpgradeIdx;

			    // ����������� � ��� ����������� � ���� �����
                for(int l = 0; l < 5; l++ )
                {
                  if( l != j && army_1->creatureTypes[l] == army_1->creatureTypes[j]
				    && army_1->quantities[l] > 0 )
                  {
                    army_1->quantities[l] += army_1->quantities[j];
                    army_1->quantities[j] = 0;
                    army_1->creatureTypes[j] = -1;
                  }
                }
			  }
            }
		  }
		}
	  }
	}
  }
  return numCastles; 
}

void philAI_CheckBuyStuff(void* philAI_1)
{
  int cannotBuy = false;
  int successfulBuy = false;
  game_CheckHeroConsistency(gpGame);
  if(gpCurPlayer->resources[RESOURCE_GOLD] >= 200 && (gpCurPlayer->resources[RESOURCE_GOLD] >= 2500 || gpCurPlayer->numHeroes))
  {
    town* townShipyard = 0;
	// ���� ��� ����� � ������
    if(giBuildShipyard[giCurPlayer] < 0)
    {
	  // �� ���� ����� � ������
      if(giBuildBoat[giCurPlayer] >= 0)
        townShipyard = (town*)&gpGame->castles[giBuildBoat[giCurPlayer]];
    }
	// ���� ���� ����� � ������
    else
    {
      townShipyard = (town*)&gpGame->castles[giBuildShipyard[giCurPlayer]];
    }
	// ���������� ����. �������. �����������
    //if(giBuildShipyard[giCurPlayer] < 0)
    //{
    //  if(giBuildBoat[giCurPlayer] >= 0)
    //    townShipyard = (town*)&gpGame->castles[giBuildBoat[giCurPlayer]];
    //}
    //else
    //{
    //  townShipyard = (town*)&gpGame->castles[giBuildShipyard[giCurPlayer]];
    //}
	// ����� ���������� �����

	// ���� ����� �������� �������� ??
    if(townShipyard && townShipyard->ownerIdx != giCurPlayer)
    {
      giBuildShipyard[giCurPlayer] = -1;
      giBuildBoat[giCurPlayer] = giBuildShipyard[giCurPlayer]; // ���� -1
      townShipyard = 0;
    }
	// ����� �������� ������... ��� �������� giBuildShipyard - ��� �����, ��� ����� ��������� �����
	// � giBuildBoat - �����, ��� ����� ��������� �����
    if(giBuildShipyard[giCurPlayer] >= 0)
    {
      if(CanBuy(townShipyard, BUILDING_DOCK) && CanBuild(townShipyard, BUILDING_DOCK))
      {
        philAI_BuildBuilding(townShipyard, BUILDING_DOCK);
        giBuildShipyard[giCurPlayer] = -1;
      }
	  // �� ����� ��� �� ? - ������, ��� �������������� ����� �� �����, ����� ������ �� ����
	  // �� ����� ������� � ������ �������
	  // ����� ��������, ����� �� ��� ������. �������, �� ���� �� ������ ����� ����� ������
	  // ������ ����� ����� ����� ���������, � ����� - ��� ? ����� ���-�� ����������� ����� � ����� ������
      else
      {
        gpCurPlayer->resources[RESOURCE_GOLD] -= 2000;
        gpCurPlayer->resources[RESOURCE_WOOD] -= 20;
      }
    }
    if(giBuildBoat[giCurPlayer] >= 0)
    {
      if(townShipyard->buildingsBuiltFlags & BUILDING_DOCK_BUILT && gpCurPlayer->resources[RESOURCE_GOLD] >= 1000
		&& gpCurPlayer->resources[RESOURCE_WOOD] >= 10)
      {
        if(game_GetBoatsBuilt(gpGame) < 48
          && !advManager_GetCell(gpAdvManager, townShipyard->boatX, townShipyard->boatY)->objType
          && game_CreateBoat(gpGame, townShipyard->boatX, townShipyard->boatY, 0) != -1 )
        {
          gpCurPlayer->resources[RESOURCE_GOLD] -= 1000;
          gpCurPlayer->resources[RESOURCE_WOOD] -= 10;
        }
        giBuildBoat[giCurPlayer] = -1;
      }
      else
      {
        gpCurPlayer->resources[RESOURCE_GOLD] -= 1000;
        gpCurPlayer->resources[RESOURCE_WOOD] -= 10;
      }
    }
    philAI_CheckForCreatureUpgrades();
    philAI_DoAllHeroInteractions(philAI_1);

	int bhcResults[4];
    while(!cannotBuy)
    {
      philAI_GetBestBHC(philAI_1, giCurPlayer, bhcResults);
      if(bhcResults[1] >= 0 && philAI_CanBuyBHC(bhcResults))
      {
        if(bhcResults[1])
        {
          if(bhcResults[1] == 1)
          {
            philAI_BuildHero(philAI_1, (town*)bhcResults[0], bhcResults[2]);
          }
          else if(bhcResults[1] == 2)
          {
            philAI_BuildCreature((town*)bhcResults[0], bhcResults[2], bhcResults[3]);
          }
        }
        else
        {
          philAI_BuildBuilding((town*)bhcResults[0], bhcResults[2]);
        }
        successfulBuy = true;
      }
      else
      {
        cannotBuy = true;
      }
    }
	// ���������� ����������������� ������. ����� ��� ������ �������� :)
    if(giBuildShipyard[giCurPlayer] >= 0)
    {
      gpCurPlayer->resources[RESOURCE_GOLD] += 2000;
      gpCurPlayer->resources[RESOURCE_WOOD] += 20;
    }
    if(giBuildBoat[giCurPlayer] >= 0)
    {
      gpCurPlayer->resources[RESOURCE_GOLD] += 1000;
      gpCurPlayer->resources[RESOURCE_WOOD] += 10;
    }
    philAI_DoAllHeroInteractions(philAI_1);
  }
}

int philAI_DetermineTargetPosition(void* phil_AI, int* x, int* y, int distance, int* bestDirectionFinal)
{
  int bestDirection;
  int result;
  int bestX;
  int bestY;
  int bestValue;

  int terrain;
  int reducedDistance;
  int twoFoldedDistance;

  pointInfo* pf;
  int rowCounter, colCounter;
  int minX, minY, maxX, maxY;
  int deltaX, deltaXY;
  int delta2_Y, delta2_XY;
  bool isImportant;
  mapCell* cell;

  int mobilityAfterVisit;
  int positionValue;
  int value;
  bool alreadyTargetedByAnotherHero;

  int dX_best;
  int dR_best;
  int dX_current;

  if(philAI_GoodAdjacent(phil_AI, &bestDirection))
  {
    *x = gpCurAIHero->x + normalDirTable[4 * bestDirection];
    *y = gpCurAIHero->y + normalDirTable[4 * bestDirection + 1];
    *bestDirectionFinal = bestDirection;
    result = 1000;
  }
  else
  {
    *bestDirectionFinal = -1;
    bestX = -1;
    bestY = -1;
    bestValue = -999999;
    giBestShipyardId = -1;
    gbPossibleShipyardFound = 0;
    gbActualShipyardFound = 0;
    gbActualBoatFound = 0;
    terrain = giGroundToTerrain[advManager_GetCell(gpAdvManager, gpCurAIHero->x, gpCurAIHero->y)->groundIndex];

	// ��, ��� ��� ���� �������� ������� ��������� ������ ������������� -
	// ��� ����� ������, � ��� ������ ����� Pathfinding ?
    if(gpCurAIHero->secondarySkillLevel[SECONDARY_SKILL_PATHFINDING] > 1)
    {
	  switch(gpGame->mapHeader.width)
      {
        case 36:
          distance = distance * 0.9;
          break;
        case 108:
          distance = distance * 1.05;
          break;
        case 144:
          distance = distance * 1.1;
          break;
      }
    }
    else
    {
      if(terrain == TERRAIN_IDX_SNOW || terrain == TERRAIN_IDX_SWAMP)
        distance = distance * 1.15;
      if(terrain == TERRAIN_IDX_DESERT)
        distance = distance * 1.35;
      if(terrain == TERRAIN_IDX_WASTELAND)
        distance = distance * 1.25;
    }
    if(gpCurPlayer->personality == AI_EXPLORER)
      distance = distance * 1.15;
    reducedDistance = distance / 100 / 4;
    if(reducedDistance < 6)
      reducedDistance = 6;
    twoFoldedDistance = 2 * distance;
    searchArray_SeedPosition(
      gpSearchArray,
      gpCurAIHero->x,
      gpCurAIHero->y,
      gpCurAIHero->directionFacing,
      2 * distance,
      gpCurAIHero->flags & HERO_AT_SEA,
      1,
      gpCurAIHero->remainingMobility,
      gpCurAIHero->secondarySkillLevel[SECONDARY_SKILL_PATHFINDING],
      -1,
	  -1,
      0,
      0);

    pf = (pointInfo*)&gpSearchArray->pointMap[gpCurAIHero->x + MAP_WIDTH * gpCurAIHero->y];
	// �������� ������� ��� - ����� �� ������� ����� ����� - �����������
    pf->field_4 &= 0xFEu;
    colCounter = -1;

	// ������ ������ ����� ������� � ����. ������ ������� 50
	// �� ������� ����� ������� �������� �� �����
	// (����� ����� ���������� �������� �������������)
    minX = gpCurAIHero->x - 25;
    if(minX < 0)
      minX = 0;
	minY = gpCurAIHero->y - 25;
    if(minY < 0)
      minY = 0;
    maxX = gpCurAIHero->x + 25;
	// ������, ������, ����� ������������ � MAP_WIDTH-1 � MAP_HEIGHT-1
	// ���� ����� �� �� ��� ������ � ����� ��� ������������ - ����� � ���
    if(MAP_WIDTH - 1 < maxX)
      maxX = MAP_WIDTH;
    maxY = gpCurAIHero->y + 25;
    if(MAP_HEIGHT - 1 < maxY)
      maxY = MAP_HEIGHT;

    for(int i = 0; ; i++)
    {
      if(i < 2)
      {
	    // ���� ����� �� ���� ��� ������ ������� �� ����������
        if(gpCurAIHero->flags & HERO_AT_SEA && !i)
          continue;
        for(int col = minX; col < maxX; col++)
        {
          rowCounter = -1;
          ++colCounter;
		  // ���������� ��� colCounter ��������� �������� �� 0 �� 5
		  // ���� reducedDistance = 6
          if(reducedDistance <= colCounter)
            colCounter = 0;
          for(int row = minY; row < maxY; ++row)
          {
            alreadyTargetedByAnotherHero = false;
            ++rowCounter;
		    // ���������� ��� rowCounter ��������� �������� �� 0 �� 5
		    // ���� reducedDistance = 6
            if(reducedDistance <= rowCounter)
              rowCounter = 0;
            if(gpSearchArray->pointMap[col + row * MAP_WIDTH].field_4 & 1)
            {
			  // � �������� ��� ������ �������, ��� ������� ������ � ���� ������ ��� i>0
              if(gpCurAIHero->flags & HERO_AT_SEA
			    // ���� ��� 2-� ������
                || ((deltaX = abs(col - gpCurAIHero->x), deltaXY = abs(row - gpCurAIHero->y) + deltaX, i)
				// �������� �� �����
                 || deltaXY <= 5
                 || gpCurAIHero->oldTargetX == col && gpCurAIHero->oldTargetY == row
                 || deltaXY < 16
                 && (advManager_GetCell(gpAdvManager, col, row)->objType == (LOCATION_HERO | TILE_HAS_EVENT)
                  || advManager_GetCell(gpAdvManager, col, row)->objType == (LOCATION_TOWN | TILE_HAS_EVENT)
                  && gpGame->castles[advManager_GetCell(gpAdvManager, col, row)->extraInfo].ownerIdx != giCurPlayer))
                && (i != 1 // ��� ������� �������
                 || deltaXY > 5
                 && (gpCurAIHero->oldTargetX != col || gpCurAIHero->oldTargetY != row)
                 && (deltaXY >= 16
                  || advManager_GetCell(gpAdvManager, col, row)->objType != (LOCATION_HERO | TILE_HAS_EVENT)
                  && (advManager_GetCell(gpAdvManager, col, row)->objType != (LOCATION_TOWN | TILE_HAS_EVENT)
                   || gpGame->castles[advManager_GetCell(gpAdvManager, col, row)->extraInfo].ownerIdx == giCurPlayer))))
              {
                cell = advManager_GetCell(gpAdvManager, col, row);
				// ���� ����� � �������� ��������� ������
                if(gpSearchArray->pointMap[col + row * MAP_WIDTH].distanceFromSourcePoint <= distance)
                {
                  isImportant = cell->objType & TILE_HAS_EVENT
                     || cell->objType == LOCATION_SHORE && gpCurAIHero->flags & HERO_AT_SEA
                     || !(col % reducedDistance)
                     && !(row % reducedDistance)
                     && (gpCurAIHero->flags & TILE_HAS_EVENT && !giGroundToTerrain[cell->groundIndex]
                      || !(gpCurAIHero->flags & TILE_HAS_EVENT) && giGroundToTerrain[cell->groundIndex])
                     || gpCurPlayer->aiProbableUltimateArtifactX == col && gpCurPlayer->aiProbableUltimateArtifactY == row;
                }
                else if(gpSearchArray->pointMap[col + row * MAP_WIDTH].distanceFromSourcePoint <= twoFoldedDistance)
                {
                  isImportant = cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT)
                     || cell->objType == (LOCATION_HERO | TILE_HAS_EVENT)
                     || cell->objType == (LOCATION_BOAT | TILE_HAS_EVENT) && !(gpCurAIHero->flags & HERO_AT_SEA);
                }
                else
                {
                  isImportant = 0;
                }
                if(isImportant)
                {
                  if(gpCurAIHero->patrolX != -1)
                  {
                    delta2_Y = abs(row - gpCurAIHero->patrolY);
                    delta2_XY = abs(col - gpCurAIHero->patrolX) + delta2_Y;
					// ���� ������� ������, �� - ���
                    if(gpCurAIHero->patrolDistance < delta2_Y)
                      isImportant = 0;
                  }
                }
                if(isImportant)
                {
                  for(int j = 0; j < gpCurPlayer->numHeroes; j++)
                  {
                    if(cell->objType != (LOCATION_TOWN | TILE_HAS_EVENT)
                      && cell->objType != (LOCATION_HERO | TILE_HAS_EVENT)
                      && gpCurPlayer->heroesOwned[j] != gpCurAIHero->idx
                      && gpGame->heroes[gpCurPlayer->heroesOwned[j]].oldTargetX == col
                      && gpGame->heroes[gpCurPlayer->heroesOwned[j]].oldTargetY == row)
                    {
                      value = -2000;
                      alreadyTargetedByAnotherHero = true;
					  break;
                    }
                  }

				  if(alreadyTargetedByAnotherHero == false)
				  {
					  CheckDoMain(0, 0);
					  mobilityAfterVisit = gpCurAIHero->mobility
						  - gpSearchArray->pointMap[col + row * MAP_WIDTH].distanceFromSourcePoint;
					  if(mobilityAfterVisit < 0)
						mobilityAfterVisit = 0;
					  positionValue = philAI_RVOfPosition(
							 phil_AI,
							 col,
							 row,
							 // ����� ����������� 3-� ��� (���� ������� �� ������� � �������� � 1 � �� 0)
							 // ������������� arg8 � philAI_RVOfPosition (� ������ � philAI_RVOfPosition
							 // ��� ���������� ���� a7)
							 // ���� ���� � ����� ������������� ������ �� ���� �� A � B
							 ((gpSearchArray->pointMap[col + row * MAP_WIDTH].field_4 >> 2) & 1),
							 // ������ field_5 - ��� 4 ���� � x � y ���� ������������� �����
							 gpSearchArray->pointMap[col + row * MAP_WIDTH].xDanger,
							 gpSearchArray->pointMap[col + row * MAP_WIDTH].yDanger,
							 ((gpSearchArray->pointMap[col + row * MAP_WIDTH].field_4 >> 3) & 1),
							 gpSearchArray->pointMap[col + row * MAP_WIDTH].xFirstDayStop,
							 gpSearchArray->pointMap[col + row * MAP_WIDTH].yFirstDayStop,
							 ORDINARY_ESTIMATION,
							 gpCurAIHero->remainingMobility);
					  // ������� �������� �������, ���� � �������
					  value = positionValue * (Random(1, 50) + 75) / 100;
				      if(*x == col && *y == row )
                      value = value * 1.5 + 20;
				  }
				}
                else
                {
                  value = -100;
				  if(*x == col && *y == row)
                  value = value * 1.5 + 20;
                }

                if(bestValue >= value)
                {
                  if(bestValue == value)
                  {
                    if(!value)
                    {
                      if(!(advManager_GetCell(gpAdvManager, col, row)->objType & TILE_HAS_EVENT))
                      {
                        if(advManager_GetCell(gpAdvManager, bestX, bestY)->objType & TILE_HAS_EVENT
                          || (dX_best = abs(bestX - gpCurAIHero->x),
                              dR_best = abs(bestY - gpCurAIHero->y) + dX_best,
                              dX_current = abs(col - gpCurAIHero->x),
                              dR_best < abs(row - gpCurAIHero->y) + dX_current))
                        {
                          bestX = col;
                          bestY = row;
                        }
                      }
                    }
                  }
                }
                else
                {
                  bestX = col;
                  bestY = row;
                  bestValue = value;
                }
              }
            }
          }
        }
        if(i || bestValue <= 150)
          continue;
      }
      break;
    }
    if(bestValue < 75 && (gbPossibleShipyardFound || gbActualShipyardFound) && !gbActualBoatFound && giCurTurn > 3)
    {
      if((gbActualShipyardFound || giBuildShipyard[giCurPlayer] < 0 || giBuildShipyard[giCurPlayer] == giBestShipyardId)
        && gpCurPlayer->resources[RESOURCE_WOOD] + 6 * gpCurPlayer->resourcesIncome[RESOURCE_WOOD] >= ((unsigned int)gbActualShipyardFound < 1 ? 30 : 10))
      {
        if (!gbActualShipyardFound)
          giBuildShipyard[giCurPlayer] = giBestShipyardId;
        giBuildBoat[giCurPlayer] = giBestShipyardId;
        giBuildBoatStuffTurn[giCurPlayer] = giCurTurn;
        bestValue = 123;
        bestX = gpGame->castles[giBestShipyardId].x;
        bestY = gpGame->castles[giBestShipyardId].y;
        if ( gpCurAIHero->x == bestX && gpCurAIHero->y == bestY)
          gpCurAIHero->remainingMobility = 0;
      }
      philAI_CheckBuyStuff(phil_AI);
    }
    *x = bestX;
    *y = bestY;
    if(gpCurAIHero->patrolX != -1 && bestValue <= 0)
    {
      *x = gpCurAIHero->patrolX;
      *y = gpCurAIHero->patrolY;
    }
    result = bestValue;
  }
  return result;
}

int philAI_QuickCombat(armyGroup* armyGroupA, hero* heroA, armyGroup* armyGroupD, hero* heroD,
	int isSiegeBattle, int castleIndex, float* casualtiesA, float* casualtiesD)
{
  int experienceValueForDefender = game_ExperienceValueOfStack(armyGroupA, heroA);
  if (isSiegeBattle)
      experienceValueForDefender += 500; // ��� - ��� ����� ��������� � experienceValueForAttacker 

  int experienceValueForAttacker = game_ExperienceValueOfStack(armyGroupD, heroD);

  experienceValueForDefender = ((float)(gpGame->difficulty * 0.12 + 1.0) * (float)experienceValueForDefender);
  experienceValueForAttacker = ((float)(gpGame->difficulty * 0.12 + 1.0) * (float)experienceValueForAttacker);

  int isAttackerWin = false;
  armyGroup* armyWinner = 0;

  int ownerD;
  if(heroD)
	  ownerD = heroD->ownerIdx;
  else
	  ownerD = -1;

  float probWinnerA;
  int probableApproxCasualtiesA;
  int probableApproxCasualtiesD;
  int probablePreciseCasualtiesA;
  int probablePreciseCasualtiesD;
  int adjustedProfitA;

  philAI_ProbableOutcomeOfBattle(armyGroupA, heroA, armyGroupD,  heroD, 0, isSiegeBattle, castleIndex,
      ownerD, &probWinnerA, &probableApproxCasualtiesA, &probableApproxCasualtiesD,
	  &probablePreciseCasualtiesA, &probablePreciseCasualtiesD, &adjustedProfitA);

  float probWinnerD = (float)Random(0, 100) / 100.0;
  float winningDegree;

  if ( probWinnerD >= probWinnerA )
  {
    winningDegree = 1.0 - probWinnerA;
    armyWinner = armyGroupD;
  }
  else
  {
    isAttackerWin = true;
    winningDegree = probWinnerA;
    armyWinner = armyGroupA;
  }

  float probDelta;
  if(probWinnerA >= probWinnerD)
    probDelta = probWinnerA - probWinnerD;
  else
    probDelta = probWinnerD - probWinnerA;

  if(isAttackerWin && probWinnerA > 0.6)
    probDelta = (probWinnerA + 0.65) * probDelta;
  if(probDelta > 1.0)
    probDelta = 1.0;
  float casualties = (1.0 - probDelta) * (1.0 - probDelta);

  if(winningDegree > 0.8 && casualties > 0.2)
    casualties = casualties * casualties;
  if(winningDegree > 0.96 && (1.0 - winningDegree) / 2.0 < casualties)
    casualties = (1.0 - winningDegree) / 2.0;
  if(casualties > 0.6 && casualties < 0.99)
    casualties = casualties - 0.1;

  if(isAttackerWin)
  {
    if(heroA) // ������ ��������, ��� ��������� ������� ������ ����� �����
    {
      advManager_GiveExperience((hero*)heroA, experienceValueForAttacker, 1);
      hero_ApplyBattleWinTemps((hero*)heroA);
    }
    hero_CheckLevel((hero*)heroA);
    *casualtiesD = 1.0;
    *casualtiesA = casualties;

	// � ��� hero_ApplyBattleLossTemps ��� heroD ??
	// �������, � ����� ������ ������� hero_ApplyBattleWinTemps �����������
	// � ����� �������� ���������
  }
  else
  {
    if(heroA) // ������ ��������
    {
	  heroA->remainingMobility = 0;
      hero_ApplyBattleLossTemps((hero*)heroA);
    }
    if(heroD)
      hero_ApplyBattleWinTemps((hero*)heroA); // ������, ����� � ���� heroD
    *casualtiesD = casualties;
    *casualtiesA = 1.0;
    if(*casualtiesA >= 0.99 && heroD)
    {
      advManager_GiveExperience(heroD, experienceValueForAttacker, 1); // ������, � ���� experienceValueForDefender
      hero_CheckLevel(heroD);
    }
  }

  int attackerQuantity = 0;
  int defenderQuantity = 0;

  for (int i = 0; i < 5; i++ )
  {
	if(heroA->army.creatureTypes[i] != -1)
		attackerQuantity += heroA->army.quantities[i];
    if(heroD) // ������ - ���-�� ����� ������� � ��� ���������
    {
		if(heroD->army.creatureTypes[i] != -1)
			defenderQuantity += heroD->army.quantities[i];
    }
  }

  gbRetreatWin = 0;
  if((isAttackerWin == false || heroD) && Random(0, 100) < 60)
    gbRetreatWin = 1;
  if(!gbRetreatWin )
  {
    if(*casualtiesA <= 0.99 )
    {
      if(*casualtiesD > 0.99 )
        advManager_TransferArtifacts(heroD, heroA);
    }
    else
    {
      advManager_TransferArtifacts(heroA, heroD);
    }
  }

  philAI_DamageGroup(armyGroupA, heroA, heroD, *casualtiesA);
  philAI_DamageGroup(armyGroupD, heroD, heroA, *casualtiesD);

  if(isAttackerWin && hero_GetSSLevel(heroA, SECONDARY_SKILL_NECROMANCY))
  {
    int necroLevel = hero_GetSSLevel(heroA, SECONDARY_SKILL_NECROMANCY);
    unsigned short quantity = ((float)necroLevel * (float)defenderQuantity * 0.12);
    if(quantity <= 0)
      quantity = 1;
	armyGroup_Add((armyGroup*)&heroA->army, CREATURE_SKELETON, quantity, -1);
  }
  else if(heroD && *casualtiesD <= 0.999 && hero_GetSSLevel(heroD, SECONDARY_SKILL_NECROMANCY) )
  {
    int necroLevel = hero_GetSSLevel(heroD, SECONDARY_SKILL_NECROMANCY);
    unsigned short quantity = ((float)necroLevel * (float)attackerQuantity * 0.12);
    if(quantity <= 0 )
      quantity = 1;
    armyGroup_Add((armyGroup*)&heroD->army, CREATURE_SKELETON, quantity, -1);
  }

  hero* heroWinner;
  hero* heroLoser;

  if(isAttackerWin)
  {
    heroLoser = heroD;
	heroWinner = heroA;
  }
  else if(*casualtiesD <= 0.999 )
  {
    heroLoser = heroA;
	heroWinner = heroD;
  }

  // ��� - Eagle Eye ����� ��������� � heroWinner
  if(heroLoser && heroLoser->secondarySkillLevel[SECONDARY_SKILL_EAGLE_EYE] && heroWinner)
  {
    for(int spell = 0; spell < 65; spell++ )
    {
      if(hero_HasSpell(heroLoser, spell)
        && !hero_HasSpell(heroWinner, spell)
		&& gsSpellInfo[spell].level <= heroWinner->secondarySkillLevel[SECONDARY_SKILL_EAGLE_EYE] + 1
        && gsSpellInfo[spell].attributes & ATTR_COMBAT_SPELL)
      {
        heroWinner->spellsLearned[spell] = 1;
        break;
      }
    }
  }

  hero_ApplyBattleWinTemps(heroA);
  if(heroD)
    hero_ApplyBattleWinTemps(heroD);
  if(isAttackerWin && isSiegeBattle)
    game_ClaimTown(gpGame, castleIndex, giCurPlayer, 0);
  gbRetreatWin = 0;
  return isAttackerWin;

}

bool philAI_CombatMonsterEvent(hero* hero_1, char creatureId, int* nCreatures, mapCell* cell)
{
  float casualtiesA;	
  float casualtiesD;
  BOOL isAttackerWin;
  
  memset(gpMonGroup, -1, 5);
  memset(gpMonGroup->quantities, 0, 10);
  if(*nCreatures / 5 > 0 )
  {
    for(int i = 0; i < 5; i++)
    {
      gpMonGroup->creatureTypes[i] = creatureId;
      gpMonGroup->quantities[i] = *nCreatures / 5;
    }
  }
  for(int j = *nCreatures % 5 - 1; j >= 0; j--)
  {
    gpMonGroup->creatureTypes[j] = creatureId;
    ++gpMonGroup->quantities[j];
  }

  isAttackerWin = philAI_QuickCombat(&hero_1->army, hero_1, gpMonGroup, 0, 0, 0, &casualtiesA, &casualtiesD);
  for(int k = 0; k < 5; k++)
    *nCreatures += gpMonGroup->quantities[k];

  return isAttackerWin != 0;
}

// ��� ��������� ��� �������� �����
void philAI_CheckReload()
{
  gbTroopReload = 0;
  fReduceFactor = 1.0;
  float selfRelativeStrength = 0.0;
  float enemyRelativeStrength = 0.0;
  int enemyHeroArmyValue;
  int heroArmyValue = philAI_FightValueOfStack(&gpCurAIHero->army, gpCurAIHero, 0, 0, 0, 0);
  if(heroArmyValue < 100)
    heroArmyValue = 100;
  searchArray_SeedPosition(
    gpSearchArray,
    gpCurAIHero->x,
    gpCurAIHero->y,
    gpCurAIHero->directionFacing,
    4 * gpCurAIHero->mobility,
    gpCurAIHero->flags & HERO_AT_SEA,
    0,
    gpCurAIHero->remainingMobility,
    gpCurAIHero->secondarySkillLevel[SECONDARY_SKILL_PATHFINDING],
    -1,
	-1,
    0,
    0);

  mapCell* cell;
  int townGarrisonValue;
  for(int col = 0; col < MAP_WIDTH; col++)
  {
    for(int row = 0; row < MAP_HEIGHT; row++)
    {
      if(gpSearchArray->pointMap[col + MAP_WIDTH * row].field_4 & 1)
      {
        cell = advManager_GetCell(gpAdvManager, col, row);
		if(cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT))
        {
          townGarrisonValue = philAI_FightValueOfStack(
                 &gpGame->castles[cell->extraInfo].garrison,
                 0,
                 0,
                 0,
                 0,
                 0);
		  // ���� ���� �����
          if(gpGame->townOwner[cell->extraInfo] == gpCurAIHero->ownerIdx )
          {
		    // distanceFromSourcePoint - distance from hero to map cell ??
		    // selfRelativeStrength ��� ������, ��� ������ ����� � ������ � ��� ����� ���� ����� � ������
		    // ��� ������ ������������ ������
            if(2 * heroArmyValue < townGarrisonValue)
              selfRelativeStrength = ((double)townGarrisonValue / (double)(2 * heroArmyValue) - 1.0)
                 * (double)(gpCurAIHero->mobility + 10)
                 / (double)(gpSearchArray->pointMap[col + MAP_WIDTH * row].distanceFromSourcePoint + 10)
                 + selfRelativeStrength;
          }
		  // ���� ����� �����
          else if(heroArmyValue/2 < townGarrisonValue)
          {
		    // ��� ������ enemyRelativeStrength, ��� ������ ������������ ������
            enemyRelativeStrength = ((double)townGarrisonValue / (double)(heroArmyValue/2) - 1.0)
               * (double)(gpCurAIHero->mobility + 30)
               / (double)(gpSearchArray->pointMap[col + MAP_WIDTH * row].distanceFromSourcePoint + 30)
               + enemyRelativeStrength;
          }
        }
		// ���� ����� �����
        else if((cell->objType == (LOCATION_HERO | TILE_HAS_EVENT))
		&& gpGame->heroOwner[cell->extraInfo] != gpCurAIHero->ownerIdx)
        {
          enemyHeroArmyValue = philAI_FightValueOfStack(
                 &gpGame->heroes[cell->extraInfo].army,
                 0,
                 0,
                 0,
                 0,
                 0);
		  // ��� ������ enemyRelativeStrength, ��� ������ ������������ ����. �����
          if(heroArmyValue/2 < enemyHeroArmyValue)
            enemyRelativeStrength = ((double)enemyHeroArmyValue / (double)(heroArmyValue/2) - 1.0)
               * (double)(gpCurAIHero->mobility + 30)
               / (double)(gpSearchArray->pointMap[col + MAP_WIDTH * row].distanceFromSourcePoint + 30)
               + enemyRelativeStrength;
        }
	  }
	}
  }
  // selfRelativeStrength � enemyRelativeStrengt ��������� �������������� �� ������ �������� ����� (������� � ������)
  //- �� ��������� � ������ �������� �����

  // ��� ������ fReduceFactor, ��� ������ ����� �� ��������� � ������ �������� �����
  if(selfRelativeStrength > 1.0 && enemyRelativeStrength > 1.0)
  {
    fReduceFactor = 3.0 / (selfRelativeStrength + enemyRelativeStrength + 2.0);
    gbTroopReload = 1;
  }
}

void philAI_CheckBerserk()
{
  int maxValue = -1;
  gbBerserk = 0;
  fBerserkFactor = 1.0;
  int heroArmyValue;
  int enemyHeroArmyValue;
  int townGarrisonValue;
  heroArmyValue = philAI_FightValueOfStack(&gpCurAIHero->army, gpCurAIHero, 1, 0, 0, 0);
  playerData* pCurrentPlayer = gpCurPlayer;
  mapCell* cell;

  // ���� AI Warrior
  if(!gpCurPlayer->personality)
  {
    heroArmyValue = heroArmyValue * 1.15;
  }
  if(heroArmyValue < 100)
    heroArmyValue = 100;
  if(heroArmyValue >= 30000)
  {
    for(int col = 0; col < MAP_WIDTH; col++)
    {
      for(int row = 0; row < MAP_HEIGHT; row++)
      {
        cell = advManager_GetCell(gpAdvManager, col, row);
        if(cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT))
        {
          if(gpGame->townOwner[cell->extraInfo] != gpCurAIHero->ownerIdx
            && gpGame->townOwner[cell->extraInfo] != -1 )
          {
            townGarrisonValue = philAI_FightValueOfStack(
                   &gpGame->castles[cell->extraInfo].garrison,
                   0,
                   1,
                   1,
                   cell->extraInfo,
                   0);
            if(townGarrisonValue > heroArmyValue)
              return;
            if(heroArmyValue < townGarrisonValue)
              maxValue = townGarrisonValue;
          }
        }
        else if(cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT) &&
        gpGame->heroOwner[cell->extraInfo] != gpCurAIHero->ownerIdx )
        {
          enemyHeroArmyValue = philAI_FightValueOfStack(
                          &gpGame->heroes[cell->extraInfo].army,
                          0,
                          1,
                          gpGame->heroes[cell->extraInfo].occupiedObjType == (LOCATION_TOWN | 128),
                          gpGame->heroes[cell->extraInfo].occupiedObjVal,
                          0);
          if(enemyHeroArmyValue > heroArmyValue)
            return;
          if(2 * enemyHeroArmyValue > maxValue)
            maxValue = 2 * enemyHeroArmyValue;
        }
      }
    }
	// ��� ������ fBerserkFactor, ��� ������ ����� �� ��������� � 1 ������ �������� ������� �����
	// (������ ��� �����)
    if(maxValue > 0)
    {
      fBerserkFactor = (float)maxValue * 0.75 / (float)heroArmyValue;
      gbBerserk = 1;
    }
  }
  // ���� �����-�� ������ ������� ������ �����, �� ���������� ������� �� �������
  // gbBerserk �������� 0, fBerserkFactor �������� 1.0
  // � ���� ������ ������� �� ���������, �� �������� gbBerserk = 1 � fBerserkFactor
  // ������ 1.0
}

void philAI_DimensionDoorTo(int x, int y)
{
  advManager_TeleportTo(gpAdvManager, gpCurAIHero, x, y, 0, 0);
  if(gpCurAIHero->remainingMobility >= 225)
    gpCurAIHero->remainingMobility -= 225;
  else
    gpCurAIHero->remainingMobility = 0;
  hero_UseSpell(gpCurAIHero, SPELL_DIMENSION_DOOR);
}

int philAI_DoAnywhereDDoorTownGate(void* philAI_1, int positionValue)
{
  int result;
  int xMaxValue;
  int yMaxValue;
  int positionValueDD;
  int maxPositionValueDD;
  mapCell* cell;
  mapCell* newCell;
  int x;
  int y;
  int* pX;
  int* pY;

  if(gpCurAIHero->flags & HERO_AT_SEA)
  {
    result = false;
  }
  else
  {
    yMaxValue = -1;
    if(positionValue <= 25)
      maxPositionValueDD = Random(0, 125) - 50;
    else
      maxPositionValueDD = positionValue + 1000;
    if(!hero_HasSpell(gpCurAIHero, SPELL_DIMENSION_DOOR) || gpCurAIHero->spellpoints < 30)
      return 0;
    for(int col = 0; col < MAP_WIDTH; col++)
    {
      for(int row = 0; row < MAP_HEIGHT; row++)
      {
	    // ���� ����� �� ����� ���������, � �������� �������� DD � ������� �� ������� ����������
        if(!(gpSearchArray->pointMap[col + MAP_WIDTH * row].field_4 & 1)
          && abs(col - gpCurAIHero->x) <= 7
          && abs(row - gpCurAIHero->y) <= 7
          && (gpCurAIHero->x != col || gpCurAIHero->y != row))
        {
          cell = advManager_GetCell(gpAdvManager, col, row);
		  // groundIndex 0 - ��� ����
          if(giGroundToTerrain[cell->groundIndex] && ((cell->objType & TILE_HAS_EVENT) || (positionValue < 25 && Random(0, 10) < 2)))
          {
            positionValueDD = Random(0, 30) + philAI_RVOfPosition(philAI_1, col, row, 0, -1, -1, 0, -1, -1, 2, gpCurAIHero->remainingMobility);
            if(maxPositionValueDD < positionValueDD)
            {
			  // ���� ���� �� ��� 1-� �� 3-� �������� ����� ���������� ���, ��� ����
			  // �� maxPositionValueDD ������ �������� positionValueDD
			  // � ���������� ��� DD - ���������� ����� �� ���� 3-� ����� (� �� col, row)
              for(int i = 0; i < 3; i++)
              {
                if(i)
                {
                  if(i == 1) // ����
                  {
                    x = col;
                    y = row + 1;
                  }
                  else // i == 2 ������
                  {
                    x = col + 1;
                    y = row;
                  }
                }
                else // i == 0 �����
                {
                  x = col - 1;
                  y = row;
                }
                if (!(gpSearchArray->pointMap[x + MAP_WIDTH * y].field_4 & 1)
                  && (gpCurAIHero->x != x || gpCurAIHero->y != y))
                {
                  if(x >= 0 && x <= MAP_WIDTH - 1)
                  {
				    if(y >= 0 && y <= MAP_HEIGHT - 1)
					{
					  // ���� ����� �� ����� �������� ��������
                      if(!advManager_FindAdjacentMonster(gpAdvManager, x, y, pX, pY, -1, -1) )
                      {
                        newCell = advManager_GetCell(gpAdvManager, x, y);
                        if(giGroundToTerrain[newCell->groundIndex])
                        {
						  // 4-� ��� (������� ����� � ������ 1)
                          if(!(newCell->flags & 8)
                            && !(newCell->objType & TILE_HAS_EVENT)
							// 8-� ��� (���������, �������)
                            && (newCell->objectIndex == 255 || newCell->flags & 0x80))
                          {
                            xMaxValue = x;
                            yMaxValue = y;
                            maxPositionValueDD = positionValueDD;
                          }
                        }
                      }
					}
				  }
				}
			  }
			}
		  }
		}
	  }
	}
	if(yMaxValue != -1)
	{
	  philAI_DimensionDoorTo(xMaxValue, yMaxValue);
	  result = true;
	}
	else
	{
	  result = false;
	}
  }
  return result;
}

int philAI_DoDimensionDoor(hero* hero_1)
{
  int result;
  if(hero_1->remainingMobility >= 75)
  {
    int yDD = -1;
	int xDD;
    int col = hero_1->x;
    int row = hero_1->y;
	mapCell* cell;
	int someIdx;

    for(int i = gpSearchArray->nSteps - 1; i >= 1; i--)
    {
      col += normalDirTable[4 * gpSearchArray->directionToTarget[i]];
      row += normalDirTable[4 * gpSearchArray->directionToTarget[i] + 1];
      if(abs(col - hero_1->x) <= 7)
      {
        if(abs(row - hero_1->y) <= 7)
        {
          cell = advManager_GetCell(gpAdvManager, col, row);
          if(!(cell->objType & TILE_HAS_EVENT))
          {
            if(!(cell->flags & 8))
            {
              yDD = col;
              xDD = row;
              someIdx = gpSearchArray->nSteps - i;
            }
          }
        }
	  }
	}
	// ����� for someIdx = gpSearchArray->nSteps - 1
    if(yDD != -1 && someIdx > 5)
    {
      philAI_DimensionDoorTo(xDD, yDD);
      result = true;
    }
    else
    {
      result = false;
    }
  }
  else
  {
    result = false;
  }
  return result;
}

void philAI_IncrementHourGlass()
{
  int numHeroes = gpCurPlayer->numHeroes;
  // ��� ��� �������
  if(numHeroes < 4)
  {
    if(gpCurPlayer->resources[RESOURCE_GOLD] >= 2500 )
    {
      if(!bHeroBuiltThisTurn)
        numHeroes++;
    }
  }
  iCurHourGlassPhase = iCurHourGlassPhase + 1;
  // �� ���� �� ���� +2
  if(numHeroes == 1)
  {
    iCurHourGlassPhase = iCurHourGlassPhase + 1;
    iCurHourGlassPhase = iCurHourGlassPhase + 1;
  }
  if(numHeroes == 2 && iCurHourGlassPhase != 1)
    iCurHourGlassPhase = iCurHourGlassPhase + 1;
  if(numHeroes == 3 && (iCurHourGlassPhase == 3 || iCurHourGlassPhase == 6))
    iCurHourGlassPhase = iCurHourGlassPhase + 1;
  if(iCurHourGlassPhase > 9)
    iCurHourGlassPhase = 9;

  // � �����, ��� ������ ������, ��� ������ iCurHourGlassPhase - ������, �� ����� ������ ��� �������
}

// ������� ������� �� ����� � ������������ ������� ��������
// �������� ������ �� ������ ������ �  ����� ������ ������
// ����� ��� ����� �������� ������ ����� ������� ������
// ������ ���� ����������� ��� ��� ����� ������ ����� �������� ���������
// � ������������ ����� ������� ������
hero* philAI_DetermineHeroToMove(int playerIdx)
{
  hero* result;
  int maxMobility = 0;
  int mobiledHero = -1;
  if(playerData_HasMobileHero(gpCurPlayer))
  {
    for(int i = 0; i < gpCurPlayer->numHeroes; i++)
    {
	  if(gpGame->heroes[gpGame->players[playerIdx].heroesOwned[i]].remainingMobility > maxMobility)
      {
        maxMobility = gpGame->heroes[gpGame->players[playerIdx].heroesOwned[i]].remainingMobility;
        mobiledHero = i;
      }
    }
  }
  if(mobiledHero < 0)
  {
    gpGame->players[playerIdx].curHeroIdx = -1;
    result = 0;
  }
  else
  {
    result = &gpGame->heroes[gpGame->players[playerIdx].heroesOwned[mobiledHero]];
  }
  return result;
}

// ������������ �� ���-�� ��� �������� ? ����� ��� ��� ����� ���������������� � philAI_GetTurnAttentionValue
// ������ aiGameAttentionValueBuildings � aiGameAttentionValueCreatures - ���������, � ������������� ������ aiGameAttentionValueHeroes
void* philAI_GetGameAttentionValue(int playerIndex)
{

  void* pAiParam = (void*)&gpGame->players[playerIndex].aiGameAttentionValueBuildings;
  gpGame->players[playerIndex].aiGameAttentionValueBuildings = Random(0, 100) / 500.0 + 0.23;
  gpGame->players[playerIndex].aiGameAttentionValueHeroes = Random(0, 100) / 500.0 + 0.23;

  //gpGame->players[playerIndex].aiGameAttentionValueHeroes = (1.0 + 3.0) / 4.0 * gpGame->players[playerIndex].aiGameAttentionValueHeroes;
  //gpGame->players[playerIndex].aiGameAttentionValueHeroes = (5.0 - 1.0) / 4.0 * gpGame->players[playerIndex].aiGameAttentionValueHeroes;
  //gpGame->players[playerIndex].aiGameAttentionValueBuildings = (1.0 + 3.0) / 4.0 * gpGame->players[playerIndex].aiGameAttentionValueBuildings;

  // ��� ������ �������, ��� ������ aiGameAttentionValueBuildings � aiGameAttentionValueHeroes � ��� ������ aiGameAttentionValueCreatures
  // ��� ������ - ��� ������ �������, ��� ������ �����
  gpGame->players[playerIndex].aiGameAttentionValueHeroes = ((3.0 - gpGame->numPlayers) * 0.15 + 1.0) * gpGame->players[playerIndex].aiGameAttentionValueHeroes;
  // ��� �������� - ��� ������ �������, ��� ������ ���������
  gpGame->players[playerIndex].aiGameAttentionValueBuildings = ((3.0 - gpGame->numPlayers) * 0.07 + 1.0) * gpGame->players[playerIndex].aiGameAttentionValueBuildings;
  // ��� ������� - ��� ������ �������, ��� ������ ��������
  gpGame->players[playerIndex].aiGameAttentionValueCreatures = 1.0 - gpGame->players[playerIndex].aiGameAttentionValueHeroes - gpGame->players[playerIndex].aiGameAttentionValueBuildings;

  return pAiParam;
}

// �� ����� ���� ��� ��� ��������� ������ �� ������������� � �� ������������
// �� � ��� �� ����������, ���� ��� ��������������:
// - ����� ��������� ����� �����, ��� �������� ����� �������, ����� �������� ����� ��� ���������, ����� �����
// ��� �������� �� �������� � �� ���������
// - ��������� ���������� �������
// - �������� �������� �������� ������ � ��������� �� ����� ���������, ����� � ������
// �� � ����� ������ � philAI_GetGameAttentionValue �����:
// - ��� ������ �������, ��� ������ ������ � ����� ������ (����� ���������� ������������ �� �����, ��� ��� �����������)
// - ��� ������ �������, ��� ������ ������ � ����� ���������� (��������� ��, ��������, �� ��������, ��� ���� ���� ������ �������� ���-�� ��������� �������)
// - ��� ������ �������, ��� ������ ������ � ����� �������� (��������� ����� ����)
// ��������, ����� ������� ���������� ������� ����� ������������ � ������� ������ �����
void* philAI_GetTurnAttentionValue(int playerIndex)
{
  void* pAiParam = (void*)&gpGame->players[playerIndex].aiGameAttentionValueBuildings;
  gpGame->players[playerIndex].aiGameAttentionValueBuildings = 0.4;
  gpGame->players[playerIndex].aiGameAttentionValueCreatures = 0.3;
  gpGame->players[playerIndex].aiGameAttentionValueHeroes = 0.3;
  gpGame->players[playerIndex].aiTurnAttentionValueBuildings = gpGame->players[playerIndex].aiGameAttentionValueBuildings; // ����. ��� ��������
  gpGame->players[playerIndex].aiTurnAttentionValueCreatures = gpGame->players[playerIndex].aiGameAttentionValueCreatures; // ����. ��� �������
  gpGame->players[playerIndex].aiTurnAttentionValueHeroes = gpGame->players[playerIndex].aiGameAttentionValueHeroes; // ����. ��� ������
  
  float aiParamMultiplier;
  if ( giCurTurn >= 5 )
  {
    if ( giCurTurn >= 10 )
    {
      if ( giCurTurn >= 20 )
      {
        if ( giCurTurn >= 30 )
          aiParamMultiplier = 0.80000001;
        else
          aiParamMultiplier = 1.0;
      }
      else
      {
        aiParamMultiplier = 1.2;
      }
    }
    else
    {
      aiParamMultiplier = 1.4;
    }
  }
  else
  {
    aiParamMultiplier = 1.6;
  }

  gpGame->players[playerIndex].aiTurnAttentionValueHeroes *= aiParamMultiplier; // ����. ��� ������ - � ������ ���� �������
  return pAiParam;
}

int philAI_TurnCostResource(int playerIndex)
{
  int sumResourceAvail = 0;
  int resourceAvail[7];

  for(int i = 0; i < 7; i++)
  {
	// ��� ������ �������� ������� ����� ��� ������� ���� ��� ������ �� �������� ������
    // � ��������� ������� (�����������) ���� ������ ��������
    resourceAvail[i] = (5 * gpGame->players[playerIndex].resourcesIncome[i] * 0.7 +
		gpGame->players[playerIndex].resources[i]) * gResourceBaseValue[i];
    sumResourceAvail += resourceAvail[i];
  }
  
  float meanResourceAvail = sumResourceAvail / 7;

  float coefResourceAvail[7];
  int res;
  for(int i = 0; i < 7; i++)
  {
    coefResourceAvail[i] = (float)resourceAvail[i] / meanResourceAvail;
    res = i;
    gafAITurnCostResource[i] = (float)gResourceBaseValue[i] / (coefResourceAvail[i] / 2.0 + 0.5);
  }
  return res;
}

void* philAI_philAI(void* philAI_1)
{
  for(int i = 0; i < 6; i++)
  {
    giBuildShipyard[i] = -1;
    giBuildBoat[i] = -1;
    giBuildBoatStuffTurn[i] = 0;
  }
  return philAI_1;
}

int philAI_GetGameAIVars(void* philAI_1)
{
  int nPlayers;

  nPlayers = gpGame->numPlayers;
  for (int i = 0; i < nPlayers ; i++)
  {
    philAI_GetGameAttentionValue(i);
  }
  return nPlayers;
}

playerData* philAI_GetTurnAIVars(int playerIdx)
{
  giCurTurn = gpGame->day + 7 * (gpGame->week - 1) + 28 * (gpGame->month - 1);
  philAI_GetTurnAttentionValue(playerIdx);
  philAI_TurnCostResource(playerIdx);
  iCurHourGlassPhase = 0;
  iSandAnim = 0;
  hero* hero_1;
  town* town_1;

  int obeliskValue = philAI_TurnValueOfObelisk(playerIdx);
  gpCurPlayer->aiObeliskValue = obeliskValue;
  // �� ������ �������, ����� ��� �����. � �������� obeliskValue - ��� ��� ��� �����
  gpCurPlayer->aiObeliskRelated = gpCurPlayer->aiObeliskValue * gpGame->numObelisks / 48;
  gpCurPlayer->aiUnexploredTerritoryRV = philAI_MeanRVOfUnexploredTerritory(playerIdx);
  bHeroBuiltThisTurn = 0;

  hero* heroD;
  armyGroup* armyD;
  float probWinnerA;
  int probableApproxCasualtiesA;
  int probableApproxCasualtiesD;
  int probablePreciseCasualtiesA;
  int probablePreciseCasualtiesD;
  int adjustedProfitA;

  if(giCurTurn - giBuildBoatStuffTurn[playerIdx] > 8)
  {
    giBuildShipyard[playerIdx] = -1;
    giBuildBoat[playerIdx] = -1;
  }

  // �� ����� �� ������������
  int v31 = 0;

  int armyFightValue = 0;

  int deltaX;
  int deltaY;

  if(giCurTurn <= 7)
  {
    fFirstWeekTownFV = 0.0;

	// ����� �������� � ����. ���
	bool isEnemyHeroClose = false;
    for(int i = 0; i < gpCurPlayer->numCastles; i++)
    {
      town_1 = &gpGame->castles[gpCurPlayer->castlesOwned[i]];
      for(int j = 0; j < 54; j++)
      {
        hero_1 = &gpGame->heroes[j];
        if(gpGame->heroes[j].ownerIdx >= 0)
        {
          if(hero_1->ownerIdx <= 5)
          {
			// ��� �������� �� ����� !
            if(hero_1->ownerIdx != giCurPlayer)
            {
              deltaX = abs(hero_1->x - town_1->x);
              if(abs(hero_1->y - town_1->y) + deltaX < 16)
              {
                fFirstWeekTownFV = 0.3;
				// ����� �������� � ����. ���
				isEnemyHeroClose = true;
				break;
              }
            }
          }
        }
      }
	  // ����� �������� � ����. ���
	  if(isEnemyHeroClose)
		  break;
    }
  }

  int overallPlayerFightValue = 0;
  for(int k = 0; k < gpCurPlayer->numHeroes; k++)
  {
    hero_1 = &gpGame->heroes[gpCurPlayer->heroesOwned[k]];
    armyFightValue = philAI_FightValueOfStack(&hero_1->army, hero_1, 0, 0, 0, 0);
    overallPlayerFightValue += armyFightValue;
    hero_1->aiParamFV = armyFightValue * 0.00004 + 0.4;
  }
  for(int k = 0; k < gpCurPlayer->numCastles; k++)
  {
    town_1 = &gpGame->castles[gpCurPlayer->castlesOwned[k]];
    armyFightValue = philAI_FightValueOfStack(&town_1->garrison, 0, 0, 0, 0, 0);
    overallPlayerFightValue += armyFightValue;
  }

  gpCurPlayer->aiIncomeToFightValueRatio = (float)(gpCurPlayer->resources[RESOURCE_GOLD] +
	  gpCurPlayer->resourcesIncome[RESOURCE_GOLD]) / (float)(overallPlayerFightValue + 1000) + gpCurPlayer->aiTurnAttentionValueCreatures;
  int artsValue = 0;
  // ��� - 37 ���������� ���� � ������ 1, � � ������ 2 �� ������
  for(int k = 4; k < 37; k++)
    artsValue += gArtifactBaseRV[k];
  for(int k = 0; k < gpGame->numPlayers; k++)
  // �� ������� � ���� ������� ? (gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers) ��� ������ gpGame->numPlayers
  // �� ��������, ����� � ���� �� ������������
  gpGame->players[k].aiGameMapSpare = 1.0 / (float)(gpGame->couldBeNumDefeatedPlayers + gpGame->numPlayers);

  // ��� - � ���� �� 33 ���������, � ������� ������
  gpCurPlayer->aiMeanGameArtValue = (float)artsValue / 33.0;

  for(int k = 0; k < 72; k++)
    gpGame->castles[k].aiInDanger = 0;
  for(int k = 0; k < gpCurPlayer->numCastles; k++)
    gpGame->castles[gpCurPlayer->castlesOwned[k]].aiInDanger = 0;

  for(int i=0; i<MAP_HEIGHT; i++)
	  for(int j=0; j<MAP_WIDTH; j++)
		  gaiEnemyHeroReachable[MAP_HEIGHT * MAP_WIDTH] = false;

  mapCell* cell;
  int townId;
  for(int l = 0; l < gpGame->numPlayers; l++)
  {
    if(l != giCurPlayer && !OnMySide(l))
    {
      for(int j = 0; j < gpGame->players[l].numHeroes; j++)
      {
        hero_1 = &gpGame->heroes[gpGame->players[l].heroesOwned[j]];
		// ��������� ������ ���� ��������
        searchArray_SeedPosition(
          gpSearchArray,
          hero_1->x,
          hero_1->y,
          hero_1->directionFacing,
          hero_1->mobility + 100,
          hero_1->flags & HERO_AT_SEA,
          1,
          hero_1->mobility + 100,
          hero_1->secondarySkillLevel[SECONDARY_SKILL_PATHFINDING],
          -1,
		  -1,
          0,
          0);

        for(int x = 0; x < MAP_WIDTH; x++)
        {
          for(int m = 0; m < MAP_WIDTH; m++)
          {
            if(gpSearchArray->pointMap[x + MAP_WIDTH * m].field_4 & 1)
			{
              gaiEnemyHeroReachable[x + MAP_WIDTH * m] = true;
              if(m)
              {
			    // ������ m - 1 ? ��������� �� ��� ?
                cell = advManager_GetCell(gpAdvManager, x, m - 1);
				if((cell->objType == (LOCATION_TOWN | TILE_HAS_EVENT)) || ((cell->objType & (TILE_HAS_EVENT - 1)) == LOCATION_HERO))
                {
                  townId = game_GetTownId(gpGame, x, m - 1);
				  if(townId != -1)
				  {
					town_1 = &gpGame->castles[townId];
					if(gpGame->castles[townId].ownerIdx == giCurPlayer)
					  if(gpGame->castles[townId].buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
					  {
						  heroD = (hero*)&gpGame->heroes[gpGame->castles[townId].visitingHeroIdx];
						  armyD = (armyGroup*)&gpGame->heroes[gpGame->castles[townId].visitingHeroIdx].army;
						  philAI_ProbableOutcomeOfBattle(
							(armyGroup*)&hero_1->army,
							hero_1,
							(armyGroup*)&heroD->army,
							heroD,
							(armyGroup*)&gpGame->castles[townId].garrison,
							1,
							gpGame->castles[townId].idx,
							gpGame->castles[townId].ownerIdx,
							&probWinnerA,
							&probableApproxCasualtiesA,
							&probableApproxCasualtiesD,
							&probablePreciseCasualtiesA,
							&probablePreciseCasualtiesD,
							&adjustedProfitA);
						  if(probWinnerA > 0.7)
						    town_1->aiInDanger = 1;

					  }
				  }
				}
			  }
			}
		  }
		}
	  }
	}
  }

  for(int i=0; i<MAP_HEIGHT; i++)
	  for(int j=0; j<MAP_WIDTH; j++)
		  gaiTurnValueOfMine[MAP_HEIGHT * MAP_WIDTH] = 7;

  int heroX, heroY;
  playerData* playerData_1;

  // �������� ��� ������ ������ ���� ���� - ��������� ��� ������ � ������ �����
  // ��� ������ �����, ��� �����, �� 7 �� 0. ������� ����� ������� ����� �����
  // ��� ������ ����������� � gaiTurnValueOfMine
  for(int l = 0; l < gpGame->numPlayers; l++)
  {
    // ����� ��� �������� �� �����
    if(l != giCurPlayer)
    {
	  playerData_1 = (playerData*)&gpGame->players[l];
      for(int j = 0; j < playerData_1->numHeroes; j++)
      {
		heroX = gpGame->heroes[playerData_1->heroesOwned[j]].x;
		heroY = gpGame->heroes[playerData_1->heroesOwned[j]].y;
		for(int x = heroX - 10; x <= heroX + 10; x++)
		  for(int m = heroY - 10; m <= heroY + 10; m++)
		  {
			if(x >= 0 && x < MAP_WIDTH)
			{
			  if(m >= 0 && m < MAP_HEIGHT)
			  {
				deltaY = abs(m - heroY);
				deltaX = abs(x - heroX);

				if(gaiTurnValueOfMine[x + MAP_WIDTH * m] > abs(deltaX + deltaY - 4)/4 )
                  gaiTurnValueOfMine[x + MAP_WIDTH * m] = abs(deltaX + deltaY - 4)/4;
			  }
			}
		  }
	  }    
	}
  }

  for(int k = 0; k < 54; k++)
    gfHeroInteractionBonus[k] = 1.0;

  if(gpGame->difficulty)
  {
    if(gpGame->difficulty == 1)
    {
      gfAttackHumanBonus = 1.0;
      gfAttackComputerBonus = 1.0;
    }
    else
    {
      gfAttackHumanBonus = 1.0 + gpGame->difficulty * 0.07000000000000001;
      gfAttackComputerBonus = 1.1 - gpGame->difficulty * 0.12;
    }
  }
  else
  {
    gfAttackHumanBonus = 0.6;
    gfAttackComputerBonus = 1.3;
  }
  // ���� �������� ������ �� ���������. �� ����, ��� ������� �������, ���� ����� ���������
  // ������������ �� ������ ������� � ���� ?
  if(gbIAmGreatest)
    gfAttackComputerBonus = 0.1;

  float townAbundancePrecise = 0.1;

  for(int k = 0; k < gpCurPlayer->numCastles; k++)
  {
    if(gpGame->castles[gpCurPlayer->castlesOwned[k]].buildingsBuiltFlags & BUILDING_CASTLE_BUILT)
      townAbundancePrecise += 1.0;
    else
      townAbundancePrecise += 0.5;
  }

  int townAbundance = townAbundancePrecise;
  // ������� ���-�� ������. ����� ������ - 2
  giMaxHeroesForThisPlayer = 3;
  // ����������� ���-�� ����������� ������� (��� ����� ��������)
  // ���� ������� ����, �� +1 �����
  if(gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers == 2 || gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers == 3)
    ++giMaxHeroesForThisPlayer;
  // ��������� ������, ���� ����� �������
  if(townAbundance >= 5)
    ++giMaxHeroesForThisPlayer;
  if(townAbundance >= 10 )
    ++giMaxHeroesForThisPlayer;
  // �������� ������, ���� ����� ���������, ��������� - ���� �������/��.�������
  if(gpGame->mapHeader.width == 36)
    --giMaxHeroesForThisPlayer;
  if(gpGame->mapHeader.width >= 108)
    ++giMaxHeroesForThisPlayer;

  // ����������� - ���������� � && �������� ���-�� ����������� ������� � ������ �����
  // ���� && �����������, ����� �������� 1 ����� (������ 2 ������ - �� 1 �� ������ �������)

  int firstGamePeriodEnd = 16;
  int secondGamePeriodEnd = 22;
  if(gpCurPlayer->personality == AI_EXPLORER)
  {
    firstGamePeriodEnd = 8;
    secondGamePeriodEnd = 15;
  }
  if(giCurTurn < firstGamePeriodEnd)
  {
    if(townAbundance == 1)
    {
      if(gpCurPlayer->numHeroes == 1)
      {
        hero_1 = (hero*)&gpGame->heroes[gpCurPlayer->heroesOwned[0]];
        town_1 = (town*)&gpGame->castles[gpCurPlayer->castlesOwned[0]];
        deltaX = abs(gpGame->castles[gpCurPlayer->castlesOwned[0]].x - gpGame->heroes[gpCurPlayer->heroesOwned[0]].x);
		deltaY = abs(gpGame->castles[gpCurPlayer->castlesOwned[0]].y - gpGame->heroes[gpCurPlayer->heroesOwned[0]].y);
		// ���� ����� �� ����� �� ������� ��������� ������������� �����, �� ������ ������ ���� �� �����
        if(deltaX + deltaY < 18)
          giMaxHeroesForThisPlayer = 1;
      }
    }
  }

  if(giCurTurn < secondGamePeriodEnd && giMaxHeroesForThisPlayer > 2)
    giMaxHeroesForThisPlayer = 2;
  if(gpCurPlayer->personality == 2)
    ++townAbundance;
  if(giMaxHeroesForThisPlayer > townAbundance + 1)
    giMaxHeroesForThisPlayer = townAbundance + 1;

  if(gpCurPlayer->startingNumHeroes > giMaxHeroesForThisPlayer)
  {
    giMaxHeroesForThisPlayer = gpCurPlayer->startingNumHeroes;
  }

  return gpCurPlayer;

}

// ������� philAI_DoAI, ��� �� ���������� �� goto, label
mouseManager* philAI_DoAI(void* philAI_1, int playerIdx)
{
  mouseManager* result;
  hero* hero_1;
  mapCell* cell;
  int isLostHero;
  int stopHero;
  int stopHero2;
  int stopHero3;
  int maxHeroMoves;
  int distancePathfinding;
  int currentMove;
  int isMovepointsHalfed;
  int subMaxSearchArraySteps;
  bool isPenultimateMove;
  int lastDirection;
  int save_bShowIt;
  int colorPointer;
  int trigX;
  int trigY;
  int hasAdjMonster;
  int townId;

  int bestDirection;
  int positionValue;

  bool targetUndefined;
  bool zeroPath;
  bool areMovesFinished;

  // LogInt((int)"DO AI 1", a2, -999, -999, -999, -999, -999, -999);
  PollSound();
  if(!gbGameOver && (!giLimitPlayer || giLimitPlayer == playerIdx))
  {
    //LogInt((int)"DO AI", a2, -999, -999, -999, -999, -999, -999);
    InitAIMapVars();
    philAI_GetTurnAIVars(playerIdx);
	// 2 ���� ���� � ���� ??
    if(gpGame->day == 1 || gpGame->day == 1)
    {
      for(int i = 0; i < gpCurPlayer->numHeroes; i++)
        gpGame->heroes[gpCurPlayer->heroesOwned[i]].aiLastTownInteractionTurn = -99;
    }
    ShowStatus();
    philAI_SetupRelativeHeroStrengths();
    for(int i = 0; i < 7; i++)
    {
      //sprintf(gText, "RES - %15s  %d  %d", gResourceNames[i], gpCurPlayer->resources[i], gpCurPlayer->field_E7[i]);
      //LogStr(gText);
    }
    philAI_CheckBuyStuff(philAI_1);
    philAI_IncrementHourGlass();

    while(true) // � ���� ����� ���������� ������ ���������������
    {
      hero_1 = philAI_DetermineHeroToMove(playerIdx);
      if(!hero_1)
        break;
      ValidateHero(hero_1);
      gpCurAIHero = hero_1;
      if(gpCurAIHero->patrolX == 255 || gpCurAIHero->patrolDistance)
      {
        giCurAIHeroMorale = armyGroup_GetMorale(&gpCurAIHero->army, gpCurAIHero, 0, 0);
        giCurAIHeroLuck = game_GetLuck(gpCurAIHero, 0, 0);
	    // �������� �� ����� ?
        armyGroup_GetMorale(&gpCurAIHero->army, gpCurAIHero, 0, 0);
        giHumanTownConquered = -1;
        iCurPlaceToVisit = 0;
        if(gbGameOver)
          break;
        //LogStr("\n\n\n\n");
        //LogStr("===================================");
        //LogInt((int)"Player with HeroTOMOVE", a2, -999, -999, -999, -999, -999, -999);
        //LogStr(gpCurAIHero->name);
        //LogStr(L"\n");
        philAI_CheckReload();
        philAI_CheckBerserk();
        giShowComputerRoute = 0;
        if(blackoutComputer
          || gbRemoteOn
          || !MapExtraPosAndAdjacentsSet(gpCurAIHero->x, gpCurAIHero->y, giCurWatchPlayerBit))
        {
          bShowIt = false;
          advManager_SetHeroContext(gpAdvManager, gpCurAIHero->idx, 0);
        }
        else
        {
          bShowIt = true;
          advManager_SetHeroContext(gpAdvManager, gpCurAIHero->idx, 0);
        }
        stopHero = false;
        ResetHeroRVs(0, 0, 0);
        if(gpCurAIHero->flags & HERO_AT_SEA)
          maxHeroMoves = 15;
        else
          maxHeroMoves = 5;
        distancePathfinding = gpCurAIHero->mobility + 800;
        maxHeroMoves = (1.7 - gpGame->difficulty * 0.1) * maxHeroMoves;
        distancePathfinding = ((gpGame->difficulty - 1) * 0.06 + 0.8) * distancePathfinding;
//LABEL_27:
		while(true) // ���� �� ������ �����
		{
		  if(stopHero || gpCurAIHero->remainingMobility < 75)
		  {
			gpCurAIHero->remainingMobility = 0;
			advManager_DeactivateCurrHero(gpAdvManager);
		  }
		  else
		  {
			// ����� gbGameOver. �� ������ ?
			if(gbGameOver)
			  break;
			// �������
			if(gpCurAIHero->remainingMobility == gpCurAIHero->mobility
			  && gpCurPlayer->aiNumberPuzzlePieces > 15
			  && gpCurPlayer->aiProbableUltimateArtifactX == gpCurAIHero->x
			  && gpCurPlayer->aiProbableUltimateArtifactY == gpCurAIHero->y )
			  advManager_ProcessSearch(gpAdvManager, gpCurAIHero->x, gpCurAIHero->y);
			do
			{
              targetUndefined = false;
              zeroPath = false;
			  do
			  {
                areMovesFinished = false;
				positionValue = philAI_DetermineTargetPosition(
				 philAI_1,
				 &gpCurAIHero->oldTargetX,
				 &gpCurAIHero->oldTargetY,
				 distancePathfinding,
				 &bestDirection);
				townId = game_GetTownId(gpGame, gpCurAIHero->x, gpCurAIHero->y);
				// ���� ����� � �����, � ����� � ���������, �� ����� � �����
				// ������ � ���, ��� �� �������� ��� ����������� -
				// ����� ����������� ��������� ��� ������, ����� ����� �������� �����
				// � � ��������� ����� ��������
				if(townId != -1)
				{
				  if(gpGame->castles[townId].aiInDanger)
				  {
					// �������� � �����, ���� ������ �� ���������� ���� � �����
					// ��������, ����������� ��������, ����� �� ��� �����
					if((advManager_GetCell(
					  gpAdvManager,
					  gpCurAIHero->oldTargetX,
					  gpCurAIHero->oldTargetY)->objType & (TILE_HAS_EVENT - 1)) != LOCATION_HERO)
					  gpCurAIHero->remainingMobility = 0;
				  }
				}
				if(bestDirection != -1)
				{
				  lastDirection = bestDirection;
				  currentMove = 99;
				  // ������������ ������ ����� (����), �� �� ������ ����� (����) �� ��������
				  // ��� ��� currentMove ����� ������ (������� while �� ����������)
				  //goto LABEL_79;
				  // ���������� �� ���� ���, ���� ������ ��� �� ����� (��. ����)
				  //subMaxSearchArraySteps = 7;
				  areMovesFinished = true;
				  break; // ������� �� �����. do-while
				}
			  }
			  // ������ philAI_DoAnywhereDDoorTownGate ��������� ������ � ��� ������,
			  // ���� positionValue < 1000 � bestDirection == -1
			  while(positionValue < 1000 && bestDirection == -1 && philAI_DoAnywhereDDoorTownGate(philAI_1, positionValue));

			  if(areMovesFinished)
				break; // ������� �� �����. do-while

			  if(positionValue < 75 && gpGame->day == 7 && gpCurAIHero->occupiedObjType == (LOCATION_TOWN | TILE_HAS_EVENT))
				gpCurAIHero->remainingMobility = 0;
			  for(int i = 0; i < iCurPlaceToVisit; i++)
			  {
				if(iPlacesVisited[i].x == gpCurAIHero->oldTargetX
				  && iPlacesVisited[i].y == gpCurAIHero->oldTargetY
				  && advManager_GetCell(
					gpAdvManager,
					gpCurAIHero->oldTargetX,
					gpCurAIHero->oldTargetY)->objType != (LOCATION_TOWN | TILE_HAS_EVENT))
				  gpCurAIHero->remainingMobility = 0;
			  }
			  if(iCurPlaceToVisit < 30)
			  {
				iPlacesVisited[iCurPlaceToVisit].x = gpCurAIHero->x;
				iPlacesVisited[iCurPlaceToVisit].y = gpCurAIHero->y;
				iCurPlaceToVisit++;
			  }
			  giShowComputerRoute = 1;
			  if(gpCurAIHero->remainingMobility == gpCurAIHero->mobility)
			  {
				isMovepointsHalfed = false;
				philAI_IncrementHourGlass();
			  }
			  if(gpCurAIHero->oldTargetX == -1 || gpCurAIHero->oldTargetY == -1 )
			  {
				stopHero = true;
				//goto LABEL_27;
				targetUndefined = true;
				break; // ������� �� �������� do-while
			  }
			  cell = 0;
			  advManager_SetHeroContext(gpAdvManager, gpCurAIHero->idx, 0);
			  searchArray_BuildPath(
				gpSearchArray,
				gpCurAIHero->x,
				gpCurAIHero->y,
				gpCurAIHero->oldTargetX,
				gpCurAIHero->oldTargetY,
				gpCurAIHero->remainingMobility);
			  // ���� ���������� �� ������ ����� �������, �� �� ��� ��� ��� �����
			  if(!gpSearchArray->nSteps)
			  {
				stopHero = true;
				//goto LABEL_113;
				zeroPath = true;
				break; // ������� �� �������� do-while
			  }
			  if(gpSearchArray->nSteps <= 0)
			  {
				stopHero = true;
				//goto LABEL_113;
				zeroPath = true;
				break; // ������� �� �������� do-while
			  }
			  advManager_UpdateScreen(gpAdvManager, 0, 0);
			}
			while(positionValue > 1000
			  && hero_HasSpell(gpCurAIHero, SPELL_DIMENSION_DOOR)
			  && gpCurAIHero->spellpoints >= 30
			  && philAI_DoDimensionDoor(gpCurAIHero));

			//if(targetUndefined && !areMovesFinished)
			if(targetUndefined)
			  continue; // ��������� �� ���������� while(true)

			//if(zeroPath && !areMovesFinished)
			if(zeroPath)
			{
			  if ( !cell )
			  //goto LABEL_27;
				continue;
			  advManager_DoAIEvent(gpAdvManager, cell, gpCurAIHero, trigX, trigY);
			  if ( gpCurPlayer->curHeroIdx != -1 )
			  {
				ValidateHero(gpCurAIHero);
				ResetHeroRVs(1, gpCurAIHero->oldTargetX, gpCurAIHero->oldTargetY);
				//goto LABEL_27;
				continue;
			  }
			  if(gpCurAIHero->occupiedObjType == (LOCATION_TOWN | TILE_HAS_EVENT))
				philAI_CheckBuyStuff(philAI_1);

			  break; // � ������ �����				  
			}

			if(areMovesFinished)
			{
			  if(advManager_GetMoveShowIt(gpCurAIHero, lastDirection))
			  {
				save_bShowIt = bShowIt;
				bShowIt = true;
				mouseManager_HideColorPointer(gpMouseManager);
				colorPointer++;
				bShowIt = save_bShowIt;
			  }
			  cell = advManager_MoveHero(gpAdvManager, lastDirection, stopHero3, &trigX, &trigY, &stopHero2, 1, &hasAdjMonster, 0);
			}
			else
			{
			  currentMove = 0;
			  subMaxSearchArraySteps = gpSearchArray->nSteps - 1;
			  stopHero2 = 0;
			  stopHero3 = 0;
			  isPenultimateMove = true;
			  while(subMaxSearchArraySteps >= 0 && currentMove < maxHeroMoves)
			  {
				// ������������� ��������
				isPenultimateMove = currentMove + 1 == maxHeroMoves || !subMaxSearchArraySteps;
				if(subMaxSearchArraySteps > 0)
				{
				  stopHero2 = 0;
				  stopHero3 = 0;
				  if(philAI_GoodAdjacent(philAI_1, &bestDirection))
				  {
					gpSearchArray->directionToTarget[subMaxSearchArraySteps] = bestDirection;
					isPenultimateMove = true;
				  }
				}
				lastDirection = gpSearchArray->directionToTarget[subMaxSearchArraySteps];
		//LABEL_79:
				if(advManager_GetMoveShowIt(gpCurAIHero, lastDirection))
				{
				  save_bShowIt = bShowIt;
				  bShowIt = true;
				  mouseManager_HideColorPointer(gpMouseManager);
				  colorPointer++;
				  bShowIt = save_bShowIt;
				}

				cell = advManager_MoveHero(gpAdvManager, lastDirection, stopHero3, &trigX, &trigY, &stopHero2, 1, &hasAdjMonster, 0);
				currentMove++;
				if(cell || stopHero2 || hasAdjMonster)
				  break;
				subMaxSearchArraySteps--;
			  }
			}

			// ��� ��� ? �������� �� ���������� ������ ?
			// ������ ���, ��������, �� ����� �� ����� "��� ����������"
			// � ���� ������ �������� � ������ �������������
			// ���������� ������� � ������� �����
			if(gpCurAIHero->ownerIdx != giCurPlayer)
			{
			  if(!isLostHero)
			  {
			    isLostHero = true;
				philAI_CheckBuyStuff(philAI_1);
			  }
			  //goto LABEL_120;
			  if(gpCurAIHero->occupiedObjType == (LOCATION_TOWN | TILE_HAS_EVENT))
			    philAI_CheckBuyStuff(philAI_1);

			  // � ������ �����
			  break; // ������� �� �����. while(true) � �������� � ������ �������� while(true)
			}
			// ���� �������� ����� �������� �����
			if(gpCurAIHero->mobility / 2 >= gpCurAIHero->remainingMobility && !isMovepointsHalfed)
			{
			  isMovepointsHalfed = true;
			  philAI_IncrementHourGlass();
			}
			// ��������������� ��� �����
			if(subMaxSearchArraySteps < 0
			  && gpCurPlayer->aiNumberPuzzlePieces > 15
			  && gpCurPlayer->aiProbableUltimateArtifactX == gpCurAIHero->x
			  && gpCurPlayer->aiProbableUltimateArtifactY == gpCurAIHero->y )
			  {
			    if(gpCurAIHero->remainingMobility == gpCurAIHero->mobility)
				  advManager_ProcessSearch(gpAdvManager, -1, -1);
				else
				  gpCurAIHero->remainingMobility = 0;
			  }
			if(subMaxSearchArraySteps < 0
			  && ((gpCurAIHero->x != gpCurAIHero->oldTargetX
			  || gpCurAIHero->oldTargetX != gpCurAIHero->y)
			  && !cell
			  || gpCurAIHero->remainingMobility < 75
			  || stopHero2 && !cell))
			  stopHero = true;
			save_bShowIt = bShowIt;
			bShowIt = true;
			while(colorPointer)
			{
			  mouseManager_ShowColorPointer(gpMouseManager);
			  colorPointer--;
			}
			bShowIt = save_bShowIt;
			advManager_UpdateRadar(gpAdvManager, 1, 0);
//	LABEL_113:
			if(!cell)
			  //goto LABEL_27;
			  continue; // ������� �� ������ �����. while(true)
			advManager_DoAIEvent(gpAdvManager, cell, gpCurAIHero, trigX, trigY);
			if(gpCurPlayer->curHeroIdx != -1)
			{
			  ValidateHero(gpCurAIHero);
		      ResetHeroRVs(1, gpCurAIHero->oldTargetX, gpCurAIHero->oldTargetY);
			  //goto LABEL_27;
			  continue; // ������� �� ������ �����. while(true)
			}
		  } // else �����. while
//	LABEL_120:
		  if(gpCurAIHero->occupiedObjType == (LOCATION_TOWN | TILE_HAS_EVENT))
			philAI_CheckBuyStuff(philAI_1);

		  // � ������ �����
		  break; // ������� �� �����. while(true) � �������� � ������ �������� while(true)
		} // �����. while(true)
      } // 1-� if �����. while
      else
      {
        gpCurAIHero->remainingMobility = 0;
      }
    } // ������� �� ������ �����. while(true)
  } // ����� ������ if, ��� �� ������ while
  game_CheckHeroConsistency(gpGame);
  gpCurAIHero = 0;
  CloseAIMapVars();

  while(true)
  {
    result = gpMouseManager;
    if(!gpMouseManager->cursorDisabled)
      break;
    mouseManager_ShowColorPointer(gpMouseManager);
  }
  return result;
}

bool philAI_ChooseGoldOrExperience(int gold, int experience)
{
  // �������� ������� ���� � �������� ����� ("<" ������ ">")
  // ���� ���� ������ �������, �� ��� � ����� �����
  return gpCurPlayer->resources[RESOURCE_GOLD] > 4000;
}
