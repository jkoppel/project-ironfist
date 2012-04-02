void __thiscall ResourceManager::prependFileLinkedListNode(ResourceManager *this, AbstractResource *res)
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
