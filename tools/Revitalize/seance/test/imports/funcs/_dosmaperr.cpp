{
  int v1; // esi@1
  unsigned int v2; // eax@1
  int *result; // eax@6

  v1 = 0;
  *__doserrno() = a1;
  v2 = (unsigned int)&unk_520B90;
  do
  {
    if ( *(_DWORD *)v2 == a1 )
    {
      result = _errno();
      *result = dword_520B94[2 * v1];
      return result;
    }
    v2 += 8;
    ++v1;
  }
  while ( v2 < (unsigned int)&unk_520CF8 );
  if ( a1 < 0x13 || a1 > 0x24 )
  {
    if ( a1 < 0xBC || a1 > 0xCA )
    {
      result = _errno();
      *result = 22;
    }
    else
    {
      result = _errno();
      *result = 8;
    }
  }
  else
  {
    result = _errno();
    *result = 13;
  }
  return result;
}
