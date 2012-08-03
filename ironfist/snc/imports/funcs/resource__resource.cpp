{
  this->resourceType = type;
  this->vtable = (ResourceVtable *)resource::_vftable_;
  this->referenceCount = referenceCount;
  this->fileID = fileID;
  this->next = next;
  return this;
}