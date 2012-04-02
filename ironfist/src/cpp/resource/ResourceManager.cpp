

#ifndef RESMGR
#define RESMGR

#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<winsock.h>
#include "resources.h"
#include "../import_thunk.cpp"
#include "../input.h"
#include "../import_val.h"

#define MAX_FILENAME_LENGTH 13

ResourceManager * ResourceManager_constructor(ResourceManager *__this)
{
  int i; // [sp+10h] [bp-4h]@1

  AbstractManager_constructor((AbstractManager *)__this);
  __this->vtable = &ResourceManager_vtable;
  __this->ready = 0;
  __this->loadedFileLinkedList = NULL;
  __this->isFreeingAllResources = 0;
  strcpy(__this->resourceToLoad, "");
  __this->fileID = 0;
  for ( i = 0; i < NUM_AGG_FILES; ++i )
  {
    __this->fileDescriptors[i] = -1;
    __this->aggContentInfo[i] = NULL;
    __this->numberOfFilesInAGG[i] = 0;
  }
  __this->numOpenAGGFiles = 0;
  __this->curHandleIdx = 0;
  return __this;
}

unsigned int ResourceManager::setResource( const char * filename, int  useEvilersion)
{
  char evilMatches; // eax@5
  unsigned int result; // eax@8
  int i; // [sp+10h] [bp-8h]@3

  strcpy(this->resourceToLoad, filename);
  if (useEvilBorders && useEvilersion)
  {
    for ( i = 0; i < NUM_GOOD_EVIL_ICONS; ++i )
    {
      evilMatches = _strcmpi(this->resourceToLoad, goodEvilIcons[i][0]);
      if ( !evilMatches )
        strcpy(this->resourceToLoad, goodEvilIcons[i][1]);
    }
  }
  result = computeFileID(this->resourceToLoad);
  this->fileID = result;
  return result;
}

MANAGER_RETURN_CODE ResourceManager::addAGG( const char * filename)
{
  MANAGER_RETURN_CODE result; // eax@2
  int headerSize; // ST1C_4@5
  __int16 numFiles; // [sp+14h] [bp-8h]@5
  int fd; // [sp+18h] [bp-4h]@3

  if ( this->numOpenAGGFiles < NUM_AGG_FILES )
  {
    fd = __open(filename, O_BINARY);
    if ( fd == -1 )
    {
      sprintf(globBuf, "Can't open file: %s", filename);
      terminate(globBuf);
      result = MANAGER_FAILED;
    }
    else
    {
      this->curHandleIdx = this->numOpenAGGFiles++;
      this->fileDescriptors[this->curHandleIdx] = fd;
      __read(this->fileDescriptors[this->curHandleIdx], &numFiles, 2u);
      this->numberOfFilesInAGG[this->curHandleIdx] = numFiles;
      headerSize = 12 * this->numberOfFilesInAGG[this->curHandleIdx];
      this->aggContentInfo[this->curHandleIdx] = (FileInAGGInfo *)KBAlloc(
                                                                    headerSize,
                                                                    "F:\\h2xsrc\\Base\\RESMGR.CPP",
                                                                    542);
      __read(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx], headerSize);
      result = MANAGER_SUCCESS;
    }
  }
  else
  {
    sprintf(globBuf, "Only %d .AGG files can be used at once.", NUM_AGG_FILES);
    terminate(globBuf);
    result = MANAGER_FAILED;
  }
  return result;
}

void ResourceManager::dumpImageToScreen( const char * filename, Bitmap * screenBuf, int  isICN)
{
  Icon *icn; // ST20_4@2
  unsigned int bmpHash; // eax@3

  if ( isICN )
  {
    icn = this->getIconByFilename(filename);
    icn->drawToScreen(0, 0, 0, 0);
    this->reduceReferenceCountToResource((AbstractResource *)icn);
  }
  else
  {
    bmpHash = this->setResource(filename, 1);
    this->pointToFile(bmpHash);
	this->readShort();
    this->readShort();
    this->readShort();
    this->readFromCurrentFile(screenBuf->contents, screenBuf->width * screenBuf->height);
  }
}

