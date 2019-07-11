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
	char _[378-sizeof(baseManager)-sizeof(town*)];
	townManager();

	void BuildObj(signed int);

	virtual int Open(int);
	int Open_orig(int);
	void SetupMage(heroWindow*);
	void SetupWell(heroWindow*);
	void SetupWell_orig(heroWindow*);

	int RecruitHero(int,int);
	int RecruitHero_orig(int,int);
};

class recruitUnit : public baseManager {
  public:
    int field_36;
    int creatureType;
    int field_3E;
    int field_42;
    int field_46;
    int field_4A;
    int field_4E;
    int field_52;
    int field_56;
    armyGroup *army;
    int field_5E;
    int field_62;
    int field_66;
    int available;
    int field_6E;
    int field_72;
    int field_76;
    int field_7A;
   
	virtual int Open(int);
    int Open_orig(int);
};

char *__fastcall GetBuildingName(int faction, int building);
char * __fastcall GetBuildingInfo(int faction, int building, int withTitle);
char * __fastcall GetBuildingInfo_orig(int faction, int building, int withTitle);
int GetDwellingType(int faction, int dwellingIndex);
char * GetDwellingName(int faction, int dwellingIndex);

extern townManager* gpTownManager;

#pragma pack(pop)

#endif
