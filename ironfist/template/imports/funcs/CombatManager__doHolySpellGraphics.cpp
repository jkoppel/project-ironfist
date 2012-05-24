{
  CombatManager *thisa; // ST1C_4@1
  CombatManager *result; // eax@1

  thisa = this;
  memcpy(this->probablyBitmapForCombatScreen->contents, HeroWindowManager::instance->screenBuffer->contents, 0x45380u);
  blur(thisa->probablyBitmapForCombatScreen, HeroWindowManager::instance->screenBuffer, 443, a2, a3, a4);
  result = thisa;
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  return result;
}
