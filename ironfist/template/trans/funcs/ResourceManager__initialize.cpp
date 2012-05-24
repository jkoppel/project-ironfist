{
  MANAGER_RETURN_CODE result;

  if ( this->addAGG(heroes2xagg_path) )
  {
    result = MANAGER_FAILED;
  }
  else
  {
    if ( this->addAGG(heroes2agg_path) )
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
  }
  return result;
}
