{
  SoundManager *this; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  this = ecx0;
  AbstractManager_constructor((AbstractManager *)ecx0);
  this->field_578 = 1;
  this->vtable = (ManagerVtable *)&SoundManager_vtable;
  this->ready = 0;
  this->volRelated = 0;
  this->field_570 = 0;
  for ( i = 0; i < 32; ++i )
    word_522B30[i] = 0;
  memset(this->_0, 0, 174u);
  this->field_688 = 0;
  this->hdidriver = 0;
  this->field_3E = 0;
  this->field_694 = 0;
  this->field_698 = 0;
  return this;
}
