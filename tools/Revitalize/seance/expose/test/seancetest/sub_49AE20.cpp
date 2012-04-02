int __cdecl sub_49AE20()
{
  int result; // eax@1
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@2

  result = sub_49B830(640, 480, 1);
  dword_519714 = result;
  if ( dword_51971C )
  {
    errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)dword_519714 + 112))(dword_519714, 0);
    if ( errorCode )
    {
      if ( errorCode != -2005532104 )
        fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519748 + 10);
    }
    result = (*(int (__cdecl **)(_DWORD))(*(_DWORD *)dword_51971C + 8))(dword_51971C);
    dword_51971C = 0;
  }
  return result;
}