AbstractResource * ResourceManager::findLoadedFile( unsigned int  fileHash)
{
  AbstractResource *cur; // [sp+10h] [bp-4h]@1

  for ( cur = this->loadedFileLinkedList; cur && cur->fileID != fileHash; cur = cur->next )
    ;
  return cur;
}

void ResourceManager::freeAllResources()
{
  AbstractResource *fil; // [sp+18h] [bp-8h]@1
  AbstractResource *next; // [sp+1Ch] [bp-4h]@3

  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil; fil = next )
  {
    next = fil->next;
    this->removeFileFromList(fil);
    if ( fil )
      fil->vtable->cleanUp(fil, 1);
  }
  this->isFreeingAllResources = 0;
}

Bitmap * ResourceManager::getBitmapByFilename( const char * filename)
{
  Bitmap *result; // eax@2
  Bitmap* newBitmapMem; // [sp+10h] [bp-Ch]@3
  Bitmap *loadedBmp; // [sp+14h] [bp-8h]@1
  Bitmap *newBitmap; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = this->setResource(filename, 1);
  loadedBmp = (Bitmap *)this->findLoadedFile(hash);
  if ( loadedBmp )
  {
    ++loadedBmp->referenceCount;
    result = loadedBmp;
  }
  else
  {
    newBitmapMem = (Bitmap*)operator new(sizeof(Bitmap));
    if ( newBitmapMem )
      newBitmap = Bitmap_constructorFromFile((Bitmap *)newBitmapMem, hash);
    else
      newBitmap = NULL;
    this->prependFileLinkedListNode((AbstractResource *)newBitmap);
    result = newBitmap;
  }
  return result;
}

int ResourceManager::getFileSize( int  fileHash)
{
  char found; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  int i; // [sp+18h] [bp-8h]@1
  int containingAGG; // [sp+1Ch] [bp-4h]@0

  found = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < NUM_AGG_FILES )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == fileHash )
          {
            found = 1;
            containingAGG = i;
            break;
          }
        }
      }
      if ( !found )
        continue;
    }
    break;
  }
  if ( !found )
  {
    sprintf(
      globBuf,
      "ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
      fileHash,
      this->fileID,
      this->resourceToLoad);
    terminate(globBuf);
  }
  return this->aggContentInfo[containingAGG][j].length;
}

Font * ResourceManager::getFontByFilename( const char * filename)
{
  Font *result; // eax@2
  Font* newFontMem; // [sp+10h] [bp-Ch]@3
  Font *loadedFont; // [sp+14h] [bp-8h]@1
  Font *newFont; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = this->setResource(filename, 1);
  loadedFont = (Font *)this->findLoadedFile(hash);
  if ( loadedFont )
  {
    ++loadedFont->referenceCount;
    result = loadedFont;
  }
  else
  {
    newFontMem = (Font*)operator new(sizeof(Font));
    if ( newFontMem )
      newFont = Font_constructor((Font *)newFontMem, hash);
    else
      newFont = 0;
    this->prependFileLinkedListNode((AbstractResource *)newFont);
    result = newFont;
  }
  return result;
}

Icon * ResourceManager::getIconByFileID( int  fileID)
{
  Icon *result; // eax@2
  Icon* newIconMem; // [sp+10h] [bp-8h]@3
  Icon *loadedIcon; // [sp+14h] [bp-4h]@1
  Icon *newIcon; // [sp+14h] [bp-4h]@4

  loadedIcon = (Icon *)this->findLoadedFile(fileID);
  if ( loadedIcon )
  {
    ++loadedIcon->referenceCount;
    result = loadedIcon;
  }
  else
  {
    newIconMem = (Icon*)operator new(sizeof(Icon));
    if ( newIconMem )
      newIcon = Icon_constructor((Icon *)newIconMem, fileID);
    else
      newIcon = 0;
    this->prependFileLinkedListNode((AbstractResource *)newIcon);
    result = newIcon;
  }
  return result;
}

Icon * ResourceManager::getIconByFilename( const char * filename)
{
  unsigned int hash; // eax@1

  hash = this->setResource(filename, 1);
  return this->getIconByFileID(hash);
}

