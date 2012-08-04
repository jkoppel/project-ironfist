{
  iconWidget *thisa; // edi@1
  int v12; // eax@1
  iconWidget *result; // eax@1

  thisa = this;
  widget::widget((widget *)this, x, y, width, height, fieldID, a10);
  thisa->vtable = &iconWidget::_vftable_;
  v12 = resourceManager::MakeId(gpResourceManager, filename, 1);
  thisa->iconFileID = v12;
  thisa->icon = resourceManager::GetIcon(gpResourceManager, v12);
  thisa->imgIdx = imgIdx;
  thisa->mirror = mirror;
  thisa->field_27 = a11;
  result = thisa;
  thisa->field_14 = a10;
  return result;
}