signed int __thiscall ArmyInfo::hasUndead(ArmyInfo *this)
{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    if ( this->creatureTypes[i] != -1 && HIBYTE(creature_table[this->creatureTypes[i]].creature_flags) & ATTR_UNDEAD )
      return 1;
  }
  return 0;
}
