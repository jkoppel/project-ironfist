__int32 __thiscall ResourceManager::pointToFile(ResourceManager *this, int id)
{
  ResourceManager *thisa; // [sp+Ch] [bp-14h]@1
  char v4; // [sp+10h] [bp-10h]@1
  int j; // [sp+14h] [bp-Ch]@0
  int i; // [sp+18h] [bp-8h]@1

  thisa = this;
  v4 = 0;
  for ( i = 0; ; ++i )
  {
    if ( i < SEEK_END )
    {
      if ( this->aggContentInfo[i] )
      {
        for ( j = 0; this->numberOfFilesInAGG[i] > j; ++j )
        {
          if ( this->aggContentInfo[i][j].id == id )
          {
            v4 = 1;
            this->curHandleIdx = i;
            break;
          }
        }
      }
      if ( !v4 )
        continue;
    }
    break;
  }
  if ( !v4 )
  {
    sprintf(
      globBuf,
      "ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
      id,
      this->fileID,
      this->resourceToLoad);
    terminate(globBuf);
  }
  return _lseek(
           thisa->fileDescriptors[thisa->curHandleIdx],
           thisa->aggContentInfo[thisa->curHandleIdx][j].off,
           SEEK_SET);
}
