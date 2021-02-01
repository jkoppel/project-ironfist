#ifndef TIED_RESOURCE_H
#define TIED_RESOURCE_H

#include <winsock.h>
#include "graphics.h"
#pragma pack(push,1)

#define MAX_FILENAME_LENGTH 13
#define PALETTE_SIZE 768

enum RESOURCE_TYPE : short
{
  RESOURCE_TYPE_BITMAP = 0x0,
  RESOURCE_TYPE_ICN = 0x1,
  RESOURCE_TYPE_PALETTE = 0x2,
  RESOURCE_TYPE_TILESET = 0x3,
  RESOURCE_TYPE_FONT = 0x5,
  RESOURCE_TYPE_SAMPLE = 0x6,
};

class resource
{
public:
  RESOURCE_TYPE resourceType;
  __int16 referenceCount;
  unsigned int fileID;
  resource *next;

  virtual ~resource();
};

class bitmap : public resource
{
public:
  __int16 setInConstructor;
  __int16 width;
  __int16 height;
  signed __int8 *contents;

  bitmap();
  bitmap(unsigned long);
  bitmap(short, short, short);
  ~bitmap();

  void GrabBitmapCareful(bitmap *, short, short);
  void DrawToBufferCareful(short, short);
  void DrawToBuffer(short, short);
  void CopyTo(bitmap *buf, int xTarg, int yTarg, int xFrom, int yFrom, int width, int height);
  void CopyToCareful(bitmap *target, int targX, int targY, int offX, int offY, int width, int height);
};

struct IconEntry
{
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  char someSortOfLength;
  int off;
};

class icon : public resource
{
public:
  __int16 numSprites;
  IconEntry *headersAndImageData;

  icon(unsigned long);
  ~icon();
  void DrawToBuffer(int,int,int,int);
  signed int CombatClipDrawToBuffer(int offsetX, int offsetY, int imageIdx, H2RECT *rect, int mirrored, int a11, unsigned char *paletteSubstitution, signed char *a12);
};

void __fastcall FlipIconToBitmap(icon *icn, bitmap *buf, int x, int y, int spriteIdx, signed int flag, int a7, int a8, int width, int height, int a11);
void __fastcall DimIconToBitmap(icon *a1, bitmap *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);
void __fastcall MonoIconToBitmap(icon *a1, bitmap *a2, int x, int y, int idx, int color, int a7, int a8, int a9, int a10, int a11);
void __fastcall IconToBitmap(icon *icn, bitmap *bmp, int a3, int a4, int spriteIdx, int a6, int a7, int a8, int a9, int a10, int a11);

class sample : public resource
{
public:
  int field_10;
  void *contents;
  int nbytes;
  int codeThing;
  unsigned int playbackRate;
  unsigned int sampleType;
  unsigned int field_28;
  int loopCount;
  
#ifndef EDITOR
  sample(char *,long,long,long);
  ~sample();
#endif
};

struct SAMPLE2 {
    sample *file;
    UINT32 sample; // actually an HSAMPLE, but HSAMPLE is not imported
};

extern SAMPLE2 NULL_SAMPLE2;

class MIDIWrap : public resource
{
public:
  void *contents;
  
#ifndef EDITOR
  MIDIWrap(char*);
  ~MIDIWrap();
#endif
};

class tileset : public resource
{
public:
  __int16 numTiles;
  __int16 field_12;
  __int16 field_14;
  void *contents;

  tileset(unsigned long);
  ~tileset();
};

class palette : public resource
{
public:
  signed char *contents;

  palette();
  palette(unsigned long);
  ~palette();
};

extern palette* gPalette;
extern palette* gpBufferPalette;

extern void __fastcall SetPalette(signed char *,int);

class font : public resource
{
public:
  int lineHeight;
  int whetherFirstShortIsMoreThan13;
  int field_18;
  icon *icon;

  font(unsigned long);
  ~font();

  int LineLength(char*, int);
  void DrawBoundedString(char *str, int x, int y, signed int regionWidth, int regionHeight, int a7, int alignType);
};

extern font* smallFont;
extern font* bigFont;

IconEntry *__fastcall GetIconEntry(icon *a1, int idx);
void __fastcall IconToBitmapColorTable(icon *a1, bitmap *buf, int a3, int a4, int a5, signed int a6, int a7, int a8, int a9, int a10, int a11, unsigned char *paletteSubstitution, int a13);
void __fastcall FlipIconToBitmap(icon *icn, bitmap *buf, int x, int y, int spriteIdx, signed int flag, int a7, int a8, int width, int height, int a11);
extern "C" char TileToBitmap(tileset *tiles, int idx, bitmap *targ, int x, int y);

#define NUM_GOOD_EVIL_ICONS 37

#pragma pack(pop)

#endif
