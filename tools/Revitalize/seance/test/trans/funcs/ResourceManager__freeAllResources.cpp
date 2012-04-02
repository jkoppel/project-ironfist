{
  ResourceManager *thisa; // [sp+Ch] [bp-14h]@1
  AbstractResource *fil; // [sp+18h] [bp-8h]@1
  AbstractResource *nextA; // [sp+1Ch] [bp-4h]@3

  thisa = this;
  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil; fil = nextA )
  {
    nextA = fil->next;
    ResourceManager::removeFileFromList(thisa, fil);
    if ( fil )
      fil->vtable->cleanUp(fil, 1);
  }
  thisa->isFreeingAllResources = 0;
}
