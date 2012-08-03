{
  resource *v2; // eax@1
  border *thisa; // esi@1

  v2 = (resource *)this->bitmap;
  this->vtable = &border::_vftable_;
  thisa = this;
  if ( v2 )
    resourceManager::Dispose(gpResourceManager, v2);
  if ( thisa->icon )
    resourceManager::Dispose(gpResourceManager, (resource *)thisa->icon);
  widget::_widget(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}