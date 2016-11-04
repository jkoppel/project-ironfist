{
  signed int result; // eax@2
  void *v1; // eax@3
  void *v2; // esi@3

  _mtinitlocks();
  dwTlsIndex = TlsAlloc();
  if ( dwTlsIndex == -1 )
  {
    result = 0;
  }
  else
  {
    v1 = calloc(1u, 0x74u);
    v2 = v1;
    if ( v1 && TlsSetValue(dwTlsIndex, v1) )
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
