{
  signed int v3; // [sp+14h] [bp-Ch]@1
  int i; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  v3 = 1;
  v5 = 0;
  for ( i = 0; this->numCreatures[a2] > i; ++i )
  {
    if ( (combatManager *)((char *)this + 24234 * a2 + 1154 * i) != (combatManager *)-13647
      && !(this->creatures[a2][i].creature.creature_flags & 0x10) )
    {
      if ( HIBYTE(this->creatures[a2][i].creature.creature_flags) & 1 )
        v5 |= v3;
    }
    v3 *= 2;
  }
  return v5;
}