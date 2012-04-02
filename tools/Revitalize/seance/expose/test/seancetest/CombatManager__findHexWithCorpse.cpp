signed int __thiscall CombatManager::findHexWithCorpse(CombatManager *this, int startHex, int *resultHex, Spell spell)
{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  while ( startHex <= 115 )
  {
    if ( CombatManager::getCorpseStackIdx(thisa, thisa->currentActionSide, spell, startHex) != -1 )
    {
      *resultHex = startHex;
      return 0;
    }
    nextRealHexIdx(&startHex);
  }
  *resultHex = -1;
  return 1;
}
