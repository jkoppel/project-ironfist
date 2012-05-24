{
  BackgroundGUI *thisa; // esi@1

  thisa = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, x, y, width, height, fieldID, a7);
  thisa->vtable = &BackgroundGUI_vtable;
  if ( filename )
    thisa->bitmap = ResourceManager::getBitmapByFilename(resourceManager, filename);
  else
    thisa->bitmap = 0;
  thisa->icon = 0;
  thisa->color = color;
  return thisa;
}
