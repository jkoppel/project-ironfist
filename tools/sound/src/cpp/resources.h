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


#define NUM_GOOD_EVIL_ICONS 37

#pragma pack(pop)

#endif
