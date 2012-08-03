{
  MACRO_DDERR errorCode; // [sp+10h] [bp-8h]@6
  signed int i; // [sp+14h] [bp-4h]@3

  if ( !gbWinGraphBusy && gbForegroundApp )
  {
    for ( i = 10; i < SPECIAL_PALETTE_INDICES_2; ++i )
    {
      LogicalPalette.palPalEntry[i].peRed = 4 * this[i].red;
      LogicalPalette.palPalEntry[i].peGreen = 4 * this[i].green;
      LogicalPalette.palPalEntry[i].peBlue = 4 * this[i].blue;
      LogicalPalette.palPalEntry[i].peFlags = PC_NOCOLLAPSE;
    }
    ProcessAssert(lpDDPal, "F:\\h2xsrc\\Source\\wingraph.cpp", fiveHundred + 18);
    errorCode = (*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)lpDDPal + 24))(
                  lpDDPal,
                  0,
                  10,
                  236,
                  (char *)&LogicalPalette + 44);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", fiveHundred + 22);
  }
}