{
  this->next = 0;
  this->prev = 0;
  this->vtable = &AbstractManager_vtable;
  this->idx = -1;
  this->type = -1;
  this->ready = 0;
  strcpy(this->name, "Unknown");
  return this;
}
