ResourceManager *__thiscall ResourceManager_constructor(ResourceManager *this)
{
  int i; // [sp+10h] [bp-4h]@1

  AbstractManager_constructor((AbstractManager *)this);
  this->vtable = &ResourceManager_vtable;
  this->ready = 0;
  this->loadedFileLinkedList = NULL;
  this->isFreeingAllResources = 0;
  strcpy(this->resourceToLoad, unk_51F1F8);
  this->fileID = 0;
  for ( i = 0; i < NUM_AGG_FILES; ++i )
  {
    this->fileDescriptors[i] = -1;
    this->aggContentInfo[i] = NULL;
    this->numberOfFilesInAGG[i] = 0;
  }
  this->numOpenAGGFiles = 0;
  this->curHandleIdx = 0;
  return this;
}
