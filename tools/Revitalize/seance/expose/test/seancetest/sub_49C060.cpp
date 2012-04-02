void __cdecl sub_49C060()
{
  MACRO_DDERR errorCode; // [sp+10h] [bp-4h]@4
  MACRO_DDERR errorCodea; // [sp+10h] [bp-4h]@14

  if ( directDrawObject )
  {
    ((void (__cdecl *)(_DWORD))(*directDrawObject)[19].lpVtbl)(directDrawObject);
    if ( dword_51971C )
    {
      if ( dword_519714 )
      {
        errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)dword_519714 + 112))(dword_519714, 0);
        if ( errorCode )
        {
          if ( errorCode != -2005532104 )
            fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519D70 + 14);
        }
      }
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)dword_51971C + 8))(dword_51971C);
      dword_51971C = 0;
    }
    if ( dword_519714 )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)dword_519714 + 8))(dword_519714);
      dword_519714 = 0;
    }
    if ( dword_519718 )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)dword_519718 + 8))(dword_519718);
      dword_519718 = 0;
    }
    if ( dword_519720 )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)dword_519720 + 8))(dword_519720);
      dword_519720 = 0;
    }
    errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*directDrawObject)[20].lpVtbl)(
                   directDrawObject,
                   windowHandle,
                   8);
    if ( errorCodea )
      fatalDirectDrawError(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519D70 + 38);
    ((void (__cdecl *)(_DWORD))(*directDrawObject)[2].lpVtbl)(directDrawObject);
    directDrawObject = 0;
  }
}
