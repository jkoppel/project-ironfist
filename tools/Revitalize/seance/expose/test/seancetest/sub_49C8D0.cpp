void __cdecl sub_49C8D0()
{
  HDC v0; // ST1C_4@2
  signed int i; // [sp+10h] [bp-4h]@2
  signed int j; // [sp+10h] [bp-4h]@5

  if ( !logicalPaletteHandle )
  {
    v0 = GetDC(0);
    GetSystemPaletteEntries(v0, 0, 0xAu, paletteLog.palPalEntry);
    GetSystemPaletteEntries(v0, 0xF6u, 0xAu, (LPPALETTEENTRY)&paletteLog + 247);
    ReleaseDC(0, v0);
    for ( i = 0; i < 10; ++i )
    {
      redBlueSwappedGlobalPaletteEntries[i].peBlue = paletteLog.palPalEntry[i].peRed;
      redBlueSwappedGlobalPaletteEntries[i].peGreen = paletteLog.palPalEntry[i].peGreen;
      redBlueSwappedGlobalPaletteEntries[i].peRed = paletteLog.palPalEntry[i].peBlue;
      redBlueSwappedGlobalPaletteEntries[i].peFlags = 0;
      paletteLog.palPalEntry[i].peFlags = 0;
      byte_5303F2[4 * i] = byte_5196D4[4 * i];
      byte_5303F1[4 * i] = byte_5196D5[4 * i];
      byte_5303F0[4 * i] = byte_5196D6[4 * i];
      byte_5303F3[4 * i] = 0;
      byte_5196D7[4 * i] = 0;
    }
    for ( j = 10; j < 246; ++j )
    {
      paletteLog.palPalEntry[j].peRed = 0;
      redBlueSwappedGlobalPaletteEntries[j].peBlue = paletteLog.palPalEntry[j].peRed;
      paletteLog.palPalEntry[j].peGreen = 0;
      redBlueSwappedGlobalPaletteEntries[j].peGreen = paletteLog.palPalEntry[j].peGreen;
      paletteLog.palPalEntry[j].peBlue = 0;
      redBlueSwappedGlobalPaletteEntries[j].peRed = paletteLog.palPalEntry[j].peBlue;
      redBlueSwappedGlobalPaletteEntries[j].peFlags = 0;
      paletteLog.palPalEntry[j].peFlags = 4;
    }
    logicalPaletteHandle = CreatePalette(&paletteLog);
  }
}
