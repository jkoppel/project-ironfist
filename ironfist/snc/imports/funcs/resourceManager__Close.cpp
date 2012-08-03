{
  int i; // [sp+10h] [bp-4h]@2

  if ( this->ready == 1 )
  {
    resourceManager::Expunge(this);
    this->loadedFileLinkedList = 0;
    for ( i = 0; i < NUM_AGG_FILES; ++i )
    {
      if ( this->aggContentInfo[i] )
        BaseFree(this->aggContentInfo[i], (int)"F:\\h2xsrc\\Base\\RESMGR.CPP", 474);
      if ( this->fileDescriptors[i] != -1 )
      {
        _close(this->fileDescriptors[i]);
        this->fileDescriptors[i] = -1;
      }
    }
    this->numOpenAGGFiles = 0;
    this->ready = 0;
  }
}