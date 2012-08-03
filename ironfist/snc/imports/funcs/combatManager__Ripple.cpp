{
  combatManager *thisa; // ST28_4@1

  thisa = a1;
  memcpy(a1->probablyBitmapForCombatScreen->contents, gpWindowManager->screenBuffer->contents, 0x45380u);
  DoRipple(thisa->probablyBitmapForCombatScreen, gpWindowManager->screenBuffer, 443, strength);
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
}