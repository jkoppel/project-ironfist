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
    "Cybernetics Lab"
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
    "Radiation Tower"
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
    "Lowers luck of enemies"
  };

  std::vector<std::string> cyborgDwellings = {
    "Sewer",
    "Meeting Hall",
    "Arena",
    "Hunting Grounds",
    "Dojo",
    "Nexus",
    "Cyborg Level 2 Upgrade",
    "Cyborg Level 3 Upgrade",
    "Cyborg Level 4 Upgrade",
    "Cyborg Level 5 Upgrade",
    "Cyborg Level 6 Upgrade"
  };

  bool IsFactionValid(int faction) {
    return (faction >= 0 && faction < MAX_FACTIONS);
  }
}

BUILDING_CODE gBuildingsToDraw[MAX_FACTIONS][BUILDING_MAX] = {
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
    BUILDING_TENT,
    BUILDING_CASTLE,
    BUILDING_WELL,
    BUILDING_STATUE,
    BUILDING_LEFT_TURRET,
    BUILDING_RIGHT_TURRET,
    BUILDING_SPECIAL_GROWTH,
    BUILDING_MOAT,
    BUILDING_SPECIAL,
    BUILDING_CAPTAIN,
    BUILDING_EXT_1,
    BUILDING_EXT_0,
    BUILDING_EXT_2,
    BUILDING_DOCK,
    BUILDING_BOAT,
    BUILDING_DWELLING_1,
    BUILDING_DWELLING_2,
    BUILDING_MARKET,
    BUILDING_TAVERN,
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
    BUILDING_THIEVES_GUILD,
    BUILDING_EXT_3
  }
};

SBuildingCost gSpecialBuildingCosts[MAX_FACTIONS] = {
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

SBuildingCost gDwellingCosts[MAX_FACTIONS][NUM_DWELLINGS] = { 0 };

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
  ASSERT(dwelling >= 0 && dwelling < NUM_DWELLINGS);

  if (faction == FACTION_CYBORG) {
    return &cyborgDwellings[dwelling][0];
  }

  return "INVALID DWELLING";
}

