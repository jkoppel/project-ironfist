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

char * GetIronfistDwellingName(int faction, int dwelling) {
  ASSERT(IsFactionValid(faction));
  ASSERT(dwelling > 0 && dwelling < NUM_DWELLINGS);

  if (faction == FACTION_CYBORG) {
    return &cyborgDwellings[dwelling][0];
  }

  return "INVALID DWELLING";
}