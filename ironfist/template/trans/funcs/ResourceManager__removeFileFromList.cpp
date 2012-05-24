{
  AbstractResource *cur;

  if ( this->loadedFileLinkedList == fil )
  {
    this->loadedFileLinkedList = fil->next;
  }
  else
  {
    for ( cur = this->loadedFileLinkedList; cur != NULL && cur->next != fil; cur = cur->next )
      ;
    if ( cur )
      cur->next = fil->next;
  }
}
