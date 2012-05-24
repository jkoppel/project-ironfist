{
  char found; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  RESOURCEMGR_CONSTANTS i; // [sp+18h] [bp-8h]@1
  RESOURCEMGR_CONSTANTS containingAGG; // [sp+1Ch] [bp-4h]@0

  found = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < NUM_AGG_FILES )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == fileHash )
          {
            found = 1;
            containingAGG = i;
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
      globBuf,
      "ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
      fileHash,
      this->fileID,
      this->resourceToLoad);
    terminate(globBuf);
  }
  return this->aggContentInfo[containingAGG][j].length;
}
