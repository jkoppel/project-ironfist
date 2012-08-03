{
  signed int v2; // edi@2
  int result; // eax@4
  int v4; // esi@4

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
  result = _wctomb_lk((LPSTR)a1, WideCharStr);
  v4 = result;
  if ( v2 )
  {
    _unlock(19);
    result = v4;
  }
  else
  {
    --dword_538E1C;
  }
  return result;
}