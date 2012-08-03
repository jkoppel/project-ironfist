{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->couldBeShouldResetCombatMessage && this->combatMessageRelatedTime )
  {
    if ( KBTickCount() > this->combatMessageRelatedTime )
      combatManager::CombatMessage(thisa, possiblyAlwaysBlankCombatMessage1, 1, 0, 1);
  }
}