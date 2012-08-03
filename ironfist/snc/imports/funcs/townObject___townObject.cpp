{
  BuildingDisplay *thisa; // [sp+Ch] [bp-Ch]@1
  widget *v2; // [sp+14h] [bp-4h]@2

  thisa = this;
  if ( this->guiElement )
  {
    v2 = (widget *)this->guiElement;
    if ( v2 )
      v2->vtable->cleanUp(v2, 1);
  }
  resourceManager::Dispose(gpResourceManager, (resource *)thisa->icon);
}