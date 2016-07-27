{
  TextEntry *v1; // esi@1

  v1 = (TextEntry *)this;
  TextWidget_noArgConstructor((TextWidget *)this);
  v1->vtable = (int)&TextEntry_vtable;
  v1->field_31 = 0;
  v1->icon = 0;
  v1->field_14 = 16384;
  v1->fifthShort = 0;
  v1->field_2F = 0;
  v1->field_4B = 0;
  return v1;
}
