#ifndef TOWN_H
#define TOWN_H

#include "adventure/adv.h"
#include "town/town_globals.h"

#pragma pack(push,1)

extern signed char gSpellLimits[];

class town {
public:
  char idx;
  char ownerIdx;
  char alignment;
  char factionID;
  char x;
  char y;
  char buildDockRelated;
  char field_7;
  armyGroup garrison;
  char visitingHeroIdx;
  unsigned int buildingsBuiltFlags;
  char mageGuildLevel;
  char field_1D;
  __int16 numCreaturesInDwelling[NUM_DWELLINGS];
  char exists;
  char mayNotBeUpgradedToCastle;
  char field_38;
  char playerPos;
  __int16 extraIdx;
  char mageGuildSpells[5][4];
  char numSpellsOfLevel[5];
  __int16 field_55;
  char name[12];
  char field_63;

  town();

  void GiveSpells(hero *captain);
  void SelectSpells();
  void SetNumSpellsOfLevel(int,int);

  void BuildBuilding(int);
  bool BuildingBuilt(int) const;
  bool DwellingBuilt(int) const;

  // Get the index of the most upgraded building built at the given tier.
  // Returns integer in range [0, NUM_DWELLINGS), or -1 for an invalid
  // tier outside range [0, 5].
  int DwellingIndex(int) const;
};

class townManager : public baseManager {
public:
  town* castle;
  icon *couldBeBackground;
  townObject *buildingDisplays[32];
  int curBuilding;
  int factionID;
  int field_C6;
  heroWindow *townScreen;
  strip *garrisonDisplay;
  strip *visitingArmyDisplay;
  strip *field_D6;
  int field_DA;
  strip *field_DE;
  int field_E2;
  strip *field_E6;
  int field_EA;
  bankBox *bankbox;
  char infoMessage[80];
  int field_142;
  int field_146;
  int field_14A;
  int field_14E;
  int field_152;
  int field_156;
  int field_15A;
  int field_15E;
  heroWindow *curScreen;
  heroWindow *dialog;
  int field_16A;
  int field_16E;
  int recruitHeroConfirmed;
  hero *heroBeingRecruited;
  townManager();

  void BuildObj(signed int);

  virtual int Open(int);
  int Open_orig(int);
  void SetupMage(heroWindow*);
  void SetupWell(heroWindow*);
  void SetupWell_orig(heroWindow*);

  int RecruitHero(int,int);
  int RecruitHero_orig(int,int);
  void RedrawTownScreen();
  void RedrawTownScreen_orig();
  void SetCommandAndText(struct tag_message &evt);
  void SetCommandAndText_orig(struct tag_message &evt);
  void DrawTown(int a2, int a3);
  void UnloadTown();
};

char *__fastcall GetBuildingName(int faction, int building);
char * __fastcall GetBuildingInfo(int faction, int building, int withTitle);
char * __fastcall GetBuildingInfo_orig(int faction, int building, int withTitle);
int GetDwellingType(int faction, int dwellingIndex);
char * GetDwellingName(int faction, int dwellingIndex);

extern townManager* gpTownManager;

#pragma pack(pop)

#endif
