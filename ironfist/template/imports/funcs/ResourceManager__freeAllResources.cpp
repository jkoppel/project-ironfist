{
  AbstractResource *fil; // [sp+18h] [bp-8h]@1
  AbstractResource *next; // [sp+1Ch] [bp-4h]@3

  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil; fil = next )
  {
    next = fil->next;
    ResourceManager::removeFileFromList(this, fil);
    if ( fil )
      fil->vtable->cleanUp(fil, 1);
  }
  this->isFreeingAllResources = 0;
}
