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
