void __thiscall sub_49BF40(RGB *this)
{
  MACRO_DDERR errorCode; // [sp+10h] [bp-8h]@6
  signed int i; // [sp+14h] [bp-4h]@3

  if ( !dword_519708 && dword_4F0A10 )
  {
    for ( i = 10; i < SPECIAL_PALETTE_INDICES_2; ++i )
    {
      paletteLog.palPalEntry[i].peRed = 4 * this[i].red;
      paletteLog.palPalEntry[i].peGreen = 4 * this[i].green;
      paletteLog.palPalEntry[i].peBlue = 4 * this[i].blue;
      paletteLog.palPalEntry[i].peFlags = PC_NOCOLLAPSE;
    }
    assertTrue(dword_519720, "F:\\h2xsrc\\Source\\wingraph.cpp", fiveHundred + 18);
    errorCode = (*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_519720 + 24))(
                  dword_519720,
                  0,
                  10,
                  236,
                  (char *)&paletteLog + 44);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", fiveHundred + 22);
  }
}
