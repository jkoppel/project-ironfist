{
  int v4; // ST3C_4@3
  int v5; // ST64_4@3
  int v6; // ST48_4@17
  int v7; // ST3C_4@46
  int v9; // [sp+Ch] [bp-210h]@16
  int v10; // [sp+18h] [bp-204h]@7
  void *v11; // [sp+20h] [bp-1FCh]@1
  void *v12; // [sp+24h] [bp-1F8h]@7
  int v13; // [sp+28h] [bp-1F4h]@18
  int v14; // [sp+2Ch] [bp-1F0h]@32
  void *v15; // [sp+30h] [bp-1ECh]@7
  int i; // [sp+34h] [bp-1E8h]@18
  int v17; // [sp+3Ch] [bp-1E0h]@30
  void *v18; // [sp+40h] [bp-1DCh]@13
  void *a1a; // [sp+48h] [bp-1D4h]@5
  int track; // [sp+4Ch] [bp-1D0h]@3
  signed int v21; // [sp+50h] [bp-1CCh]@1
  int v22; // [sp+54h] [bp-1C8h]@29
  char v23; // [sp+58h] [bp-1C4h]@32

  logUpTo7Ints((int)"FW1", a4, -999, -999, -999, -999, -999, -999);
  debugLog("RSG1");
  sub_4CAA50("Receive Start - Getting Data");
  sub_456000(advManager, 4);
  v11 = 0;
  v21 = 0;
  sub_4C2FB0(advManager, 999, 0);
  if ( advManager->ready == 1 )
    sub_435D20("Receiving Data", -1, 0);
  v4 = soundManager->field_688;
  track = soundManager->currentTrack;
  soundManager->field_688 = 1;
  SoundManager::couldBePlayCDTrack(soundManager, -1);
  soundManager->field_688 = v4;
  debugLog("Begin Transmit Init Confirm");
  v5 = sub_46E1D0(0, a4, 0, 2, 1, 1, -1);
  debugLog("End Transmit Init Confirm");
  if ( !v5 )
    terminate(0);
  a1a = KBAlloc(0x1388u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 51);
  memset(a1a, 0, 0x1388u);
  if ( byte_526ED8 )
    v11 = KBAlloc(0xAAE60u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 55);
  v12 = KBAlloc(0x100u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 57);
  v15 = KBAlloc(a1 + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 58);
  v10 = getTickCount();
  logUpTo7Ints((int)"FW2", a4, -999, -999, -999, -999, -999, -999);
  while ( !v21 )
  {
    yieldToGlobalUpdater();
    sub_4AA7B0(0, 1);
    if ( getTickCount() > v10 + 90000 )
    {
      display_message_window("Error receiving data.  Keep trying?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        v10 = getTickCount();
      else
        terminate(0);
    }
    v18 = sub_46E3F0(1);
    if ( v18 && (*((_BYTE *)v18 + 5) == 2 || *((_BYTE *)v18 + 5) == 3) )
    {
      v10 = getTickCount();
      v9 = *((_BYTE *)v18 + 6);
      switch ( v9 )
      {
        case 3:
          v6 = *(_WORD *)((char *)v18 + 9);
          *((_BYTE *)a1a + v6) = 1;
          memcpy((char *)v15 + 200 * v6, (char *)v18 + 11, *(_WORD *)((char *)v18 + 7) - 2);
          break;
        case 4:
          v13 = *(_WORD *)((char *)v18 + 9);
          for ( i = *(_WORD *)((char *)v18 + 9); v13 + 100 > i; ++i )
            *((_BYTE *)v12 + i - v13) = *((_BYTE *)a1a + i);
          logUpTo7Ints((int)"FW3", a4, -999, -999, -999, -999, -999, -999);
          if ( !sub_46E1D0(v12, a4, 0xC8u, 5, 1, 1, -1) )
            terminate(0);
          break;
        case 6:
          v21 = 1;
          break;
      }
    }
  }
  sub_4CAA50("Receive Start - Decompressing Data");
  v22 = sub_46DC60((int)v15, a1);
  logUpTo7Ints((int)"Receive", a1, v22, a3, -999, -999, -999, -999);
  if ( byte_526ED8 )
  {
    a1 = sub_4D6670(v11, v15, a1);
    v17 = sub_46DC60((int)v11, a1);
  }
  else
  {
    v11 = v15;
    v17 = v22;
  }
  logUpTo7Ints((int)"Receive", a1, v17, a2, -999, -999, -999, -999);
  sprintf(&v23, "%s%s", ".\\DATA\\", &computerWalkSpeed + 340);
  v14 = _open(&v23, 33537, 128);
  if ( v14 == -1 )
    sub_436DF0(&v23);
  _write(v14, v11, a1);
  _close(v14);
  if ( a1a )
    KBFree(a1a, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 161);
  if ( v12 )
    KBFree(v12, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 162);
  if ( v15 )
    KBFree(v15, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 163);
  if ( v11 && v15 != v11 )
    KBFree(v11, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 164);
  sub_42D5B0((int)byte_52497A, (int)byte_524994, (int)(&computerWalkSpeed + 327));
  sub_4CAA50("Receive End");
  if ( advManager->ready == 1 )
  {
    dword_52405C = 0;
    sub_44D440(advManager, 1, 1, 1);
  }
  if ( track != -1 )
  {
    v7 = soundManager->field_688;
    soundManager->field_688 = 1;
    SoundManager::couldBePlayCDTrack(soundManager, track);
    soundManager->field_688 = v7;
  }
  return 1;
}
