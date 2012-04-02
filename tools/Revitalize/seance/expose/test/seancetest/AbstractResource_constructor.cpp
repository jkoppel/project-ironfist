AbstractResource *__thiscall AbstractResource_constructor(AbstractResource *this, RESOURCE_TYPE type, int fileID, __int16 referenceCount, AbstractResource *next)
{
  this->resourceType = type;
  this->vtable = (ResourceVtable *)AbstractResource_vtable;
  this->referenceCount = referenceCount;
  this->fileID = fileID;
  this->next = next;
  return this;
}
