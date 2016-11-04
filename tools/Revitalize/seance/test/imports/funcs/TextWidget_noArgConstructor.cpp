{
  TextWidget *thisa; // edi@1

  thisa = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, 0, 0, 0, 0, 0, 0);
  thisa->vtable = &TextWidget_vtable;
  thisa->field_28 = 1;
  thisa->field_2A = 1;
  thisa->font = 0;
  thisa->content = 0;
  thisa->field_14 = 512;
  return thisa;
}
