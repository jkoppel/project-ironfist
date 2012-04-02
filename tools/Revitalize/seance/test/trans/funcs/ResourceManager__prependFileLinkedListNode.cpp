{
  if ( this->loadedFileLinkedList )
  {
    res->next = this->loadedFileLinkedList;
    this->loadedFileLinkedList = res;
  }
  else
  {
    this->loadedFileLinkedList = res;
    this->loadedFileLinkedList->next = 0;
  }
}
