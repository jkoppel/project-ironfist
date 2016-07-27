{
  LPCRITICAL_SECTION *v1; // edi@1
  int v2; // esi@2

  v1 = &dword_520D58 + a1;
  if ( !*v1 )
  {
    v2 = malloc(0x18u);
    if ( !v2 )
      _amsg_exit(17);
    _lock(17);
    if ( *v1 )
    {
      free(v2);
    }
    else
    {
      InitializeCriticalSection((LPCRITICAL_SECTION)v2);
      *v1 = (LPCRITICAL_SECTION)v2;
    }
    _unlock(17);
  }
  EnterCriticalSection(*v1);
}
