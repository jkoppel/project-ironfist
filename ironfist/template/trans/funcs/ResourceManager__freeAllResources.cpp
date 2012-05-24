{
  AbstractResource *fil;
  AbstractResource *next;

  this->isFreeingAllResources = 1;
  for ( fil = this->loadedFileLinkedList; fil != NULL; fil = next )
  {
    next = fil->next;
    this->removeFileFromList(fil);
    if ( fil )
      fil->vtable->cleanUp(fil, 1);
  }
  this->isFreeingAllResources = 0;
}
