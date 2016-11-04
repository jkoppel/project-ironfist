
#ifndef RESMGR
#define RESMGR

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<winsock.h>
#include "resources.h"
#include "../import_thunk.cpp"
#include "../input.h"
#include "../import_val.h"

#define MAX_FILENAME_LENGTH 13


unsigned int ResourceManager::setResource( const char * filename, int  useEvilersion)
{
  int evilMatches;
  unsigned int result;
  int i;

  strcpy(this->resourceToLoad, filename);
  if ( useEvilBorders && useEvilersion )
  {
    for ( i = 0; i < NUM_GOOD_EVIL_ICONS; ++i )
    {
      LOBYTE(evilMatches) = _strcmpi(this->resourceToLoad, goodEvilIcons[i][0]);
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
  MANAGER_RETURN_CODE result;
  int headerSize;
  __int16 numFiles;
  int fd;

  if ( this->numOpenAGGFiles < NUM_AGG_FILES )
  {
    fd = _open(filename, O_BINARY);
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
      _read(this->fileDescriptors[this->curHandleIdx], &numFiles, 2u);
      this->numberOfFilesInAGG[this->curHandleIdx] = numFiles;
      headerSize = 12 * this->numberOfFilesInAGG[this->curHandleIdx];
      this->aggContentInfo[this->curHandleIdx] = (FileInAGGInfo *)KBAlloc(
                                                                    headerSize,
                                                                    "F:\\h2xsrc\\Base\\RESMGR.CPP",
                                                                    542);
      _read(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx], headerSize);
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
    Icon::drawToScreen(icn, 0, 0, 0, 0);
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
  AbstractResource *cur;

  for ( cur = this->loadedFileLinkedList; cur != NULL && cur->fileID != fileHash; cur = cur->next );
  return cur;
}

void ResourceManager::freeAllResources()
{
  AbstractResource *fil;
  AbstractResource *next;

  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil != NULL; fil = next )
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
  Bitmap *result;
  Bitmap *newBitmapMem;
  Bitmap *loadedBmp;
  Bitmap *newBitmap;
  unsigned int hash;

  hash = this->setResource( filename, 1);
  loadedBmp = (Bitmap *)this->findLoadedFile(hash);
  if ( loadedBmp )
  {
    ++loadedBmp->referenceCount;
    result = loadedBmp;
  }
  else
  {
    newBitmapMem = new Bitmap;
    if ( newBitmapMem )
      newBitmap = Bitmap_constructorFromFile(newBitmapMem, hash);
    else
      newBitmap = NULL;
    this->prependFileLinkedListNode(this, (AbstractResource *)newBitmap);
    result = newBitmap;
  }
  return result;
}

int ResourceManager::getFileSize( int  fileHash)
{
  char found;
  int j;
  RESOURCEMGR_CONSTANTS i;
  RESOURCEMGR_CONSTANTS containingAGG;

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
  Font *result;
  Font *newFontMem;
  Font *loadedFont;
  Font *newFont;
  unsigned int hash;

  hash = this->setResource(filename, 1);
  loadedFont = (Font *)this->findLoadedFile(hash);
  if ( loadedFont )
  {
    ++loadedFont->referenceCount;
    result = loadedFont;
  }
  else
  {
    newFontMem = new Font;
    if ( newFontMem )
      newFont = Font_constructor(newFontMem, hash);
    else
      newFont = 0;
    this->prependFileLinkedListNode((AbstractResource *)newFont);
    result = newFont;
  }
  return result;
}

Icon * ResourceManager::getIconByFileID( int  fileID)
{
  Icon *icon;

  icon = (Icon *)this->findLoadedFile(fileID);
  if ( icon )
  {
    ++icon->referenceCount;
  }
  else
  {
    icon = new Icon;
    if ( icon )
      icon = Icon_constructor(icon, fileID);
    else
      icon = NULL;
    this->prependFileLinkedListNode((AbstractResource *)icon);
  }
  return icon;
}

Icon * ResourceManager::getIconByFilename( const char * filename)
{
  unsigned int hash;

  hash = this->setResource(filename, 1);
  return this->getIconByFileID(hash);
}

Palette * ResourceManager::getPal( const char * filename)
{
  Palette *pal;
  unsigned int fileID;

  fileID = this->setResource(filename, 1);
  pal = (Palette *)this->findLoadedFile(fileID);
  if ( pal )
  {
    ++pal->referenceCount;
  }
  else
  {
    pal = new Palette;
    if ( pal )
      pal = Palette_constructorFromFile(pal, fileID);
    else
      pal = NULL;
    this->prependFileLinkedListNode((AbstractResource *)pal);
  }
  return pal;
}

Sample * ResourceManager::getSampleByFilename( const char * filename)
{
  unsigned int hash;
  Sample *sample;

  hash = this->setResource(filename, 1);
  sample = (Sample *)this->findLoadedFile(hash);
  if ( sample )
  {
    ++sample->referenceCount;
  }
  else
  {
    sample = new Sample;
    if ( sample )
      sample = Sample_constructor(sample, filename, 0, 127, 1);
    else
      sample = NULL;
    this->prependFileLinkedListNode((AbstractResource *)sample);
  }
  return sample;
}

Sequence * ResourceManager::getSequenceByFilename( const char * filename)
{
  unsigned int hash;
  Sequence *sequence;

  hash = this->setResource(filename, 1);
  sequence = (Sequence *)this->findLoadedFile(hash);
  if ( sequence )
  {
    ++sequence->referenceCount;
  }
  else
  {
    sequence = new Sequence;
    if ( sequence )
      sequence = Sequence_constructor(sequence, filename);
    else
      sequence = NULL;
    this->prependFileLinkedListNode((AbstractResource *)sequence);
  }
  return sequence;
}

Tileset * ResourceManager::getTilesetByFilename( const char * filename)
{
  Tileset *tiles;
  unsigned int fileID;

  fileID = this->setResource(filename, 1);
  tiles = (Tileset *)this->findLoadedFile(fileID);
  if ( tiles )
  {
    ++tiles->referenceCount;
  }
  else
  {
    tiles = new Tileset;
    if ( tiles )
      tiles = Tileset_constructor(tiles, fileID);
    else
      tiles = NULL;
    this->prependFileLinkedListNode((AbstractResource *)tiles);
  }
  return tiles;
}

MANAGER_RETURN_CODE ResourceManager::handleInput( InputEvent * a1)
{
  return MANAGER_SUCCESS;
}

MANAGER_RETURN_CODE ResourceManager::initialize( int  idx)
{
  MANAGER_RETURN_CODE result;

  if ( this->addAGG(heroes2xagg_path) )
  {
    result = MANAGER_FAILED;
  }
  else
  {
    if ( this->addAGG(heroes2agg_path) )
    {
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
  char found;
  int j;
  int i;

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
  return _lseek(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx][j].off, SEEK_SET);
}

void ResourceManager::popFileAndOffsetOffStack()
{
  --indexOfFileOffsetStack;
  this->curHandleIdx = handleIndicesStack[indexOfFileOffsetStack];
  _lseek(this->fileDescriptors[this->curHandleIdx], fileOffsetStack[indexOfFileOffsetStack], SEEK_SET);
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
  int err1;
  int *err2;
  signed int nread;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 816);
  yieldToGlobalUpdater();
  nread = _read(this->fileDescriptors[this->curHandleIdx], buf, ntoread);
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
  int err;
  int buf;
  int success;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 760);
  buf = 0;
  success = _read(this->fileDescriptors[this->curHandleIdx], &buf, sizeof(int));
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
  int err;
  __int16 buf;
  int success;

  assertTrue(this->fileDescriptors[this->curHandleIdx] != -1, "F:\\h2xsrc\\Base\\RESMGR.CPP", 732);
  buf = 0;
  success = _read(this->fileDescriptors[this->curHandleIdx], &buf, sizeof(short));
  if ( !success )
    err = *_errno();
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
  AbstractResource *cur;

  if ( this->loadedFileLinkedList == fil )
  {
    this->loadedFileLinkedList = fil->next;
  }
  else
  {
    for ( cur = this->loadedFileLinkedList; cur != NULL && cur->next != fil; cur = cur->next )
      ;
    if ( cur )
      cur->next = fil->next;
  }
}

#endif
