#include <string>
#include <vector>

#include "analytics.h"
#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "prefs.h"
#include "scripting/callback.h"
#include "scripting/scripting.h"
#include "skills.h"
#include "spell/spells.h"


// The title screen implements button hovering manually in code, using this data structure
// x, y, width, height
unsigned short IMHotSpots[][4] = {
  {556,   8, 81, 113}, // new game
  {442, 269, 88,  77}, // load game
  {  0, 374, 80,  74}, // high scores
  { 79, 434, 76,  43}, // credits
  {555, 434, 86,  44}  // quit
};

void __fastcall CheckShingleUpdate() {
  // Do nothing
}



char* gAlignmentNames[MAX_FACTIONS] = {"Knight", "Barbarian", "Sorceress", "Warlock", "Wizard", "Necromancer",
                                       "Multiple", "Random", NULL, NULL, NULL, NULL,
                                       "Cyborg"};

H2RECT gMapViewportRegion = H2RECT(top(16), bottom(464), left(16), right(464));

int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}

extern int gbNoCDRom;

randomHeroCreatureInfo randomHeroArmyBounds[MAX_FACTIONS][2] = {
  {{CREATURE_PEASANT,  30, 50},{CREATURE_ARCHER,   3, 5}},
  {{CREATURE_GOBLIN,   15, 25},{CREATURE_ORC,      3, 5}},
  {{CREATURE_SPRITE,   10, 20},{CREATURE_DWARF,    2, 4}},
  {{CREATURE_CENTAUR,  6,  10},{CREATURE_GARGOYLE, 2, 4}},
  {{CREATURE_HALFLING, 6,  10},{CREATURE_BOAR,     2, 4}},
  {{CREATURE_SKELETON, 6,  10},{CREATURE_ZOMBIE,   2, 4}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_INVALID,  0,  0} ,{CREATURE_INVALID,  0, 0}},
  {{CREATURE_CYBER_KOBOLD_SPEARMAN, 6, 10},{CREATURE_CYBER_PLASMA_BERSERKER, 2, 4}}
};

int neutralTownCreatureTypes[MAX_FACTIONS][5] = {
  {CREATURE_PEASANT,  CREATURE_ARCHER,   CREATURE_PIKEMAN,    CREATURE_SWORDSMAN, CREATURE_CAVALRY},
  {CREATURE_GOBLIN,   CREATURE_ORC,      CREATURE_WOLF,       CREATURE_OGRE,      CREATURE_TROLL},
  {CREATURE_SPRITE,   CREATURE_DWARF,    CREATURE_ELF,        CREATURE_DRUID,     CREATURE_UNICORN},
  {CREATURE_CENTAUR,  CREATURE_GARGOYLE, CREATURE_GRIFFIN,    CREATURE_MINOTAUR,  CREATURE_HYDRA},
  {CREATURE_HALFLING, CREATURE_BOAR,     CREATURE_IRON_GOLEM, CREATURE_ROC,       CREATURE_MAGE},
  {CREATURE_SKELETON, CREATURE_ZOMBIE,   CREATURE_MUMMY,      CREATURE_VAMPIRE,   CREATURE_LICH},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_INVALID,  CREATURE_INVALID,  CREATURE_INVALID,    CREATURE_INVALID,   CREATURE_INVALID},
  {CREATURE_CYBER_KOBOLD_SPEARMAN, CREATURE_CYBER_PLASMA_BERSERKER, CREATURE_CYBER_PLASMA_LANCER, CREATURE_CYBER_INDIGO_PANTHER, CREATURE_CYBER_SHADOW_ASSASSIN},
};

