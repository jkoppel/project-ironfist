GUIIcon *__thiscall GUIIcon::cleanUp(GUIIcon *this, char a2)
{
  AbstractResource *v2; // eax@1
  GUIIcon *thisa; // esi@1

  v2 = (AbstractResource *)this->icon;
  this->vtable = &GUIIcon_vtable;
  thisa = this;
  ResourceManager::reduceReferenceCountToResource(resourceManager, v2);
  AbstractGUIComponent_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
