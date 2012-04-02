int __cdecl tolower(int a1)
{
  int result; // eax@2
  signed int v2; // esi@6
  int v3; // edi@8

  if ( Locale )
  {
    if ( dword_538E18 )
    {
      v2 = 1;
      _lock(19);
    }
    else
    {
      v2 = 0;
      ++dword_538E1C;
    }
    result = tolower_0(a1);
    v3 = result;
    if ( v2 )
    {
      _unlock(19);
      result = v3;
    }
    else
    {
      --dword_538E1C;
    }
  }
  else
  {
    result = a1;
    if ( a1 >= 65 )
    {
      if ( a1 <= 90 )
        result = a1 + 32;
    }
  }
  return result;
}
