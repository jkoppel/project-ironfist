{
  signed int i; // [sp+14h] [bp-4h]@1
  int j; // [sp+14h] [bp-4h]@4

  for ( i = 0; i < 5; ++i )
  {
    this->armies[side]->creatureTypes[i] = -1;
    this->armies[side]->quantities[i] = 0;
  }
  for ( j = 0; this->numCreatures[side] > j; ++j )
  {
    if ( !(this->creatures[side][j].creature.creature_flags & DEAD)
      && this->creatures[side][j].quantity > 0
      && (this->playerID[side] == -1
       || this->creatures[side][j].creatureIdx != CREATURE_EARTH_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_AIR_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_FIRE_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_WATER_ELEMENTAL
       || !(HIBYTE(this->creatures[side][j].creature.creature_flags) & 8)) )
    {
      if ( !(HIBYTE(this->creatures[side][j].creature.creature_flags) & ATTR_MIRROR_IMAGE) )
      {
        this->armies[side]->creatureTypes[this->creatures[side][j].armyIdx] = LOBYTE(this->creatures[side][j].creatureIdx);
        this->armies[side]->quantities[this->creatures[side][j].armyIdx] = this->creatures[side][j].quantity;
      }
    }
  }
  if ( *(_DWORD *)&skeletonsToRaise && this->winningSide == side )
    ArmyInfo::addCreatures(this->armies[side], 47, skeletonsToRaise, -1);
}
