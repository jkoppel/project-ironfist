{
  if ( !dword_5110CC && dword_5235D4 != 1 && dword_524778 != 2 )
  {
    Icon::drawToScreen(dword_524F38, 244, 406, 81, 0);
    Font::drawString(smallFont, dword_524F3C, 244, 406, 348, 12, 2, 0);
    if ( a1 )
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 244, 406, 0x15Cu, 12);
  }
}
