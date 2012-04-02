{
  signed int result; // eax@2
  ResourceManager *this; // [sp+Ch] [bp-4h]@1

  this = ecx0;
  if ( ResourceManager::addAGG(ecx0, heroes2xagg_path) )
  {
    result = 3;
  }
  else
  {
    if ( ResourceManager::addAGG(this, heroes2agg_path) )
    {
      result = 3;
    }
    else
    {
      this->type = 128;
      this->idx = idx;
      this->ready = 1;
      strcpy(this->name, "resourceManager");
      this->loadedFileLinkedList = 0;
      result = 0;
    }
  }
  return result;
}
