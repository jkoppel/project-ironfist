{
  bitmap *result; // eax@2
  bitmap *newBitmapMem; // [sp+10h] [bp-Ch]@3
  bitmap *loadedBmp; // [sp+14h] [bp-8h]@1
  bitmap *newBitmap; // [sp+14h] [bp-8h]@4
  unsigned int hash; // [sp+18h] [bp-4h]@1

  hash = resourceManager::MakeId(this, filename, 1);
  loadedBmp = (bitmap *)resourceManager::Query(this, hash);
  if ( loadedBmp )
  {
    ++loadedBmp->referenceCount;
    result = loadedBmp;
  }
  else
  {
    newBitmapMem = (bitmap *)operator new(sizeof(bitmap));
    if ( newBitmapMem )
      newBitmap = bitmap::bitmap(newBitmapMem, hash);
    else
      newBitmap = NULL;
    resourceManager::AddResource(this, (resource *)newBitmap);
    result = newBitmap;
  }
  return result;
}