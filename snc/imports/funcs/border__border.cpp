{
  border *thisa; // esi@1

  thisa = this;
  widget::widget((widget *)this, x, y, width, height, fieldID, a7);
  thisa->vtable = &border::_vftable_;
  if ( filename )
    thisa->bitmap = resourceManager::GetBitmap(gpResourceManager, filename);
  else
    thisa->bitmap = 0;
  thisa->icon = 0;
  thisa->color = color;
  return thisa;
}