{
  LPCRITICAL_SECTION *v1; // edi@1
  struct _RTL_CRITICAL_SECTION *v2; // esi@2

  v1 = &_locktable + a1;
  if ( !*v1 )
  {
    v2 = (struct _RTL_CRITICAL_SECTION *)malloc(0x18u);
    if ( !v2 )
      _amsg_exit(17);
    _lock(17);
    if ( *v1 )
    {
      free((BOOL)v2);
    }
    else
    {
      InitializeCriticalSection(v2);
      *v1 = v2;
    }
    _unlock(17);
  }
  EnterCriticalSection(*v1);
}