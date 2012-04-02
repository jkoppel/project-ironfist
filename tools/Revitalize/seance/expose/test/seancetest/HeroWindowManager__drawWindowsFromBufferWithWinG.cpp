void __thiscall HeroWindowManager::drawWindowsFromBufferWithWinG(HeroWindowManager *this)
{
  HeroWindowManager *thisa; // esi@1

  thisa = this;
  yieldToGlobalUpdater();
  renderScreenFromBitmapWithWinG(thisa->screenBuffer);
  yieldToGlobalUpdater();
}
