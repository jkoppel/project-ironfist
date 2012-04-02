{
  AbstractResource *i; // [sp+10h] [bp-4h]@1

  for ( i = this->loadedFileLinkedList; i && i->fileID != fileID; i = i->next )
    ;
  return i;
}
