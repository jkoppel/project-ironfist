{
  MANAGER_RETURN_CODE result; // eax@2

  if ( resourceManager::LoadAggregateHeader(this, EXPANSION_AGGREGATE_NAME) )
  {
    result = MANAGER_FAILED;
  }
  else if ( resourceManager::LoadAggregateHeader(this, DEFAULT_AGGREGATE_NAME) )
  {
    result = MANAGER_FAILED;
  }
  else
  {
    this->type = MANAGER_TYPE_RESOURCE_MAMANGER;
    this->idx = idx;
    this->ready = 1;
    strcpy(this->name, "resourceManager");
    this->loadedFileLinkedList = NULL;
    result = MANAGER_SUCCESS;
  }
  return result;
}