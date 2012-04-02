signed int __thiscall ArmyInfo::addCreatures(ArmyInfo *this, int creatureType, __int16 quantity, signed int stackIdx)
{
  signed int result; // eax@16
  signed int i; // [sp+10h] [bp-4h]@2
  signed int j; // [sp+10h] [bp-4h]@8

  if ( stackIdx == -1 )
  {
    for ( i = 0; i < 5; ++i )
    {
      if ( this->creatureTypes[i] == creatureType )
      {
        stackIdx = i;
        break;
      }
    }
  }
  if ( stackIdx == -1 )
  {
    for ( j = 0; j < 5; ++j )
    {
      if ( this->creatureTypes[j] == -1 || this->creatureTypes[j] == creatureType )
      {
        stackIdx = j;
        break;
      }
    }
  }
  if ( stackIdx < 5 && stackIdx >= 0 )
  {
    this->creatureTypes[stackIdx] = creatureType;
    if ( this->quantities[stackIdx] < 0 )
      this->quantities[stackIdx] = 0;
    this->quantities[stackIdx] += quantity;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
