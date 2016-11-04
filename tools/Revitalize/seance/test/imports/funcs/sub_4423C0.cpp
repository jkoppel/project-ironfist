{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( *(_DWORD *)&showCombatGrid != a2 || *(_DWORD *)&showCombatMouseHex != a3 || combatShadeLevel != a4 )
  {
    sub_4C4960(this, -1, 0);
    *(_DWORD *)&showCombatGrid = a2;
    *(_DWORD *)&showCombatMouseHex = a3;
    combatShadeLevel = a4;
    thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
    sub_4C3DD0(thisa, &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx]);
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
    sub_440ED0(thisa);
    propagateSettingChanges();
  }
}
