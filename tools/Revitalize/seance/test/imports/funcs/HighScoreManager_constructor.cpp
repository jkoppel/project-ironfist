{
  AbstractManager *this; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  this = ecx0;
  AbstractManager_constructor(ecx0);
  this->vtable = &HighScoreManager_vtable;
  for ( i = 0; i < 10; ++i )
    *((_WORD *)&this[1].vtable + i) = unseededNextRand(0, 17);
  this[1].name[20] = 0;
  return this;
}
