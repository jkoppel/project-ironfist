{
  void *v3; // [sp+Ch] [bp-4h]@1

  v3 = this;
  if ( a3 || dword_524C14 )
  {
    yieldToGlobalUpdater();
    dword_4F2E78 = *(_DWORD *)((char *)v3 + 502);
    dword_4F2E7C = *(_DWORD *)((char *)v3 + 506);
    if ( xOff == -1 )
      renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 16, 16, 0x1C0u, 448, 16, 16);
    else
      renderBitmapToScreenWithWinG(
        HeroWindowManager::instance->screenBuffer,
        xOff,
        yOff,
        dword_524D18 - xOff,
        dword_524D1C - yOff,
        xOff,
        yOff);
    dword_4F2E7C = 0;
    dword_4F2E78 = 0;
    yieldToGlobalUpdater();
    if ( getTickCount() > animationFrameSwitchTime )
    {
      ++*(_DWORD *)((char *)v3 + 514);
      ++*(_DWORD *)((char *)v3 + 510);
      if ( *(_DWORD *)((char *)v3 + 510) >= 6 )
        *(_DWORD *)((char *)v3 + 510) = 0;
      animationFrameSwitchTime = getTickCount() + 120;
      if ( *(_DWORD *)((char *)v3 + 510) != 1
        && *(_DWORD *)((char *)v3 + 510) != 3
        && *(_DWORD *)((char *)v3 + 510) != 5 )
      {
        ++*(_DWORD *)((char *)v3 + 522);
        *(_DWORD *)((char *)v3 + 522) %= 18;
        ++*(_DWORD *)((char *)v3 + 530);
        *(_DWORD *)((char *)v3 + 530) %= 18;
      }
      else
      {
        ++*(_DWORD *)((char *)v3 + 526);
        *(_DWORD *)((char *)v3 + 526) %= 18;
        ++*(_DWORD *)((char *)v3 + 534);
        *(_DWORD *)((char *)v3 + 534) %= 18;
      }
    }
    xOff = -1;
    passOnMessages();
  }
  else
  {
    if ( getTickCount() > animationFrameSwitchTime )
      animationFrameSwitchTime = getTickCount() + 120;
  }
}
