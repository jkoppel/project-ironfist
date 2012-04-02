void __cdecl sub_49AEC0()
{
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2
  MACRO_DDERR errorCodea; // [sp+Ch] [bp-4h]@4
  MACRO_DDERR errorCodeb; // [sp+Ch] [bp-4h]@6

  if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
  {
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*directDrawObject)[4].lpVtbl)(
                  directDrawObject,
                  0,
                  &dword_51971C,
                  0);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 8);
    errorCodea = (*(int (__cdecl **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_51971C + 32))(
                   dword_51971C,
                   0,
                   windowHandle);
    if ( errorCodea )
      fatalDirectDrawError(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 13);
    errorCodeb = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)dword_519714 + 112))(dword_519714, dword_51971C);
    if ( errorCodeb )
      fatalDirectDrawError(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_51976C + 18);
  }
}
