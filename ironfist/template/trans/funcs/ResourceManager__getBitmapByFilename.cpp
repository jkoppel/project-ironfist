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
