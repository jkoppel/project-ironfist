{
  char found; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  int i; // [sp+18h] [bp-8h]@1

  found = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < NUM_AGG_FILES )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == id )
          {
            found = 1;
            this->curHandleIdx = i;
            break;
          }
        }
      }
      if ( !found )
        continue;
    }
    break;
  }
  if ( !found )
  {
    sprintf(
      gText,
      "ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
      id,
      this->fileID,
      this->resourceToLoad);
    ShutDown(gText);
  }
  return _lseek(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx][j].off, SEEK_SET);
}