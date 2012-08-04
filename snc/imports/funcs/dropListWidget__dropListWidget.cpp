{
  int v1; // esi@1
  int result; // eax@1

  v1 = this;
  widget::widget((widget *)this, 0, 0, 0, 0, 0, 0);
  *(_DWORD *)(v1 + 64) = 0;
  result = v1;
  *(_DWORD *)v1 = &dropListWidget::_vftable_;
  *(_DWORD *)(v1 + 176) = 0;
  *(_WORD *)(v1 + 60) = 0;
  *(_WORD *)(v1 + 62) = -1;
  return result;
}