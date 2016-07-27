{
  InputManager *thisa; // ebx@1

  thisa = this;
  memset(this->inputInstances, 0, sizeof(this->inputInstances));
  this->currentInfoField = 0;
  this->currentInputEvt = 0;
  this->field_852 = a2;
  this->forSettingBitmask = 0;
  InputManager::setKeycodeRelatedThings(this);
  thisa->type = 4;
  thisa->idx = -1;
  thisa->ready = 1;
  strcpy(thisa->name, "inputManager");
  return 0;
}
