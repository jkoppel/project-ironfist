{
  int v0; // ebx@1
  int v1; // edi@1
  unsigned int v2; // esi@1
  unsigned int v3; // ebp@2
  int v4; // eax@17
  int *v5; // esi@18
  int v7; // [sp+10h] [bp-4h]@1

  v0 = -1;
  v1 = 0;
  v2 = (unsigned int)dword_538E20;
  _lock(18);
  v7 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)v2;
    if ( !*(_DWORD *)v2 )
      break;
    if ( v3 + 1152 > v3 )
    {
      do
      {
        if ( !(*(_BYTE *)(v3 + 4) & 1) )
        {
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
          EnterCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
          if ( !(*(_BYTE *)(v3 + 4) & 1) )
          {
            *(_DWORD *)v3 = -1;
            v0 = v1 + (signed int)(v3 - *(_DWORD *)v2) / 36;
            break;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
        }
        v3 += 36;
      }
      while ( *(_DWORD *)v2 + 1152 > v3 );
    }
    if ( v0 == -1 )
    {
      v1 += 32;
      v2 += 4;
      ++v7;
      if ( v2 < (unsigned int)&uNumber )
        continue;
    }
    goto LABEL_21;
  }
  v4 = malloc(0x480u);
  if ( v4 )
  {
    uNumber += 32;
    v5 = &dword_538E20[v7];
    for ( *v5 = v4; *v5 + 1152 > (unsigned int)v4; *(_DWORD *)(v4 - 28) = 0 )
    {
      *(_BYTE *)(v4 + 4) = 0;
      v4 += 36;
      *(_DWORD *)(v4 - 36) = -1;
      *(_BYTE *)(v4 - 31) = 10;
    }
    v0 = 32 * v7;
    _lock_fhandle(32 * v7);
  }
LABEL_21:
  _unlock(18);
  return v0;
}
