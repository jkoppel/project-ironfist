void __fastcall CombatManager::doDeathSpellGraphics(CombatManager *a1, int a2, int strength)
{
  CombatManager *thisa; // ST28_4@1

  thisa = a1;
  memcpy(a1->probablyBitmapForCombatScreen->contents, HeroWindowManager::instance->screenBuffer->contents, 0x45380u);
  sendRippleAcrossScreen(thisa->probablyBitmapForCombatScreen, HeroWindowManager::instance->screenBuffer, 443, strength);
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
}
