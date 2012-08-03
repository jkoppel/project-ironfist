{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  while ( startHex <= 115 )
  {
    if ( thisa->combatGrid[startHex].unitOwner == side || side == 2 && thisa->combatGrid[startHex].unitOwner >= 0 )
    {
      *resultHex = startHex;
      return 0;
    }
    combatManager::NextPos(&startHex);
  }
  *resultHex = -1;
  return 1;
}