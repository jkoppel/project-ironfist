{
  listBox *v1; // esi@1

  v1 = this;
  widget::widget((widget *)this, 0, 0, 0, 0, 0, 0);
  v1->vtable = (int)&listBoxWidget::_vftable_;
  *(_DWORD *)&v1->field_3C = 0;
  *(_DWORD *)&v1->field_72[14] = 0;
  v1->field_32 = 0;
  v1->field_34 = -1;
  v1->field_36 = -1;
  return v1;
}