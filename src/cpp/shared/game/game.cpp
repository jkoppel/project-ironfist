#include<string>

#include "analytics.h"
#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "prefs.h"
#include "scripting/callback.h"
#include "scripting/scripting.h"
#include "spell/spells.h"


char* gAlignmentNames[13] = {"Knight", "Barbarian", "Sorceress", "Warlock", "Wizard", "Necromancer",
                             "Multiple", "Random", NULL, NULL, NULL, NULL,
                             "Cyborg"};

int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}

extern int gbNoCDRom;

__int16 creatureTypesAndQuantities[NUM_FACTIONS][3][3] = {
  {{CREATURE_PEASANT,  30, 50},{CREATURE_ARCHER,   3, 5},{CREATURE_PIKEMAN,    2, 4}},
  {{CREATURE_GOBLIN,   15, 25},{CREATURE_ORC,      3, 5},{CREATURE_WOLF,       2, 3}},
  {{CREATURE_SPRITE,   10, 20},{CREATURE_DWARF,    2, 4},{CREATURE_ELF,        1, 2}},
  {{CREATURE_CENTAUR,  6,  10},{CREATURE_GARGOYLE, 2, 4},{CREATURE_GRIFFIN,    1, 2}},
  {{CREATURE_HALFLING, 6,  10},{CREATURE_BOAR,     2, 4},{CREATURE_IRON_GOLEM, 1, 2}},
  {{CREATURE_SKELETON, 6,  10},{CREATURE_ZOMBIE,   2, 4},{CREATURE_MUMMY,      1, 2}}
};

int neutralTownCreatureTypes[NUM_FACTIONS][5] = {
  {CREATURE_PEASANT,  CREATURE_ARCHER,   CREATURE_PIKEMAN,    CREATURE_SWORDSMAN, CREATURE_CAVALRY},
  {CREATURE_GOBLIN,   CREATURE_ORC,      CREATURE_WOLF,       CREATURE_OGRE,      CREATURE_TROLL},
  {CREATURE_SPRITE,   CREATURE_DWARF,    CREATURE_ELF,        CREATURE_DRUID,     CREATURE_UNICORN},
  {CREATURE_CENTAUR,  CREATURE_GARGOYLE, CREATURE_GRIFFIN,    CREATURE_MINOTAUR,  CREATURE_HYDRA},
  {CREATURE_HALFLING, CREATURE_BOAR,     CREATURE_IRON_GOLEM, CREATURE_ROC,       CREATURE_MAGE},
  {CREATURE_SKELETON, CREATURE_ZOMBIE,   CREATURE_MUMMY,      CREATURE_VAMPIRE,   CREATURE_LICH}
};

int game::SetupGame() {
	int oldNoCDRom = gbNoCDRom;
	gbNoCDRom = 0;
	int res = this->SetupGame_orig();
	gbNoCDRom = oldNoCDRom;
	return res;
}

void game::RandomizeHeroPool() {
	signed int idx;

	for( idx = 0; idx < MAX_HEROES; idx++) {
		this->heroes[idx].experience = Random(0, 50) + 40;
		this->SetRandomHeroArmies(idx, 0);
		this->heroes[idx].remainingMobility = this->heroes[idx].CalcMobility();
		this->heroes[idx].mobility = this->heroes[idx].remainingMobility;
		this->heroes[idx].randomSeed = Random(1, 255);
		this->heroes[idx].wisdomLastOffered = 1;
		switch(this->heroes[idx].factionID) {
		case FACTION_SORCERESS:
			this->heroes[idx].AddSpell(SPELL_BLESS);
			break;
		case FACTION_WARLOCK:
			this->heroes[idx].AddSpell(SPELL_CURSE);
			break;
		case FACTION_NECROMANCER:
			this->heroes[idx].AddSpell(SPELL_HASTE);
			break;
		case FACTION_WIZARD:
			this->heroes[idx].AddSpell(SPELL_STONESKIN);
			break;
		}
	}
}

extern char gMapName[]; // the map selected in the list
extern char gLastFilename[];
extern signed char xIsExpansionMap;

void game::InitNewGame(struct SMapHeader *a) {
	if (!strlen(gLastFilename)) { // game just started, no map was played yet
		std::string lastPlayed;
		if (xIsExpansionMap)
			lastPlayed = read_pref<std::string>("Last Map expansion");
		else
			lastPlayed = read_pref<std::string>("Last Map");

		if (lastPlayed.length() < 20) { // otherwise means no registry keys exist yet
			strcpy(gMapName, lastPlayed.c_str());
			strcpy(this->mapFilename, lastPlayed.c_str());
		}
	}
	this->InitNewGame_orig(a);
}

void game::NewMap(char* mapname) {
  send_event(mapAction, mapname);
  if (xIsExpansionMap)
	  write_pref("Last Map expansion", std::string(gMapName));
  else
	  write_pref("Last Map", std::string(gMapName));
  this->ResetIronfistGameState();
  this->NewMap_orig(mapname);
  ScriptingInit(std::string(mapname));
  gpGame->firstDayEventDone = false;
  gpGame->allowAIArmySharing = true;
}

