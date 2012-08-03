{
  combatManager *thisa; // [sp+Ch] [bp-8h]@1
  int a3; // [sp+10h] [bp-4h]@1

  thisa = this;
  a3 = combatManager::AICheckRetreat((int)this);
  if ( *(&thisa->field_353F + thisa->currentActionSide)
    || thisa->playerID[thisa->currentActionSide] != -1
    && *(&gbThisNetHumanPlayer + thisa->playerID[thisa->currentActionSide])
    && !*(_DWORD *)&autoCombatUseSpells
    || !combatManager::DoSpellAI(thisa, thisa->currentActionSide, a3) )
  {
    if ( combatManager::AICheckRetreat((int)thisa) )
      giNextAction = 4;
    else
      combatManager::DoCompAI(thisa, thisa->currentActionSide);
  }
}