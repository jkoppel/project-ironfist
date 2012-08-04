{
  int result; // eax@3
  signed int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    result = this->army.creatureTypes[i];
    if ( result != -1 )
    {
      result = this->army.creatureTypes[i];
      if ( result >= 0 )
        result = this->army.creatureTypes[i];
    }
  }
  return result;
}