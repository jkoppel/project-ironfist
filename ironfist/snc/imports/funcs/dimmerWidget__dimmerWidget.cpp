{
  int v1; // esi@1
  int result; // eax@1

  v1 = this;
  widget::widget((widget *)this, 0, 0, 0, 0, 0, 0);
  result = v1;
  *(_DWORD *)v1 = &dimmerWidget::_vftable_;
  return result;
}