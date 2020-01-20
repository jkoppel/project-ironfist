#include "base.h"
#include "gui/msg.h"

#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "gui/gui.h"
#include "resource/resources.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "town/buildings.h"
#include "town/town_globals.h"

#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

unsigned long gTownEligibleBuildMask[MAX_FACTIONS] = {
  0x3FF8BF9F,
  0x1BF8BF9F,
  0xFF8BF9F,
  0x69F8BF9F,
  0x35F8BF9F,
  0x1FF8BF9B,
  0x0,
  0x0,
  0x0,
  0x0,
  0x0,
  0x0,
  0x01F8BF9F  // TODO: decide whether Cyborg creatures have any upgrades
};

// Leave these undefined initially to make the compiler put them in the
// same data segment. This ensures the old game code will be able to index
// into gDwellingType by referencing gTownObjNames.
char *gTownObjNames[32] = { 0 };
unsigned char gDwellingType[MAX_FACTIONS][NUM_DWELLINGS] = { 0 };

// Declare these in the cpp file to force the use of the helper functions in
// order to get these building names.
extern char *gWellExtraNames[MAX_FACTIONS] = { 0 };
extern char *gSpecialBuildingNames[MAX_FACTIONS] = { 0 };
extern char *gBuildingInfoSpecial[MAX_FACTIONS] = { 0 };

extern char *gTownPrefixNames[MAX_FACTIONS] = {
  "twnk", "twnb", "twns", "twnw", "twnz", "twnn",
  "", "", "", "", "", "",
  "twnc"
};

std::vector<std::string> objectNames = {
  "mage",
  "thie",
  "tvrn",
  "dock",
  "well",
  "tent",
  "cstl",
  "stat",
  "ltur",
  "rtur",
  "mark",
  "wel2",
  "moat",
  "spec",
  "boat",
  "capt",
  "ext0",
  "ext1",
  "ext2",
  "dw_0",
  "dw_1",
  "dw_2",
  "dw_3",
  "dw_4",
  "dw_5",
  "up_1",
  "up_2",
  "up_3",
  "up_4",
  "up_5",
  "up5b",
  "ext3"
};

std::vector<FACTION> FACTIONS_ACTUAL = {
  FACTION_KNIGHT,
  FACTION_BARBARIAN,
  FACTION_SORCERESS,
  FACTION_WARLOCK,
  FACTION_WIZARD,
  FACTION_NECROMANCER,
  FACTION_CYBORG
};

std::vector<std::string> FACTIONS_ACTUAL_NAMES = {
  "Knight",
  "Barbarian",
  "Sorceress",
  "Warlock",
  "Wizard",
  "Necromancer",
  "Cyborg"
};

void InitTownObjNames() {
  for (auto i = 0u; i < objectNames.size(); ++i) {
    gTownObjNames[i] = &objectNames[i][0];
  }
}

