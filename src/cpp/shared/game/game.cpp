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

randomHeroCreatureInfo randomHeroArmyBounds[NUM_FACTIONS][2] = {
  {{CREATURE_PEASANT,  30, 50},{CREATURE_ARCHER,   3, 5}},
  {{CREATURE_GOBLIN,   15, 25},{CREATURE_ORC,      3, 5}},
  {{CREATURE_SPRITE,   10, 20},{CREATURE_DWARF,    2, 4}},
  {{CREATURE_CENTAUR,  6,  10},{CREATURE_GARGOYLE, 2, 4}},
  {{CREATURE_HALFLING, 6,  10},{CREATURE_BOAR,     2, 4}},
  {{CREATURE_SKELETON, 6,  10},{CREATURE_ZOMBIE,   2, 4}}
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
  double randomUpperBound;
  double randomLowerBound;
  armyGroup *heroArmy = &gpGame->heroes[heroIdx].army;
  bool hasTier[2];
  randomHeroCreatureInfo* creatureFaction = randomHeroArmyBounds[gpGame->heroes[heroIdx].factionID];

  hasTier[0] = 1;
  hasTier[1] = Random(0, 99) < 87;

  this->ClearArmy(heroArmy);
  for (int creatureTier = 0; creatureTier < 2; ++creatureTier) {
    if (hasTier[creatureTier]) {
      randomLowerBound = creatureFaction[creatureTier].lowQuantity;
      randomUpperBound = creatureFaction[creatureTier].highQuantity + 9;
      if (isAI) { //  If isAI, randomLowerBound is assigned the average of the bounds and this results in the probability of higher values
        randomLowerBound = (randomUpperBound + randomLowerBound) / 2;
      }
      this->GiveArmy(heroArmy, creatureFaction[creatureTier].creatureType, (int)Random(randomLowerBound, randomUpperBound), creatureTier);
    }
  }
}

void game::ClearArmy(class armyGroup * heroArmy) {
  for (int armySlotIdx = 0; armySlotIdx < 5; ++armySlotIdx) {
    heroArmy->creatureTypes[armySlotIdx] = -1;
    heroArmy->quantities[armySlotIdx] = -1;
  }
}

void game::GiveTroopsToNeutralTown(int castleIdx) {
  int randomQuantity;
  int quantity;
  signed int creatureTier;
  int creatureType;
  int creatureTierRandomizer;

  if ((this->castles[castleIdx].x > 0 || this->castles[castleIdx].y > 0) && this->castles[castleIdx].ownerIdx < 0) {
    creatureTierRandomizer = Random(1, 15);
    if (giCurTurn / 10 > 0) { // As time goes on, the odds of getting smaller stacks of stronger creatures increases, but it is still possible to get larger stacks of weaker creatures
      creatureTierRandomizer += Random(0, giCurTurn / 10);
    }
    if (creatureTierRandomizer <= 5) {
      creatureTier = 1;
      randomQuantity = Random(8, 15);
    } else if (creatureTierRandomizer <= 10) {
      creatureTier = 2;
      randomQuantity = Random(5, 7);
    } else if (creatureTierRandomizer <= 13) {
      creatureTier = 3;
      randomQuantity = Random(3, 5);
    } else if (creatureTierRandomizer <= 15) {
      creatureTier = 4;
      randomQuantity = Random(1, 3);
    } else {
      creatureTier = 5;
      randomQuantity = 1;
    }
    quantity = giCurTurn / 20 + randomQuantity;
    creatureType = neutralTownCreatureTypes[this->castles[castleIdx].factionID][creatureTier];
    this->GiveArmy(&this->castles[castleIdx].garrison, creatureType, quantity, -1);
  }
}

