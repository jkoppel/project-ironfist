#include <string>
#include <vector>

#include "analytics.h"
#include "base.h"
#include "campaign/campaign.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "prefs.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"
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
	if(!gbInCampaign && !xIsPlayingExpansionCampaign && !strlen(gLastFilename)) { // game just started, no map was played yet
		std::string lastPlayed;
		if (xIsExpansionMap)
			lastPlayed = read_pref<std::string>("Last Map expansion");
		else
			lastPlayed = read_pref<std::string>("Last Map");

		const int mapNameSize = sizeof(mapFilename); // DOS 8+3 format
		if (lastPlayed.length() < mapNameSize) { // otherwise means no registry keys exist yet
			strcpy_s(gMapName, mapNameSize, lastPlayed.c_str());
			strcpy_s(this->mapFilename, mapNameSize, lastPlayed.c_str());
		}
	}
	this->InitNewGame_orig(a);
}

void game::NewMap(char* mapname) {
  send_event(mapAction, mapname);
  if(!gbInCampaign && !xIsPlayingExpansionCampaign) {
    if(xIsExpansionMap)
      write_pref("Last Map expansion", std::string(gMapName));
    else
      write_pref("Last Map", std::string(gMapName));
  }
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
	this->onMapEndCallbackStatus = false;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = false;
        }
    }
	for (int i = 0; i < MAX_HEROES; i++) {
		for (int j = 0; j < MAX_HEROES; j++) {
			this->forcedComputerPlayerChases[i][j] = false;
		}
	}
}

extern int gbGameOver;
extern int giEndSequence;

