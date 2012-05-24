{
  Tileset *tiles; // eax@2 MAPDST
  unsigned int fileID; // [sp+14h] [bp-8h]@1

  fileID = ResourceManager::setResource(this, filename, 1);
  tiles = (Tileset *)ResourceManager::findLoadedFile(this, fileID);
  if ( tiles )
  {
    ++tiles->referenceCount;
  }
  else
  {
    tiles = (Tileset *)operator new(sizeof(Tileset));
    if ( tiles )
      tiles = Tileset_constructor(tiles, fileID);
    else
      tiles = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)tiles);
  }
  return tiles;
}
