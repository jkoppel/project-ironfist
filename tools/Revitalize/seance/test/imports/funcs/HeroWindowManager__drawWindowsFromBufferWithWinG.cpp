{
  HeroWindowManager *thisa; // esi@1

  thisa = this;
  yieldToGlobalUpdater();
  renderScreenFromBitmapWithWinG(thisa->screenBuffer);
  yieldToGlobalUpdater();
}
