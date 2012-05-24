Palette *__thiscall ResourceManager::getPal(ResourceManager *this, const char *filename)
{
  Palette *pal; // eax@2 MAPDST
  unsigned int fileID; // [sp+14h] [bp-8h]@1

  fileID = ResourceManager::setResource(this, filename, 1);
  pal = (Palette *)ResourceManager::findLoadedFile(this, fileID);
  if ( pal )
  {
    ++pal->referenceCount;
  }
  else
  {
    pal = (Palette *)operator new(sizeof(Palette));
    if ( pal )
      pal = Palette_constructorFromFile(pal, fileID);
    else
      pal = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)pal);
  }
  return pal;
}
