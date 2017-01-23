#ifndef OVERLAY_H
#define OVERLAY_H


#define NUM_OVERLAYS 970 // must be also changed in asm!
#define NUM_TILESETS 64

enum OVERLAY_CATEGORY : __int8 {
  OVERLAY_CATEGORY_TERRAIN = 0,
  OVERLAY_CATEGORY_TREASURE = 1,
  OVERLAY_CATEGORY_CREATURE = 2,
  OVERLAY_CATEGORY_ARTIFACT = 3,
  OVERLAY_CATEGORY_TOWN = 5,
  OVERLAY_CATEGORY_HERO = 7,
};

#pragma pack(push, 1)
struct overlay
{
  int idx;
  int idx2;
  int ordinal;
  char tileset;
  char category;
  __int16 field_E;
  char field_10;
  __int64 intersectsTileMask;
  int terrainObjCategoryMask;
  int allowedTerrainPlacementMask;
  __int64 coveredNonObstructedMask;
  __int64 shadowsMask;
  __int64 animatedLateOverlay;
  __int64 resourceField;
  char townColorOrMineColor;
  char field_42;
  __int64 interactionPointMask;
  char field_4B;
  char locationType;
  char field_4D;
  int field_4E;
  char fullGridIconIndices[48];
};
#pragma pack(pop)


extern signed int __fastcall OverlayMaskBitSet(__int64 *mask, int x, int y);
overlay gOverlayDatabase[];

extern signed int __fastcall PlaceOverlay_orig(overlay *ovr, int left, int right, int userDemanded);

//FIXME: Check sig, names
extern int __fastcall ValidOverlayPlacement(overlay*,int,int,int);
extern int CountTowns();
extern int CountPlacedEvents();

#endif