BackgroundGUI *__thiscall BackgroundGUI_constructor(BackgroundGUI *this, __int16 x, __int16 y, __int16 width, __int16 height, __int16 fieldID, __int16 a7, __int16 color, const char *filename)
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