void InitDwellingCosts() {
  gDwellingCosts[FACTION_KNIGHT][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 200 };
  gDwellingCosts[FACTION_KNIGHT][DWELLING_2] = { 0, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_KNIGHT][DWELLING_3] = { 0, 0, 5, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_KNIGHT][DWELLING_4] = {10, 0, 10, 0, 0, 0, 2000};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_5] = {20, 0, 0, 0, 0, 0, 3000};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_6] = {20, 0, 0, 0, 20, 0, 5000};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_2_UPGRADE] = {5, 0, 0, 0, 0, 0, 1500};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_3_UPGRADE] = {0, 0, 5, 0, 0, 0, 1500};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_4_UPGRADE] = {5, 0, 5, 0, 0, 0, 2000};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_5_UPGRADE] = {10, 0, 0, 0, 0, 0, 3000};
  gDwellingCosts[FACTION_KNIGHT][DWELLING_6_UPGRADE] = {10, 0, 0, 0, 10, 0, 5000};

  gDwellingCosts[FACTION_BARBARIAN][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 300 };
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_2] = { 5, 0, 0, 0, 0, 0, 800 };
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_3] = {0, 0, 0, 0, 0, 0, 1000};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_4] = {10, 0, 10, 0, 0, 0, 2000};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_5] = {0, 0, 20, 0, 0, 0, 4000};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_6] = {0, 0, 20, 0, 20, 0, 6000};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_2_UPGRADE] = {5, 0, 0, 0, 0, 0, 1200};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_4_UPGRADE] = {5, 0, 5, 0, 0, 0, 3000};
  gDwellingCosts[FACTION_BARBARIAN][DWELLING_5_UPGRADE] = {0, 0, 10, 0, 0, 0, 2000};

  gDwellingCosts[FACTION_SORCERESS][DWELLING_1] = { 5, 0, 0, 0, 0, 0, 500 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_2] = { 5, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_3] = { 0, 0, 0, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_4] = { 0, 0, 10, 0, 0, 0, 2500 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_5] = {10, 0, 0, 0, 0, 10, 3000 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_6] = { 0, 20, 30, 0, 0, 0, 10000 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_2_UPGRADE] = { 5, 0, 0, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_3_UPGRADE] = { 5, 0, 0, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_SORCERESS][DWELLING_4_UPGRADE] = { 0, 5, 0, 0, 0, 0, 1500 };

  gDwellingCosts[FACTION_WARLOCK][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 500 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_2] = { 0, 0, 10, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_3] = { 0, 0, 0, 0, 0, 0, 2000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_4] = { 0, 0, 0, 0, 0, 10, 3000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_5] = { 0, 0, 0, 10, 0, 0, 4000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_6] = { 0, 0, 30, 20, 0, 0, 15000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_4_UPGRADE] = { 0, 0, 0, 0, 0, 5, 2000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_6_UPGRADE] = { 0, 0, 5, 10, 0, 0, 5000 };
  gDwellingCosts[FACTION_WARLOCK][DWELLING_6_UPGRADE2] = { 0, 0, 5, 10, 0, 0, 5000 };

  gDwellingCosts[FACTION_WIZARD][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 400 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_2] = { 0, 0, 0, 0, 0, 0, 800 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_3] = { 5, 0, 5, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_4] = { 5, 0, 0, 0, 0, 0, 3000 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_5] = { 5, 5, 5, 5, 5, 5, 3500 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_6] = { 5, 0, 5, 0, 0, 20, 12500 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_3_UPGRADE] = { 0, 5, 0, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_5_UPGRADE] = { 5, 0, 5, 0, 0, 0, 4000 };
  gDwellingCosts[FACTION_WIZARD][DWELLING_6_UPGRADE] = { 5, 0, 5, 0, 0, 20, 12500 };

  gDwellingCosts[FACTION_NECROMANCER][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 400 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_2] = { 0, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_3] = { 0, 0, 10, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_4] = { 10, 0, 0, 0, 0, 0, 3000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_5] = { 10, 0, 0, 10, 0, 0, 4000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_6] = { 10, 5, 10, 5, 5, 5, 10000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_2_UPGRADE] = { 0, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_3_UPGRADE] = { 0, 0, 5, 0, 0, 0, 1500 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_4_UPGRADE] = { 5, 0, 0, 0, 10, 10, 4000 };
  gDwellingCosts[FACTION_NECROMANCER][DWELLING_5_UPGRADE] = { 0, 0, 5, 0, 5, 0, 3000 };

  // TODO: decide on Cyborg building costs
  gDwellingCosts[FACTION_CYBORG][DWELLING_1] = { 0, 0, 0, 0, 0, 0, 200 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_2] = { 0, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_3] = { 0, 0, 5, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_4] = {10, 0, 10, 0, 0, 0, 2000};
  gDwellingCosts[FACTION_CYBORG][DWELLING_5] = {20, 0, 0, 0, 0, 0, 3000};
  gDwellingCosts[FACTION_CYBORG][DWELLING_6] = {20, 0, 0, 0, 20, 0, 5000};
  gDwellingCosts[FACTION_CYBORG][DWELLING_2_UPGRADE] = { 0, 0, 0, 0, 0, 0, 200 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_3_UPGRADE] = { 0, 0, 0, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_4_UPGRADE] = { 0, 0, 5, 0, 0, 0, 1000 };
  gDwellingCosts[FACTION_CYBORG][DWELLING_5_UPGRADE] = {10, 0, 10, 0, 0, 0, 2000};
  gDwellingCosts[FACTION_CYBORG][DWELLING_6_UPGRADE] = {20, 0, 0, 0, 0, 0, 3000};
}

void BuildingCostToIntArray(SBuildingCost &cost, int (&arr)[NUM_RESOURCES]) {
  arr[RESOURCE_WOOD] = cost.wood;
  arr[RESOURCE_MERCURY] = cost.mercury;
  arr[RESOURCE_ORE] = cost.ore;
  arr[RESOURCE_SULFUR] = cost.sulfur;
  arr[RESOURCE_CRYSTAL] = cost.crystal;
  arr[RESOURCE_GEMS] = cost.gems;
  arr[RESOURCE_GOLD] = cost.gold;
}