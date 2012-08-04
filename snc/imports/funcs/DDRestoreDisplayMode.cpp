{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2

  if ( lpDD )
  {
    errorCode = ((int (__cdecl *)(_DWORD))(*lpDD)[19].lpVtbl)(lpDD);
    if ( errorCode )
      DDSD(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519724 + 7);
  }
}