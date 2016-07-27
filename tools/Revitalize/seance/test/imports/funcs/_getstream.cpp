{
  signed int v0; // esi@1
  int v1; // edi@1
  int v2; // ebx@2
  int v3; // eax@3
  int v4; // eax@10

  v0 = 0;
  v1 = 0;
  _lock(2);
  if ( (signed int)dword_538E10 > 0 )
  {
    v2 = 0;
    while ( 1 )
    {
      v3 = *(_DWORD *)(dword_537E0C + v2);
      if ( !v3 )
        break;
      if ( !(*(_DWORD *)(v3 + 12) & 0x83) )
      {
        _lock_file2(v0, *(_DWORD *)(dword_537E0C + v2));
        if ( !(*(_DWORD *)(*(_DWORD *)(dword_537E0C + v2) + 12) & 0x83) )
        {
          v1 = *(_DWORD *)(dword_537E0C + 4 * v0);
          goto LABEL_12;
        }
        _unlock_file2(v0, *(_DWORD *)(dword_537E0C + v2));
      }
      v2 += 4;
      ++v0;
      if ( (signed int)dword_538E10 <= v0 )
        goto LABEL_12;
    }
    *(_DWORD *)(dword_537E0C + 4 * v0) = malloc(0x38u);
    v4 = *(_DWORD *)(dword_537E0C + 4 * v0);
    if ( v4 )
    {
      InitializeCriticalSection((LPCRITICAL_SECTION)(v4 + 32));
      EnterCriticalSection((LPCRITICAL_SECTION)(*(_DWORD *)(dword_537E0C + 4 * v0) + 32));
      v1 = *(_DWORD *)(dword_537E0C + 4 * v0);
    }
  }
LABEL_12:
  if ( v1 )
  {
    *(_DWORD *)(v1 + 4) = 0;
    *(_DWORD *)(v1 + 12) = 0;
    *(_DWORD *)(v1 + 8) = 0;
    *(_DWORD *)v1 = 0;
    *(_DWORD *)(v1 + 28) = 0;
    *(_DWORD *)(v1 + 16) = -1;
  }
  _unlock(2);
  return v1;
}
