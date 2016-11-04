{
  void *a1a; // [sp+10h] [bp-Ch]@1
  int v15; // [sp+14h] [bp-8h]@1
  int v16; // [sp+18h] [bp-4h]@24

  a1a = KBAlloc(0xFFu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CBC + 3);
  v15 = 0;
  *(_BYTE *)a1a = 0;
  *((_BYTE *)a1a + 1) = a1;
  *((_BYTE *)a1a + 2) = a2;
  if ( a3 )
    *((_BYTE *)a1a + 3) = 1;
  else
    *((_BYTE *)a1a + 3) = 0;
  if ( a5 )
    *((_BYTE *)a1a + 4) = 1;
  else
    *((_BYTE *)a1a + 4) = 0;
  if ( a6 )
    *((_BYTE *)a1a + 5) = 1;
  else
    *((_BYTE *)a1a + 5) = 0;
  *((_BYTE *)a1a + 6) = a8;
  *((_BYTE *)a1a + 7) = a9;
  *((_DWORD *)a1a + 2) = a10;
  *((_BYTE *)a1a + 12) = a12;
  *((_BYTE *)a1a + 13) = a13;
  *((_BYTE *)a1a + 14) = a14;
  if ( a3 )
    *((_BYTE *)a1a + 15) = *(_BYTE *)(a3 + 3);
  else
    *((_BYTE *)a1a + 15) = -1;
  if ( a3 )
    *((_DWORD *)a1a + 4) = gameObject->players[*(_BYTE *)(a3 + 3)].resources[6];
  else
    *((_DWORD *)a1a + 4) = 0;
  if ( a6 )
    *((_BYTE *)a1a + 20) = *(_BYTE *)(a6 + 3);
  else
    *((_BYTE *)a1a + 20) = -1;
  if ( a6 )
    *(_DWORD *)((char *)a1a + 21) = gameObject->players[*(_BYTE *)(a6 + 3)].resources[6];
  else
    *(_DWORD *)((char *)a1a + 21) = 0;
  memcpy((char *)a1a + 25, a4, 0xFu);
  memcpy((char *)a1a + 40, a7, 0xFu);
  if ( a5 )
    memcpy((char *)a1a + 55, a5, 0x64u);
  v16 = sub_46EC00(a1a, a11, 0x9Bu, 21, 22, (int)&v15);
  if ( !v16 )
    terminate(0);
  if ( a3 )
  {
    *(_BYTE *)a1a = 1;
    memcpy((char *)a1a + 1, (const void *)a3, 0xC8u);
    v16 = sub_46E1D0(a1a, a11, 0xC9u, 21, 1, 1, -1);
    if ( !v16 )
      terminate(0);
    *(_BYTE *)a1a = 2;
    memcpy((char *)a1a + 1, (const void *)(a3 + 200), 0x32u);
    v16 = sub_46E1D0(a1a, a11, 0x33u, 21, 1, 1, -1);
    if ( !v16 )
      terminate(0);
  }
  if ( a6 )
  {
    *(_BYTE *)a1a = 3;
    memcpy((char *)a1a + 1, (const void *)a6, 0xC8u);
    v16 = sub_46E1D0(a1a, a11, 0xC9u, 21, 1, 1, -1);
    if ( !v16 )
      terminate(0);
    *(_BYTE *)a1a = 4;
    memcpy((char *)a1a + 1, (const void *)(a6 + 200), 0x32u);
    v16 = sub_46E1D0(a1a, a11, 0x33u, 21, 1, 1, -1);
    if ( !v16 )
      terminate(0);
  }
  KBFree(a1a, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CBC + 92);
}
