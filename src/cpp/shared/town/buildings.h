#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <adventure/adv.h>
#include <town/town_globals.h>

struct SBuildingInfo {
  char animationLength;
  short x;
  short y;
  short width;
  short height;
};

struct SBuildingCost {
  int wood;
  int mercury;
  int ore;
  int sulfur;
  int crystal;
  int gems;
  int gold;
};

char * GetFirstLevelGrowerName(int faction);
char * GetSpecialBuildingName(int faction);
char * GetSpecialBuildingDesc(int faction);
char * GetIronfistDwellingName(int faction, int dwelling);
void InitDwellingCosts();
void BuildingCostToIntArray(SBuildingCost &cost, int (&arr)[NUM_RESOURCES]);

extern SBuildingCost gSpecialBuildingCosts[];
extern SBuildingCost gDwellingCosts[MAX_FACTIONS][NUM_DWELLINGS];

#endif
