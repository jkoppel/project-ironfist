void __cdecl sub_49B640()
{
  HDC dc; // ST24_4@2
  MACRO_DDERR errorCode; // [sp+10h] [bp-8h]@8
  signed int i; // [sp+14h] [bp-4h]@2
  signed int j; // [sp+14h] [bp-4h]@5

  if ( !dword_519708 )
  {
    dc = GetDC(0);
    GetSystemPaletteEntries(dc, 0, 10u, paletteLog.palPalEntry);
    GetSystemPaletteEntries(dc, SPECIAL_PALETTE_INDICES_2, 10u, (LPPALETTEENTRY)&paletteLog + 247);
    ReleaseDC(0, dc);
    for ( i = 0; i < 10; ++i )
    {
      paletteLog.palPalEntry[i].peFlags = 0;
      byte_5196D7[4 * i] = 0;
    }
    for ( j = 10; j < 246; ++j )
    {
      paletteLog.palPalEntry[j].peRed = 0;
      paletteLog.palPalEntry[j].peGreen = 0;
      paletteLog.palPalEntry[j].peBlue = 0;
      paletteLog.palPalEntry[j].peFlags = PC_NOCOLLAPSE;
    }
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*directDrawObject)[5].lpVtbl)(
                  directDrawObject,
                  4,
                  paletteLog.palPalEntry,
                  &dword_519720,
                  0);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519950 + 63);
    sub_49CDE0();
  }
}
