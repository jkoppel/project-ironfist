{
  resource *v2; // eax@1
  iconWidget *thisa; // esi@1

  v2 = (resource *)this->icon;
  this->vtable = &iconWidget::_vftable_;
  thisa = this;
  resourceManager::Dispose(gpResourceManager, v2);
  widget::_widget(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}