void __thiscall CombatManager::couldBeResetCombatMessage(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->couldBeShouldResetCombatMessage && this->combatMessageRelatedTime )
  {
    if ( getTickCount() > this->combatMessageRelatedTime )
      CombatManager::displayCombatMessage(thisa, possiblyAlwaysBlankCombatMessage1, 1, 0, 1);
  }
}
