{
  MACRO_DDERR errorCode; // [sp+10h] [bp-4h]@4
  MACRO_DDERR errorCodea; // [sp+10h] [bp-4h]@14

  if ( lpDD )
  {
    ((void (__cdecl *)(_DWORD))(*lpDD)[19].lpVtbl)(lpDD);
    if ( lpClipper )
    {
      if ( lpDDSPrimary )
      {
        errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)lpDDSPrimary + 112))(lpDDSPrimary, 0);
        if ( errorCode )
        {
          if ( errorCode != -2005532104 )
            DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519D70 + 14);
        }
      }
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)lpClipper + 8))(lpClipper);
      lpClipper = 0;
    }
    if ( lpDDSPrimary )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)lpDDSPrimary + 8))(lpDDSPrimary);
      lpDDSPrimary = 0;
    }
    if ( lpDDSOne )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)lpDDSOne + 8))(lpDDSOne);
      lpDDSOne = 0;
    }
    if ( lpDDPal )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)lpDDPal + 8))(lpDDPal);
      lpDDPal = 0;
    }
    errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*lpDD)[20].lpVtbl)(lpDD, hwndApp, 8);
    if ( errorCodea )
      DDSD(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519D70 + 38);
    ((void (__cdecl *)(_DWORD))(*lpDD)[2].lpVtbl)(lpDD);
    lpDD = 0;
  }
}