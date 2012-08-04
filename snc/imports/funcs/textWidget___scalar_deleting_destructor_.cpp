{
  font *font; // eax@1
  textWidget *thisa; // esi@1

  font = this->font;
  this->vtable = &textWidget::_vftable_;
  thisa = this;
  resourceManager::Dispose(gpResourceManager, (resource *)font);
  BaseFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 85);
  widget::_widget(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}