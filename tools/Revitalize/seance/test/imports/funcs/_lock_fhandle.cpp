{
  char *v1; // edi@1
  int v2; // esi@1
  int v3; // ebx@1

  v1 = (char *)dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3);
  v2 = 36 * (a1 & 0x1F);
  v3 = v2 + *(_DWORD *)v1;
  if ( !*(_DWORD *)(v3 + 8) )
  {
    _lock(17);
    if ( !*(_DWORD *)(v3 + 8) )
    {
      InitializeCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
      ++*(_DWORD *)(v3 + 8);
    }
    _unlock(17);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(v2 + *(_DWORD *)v1 + 12));
}
