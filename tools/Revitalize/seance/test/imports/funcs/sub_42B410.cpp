{
  int v4; // ST38_4@1
  int v5; // ST38_4@63
  void *thisa; // [sp+Ch] [bp-22Ch]@1
  int i; // [sp+10h] [bp-228h]@18
  void *buf; // [sp+24h] [bp-214h]@7
  void *v10; // [sp+28h] [bp-210h]@3
  void *a1; // [sp+2Ch] [bp-20Ch]@5
  signed int v12; // [sp+34h] [bp-204h]@23
  int fd; // [sp+38h] [bp-200h]@7
  void *v14; // [sp+3Ch] [bp-1FCh]@1
  int j; // [sp+40h] [bp-1F8h]@25
  int k; // [sp+40h] [bp-1F8h]@36
  int l; // [sp+40h] [bp-1F8h]@41
  unsigned __int32 nbytes; // [sp+44h] [bp-1F4h]@5
  signed int v19; // [sp+48h] [bp-1F0h]@1
  int v20; // [sp+4Ch] [bp-1ECh]@1
  int v21; // [sp+50h] [bp-1E8h]@18
  int v22; // [sp+54h] [bp-1E4h]@18
  size_t v23; // [sp+58h] [bp-1E0h]@29
  int v24; // [sp+5Ch] [bp-1DCh]@1
  int track; // [sp+60h] [bp-1D8h]@1
  int v26; // [sp+64h] [bp-1D4h]@10
  char v27; // [sp+6Ch] [bp-1CCh]@5
  int v28; // [sp+230h] [bp-8h]@14
  int v29; // [sp+234h] [bp-4h]@21

  thisa = this;
  sub_456000(advManager, 4);
  v20 = 0;
  v14 = 0;
  v19 = 0;
  v24 = 0;
  track = -1;
  v4 = soundManager->field_688;
  soundManager->field_688 = 1;
  track = soundManager->currentTrack;
  SoundManager::couldBePlayCDTrack(soundManager, -1);
  soundManager->field_688 = v4;
  debugLog("Transmit Game Start");
  if ( advManager->ready == 1 )
    sub_435D20("Sending Data", -1, 0);
  sub_4CAA50("Transmit Start - Compressing");
  v10 = KBAlloc(0x1388u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 43);
  memset(v10, 0, 0x1388u);
  GameInfo::saveGame((GameInfo *)thisa, (const char *)&computerWalkSpeed + 366, 0, 0);
  if ( !byte_526DAC )
    a4 = 1;
  sub_42CFF0((int)byte_5249A1, (int)byte_5249AE, (int)(&computerWalkSpeed + 379), a2, a4);
  sprintf(&v27, "%s%s", ".\\DATA\\", &computerWalkSpeed + 379);
  nbytes = sub_4CADB0(&v27);
  logUpTo7Ints((int)"PostDiffFileSize", nbytes, -999, -999, -999, -999, -999, -999);
  a1 = KBAlloc(0x100u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 63);
  if ( byte_526ED8 )
    v14 = KBAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 65);
  buf = KBAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 66);
  fd = _open(&v27, 32768);
  if ( fd == -1 )
    sub_436DF0(&v27);
  if ( fd != -1 )
  {
    _read(fd, buf, nbytes);
    _close(fd);
    v26 = sub_46DC60((int)buf, nbytes);
    if ( byte_526ED8 )
      nbytes = sub_4D63A0(v14, buf, nbytes);
    else
      v14 = buf;
    sub_4CAA50("Transmit Start - Sending");
    if ( byte_526ED8 )
      v28 = sub_46DC60((int)v14, nbytes);
    else
      v28 = v26;
    logUpTo7Ints((int)"Send", nbytes, v28, -999, -999, -999, -999, -999);
    *(_DWORD *)a1 = nbytes;
    *((_DWORD *)a1 + 1) = v26;
    *((_DWORD *)a1 + 2) = v28;
    *((_DWORD *)a1 + 3) = a3;
    v24 = sub_46EC00(a1, a2, 0x10u, 1, 2, (int)&v20);
    if ( !v24 )
      terminate(0);
    v21 = (signed int)(nbytes - 1) / 200 + 1;
    v22 = (signed int)(nbytes - 1) / 200 / 100 + 1;
    for ( i = 0; i < v22; ++i )
    {
      if ( i + 1 == v22 )
        v29 = v21 - 100 * i;
      else
        v29 = 100;
      v12 = 0;
      while ( !v12 )
      {
        for ( j = 100 * i; v29 + 100 * i > j; ++j )
        {
          yieldToGlobalUpdater();
          sub_4AA7B0(0, 1);
          if ( !*((_BYTE *)v10 + j) )
          {
            if ( j + 1 == v21 )
              v23 = nbytes - 200 * j;
            else
              v23 = 200;
            *(_WORD *)a1 = j;
            memcpy((char *)a1 + 2, (char *)v14 + 200 * j, v23);
            v24 = sub_46E1D0(a1, a2, v23 + 2, 3, 0, 1, -1);
            if ( !v24 )
              terminate(0);
          }
        }
        debugLog("PreWait");
        *(_WORD *)a1 = 100 * i;
        v24 = sub_46EC00(a1, a2, 2u, 4, 5, (int)&v20);
        debugLog("PostWait");
        if ( !v24 )
          terminate(0);
        for ( k = 0; k < v29; ++k )
        {
          if ( (signed int)*(_BYTE *)(k + v20 + 9) > 0 )
            *((_BYTE *)v10 + 100 * i + k) = 1;
        }
        v12 = 1;
        for ( l = 100 * i; v29 + 100 * i > l; ++l )
        {
          if ( !*((_BYTE *)v10 + l) )
            v12 = 0;
        }
      }
    }
    v24 = sub_46E1D0(0, a2, 0, 6, 1, 1, -1);
    if ( !v24 )
      terminate(0);
    v19 = 1;
  }
  if ( a1 )
    KBFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 199);
  if ( v14 )
    KBFree(v14, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 200);
  if ( buf && v14 != buf )
    KBFree(buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 201);
  if ( v10 )
    KBFree(v10, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF6BC + 202);
  sub_4CAA50("Transmit End");
  if ( advManager->ready == 1 )
  {
    dword_52405C = 0;
    sub_44D440(advManager, 1, 1, 1);
  }
  if ( track != -1 )
  {
    v5 = soundManager->field_688;
    soundManager->field_688 = 1;
    SoundManager::couldBePlayCDTrack(soundManager, track);
    soundManager->field_688 = v5;
  }
  return v19;
}
