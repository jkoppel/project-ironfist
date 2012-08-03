{
  int icn; // eax@1
  textEntryWidget *thisa; // esi@1

  icn = this->icon;
  this->vtable = (int)&textEntryWidget::_vftable_;
  thisa = this;
  resourceManager::Dispose(gpResourceManager, (resource *)icn);
  textWidget::_textWidget((textWidget *)thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}