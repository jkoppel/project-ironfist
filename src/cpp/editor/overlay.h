#ifndef OVERLAY_H
#define OVERLAY_H


#define MAX_OVERLAYS 2048
#define NUM_TILESETS 64

enum OVERLAY_CATEGORY : __int8 {
  OVERLAY_CATEGORY_TERRAIN = 0,
  OVERLAY_CATEGORY_TREASURE = 1,
  OVERLAY_CATEGORY_CREATURE = 2,
  OVERLAY_CATEGORY_ARTIFACT = 3,
  OVERLAY_CATEGORY_TOWN = 5,
  OVERLAY_CATEGORY_BUILTIN = 6,
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

#pragma pack(push, 1)
class overlayManager : public baseManager
{
public:
  int field_36;
  icon *overlayTiles;
  icon *overlaySelectBoxes;
  overlay availOverlays[956];
  int nAvailOverlays;
  int field_1E5BE;
  int field_1E5C2;
  widget *selectionHighlight;
  textWidget *textWid;
  void *objTypeButtons[14];
  heroWindow *selectionWindow;
  widget *scrollBar;
  widget *slider;
  int field_1E612;
  int Open(int);
  int Open_orig(int);
  int SelectObject(int objType);
  int SelectObject_orig(int objType);
  int PopulateAvailOverlays(int ovrType);
  void SetupOverlayWindow(int draw);
  void DrawAffectedTileGrid(int x, int y, int width, int height, overlay *ovr, signed int a7);
  void DrawOverlay(overlay *ovr, int xoff, int yoff, int a4, int width, int height, int draw, signed int a8, int a9);
  int SelectOverlayMain(tag_message &evt);
  int SelectOverlayMain_orig(tag_message &evt);
};
#pragma pack(pop)

extern signed int __fastcall OverlayMaskBitSet(__int64 *mask, int x, int y);
overlay gOverlayDatabase[];
extern int gNumOverlays;
extern char gOverlayTypeCategories[13];
extern int gObjTypeTerrains[13];

extern signed int __fastcall sub_4291A2(overlay *ovr, int x, int y, int a4);
extern int __fastcall sub_429170(overlay *ovr, int x, int y);
signed int __stdcall sub_42AAF9(int *x, int *y, int a3, int doMountains, char tileset);

//FIXME: Check sig, names
extern int __fastcall ValidOverlayPlacement(overlay*,int,int,int);
extern int CountTowns();
extern int CountPlacedEvents();
void LoadOverlays();
void LoadOverlayNames();

#endif