Bitmap *__thiscall ResourceManager::getBitmapByFilename(ResourceManager *this, const char *filename)
{
  Bitmap *result; // eax@2
  Bitmap *newBitmapMem; // [sp+10h] [bp-Ch]@3
  Bitmap *loadedBmp; // [sp+14h] [bp-8h]@1
  Bitmap *newBitmap; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = ResourceManager::setResource(this, filename, 1);
  loadedBmp = (Bitmap *)ResourceManager::findLoadedFile(this, hash);
  if ( loadedBmp )
  {
    ++loadedBmp->referenceCount;
    result = loadedBmp;
  }
  else
  {
    newBitmapMem = (Bitmap *)operator new(sizeof(Bitmap));
    if ( newBitmapMem )
      newBitmap = Bitmap_constructorFromFile(newBitmapMem, hash);
    else
      newBitmap = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)newBitmap);
    result = newBitmap;
  }
  return result;
}
