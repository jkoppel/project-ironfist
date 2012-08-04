
#ifndef RESOURCE_H
#define RESOURCE_H

struct resourceVtable;

struct resource
{
  RESOURCE_WOOD = 0x0,
  RESOURCE_MERCURY = 0x1,
  RESOURCE_ORE = 0x2,
  RESOURCE_SULFUR = 0x3,
  RESOURCE_CRYSTAL = 0x4,
  RESOURCE_GEMS = 0x5,
  RESOURCE_GOLD = 0x6,
};

struct bitmap
{
  ResourceVtable *vtable;
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
  ResourceVtable *vtable;
  RESOURCE_TYPE resourceType;
  __int16 referenceCount;
  int fileID;
  resource *next;
  __int16 numSprites;
  IconEntry *headersAndImageData;
};

#endif
