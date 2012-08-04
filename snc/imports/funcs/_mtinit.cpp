{
  signed int result; // eax@2
  void *v1; // eax@3
  void *v2; // esi@3

  _mtinitlocks();
  __tlsindex = TlsAlloc();
  if ( __tlsindex == -1 )
  {
    result = 0;
  }
  else
  {
    v1 = calloc(1, 116);
    v2 = v1;
    if ( v1 && TlsSetValue(__tlsindex, v1) )
    {
      _initptd(v2);
      *(_DWORD *)v2 = GetCurrentThreadId();
      result = 1;
      *((_DWORD *)v2 + 1) = -1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}