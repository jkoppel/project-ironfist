
#ifndef RESOURCE_H
#define RESOURCE_H

#pragma pack(push,1)

struct resourceVtable;

enum RESOURCE_TYPE : __int16
{
  RESOURCE_TYPE_BITMAP = 0x0,
  RESOURCE_TYPE_ICN = 0x1,
  RESOURCE_TYPE_PALETTE = 0x2,
  RESOURCE_TYPE_TILESET = 0x3,
  RESOURCE_TYPE_FONT = 0x5,
  RESOURCE_TYPE_SAMPLE = 0x6,
};

struct resource
{
  resourceVtable *vtable;
  RESOURCE_TYPE resourceType;
  __int16 referenceCount;
  unsigned int fileID;
  resource *next;
};

struct bitmap
{
  resourceVtable *vtable;
  RESOURCE_TYPE resourceType;
  __int16 referenceCount;
  int fileID;
  int next;
  __int16 setInConstructor;
  __int16 width;
  __int16 height;
  unsigned __int8 *contents;
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

struct icon
{
  resourceVtable *vtable;
  RESOURCE_TYPE resourceType;
  __int16 referenceCount;
  int fileID;
  resource *next;
  __int16 numSprites;
  IconEntry *headersAndImageData;
};

class font
{
public:

  resourceVtable *vtable;
  __int16 resourceType;
  __int16 referenceCount;
  int fileID;
  int next;
  int lineHeight;
  int whetherFirstShortIsMoreThan13;
  int field_18;
  icon *icon;
};

class palette
{
public:

  resourceVtable *vtable;
  __int16 resourceType;
  __int16 referenceCount;
  int fileID;
  int next;
  char *contents;
};

#pragma pack(pop)

#endif
