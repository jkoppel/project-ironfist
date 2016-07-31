{
  void *v2; // ST2C_4@6
  MapTiles *thisa; // [sp+Ch] [bp-18h]@1
  int a2; // [sp+18h] [bp-Ch]@1
  int i; // [sp+1Ch] [bp-8h]@6

  thisa = this;
  for ( a2 = 1; this->field_10 > a2; ++a2 )
  {
    if ( *(_WORD *)(this->field_4 + 7 * a2) == 65535 )
    {
      sub_46F800(this, a2);
      return a2;
    }
  }
  v2 = operator new(7 * (this->field_10 + 100));
  memcpy(v2, (const void *)thisa->field_4, 7 * thisa->field_10);
  operator delete((void *)thisa->field_4);
  thisa->field_4 = (int)v2;
  for ( i = thisa->field_10; thisa->field_10 + 100 > i; ++i )
    *(_WORD *)(thisa->field_4 + 7 * i) = -1;
  thisa->field_10 += 100;
  sub_46F800(thisa, thisa->field_10 - 100);
  return thisa->field_10 - 100;
}
