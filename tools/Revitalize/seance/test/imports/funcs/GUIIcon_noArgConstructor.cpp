{
  GUIIcon *v1; // esi@1
  GUIIcon *result; // eax@1

  v1 = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, 0, 0, 0, 0, 0, 0);
  v1->imgIdx = 0;
  v1->vtable = &GUIIcon_vtable;
  v1->field_27 = 0;
  result = v1;
  v1->icon = 0;
  v1->mirror = 0;
  v1->iconFileID = 0;
  return result;
}
