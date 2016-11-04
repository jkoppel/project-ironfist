{
  TextWidget *thisa; // esi@1
  Font *font; // eax@1

  thisa = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, offsetX, offsetY, width, height, fieldID, a7);
  thisa->vtable = &TextWidget_vtable;
  font = ResourceManager::getFontByFilename(resourceManager, fontName);
  thisa->field_28 = a8;
  thisa->font = font;
  thisa->field_2A = a11;
  thisa->field_14 = 512;
  thisa->content = content;
  return thisa;
}
