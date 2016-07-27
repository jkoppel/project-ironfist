{
  signed int stackIdx; // [sp+10h] [bp-8h]@12
  int idx; // [sp+14h] [bp-4h]@4
  int idxa; // [sp+14h] [bp-4h]@9

  if ( a1 && a2 )
  {
    for ( idx = 0; idx < 5; ++idx )
    {
      if ( ArmyInfo::hasCreatureOfType(a2, a1->creatureTypes[idx]) )
      {
        ArmyInfo::addCreatures(a2, a1->creatureTypes[idx], a1->quantities[idx], -1);
        ArmyInfo::deleteStack(a1, idx);
      }
    }
    for ( idxa = 0; idxa < 5; ++idxa )
    {
      if ( a1->creatureTypes[idxa] != -1 )
      {
        for ( stackIdx = 0; stackIdx < 5; ++stackIdx )
        {
          if ( a2->creatureTypes[stackIdx] == -1 )
          {
            ArmyInfo::addCreatures(a2, a1->creatureTypes[idxa], a1->quantities[idxa], stackIdx);
            ArmyInfo::deleteStack(a1, idxa);
          }
        }
      }
    }
  }
}
