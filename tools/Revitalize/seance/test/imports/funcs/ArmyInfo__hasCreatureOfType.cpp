{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    if ( this->creatureTypes[i] == creatureType )
      return 1;
  }
  return 0;
}
