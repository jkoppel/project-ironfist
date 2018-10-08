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