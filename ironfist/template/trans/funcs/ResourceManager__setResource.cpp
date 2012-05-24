{
  int evilMatches;
  unsigned int result;
  int i;

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
