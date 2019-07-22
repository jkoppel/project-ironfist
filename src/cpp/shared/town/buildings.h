#ifndef BUILDINGS_H
#define BUILDINGS_H

#define NUM_NON_DWELLING_BUILDINGS 18

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

#endif
