#ifndef TOWN_H
#define TOWN_H

#include "adventure/adv.h"

#pragma pack(push,1)

unsigned long gTownEligibleBuildMask[];

extern signed char gSpellLimits[];

extern char cHeroTypeInitial[];

#define MAX_CASTLES 72

enum HERO_TYPE
{
	HERO_TYPE_KNIGHT = 0,
	HERO_TYPE_BARBARIAN = 1,
	HERO_TYPE_SORCERESS = 2,
	HERO_TYPE_WARLOCK = 3,
	HERO_TYPE_WIZARD = 4,
	HERO_TYPE_NECROMANCER = 5,
	HERO_TYPE_KNIGHT_CAPTAIN = 6,
	HERO_TYPE_BARBARIAN_CAPTAIN = 7,
	HERO_TYPE_SORCERESS_CAPTAIN = 8,
	HERO_TYPE_WARLOCK_CAPTAIN = 9,
	HERO_TYPE_WIZARD_CAPTAIN = 10,
	HERO_TYPE_NECROMANCER_CAPTAIN = 11,
	HERO_TYPE_CYBORG = 12,
	HERO_TYPE_CYBORG_CAPTAIN = 18
};

enum FACTION
{
	FACTION_KNIGHT = 0,
	FACTION_BARBARIAN = 1,
	FACTION_SORCERESS = 2,
	FACTION_WARLOCK = 3,
	FACTION_WIZARD = 4,
	FACTION_NECROMANCER = 5,
	FACTION_MULTIPLE = 6,
	FACTION_RANDOM = 7,

	FACTION_CYBORG = 12,
	MAX_FACTIONS
};

enum BUILDING_CODE : __int8
{
  BUILDING_INVALID = -1,
  BUILDING_MAGE_GUILD = 0x0,
  BUILDING_THIEVES_GUILD = 0x1,
  BUILDING_TAVERN = 0x2,
  BUILDING_DOCK = 0x3,
  BUILDING_WELL = 0x4,
  BUILDING_TENT = 0x5,
  BUILDING_CASTLE = 0x6,
  BUILDING_STATUE = 0x7,
  BUILDING_LEFT_TURRET = 0x8,
  BUILDING_RIGHT_TURRET = 0x9,
  BUILDING_MARKET = 0xA,
  BUILDING_SPECIAL_GROWTH = 0xB,
  BUILDING_MOAT = 0xC,
  BUILDING_SPECIAL = 0xD,
  BUILDING_BOAT = 0xE,
  BUILDING_CAPTAIN = 0xF,
  BUILDING_EXT_0 = 0x10,
  BUILDING_EXT_1 = 0x11,
  BUILDING_EXT_2 = 0x12,
  BUILDING_DWELLING_1 = 0x13,
  BUILDING_DWELLING_2 = 0x14,
  BUILDING_DWELLING_3 = 0x15,
  BUILDING_DWELLING_4 = 0x16,
  BUILDING_DWELLING_5 = 0x17,
  BUILDING_DWELLING_6 = 0x18,
  //Why is "upgrade 1" an upgrade to dwelling 2?
  //Don't know; these names were found in the executable
  BUILDING_UPGRADE_1 = 0x19,
  BUILDING_UPGRADE_2 = 0x1A,
  BUILDING_UPGRADE_3 = 0x1B,
  BUILDING_UPGRADE_4 = 0x1C,
  BUILDING_UPGRADE_5 = 0x1D,
  BUILDING_UPGRADE_5B = 0x1E,
  BUILDING_EXT_3 = 0x1F,
  BUILDING_MAX
};

enum DWELLING_TYPE
{
  DWELLING_1,
  DWELLING_2,
  DWELLING_3,
  DWELLING_4,
  DWELLING_5,
  DWELLING_6,
  DWELLING_2_UPGRADE,
  DWELLING_3_UPGRADE,
  DWELLING_4_UPGRADE,
  DWELLING_5_UPGRADE,
  DWELLING_6_UPGRADE,
  DWELLING_6_UPGRADE2,
  NUM_DWELLINGS
};

// Order matters here. The original game indexes into gTownObjNames to
// access elements of gDwellingType.
extern char *gTownObjNames[];
extern unsigned char gDwellingType[][NUM_DWELLINGS];

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
