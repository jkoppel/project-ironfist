{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    if ( this->creatureTypes[i] != -1
      && !(HIBYTE(gMonsterDatabase[this->creatureTypes[i]].creature_flags) & ATTR_UNDEAD) )
      return 0;
  }
  return 1;
}