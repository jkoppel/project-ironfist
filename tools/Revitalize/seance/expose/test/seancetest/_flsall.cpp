signed int __cdecl flsall(int a1)
{
  signed int v1; // ebx@1
  signed int v2; // edi@1
  int v3; // ebp@2
  int v4; // esi@2
  int v5; // eax@3
  int v6; // eax@5
  signed int result; // eax@17
  signed int v8; // [sp+10h] [bp-4h]@1

  v1 = 0;
  v2 = 0;
  v8 = 0;
  _lock(2);
  if ( (signed int)dword_538E10 <= 0 )
  {
    v4 = a1;
  }
  else
  {
    v3 = 0;
    v4 = a1;
    do
    {
      v5 = *(_DWORD *)(dword_537E0C + v3);
      if ( v5 && *(_BYTE *)(v5 + 12) & 0x83 )
      {
        _lock_file2(v2, *(_DWORD *)(dword_537E0C + v3));
        v6 = *(_DWORD *)(*(_DWORD *)(dword_537E0C + v3) + 12);
        if ( v6 & 0x83 )
        {
          if ( a1 == 1 )
          {
            if ( _fflush_lk(*(_DWORD *)(dword_537E0C + v3)) != -1 )
              ++v1;
          }
          else
          {
            if ( !a1 && v6 & 2 && _fflush_lk(*(_DWORD *)(dword_537E0C + v3)) == -1 )
              v8 = -1;
          }
        }
        _unlock_file2(v2, *(_DWORD *)(dword_537E0C + v3));
      }
      v3 += 4;
      ++v2;
    }
    while ( v2 < (signed int)dword_538E10 );
  }
  _unlock(2);
  result = v1;
  if ( v4 != 1 )
    result = v8;
  return result;
}
