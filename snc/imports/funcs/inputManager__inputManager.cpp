{
  inputManager *v1; // esi@1

  v1 = (inputManager *)this;
  baseManager::baseManager((baseManager *)this);
  v1->vtable = &inputManager::_vftable_;
  v1->ready = 0;
  v1->readingInputMutex = 0;
  v1->field_852 = 1;
  v1->field_84E = 0;
  v1->field_742 = 0;
  v1->field_746 = 0;
  v1->field_74A = 1;
  v1->normalizingKeycodeRelated = 1;
  v1->field_866 = 0;
  v1->field_862 = -1;
  return v1;
}