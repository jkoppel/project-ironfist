{
  heroWindowManager *thisa; // esi@1

  thisa = this;
  baseManager::baseManager((baseManager *)this);
  thisa->vtable = &heroWindowManager::_vftable_;
  thisa->ready = 0;
  thisa->nextTopmostWindow = 0;
  thisa->topmostWindow = 0;
  thisa->lastWindow = 0;
  thisa->firstWindow = 0;
  thisa->screenBuffer = 0;
  thisa->field_56 = 0;
  thisa->someBMP = 0;
  thisa->numScreenshots = 1;
  thisa->field_4E = 0;
  thisa->field_5E = -1;
  thisa->buttonPressedCode = -1;
  return thisa;
}