{
  int v3; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  v3 = 0;
  for ( i = 0; i < 20; ++i )
  {
    if ( this->creatures[side][i].creatureIdx != -1 )
    {
      if ( !(HIBYTE(this->creatures[side][i].creature.creature_flags) & 8) )
        v3 += creature_table[this->creatures[side][i].creatureIdx].hp
            * (this->creatures[side][i].initialQuantity - this->creatures[side][i].quantity);
    }
  }
  if ( this->heroes[side] )
    v3 += 500;
  return v3;
}
