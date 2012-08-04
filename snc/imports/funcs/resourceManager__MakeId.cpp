{
  int evilMatches; // eax@5
  unsigned int result; // eax@8
  int i; // [sp+10h] [bp-8h]@3

  strcpy(this->resourceToLoad, filename);
  if ( gbUseEvilInterface && useEvilersion )
  {
    for ( i = 0; i < NUM_GOOD_EVIL_ICONS; ++i )
    {
      LOBYTE(evilMatches) = stricmp(this->resourceToLoad, cEvilTranslate[i][0]);
      if ( !evilMatches )
        strcpy(this->resourceToLoad, cEvilTranslate[i][1]);
    }
  }
  result = MAKEFILEID(this->resourceToLoad);
  this->fileID = result;
  return result;
}