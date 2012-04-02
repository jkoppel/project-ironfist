void __thiscall CombatManager::handleGarrisonAndCatapult(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->isCastleBattle && !this->currentActionSide )
  {
    while ( thisa->timesCatapultMustFire[thisa->currentActionSide] > 0 )
    {
      CombatManager::handleCatapult(thisa, thisa->currentActionSide);
      --thisa->timesCatapultMustFire[thisa->currentActionSide];
    }
  }
  if ( thisa->isCastleBattle && thisa->currentActionSide == 1 )
  {
    while ( thisa->timesGarrisonMustFire[thisa->currentActionSide] > 0 )
    {
      CombatManager::handleTurrets(thisa, 0);
      CombatManager::handleTurrets(thisa, 1);
      CombatManager::handleTurrets(thisa, 2);
      --thisa->timesGarrisonMustFire[thisa->currentActionSide];
    }
  }
}
