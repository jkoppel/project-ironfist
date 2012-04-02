void __thiscall sub_4CAA50(void *this)
{
  void *v1; // esi@1

  v1 = this;
  if ( debugLogLevel >= 2 )
  {
    sub_4D6A50(HeroWindowManager::instance->screenBuffer, 0, 460, 0x280u, 20, 0);
    Font::drawString(smallFont, (const char *)v1, 0, 464, 640, 16, 1, 0);
    renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 460, 0x280u, 20, 0, 460);
  }
}
