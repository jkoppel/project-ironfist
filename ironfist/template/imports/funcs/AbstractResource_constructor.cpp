{
  this->resourceType = type;
  this->vtable = (ResourceVtable *)AbstractResource_vtable;
  this->referenceCount = referenceCount;
  this->fileID = fileID;
  this->next = next;
  return this;
}
