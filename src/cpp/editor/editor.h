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
  int zoomLevel;
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
  void SpellScrollEditDialog(int *a1);
  void SpellScrollEditDialog_orig(int *RelatedToSpellIdx);
  void __thiscall UpdateCursor();
  signed int GetOverlayID(int x, int y);
};

extern editManager* gpEditManager;
extern SMapHeader gpMapHeader;
extern heroWindow* gpCellEditDialog;
extern heroWindow* gpSpecEditDialog;
extern int OriginalSpell;

void __fastcall ShowErrorMessage(const char *str);

int __fastcall SpellScrollEditDialogCallback(tag_message& msg);
int __fastcall SpellScrollEditDialogCallback_orig(tag_message& msg);

extern int CountMines();

extern int __fastcall SelectTerrainTile(int, int, int, int, int, int, float);

extern char* gpTownNames[];

extern void __cdecl RedrawEditPane();

int __cdecl WinConditionHandler();
extern int __cdecl WinConditionHandler_orig();
int __fastcall FillInWinCondition(int);
extern int __fastcall FillInWinCondition_orig(int);

#pragma pack(pop)

#endif