#ifndef EDITOR_H
#define EDITOR_H

#include "manager.h"

#include "adventure/map.h"
#include "gui/gui.h"
#include "resource/resources.h"

#pragma pack(push, 1)

extern fullMap gpMap;
extern mapCell* gpExaminedCell;

class editManager : public baseManager
{
public:
  int curToolBoxNo;
  icon *radarIcons;
  icon *editButtonIcons;
  tileset *groundTileset;
  int field_46;
  tileset *clof32Tileset;
  int field_4E;
  icon *overlayIcons[64][2];
  /* These next four are actually iconWidget's, which have yet to be exposed */
  widget *horizontalScrollBar; 
  widget *verticalScrollBar;
  widget *horizontalScrollHandle;
  widget *verticalScrollHandle;
  int cursorType;
  int setOnEventUpdate;
  int field_26A;
  int field_26E;
  int field_272;
  int brushSize;
  int field_27A;
  int field_27E;
  int field_282;
  int toolManager;
  heroWindow *editWindow;
  int nMapExtra;
  __int16 lenMapExtra[512];
  void *mapExtra[512];
  int cellLeft;
  int cellTop;
  int cursorX;
  int cursorY;

  editManager();

  void InitializeMap(int random, int width, int height);
  void InitializeMap_orig(int random, int width, int height);
  void SpellScrollEditDialog(void **a1);
  void __thiscall UpdateCursor();
};

extern editManager* gpEditManager;
extern SMapHeader gpMapHeader;

void __fastcall ShowErrorMessage(const char *str);

extern int CountMines();

extern int __fastcall SelectTerrainTile(int, int, int, int, int, int, float);

extern char* gpTownNames[];

extern void __cdecl RedrawEditPane();

#pragma pack(pop)

#endif