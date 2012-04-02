{
  signed int v3; // [sp+14h] [bp-Ch]@1
  int i; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  v3 = 1;
  v5 = 0;
  for ( i = 0; this->numCreatures[side] > i; ++i )
  {
    if ( (CombatManager *)((char *)this + 24234 * side + 1154 * i) != (CombatManager *)-13647// &this[side][i] != 0. Likely meant to be this[side][i] != 0.
      && !(this->creatures[side][i].creature.creature_flags & DEAD) )
    {
      if ( this->creatures[side][i].quantity > 0 )
        v5 |= v3;
    }
    v3 *= 2;
  }
  return v5;
}
