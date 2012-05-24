{
  signed int result; // eax@2
  ArmyInfo *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( ArmyInfo::hasCreatureOfType(this, creatureType) )
  {
    result = 1;
  }
  else
  {
    if ( ArmyInfo::hasCreatureOfType(thisa, -1) )
      result = 1;
    else
      result = 0;
  }
  return result;
}
