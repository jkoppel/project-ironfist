{
  if ( a2 )
  {
    if ( getTickCount() > dword_4F1CB0 )
    {
      dword_4F1CB0 = getTickCount() + 250;
      dword_50DFC4 = (dword_50DFC4 + 1) % 39;
      Icon::drawToScreen(a2, 0, 0, dword_50DFC4 + 1, 0);
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 46, 176, 0x8Bu, 187);
    }
  }
}
