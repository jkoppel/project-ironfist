{
  ResourceManager *thisa; // [sp+Ch] [bp-14h]@1
  char found; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  signed int i; // [sp+18h] [bp-8h]@1
  signed int containingAGG; // [sp+1Ch] [bp-4h]@0

  thisa = this;
  found = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < 2 )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == fileID )
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
      fileID,
      this->fileID,
      this->resourceToLoad);
    terminate(globBuf);
  }
  return thisa->aggContentInfo[containingAGG][j].length;
}
