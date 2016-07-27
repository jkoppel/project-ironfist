{
  int v3; // eax@3
  signed int i; // [sp+10h] [bp-8h]@1

  for ( i = 0; i < 5; ++i )
  {
    v3 = this->army.creatureTypes[i];
    if ( v3 == fromType )
    {
      LOBYTE(v3) = toType;
      this->army.creatureTypes[i] = toType;
    }
  }
  return v3;
}
