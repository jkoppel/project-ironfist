{
  baseManager *this; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  this = ecx0;
  baseManager::baseManager(ecx0);
  this->vtable = &highScoreManager::_vftable_;
  for ( i = 0; i < 10; ++i )
    *((_WORD *)&this[1].vtable + i) = Random(0, 17);
  this[1].name[20] = 0;
  return this;
}