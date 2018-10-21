#ifndef BUILDINGS_H
#define BUILDINGS_H

struct building_cost {
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

#endif
