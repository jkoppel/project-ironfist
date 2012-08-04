{
  palette *pal; // eax@2 MAPDST
  unsigned int fileID; // [sp+14h] [bp-8h]@1

  fileID = resourceManager::MakeId(this, filename, 1);
  pal = (palette *)resourceManager::Query(this, fileID);
  if ( pal )
  {
    ++pal->referenceCount;
  }
  else
  {
    pal = (palette *)operator new(sizeof(palette));
    if ( pal )
      pal = palette::palette(pal, fileID);
    else
      pal = NULL;
    resourceManager::AddResource(this, (resource *)pal);
  }
  return pal;
}