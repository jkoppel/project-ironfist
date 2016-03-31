#ifndef GUI_H
#define GUI_H

#include "manager.h"
#include "resource/resources.h"

#pragma pack(push,1)

class heroWindow;

class widget {
public:
  heroWindow *parentWindow;
  widget *nextInLinkedList;
  widget *prevInLinkedList;
  __int16 fieldID;
  __int16 componentIndex;
  __int16 field_14;
  __int16 flags;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;

  virtual void Draw();
  virtual ~widget();
  virtual int main(tag_message&);
};

class textWidget : public widget {
  char *content;
  font *font;
  __int16 field_28;
  char field_2A;
};

class heroWindow {
public:
  int idx;
  heroWindow *nextWindow;
  heroWindow *prevWindow;
  char filename[20];
  int flags1;
  int flags2;
  int xOffset;
  int yOffset;
  int width;
  int height;
  widget *lastWidget;
  widget *firstWidget;
  bitmap *bitmap;

  heroWindow(int, int, char*);
  int BroadcastMessage(tag_message&);
};

class heroWindowManager : public baseManager
{
public:
  heroWindow *firstWindow;
  heroWindow *lastWindow;
  heroWindow *topmostWindow;
  heroWindow *nextTopmostWindow;
  bitmap *screenBuffer;
  bitmap *fizzleSource;
  bitmap *field_4E;
  int numScreenshots;
  int field_56;
  int buttonPressedCode;
  int hoveredFieldID;

  heroWindowManager();

  int DoDialog(heroWindow *,int (__fastcall*)(tag_message &),int);
};

extern heroWindowManager* gpWindowManager;

enum ICON_GUI_FLAGS
{
  ICON_GUI_VISIBLE = 0x4,
};

/* These functions provide a simpler API to parts of the old GUI "BroadcastMessage" API */

void GUIAddFlag(heroWindow*, int, int);
void GUIRemoveFlag(heroWindow*, int, int);
void GUISetImgIdx(heroWindow*, int, int);
void GUISetIcon(heroWindow*, int, char*);
void GUISetText(heroWindow*, int, char*);

void GUIBroadcastMessage(heroWindow*, int,int,void*);

void __fastcall SetupRecruitWin(heroWindow *,int,int,int,int,int);
void __fastcall QuickViewWait(void);

#pragma pack(pop)

#endif
