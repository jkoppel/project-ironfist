{
  DWORD v0; // esi@1
  LPVOID v1; // edi@1
  void *v2; // eax@2

  v0 = GetLastError();
  v1 = TlsGetValue(__tlsindex);
  if ( !v1 )
  {
    v2 = calloc(1, 116);
    v1 = v2;
    if ( v2 && TlsSetValue(__tlsindex, v2) )
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