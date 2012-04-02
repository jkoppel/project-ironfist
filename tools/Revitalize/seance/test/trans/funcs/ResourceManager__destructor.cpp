{
  ResourceManager *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@2

  thisa = this;
  if ( this->ready == 1 )
  {
    ResourceManager::freeAllResources(this);
    thisa->loadedFileLinkedList = 0;
    for ( i = 0; i < 2; ++i )
    {
      if ( thisa->aggContentInfo[i] )
        KBFree(thisa->aggContentInfo[i], (int)"F:\\h2xsrc\\Base\\RESMGR.CPP", 474);
      if ( thisa->fileDescriptors[i] != -1 )
      {
        _close(thisa->fileDescriptors[i]);
        thisa->fileDescriptors[i] = -1;
      }
    }
    thisa->numOpenAGGFiles = 0;
    thisa->ready = 0;
  }
}
