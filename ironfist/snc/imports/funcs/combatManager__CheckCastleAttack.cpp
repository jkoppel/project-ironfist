{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->isCastleBattle && !this->currentActionSide )
  {
    while ( thisa->timesCatapultMustFire[thisa->currentActionSide] > 0 )
    {
      combatManager::CatAttack(thisa, thisa->currentActionSide);
      --thisa->timesCatapultMustFire[thisa->currentActionSide];
    }
  }
  if ( thisa->isCastleBattle && thisa->currentActionSide == 1 )
  {
    while ( thisa->timesGarrisonMustFire[thisa->currentActionSide] > 0 )
    {
      combatManager::KeepAttack(thisa, 0);
      combatManager::KeepAttack(thisa, 1);
      combatManager::KeepAttack(thisa, 2);
      --thisa->timesGarrisonMustFire[thisa->currentActionSide];
    }
  }
}