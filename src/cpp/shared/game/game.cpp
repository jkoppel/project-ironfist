#include <string>
#include <vector>
#include <Windows.h>

#include "analytics.h"
#include "adventure/hero_globals.h"
#include "adventure/terrain.h"
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
#include "smacker.h"
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
  {{CREATURE_CYBER_KOBOLD_SPEARMAN, 8, 12},{CREATURE_CYBER_PLASMA_BERSERKER, 3, 6}}
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

std::vector<CREATURES> monthSpecificCreatures = {
  CREATURE_PEASANT,
  CREATURE_TROLL,
  CREATURE_DWARF,
  CREATURE_ROC,
  CREATURE_OGRE,
  CREATURE_DRUID,
  CREATURE_VAMPIRE,
  CREATURE_WOLF,
  CREATURE_CENTAUR,
  CREATURE_GARGOYLE,
  CREATURE_UNICORN,
  CREATURE_LICH
};

int game::SetupGame() {
  LogStr("Setup 0");
  xIsPlayingExpansionCampaign = 0;
  xIsExpansionMap = 0;
  gbInCampaign = 0;
  gbCampaignSideChoice = 0;
  iMPExtendedType = 10;
  iMPBaseType = 10;
  iLastMsgNumHumanPlayers = 1;
  gbWaitForRemoteReceive = 0;
  gbDirectConnect = 0;
  gbInSetupDialog = 1;
  if(giMenuCommand == -1) {
    heroWindow *win = new heroWindow(405, 8, "stpnewgm.bin");
    if ( !win )
      MemError();
    gpWindowManager->DoDialog(win, SetupGameHandler, 0);
    delete win;
    int code = LOWORD(gpWindowManager->buttonPressedCode);
    if(code <= BUTTON_CANCEL) {
      if(code == BUTTON_CANCEL) {
        gbInSetupDialog = 0;
        return 0;
      }
      if(code != 1) {
        if(code == 2) {
          heroWindow *window = new heroWindow(405, 8, "x_loadcm.bin");
          if(!window)
            MemError();
          gpWindowManager->DoDialog(window, ExpLoadCampaignHandler, 0);
          delete window;
          int pressedCode = LOWORD(gpWindowManager->buttonPressedCode);
          switch(pressedCode) {
            case 1:
              gbInCampaign = 1;
              if(giSetupGameType != 1 && !game::SetupCampaignGame()) {
                gbInSetupDialog = 0;
                return 0;
              }
              break;
            case 2:
              xIsPlayingExpansionCampaign = 1;
              xIsExpansionMap = 1;
              if(giSetupGameType != 1) {
                int campID = xCampaign.Choose();
                xCampaign.InitNewCampaign(campID);
              }
              break;
            case 3: {
              xIsPlayingExpansionCampaign = 1;
              xIsExpansionMap = 1;
              int campID = LoadCampaignFromFile("cyborg.cmp");
              xCampaign.campaignID = campID;
              if(campID == -1) {
                gbInSetupDialog = 0;
                return 0;
              }
              if(giSetupGameType != 1)
                xCampaign.InitNewCampaign(campID);
              break;
            }
            case 4:
              xIsPlayingExpansionCampaign = 1;
              xIsExpansionMap = 1;
              xCampaign.campaignID = 5;
              if(giSetupGameType != 1) {                
                // This is done in order to avoid error messages hardcoded in fileRequester::Main
                int tmp = giDebugLevel;
                int tmp2 = iLastMsgNumHumanPlayers;
                iLastMsgNumHumanPlayers = 999;
                giDebugLevel = 3;

                fileRequester* fileChoiceDialog = new fileRequester(200, 58, 2, "*.cmp", ".\\CAMPAIGNS\\", "*.cmp");
                if(!fileChoiceDialog)
                  MemError();
                int buttonPressed = gpExec->DoDialog(fileChoiceDialog);
                delete fileChoiceDialog;

                giDebugLevel = tmp;
                iLastMsgNumHumanPlayers = tmp2;

                if(buttonPressed == BUTTON_OK) {
                  int campID = LoadCampaignFromFile(gLastFilename);
                  if(campID == -1) {
                    gbInSetupDialog = 0;
                    return 0;
                  }
                  xCampaign.InitNewCampaign(campID);
                } else {
                  gbInSetupDialog = 0;
                  return 0;
                }
              }
              break;
            case BUTTON_CANCEL:
              gbInSetupDialog = 0;
              return 0;
          }
        } else {
          if(code == 3) {
            int oldNoCDRom = gbNoCDRom;
            gbNoCDRom = 0;
            int res = this->SetupMultiPlayerGame();
            gbNoCDRom = oldNoCDRom;
            if(!res) {
              gbInSetupDialog = 0;
              return 0;
            }
          }
        }
      }
    }
    LogStr(" Setup 1");
    if(iMPBaseType == 1 || !iMPBaseType) {
      LogStr(" Setup 2");
      RemoteMain(iMPExtendedType);
      LogStr(" Setup 3");
      if(iMPExtendedType == 2 || iMPExtendedType == 4)
        gbWaitForRemoteReceive = 1;
    }
  } else {
    if((unsigned int)(giMenuCommand - 40102) <= 36) {
      switch(giMenuCommand) {
        case 40110:
        case 40127:
          iLastMsgNumHumanPlayers = 2;
          iMPBaseType = 2;
          break;
        case 40111:
        case 40128:
          iLastMsgNumHumanPlayers = 3;
          iMPBaseType = 2;
          break;
        case 40112:
        case 40129:
          iLastMsgNumHumanPlayers = 4;
          iMPBaseType = 2;
          break;
        case 40114:
        case 40131:
          iMPBaseType = 1;
          iMPExtendedType = 1;
          goto LABEL_12;
        case 40115:
        case 40132:
          iMPBaseType = 1;
          iMPExtendedType = 2;
          goto LABEL_12;
        case 40117:
        case 40134:
          iMPBaseType = 0;
          iMPExtendedType = 3;
          goto LABEL_12;
        case 40118:
        case 40135:
          iMPBaseType = 0;
          iMPExtendedType = 4;
          goto LABEL_12;
        case 40120:
        case 40137:
          iMPBaseType = 0;
          iMPExtendedType = 3;
          gbDirectConnect = 1;
          goto LABEL_12;
        case 40121:
        case 40138:
          iMPBaseType = 0;
          iMPExtendedType = 4;
          gbDirectConnect = 1;
        LABEL_12:
          LogStr("Setup 0a");
          RemoteMain(iMPExtendedType);
          if(iMPExtendedType == 2 || iMPExtendedType == 4)
            gbWaitForRemoteReceive = 1;
          break;
        case 40102:
        case 40123:
          break;
      }
    }
    giMenuCommand = -1;
    gbInSetupDialog = 0;
    return 1;
  }
  gbInSetupDialog = 0;
  return 1;
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

void game::ProcessRandomObjects() {
  giUltimateArtifactBaseX = -1;
  giUltimateArtifactBaseY = -1;
  giUltimateArtifactRadius = 0;
  for(int resourceIdx = 0; resourceIdx < 7; ++resourceIdx)
    randomMineResources[resourceIdx] = 0;
  for(int y = 0; y < MAP_HEIGHT; ++y) {
    for(int x = 0; x < MAP_WIDTH; ++x) {
      mapCell *cell = &this->map.tiles[y * this->map.width + x];
      int minFightValue, maxFightValue;
      bool randomSpawn = false;
      switch(cell->objType) {
        case TILE_HAS_EVENT | LOCATION_ULTIMATE_ARTIFACT:
          giUltimateArtifactBaseX = x;
          giUltimateArtifactBaseY = y;
          giUltimateArtifactRadius = cell->extraInfo;
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
        case TILE_HAS_EVENT | LOCATION_RANDOM_RESOURCE: {
          cell->objType = TILE_HAS_EVENT | LOCATION_RESOURCE;
          int randomResource = Random(0, NUM_RESOURCES - 1);
          this->ConvertObject(x - 1, y, x - 1, y, 46, 16, 16, 46, 2 * randomResource, -1, -1);
          this->ConvertObject(x, y, x, y, 46, 17, 17, 46, 2 * randomResource + 1, -1, -1);
          if(randomResource && randomResource != RESOURCE_ORE)
          {
            if(randomResource == RESOURCE_GOLD)
              cell->extraInfo = Random(5, 10);
            else
              cell->extraInfo = Random(3, 7);
          } else {
            cell->extraInfo = Random(8, 16);
          }
          break;
        }
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT: {
          int artIdx = this->GetRandomArtifactId(14, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 162, 162, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 163, 163, 11, 2 * artIdx + 1, -1, -1);
          break;
        }
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_TREASURE: {
          int artIdx = this->GetRandomArtifactId(8, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 166, 166, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 167, 167, 11, 2 * artIdx + 1, -1, -1);
          break;
        }
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MINOR: {
          int artIdx = this->GetRandomArtifactId(4, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 168, 168, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 169, 169, 11, 2 * artIdx + 1, -1, -1);
          break;
        }
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MAJOR: {
          int artIdx = this->GetRandomArtifactId(2, 0);
          cell->objType = TILE_HAS_EVENT | LOCATION_ARTIFACT;
          this->ConvertObject(x - 1, y, x - 1, y, 11, 170, 170, 11, 2 * artIdx, -1, -1);
          this->ConvertObject(x, y, x, y, 11, 171, 171, 11, 2 * artIdx + 1, -1, -1);
          break;
        }
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN | LOCATION_SIGN:
          this->RandomizeMine(x, y);
          break;
        default:
          continue;
      }
      if(randomSpawn) {
        if(cell->objTileset == TILESET_MONSTER && cell->objectIndex >= CREATURE_RANDMON_1 && cell->objectIndex <= CREATURE_RANDMON_4) {
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
        cell->objType = TILE_HAS_EVENT | LOCATION_ARMY_CAMP;
        int randMon;
        int fightval;
        do {
          randMon = CREATURES_RANDOMIZABLE.at(Random(0, CREATURES_RANDOMIZABLE.size()-1));
          fightval = gMonsterDatabase[randMon].fight_value;
        } while(fightval <= minFightValue || fightval >= maxFightValue);
        cell->objectIndex = randMon;
      }
    }
  }
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
  for(int i = 0; i < NUM_PLAYERS; i++) {
    if(gpGame->newGameSelectedFaction[i] == FACTION_RANDOM)
      gpGame->newGameSelectedFaction[i] = FACTIONS_ACTUAL[Random(0, FACTIONS_ACTUAL.size() - 1)];;
  }
  ScriptingInit(std::string(mapname));
  this->NewMap_orig(mapname);  
  gpGame->firstDayEventDone = false;
  gpGame->allowAIArmySharing = true;
  for(int i = 0; i < (unsigned)disallowedBuildings->size(); i++) {
    if(!gpGame->castles[i].CanBuildDock())
      disallowedBuildings[i][BUILDING_DOCK] = true;
  }
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
  giWeekType = WEEK_REGULAR;
  giWeekTypeExtra = Random(0, 14);

  // 25% chance for creature specific week when it's not new month
  if(this->week != 4 && Random(1, 4) == 1) {
    giWeekType = WEEK_CREATURE;
    giWeekTypeExtra = CREATURES_RANDOMIZABLE.at(Random(0, CREATURES_RANDOMIZABLE.size()-1));
  }

  for(int townIdx = 0; townIdx < MAX_TOWNS; ++townIdx) {
    town *twn = &this->castles[townIdx];
    for(int i = BUILDING_DWELLING_1; i <= BUILDING_UPGRADE_5B; ++i) {
      if(!twn->BuildingBuilt(i))
        continue;
      int growth = gMonsterDatabase[gDwellingType[twn->factionID][i - 19]].growth;
      if(twn->BuildingBuilt(BUILDING_WELL))
        growth += 2;
      if(i == BUILDING_DWELLING_1 && twn->BuildingBuilt(BUILDING_SPECIAL_GROWTH))
        growth += 8;
      int owner = twn->ownerIdx;
      if(owner == -1)
        growth /= 2;
      if(owner >= 0 && !twn->numCreaturesInDwelling[i - 19] && !gbHumanPlayer[owner]) {
        if(gpGame->difficulty == 2)
          growth = (signed __int64)((double)growth * 1.2);
        if(gpGame->difficulty == 3)
          growth = (signed __int64)((double)growth * 1.32);
        if(gpGame->difficulty == 4)
          growth = (signed __int64)((double)growth * 1.44);
      }
      if(giWeekType == WEEK_CREATURE) {
        if(gDwellingType[twn->factionID][i - 19] == giWeekTypeExtra)
          growth += 5;
      }
      twn->numCreaturesInDwelling[i - 19] += growth;
    }
  }

  for(int playerIdx = 0; playerIdx < NUM_PLAYERS; ++playerIdx) {
    for(int j = 0; j < 2; ++j) {
      int heroIdx = gpGame->players[playerIdx].heroesForPurchase[j];
      int randomFactionIdx = NULL;
      if(j == 1)
        randomFactionIdx = this->heroes[heroIdx].factionID;
      randomFactionIdx = (randomFactionIdx + Random(1, 5)) % NUM_ORIG_FACTIONS;
      int faction = randomFactionIdx;
      if(j == 0 && faction < FACTION_MULTIPLE)
        faction = this->newGameSelectedFaction[gcColorToSetupPos[this->players[playerIdx].color]];

      char hire = gpGame->heroHireStatus[heroIdx];
      if(hire != 64 || !(gpGame->heroes[heroIdx].flags) & (1 << 16)) {
        if(hire == 64)
          hire = -1;
        if(j == 1 && !gbHumanPlayer[playerIdx])
          faction = -1;
        int getPowerfulHero = !gbHumanPlayer[playerIdx] && gpGame->difficulty > 0;
        gpGame->players[playerIdx].heroesForPurchase[j] = gpGame->GetNewHeroId(playerIdx, faction, getPowerfulHero);
        this->heroHireStatus[heroIdx] = 64;
      }
    }
  }

  for(int j = 0; MAP_HEIGHT > j; ++j) {
    for(int i = 0; i < MAP_WIDTH; ++i) {
      mapCell *tile = &this->map.tiles[j * this->map.width + i];
      switch(tile->objType) {
        case TILE_HAS_EVENT | LOCATION_ARMY_CAMP: {
          int currentQty = (unsigned char)tile->extraInfo;
          int addQty = currentQty / 7;
          if(Random(1, 7) <= currentQty % 7)
            ++addQty;
          int newQty = addQty + currentQty;
          if(tile->extraInfo & 0x1000)
            newQty |= 0x1000;
          tile->extraInfo = newQty;
          break;
        }
        case TILE_HAS_EVENT | LOCATION_ARTESIAN_SPRING:
          tile->extraInfo |= 1;
          break;
        case TILE_HAS_EVENT | LOCATION_WATERWHEEL:
          if(tile->extraInfo != 255) {
            tile->extraInfo |= 2;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_MAGIC_GARDEN:
          if(Random(0, 1)) {
            tile->extraInfo = 6;
          } else {
            tile->extraInfo = 7;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_WINDMILL:
          tile->extraInfo = Random(1, 5);
          break;
        case TILE_HAS_EVENT | LOCATION_ARCHERS_HOUSE:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(2, 4);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_GOBLIN_HUT:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(3, 6);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_DWARF_COTTAGE:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(2, 4);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_PEASANT_HUT:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(5, 10);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_LOG_CABIN:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(5, 10);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_DESERT_TENT:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(1, 3);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_WAGON_CAMP:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(3, 6);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_TREE_HOUSE:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(4, 8);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_DWARF_CABIN:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(3, 6);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_WATCH_TOWER:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(1, 4);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_RUINS:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(1, 3);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_TREE_CITY:
          if(tile->extraInfo < 8161) {
            tile->extraInfo += Random(10, 20);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_CAVE:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(3, 6);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_EXCAVATION:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(4, 8);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_HALFLING_HOLE:
          if(tile->extraInfo < 8171) {
            tile->extraInfo += Random(5, 10);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_TROLL_BRIDGE:
          if(!(tile->extraInfo & 0x80) && tile->extraInfo < 220) {
            tile->extraInfo += Random(1, 3);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_CITY_OF_DEAD:
          if(!(tile->extraInfo & 0x80) && tile->extraInfo < 220) {
            tile->extraInfo += Random(1, 3);
          }
          break;
        case TILE_HAS_EVENT | LOCATION_DRAGON_CITY:
          if(!(tile->extraInfo & 0x80) && tile->extraInfo < 220) {
            tile->extraInfo += 1;
          }
          break;
        case TILE_HAS_EVENT | LOCATION_EXPANSION_DWELLING:
          this->WeeklyRecruitSite(tile);
          break;
        case TILE_HAS_EVENT | LOCATION_ALCHEMIST_TOWER:
          this->WeeklyGenericSite(tile);
          break;
        case TILE_HAS_EVENT | LOCATION_ROAD:
        case TILE_HAS_EVENT | LOCATION_EVENT:
        case TILE_HAS_EVENT | LOCATION_LIGHTHOUSE:
        case TILE_HAS_EVENT | LOCATION_MINE:
        case TILE_HAS_EVENT | LOCATION_OBELISK:
        case TILE_HAS_EVENT | LOCATION_OASIS:
        case TILE_HAS_EVENT | LOCATION_RESOURCE:
        case TILE_HAS_EVENT | LOCATION_ARMY_CAMP | LOCATION_SKELETON:
        case TILE_HAS_EVENT | LOCATION_SAWMILL:
        case TILE_HAS_EVENT | LOCATION_ORACLE:
        case TILE_HAS_EVENT | LOCATION_SHRINE_FIRST_ORDER:
        case TILE_HAS_EVENT | LOCATION_SHIPWRECK:
        case TILE_HAS_EVENT | LOCATION_SEA_CHEST:
        case TILE_HAS_EVENT | LOCATION_TOWN:
        case TILE_HAS_EVENT | LOCATION_STONE_LITHS:
        case TILE_HAS_EVENT | LOCATION_WELL:
        case TILE_HAS_EVENT | LOCATION_WHIRLPOOL:
        case TILE_HAS_EVENT | LOCATION_ARTIFACT:
        case TILE_HAS_EVENT | LOCATION_HERO:
        case TILE_HAS_EVENT | LOCATION_BOAT:
        case TILE_HAS_EVENT | LOCATION_WINDMILL | LOCATION_SKELETON:
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT:
        case TILE_HAS_EVENT | LOCATION_RANDOM_RESOURCE:
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER:
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN:
        case TILE_HAS_EVENT | LOCATION_RANDOM_CASTLE:
        case TILE_HAS_EVENT | LOCATION_RANDOM_TOWN | LOCATION_SIGN:
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_WEAK:
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_MEDIUM:
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_STRONG:
        case TILE_HAS_EVENT | LOCATION_RANDOM_MONSTER_VERY_STRONG:
        case TILE_HAS_EVENT | LOCATION_RANDOM_HERO:
        case TILE_HAS_EVENT | LOCATION_NOTHING_SPECIAL:
        case TILE_HAS_EVENT | LOCATION_NOTHING_SPECIAL | LOCATION_ALCHEMIST_LAB:
        case TILE_HAS_EVENT | LOCATION_FORT:
        case TILE_HAS_EVENT | LOCATION_TRADING_POST:
        case TILE_HAS_EVENT | LOCATION_ABANDONED_MINE:
        case TILE_HAS_EVENT | LOCATION_STANDING_STONES:
        case TILE_HAS_EVENT | LOCATION_IDOL:
        case TILE_HAS_EVENT | LOCATION_TREE_OF_KNOWLEDGE:
        case TILE_HAS_EVENT | LOCATION_WITCH_DOCTORS_HUT:
        case TILE_HAS_EVENT | LOCATION_TEMPLE:
        case TILE_HAS_EVENT | LOCATION_HILL_FORT:
        case TILE_HAS_EVENT | LOCATION_MERCENARY_CAMP:
        case TILE_HAS_EVENT | LOCATION_SHRINE_SECOND_ORDER:
        case TILE_HAS_EVENT | LOCATION_SHRINE_THIRD_ORDER:
        case TILE_HAS_EVENT | LOCATION_PYRAMID:
        case TILE_HAS_EVENT | LOCATION_SPHINX:
        case TILE_HAS_EVENT | LOCATION_WAGON:
        case TILE_HAS_EVENT | LOCATION_TAR_PIT:
        case TILE_HAS_EVENT | LOCATION_WATERING_HOLE:
        case TILE_HAS_EVENT | LOCATION_WITCH_HUT:
        case TILE_HAS_EVENT | LOCATION_XANADU:
        case TILE_HAS_EVENT | LOCATION_LEAN_TO:
        case TILE_HAS_EVENT | LOCATION_MAGELLANS_MAPS:
        case TILE_HAS_EVENT | LOCATION_FLOTSAM:
        case TILE_HAS_EVENT | LOCATION_DERELICT_SHIP:
        case TILE_HAS_EVENT | LOCATION_SHIPWRECK_SURVIVOR:
        case TILE_HAS_EVENT | LOCATION_BOTTLE:
        case TILE_HAS_EVENT | LOCATION_MAGIC_WELL:
        case TILE_HAS_EVENT | LOCATION_OBSERVATION_TOWER:
        case TILE_HAS_EVENT | LOCATION_FREEMANS_FOUNDRY:
        case TILE_HAS_EVENT | LOCATION_STREAM:
        case TILE_HAS_EVENT | LOCATION_TREES:
        case TILE_HAS_EVENT | LOCATION_MOUNTAINS:
        case TILE_HAS_EVENT | LOCATION_VOLCANO:
        case TILE_HAS_EVENT | LOCATION_FLOWERS:
        case TILE_HAS_EVENT | LOCATION_ROCK:
        case TILE_HAS_EVENT | LOCATION_LAKE:
        case TILE_HAS_EVENT | LOCATION_MANDRAKE:
        case TILE_HAS_EVENT | LOCATION_DEAD_TREE:
        case TILE_HAS_EVENT | LOCATION_STUMP:
        case TILE_HAS_EVENT | LOCATION_CRATER:
        case TILE_HAS_EVENT | LOCATION_CACTUS:
        case TILE_HAS_EVENT | LOCATION_MOUND:
        case TILE_HAS_EVENT | LOCATION_DUNE:
        case TILE_HAS_EVENT | LOCATION_LAVA_POOL:
        case TILE_HAS_EVENT | LOCATION_SHRUB:
        case TILE_HAS_EVENT | LOCATION_HOLE:
        case TILE_HAS_EVENT | LOCATION_OUTCROPPING:
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_TREASURE:
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MINOR:
        case TILE_HAS_EVENT | LOCATION_RANDOM_ARTIFACT_MAJOR:
        case TILE_HAS_EVENT | LOCATION_BARRIER:
        case TILE_HAS_EVENT | LOCATION_TRAVELLER_TENT:
          continue;
      }
    }
  }

  for(int playerIdxb = 0; playerIdxb < 54; ++playerIdxb) {
    if(this->heroes[playerIdxb].flags & (HERO_AT_SEA << 16))
      this->heroes[playerIdxb].flags -= 0x800000;
  }

  this->week++;
  this->SetupNewRumour();
  this->GiveTroopsToNeutralTowns();

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

  this->month++;
  int rand = Random(1, 10);
  if(rand > 5) {
    if(rand > 9) {
      giMonthType = MONTH_PLAGUE;
    } else {
      giMonthType = MONTH_CREATURE;
      giMonthTypeExtra = monthSpecificCreatures[Random(0, monthSpecificCreatures.size()-1)];
    }
  } else {
    giMonthType = MONTH_REGULAR;
    giMonthTypeExtra = Random(0, 9);
  }

  for(int townIdx = 0; townIdx < MAX_TOWNS; ++townIdx) {
    for(int i = BUILDING_DWELLING_1; i <= BUILDING_UPGRADE_5B; ++i) {
      town* twn = &this->castles[townIdx];
      if(!twn->BuildingBuilt(i))
        continue;
      int growth = gMonsterDatabase[gDwellingType[twn->factionID][i - 19]].growth;
      if(twn->BuildingBuilt(BUILDING_WELL))
        growth += 2;
      if(i == BUILDING_DWELLING_1 && twn->BuildingBuilt(BUILDING_SPECIAL_GROWTH))
        growth += 8;
      if(giMonthType == MONTH_CREATURE && gDwellingType[twn->factionID][i - 19] == giMonthTypeExtra)
        growth *= 2;
      if(giMonthType == MONTH_PLAGUE) {
        twn->numCreaturesInDwelling[i - 19] -= growth;
        if(twn->numCreaturesInDwelling[i - 19] < 0)
          twn->numCreaturesInDwelling[i - 19] = 0;
        twn->numCreaturesInDwelling[i - 19] /= 2;
      }
    }
  }

  if(giMonthType == MONTH_CREATURE) {
    for(int x = 0; x < MAP_WIDTH; ++x) {
      for(int y = 0; y < MAP_HEIGHT; ++y) {
        mapCell *tile = gpAdvManager->GetCell(x, y);
        if(tile->objType)
          continue;
        if(tile->isShadow)
          continue;
        if(tile->field_4_1)
          continue;
        if(giGroundToTerrain[tile->groundIndex]) {
          if(Random(0, 360) == 10) {
            tile->objType = TILE_HAS_EVENT | LOCATION_ARMY_CAMP;
            tile->objTileset = TILESET_MONSTER;
            tile->objectIndex = giMonthTypeExtra;
            tile->extraInfo = this->GetRandomNumTroops(giMonthTypeExtra) * 2;
            if(Random(0, 100) < 20)
              tile->extraInfo |= 0x1000; // will join
          }
        }        
      }
    }
  }
  gpAdvManager->CompleteDraw(0);

  if (!IsWellDisabled() || giMonthType != MONTH_PLAGUE) {
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
  giMonthType = MONTH_REGULAR;
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
  for(auto &i : disallowedBuildings) 
    i.reset();
}

extern int gbGameOver;
extern int giEndSequence;

void __fastcall CheckEndGame(int a, int b) {
	CheckEndGame_orig(a, b);
	if (gbGameOver) {
		if (!gpGame->onMapEndCallbackStatus && !gbInNewGameSetup) {
			gpGame->onMapEndCallbackStatus = true;
			if (giEndSequence) {
				ScriptCallback("OnMapVictory");
			} else {
				ScriptCallback("OnMapLoss");
			}
		}
	}
}

bool dbgAutoWinBattles = false;
extern void *hmnuAdv;

extern void __fastcall UpdateDfltMenu_orig(void *hMenu);

extern void __fastcall UpdateDfltMenu(void *hMenu) {
  UpdateDfltMenu_orig(hMenu);
  EnableMenuItem((HMENU)hMenu, 40010, MF_ENABLED);
  EnableMenuItem((HMENU)hMenu, 40011, MF_ENABLED);
}

int __fastcall HandleAppSpecificMenuCommands(int a1) {
  int spell; // [sp+24h] [bp-8h]@55
  hero *hro; // [sp+28h] [bp-4h]@1

  hro = 0;
  if (gpCurPlayer && gpCurPlayer->curHeroIdx != -1)
    hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  if(a1 >= 41000 && a1 <= 41083) {
    gpGame->hasCheated = true;
    if(gbInCampaign)
      gpGame->campHasCheated = true;
    if(gpCurPlayer->curHeroIdx != -1) {
      gpGame->GiveArmy(&gpGame->heroes[gpCurPlayer->curHeroIdx].army, a1 - 41000, 5, -1);
      gpAdvManager->UpdBottomView(1, 1, 1);
    }
    return 0;
  }
  switch (a1) {
    case 40010: //MENUITEM "1280 x 960 (Native x2)"
      ResizeWindow(-1, -1, 1280, 960);
      return 0;
    case 40011: //MENUITEM "1920 x 1440 (Native x3)"
      ResizeWindow(-1, -1, 1920, 1440);
      return 0;
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
    case 40145:
      if(!dbgAutoWinBattles) {
        dbgAutoWinBattles = true;
        CheckMenuItem((HMENU)hmnuAdv, 40145, MF_CHECKED);
      } else {
        dbgAutoWinBattles = false;
        CheckMenuItem((HMENU)hmnuAdv, 40145, MF_UNCHECKED);
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

int philAI::ValueOfEventAtPosition(int x, int y, int a2, int *a3) {
  if(gpAdvManager->GetCell(x, y)->getLocationType() == LOCATION_SHIPYARD)
    return 0; // ignore shipyard objects
  else
    return ValueOfEventAtPosition_orig(x, y, a2, a3);
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
  struct heroData {
    FACTION faction;
    bool randomizable;
    bool exists;
  };

  std::vector<heroData> heroesAvailable;
  for(int i = 0; i < TOTAL_AVAILABLE_HEROES; i++) {
    heroData data;
    data.exists = false;
    if(i < 54) {
      data.randomizable = true;
      data.faction = (FACTION)(i / 9);
    } else if(i < 72) {
      data.randomizable = false;
      data.faction = FACTION_KNIGHT; // doesn't matter since not randomizable
    } else {
      data.randomizable = true;
      data.faction = FACTION_CYBORG;
    }    
    heroesAvailable.push_back(data);
  }

  char heroExists[MAX_HEROES];
  memset(heroExists, 0, MAX_HEROES);
  for (int y = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
      mapCell *loc = &this->map.tiles[(y * this->map.width) + x];
      if (loc->getLocationType() == LOCATION_RANDOM_HERO || loc->objType == (TILE_HAS_EVENT | LOCATION_JAIL)) {        
        bool isJail = loc->getLocationType() == LOCATION_JAIL;
        int ppMapExtraHeroIdx = loc->extraInfo;
        HeroExtra *mapExtraHero = (HeroExtra *)ppMapExtra[ppMapExtraHeroIdx];
        // handle non-default heroes
        if (!mapExtraHero->customPortrait || mapExtraHero->heroID >= MAX_HEROES || heroExists[mapExtraHero->heroID]) {
          mapExtraHero->hasFaction = 0;
        } else {
        // handle default 54 heroes
          heroExists[mapExtraHero->heroID] = true;
          mapExtraHero->hasFaction = 1;
        }

        int faction;
        if (isJail) {
          mapExtraHero->owner = -1;
          faction = mapExtraHero->factionID;
        } else {
          mapExtraHero->owner = gcColorToPlayerPos[GetHeroOverlayColor(loc->objectIndex)];
          faction = GetHeroOverlayFaction(loc->objectIndex);
          if (faction == FACTION_MULTIPLE) {
            faction = this->newGameSelectedFaction[gcColorToSetupPos[gpGame->players[mapExtraHero->owner].color]];
          }
        }

        if (mapExtraHero->hasFaction) {
          this->heroes[mapExtraHero->heroID].factionID = faction;
        } else {
          // find a free hero with specific faction
          std::vector<int> neededFactionHeroes;
          for(int i = 0; i < heroesAvailable.size(); i++) {
            heroData *hro = &heroesAvailable[i];
            if(hro->randomizable && !hro->exists && hro->faction == faction)
              neededFactionHeroes.push_back(i);
          }

          int randomHeroIdx;
          if(neededFactionHeroes.size()) {
            randomHeroIdx = neededFactionHeroes[Random(0, neededFactionHeroes.size() - 1)];
            if(!mapExtraHero->customPortrait) // do not overwrite portrait placed in editor
              mapExtraHero->heroID = randomHeroIdx;            
          } else { // if none from this faction are available, choose a random one from any faction
            std::vector<int> allFreeHeroes;
            for(int i = 0; i < heroesAvailable.size(); i++) {
              heroData *hro = &heroesAvailable[i];
              if(hro->randomizable && !hro->exists)
                allFreeHeroes.push_back(i);
            }
            randomHeroIdx = allFreeHeroes[Random(0, allFreeHeroes.size()-1)];
            mapExtraHero->heroID = randomHeroIdx;
          }

          // overwrite a random free slot from a default hero for cyborg faction
          // and use portrait from mapExtraHero->heroID
          if(randomHeroIdx >= MAX_HEROES) {
            std::vector<int> freeHeroes;
            for(int i = 0; i < MAX_HEROES; i++) {
              if(!heroExists[i])
                freeHeroes.push_back(i);
            }

            int overwrittenIdx = freeHeroes[Random(0, freeHeroes.size()-1)];
            mapExtraHero->customPortrait = true;
            randomHeroIdx = overwrittenIdx;
          }

          // this sets IDs and portraits for campaign heroes (and cyborg too)
          this->heroes[randomHeroIdx].factionID = faction;
          if (mapExtraHero->customPortrait && mapExtraHero->heroID >= MAX_HEROES) {
            this->heroes[randomHeroIdx].heroID = mapExtraHero->heroID;
          }
          if(heroNames[mapExtraHero->heroID].length())
            strcpy(heroes[randomHeroIdx].name, heroNames[mapExtraHero->heroID].c_str());
          heroesAvailable[mapExtraHero->heroID].exists = true;
          mapExtraHero->heroID = randomHeroIdx;
        }
        
        heroExists[mapExtraHero->heroID] = true;        
        heroesAvailable[mapExtraHero->heroID].exists = true;

        hero *randomHero = &this->heroes[mapExtraHero->heroID];

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
        } else {
          this->SetRandomHeroArmies(mapExtraHero->heroID, 0);
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
          this->heroHireStatus[mapExtraHero->heroID] = 65;
          loc->extraInfo = mapExtraHero->heroID;
        } else {
          randomHero->ownerIdx = mapExtraHero->owner;
          this->heroHireStatus[mapExtraHero->heroID] = randomHero->ownerIdx;
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
          for (int i = 0; i < MAX_SECONDARY_SKILLS; ++i) {
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

extern int iCDRomErr;
extern std::string RegAppPath;
extern std::string RegCDRomPath;
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
extern int byte_4F74B8;

static icon* cmpnNoCD;

void __fastcall SmackManagerMain() {
  gbLastFramePlayed = 0;

  if(bSmackNum == SMACKER_ORIG_CAMPAIGN_SELECTION) {
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

  if(!gbNoSound && gpSoundManager->hdidriver && giSoundVolume && bSmackNum != SMACKER_CREDITS) {
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
  
  std::string actualFolder;
  
  if(!iCDRomErr)
    actualFolder = RegCDRomPath;
  else
    actualFolder = RegAppPath;

  std::string smkPath;
  if(byte_4F74B8 && bSmackNum > SMACKER_MM6) {
    smkPath = "i:\\projects\\heroes\\art\\fin3d\\";
  } else {
    if(bSmackNum == SMACKER_XCAMPAIGN_SELECTION) {
      smkPath = ".\\DATA\\";
    }
    else
      smkPath = actualFolder + "\\HEROES2\\ANIM\\";
  }

  if(slowVideo)
    sprintf(gText, "%s%s.SMK", smkPath.c_str(), &SmackOptions[bSmackNum].slowName);
  else
    sprintf(gText, "%s%s.SMK", smkPath.c_str(), &SmackOptions[bSmackNum].name);

  unsigned int smackSoundFlag;
  if(bSmackSound)
    smackSoundFlag = 1040384;
  else
    smackSoundFlag = 0;

  int smackFlag;
  if(SmackOptions[bSmackNum].flag3)
    smackFlag = 512;
  else
    smackFlag = 0;
  if(gbLowMemory && bSmackNum == SMACKER_ORIG_CAMPAIGN_ARCHIBALD_11 && !slowVideo)
    smackFlag = 0;
  smk1 = nullptr;
  
  if(bSmackNum != SMACKER_XCAMPAIGN_SELECTION) {
    while(!smk1) {
      smk1 = SmackOpen((HANDLE*)gText, smackSoundFlag + smackFlag, -1);
      if(!smk1) {
        cmpnNoCD = gpResourceManager->GetIcon("CMPNNOCD.icn");
        break;
      }
    }
    if(smk1)
      SmackToBuffer(smk1, 0, 0, 640, 480, gpWindowManager->screenBuffer->contents, 0);
  }
  
  if(smk1 && strlen(SmackOptions[bSmackNum].name2) > 1) {
    if(slowVideo)
      sprintf(gText, "%s%s.SMK", smkPath.c_str(), &SmackOptions[bSmackNum].slowName2);
    else
      sprintf(gText, "%s%s.SMK", smkPath.c_str(), &SmackOptions[bSmackNum].name2);
    int v0 = ((unsigned int)bSmackSound < 1) - 1;
    smk2 = SmackOpen((HANDLE*)gText, v0 & 0xFE000, -1);
    if(SmackOptions[bSmackNum].flag5) {
      if(!slowVideo && bSmackNum != SMACKER_XCAMPAIGN_SELECTION)
        SmackToBuffer(smk2, SmackOptions[bSmackNum].offsetX, SmackOptions[bSmackNum].offsetY, 640, 480, gpWindowManager->screenBuffer->contents, 0);
    }
  }

  FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0);
  BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);

  if(SmackOptions[bSmackNum].fadeFlag)
    gpWindowManager->FadeScreen(1, 128, 0);

  if(bSmackNum == SMACKER_ORIG_CAMPAIGN_SELECTION) {
    if(!smk1) {
      gpWindowManager->FadeScreen(0, 4, 0);
      cmpnNoCD->DrawToBuffer(0, 0, 0, 0);
      BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);
    }
    Process1WindowsMessage();
    while(gpInputManager->GetEvent().eventCode != NULL){
    
    }
  }
   
  int v25 = 0;
  int v22 = 0;
  int breakFlag = 1;
  int v24 = 0;
  while(breakFlag) {
    if(!smk1 && bSmackNum != SMACKER_ORIG_CAMPAIGN_SELECTION && bSmackNum != SMACKER_XCAMPAIGN_SELECTION)
      break;
    if(bSmackNum == SMACKER_XCAMPAIGN_SELECTION) {
      if(!v25) {
        gpMouseManager->SetPointer("advmice.mse", 40, -999);
        gpMouseManager->ReallyShowPointer();
        gpSoundManager->PlayAmbientMusic(42, 0, -1);
        backImage = gpResourceManager->GetIcon("x_ivy.icn");
        if(!backImage)
          MemError();
        backImage->DrawToBuffer(0, 0, 0, 0);
        backImage->DrawToBuffer(0, 0, 1, 0);
        sprintf(gText, "%s%s.SMK", smkPath.c_str(), "IVYPOL");
        smk2 = SmackOpen((HANDLE*)gText, 0, -1);
        memcpy(gPalette->contents, smk2->Palette, PALETTE_SIZE);
        SmackClose(smk2);
        smk2 = nullptr;
        ConvertSmackerPalette((unsigned char*)gPalette->contents);
        UpdatePalette(gPalette->contents);
        memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
        gpWindowManager->FadeScreen(0, 4, 0);
        v25 = 1;
      }
    } else {
      if(smk1 && !SmackWait(smk1)) {
        if(bSmackNum == SMACKER_LOSE && !v24) {
          v24 = 1;
          gpSoundManager->PlayAmbientMusic(19, 0, -1);
        }
        if((!v25 || smk1->Frames > 1)
          && (bSmackNum != SMACKER_WIN || smk1->Frames - 1 != smk1->FrameNum)) {
          int v4 = v25 || !SmackOptions[bSmackNum].fadeFlag;
          DoAdvance(smk1, 1, 1, v4, 0);
        }
        if(smk1->FrameNum || smk1->Frames <= 1u) {
          if(!v25) {
            if(bSmackNum == SMACKER_ORIG_CAMPAIGN_SELECTION) {
              gpMouseManager->SetPointer("advmice.mse", 40, -999);
              gpMouseManager->ReallyShowPointer();
            }
            if(SmackOptions[bSmackNum].fadeFlag) {
              memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
              gpWindowManager->FadeScreen(0, 4, 0);
            }
            if(bSmackNum == SMACKER_CREDITS || bSmackNum == SMACKER_CREDITS_CYBERLORE)
              gpSoundManager->PlayAmbientMusic(42, 0, -1);
          }
          v25 = 1;
        }
      }
    }
    if(smk2 && v25 && !SmackWait(smk2)) {
      if(v22 && smk2->Frames - 1 == smk2->FrameNum) {
        int v14 = 0;
        int v13;
        if(!SmackOptions[bSmackNum].flag5 || slowVideo) {
          if(bSmackNum == SMACKER_XCAMPAIGN_SELECTION) {
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
        if(bSmackNum == SMACKER_XCAMPAIGN_SELECTION)
          DoAdvance(smk2, 1, 1, 0, 1);
        else
          DoAdvance(smk2, SmackOptions[bSmackNum].flag5, 1, 0, 1);
      }
      if(smk2 && smk2->FrameNum)
        v22 = 1;
    }
    Process1WindowsMessage();
    tag_message msg;
    memcpy(&msg, &gpInputManager->GetEvent(), sizeof(tag_message));
    if((unsigned int)(msg.eventCode - 1) <= 0x1F) {
      bool shouldBreak = false;
      switch(msg.eventCode) {
        case INPUT_MOUSEMOVE_EVENT_CODE:
          if(bSmackNum == SMACKER_ORIG_CAMPAIGN_SELECTION) {
            int mouseX, mouseY;
            gpMouseManager->MouseCoords(mouseX, mouseY);
            int sideChoice = 0;
            if(mouseX < 320)
              sideChoice = 1;
            if(sideChoice != gbCampaignSideChoice) {
              gbCampaignSideChoice = sideChoice;
              if(!smk1) {
                cmpnNoCD->DrawToBuffer(0, 0, 0, 0);
                BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);
              }
              if(sideChoice == 1) {
                brotherIcon->DrawToBuffer(0, 0, 0, 0);
                brotherIcon->DrawToBuffer(0, 0, 3, 0);
              } else {
                brotherIcon->DrawToBuffer(0, 0, 1, 0);
                brotherIcon->DrawToBuffer(0, 0, 2, 0);
              }
              BlitBitmapToScreen(gpWindowManager->screenBuffer, 49, 78, 538, 258, 49, 78);
            }
          } else {
            if(bSmackNum == SMACKER_XCAMPAIGN_SELECTION) {
              int mouseX, mouseY;
              gpMouseManager->MouseCoords(mouseX, mouseY);
              int selectedCampaignRect = ExpansionCampaignRect(mouseX, mouseY);
              if(selectedCampaignRect != xLastChoice) {
                backImage->DrawToBuffer(0, 0, 0, 0);
                BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);
                xLastChoice = selectedCampaignRect;
                if(smk2) {
                  SmackClose(smk2);
                  smk2 = nullptr;
                }
                if(selectedCampaignRect != -1) {
                  SMACKER_VIDEOS smkNeeded = GetCampaignRectangleSmackerVideo(selectedCampaignRect);
                  sprintf(gText, "%s%s.SMK", smkPath.c_str(), &SmackOptions[smkNeeded].name);
                  int v1 = ((unsigned int)bSmackSound < 1) - 1;
                  smk2 = SmackOpen((HANDLE*)gText, v1 & 0xFE000, -1);
                  SmackToBuffer(smk2, SmackOptions[smkNeeded].offsetX, SmackOptions[smkNeeded].offsetY, 640, 480, gpWindowManager->screenBuffer->contents, 0);
                  backImage->DrawToBuffer(0, 0, 1, 0);
                }
              }
            }
          }
          break;
        case INPUT_KEYDOWN_EVENT_CODE:
          if(msg.xCoordOrKeycode != 62 && bSmackNum != SMACKER_ORIG_CAMPAIGN_SELECTION && bSmackNum != SMACKER_XCAMPAIGN_SELECTION && bSmackNum != SMACKER_EARTH && (bSmackNum != SMACKER_XCAMPAIGN_SELECTION || xLastChoice != -1))
            shouldBreak = true;
          break;
        case INPUT_RIGHT_CLICK:
          if(bSmackNum != SMACKER_ORIG_CAMPAIGN_SELECTION && bSmackNum != SMACKER_XCAMPAIGN_SELECTION && bSmackNum != SMACKER_EARTH && (bSmackNum != SMACKER_XCAMPAIGN_SELECTION || xLastChoice != -1))
            shouldBreak = true;
          break;
        case INPUT_LEFT_CLICK_EVENT_CODE:
          if(bSmackNum != SMACKER_EARTH && (bSmackNum != SMACKER_XCAMPAIGN_SELECTION || xLastChoice != -1))
            shouldBreak = true;
          break;
      }
      if(shouldBreak)
        break;
    }
    if(bSmackNum == SMACKER_WIN && smk1->FrameNum + 1 == smk1->Frames && !v24) {
      v24 = 1;
      gpSoundManager->PlayAmbientMusic(43, 0, -1);
    }
    if(!SmackOptions[bSmackNum].flag4) {
      int v3;
      if(gbLastFramePlayed || smk2 && (bSmackNum < SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_INTRO ? (smk2->FrameNum < smk2->Frames ? (v3 = 0) : (v3 = 1)) : (unsigned int)(smk2->Frames - 1) > smk2->FrameNum ? (v3 = 0) : (v3 = 1),
          v3 || !smk2->FrameNum && v22) || !smk2 && smk1 && (smk1->FrameNum >= smk1->Frames || !smk1->FrameNum && v25)) {
        breakFlag = 0;
        gbPlayedThrough = 1;
      }
    }
  }

  if(bSmackNum == SMACKER_ORIG_CAMPAIGN_SELECTION) {
    gpMouseManager->HideColorPointer();
    gpMouseManager->SetPointer("advmice.mse", 0, -999);
  }

  if(SmackOptions[bSmackNum].flag2) {
    memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
    gpWindowManager->FadeScreen(1, 8, 0);
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640, 480, 36);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);
  } else if(!gbPlayedThrough && bSmackNum != SMACKER_WIN) {
    memcpy(gpBufferPalette->contents, gPalette->contents, PALETTE_SIZE);
    gpWindowManager->FadeScreen(1, 128, 0);
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640, 480, 36);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640, 480, 0, 0);
  }

  if(bTesting)
    SmackSummary(smk1, &smksum);

  if(smk1)
    SmackClose(smk1);
  smk1 = nullptr;

  if(smk2)
    SmackClose(smk2);
  smk2 = nullptr;

  if(bSmackNum != SMACKER_WIN) {
    memcpy(gPalette->contents, &tmpPalette, PALETTE_SIZE);
    UpdatePalette(gPalette->contents);
  }

  gpMouseManager->ShowColorPointer();
  if(brotherIcon)
    gpResourceManager->Dispose(brotherIcon);
  brotherIcon = nullptr;

  if(cmpnNoCD)
    gpResourceManager->Dispose(cmpnNoCD);
  cmpnNoCD = nullptr;

  if(backImage)
    gpResourceManager->Dispose(backImage);
  backImage = nullptr;
}

int __fastcall PlaySmacker(int smkID) {
  int tmpgbNoCDRom = gbNoCDRom;
  if(gbNoCDRom) 
    gbNoCDRom = false;
  int res = PlaySmacker_orig(smkID);
  gbNoCDRom = tmpgbNoCDRom;
  return res;
}

int __fastcall AddScoreToHighScore(int score, int days, int difficulty, int type, char *name) {
  // This is here because it's complicated to change xHSCampaignNames on the fly
  if(type == CAMPAIGN_TYPE_EXPANSION)
    name = (char*)xCampaignNames[xCampaign.campaignID].c_str();
  return AddScoreToHighScore_orig(score, days, difficulty, type, name);
}

int game::GetLuck(hero* hro, army *stack, town *castle) {
  int luck = GetLuck_orig(hro, stack, castle);
  auto res = ScriptCallbackResult<int>("OnCalcLuck", deepbind<hero*>(hro), deepbind<army*>(stack), deepbind<town*>(castle), luck);
  if(res.has_value())
    luck = res.value();
  luck = max(-3, min(luck, 3));
  return luck;
}

int armyGroup::GetMorale(hero *hro, town *twn, armyGroup *armyGr) {
  int morale = GetMorale_orig(hro, twn, armyGr);
  auto res = ScriptCallbackResult<int>("OnCalcMorale", deepbind<hero*>(hro), deepbind<town*>(twn), morale);
  if(res.has_value())
    morale = res.value();
  morale = max(-3, min(morale, 3));
  return morale;
}

void game::ShowLuckInfo(hero *hro, int dialogType) {
  std::string msg;
  town *twn = hro->GetOccupiedTown();
  int luck = GetLuck(hro, 0, twn);
  if(luck == 0)
    msg = "{Neutral Luck}\n\nNeutral luck means your armies will never get lucky or unlucky attacks on the enemy.";
  else if(luck < 0)
    msg = "{Bad Luck}\n\nBad luck sometimes falls on your armies in combat, causing their attacks to only do half damage.";
  else
    msg = "{Good Luck}\n\nGood luck sometimes lets your armies get lucky attacks (double strength) in combat.";

  sprintf(gText, "%s\n\n\nCurrent Luck Modifiers:", &msg[0u]);

  unsigned len = strlen(gText);
  if(twn && twn->factionID == FACTION_SORCERESS && twn->BuildingBuilt(BUILDING_SPECIAL))
    strcat(gText, "\nSorceress Rainbow +2");
  if(hro->HasArtifact(ARTIFACT_LUCKY_RABBITS_FOOT))
    strcat(gText, "\nLucky Rabbit's Foot +1");
  if(hro->HasArtifact(ARTIFACT_GOLDEN_HORSESHOE))
    strcat(gText, "\nGolden Horseshoe +1");
  if(hro->HasArtifact(ARTIFACT_GAMBLERS_LUCKY_COIN))
    strcat(gText, "\nGambler's Lucky Coin +1");
  if(hro->HasArtifact(ARTIFACT_FOUR_LEAF_CLOVER))
    strcat(gText, "\nFour-Leaf Clover +1");
  if(hro->flags & HERO_FAIRY_RING_VISITED)
    strcat(gText, "\nFaerie ring visited +1");
  if(hro->flags & HERO_IDOL_VISITED)
    strcat(gText, "\nIdol visited +1");
  if(hro->flags & HERO_FOUNTAIN_VISITED)
    strcat(gText, "\nFountain visited +1");
  if(hro->flags & HERO_PYRAMID_RAIDED)
    strcat(gText, "\nPyramid raided -2");
  if(hro->secondarySkillLevel[SECONDARY_SKILL_LUCK] == 1)
    strcat(gText, "\nBasic Luck +1");
  if(hro->secondarySkillLevel[SECONDARY_SKILL_LUCK] == 2)
    strcat(gText, "\nAdvanced Luck +2");
  if(hro->secondarySkillLevel[SECONDARY_SKILL_LUCK] == 3)
    strcat(gText, "\nExpert Luck +3");
  if(hro->HasArtifact(ARTIFACT_MASTHEAD) && hro->flags & HERO_AT_SEA)
    strcat(gText, "\nMasthead bonus at sea +1");
  if(hro->flags & HERO_MERMAID_VISITED)
    strcat(gText, "\nMermaid visited +1");
  if(hro->HasArtifact(ARTIFACT_BATTLE_GARB_OF_ANDURAN))
    strcat(gText, "\nBattle Garb of Anduran gives you maximum luck.");

  auto res = ScriptCallbackResult<std::string>("OnShowLuckInfo", deepbind<hero*>(hro));
  if(res.has_value()) {
    strcat(gText, "\n");
    strcat(gText, res.value().c_str());
  }

  if(len == strlen(gText))
    strcat(gText, "\nnone");

  return NormalDialog(gText, dialogType, -1, -1, -1, 0, -1, 0, -1, 0);
}

void game::ShowMoraleInfo(hero *hro, int dialogType) {
  std::string msg;
  town *twn = hro->GetOccupiedTown();
  int morale = hro->army.GetMorale(hro, twn, NULL);
  if(morale == 0)
    msg = "{Neutral Morale}\n\nNeutral morale means your armies will never be blessed with extra attacks or freeze in combat.";
  else if(morale < 0)
    msg = "{Bad Morale}\n\nBad morale may cause your armies to freeze in combat.";
  else
    msg = "{Good Morale}\n\nGood morale may give your armies extra attacks in combat.";

  sprintf(gText, "%s\n\n\nCurrent Morale Modifiers:", &msg[0u]);

  unsigned len = strlen(gText);
  if(hro->army.HasAllUndead()) {
    strcat(gText, "\nEntire unit is undead, so morale does not apply.");
  } else {
    bool hasUndead = false;
    if(hro->army.HasSomeUndead() || hro->HasArtifact(ARTIFACT_ARM_OF_THE_MARTYR)) {
      strcat(gText, "\nSome undead in group -1");
      hasUndead = true;
    }
    int troopAlignments = hro->army.IsHomogeneous(-1);
    if(hasUndead && troopAlignments > 0)
      troopAlignments = 0;
    int faction = 0;
    if(troopAlignments > 0) {
      for(int i = 0; i < CREATURES_IN_ARMY; ++i) {
        if(hro->army.creatureTypes[i] != -1)
          faction = gMonsterDatabase[hro->army.creatureTypes[i]].faction;
      }
      msg = "\nAll " + std::string(gAlignmentNames[faction]) + " troops +1";
      strcat(gText, &msg[0]);
    }
    if(troopAlignments == -1)
      strcat(gText, "\nTroops of 3 alignments -1");
    if(troopAlignments == -2)
      strcat(gText, "\nTroops of 4 alignments -2");
    if(troopAlignments == -3)
      strcat(gText, "\nTroops of 5 alignments -3");
    if(twn) {
      if(twn->factionID == FACTION_BARBARIAN && twn->BuildingBuilt(BUILDING_SPECIAL))
        strcat(gText, "\nBarbarian Coliseum +2");
      if(twn->BuildingBuilt(BUILDING_TAVERN))
        strcat(gText, "\nTavern +1");
    }
    if(hro->HasArtifact(ARTIFACT_MEDAL_OF_VALOR))
      strcat(gText, "\nMedal of Valor +1");
    if(hro->HasArtifact(ARTIFACT_MEDAL_OF_COURAGE))
      strcat(gText, "\nMedal of Courage +1");
    if(hro->HasArtifact(ARTIFACT_MEDAL_OF_HONOR))
      strcat(gText, "\nMedal of Honor +1");
    if(hro->HasArtifact(ARTIFACT_MEDAL_OF_DISTINCTION))
      strcat(gText, "\nMedal of Distinction +1");
    if(hro->HasArtifact(ARTIFACT_FIZBIN_OF_MISFOURTUNE))
      strcat(gText, "\nFizbin of Misfortune -2");
    if(hro->flags & HERO_BUOY_VISITED)
      strcat(gText, "\nBuoy visited +1");
    if(hro->flags & HERO_OASIS_VISITED)
      strcat(gText, "\nOasis visited +1");
    if(hro->flags & HERO_TEMPLE_VISITED)
      strcat(gText, "\nTemple visited +2");
    if(hro->flags & HERO_GRAVEYARD_ROBBER)
      strcat(gText, "\nGraveyard robber -1");
    if(hro->flags & HERO_SHIPWRECK_ROBBER)
      strcat(gText, "\nShipwreck robber -1");
    if(hro->flags & HERO_WATERING_HOLE_VISITED)
      strcat(gText, "\nWatering hole visited +1");
    if(hro->flags & HERO_DERELICT_SHIP_ROBBER)
      strcat(gText, "\nDerelict ship robber -1");
    int leadership = hro->secondarySkillLevel[SECONDARY_SKILL_LEADERSHIP];
    if(leadership == 1)
      strcat(gText, "\nBasic Leadership +1");
    if(leadership == 2)
      strcat(gText, "\nAdvanced Leadership +2");
    if(leadership == 3)
      strcat(gText, "\nExpert Leadership +3");
    if(hro->HasArtifact(ARTIFACT_MASTHEAD) && hro->flags & HERO_AT_SEA)
      strcat(gText, "\nMasthead bonus at sea +1");
    if(hro->HasArtifact(ARTIFACT_BATTLE_GARB_OF_ANDURAN))
      strcat(gText, "\nBattle Garb of Anduran gives you maximum morale.");
  }

  auto res = ScriptCallbackResult<std::string>("OnShowMoraleInfo", deepbind<hero*>(hro));
  if(res.has_value()) {
    strcat(gText, "\n");
    strcat(gText, res.value().c_str());
  }

  if(len == strlen(gText))
    strcat(gText, "\nnone");

  return NormalDialog(gText, dialogType, -1, -1, -1, 0, -1, 0, -1, 0);
}

void mouseManager::SetPointer(int spriteIdxArg) {
  if(this->field_7E || spriteIdxArg < 0)
    return;

  if(this->ready != 1 || this->spriteIdx == spriteIdxArg || gbInSetPointer)
    return;

  gbInSetPointer = 1;
  ++gbPutzingWithMouseCtr;
  gpResourceManager->SavePosition();

  if(giCurExe == 1)
    this->cursorCategory = MOUSE_CURSOR_CATEGORY_ADVENTURE;

  int spriteIdx = spriteIdxArg;
  if(spriteIdxArg == 1000)
    spriteIdx = this->spriteIdx;
  else
    this->spriteIdx = spriteIdxArg;

  int offset = iMouseOffset[this->cursorCategory];
  int actualIdx = spriteIdx + offset;

  // Ironfist fallback to a large cursor slot in various cursor related arrays
  if(actualIdx >= MAX_MOUSE_CURSORS)
    actualIdx = 83;
  this->cursorIdx = actualIdx;
  ProcessAssert(!(actualIdx < 0 || actualIdx >= MAX_MOUSE_CURSORS), __FILE__, __LINE__);

  if(gbColorMice) {
    this->NewUpdate(1);
  } else {
      std::string fileName;
      int actualSpriteIdx;
      MOUSE_CURSOR_CATEGORY category = this->cursorCategory;
      switch(category) {
        case MOUSE_CURSOR_CATEGORY_ADVENTURE:
          actualSpriteIdx = spriteIdx + 1;
          fileName = "ADVMBW";
          break;
        case MOUSE_CURSOR_CATEGORY_COMBAT:
          actualSpriteIdx = spriteIdx + 1;
          fileName = "CMSEBW";
          break;
        case MOUSE_CURSOR_CATEGORY_SPELL:
          actualSpriteIdx = spriteIdx;
          fileName = "SPELBW";
          break;
      }

      char fileNameChar[FILENAME_MAX];
      sprintf_s(fileNameChar, "%s%02d.BMP", fileName.c_str(), actualSpriteIdx);

      int fileID = gpResourceManager->MakeId(fileNameChar, 1);
      gpResourceManager->PointToFile(fileID);

      if(cColorBits[this->cursorIdx])
        BaseFree(cColorBits[this->cursorIdx], __FILE__, __LINE__);
      if(cAndBits[this->cursorIdx])
        BaseFree(cAndBits[this->cursorIdx], __FILE__, __LINE__);
      cColorBits[this->cursorIdx] = BaseAlloc(1024, __FILE__, __LINE__);
      cAndBits[this->cursorIdx] = BaseAlloc(256, __FILE__, __LINE__);
      gpResourceManager->ReadBlock((signed char*)cColorBits[this->cursorIdx], 6);
      gpResourceManager->ReadBlock((signed char*)cColorBits[this->cursorIdx], 1024);
      memset(cAndBits[this->cursorIdx], 0, 256);
      
      int cnt, cnt2;
      cnt = cnt2 = 0;
      do {
        int cnt3 = 0;
        do {
          void *bits = cColorBits[this->cursorIdx];
          if(*((char *)bits + cnt3 + cnt)) {
            if(*((char *)bits + cnt3 + cnt) == 1)
              *((char *)cAndBits[this->cursorIdx] + (cnt3 >> 3) + cnt2 + 128) |= 1 << (7 - (cnt3 & 7));
          } else {
            *((char *)cAndBits[this->cursorIdx] + (cnt3 >> 3) + cnt2) |= 1 << (7 - (cnt3 & 7));
          }
          ++cnt3;
        } while(cnt3 < 32);
        cnt2 += 4;
        cnt += 32;
      } while(cnt < 1024);

      BITMAP bmpAndMask;
      bmpAndMask.bmType = 0;
      bmpAndMask.bmWidth = 32;
      bmpAndMask.bmHeight = 64;
      bmpAndMask.bmWidthBytes = 4;
      bmpAndMask.bmPlanes = 1;
      bmpAndMask.bmBitsPixel = 1;
      bmpAndMask.bmWidthBytes = 4;
      bmpAndMask.bmBits = cAndBits[this->cursorIdx];

      HBITMAP hbmpAndMask = CreateBitmapIndirect(&bmpAndMask);
      ProcessAssert((int)hbmpAndMask, __FILE__, __LINE__);

      _ICONINFO IconInfo;
      IconInfo.fIcon = 0;
      if(this->cursorCategory == MOUSE_CURSOR_CATEGORY_SPELL)
        IconInfo.xHotspot = IconInfo.yHotspot = 15;
      else {
        IconInfo.xHotspot = iHotSpot[this->cursorIdx][0];
        IconInfo.yHotspot = iHotSpot[this->cursorIdx][1];
      }
      IconInfo.hbmMask = hbmpAndMask;
      IconInfo.hbmColor = 0;
      
      DestroyIcon((HICON)hMouseCursor[this->cursorIdx]);
      hMouseCursor[this->cursorIdx] = (HCURSOR *)CreateIconIndirect(&IconInfo);
      ProcessAssert((int)hMouseCursor[this->cursorIdx], __FILE__, __LINE__);
      SetCursor((HCURSOR)hMouseCursor[this->cursorIdx]);
  }

  gpResourceManager->RestorePosition();
  gbInSetPointer = 0;
  --gbPutzingWithMouseCtr;
}