Palette * ResourceManager::getPal( const char * file)
{
  Palette *result; // eax@2
  Palette *newPalMem; // [sp+10h] [bp-Ch]@3
  unsigned int fileID; // [sp+14h] [bp-8h]@1
  Palette *loadedPal; // [sp+18h] [bp-4h]@1
  Palette *newPal; // [sp+18h] [bp-4h]@4

  fileID = this->setResource(file, 1);
  loadedPal = (Palette *)this->findLoadedFile(fileID);
  if ( loadedPal )
  {
    ++loadedPal->referenceCount;
    result = loadedPal;
  }
  else
  {
    newPalMem = (Palette*)operator new(sizeof(Palette));
    if ( newPalMem )
      newPal = Palette_constructorFromFile((Palette *)newPalMem, fileID);
    else
      newPal = NULL;
    this->prependFileLinkedListNode((AbstractResource *)newPal);
    result = newPal;
  }
  return result;
}

Sample * ResourceManager::getSampleByFilename(char * filename)
{
  unsigned int hash; // ST28_4@1
  Sample *result; // eax@2
  Sample *newSampleMemory; // [sp+10h] [bp-Ch]@3
  Sample *loadedSample; // [sp+14h] [bp-8h]@1
  Sample *newSample; // [sp+14h] [bp-8h]@4

  hash = this->setResource(filename, 1);
  loadedSample = (Sample *)this->findLoadedFile(hash);
  if ( loadedSample )
  {
    ++loadedSample->referenceCount;
    result = loadedSample;
  }
  else
  {
    newSampleMemory = (Sample*)operator new(sizeof(Sample));
    if ( newSampleMemory )
      newSample = Sample_constructor((Sample *)newSampleMemory, filename, 0, 127, 1);
    else
      newSample = NULL;
    this->prependFileLinkedListNode((AbstractResource *)newSample);
    result = newSample;
  }
  return result;
}

Sequence * ResourceManager::getSequenceByFilename(char * filename)
{
  unsigned int hash; // ST20_4@1
  Sequence *result; // eax@2
  Sequence* newSeqMemory; // [sp+10h] [bp-Ch]@3
  Sequence *seq; // [sp+14h] [bp-8h]@1
  Sequence *newSeq; // [sp+14h] [bp-8h]@4

  hash = this->setResource(filename, 1);
  seq = (Sequence *)this->findLoadedFile(hash);
  if ( seq )
  {
    ++seq->referenceCount;
    result = seq;
  }
  else
  {
    newSeqMemory = (Sequence*)operator new(sizeof(Sequence));
    if ( newSeqMemory )
      newSeq = Sequence_constructor((Sequence *)newSeqMemory, filename);
    else
      newSeq = NULL;
    this->prependFileLinkedListNode((AbstractResource *)newSeq);
    result = newSeq;
  }
  return result;
}

Tileset * ResourceManager::getTilesetByFilename( char * filename)
{
  Tileset *result; // eax@2
  Tileset* newtilesMemory; // [sp+10h] [bp-Ch]@3
  unsigned int fileID; // [sp+14h] [bp-8h]@1
  Tileset *loadedTiles; // [sp+18h] [bp-4h]@1
  Tileset *newTiles; // [sp+18h] [bp-4h]@4

  fileID = this->setResource(filename, 1);
  loadedTiles = (Tileset *)this->findLoadedFile(fileID);
  if ( loadedTiles )
  {
    ++loadedTiles->referenceCount;
    result = loadedTiles;
  }
  else
  {
    newtilesMemory = (Tileset*)operator new(sizeof(Tileset));
    if ( newtilesMemory )
      newTiles = Tileset_constructor((Tileset *)newtilesMemory, fileID);
    else
      newTiles = NULL;
    this->prependFileLinkedListNode((AbstractResource *)newTiles);
    result = newTiles;
  }
  return result;
}

MANAGER_RETURN_CODE ResourceManager::handleInput( InputEvent * a1)
{
  return MANAGER_SUCCESS;
}

MANAGER_RETURN_CODE ResourceManager::initialize( int  idx)
{
  MANAGER_RETURN_CODE result; // eax@2

  if ( this->addAGG(".\\DATA\\ironfist.agg") )
  {
    result = MANAGER_FAILED;
  }
  else
  {
    if ( this->addAGG(heroes2xagg_path) )
    {
      result = MANAGER_FAILED;
    }
    else if(this->addAGG(heroes2agg_path)) {
		result = MANAGER_FAILED;
	}
	else
    {
      this->type = MANAGER_TYPE_RESOURCE_MAMANGER;
      this->idx = idx;
      this->ready = 1;
      strcpy(this->name, "resourceManager");
      this->loadedFileLinkedList = NULL;
      result = MANAGER_SUCCESS;
    }
  }
  return result;
}

