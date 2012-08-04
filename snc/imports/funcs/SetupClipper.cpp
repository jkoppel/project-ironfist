{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2
  MACRO_DDERR errorCodea; // [sp+Ch] [bp-4h]@4
  MACRO_DDERR errorCodeb; // [sp+Ch] [bp-4h]@6

  if ( !*(&bMenu + 7 * giCurExe + 5) )
  {
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*lpDD)[4].lpVtbl)(lpDD, 0, &lpClipper, 0);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 8);
    errorCodea = (*(int (__cdecl **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)lpClipper + 32))(lpClipper, 0, hwndApp);
    if ( errorCodea )
      DDSD(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 13);
    errorCodeb = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)lpDDSPrimary + 112))(lpDDSPrimary, lpClipper);
    if ( errorCodeb )
      DDSD(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 18);
  }
}