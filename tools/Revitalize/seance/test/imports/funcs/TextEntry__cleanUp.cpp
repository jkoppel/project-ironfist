{
  int icn; // eax@1
  TextEntry *thisa; // esi@1

  icn = this->icon;
  this->vtable = (int)&TextEntry_vtable;
  thisa = this;
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)icn);
  TextWidget_destructor((TextWidget *)thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