void __fastcall CheckEndGame(int a, int b) {
	CheckEndGame_orig(a, b);
	if (gbGameOver) {
		if (!gpGame->onMapEndCallbackStatus) {
			gpGame->onMapEndCallbackStatus = true;
			if (giEndSequence) {
				ScriptCallback("OnMapVictory");
			} else {
				ScriptCallback("OnMapLoss");
			}
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
      gpGame->hasCheated = 1;
      if (gbInCampaign)
        gpGame->campHasCheated = 1;
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

	int EvaluateHeroEvent_orig(int, int, int, int, int *);
	int EvaluateHeroEvent(int a1, int a2, int a3, int a4, int *a5);
};

void philAI::RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5) {
	if (gpGame->allowAIArmySharing) {
		RedistributeTroops_orig(army1, army2, a1, a2, a3, a4, a5);
	}
}

int philAI::EvaluateHeroEvent(int a1, int a2, int a3, int a4, int *a5) {
	hero *src = GetCurrentHero();
	hero *dst = &gpGame->heroes[a1];
	if (gpGame->forcedComputerPlayerChases[src->idx][dst->idx]) {
		return AI_VALUE_CAP;
	}
	return EvaluateHeroEvent_orig(a1, a2, a3, a4, a5);
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

extern int gbCampaignSideChoice;

extern icon* brotherIcon;
extern icon* backImage;
extern signed char bMainDone;
extern int gbNoSound;
extern unsigned long giSoundVolume;
extern unsigned long giMusicVolume;

extern int slowVideo;
extern int gbLowMemory;
extern int gbPlayedThrough;
extern int bTesting;

extern int gbLastFramePlayed;

extern int xLastChoice;
extern char byte_50FF36[];
extern char byte_50FF34[];
extern char byte_50FF35[];
extern char byte_50FF37[];
extern char byte_50FF38[];
extern char byte_524F14;
extern short word_50FF39;
extern short word_50FF3B;
extern int byte_4F74B8;

void __fastcall ConvertSmackerPalette(unsigned char *);
void __fastcall UpdatePalette(signed char *);
void __fastcall DoAdvance(struct SmackTag *,int,int,int,int);
extern struct SmackSumTag smksum;
extern struct SSmackOptions * SmackOptions;
extern SmackTag* smk1;
extern SmackTag* smk2;
extern int bSmackSound;
extern signed char bSmackNum;

void __fastcall SmackManagerMain() {
  gbLastFramePlayed = 0;

  if(bSmackNum == 35) {
    brotherIcon = gpResourceManager->GetIcon("brothers.icn");
    int x, y;
    gpMouseManager->MouseCoords(x, y);
    gbCampaignSideChoice = x < 320;
  }      

  KBChangeMenu(hmnuDflt);
  gpMouseManager->HideColorPointer();
  bMainDone = 1;

  char tmpPalette[PALETTE_SIZE];
  memcpy(&tmpPalette, gPalette->contents, PALETTE_SIZE);

  if(!gbNoSound && gpSoundManager->hdidriver && giSoundVolume && bSmackNum != 36) {
    bSmackSound = 1;
    if(AIL_get_preference(15)) {
      SmackSoundUseMSS(gpSoundManager->hdidriver);
      LogStr("SSSS 1");
    } else {
      SmackSoundUseDirectSound(*((unsigned *)gpSoundManager->hdidriver + 19));
      LogStr("SSSS 2");
    }
  } else {
    bSmackSound = 0;
  }
  
  char tmpStr[100];
  if(byte_4F74B8 && bSmackNum > 38) {
    strcpy(tmpStr, "i:\\projects\\heroes\\art\\fin3d\\");
  } else {
    if(bSmackNum == 67)
      strcpy(tmpStr, ".\\DATA\\");
    else
      strcpy(tmpStr, ".\\\\HEROES2\\ANIM\\");
  }

  if(slowVideo)
    sprintf(gText, "%s%s.SMK", &tmpStr, (char *)&SmackOptions + 45 * bSmackNum + 18);
  else
    sprintf(gText, "%s%s.SMK", &tmpStr, (char *)&SmackOptions + 45 * bSmackNum);

  unsigned int smackSoundFlag;
  if(bSmackSound)
    smackSoundFlag = 1040384;
  else
    smackSoundFlag = 0;

  int smackFlag;
  if(byte_50FF36[45 * bSmackNum])
    smackFlag = 512;
  else
    smackFlag = 0;
  if(gbLowMemory && bSmackNum == 30 && !slowVideo)
    smackFlag = 0;
  smk1 = nullptr;
  
  if(bSmackNum != 67) {
    while(!smk1) {
      smk1 = SmackOpen((HANDLE*)gText, smackSoundFlag + smackFlag, -1);
      if(!smk1) {
        gpWindowManager->FadeScreen(0, 128, 0);
        NormalDialog("Error reading the Heroes 2 Expansion CD.  Retry?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if(gpWindowManager->buttonPressedCode == 30726)
          ShutDown("CDROM drive error.  Exiting.");
      }
    }
    SmackToBuffer(smk1, 0, 0, 640, 480, *(unsigned *)((char *)gpWindowManager->screenBuffer + 22), 0);
  }
  
  if(strlen((char *)&SmackOptions + 45 * bSmackNum + 9) > 1) {
    if(slowVideo)
      sprintf(gText, "%s%s.SMK", &tmpStr, (char *)&SmackOptions + 45 * bSmackNum + 27);
    else
      sprintf(gText, "%s%s.SMK", &tmpStr, (char *)&SmackOptions + 45 * bSmackNum + 9);
    int v0 = ((unsigned int)bSmackSound < 1) - 1;
    smk2 = SmackOpen((HANDLE*)gText, v0 & 0xFE000, -1);
    if(byte_50FF38[45 * bSmackNum]) {
      if(!slowVideo && bSmackNum != 67)
        SmackToBuffer(
          smk2,
          *(__int16 *)((char *)&word_50FF39 + 45 * bSmackNum),
          *(__int16 *)((char *)&word_50FF3B + 45 * bSmackNum),
          640,
          480,
          *(int *)((char *)gpWindowManager->screenBuffer + 22),
          0);
    }
  }

  FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0);
  BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  if(byte_50FF34[45 * bSmackNum])
    gpWindowManager->FadeScreen(1, 128, 0);

  if(bSmackNum == 35) {
    Process1WindowsMessage();
    while(gpInputManager->GetEvent().eventCode != NULL){
    
    }
  }
   
  int v25 = 0;
  int v22 = 0;
  int breakFlag = 1;
  int v24 = 0;
  while(breakFlag) {
    if(bSmackNum == 67) {
      if(!v25) {
        gpMouseManager->SetPointer("advmice.mse", 40, -999);
        gpMouseManager->ReallyShowPointer();
        gpSoundManager->PlayAmbientMusic(42, 0, -1);
        backImage = gpResourceManager->GetIcon("x_ivy.icn");
        if(!backImage)
          MemError();
        backImage->DrawToBuffer(0, 0, 0, 0);
        backImage->DrawToBuffer(0, 0, 1, 0);
        sprintf(gText, "%s%s.SMK", &tmpStr, "IVYPOL");
        smk2 = SmackOpen((HANDLE*)gText, 0, -1);
        memcpy(gPalette->contents, (char *)smk2 + 108, PALETTE_SIZE);
        SmackClose(smk2);
        smk2 = nullptr;
        ConvertSmackerPalette((unsigned char*)gPalette->contents);
        UpdatePalette(gPalette->contents);
        memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
        gpWindowManager->FadeScreen(0, 4, 0);
        v25 = 1;
      }
    } else {
      if(!SmackWait(smk1)) {
        if(bSmackNum == 3 && !v24) {
          v24 = 1;
          gpSoundManager->PlayAmbientMusic(19, 0, -1);
        }
        if((!v25 || *((unsigned *)smk1 + 3) > 1u)
          && (bSmackNum != 2 || *((unsigned *)smk1 + 3) - 1 != *((unsigned *)smk1 + 221))) {
          int v4 = v25 || !byte_50FF34[45 * bSmackNum];
          DoAdvance(smk1, 1, 1, v4, 0);
        }
        if(*((unsigned *)smk1 + 221) || *((unsigned *)smk1 + 3) <= 1u) {
          if(!v25) {
            if(bSmackNum == 35) {
              gpMouseManager->SetPointer("advmice.mse", 40, -999);
              gpMouseManager->ReallyShowPointer();
            }
            if(byte_50FF34[45 * bSmackNum]) {
              memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
              gpWindowManager->FadeScreen(0, 4, 0);
            }
            if(bSmackNum == 36)
              gpSoundManager->PlayAmbientMusic(42, 0, -1);
            if(bSmackNum == 72)
              gpSoundManager->PlayAmbientMusic(42, 0, -1);
          }
          v25 = 1;
        }
      }
    }
    if(smk2 && v25 && !SmackWait(smk2)) {
      if(v22 && *((unsigned *)smk2 + 3) - 1 == *((unsigned *)smk2 + 221)) {
        int v14 = 0;
        int v13;
        if(!byte_50FF38[45 * bSmackNum] || slowVideo) {
          if(bSmackNum == 67) {
            v13 = 1;
            v14 = 1;
          } else {
            v13 = 0;
          }
        } else {
          v13 = 1;
        }
        DoAdvance(smk2, v13, v14, 0, 1);
        gbLastFramePlayed = 1;
        while(SmackWait(smk2))
          Process1WindowsMessage();
      } else {
        if(bSmackNum == 67)
          DoAdvance(smk2, 1, 1, 0, 1);
        else
          DoAdvance(smk2, byte_50FF38[45 * bSmackNum], 1, 0, 1);
      }
      if(smk2 && *((unsigned *)smk2 + 221))
        v22 = 1;
    }
    Process1WindowsMessage();
    tag_message msg;
    memcpy(&msg, &gpInputManager->GetEvent(), sizeof(tag_message));
    if((unsigned int)(msg.eventCode - 1) <= 0x1F) {
      switch(msg.eventCode) {
        case 4:
          if(bSmackNum == 35) {
            int mouseX, mouseY;
            gpMouseManager->MouseCoords(mouseX, mouseY);
            int v10 = mouseX < 320;
            if(v10 != gbCampaignSideChoice) {
              gbCampaignSideChoice = v10;
              if(v10 == 1) {
                brotherIcon->DrawToBuffer(0, 0, 0, 0);
                brotherIcon->DrawToBuffer(0, 0, 3, 0);
              } else {
                brotherIcon->DrawToBuffer(0, 0, 1, 0);
                brotherIcon->DrawToBuffer(0, 0, 2, 0);
              }
              BlitBitmapToScreen(gpWindowManager->screenBuffer, 49, 78, 0x21Au, 258, 49, 78);
            }
          } else {
            if(bSmackNum == 67) {
              int mouseX, mouseY;
              gpMouseManager->MouseCoords(mouseX, mouseY);
              int selectedCampaignRect = ExpansionCampaignRect(mouseX, mouseY);
              if(selectedCampaignRect != xLastChoice) {
                backImage->DrawToBuffer(0, 0, 0, 0);
                BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
                xLastChoice = selectedCampaignRect;
                if(smk2) {
                  SmackClose(smk2);
                  smk2 = nullptr;
                }
                if(selectedCampaignRect != -1) {
                  byte_524F14 = selectedCampaignRect + 68;
                  sprintf(gText, "%s%s.SMK", &tmpStr, (char *)&SmackOptions + 45 * (char)(selectedCampaignRect + 68));
                  int v1 = ((unsigned int)bSmackSound < 1) - 1;
                  smk2 = SmackOpen((HANDLE*)gText, v1 & 0xFE000, -1);
                  SmackToBuffer(
                    smk2,
                    *(__int16 *)((char *)&word_50FF39 + 45 * byte_524F14),
                    *(__int16 *)((char *)&word_50FF3B + 45 * byte_524F14),
                    640,
                    480,
                    *(unsigned *)((char *)gpWindowManager->screenBuffer + 22),
                    0);
                  backImage->DrawToBuffer(0, 0, 1, 0);
                }
              }
            }
          }
          break;
        case 1:
          if(msg.xCoordOrKeycode != 62)
            goto LABEL_124;
          break;
        case 32:
        LABEL_124:
          if(bSmackNum != 35 && bSmackNum != 67)
            goto LABEL_126;
          break;
        case 8:
        LABEL_126:
          if(bSmackNum != 37 && (bSmackNum != 67 || xLastChoice != -1))
            goto LABEL_156;
          break;
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
          break;
      }
    }
    if(bSmackNum == 2 && *((unsigned *)smk1 + 221) + 1 == *((unsigned *)smk1 + 3) && !v24) {
      v24 = 1;
      gpSoundManager->PlayAmbientMusic(43, 0, -1);
    }
    if(!byte_50FF37[45 * bSmackNum]) {
      int v3;
      if(gbLastFramePlayed || smk2 && (bSmackNum < 39 ? (*((unsigned *)smk2 + 221) < *((unsigned *)smk2 + 3) ? (v3 = 0) : (v3 = 1)) : (unsigned int)(*((unsigned *)smk2 + 3) - 1) > *((unsigned *)smk2 + 221) ? (v3 = 0) : (v3 = 1),
          v3 || !*((unsigned *)smk2 + 221) && v22)
        || !smk2 && (*((unsigned *)smk1 + 221) >= *((unsigned *)smk1 + 3) || !*((unsigned *)smk1 + 221) && v25)) {
        breakFlag = 0;
        gbPlayedThrough = 1;
      }
    }
  }
LABEL_156:
  if(bSmackNum == 35) {
    gpMouseManager->HideColorPointer();
    gpMouseManager->SetPointer("advmice.mse", 0, -999);
  }
  if(byte_50FF35[45 * bSmackNum]) {
    memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
    gpWindowManager->FadeScreen(1, 8, 0);
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 36);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  } else {
    if(!gbPlayedThrough && bSmackNum != 2) {
      memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
      gpWindowManager->FadeScreen(1, 128, 0);
      FillBitmapArea((bitmap *)gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 36);
      BlitBitmapToScreen((bitmap *)gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
    }
  }

  if(bTesting)
    SmackSummary(smk1, &smksum);

  if(smk1)
    SmackClose(smk1);

  smk1 = nullptr;
  if(smk2)
    SmackClose(smk2);

  smk2 = nullptr;
  if(bSmackNum != 2) {
    memcpy(gPalette->contents, &tmpPalette, PALETTE_SIZE);
    UpdatePalette(gPalette->contents);
  }

  gpMouseManager->ShowColorPointer();
  if(brotherIcon)
    gpResourceManager->Dispose(brotherIcon);

  brotherIcon = nullptr;
  if(backImage)
    gpResourceManager->Dispose(backImage);

  backImage = nullptr;
}