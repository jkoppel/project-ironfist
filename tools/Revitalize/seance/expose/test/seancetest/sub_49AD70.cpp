void __cdecl sub_49AD70()
{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2

  if ( directDrawObject )
  {
    errorCode = ((int (__cdecl *)(_DWORD))(*directDrawObject)[19].lpVtbl)(directDrawObject);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519724 + 7);
  }
}
