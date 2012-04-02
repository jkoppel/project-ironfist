signed int __thiscall CombatManager::findCreature(CombatManager *this, int startHex, int side, int *resultHex)
{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  while ( startHex <= 115 )
  {
    if ( thisa->combatGrid[startHex].unitOwner == side || side == 2 && thisa->combatGrid[startHex].unitOwner >= 0 )
    {
      *resultHex = startHex;
      return 0;
    }
    nextRealHexIdx(&startHex);
  }
  *resultHex = -1;
  return 1;
}
