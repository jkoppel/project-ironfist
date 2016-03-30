#ifndef MAP_H
#define MAP_H

#include "adventure/adv.h"

#pragma pack(push, 1)

class mapCell
{
public:
  __int16 groundIndex;
  char bitfield_1_hasObject_1_isRoad_6_objTileset;
  char objectIndex;
  unsigned __int16 field_4_1_1_isShadow_1_13_extraInfo;
  char field__1_hasOverlay_1_q_6_overlayTileset;
  char overlayIndex;
  char displayFlags;
  char objType;
  __int16 extraIdx;
#ifdef EDITOR
  int objLink;
  int ovrLink;
#endif
};

struct mapCellExtra;

class fullMap {
public:
	mapCell *tiles;
	mapCellExtra *cellExtras;
	int width;
	int height;
	int numCellExtras;
	fullMap();
	~fullMap();

	void Read(int,int);
	void Write(int);
};


struct SMapHeader {
	int field_0;
	__int16 field_4;
	char width;
	char height;
	char hasPlayer[6];
	char playerMayBeHuman[6];
	char playerMayBeComp[6];
	char numPlayers;
	char minHumans;
	char maxHumans;
	char winConditionType;
	char field_1E;
	char allowDefeatAllVictory;
	__int16 winConditionArgument;
	int field_22;
	char playerFactions[6];
	__int16 field_2C;
	int field_2E;
	int field_32;
	char field_36;
	char field_37;
	char field_38;
	char field_39;
	char name[60];
	char description[298];
	char field_1A0;
	char field_1A1;
	char numRumors;
	char numEvents;
};


extern int MAP_HEIGHT;
extern int MAP_WIDTH;

extern int iMaxMapExtra;
extern unsigned char* mapExtra;
extern void** ppMapExtra;
extern short* pwSizeOfMapExtra;

extern signed char xIsExpansionMap;

extern void __fastcall ClearMapExtra();

struct townMapExtra
{
  char color;
  char customBuildings;
  int buildingsBuilt;
  char mageGuildLevel;
  char customGarrison;
  armyGroup garrison;
  char hasCaptain;
  char customName;
  char name[13];
  char faction;
  char isCastle;
  char disallowCastle;
  char _[25];
  char field_42;
  char field_43;
  char field_44;
  char field_45;
};

#pragma pack(pop)

#endif