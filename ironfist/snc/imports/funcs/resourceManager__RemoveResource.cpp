{
  resource *cur; // [sp+10h] [bp-4h]@3

  if ( this->loadedFileLinkedList == fil )
  {
    this->loadedFileLinkedList = fil->next;
  }
  else
  {
    for ( cur = this->loadedFileLinkedList; cur && cur->next != fil; cur = cur->next )
      ;
    if ( cur )
      cur->next = fil->next;
  }
}