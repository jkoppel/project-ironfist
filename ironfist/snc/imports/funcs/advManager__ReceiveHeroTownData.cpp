{
  void *result; // eax@9
  int v16; // edx@17
  int v17; // [sp+10h] [bp-2Ch]@9
  int v18; // [sp+14h] [bp-28h]@3
  signed int v19; // [sp+18h] [bp-24h]@9
  int v20; // [sp+1Ch] [bp-20h]@1
  signed int v21; // [sp+20h] [bp-1Ch]@9
  int v22; // [sp+28h] [bp-14h]@1
  signed int v23; // [sp+2Ch] [bp-10h]@9
  int v24; // [sp+30h] [bp-Ch]@1
  signed int v25; // [sp+34h] [bp-8h]@9
  int v26; // [sp+38h] [bp-4h]@1
  void *v27; // [sp+44h] [bp+8h]@21

  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  *a8 = 0;
  *a9 = 0;
  *(_DWORD *)a2 = *(_BYTE *)a1;
  *(_DWORD *)a3 = *(_BYTE *)(a1 + 10);
  *(_DWORD *)a4 = *(_BYTE *)(a1 + 11);
  v26 = *(_BYTE *)(a1 + 12);
  v22 = *(_BYTE *)(a1 + 13);
  v20 = *(_BYTE *)(a1 + 14);
  *(_DWORD *)a10 = *(_BYTE *)(a1 + 15);
  *(_DWORD *)a11 = *(_BYTE *)(a1 + 16);
  *(_DWORD *)a12 = *(_DWORD *)(a1 + 17);
  *(_BYTE *)a13 = *(_BYTE *)(a1 + 21);
  *(_BYTE *)a14 = *(_BYTE *)(a1 + 22);
  *(_BYTE *)a15 = *(_BYTE *)(a1 + 23);
  v24 = *(_BYTE *)(a1 + 24);
  if ( v24 > 0 )
    gpGame->players[v24].resources[6] = *(_DWORD *)(a1 + 25);
  v18 = *(_BYTE *)(a1 + 29);
  if ( v18 > 0 )
    gpGame->players[v18].resources[6] = *(_DWORD *)(a1 + 30);
  *a6 = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 38);
  memcpy(*a6, (const void *)(a1 + 34), 0xFu);
  *a9 = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 41);
  memcpy(*a9, (const void *)(a1 + 49), 0xFu);
  if ( v22 )
  {
    *a7 = BaseAlloc(0x64u, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 46);
    memcpy(*a7, (const void *)(a1 + 64), 0x64u);
  }
  iCombatControlNetPos = *(_DWORD *)a2;
  dword_523434 = giThisNetPos;
  if ( !TransmitRemoteData(0, *(_DWORD *)a2, 0, 22, 1, 1, -1) )
    ShutDown(0);
  result = (void *)KBTickCount();
  v17 = (int)result;
  v19 = 1;
  v23 = 1;
  v25 = 1;
  v21 = 1;
  if ( v26 )
  {
    result = BaseAlloc(0xFAu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 71);
    *a5 = result;
    v19 = 0;
    v23 = 0;
  }
  if ( v20 )
  {
    result = BaseAlloc(0xFAu, "F:\\h2xsrc\\Source\\EVENTS.CPP", word_518CF8 + 77);
    *a8 = result;
    v25 = 0;
    v21 = 0;
  }
  while ( !v19 || !v23 || !v25 || !v21 )
  {
    PollSound();
    if ( KBTickCount() > v17 + 90000 )
    {
      NormalDialog("Error receiving data.  Keep trying?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode == 30725 )
        v17 = KBTickCount();
      else
        ShutDown("Game canceled.");
    }
    result = GetRemoteData(1, v16);
    v27 = result;
    if ( result )
    {
      result = (void *)*((_BYTE *)result + 5);
      if ( result == (void *)2 )
      {
        result = (void *)*((_BYTE *)v27 + 6);
        if ( result == (void *)21 )
        {
          v17 = KBTickCount();
          if ( *((_BYTE *)v27 + 9) == 1 )
          {
            memcpy(*a5, (char *)v27 + 10, 0xC8u);
            v19 = 1;
          }
          if ( *((_BYTE *)v27 + 9) == 2 )
          {
            memcpy((char *)*a5 + 200, (char *)v27 + 10, 0x32u);
            v23 = 1;
          }
          if ( *((_BYTE *)v27 + 9) == 3 )
          {
            memcpy(*a8, (char *)v27 + 10, 0xC8u);
            v25 = 1;
          }
          result = (void *)*((_BYTE *)v27 + 9);
          if ( result == (void *)4 )
          {
            result = memcpy((char *)*a8 + 200, (char *)v27 + 10, 0x32u);
            v21 = 1;
          }
        }
      }
    }
  }
  return result;
}