{
  signed int i; // [sp+10h] [bp-8h]@1
  int v5; // [sp+14h] [bp-4h]@1

  v5 = 0;
  for ( i = 0; i < 144; ++i )
  {
    if ( this->_8[7 * i + 1] == a2 )
    {
      if ( this->_8[7 * i + 2] == a3 )
        ++v5;
    }
  }
  return v5;
}
