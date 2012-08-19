#ifndef TIED_GAME_H
#define TIED_GAME_H

#include "tied/adventure/adv.h"

#pragma pack(push,1)

enum FACTION
{
  FACTION_KNIGHT = 0x0,
  FACTION_BARBARIAN = 0x1,
  FACTION_SORCERESS = 0x2,
  FACTION_WARLOCK = 0x3,
  FACTION_WIZARD = 0x4,
  FACTION_NECROMANCER = 0x5,
  FACTION_MULTIPLE = 0x6,
  FACTION_RANDOM = 0x7,
};

class fullMap {
public:
	char _[20];
	fullMap();
	~fullMap();
};


#define BUILDING_RIGHT_TURRET_BUILT     0x1
#define BUILDING_LEFT_TURRET_BUILT      0x2
#define BUILDING_SPECIAL_DEFENSE_BUILT  0x20

class town {
public:
	char idx;
	char ownerIdx;
	char alignment;
	char factionID;
	char field_4;
	char field_5;
	__int16 field_6;
	armyGroup garrison;
	char visitingHeroIdx;
	unsigned int buildingsBuiltFlags;
	char mageGuildLevel;
	char field_1D;
	__int16 numCreaturesInDwelling[12];
	char field_36;
	char mayNotBeUpgradedToCastle;
	char _2[4];
	char mageGuildSpells[5][4];
	char numSpellsOfLevel[5];
	__int16 field_55;
	char name[12];
	char field_63;

	town();
};

class game {
public:
	char _[0xB3E];
	fullMap f;
	char numObelisks;
	town castles[72];
	char _7[81];
	hero h[54];
	char _8[2447];

	int GetRandomNumTroops(int);
};

extern game* gpGame;

#pragma pack(pop)

#endif