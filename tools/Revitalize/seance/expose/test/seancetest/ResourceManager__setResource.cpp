unsigned int __thiscall ResourceManager::setResource(ResourceManager *this, const char *filename, int useEvilersion)
{
  int evilMatches; // eax@5
  unsigned int result; // eax@8
  int i; // [sp+10h] [bp-8h]@3

  strcpy(this->resourceToLoad, filename);
  if ( useEvilBorders && useEvilersion )
  {
    for ( i = 0; i < NUM_GOOD_EVIL_ICONS; ++i )
    {
      LOBYTE(evilMatches) = _strcmpi(this->resourceToLoad, goodEvilIcons[i][0]);
      if ( !evilMatches )
        strcpy(this->resourceToLoad, goodEvilIcons[i][1]);
    }
  }
  result = computeFileID(this->resourceToLoad);
  this->fileID = result;
  return result;
}
