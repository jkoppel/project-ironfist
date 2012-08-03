{
  tileset *tiles; // eax@2 MAPDST
  unsigned int fileID; // [sp+14h] [bp-8h]@1

  fileID = resourceManager::MakeId(this, filename, 1);
  tiles = (tileset *)resourceManager::Query(this, fileID);
  if ( tiles )
  {
    ++tiles->referenceCount;
  }
  else
  {
    tiles = (tileset *)operator new(sizeof(tileset));
    if ( tiles )
      tiles = tileset::tileset(tiles, fileID);
    else
      tiles = NULL;
    resourceManager::AddResource(this, (resource *)tiles);
  }
  return tiles;
}