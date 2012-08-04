{
  HDC v0; // ST1C_4@2
  signed int i; // [sp+10h] [bp-4h]@2
  signed int j; // [sp+10h] [bp-4h]@5

  if ( !hpalApp )
  {
    v0 = GetDC(0);
    GetSystemPaletteEntries(v0, 0, 0xAu, LogicalPalette.palPalEntry);
    GetSystemPaletteEntries(v0, 0xF6u, 0xAu, (LPPALETTEENTRY)&LogicalPalette + 247);
    ReleaseDC(0, v0);
    for ( i = 0; i < 10; ++i )
    {
      redBlueSwappedGlobalPaletteEntries[i].peBlue = LogicalPalette.palPalEntry[i].peRed;
      redBlueSwappedGlobalPaletteEntries[i].peGreen = LogicalPalette.palPalEntry[i].peGreen;
      redBlueSwappedGlobalPaletteEntries[i].peRed = LogicalPalette.palPalEntry[i].peBlue;
      redBlueSwappedGlobalPaletteEntries[i].peFlags = 0;
      LogicalPalette.palPalEntry[i].peFlags = 0;
      byte_5303F2[4 * i] = byte_5196D4[4 * i];
      byte_5303F1[4 * i] = byte_5196D5[4 * i];
      byte_5303F0[4 * i] = byte_5196D6[4 * i];
      byte_5303F3[4 * i] = 0;
      byte_5196D7[4 * i] = 0;
    }
    for ( j = 10; j < 246; ++j )
    {
      LogicalPalette.palPalEntry[j].peRed = 0;
      redBlueSwappedGlobalPaletteEntries[j].peBlue = LogicalPalette.palPalEntry[j].peRed;
      LogicalPalette.palPalEntry[j].peGreen = 0;
      redBlueSwappedGlobalPaletteEntries[j].peGreen = LogicalPalette.palPalEntry[j].peGreen;
      LogicalPalette.palPalEntry[j].peBlue = 0;
      redBlueSwappedGlobalPaletteEntries[j].peRed = LogicalPalette.palPalEntry[j].peBlue;
      redBlueSwappedGlobalPaletteEntries[j].peFlags = 0;
      LogicalPalette.palPalEntry[j].peFlags = 4;
    }
    hpalApp = CreatePalette(&LogicalPalette);
  }
}