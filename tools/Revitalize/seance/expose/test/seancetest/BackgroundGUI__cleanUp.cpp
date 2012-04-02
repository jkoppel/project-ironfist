BackgroundGUI *__thiscall BackgroundGUI::cleanUp(BackgroundGUI *this, char a2)
{
  AbstractResource *v2; // eax@1
  BackgroundGUI *thisa; // esi@1

  v2 = (AbstractResource *)this->bitmap;
  this->vtable = &BackgroundGUI_vtable;
  thisa = this;
  if ( v2 )
    ResourceManager::reduceReferenceCountToResource(resourceManager, v2);
  if ( thisa->icon )
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->icon);
  AbstractGUIComponent_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