// Defines the creature types in dwellings 1-6, followed by upgrades 1-5b
// (which are really the tier 2 upgrade through tier 6 second upgrade).
void InitDwellingTypes() {
  for (int i = 0; i < MAX_FACTIONS; ++i) {
    for (int j = 0; j < NUM_DWELLINGS; ++j) {
      gDwellingType[i][j] = CREATURE_INVALID;
    }
  }

  gDwellingType[FACTION_KNIGHT][DWELLING_1] = CREATURE_PEASANT;
  gDwellingType[FACTION_KNIGHT][DWELLING_2] = CREATURE_ARCHER;
  gDwellingType[FACTION_KNIGHT][DWELLING_3] = CREATURE_PIKEMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_4] = CREATURE_SWORDSMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_5] = CREATURE_CAVALRY;
  gDwellingType[FACTION_KNIGHT][DWELLING_6] = CREATURE_PALADIN;
  gDwellingType[FACTION_KNIGHT][DWELLING_2_UPGRADE] = CREATURE_RANGER;
  gDwellingType[FACTION_KNIGHT][DWELLING_3_UPGRADE] = CREATURE_VETERAN_PIKEMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_4_UPGRADE] = CREATURE_MASTER_SWORDSMAN;
  gDwellingType[FACTION_KNIGHT][DWELLING_5_UPGRADE] = CREATURE_CHAMPION;
  gDwellingType[FACTION_KNIGHT][DWELLING_6_UPGRADE] = CREATURE_CRUSADER;

  gDwellingType[FACTION_BARBARIAN][DWELLING_1] = CREATURE_GOBLIN;
  gDwellingType[FACTION_BARBARIAN][DWELLING_2] = CREATURE_ORC;
  gDwellingType[FACTION_BARBARIAN][DWELLING_3] = CREATURE_WOLF;
  gDwellingType[FACTION_BARBARIAN][DWELLING_4] = CREATURE_OGRE;
  gDwellingType[FACTION_BARBARIAN][DWELLING_5] = CREATURE_TROLL;
  gDwellingType[FACTION_BARBARIAN][DWELLING_6] = CREATURE_CYCLOPS;
  gDwellingType[FACTION_BARBARIAN][DWELLING_2_UPGRADE] = CREATURE_ORC_CHIEF;
  gDwellingType[FACTION_BARBARIAN][DWELLING_4_UPGRADE] = CREATURE_OGRE_LORD;
  gDwellingType[FACTION_BARBARIAN][DWELLING_5_UPGRADE] = CREATURE_WAR_TROLL;

  gDwellingType[FACTION_SORCERESS][DWELLING_1] = CREATURE_SPRITE;
  gDwellingType[FACTION_SORCERESS][DWELLING_2] = CREATURE_DWARF;
  gDwellingType[FACTION_SORCERESS][DWELLING_3] = CREATURE_ELF;
  gDwellingType[FACTION_SORCERESS][DWELLING_4] = CREATURE_DRUID;
  gDwellingType[FACTION_SORCERESS][DWELLING_5] = CREATURE_UNICORN;
  gDwellingType[FACTION_SORCERESS][DWELLING_6] = CREATURE_PHOENIX;
  gDwellingType[FACTION_SORCERESS][DWELLING_2_UPGRADE] = CREATURE_BATTLE_DWARF;
  gDwellingType[FACTION_SORCERESS][DWELLING_3_UPGRADE] = CREATURE_GRAND_ELF;
  gDwellingType[FACTION_SORCERESS][DWELLING_4_UPGRADE] = CREATURE_GREATER_DRUID;

  gDwellingType[FACTION_WARLOCK][DWELLING_1] = CREATURE_CENTAUR;
  gDwellingType[FACTION_WARLOCK][DWELLING_2] = CREATURE_GARGOYLE;
  gDwellingType[FACTION_WARLOCK][DWELLING_3] = CREATURE_GRIFFIN;
  gDwellingType[FACTION_WARLOCK][DWELLING_4] = CREATURE_MINOTAUR;
  gDwellingType[FACTION_WARLOCK][DWELLING_5] = CREATURE_HYDRA;
  gDwellingType[FACTION_WARLOCK][DWELLING_6] = CREATURE_GREEN_DRAGON;
  gDwellingType[FACTION_WARLOCK][DWELLING_4_UPGRADE] = CREATURE_MINOTAUR_KING;
  gDwellingType[FACTION_WARLOCK][DWELLING_6_UPGRADE] = CREATURE_RED_DRAGON;
  gDwellingType[FACTION_WARLOCK][DWELLING_6_UPGRADE2] = CREATURE_BLACK_DRAGON;

  gDwellingType[FACTION_WIZARD][DWELLING_1] = CREATURE_HALFLING;
  gDwellingType[FACTION_WIZARD][DWELLING_2] = CREATURE_BOAR;
  gDwellingType[FACTION_WIZARD][DWELLING_3] = CREATURE_IRON_GOLEM;
  gDwellingType[FACTION_WIZARD][DWELLING_4] = CREATURE_ROC;
  gDwellingType[FACTION_WIZARD][DWELLING_5] = CREATURE_MAGE;
  gDwellingType[FACTION_WIZARD][DWELLING_6] = CREATURE_GIANT;
  gDwellingType[FACTION_WIZARD][DWELLING_3_UPGRADE] = CREATURE_STEEL_GOLEM;
  gDwellingType[FACTION_WIZARD][DWELLING_5_UPGRADE] = CREATURE_ARCHMAGE;
  gDwellingType[FACTION_WIZARD][DWELLING_6_UPGRADE] = CREATURE_TITAN;

  gDwellingType[FACTION_NECROMANCER][DWELLING_1] = CREATURE_SKELETON;
  gDwellingType[FACTION_NECROMANCER][DWELLING_2] = CREATURE_ZOMBIE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_3] = CREATURE_MUMMY;
  gDwellingType[FACTION_NECROMANCER][DWELLING_4] = CREATURE_VAMPIRE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_5] = CREATURE_LICH;
  gDwellingType[FACTION_NECROMANCER][DWELLING_6] = CREATURE_BONE_DRAGON;
  gDwellingType[FACTION_NECROMANCER][DWELLING_2_UPGRADE] = CREATURE_MUTANT_ZOMBIE;
  gDwellingType[FACTION_NECROMANCER][DWELLING_3_UPGRADE] = CREATURE_ROYAL_MUMMY;
  gDwellingType[FACTION_NECROMANCER][DWELLING_4_UPGRADE] = CREATURE_VAMPIRE_LORD;
  gDwellingType[FACTION_NECROMANCER][DWELLING_5_UPGRADE] = CREATURE_POWER_LICH;

  gDwellingType[FACTION_CYBORG][DWELLING_1] = CREATURE_CYBER_KOBOLD_SPEARMAN;
  gDwellingType[FACTION_CYBORG][DWELLING_2] = CREATURE_CYBER_PLASMA_BERSERKER;
  gDwellingType[FACTION_CYBORG][DWELLING_3] = CREATURE_CYBER_PLASMA_LANCER;
  gDwellingType[FACTION_CYBORG][DWELLING_4] = CREATURE_CYBER_INDIGO_PANTHER;
  gDwellingType[FACTION_CYBORG][DWELLING_5] = CREATURE_CYBER_SHADOW_ASSASSIN;
  gDwellingType[FACTION_CYBORG][DWELLING_6] = CREATURE_CYBER_BEHEMOTH;
  // TODO: do Cyborg creatures have upgrades?
  // dummies
  gDwellingType[FACTION_CYBORG][DWELLING_2_UPGRADE] = CREATURE_CYBER_PLASMA_BERSERKER;
  gDwellingType[FACTION_CYBORG][DWELLING_3_UPGRADE] = CREATURE_CYBER_PLASMA_LANCER;
  gDwellingType[FACTION_CYBORG][DWELLING_4_UPGRADE] = CREATURE_CYBER_INDIGO_PANTHER;
  gDwellingType[FACTION_CYBORG][DWELLING_5_UPGRADE] = CREATURE_CYBER_SHADOW_ASSASSIN;
  gDwellingType[FACTION_CYBORG][DWELLING_6_UPGRADE] = CREATURE_CYBER_BEHEMOTH;  
}

void InitBuildingNames() {
  for (int f = 0; f < MAX_FACTIONS; ++f) {
    gWellExtraNames[f] = GetFirstLevelGrowerName(f);
    gSpecialBuildingNames[f] = GetSpecialBuildingName(f);
    gBuildingInfoSpecial[f] = GetSpecialBuildingDesc(f);
  }
}