signed int ResourceManager::pointToFile( int  id)
{
  char found; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  int i; // [sp+18h] [bp-8h]@1

  found = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < NUM_AGG_FILES )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == id )
          {
            found = 1;
            this->curHandleIdx = i;
            break;
          }
        }
      }
      if ( !found )
        continue;
    }
    break;
  }
  if ( !found )
  {
    sprintf(
      globBuf,
      "ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
      id,
      this->fileID,
      this->resourceToLoad);
    terminate(globBuf);
  }
  return __lseek(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx][j].off, SEEK_SET);
}

void ResourceManager::popFileAndOffsetOffStack()
{
  --indexOfFileOffsetStack;
  this->curHandleIdx = handleIndicesStack[indexOfFileOffsetStack];
  __lseek(this->fileDescriptors[this->curHandleIdx], fileOffsetStack[indexOfFileOffsetStack], SEEK_SET);
}

void ResourceManager::prependFileLinkedListNode( AbstractResource * res)
{
  if ( this->loadedFileLinkedList )
  {
    res->next = this->loadedFileLinkedList;
    this->loadedFileLinkedList = res;
  }
  else
  {
    this->loadedFileLinkedList = res;
    this->loadedFileLinkedList->next = NULL;
  }
}

void ResourceManager::pushCurrentFileAndOffsetOntoStack()
{
  fileOffsetStack[indexOfFileOffsetStack] = getFileOffset(this->fileDescriptors[this->curHandleIdx]);
  handleIndicesStack[indexOfFileOffsetStack++] = this->curHandleIdx;
}

void ResourceManager::readFromCurrentFile( void * buf, DWORD  ntoread)
{
  int err1; // ST28_4@2
  int *err2; // eax@2
  signed int nread; // [sp+18h] [bp-4h]@1

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 816);
  yieldToGlobalUpdater();
  nread = __read(this->fileDescriptors[this->curHandleIdx], buf, ntoread);
  if ( nread != ntoread )
  {
    err1 = *_errno();
    err2 = _errno();
    sprintf(
      globBuf,
      "File error - bytes read %d, bytes requested %d, errno %d, last file '%s'",
      nread,
      ntoread,
      *err2,
      this->resourceToLoad);
    debugLog(globBuf);
  }
  yieldToGlobalUpdater();
}

int ResourceManager::readInt()
{
  int err; // ST1C_4@2
  int buf; // [sp+18h] [bp-8h]@1
  int success; // [sp+1Ch] [bp-4h]@1

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 760);
  buf = 0;
  success = __read(this->fileDescriptors[this->curHandleIdx], &buf, 4u);
  if ( !success )
    err = *_errno();
  return buf;
}

void ResourceManager::readNexDOSFilename( char * buf)
{
  this->readFromCurrentFile(buf, MAX_FILENAME_LENGTH);
}

__int16 ResourceManager::readShort()
{
  __int16 buf; // [sp+18h] [bp-8h]@1

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 732);
  buf = 0;
  __read(this->fileDescriptors[this->curHandleIdx], &buf, 2u);
  return buf;
}

void ResourceManager::reduceReferenceCountToResource( AbstractResource * res)
{
  if ( !this->isFreeingAllResources )
  {
    if ( res )
    {
      --res->referenceCount;
      if ( res->referenceCount <= 0 )
      {
        this->removeFileFromList(res);
        if ( res )
          res->vtable->cleanUp(res, 1);
      }
    }
  }
}

void ResourceManager::removeFileFromList( AbstractResource * fil)
{
  AbstractResource *cur; // [sp+10h] [bp-4h]@3

  if ( this->loadedFileLinkedList == fil )
  {
    this->loadedFileLinkedList = fil->next;
  }
  else
  {
    for ( cur = this->loadedFileLinkedList; cur && cur->next != fil; cur = cur->next )
      ;
    if ( cur )
      cur->next = fil->next;
  }
}

#endif