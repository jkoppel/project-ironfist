{
  HDC hDC; // [sp+10h] [bp-Ch]@6
  signed int i; // [sp+18h] [bp-4h]@1

  for ( i = 10; i < 246; ++i )
  {
    LogicalPalette.palPalEntry[i].peRed = 4 * this->colors[i].red;
    redBlueSwappedGlobalPaletteEntries[i].peBlue = LogicalPalette.palPalEntry[i].peRed;
    LogicalPalette.palPalEntry[i].peGreen = 4 * this->colors[i].green;
    redBlueSwappedGlobalPaletteEntries[i].peGreen = LogicalPalette.palPalEntry[i].peGreen;
    LogicalPalette.palPalEntry[i].peBlue = 4 * this->colors[i].blue;
    redBlueSwappedGlobalPaletteEntries[i].peRed = LogicalPalette.palPalEntry[i].peBlue;
  }
  AnimatePalette(hpalApp, 10u, 236u, (const PALETTEENTRY *)&LogicalPalette + 11);
  thunk_WinGSetDIBColorTable();
  if ( hpalApp )
    DeleteObject(hpalApp);
  hpalApp = CreatePalette(&LogicalPalette);
  hDC = GetDC(hwndApp);
  if ( hpalApp )
    SelectPalette(hDC, hpalApp, 0);
  RealizePalette(hDC);
  ReleaseDC(hwndApp, hDC);
  if ( giMainVideoModeColorDepth != 8 && gpWindowManager->screenBuffer )
  {
    if ( gbLimitedCombatUpdatePalette )
    {
      if ( gbFullCombatScreenDrawn )
        BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640u, 458, 0, 0);
    }
    else
    {
      BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640u, 480, 0, 0);
    }
  }
}