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
}

char * GetFirstLevelGrowerName(int faction) {
  ASSERT(faction >= 0 && faction < static_cast<int>(firstLevelGrowerNames.size()));
  return &firstLevelGrowerNames[faction][0];
}