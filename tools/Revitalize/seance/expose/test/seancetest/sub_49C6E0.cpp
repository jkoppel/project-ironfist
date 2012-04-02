void __thiscall sub_49C6E0(PaletteContents *this)
{
  HDC hDC; // [sp+10h] [bp-Ch]@6
  signed int i; // [sp+18h] [bp-4h]@1

  for ( i = 10; i < 246; ++i )
  {
    paletteLog.palPalEntry[i].peRed = 4 * this->colors[i].red;
    redBlueSwappedGlobalPaletteEntries[i].peBlue = paletteLog.palPalEntry[i].peRed;
    paletteLog.palPalEntry[i].peGreen = 4 * this->colors[i].green;
    redBlueSwappedGlobalPaletteEntries[i].peGreen = paletteLog.palPalEntry[i].peGreen;
    paletteLog.palPalEntry[i].peBlue = 4 * this->colors[i].blue;
    redBlueSwappedGlobalPaletteEntries[i].peRed = paletteLog.palPalEntry[i].peBlue;
  }
  AnimatePalette(logicalPaletteHandle, 10u, 236u, (const PALETTEENTRY *)&paletteLog + 11);
  WinGSetDIBColorTable();
  if ( logicalPaletteHandle )
    DeleteObject(logicalPaletteHandle);
  logicalPaletteHandle = CreatePalette(&paletteLog);
  hDC = GetDC(windowHandle);
  if ( logicalPaletteHandle )
    SelectPalette(hDC, logicalPaletteHandle, 0);
  RealizePalette(hDC);
  ReleaseDC(windowHandle, hDC);
  if ( bitspixel != 8 && HeroWindowManager::instance->screenBuffer )
  {
    if ( dword_4F7460 )
    {
      if ( dword_4F745C )
        renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 640u, 458, 0, 0);
    }
    else
    {
      renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 640u, 480, 0, 0);
    }
  }
}
