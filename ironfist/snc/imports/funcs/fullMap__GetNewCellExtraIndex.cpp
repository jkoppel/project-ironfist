{
  void *v2; // ST2C_4@6
  int a2; // [sp+18h] [bp-Ch]@1
  int i; // [sp+1Ch] [bp-8h]@6

  for ( a2 = 1; this->field_10 > a2; ++a2 )
  {
    if ( *(_WORD *)(this->field_4 + 7 * a2) == 65535 )
    {
      fullMap::ClearCellExtra(this, a2);
      return a2;
    }
  }
  v2 = operator new(7 * (this->field_10 + 100));
  memcpy(v2, (const void *)this->field_4, 7 * this->field_10);
  operator delete((void *)this->field_4);
  this->field_4 = (int)v2;
  for ( i = this->field_10; this->field_10 + 100 > i; ++i )
    *(_WORD *)(this->field_4 + 7 * i) = -1;
  this->field_10 += 100;
  fullMap::ClearCellExtra(this, this->field_10 - 100);
  return this->field_10 - 100;
}