{
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  int hexIdx; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( hexIdx = 0; hexIdx < HEX_GRID_SIZE; ++hexIdx )
  {
    if ( hexIdx % 13 && hexIdx % 13 != 12 && CombatManager::spellWillAffectUnitIn(thisa, spellID, hexIdx) )
      return 1;
  }
  return 0;
}
