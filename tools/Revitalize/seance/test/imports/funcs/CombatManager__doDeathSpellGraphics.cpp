{
  CombatManager *thisa; // ST28_4@1

  thisa = this;
  memcpy(this->probablyBitmapForCombatScreen->contents, HeroWindowManager::instance->screenBuffer->contents, 0x45380u);
  sendRippleAcrossScreen(thisa->probablyBitmapForCombatScreen, HeroWindowManager::instance->screenBuffer, 443, strength);
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
}
