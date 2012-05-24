{
  AbstractResource *cur;

  for ( cur = this->loadedFileLinkedList; cur != NULL && cur->fileID != fileHash; cur = cur->next );
  return cur;
}
