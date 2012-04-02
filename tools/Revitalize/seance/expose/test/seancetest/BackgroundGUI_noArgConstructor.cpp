BackgroundGUI *__thiscall BackgroundGUI_noArgConstructor(BackgroundGUI *this)
{
  BackgroundGUI *v1; // esi@1
  BackgroundGUI *result; // eax@1

  v1 = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, 0, 0, 0, 0, 0, 0);
  result = v1;
  v1->vtable = &BackgroundGUI_vtable;
  v1->bitmap = 0;
  v1->icon = 0;
  v1->color = 0;
  return result;
}
