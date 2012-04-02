{
  AbstractResource *icn; // eax@1

  icn = (AbstractResource *)this->icon;
  this->vtable = &Button_vtable;
  ResourceManager::reduceReferenceCountToResource(resourceManager, icn);
  AbstractGUIComponent_destructor(this);
  if ( a2 & 1 )
    operator delete(this);
}
