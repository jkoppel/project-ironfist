signed int __thiscall Castle::hasGarrison(Castle *this)
{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    if ( this->garrison.creatureTypes[i] != -1 )
      return 1;
  }
  return 0;
}
