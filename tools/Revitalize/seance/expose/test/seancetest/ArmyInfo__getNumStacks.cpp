int __thiscall ArmyInfo::getNumStacks(ArmyInfo *this)
{
  signed int i; // [sp+10h] [bp-8h]@1
  int numStacks; // [sp+14h] [bp-4h]@1

  numStacks = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( this->creatureTypes[i] != -1 )
      ++numStacks;
  }
  return numStacks;
}
