{
  signed int i; // [sp+10h] [bp-8h]@1
  int numOfType; // [sp+14h] [bp-4h]@1

  numOfType = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( this->army.creatureTypes[i] == type )
    {
      if ( this->army.quantities[i] > 0 )
        ++numOfType;
    }
  }
  return numOfType;
}
