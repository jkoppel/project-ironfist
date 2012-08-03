{
  townManager *thisa; // ST0C_4@1

  thisa = this;
  baseManager::baseManager((baseManager *)this);
  thisa->vtable = &townManager::_vftable_;
  thisa->castle = 0;
  thisa->curScreen = 0;
  thisa->field_C6 = 0;
  thisa->field_15E = -1;
  thisa->field_15A = 0;
  return thisa;
}