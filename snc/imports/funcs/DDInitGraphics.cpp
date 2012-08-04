{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2
  MACRO_DDERR errorCodea; // [sp+Ch] [bp-4h]@5
  MACRO_DDERR errorCodeb; // [sp+Ch] [bp-4h]@7
  MACRO_DDERR errorCodec; // [sp+Ch] [bp-4h]@10

  if ( !gbWinGraphBusy )
  {
    errorCode = lpDirectDrawCreate(NULL, &lpDD, NULL);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 8);
    if ( *(&bMenu + 7 * giCurExe + 5) )
    {
      SetMenuStatus(0);
      errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*lpDD)[20].lpVtbl)(lpDD, hwndApp, 19);
      if ( errorCodea )
        DDSD(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 20);
      errorCodeb = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*lpDD)[21].lpVtbl)(lpDD, 640, 480, 8);
      if ( errorCodeb )
        DDSD(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 24);
    }
    else
    {
      errorCodec = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*lpDD)[20].lpVtbl)(lpDD, hwndApp, 8);
      if ( errorCodec )
        DDSD(errorCodec, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 31);
    }
    CreatePrimary();
    SetupClipper();
    lpDDSOne = DDCreateSurface(640, 480, 0);
    InitializePalette();
  }
}