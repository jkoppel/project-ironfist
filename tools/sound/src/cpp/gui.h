
#ifndef GUI_H
#define GUI_H

#pragma pack(push,1)


#include "baseManager.h"
#include "resource.h"

struct widgetVtable;
class heroWindow;

class widget
{
public:

  widgetVtable *vtable;
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
};

enum BUTTON_FLAGS
{
  BUTTON_IS_ARMED = 0x1,
};

struct button
{
  widgetVtable *vtable;
  heroWindow *parentWindow;
  int nextInLinkedList;
  int prevInLinkedList;
  __int16 fieldID;
  __int16 field_12;
  __int16 field_14;
  BUTTON_FLAGS flags;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  icon *icon;
  __int16 normalImageIdx;
  __int16 armedImageIdx;
  __int16 field_28;
  __int16 field_2A;
  int icnFileID;
};

struct listBox
{
  int vtable;
  heroWindow *parentWindow;
  int nextInLinkedList;
  int prevInLinkedList;
  __int16 fieldID;
  __int16 componentIdx;
  __int16 field_14;
  __int16 field_16;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  int fontID;
  icon *icon;
  __int16 field_28;
  __int16 field_2A;
  __int16 field_2C;
  __int16 field_2E;
  __int16 field_30;
  __int16 field_32;
  __int16 field_34;
  __int16 field_36;
  __int16 field_38;
  __int16 field_3A;
  __int16 field_3C;
  __int16 field_3E;
  __int16 field_40;
  __int16 field_42;
  __int16 field_44[23];
  __int16 field_72[15];
};

struct textWidget
{
  widgetVtable *vtable;
  heroWindow *parentWindow;
  int nextInLinkedList;
  int prevInLinkedList;
  __int16 fieldID;
  __int16 field_12;
  __int16 field_14;
  __int16 field_16;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  char *content;
  font *font;
  __int16 field_28;
  char field_2A;
};

struct textEntryWidget
{
  int vtable;
  heroWindow *parentWindow;
  int nextInLinkedList;
  int prevInLinkedList;
  __int16 fieldID;
  __int16 field_12;
  __int16 field_14;
  __int16 field_16;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  void *ptrToFifthShortPlusFiveManyBytes;
  int font;
  __int16 field_28;
  char field_2A;
  int icon;
  __int16 field_2F;
  __int16 field_31;
  __int16 fifthShort;
  __int16 field_35;
  __int16 field_37;
  __int16 field_39;
  __int16 field_3B;
  __int16 field_3D;
  __int16 field_3F;
  __int16 field_41;
  __int16 field_43;
  __int16 _1;
  __int16 field_47;
  __int16 type;
  __int16 field_4B;
  char _2;
};

struct iconWidget
{
  widgetVtable *vtable;
  heroWindow *parentWindow;
  widget *nextInLinkedList;
  widget *prevInLinkedList;
  __int16 fieldID;
  __int16 componentIndex;
  __int16 field_14;
  __int16 field_16;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  icon *icon;
  __int16 imgIdx;
  char mirror;
  __int16 field_27;
  int iconFileID;
};

class heroWindow
{
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
  heroWindow(int,int,char*);
};

class heroWindowManager
{
public:

  managerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
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
  int DoDialog(heroWindow*, int (__fastcall*)(struct tag_message &),int);
};

#pragma pack(pop)

#endif
