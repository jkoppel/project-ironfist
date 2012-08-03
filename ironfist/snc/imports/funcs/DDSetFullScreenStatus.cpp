{
  int y; // [sp+10h] [bp-14h]@3
  MACRO_DDERR errorCode; // [sp+14h] [bp-10h]@5
  MACRO_DDERR errorCodea; // [sp+14h] [bp-10h]@8
  MACRO_DDERR errorCodeb; // [sp+14h] [bp-10h]@11
  MACRO_DDERR errorCodec; // [sp+14h] [bp-10h]@13
  MACRO_DDERR errorCoded; // [sp+14h] [bp-10h]@17
  int x; // [sp+18h] [bp-Ch]@3
  unsigned int heightNeededToDisplay; // [sp+1Ch] [bp-8h]@3
  unsigned int width; // [sp+20h] [bp-4h]@3

  if ( !gbWinGraphBusy && (void *)*(&bMenu + 7 * giCurExe + 5) != this )
  {
    x = *(&bMenu + 7 * giCurExe + 1);
    y = *(&bMenu + 7 * giCurExe + 2);
    width = *(&bMenu + 7 * giCurExe + 3);
    heightNeededToDisplay = *(&bMenu + 7 * giCurExe + 4);
    gbWinGraphBusy = 1;
    *(&bMenu + 7 * giCurExe + 5) = (BOOL)this;
    if ( *(&bMenu + 7 * giCurExe + 5) )
      SetMenuStatus(0);
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*lpDD)[20].lpVtbl)(lpDD, hwndApp, 19);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 21);
    if ( *(&bMenu + 7 * giCurExe + 5) )
    {
      errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*lpDD)[21].lpVtbl)(lpDD, 640, 480, 8);
      if ( errorCodea )
        DDSD(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 27);
    }
    else
    {
      errorCodeb = ((int (__cdecl *)(_DWORD))(*lpDD)[19].lpVtbl)(lpDD);
      if ( errorCodeb )
        DDSD(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 34);
      errorCodec = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*lpDD)[20].lpVtbl)(lpDD, hwndApp, 8);
      if ( errorCodec )
        DDSD(errorCodec, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 39);
    }
    if ( lpDDSPrimary )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)lpDDSPrimary + 8))(lpDDSPrimary);
      lpDDSPrimary = 0;
    }
    CreatePrimary();
    errorCoded = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)lpDDSPrimary + 124))(lpDDSPrimary, lpDDPal);
    if ( errorCoded )
      DDSD(errorCoded, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 51);
    WritePrefs();
    gbWinGraphBusy = 0;
    if ( *(&bMenu + 7 * giCurExe + 5) )
    {
      *(&bMenu + 7 * giCurExe + 1) = x;
      *(&bMenu + 7 * giCurExe + 2) = y;
      *(&bMenu + 7 * giCurExe + 3) = width;
      *(&bMenu + 7 * giCurExe + 4) = heightNeededToDisplay;
    }
    else
    {
      SetMenuStatus(1);
      ResizeWindow(x, y, width, heightNeededToDisplay);
    }
    SetupClipper();
  }
}