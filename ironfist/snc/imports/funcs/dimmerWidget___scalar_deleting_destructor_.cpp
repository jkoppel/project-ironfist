{
  void *v2; // esi@1

  *(_DWORD *)this = &dimmerWidget::_vftable_;
  v2 = this;
  widget::_widget(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}