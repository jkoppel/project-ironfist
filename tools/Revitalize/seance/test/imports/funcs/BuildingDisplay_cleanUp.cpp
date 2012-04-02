{
  BuildingDisplay *thisa; // [sp+Ch] [bp-Ch]@1
  AbstractGUIComponent *v2; // [sp+14h] [bp-4h]@2

  thisa = this;
  if ( this->guiElement )
  {
    v2 = (AbstractGUIComponent *)this->guiElement;
    if ( v2 )
      v2->vtable->cleanUp(v2, 1);
  }
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->icon);
}
