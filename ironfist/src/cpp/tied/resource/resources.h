#ifndef TIED_RESOURCE_H
#define TIED_RESOURCE_H

#include <winsock.h>

#pragma pack(push,1)

#define MAX_FILENAME_LENGTH 13

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
  ~bitmap();
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
};

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

  sample(char *,long,long,long);
  ~sample();
};

class MIDIWrap : public resource
{
public:
  void *contents;

  MIDIWrap(char*);
  ~MIDIWrap();
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
  char *contents;

  palette();
  palette(unsigned long);
  ~palette();
};

extern palette* gpBufferPalette;

class font : public resource
{
public:
  int lineHeight;
  int whetherFirstShortIsMoreThan13;
  int field_18;
  icon *icon;

  font(unsigned long);
  ~font();
};


#define NUM_GOOD_EVIL_ICONS 37

#pragma pack(pop)

#endif
