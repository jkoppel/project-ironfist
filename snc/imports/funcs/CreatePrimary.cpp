{
  int result; // eax@1
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2

  result = DDCreateSurface(640, 480, 1);
  lpDDSPrimary = result;
  if ( lpClipper )
  {
    errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)lpDDSPrimary + 112))(lpDDSPrimary, 0);
    if ( errorCode )
    {
      if ( errorCode != -2005532104 )
        DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519748 + 10);
    }
    result = (*(int (__cdecl **)(_DWORD))(*(_DWORD *)lpClipper + 8))(lpClipper);
    lpClipper = 0;
  }
  return result;
}