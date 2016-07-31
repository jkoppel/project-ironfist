{
  void *result; // eax@9
  int v16; // [sp+10h] [bp-2Ch]@9
  int v17; // [sp+14h] [bp-28h]@3
  signed int v18; // [sp+18h] [bp-24h]@9
  int v19; // [sp+1Ch] [bp-20h]@1
  signed int v20; // [sp+20h] [bp-1Ch]@9
  int v21; // [sp+28h] [bp-14h]@1
  signed int v22; // [sp+2Ch] [bp-10h]@9
  int v23; // [sp+30h] [bp-Ch]@1
  signed int v24; // [sp+34h] [bp-8h]@9
  int v25; // [sp+38h] [bp-4h]@1
  void *v26; // [sp+44h] [bp+8h]@21

  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  *a8 = 0;
  *a9 = 0;
  *(_DWORD *)a2 = *(_BYTE *)a1;
  *(_DWORD *)a3 = *(_BYTE *)(a1 + 10);
  *(_DWORD *)a4 = *(_BYTE *)(a1 + 11);
  v25 = *(_BYTE *)(a1 + 12);
  v21 = *(_BYTE *)(a1 + 13);
  v19 = *(_BYTE *)(a1 + 14);
  *(_DWORD *)a10 = *(_BYTE *)(a1 + 15);
  *(_DWORD *)a11 = *(_BYTE *)(a1 + 16);
  *(_DWORD *)a12 = *(_DWORD *)(a1 + 17);
  *(_BYTE *)a13 = *(_BYTE *)(a1 + 21);
  *(_BYTE *)a14 = *(_BYTE *)(a1 + 22);
  *(_BYTE *)a15 = *(_BYTE *)(a1 + 23);
  v23 = *(_BYTE *)(a1 + 24);
  if ( v23 > 0 )
    gameObject->players[v23].resources[6] = *(_DWORD *)(a1 + 25);
  v17 = *(_BYTE *)(a1 + 29);
  if ( v17 > 0 )
    gameObject->players[v17].resources[6] = *(_DWORD *)(a1 + 30);
  *a6 = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 38);
  memcpy(*a6, (const void *)(a1 + 34), 0xFu);
  *a9 = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 41);
  memcpy(*a9, (const void *)(a1 + 49), 0xFu);
  if ( v21 )
  {
    *a7 = KBAlloc(0x64u, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 46);
    memcpy(*a7, (const void *)(a1 + 64), 0x64u);
  }
  dword_523430 = *(_DWORD *)a2;
  dword_523434 = dword_523F14;
  if ( !sub_46E1D0(0, *(_DWORD *)a2, 0, 22, 1, 1, -1) )
    terminate(0);
  result = (void *)getTickCount();
  v16 = (int)result;
  v18 = 1;
  v22 = 1;
  v24 = 1;
  v20 = 1;
  if ( v25 )
  {
    result = KBAlloc(0xFAu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 71);
    *a5 = result;
    v18 = 0;
    v22 = 0;
  }
  if ( v19 )
  {
    result = KBAlloc(0xFAu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 77);
    *a8 = result;
    v24 = 0;
    v20 = 0;
  }
  while ( !v18 || !v22 || !v24 || !v20 )
  {
    yieldToGlobalUpdater();
    if ( getTickCount() > v16 + 90000 )
    {
      display_message_window("Error receiving data.  Keep trying?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        v16 = getTickCount();
      else
        terminate("Game canceled.");
    }
    result = sub_46E3F0(1);
    v26 = result;
    if ( result )
    {
      result = (void *)*((_BYTE *)result + 5);
      if ( result == (void *)2 )
      {
        result = (void *)*((_BYTE *)v26 + 6);
        if ( result == (void *)21 )
        {
          v16 = getTickCount();
          if ( *((_BYTE *)v26 + 9) == 1 )
          {
            memcpy(*a5, (char *)v26 + 10, 0xC8u);
            v18 = 1;
          }
          if ( *((_BYTE *)v26 + 9) == 2 )
          {
            memcpy((char *)*a5 + 200, (char *)v26 + 10, 0x32u);
            v22 = 1;
          }
          if ( *((_BYTE *)v26 + 9) == 3 )
          {
            memcpy(*a8, (char *)v26 + 10, 0xC8u);
            v24 = 1;
          }
          result = (void *)*((_BYTE *)v26 + 9);
          if ( result == (void *)4 )
          {
            result = memcpy((char *)*a8 + 200, (char *)v26 + 10, 0x32u);
            v20 = 1;
          }
        }
      }
    }
  }
  return result;
}
