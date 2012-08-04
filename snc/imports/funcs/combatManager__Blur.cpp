{
  combatManager *thisa; // ST1C_4@1
  combatManager *result; // eax@1

  thisa = this;
  memcpy(this->probablyBitmapForCombatScreen->contents, gpWindowManager->screenBuffer->contents, 0x45380u);
  DoBlur(thisa->probablyBitmapForCombatScreen, gpWindowManager->screenBuffer, 443, a2, a3, a4);
  result = thisa;
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  return result;
}