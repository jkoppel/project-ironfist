{
  int v0; // ebx@1
  signed int v1; // ebp@1
  signed int v2; // esi@2
  int v3; // eax@3

  v0 = 0;
  v1 = 3;
  _lock(2);
  if ( (signed int)dword_538E10 > 3 )
  {
    v2 = 12;
    do
    {
      v3 = *(_DWORD *)(dword_537E0C + v2);
      if ( v3 )
      {
        if ( *(_BYTE *)(v3 + 12) & 0x83 && fclose(*(_DWORD *)(dword_537E0C + v2)) != -1 )
          ++v0;
        if ( v2 >= 80 )
        {
          DeleteCriticalSection((LPCRITICAL_SECTION)(*(_DWORD *)(dword_537E0C + v2) + 32));
          free(*(_DWORD *)(dword_537E0C + v2));
          *(_DWORD *)(dword_537E0C + v2) = 0;
        }
      }
      v2 += 4;
      ++v1;
    }
    while ( (signed int)dword_538E10 > v1 );
  }
  _unlock(2);
  return v0;
}