void game::ProcessOnMapHeroes() {
  int faction;
  signed int randomHeroIdx;
  mapCell *loc;
  hero *randomHero;
  char heroExists[MAX_HEROES];
  int ppMapExtraHeroIdx;
  HeroExtra *mapExtraHero;
  char isJail;

  memset(heroExists, 0, 54u);// Only 54 out of 56 bytes set to zero, for whatever reason.
  for (int y = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
      loc = &this->map.tiles[(y * this->map.width) + x];
      if (loc->getLocationType() == LOCATION_RANDOM_HERO || loc->objType == TILE_HAS_EVENT | LOCATION_RANDOM_HERO) {
        isJail = loc->getLocationType() == LOCATION_JAIL;
        ppMapExtraHeroIdx = loc->extraInfo;
        mapExtraHero = (HeroExtra *)ppMapExtra[ppMapExtraHeroIdx];
        if (!mapExtraHero->field_11 || mapExtraHero->heroID >= MAX_HEROES || heroExists[mapExtraHero->heroID]) {
          mapExtraHero->hasFaction = 0;
        } else {
          heroExists[mapExtraHero->heroID] = 1;
          mapExtraHero->hasFaction = 1;
        }

        if (isJail) {
          mapExtraHero->owner = -1;
          faction = mapExtraHero->factionID;
        } else {
          mapExtraHero->owner = gcColorToPlayerPos[loc->objectIndex / 7];
          faction = loc->objectIndex % 7; // Constant here (needs to be generalized)
          if (faction == FACTION_MULTIPLE) { // Constant here (faction related)
            faction = this->relatedToColorOfPlayerOrFaction[gcColorToSetupPos[gpGame->players[mapExtraHero->owner].color]];// Constant here (I think this is a faction-related structure)
          }
        }

        if (mapExtraHero->hasFaction) {
          this->heroes[mapExtraHero->heroID].factionID = faction;
        } else {
          randomHeroIdx = this->RandomScan((signed char *)heroExists, 9 * faction, 9, 1000, 0);// Constant here (the game might depend on the number of heroes as it relates to the number of factions)
          if (randomHeroIdx == -1) { //  I think RandomScan is just a strange way of trying to return a random Idx that will correspond to a hero that satisfies a particular criterion, yet I think there is a better way of accomplishing this.
            randomHeroIdx = this->RandomScan((signed char *)heroExists, 0, MAX_HEROES, 10000, 0);// Constant here (the game might depend on the number of heroes as it relates to the number of factions)
            faction = randomHeroIdx / 9; // Constant here (relies on relation between number of factions and number of heroes); perhaps define HEROES_PER_FACTION?
          }                              // NOTE: Hardcoded heroes may need to be generalized?!
          heroExists[randomHeroIdx] = 1;
          this->heroes[randomHeroIdx].factionID = faction;
          if (mapExtraHero->field_11 && mapExtraHero->heroID >= MAX_HEROES) { // NUM_HEROES?
            this->heroes[randomHeroIdx].heroID = mapExtraHero->heroID;
          }
          mapExtraHero->heroID = randomHeroIdx;
        }
        randomHero = &this->heroes[mapExtraHero->heroID];

        if (!isJail && mapExtraHero->relatedToJailCondition) {
          this->heroes[mapExtraHero->heroID].relatedToX = x;// field_29 changed to relatedTo_HIBYTE_y_LOBYTE_x
          randomHero->relatedToY = y;
          randomHero->relatedToFactionID = mapExtraHero->factionID;// field_3C changed to relatedTo_HIBYTE_Unknown_LOBYTE_factionID
        }

        if (mapExtraHero->hasArmy) {
          for (int armySlotIdx = 0; armySlotIdx < 5; ++armySlotIdx) {
            randomHero->army.quantities[armySlotIdx] = mapExtraHero->army.quantities[armySlotIdx];
            if (randomHero->army.quantities[armySlotIdx] <= 0) {
              randomHero->army.creatureTypes[armySlotIdx] = -1;
            } else {
              randomHero->army.creatureTypes[armySlotIdx] = mapExtraHero->army.creatureTypes[armySlotIdx];
            }
          }
        }
        for (int i = 0; i < 3; ++i) {
          if (mapExtraHero->artifacts[i] >= 0) {
            GiveArtifact(randomHero, mapExtraHero->artifacts[i], 1, -1);
          }
        }
        if (mapExtraHero->hasName) {
          strcpy(randomHero->name, &mapExtraHero->name[6]);
        }
        randomHero->experience = 0;
        gpAdvManager->GiveExperience(randomHero, mapExtraHero->experience, 1);// field_17 changed to experience
        randomHero->CheckLevel();       // Check this function (design question based on generalizing hardcoded, faction-specific data structure information related to skills)
        randomHero->x = x;
        randomHero->y = y;

        if (isJail) {
          randomHero->ownerIdx = -1;
          this->relatedToHeroForHireStatus[mapExtraHero->heroID] = 65;
          loc->extraInfo = mapExtraHero->heroID;
        } else {
          randomHero->ownerIdx = mapExtraHero->owner;
          this->relatedToHeroForHireStatus[mapExtraHero->heroID] = randomHero->ownerIdx;
          this->players[randomHero->ownerIdx].heroesOwned[this->players[randomHero->ownerIdx].numHeroes++] = randomHero->idx;
          if (y > 0 && (this->map.tiles[x + ((y - 1) * this->map.width)].objType) == TILE_HAS_EVENT | LOCATION_TOWN) {
            --randomHero->relatedToY;
            --randomHero->y;
            this->castles[this->GetTownId(x, y - 1)].visitingHeroIdx = randomHero->idx;
          }
          loc->objTileset = 0;
          loc->objectIndex = -1;
          loc->extraInfo = 0;
          loc->objType = 0;
        }

        if (mapExtraHero->couldBeHasSecondarySkills) {
          randomHero->numSecSkillsKnown = 0;
          for (int i = 0; i < 14; ++i) { //clear secondary skills
            randomHero->secondarySkillLevel[i] = 0;
            randomHero->skillIndex[i] = 0;
          }
          for (int i = 0; i < NUM_SECONDARY_SKILLS; ++i) { //assign new secondary skills
            if (mapExtraHero->secondarySkills[i] != -1)
              randomHero->GiveSS(mapExtraHero->secondarySkills[i],  mapExtraHero->secondarySkillLevel[i]);
          }
        }

        if (!isJail) {
          this->SetVisibility(randomHero->x, randomHero->y, randomHero->ownerIdx, giVisRange[randomHero->secondarySkillLevel[SECONDARY_SKILL_SCOUTING]]);
        }

        FREE(ppMapExtra[ppMapExtraHeroIdx]);
        ppMapExtra[ppMapExtraHeroIdx] = NULL;
      }
    }
  }
}