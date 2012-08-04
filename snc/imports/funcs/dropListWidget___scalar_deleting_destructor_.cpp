{
  int v2; // esi@1

  v2 = this;
  dropListWidget::_dropListWidget(this);
  if ( a2 & 1 )
    operator delete((void *)v2);
  return v2;
}