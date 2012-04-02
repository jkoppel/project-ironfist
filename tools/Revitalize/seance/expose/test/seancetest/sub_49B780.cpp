signed int __cdecl sub_49B780()
{
  signed int result; // eax@2
  MACRO_DDERR errorCode; // [sp+Ch] [bp-4h]@9

  if ( dword_519708 )
  {
    result = 1;
  }
  else
  {
    if ( dword_4F0A10 )
    {
      if ( dword_519720 && dword_519714 && directDrawObject )
      {
        errorCode = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)dword_519714 + 124))(dword_519714, dword_519720);
        if ( errorCode )
          fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519974 + 15);
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
  }
  return result;
}
