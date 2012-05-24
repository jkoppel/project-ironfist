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
