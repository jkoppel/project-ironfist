#include "town/buildings.h"

#include "base.h"
#include "town/town.h"
#include <string>
#include <vector>


namespace {
  std::vector<std::string> firstLevelGrowerNames = {
    "Farm",
    "Garbage Heap",
    "Crystal Garden",
    "Waterfall",
    "Orchard",
    "Skull Pile",
    "1st Lvl Growth",
    "",
    "",
    "",
    "",
    "",
    "[TODO] Cyborg Grower"
  };

  std::vector<std::string> specialBuildingNames = {
    "Fortifications",
    "Coliseum",
    "Rainbow",
    "Dungeon",
    "Library",
    "Storm",
    "Special",
    "",
    "",
    "",
    "",
    "",
    "[TODO] Cyborg Special"
  };

  std::vector<std::string> specialBuildingDescriptions = {
    "The Fortifications increase the toughness of the walls, increasing the number of turns it takes to knock them down.",
    "The Coliseum provides inspiring spectacles to defending troops, raising their morale by two during combat.",
    "The Rainbow increases the luck of the defending units by two.",
    "The Dungeon increases the income of the town by 500 / day.",
    "The Library increases the number of spells in the Guild by one for each level of the guild.",
    "The Storm adds +2 to the power of spells of a defending spell caster.",
    "",
    "",
    "",
    "",
    "",
    "",
    "[TODO] Cyborg special building description"
  };

  std::vector<std::string> cyborgDwellings = {
    "Cyborg Level 1",
    "Cyborg Level 2",
    "Cyborg Level 3",
    "Cyborg Level 4",
    "Cyborg Level 5",
    "Cyborg Level 6",
    "Cyborg Level 2 Upgrade",
    "Cyborg Level 3 Upgrade",
    "Cyborg Level 4 Upgrade",
    "Cyborg Level 5 Upgrade",
    "Cyborg Level 6 Upgrade",
    "Cyborg Level 6 Upgrade 2"
  };

  bool IsFactionValid(int faction) {
    return (faction >= 0 && faction < MAX_FACTIONS);
  }
}

char * GetFirstLevelGrowerName(int faction) {
  ASSERT(IsFactionValid(faction));
  return &firstLevelGrowerNames[faction][0];
}

char * GetSpecialBuildingName(int faction) {
  ASSERT(IsFactionValid(faction));
  return &specialBuildingNames[faction][0];
}

char * GetSpecialBuildingDesc(int faction) {
  ASSERT(IsFactionValid(faction));
  return &specialBuildingDescriptions[faction][0];
}

char * GetIronfistDwellingName(int faction, int dwelling) {
  ASSERT(IsFactionValid(faction));
  ASSERT(dwelling > 0 && dwelling < NUM_DWELLINGS);

  if (faction == FACTION_CYBORG) {
    return &cyborgDwellings[dwelling][0];
  }

  return "INVALID DWELLING";
}

