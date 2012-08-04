{
  bool result; // eax@2
  armyGroup *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( armyGroup::IsMember(this, creatureType) )
    result = 1;
  else
    result = armyGroup::IsMember(thisa, -1) != 0;
  return result;
}