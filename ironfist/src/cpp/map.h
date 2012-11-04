#ifndef MAP_H
#define MAP_H

#include "adventure/adv.h"

#pragma pack(push, 1)

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
  char field_18;
  char name[12];
  char field_25;
  __int16 faction;
  char mayNotBeUpgraded;
  char field_29;
  char field_2A;
  char field_2B[6];
  char _[17];
  char field_42;
  char field_43;
  char field_44;
  char field_45;
};

#pragma pack(pop)

#endif