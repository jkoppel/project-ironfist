signed int __thiscall CombatManager::spellWillAffectSomeone(CombatManager *this, Spell spellID)
{
  int hexIdx; // [sp+10h] [bp-4h]@1

  for ( hexIdx = 0; hexIdx < HEX_GRID_SIZE; ++hexIdx )
  {
    if ( hexIdx % 13 && hexIdx % 13 != 12 && CombatManager::spellWillAffectUnitIn(this, spellID, hexIdx) )
      return 1;
  }
  return 0;
}
