AbstractResource *__thiscall ResourceManager::findLoadedFile(ResourceManager *this, unsigned int fileHash)
{
  AbstractResource *cur; // [sp+10h] [bp-4h]@1

  for ( cur = this->loadedFileLinkedList; cur && cur->fileID != fileHash; cur = cur->next )
    ;
  return cur;
}
