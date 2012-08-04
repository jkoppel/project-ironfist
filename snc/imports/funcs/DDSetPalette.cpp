{
  signed int result; // eax@2
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@9

  if ( gbWinGraphBusy )
  {
    result = 1;
  }
  else if ( gbForegroundApp )
  {
    if ( lpDDPal && lpDDSPrimary && lpDD )
    {
      errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)lpDDSPrimary + 124))(lpDDSPrimary, lpDDPal);
      if ( errorCode )
        DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519974 + 15);
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}