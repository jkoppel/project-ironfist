{
  unsigned int result; // eax@8
  ResourceManager *v4; // [sp+Ch] [bp-Ch]@1
  signed int i; // [sp+10h] [bp-8h]@3

  v4 = this;
  strcpy(this->resourceToLoad, filename);
  if ( useEvilBorders && useEvilersion )
  {
    for ( i = 0; i < 37; ++i )
    {
      if ( !_strcmpi(v4->resourceToLoad, goodEvilIcons[i][0]) )
        strcpy(v4->resourceToLoad, goodEvilIcons[i][1]);
    }
  }
  result = computeFileID(v4->resourceToLoad);
  v4->fileID = result;
  return result;
}
