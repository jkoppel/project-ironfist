{
  resource *fil; // [sp+18h] [bp-8h]@1
  resource *next; // [sp+1Ch] [bp-4h]@3

  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil; fil = next )
  {
    next = fil->next;
    resourceManager::RemoveResource(this, fil);
    if ( fil )
      fil->vtable->cleanUp(fil, 1);
  }
  this->isFreeingAllResources = 0;
}