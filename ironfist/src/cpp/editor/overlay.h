#ifndef OVERLAY_H
#define OVERLAY_H


#define NUM_OVERLAYS 964
#define NUM_TILESETS 64

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
  __int64 field_31;
  __int64 field_39;
  char field_41;
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
extern int ValidOverlayPlacement(overlay*,int,int,int);
extern int CountTowns();
extern int CountPlacedEvents();

#endif