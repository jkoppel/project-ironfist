Bitmap *__thiscall ResourceManager::getBitmapByFilename(ResourceManager *this, const char *filename)
{
  Bitmap *result; // eax@2
  Bitmap *thisb; // [sp+10h] [bp-Ch]@3
  AbstractResource *fileNode; // [sp+14h] [bp-8h]@1
  Bitmap *fileNodea; // [sp+14h] [bp-8h]@4
  int fileID; // [sp+18h] [bp-4h]@1

  fileID = ResourceManager::setResource(this, filename, 1);
  fileNode = ResourceManager::findLoadedFile(this, fileID);
  if ( fileNode )
  {
    ++fileNode->referenceCount;
    result = (Bitmap *)fileNode;
  }
  else
  {
    thisb = (Bitmap *)operator new(0x1Au);
    if ( thisb )
      fileNodea = Bitmap_constructorFromFile(thisb, fileID);
    else
      fileNodea = 0;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)fileNodea);
    result = fileNodea;
  }
  return result;
}