int factionPortraitIconIdx[MAX_FACTIONS][2] = {
  {51, 70},
  {52, 71},
  {53, 72},
  {54, 73},
  {55, 74},
  {56, 75},
  {57, 76},
  {58, 77},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {82, 83}
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

		const int mapNameSize = 13;  // DOS 8+3 format
		if (lastPlayed.length() < mapNameSize) { // otherwise means no registry keys exist yet
			strcpy_s(gMapName, mapNameSize, lastPlayed.c_str());
			strcpy_s(this->mapFilename, sizeof(mapFilename), lastPlayed.c_str());
		}
	}
	this->InitNewGame_orig(a);
}

void game::ProcessRandomObjects() {
  giUltimateArtifactBaseX = -1;
  giUltimateArtifactBaseY = -1;
  giUltimateArtifactRadius = 0;
  //for(int resourceIdx = 0; resourceIdx < 7; ++resourceIdx)
  //  randomMineResources[resourceIdx] = 0;
  for(int y = 0; y < MAP_HEIGHT; ++y) {
    for(int x = 0; x < MAP_WIDTH; ++x) {
      mapCell *cell = &this->map.tiles[y * this->map.width] + x;
      int minFightValue, maxFightValue;
      bool randomSpawn = false;
      switch(cell->objType) {
        case TILE_HAS_EVENT | LOCATION_WINDMILL | LOCATION_SKELETON:
          giUltimateArtifactBaseX = x;
          giUltimateArtifactBaseY = y;
          giUltimateArtifactRadius = (unsigned __int8)((unsigned __int8)(cell->extraInfo >> 8) >> -5);
          cell->objType = 0;
          cell->objTileset &= 3u;
          cell->objectIndex = -1;
          continue;
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN:
          this->RandomizeTown(x, y, 0);
          continue;
        case TILE_HAS_EVENT | LOCATION_RANDOM_CASTLE:
          this->RandomizeTown(x, y, 1);
          continue;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER:
          minFightValue = 80;
          maxFightValue = 2000;
          randomSpawn = true;
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_WEAK:
          minFightValue = 0;
          maxFightValue = 400;
          randomSpawn = true;
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_MEDIUM:
          minFightValue = 400;
          maxFightValue = 1000;
          randomSpawn = true;
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_STRONG:
          minFightValue = 1000;
          maxFightValue = 2500;
          randomSpawn = true;
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_VERY_STRONG:
          minFightValue = 2500;
          maxFightValue = 100000;
          randomSpawn = true;          
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_RESOURCE:
          cell->objType = 155;
          int randomResource = Random(0, NUM_RESOURCES - 1);
          this->ConvertObject(x - 1, y, x - 1, y, 46, 16, 16, 46, 2 * randomResource, -1, -1);
          this->ConvertObject(x, y, x, y, 46, 17, 17, 46, 2 * randomResource + 1, -1, -1);
          if(randomResource && randomResource != RESOURCE_ORE)
          {
            if(randomResource == RESOURCE_GOLD)
              cell->extraInfo = cell->extraInfo & 7 | 8 * Random(5, 10);
            else
              cell->extraInfo = cell->extraInfo & 7 | 8 * Random(3, 7);
          } else {
            cell->extraInfo = cell->extraInfo & 7 | 8 * Random(8, 16);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT:
          int artIdx = this->GetRandomArtifactId(14, 0);
          cell->objType = 169;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 162, 162, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 163, 163, 11, 2 * artIdx + 1, -1, -1);
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_TREASURE:
          int artIdx = this->GetRandomArtifactId(8, 0);
          cell->objType = 169;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 166, 166, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 167, 167, 11, 2 * artIdx + 1, -1, -1);
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MINOR:
          int artIdx = this->GetRandomArtifactId(4, 0);
          cell->objType = 169;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 168, 168, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 169, 169, 11, 2 * artIdx + 1, -1, -1);
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MAJOR:
          int artIdx = this->GetRandomArtifactId(2, 0);
          cell->objType = 169;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 170, 170, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 171, 171, 11, 2 * artIdx + 1, -1, -1);
          break;
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN | LOCATION_SIGN:
          this->RandomizeMine(x, y);
          break;
        default:
          continue;
      }
      if(randomSpawn) {
        if((((unsigned __int8)cell->objTileset >> 2) & 0x3F) == 12 && cell->objectIndex >= CREATURE_RANDMON_1 && cell->objectIndex <= CREATURE_RANDMON_4) {
          switch(cell->objectIndex) {
            case CREATURE_RANDMON_1:
              minFightValue = 0;
              maxFightValue = 400;
              break;
            case CREATURE_RANDMON_2:
              minFightValue = 400;
              maxFightValue = 1000;
              break;
            case CREATURE_RANDMON_3:
              minFightValue = 1000;
              maxFightValue = 2500;
              break;
            case CREATURE_RANDMON_4:
              minFightValue = 2500;
              maxFightValue = 100000;
              break;
            default:
              break;
          }
        }
        cell->objType = 152;
        int randMon;
        int fightval;
        do {
          randMon = Random(0, MAX_BASE_CREATURE);
          fightval = gMonsterDatabase[randMon].fight_value;
        } while(fightval <= minFightValue && fightval >= maxFightValue);
        cell->objectIndex = randMon;
      }
    }
  }
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

