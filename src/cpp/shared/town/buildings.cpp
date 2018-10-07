#include "town/buildings.h"

#include "base.h"
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
    "Special"
    "",
    "",
    "",
    "",
    "",
    "[TODO] Cyborg Special"
  };

  bool IsFactionValid(int faction) {
    return faction >= 0 && faction < static_cast<int>(firstLevelGrowerNames.size());
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