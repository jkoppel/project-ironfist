{
  resource *icn; // eax@1

  icn = (resource *)this->icon;
  this->vtable = &tileset::_vftable_;
  resourceManager::Dispose(gpResourceManager, icn);
  widget::_widget(this);
  if ( a2 & 1 )
    operator delete(this);
}