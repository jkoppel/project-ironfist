{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  while ( startHex <= 115 )
  {
    if ( combatManager::FindResurrectArmyIndex(thisa, thisa->currentActionSide, spell, startHex) != -1 )
    {
      *resultHex = startHex;
      return 0;
    }
    combatManager::NextPos(&startHex);
  }
  *resultHex = -1;
  return 1;
}