{
  textWidget *thisa; // esi@1
  font *font; // eax@1

  thisa = this;
  widget::widget((widget *)this, offsetX, offsetY, width, height, fieldID, a7);
  thisa->vtable = &textWidget::_vftable_;
  font = resourceManager::GetFont(gpResourceManager, fontName);
  thisa->field_28 = a8;
  thisa->font = font;
  thisa->field_2A = a11;
  thisa->field_14 = 512;
  thisa->content = content;
  return thisa;
}