void game::PerWeek() {
  PerWeek_orig();
  if (!IsWellDisabled()) {
    return;
  }

  for (int i = 0; i < MAX_TOWNS; ++i) {
    town &townObj = castles[i];
    for (int d = BUILDING_DWELLING_1; d <= BUILDING_UPGRADE_5B; ++d) {
      if (!townObj.BuildingBuilt(BUILDING_WELL) || !townObj.BuildingBuilt(d)) {
        continue;
      }

      // Undo the +2 growth provided by the Well. Unowned towns grow at half rate.
      const int dwellingIdx = d - BUILDING_DWELLING_1;
      if (townObj.ownerIdx >= 0) {
        townObj.numCreaturesInDwelling[dwellingIdx] -= 2;
      } else {
        townObj.numCreaturesInDwelling[dwellingIdx] -= 1;
      }
    }
  }
}

void game::PerMonth() {
  // Save the number of creatures in each dwelling in case we have to restore
  // them later. PerWeek() runs before this so all dwellings have increased
  // population at this point.
  int numCreatures[MAX_CASTLES][NUM_DWELLINGS];
  for (int c = 0; c < MAX_CASTLES; ++c) {
    town &townObj = castles[c];
    for (int d = 0; d < NUM_DWELLINGS; ++d) {
      numCreatures[c][d] = townObj.numCreaturesInDwelling[d];
    }
  }

  PerMonth_orig();
  if (!IsWellDisabled() || giMonthType != 2) {
    return;
  }

  // The math the original code does for Month of Plague is slightly off now
  // that I've disabled the Well. But I kinda hate the Plague anyway so I'll
  // just remove it.
  for (int c = 0; c < MAX_CASTLES; ++c) {
    town &townObj = castles[c];
    for (int d = 0; d < NUM_DWELLINGS; ++d) {
      townObj.numCreaturesInDwelling[d] = numCreatures[c][d];
    }
  }

  // One of the benign month types that don't do anything.
  giMonthType = 0;
  giMonthTypeExtra = Random(0, 9);
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

bool IsWellDisabled_impl() {
  const std::string key = "Disable Well";
  const DWORD wellSetting = read_pref<DWORD>(key);
  if (wellSetting == DWORD(-1)) {
    write_pref(key, 0ul);
    return false;
  }

  return wellSetting == 1;
}

bool IsWellDisabled() {
  static const bool isDisabled = IsWellDisabled_impl();
  return isDisabled;
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

void game::InitRandomArtifacts() {
  ResetGeneratedArtifacts();
  for (int i = 0; i < MAP_WIDTH; ++i) {
    for (int j = 0; j < MAP_HEIGHT; ++j) {
      const auto &tile = map.tiles[j * MAP_WIDTH + i];
      if (tile.objType == (TILE_HAS_EVENT | LOCATION_ARTIFACT)) {
        // Each artifact has two tiles. Convert from tile id to the artifact id.
        const int artifactId = static_cast<unsigned char>(tile.objectIndex) / 2;
        GenerateArtifact(artifactId);
      }
    }
  }
}

int game::GetRandomArtifactId(int allowedLevels, int allowNegatives) {
  int winConditionArtifact = -1;
  if (mapHeader.winConditionType == WIN_CONDITION_FIND_ARTIFACT) {
    winConditionArtifact = mapHeader.winConditionArgumentOrLocX - 1;
  }

  // Cursed artifacts are allowed 70% of the time, every time.
  const bool allowCursed = (allowNegatives && Random(0, 100) >= 30);

  std::vector<int> choices;
  const int numArtifacts = (xIsExpansionMap ? NUM_SUPPORTED_ARTIFACTS : MAX_BASE_ARTIFACT + 1);

  for (int i = 0; i < numArtifacts; ++i) {
    if ((GetArtifactLevel(i) & allowedLevels) == 0) {
      continue;
    }
    if (!IsArtifactGenerationAllowed(i)) {
      continue;
    }
    if (!allowCursed && IsCursedItem(i)) {
      continue;
    }
    if (i == winConditionArtifact) {
      continue;
    }

    choices.push_back(i);
  }

  // Ran out of artifacts (how'd you manage that?), so reset and try again.
  if (choices.empty()) {
    ResetGeneratedArtifacts(allowedLevels);
    return GetRandomArtifactId(allowedLevels, allowNegatives);
  }

  const auto artifactId = choices[Random(0, choices.size() - 1)];
  GenerateArtifact(artifactId);
  return artifactId;
}

void game::SetRandomHeroArmies(int heroIdx, int isAI) {
  double randomUpperBound;
  double randomLowerBound;
  armyGroup *heroArmy = &gpGame->heroes[heroIdx].army;
  bool hasTier[2];
  randomHeroCreatureInfo* creatureFaction = randomHeroArmyBounds[gpGame->heroes[heroIdx].factionID];

  hasTier[0] = 1;
  hasTier[1] = Random(0, 99) < 87;

  heroArmy->ClearArmy();
  for (int creatureTier = 0; creatureTier < 2; ++creatureTier) {
    if (hasTier[creatureTier]) {
      randomLowerBound = creatureFaction[creatureTier].lowQuantity;
      randomUpperBound = creatureFaction[creatureTier].highQuantity + 0.9;
      if (isAI) { //  If isAI, randomLowerBound is assigned the average of the bounds and this results in the probability of higher values
        randomLowerBound = (randomUpperBound + randomLowerBound) / 2;
      }
      const int numCreatures = Random(static_cast<int>(randomLowerBound), static_cast<int>(randomUpperBound));
      this->GiveArmy(heroArmy, creatureFaction[creatureTier].creatureType, numCreatures, creatureTier);
    }
  }
}

void armyGroup::ClearArmy() {
  for (int armySlotIdx = 0; armySlotIdx < 5; ++armySlotIdx) {
    this->creatureTypes[armySlotIdx] = -1;
    this->quantities[armySlotIdx] = -1;
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

  memset(heroExists, 0, MAX_HEROES);
  for (int y = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
      loc = &this->map.tiles[(y * this->map.width) + x];
      if (loc->getLocationType() == LOCATION_RANDOM_HERO || loc->objType == (TILE_HAS_EVENT | LOCATION_JAIL)) {
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
            faction = this->newGameSelectedFaction[gcColorToSetupPos[gpGame->players[mapExtraHero->owner].color]];// Constant here (I think this is a faction-related structure)
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
          if (mapExtraHero->field_11 && mapExtraHero->heroID >= MAX_HEROES) {
            this->heroes[randomHeroIdx].heroID = mapExtraHero->heroID;
          }
          mapExtraHero->heroID = randomHeroIdx;
        }
        randomHero = &this->heroes[mapExtraHero->heroID];

        if (!isJail && mapExtraHero->relatedToJailCondition) {
          this->heroes[mapExtraHero->heroID].relatedToX = x;
          randomHero->relatedToY = y;
          randomHero->relatedToFactionID = mapExtraHero->factionID;
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
          strcpy_s(randomHero->name, sizeof(randomHero->name), mapExtraHero->name);
        }
        randomHero->experience = 0;
        gpAdvManager->GiveExperience(randomHero, mapExtraHero->experience, 1);
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
          if (y > 0 && this->map.tiles[x + ((y - 1) * this->map.width)].objType == (TILE_HAS_EVENT | LOCATION_TOWN)) {
            --randomHero->relatedToY;
            --randomHero->y;
            this->castles[this->GetTownId(x, y - 1)].visitingHeroIdx = randomHero->idx;
          }
          loc->objTileset = 0;
          loc->objectIndex = -1;
          loc->extraInfo = 0;
          loc->objType = 0;
        }

        if (mapExtraHero->hasSecondarySkills) {
          randomHero->ClearSS();
          for (int i = 0; i < NUM_SECONDARY_SKILLS; ++i) {
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

int getCastleOwnedIdx(playerData *player, int castleIdx) {
  for (int i = 0; player->numCastles > i; ++i ) {
    if (player->castlesOwned[i] == castleIdx )
      return i;
  }
  return -1;
}

int game::getNumberOfThievesGuilds(int playerIdx) {
  int numGuilds = 0;
  for(int i = 0; this->players[playerIdx].numCastles > i; ++i) {
    if(gpGame->castles[this->players[playerIdx].castlesOwned[i]].buildingsBuiltFlags & BUILDING_TAVERN)
      ++numGuilds;
  }
  return numGuilds;
}

int __fastcall NewGameHandler(tag_message &msg) {
  if(!gbNewGameShadowHidden) {
    gbNewGameShadowHidden = 1;
    GUIRemoveFlag(gpGame->newGameWindow, 73, 6);
  }
  
  int keycode = msg.xCoordOrKeycode;
  if(keycode != GUI_MESSAGE_MOUSE_CLICK)
    return NewGameHandler_orig(msg);
  
  int field;
  switch(msg.yCoordOrFieldID) {
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
      field = msg.yCoordOrFieldID - 36;
      break;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
      field = msg.yCoordOrFieldID - 30;
      break;
    default:
      return NewGameHandler_orig(msg);
  }

  bool windowUpdate = false;
  bool remoteUpdate = false;
  if(gpGame->mapHeader.playerFactions[gpGame->relatedToPlayerPosAndColor[field]] == 7) {
    if(gpGame->newGameSelectedFaction[field] == 7) {
      gpGame->newGameSelectedFaction[field] = 0;
    } else {
      if(gpGame->newGameSelectedFaction[field] == 5)
        gpGame->newGameSelectedFaction[field] = 12;
      else {
        if(gpGame->newGameSelectedFaction[field] == 12)
          gpGame->newGameSelectedFaction[field] = 7;
        else
          ++gpGame->newGameSelectedFaction[field];
      }
    }
    remoteUpdate = true;
    windowUpdate = true;
  }

  if(windowUpdate) {
    gpGame->UpdateNewGameWindow();
    gpGame->newGameWindow->DrawWindow();
  }

  if(remoteUpdate && gbRemoteOn) {
    char v6[60];
    char v7[65];
    memcpy(&v6, gpGame->mapHeader.name, 0x3Cu);
    memcpy(&v7, &gpGame->relatedToPlayerPosAndColor, 0x41u);
    if(!TransmitRemoteData(v6, 127, 125, 51, 1, 1, -1))
      ShutDown(0);
  }
  return 1;
}

void game::RandomizeTown(int argX, int argY, int mightBeUseless) {
  int townID = this->GetTownId(argX, argY);
  TownExtra *twn = (TownExtra *)ppMapExtra[this->map.tiles[argX + argY * this->map.width].extraInfo];

  char faction;
  if(twn->color == -1)
    faction = FACTIONS_ACTUAL[Random(0, FACTIONS_ACTUAL.size() - 1)];
  else
    faction = this->newGameSelectedFaction[gcColorToSetupPos[twn->color]];
  this->castles[townID].field_55 = 10;
  this->castles[townID].factionID = faction;
  
  if(faction == FACTION_CYBORG)
    faction = 6; // follows the order from OBJNTOWN.ICN
  this->ConvertObject(argX - 5, argY - 3, argX + 2, argY + 1, 38, 0, 31, 35, 32 * faction, 48, 35);
  this->ConvertObject(argX - 5, argY - 3, argX + 2, argY + 1, 38, 32, 255, 37, 32 * faction, 48, 35);
  this->ConvertObject(argX - 5, argY - 3, argX + 2, argY + 1, 38, 0, 31, 35, 32 * faction, 49, 35);
  this->ConvertObject(argX - 5, argY - 3, argX + 2, argY + 1, 38, 32, 255, 37, 32 * faction, 49, 35);
}

void game::UpdateNewGameWindow() {
  strcpy(gText, this->mapHeader.name);
  GUISetText(this->newGameWindow, 64, gText);

  for(int i = 0; i < 5; ++i) {
    GUIRemoveFlag(this->newGameWindow, 67 + i, 4);
  }
  GUIAddFlag(this->newGameWindow, 67 + this->difficulty, 4);

  if(iLastMsgNumHumanPlayers > 1) {
    for(int i = 0; i < 3; ++i) {
      sprintf(gText, cTextReceivedBuffer[i]);
      GUISetText(this->newGameWindow, 74 + i, gText);
    }
  }

  for(int i = 0; this->mapHeader.numPlayers > i; ++i) {
    char playerID = this->somePlayerCodeOr10IfMayBeHuman[i];
    if(playerID == 10) {
      sprintf(gText, "");
    } else {
      if(strlen(cPlayerNames[playerID]))
        sprintf(gText, cPlayerNames[playerID]);
      else
        sprintf(gText, "Player %d", playerID + 1);
    }

    GUISetText(this->newGameWindow, 24 + i, gText);

    if(this->mapFilename[19] == i)
      GUIAddFlag(this->newGameWindow, 18 + i, 4);
    else
      GUIRemoveFlag(this->newGameWindow, 18 + i, 4);

    unsigned canChangeOpponent = !this->mapFilename[i + 13] && (iLastMsgNumHumanPlayers <= 1 || this->somePlayerCodeOr10IfMayBeHuman[i] == 10);

    int imgIdx;
    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      imgIdx = (canChangeOpponent < 1 ? 3 : 15) + this->relatedToPlayerPosAndColor[i];
    else
      imgIdx = (canChangeOpponent < 1 ? 9 : 21) + this->relatedToPlayerPosAndColor[i];
    if(iLastMsgNumHumanPlayers > 1)
      imgIdx = imgIdx + 24;
    GUISetImgIdx(this->newGameWindow, 12 + i, imgIdx);
    
    if(canChangeOpponent)
      GUIRemoveFlag(this->newGameWindow, 12 + i, 2);
    else
      GUIAddFlag(this->newGameWindow, 12 + i, 2);
    
    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      GUISetImgIdx(this->newGameWindow, 48 + i, 78);
    else
      GUISetImgIdx(this->newGameWindow, 48 + i, this->playerHandicap[i]);
   
    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      GUIRemoveFlag(this->newGameWindow, 48 + i, 2);
    else
      GUIAddFlag(this->newGameWindow, 48 + i, 2);
    
    GUIAddFlag(this->newGameWindow, 48 + i, 2);

    unsigned canChooseFaction = this->mapHeader.playerFactions[this->relatedToPlayerPosAndColor[i]] != 7;
    if(canChooseFaction < 1)
      imgIdx = factionPortraitIconIdx[this->newGameSelectedFaction[i]][0];
    else
      imgIdx = factionPortraitIconIdx[this->newGameSelectedFaction[i]][1];
    GUISetImgIdx(this->newGameWindow, 36 + i, imgIdx);

    sprintf(gText, gAlignmentNames[this->newGameSelectedFaction[i]]);
    GUISetText(this->newGameWindow, i + 78, gText);

    if(canChooseFaction)
      GUIRemoveFlag(this->newGameWindow, i + 78, 2);
    else
      GUIAddFlag(this->newGameWindow, i + 78, 2);
  }

  gpGame->gameDifficulty = this->CalcDifficultyRating();
  sprintf(gText, "%s %d%%", "Rating", gpGame->gameDifficulty);
  GUISetText(this->newGameWindow, 66, gText);
  this->DrawNGKPDisplayString(false);
}

void game::ShowScenInfo() {
  gpMouseManager->SetPointer("advmice.mse", 0, -999);

  heroWindow *window = new heroWindow(90, 4, "sceninfo.bin");
  if(!window)
    MemError();
  SetWinText(window, 23);

  GUISetText(window, 64, this->mapHeader.name);
  GUISetText(window, 200, cDifficulty[LOBYTE(this->mapHeader.field_4)]);
  GUISetText(window, 201, cDifficulty[this->difficulty]);
  sprintf(gText, "%d%%", this->CalcDifficultyRating());
  GUISetText(window, 202, gText);

  char *mapSizeStr;
  switch((unsigned char)this->mapHeader.width) {
    case 36:
      mapSizeStr = cMapSize[0];
      break;
    case 72:
      mapSizeStr = cMapSize[1];
      break;
    case 108:
      mapSizeStr = cMapSize[2];
      break;
    case 144:
      mapSizeStr = cMapSize[3];
      break;
    default:
      mapSizeStr = cMapSize[0];
  }
  GUISetText(window, 203, mapSizeStr);

  GUISetText(window, 204, this->mapHeader.description);
  this->GetVictoryConditionText(gText);
  GUISetText(window, 205, gText);
  this->GetLossConditionText(gText);
  GUISetText(window, 206, gText);
  
  int offX_all = 372 - 62 * this->mapHeader.numPlayers;
  int margin = offX_all / (this->mapHeader.numPlayers + 1);
  int offsetX = margin + 24;
  int itemWidth = margin + 62; // includes space between
  widget *guiObj = nullptr;
  for(int i = 0; this->mapHeader.numPlayers > i; ++i) {
    if(iLastMsgNumHumanPlayers > 1) {
      guiObj = new iconWidget(offsetX + i * itemWidth + 13, 309, 64, 28, "ngextra.icn", 59, 0, i + 42, 16, 1);
      if(!guiObj)
        MemError();
      window->AddWidget(guiObj, -1);

      guiObj = new iconWidget(offsetX + i * itemWidth + 16, 306, 62, 26, "ngextra.icn", 0, 0, i + 48, 16, 1);
      if(!guiObj)
        MemError();
      window->AddWidget(guiObj, -1);
    }
    int someCondition = ((iLastMsgNumHumanPlayers <= 1) - 1);
    guiObj = new iconWidget(offsetX + i * itemWidth + 11, 163, 68, (someCondition & 0x11) + 47, "ngextra.icn", (someCondition & 0xFFED) + 79, 0, i + 6, 16, 1);
    if(!guiObj)
      MemError();
    window->AddWidget(guiObj, -1);

    guiObj = new iconWidget(offsetX + i * itemWidth + 16, 160, 62, 58, "ngextra.icn", (someCondition & 0x18) + 3, 0, i + 12, 16, 1);
    if(!guiObj)
      MemError();
    window->AddWidget(guiObj, -1);

    textWidget *textWidg = nullptr;
    if(iLastMsgNumHumanPlayers > 1) {
      void *content = ALLOC(2u);
      sprintf((char *)content, " ");
      textWidg = new textWidget(offsetX + i * itemWidth + 19, 206, 56, 9, (char *)content, "smalfont.fnt", 1, i + 24, 512, 1);
      if(!textWidg)
        MemError();
      window->AddWidget(textWidg, -1);
    }

    guiObj = new iconWidget(offsetX + i * itemWidth + 11, 243, 64, 47, "ngextra.icn", 61, 0, i + 30, 16, 1);
    if(!guiObj)
      MemError();
    window->AddWidget(guiObj, -1);
    
    int v15;
    if(this->mapHeader.numPlayers < 5) {
      v15 = 26;
    } else {
      if(this->mapHeader.numPlayers < 6)
        v15 = 16;
      else
        v15 = 0;
    }
    void *content = ALLOC(2u);
    sprintf((char *)content, "A");
    textWidg = new textWidget(offsetX + i * itemWidth + 15 - v15 / 2, 288, v15 + 64, 12, (char *)content, "smalfont.fnt", 1, 78 + i, 512,  1);
    if(!textWidg)
      MemError();
    window->AddWidget(textWidg, -1);
    guiObj = new iconWidget(offsetX + i * itemWidth + 16, 240, 62, 45, "ngextra.icn", 51, 0, i + 36, 16, 1);
    if(!guiObj)
      MemError();
    window->AddWidget(guiObj, -1);
  }

  for(int i = 0; this->mapHeader.numPlayers > i; ++i) {
    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10) {
      sprintf(gText, "");
    } else {
      if(strlen(cPlayerNames[this->somePlayerCodeOr10IfMayBeHuman[i]]))
        sprintf(gText, cPlayerNames[this->somePlayerCodeOr10IfMayBeHuman[i]]);
      else
        sprintf(gText, "Player %d", this->somePlayerCodeOr10IfMayBeHuman[i] + 1);
    }
    GUISetText(window, 24 + i, gText);

    if(this->mapFilename[19] == i)
      GUIAddFlag(window, 18 + i, 4);
    else
      GUIRemoveFlag(window, 18 + i, 4);

    int imgIdx;
    unsigned int canChooseFaction = !this->mapFilename[i + 13] && (iLastMsgNumHumanPlayers <= 1 || this->somePlayerCodeOr10IfMayBeHuman[i] == 10);
    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      imgIdx = (canChooseFaction < 1 ? 3 : 15) + this->relatedToPlayerPosAndColor[i];
    else
      imgIdx = (canChooseFaction < 1 ? 9 : 21) + this->relatedToPlayerPosAndColor[i];
    if(iLastMsgNumHumanPlayers > 1)
      imgIdx += 24;
    GUISetImgIdx(window, 12 + i, imgIdx);

    if(canChooseFaction)
      GUIRemoveFlag(window, 12 + i, 2);
    else
      GUIAddFlag(window, 12 + i, 2);

    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      GUISetImgIdx(window, 48 + i, 78);
    else
      GUISetImgIdx(window, 48 + i, this->playerHandicap[i]);

    if(this->somePlayerCodeOr10IfMayBeHuman[i] == 10)
      GUIRemoveFlag(window, 48 + i, 2);
    else
      GUIAddFlag(window, 48 + i, 2);

    if(canChooseFaction < 1)
      imgIdx = factionPortraitIconIdx[this->newGameSelectedFaction[i]][0];
    else
      imgIdx = factionPortraitIconIdx[this->newGameSelectedFaction[i]][1];
    GUISetImgIdx(window, 36 + i, imgIdx);

    sprintf(gText, gAlignmentNames[this->newGameSelectedFaction[i]]);
    GUISetText(window, 78 + i, gText);
  }
  gpWindowManager->DoDialog(window, EventWindowHandler, 0);
  delete window;
}

extern short randomMineResources[];