void game::NextPlayer() {
	/*
	 * Because heroes no longer regain movement on hire.
	 * we need to make sure all heroes in hero pool regain movement between turns.
	 */
	NextPlayer_orig();
	for(int i = 0; i < MAX_HEROES; i++) {
		hero *h = &this->heroes[i];
		h->mobility = h->CalcMobility();
		h->remainingMobility = h->mobility;
	}
}

void game::PerDay() {
	this->PerDay_orig();
	ScriptCallback("OnNewDay", this->month, this->week, this->day);
}

void game::ResetIronfistGameState() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = false;
        }
    }
}

extern int gbGameOver;
extern int giEndSequence;

void __fastcall CheckEndGame(int a, int b) {
  CheckEndGame_orig(a, b);
  if (gbGameOver) {
    if (giEndSequence) {
      ScriptCallback("OnMapVictory");
    } else {
      ScriptCallback("OnMapLoss");
    }
  }
}

int __fastcall HandleAppSpecificMenuCommands(int a1) {
  int spell; // [sp+24h] [bp-8h]@55
  hero *hro; // [sp+28h] [bp-4h]@1

  hro = 0;
  if (gpCurPlayer && gpCurPlayer->curHeroIdx != -1)
    hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  switch (a1) {
    case 40143: // MENUITEM "Free Spells"
      gpGame->_B[1] = 1;
      if (gbInCampaign)
        gpGame->_11[72] = 1;
      if (hro) {
        for (spell = 0; spell < NUM_SPELLS; ++spell)
          hro->AddSpell(spell, 10); // Knowledge argument "10" is redundant due to zeroing out of value in modified AddSpell
        hro->spellpoints = 999;
      }
      return 0;
    default:
      return HandleAppSpecificMenuCommands_orig(a1);
  }
}

class philAI {

	char _; // Yes, this is a 1-byte object.

public:
	void RedistributeTroops_orig(armyGroup *, armyGroup *, int, int, int, int, int);
	void RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5);
};

void philAI::RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5) {
	if (gpGame->allowAIArmySharing) {
		RedistributeTroops_orig(army1, army2, a1, a2, a3, a4, a5);
	}
}

void game::SetRandomHeroArmies(int heroIdx, int isAI) {
  int randomizedValue; // eax@1
  int randomizedValue2;
  int creatureTier2 = 0; // [sp+10h] [bp-8Ch]@1
  int randomUpperBound; // [sp+14h] [bp-88h]@9
  signed int armySlotIdx; // [sp+18h] [bp-84h]@3
  signed int creatureTier; // [sp+18h] [bp-84h]@6
  int randomLowerBound; // [sp+1Ch] [bp-80h]@9
                        //__int16 creatureTypesAndQuantities[54]; // [sp+20h] [bp-7Ch]@1
  armyGroup *pointerToArmyOfHeroIdx = &gpGame->heroes[heroIdx].army; // [sp+8Ch] [bp-10h]@1
  bool hasTier[3]; // [sp+90h] [bp-Ch]@1
  int TIER_ONE = 0;
  int TIER_TWO = 1;
  int TIER_THREE = 2;

  hasTier[TIER_ONE] = 1;
  hasTier[TIER_TWO] = Random(0, 99) < (isAI < 1 ? 50 : 80);// If isAI, there is a ~20% chance that this hero will get Tier 2 creatures; if not, then a ~50% chance
  randomizedValue2 = Random(0, 99);
  hasTier[TIER_THREE] = (isAI < 1 ? 25 : 65) > randomizedValue2;// If isAI, there is a ~65% chance that this hero will get Tier 3 creatures; if not, then a ~25% chance
  if ((isAI < 1 ? 25 : 65) <= randomizedValue2)// If isAI, there is a ~35% chance that this hero will get Tier 2 creatures; if not, then a ~75% chance
    hasTier[TIER_TWO] = 1;
  for (armySlotIdx = 0; armySlotIdx < 5; ++armySlotIdx) {
    pointerToArmyOfHeroIdx->creatureTypes[armySlotIdx] = -1;
    pointerToArmyOfHeroIdx->quantities[armySlotIdx] = -1;
  }
  for (creatureTier = 0; creatureTier < 2; ++creatureTier) {
    if (hasTier[creatureTier]) {
      pointerToArmyOfHeroIdx->creatureTypes[creatureTier2] = creatureTypesAndQuantities[gpGame->heroes[heroIdx].factionID][creatureTier][TIER_ONE];
      randomLowerBound = 10 * creatureTypesAndQuantities[gpGame->heroes[heroIdx].factionID][creatureTier][TIER_TWO];
      randomUpperBound = 10 * creatureTypesAndQuantities[gpGame->heroes[heroIdx].factionID][creatureTier][TIER_THREE] + 9;
      if (isAI) {                              //  If isAI, randomLowerBound is assigned the average of the bounds and results in the probability of higher random values
        randomLowerBound = (randomUpperBound + randomLowerBound) / 2;
      }
      randomizedValue = Random(randomLowerBound, randomUpperBound) / 10;
      pointerToArmyOfHeroIdx->quantities[creatureTier2++] = randomizedValue;
    }
  }
}