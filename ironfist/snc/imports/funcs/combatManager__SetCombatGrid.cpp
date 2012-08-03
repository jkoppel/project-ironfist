{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( *(_DWORD *)&showCombatGrid != a2 || *(_DWORD *)&showCombatMouseHex != a3 || combatShadeLevel != a4 )
  {
    combatManager::UpdateMouseGrid(this, -1, 0);
    *(_DWORD *)&showCombatGrid = a2;
    *(_DWORD *)&showCombatMouseHex = a3;
    combatShadeLevel = a4;
    thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
    combatManager::SetupGridForArmy(thisa, &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx]);
    combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
    combatManager::ResetMouse(thisa);
    WritePrefs();
  }
}