{
  HDC dc; // ST24_4@2
  MACRO_DDERR errorCode; // [sp+10h] [bp-8h]@8
  signed int i; // [sp+14h] [bp-4h]@2
  signed int j; // [sp+14h] [bp-4h]@5

  if ( !gbWinGraphBusy )
  {
    dc = GetDC(0);
    GetSystemPaletteEntries(dc, 0, 10u, LogicalPalette.palPalEntry);
    GetSystemPaletteEntries(dc, SPECIAL_PALETTE_INDICES_2, 10u, (LPPALETTEENTRY)&LogicalPalette + 247);
    ReleaseDC(0, dc);
    for ( i = 0; i < 10; ++i )
    {
      LogicalPalette.palPalEntry[i].peFlags = 0;
      byte_5196D7[4 * i] = 0;
    }
    for ( j = 10; j < 246; ++j )
    {
      LogicalPalette.palPalEntry[j].peRed = 0;
      LogicalPalette.palPalEntry[j].peGreen = 0;
      LogicalPalette.palPalEntry[j].peBlue = 0;
      LogicalPalette.palPalEntry[j].peFlags = PC_NOCOLLAPSE;
    }
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*lpDD)[5].lpVtbl)(
                  lpDD,
                  4,
                  LogicalPalette.palPalEntry,
                  &lpDDPal,
                  0);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519950 + 63);
    SetPalette();
  }
}