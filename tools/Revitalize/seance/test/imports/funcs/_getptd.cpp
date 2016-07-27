{
  DWORD v0; // esi@1
  LPVOID v1; // edi@1
  void *v2; // eax@2

  v0 = GetLastError();
  v1 = TlsGetValue(dwTlsIndex);
  if ( !v1 )
  {
    v2 = calloc(1u, 0x74u);
    v1 = v2;
    if ( v2 && TlsSetValue(dwTlsIndex, v2) )
    {
      _initptd(v1);
      *(_DWORD *)v1 = GetCurrentThreadId();
      *((_DWORD *)v1 + 1) = -1;
    }
    else
    {
      _amsg_exit(16);
    }
  }
  SetLastError(v0);
  return v1;
}
