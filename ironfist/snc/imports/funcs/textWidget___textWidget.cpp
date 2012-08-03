{
  resource *fnt; // eax@1
  textWidget *thisa; // esi@1

  fnt = (resource *)this->font;
  this->vtable = &textWidget::_vftable_;
  thisa = this;
  resourceManager::Dispose(gpResourceManager, fnt);
  BaseFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 85);
  widget::_widget(thisa);
}