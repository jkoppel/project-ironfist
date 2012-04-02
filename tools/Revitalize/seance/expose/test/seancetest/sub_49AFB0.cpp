void __cdecl sub_49AFB0()
{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2
  MACRO_DDERR errorCodea; // [sp+Ch] [bp-4h]@5
  MACRO_DDERR errorCodeb; // [sp+Ch] [bp-4h]@7
  MACRO_DDERR errorCodec; // [sp+Ch] [bp-4h]@10

  if ( !dword_519708 )
  {
    errorCode = DirectDrawCreate(NULL, &directDrawObject, NULL);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 8);
    if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
    {
      sub_485B30(0);
      errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*directDrawObject)[20].lpVtbl)(
                     directDrawObject,
                     windowHandle,
                     19);
      if ( errorCodea )
        fatalDirectDrawError(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 20);
      errorCodeb = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*directDrawObject)[21].lpVtbl)(
                     directDrawObject,
                     640,
                     480,
                     8);
      if ( errorCodeb )
        fatalDirectDrawError(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 24);
    }
    else
    {
      errorCodec = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*directDrawObject)[20].lpVtbl)(
                     directDrawObject,
                     windowHandle,
                     8);
      if ( errorCodec )
        fatalDirectDrawError(errorCodec, "F:\\h2xsrc\\Source\\wingraph.cpp", word_5197D0 + 31);
    }
    sub_49AE20();
    sub_49AEC0();
    dword_519718 = sub_49B830(640, 480, 0);
    sub_49CF80();
  }
}