extern BUILDING_CODE gBuildingsToDraw[MAX_FACTIONS][BUILDING_MAX] = {
  { // Knight buildings
    BUILDING_SPECIAL_GROWTH,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_SPECIAL,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_CAPTAIN,
    BUILDING_MOAT,
    BUILDING_MARKET,
    BUILDING_THIEVES_GUILD,
    BUILDING_DWELLING_2,
    BUILDING_UPGRADE_1,
    BUILDING_DWELLING_5,
    BUILDING_UPGRADE_4,
    BUILDING_TAVERN,
    BUILDING_MAGE_GUILD,
    BUILDING_DWELLING_6,
    BUILDING_UPGRADE_5,
    BUILDING_EXT_1,
    BUILDING_EXT_2,
    BUILDING_EXT_0,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_3,
    BUILDING_UPGRADE_2,
    BUILDING_DWELLING_4,
    BUILDING_UPGRADE_3,
    BUILDING_STATUE,
    BUILDING_WELL,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { // Barbarian buildings
    BUILDING_EXT_0,
    BUILDING_EXT_1,
    BUILDING_SPECIAL,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_DWELLING_6,
    BUILDING_THIEVES_GUILD,
    BUILDING_CAPTAIN,
    BUILDING_DWELLING_5,
    BUILDING_UPGRADE_4,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_MOAT,
    BUILDING_MARKET,
    BUILDING_DWELLING_2,
    BUILDING_UPGRADE_1,
    BUILDING_DWELLING_3,
    BUILDING_EXT_3,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_4,
    BUILDING_UPGRADE_3,
    BUILDING_MAGE_GUILD,
    BUILDING_EXT_2,
    BUILDING_TAVERN,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_WELL,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_STATUE,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { // Sorceress buildings
    BUILDING_SPECIAL,
    BUILDING_DWELLING_6,
    BUILDING_DWELLING_5,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_MOAT,
    BUILDING_CAPTAIN,
    BUILDING_DWELLING_3,
    BUILDING_UPGRADE_2,
    BUILDING_DWELLING_1,
    BUILDING_MAGE_GUILD,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_DWELLING_4,
    BUILDING_UPGRADE_3,
    BUILDING_WELL,
    BUILDING_MARKET,
    BUILDING_DWELLING_2,
    BUILDING_UPGRADE_1,
    BUILDING_THIEVES_GUILD,
    BUILDING_TAVERN,
    BUILDING_EXT_1,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_STATUE,
    BUILDING_EXT_0,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { // Warlock buildings
    BUILDING_DWELLING_5,
    BUILDING_DWELLING_3,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_CAPTAIN,
    BUILDING_EXT_0,
    BUILDING_MOAT,
    BUILDING_TAVERN,
    BUILDING_THIEVES_GUILD,
    BUILDING_MAGE_GUILD,
    BUILDING_MARKET,
    BUILDING_STATUE,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_DWELLING_1,
    BUILDING_SPECIAL,
    BUILDING_DWELLING_4,
    BUILDING_UPGRADE_3,
    BUILDING_DWELLING_2,
    BUILDING_UPGRADE_5,
    BUILDING_UPGRADE_5B,
    BUILDING_DWELLING_6,
    BUILDING_WELL,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { // Wizard buildings
    BUILDING_UPGRADE_5,
    BUILDING_DWELLING_6,
    BUILDING_THIEVES_GUILD,
    BUILDING_CAPTAIN,
    BUILDING_EXT_0,
    BUILDING_DWELLING_5,
    BUILDING_UPGRADE_4,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_MOAT,
    BUILDING_DWELLING_3,
    BUILDING_UPGRADE_2,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_4,
    BUILDING_MAGE_GUILD,
    BUILDING_TAVERN,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_WELL,
    BUILDING_DWELLING_2,
    BUILDING_SPECIAL,
    BUILDING_MARKET,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_STATUE,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { // Necromancer buildings
    BUILDING_SPECIAL,
    BUILDING_TAVERN,
    BUILDING_CASTLE,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_MOAT,
    BUILDING_CAPTAIN,
    BUILDING_THIEVES_GUILD,
    BUILDING_DWELLING_6,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_3,
    BUILDING_UPGRADE_2,
    BUILDING_MAGE_GUILD,
    BUILDING_EXT_0,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_DWELLING_5,
    BUILDING_UPGRADE_4,
    BUILDING_DWELLING_2,
    BUILDING_UPGRADE_1,
    BUILDING_DWELLING_4,
    BUILDING_UPGRADE_3,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_TENT,
    BUILDING_WELL,
    BUILDING_MARKET,
    BUILDING_STATUE,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID,
    BUILDING_INVALID
  },
  { BUILDING_INVALID },
  { BUILDING_INVALID },
  { BUILDING_INVALID },
  { BUILDING_INVALID },
  { BUILDING_INVALID },
  { BUILDING_INVALID },
  { // Cyborg buildings (include them all for now)
    BUILDING_MAGE_GUILD,
    BUILDING_THIEVES_GUILD,
    BUILDING_TAVERN,
    BUILDING_DOCK,
    BUILDING_WELL,
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_STATUE,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_MARKET,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_MOAT,
    BUILDING_SPECIAL,
    BUILDING_BOAT,
    BUILDING_CAPTAIN,
    BUILDING_EXT_0,
    BUILDING_EXT_1,
    BUILDING_EXT_2,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_2,
    BUILDING_DWELLING_3,
    BUILDING_DWELLING_4,
    BUILDING_DWELLING_5,
    BUILDING_DWELLING_6,
    BUILDING_UPGRADE_1,
    BUILDING_UPGRADE_2,
    BUILDING_UPGRADE_3,
    BUILDING_UPGRADE_4,
    BUILDING_UPGRADE_5,
    BUILDING_UPGRADE_5B,
    BUILDING_EXT_3
  }
};

extern building_cost gSpecialBuildingCosts[MAX_FACTIONS] = {
  {5, 0, 15, 0, 0, 0, 1500},
  {10, 0, 10, 0, 0, 0, 2000},
  {0, 0, 0, 0, 10, 0, 1500},
  {5, 0, 10, 0, 0, 0, 3000},
  {5, 5, 5, 5, 5, 5, 1500},
  {0, 10, 0, 10, 0, 0, 1000},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {5, 0, 15, 0, 0, 0, 1500}  // TODO: what should Cyborg special building cost?
};