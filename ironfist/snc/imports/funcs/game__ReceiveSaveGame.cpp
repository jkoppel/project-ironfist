{
  int v4; // ST3C_4@3
  int v5; // ST64_4@3
  int v6; // edx@9
  int v7; // ST48_4@17
  int v8; // ST3C_4@46
  int v10; // [sp+Ch] [bp-210h]@16
  int v11; // [sp+18h] [bp-204h]@7
  void *v12; // [sp+20h] [bp-1FCh]@1
  const void *v13; // [sp+24h] [bp-1F8h]@7
  int v14; // [sp+28h] [bp-1F4h]@18
  int v15; // [sp+2Ch] [bp-1F0h]@32
  const void *v16; // [sp+30h] [bp-1ECh]@7
  int i; // [sp+34h] [bp-1E8h]@18
  int v18; // [sp+3Ch] [bp-1E0h]@30
  void *v19; // [sp+40h] [bp-1DCh]@13
  void *a1a; // [sp+48h] [bp-1D4h]@5
  int track; // [sp+4Ch] [bp-1D0h]@3
  signed int v22; // [sp+50h] [bp-1CCh]@1
  int v23; // [sp+54h] [bp-1C8h]@29
  char v24; // [sp+58h] [bp-1C4h]@32

  LogInt((int)"FW1", a4, -999, -999, -999, -999, -999, -999);
  LogStr("RSG1");
  AiPrint("Receive Start - Getting Data");
  advManager::TrimLoopingSounds(gpAdvManager, 4);
  v12 = 0;
  v22 = 0;
  advManager::UnwindMapChangeQueue(gpAdvManager, 999, 0);
  if ( gpAdvManager->ready == 1 )
    BVResMsg("Receiving Data", -1, 0);
  v4 = gpSoundManager->aiMusicOff;
  track = gpSoundManager->currentTrack;
  gpSoundManager->aiMusicOff = 1;
  soundManager::SwitchAmbientMusic(gpSoundManager, -1);
  gpSoundManager->aiMusicOff = v4;
  LogStr("Begin Transmit Init Confirm");
  v5 = TransmitRemoteData(0, a4, 0, 2, 1, 1, -1);
  LogStr("End Transmit Init Confirm");
  if ( !v5 )
    ShutDown(0);
  a1a = BaseAlloc(0x1388u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 51);
  memset(a1a, 0, 0x1388u);
  if ( gbUseRegularCompression )
    v12 = BaseAlloc(0xAAE60u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 55);
  v13 = BaseAlloc(0x100u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 57);
  v16 = BaseAlloc(a1 + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 58);
  v11 = KBTickCount();
  LogInt((int)"FW2", a4, -999, -999, -999, -999, -999, -999);
  while ( !v22 )
  {
    PollSound();
    CheckDoMain(0, 1);
    if ( KBTickCount() > v11 + 90000 )
    {
      NormalDialog("Error receiving data.  Keep trying?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode == 30725 )
        v11 = KBTickCount();
      else
        ShutDown(0);
    }
    v19 = GetRemoteData(1, v6);
    if ( v19 && (*((_BYTE *)v19 + 5) == 2 || *((_BYTE *)v19 + 5) == 3) )
    {
      v11 = KBTickCount();
      v10 = *((_BYTE *)v19 + 6);
      switch ( v10 )
      {
        case 3:
          v7 = *(_WORD *)((char *)v19 + 9);
          *((_BYTE *)a1a + v7) = 1;
          memcpy((char *)v16 + 200 * v7, (char *)v19 + 11, *(_WORD *)((char *)v19 + 7) - 2);
          break;
        case 4:
          v14 = *(_WORD *)((char *)v19 + 9);
          for ( i = *(_WORD *)((char *)v19 + 9); v14 + 100 > i; ++i )
            *((char *)v13 + i - v14) = *((_BYTE *)a1a + i);
          LogInt((int)"FW3", a4, -999, -999, -999, -999, -999, -999);
          if ( !TransmitRemoteData(v13, a4, 0xC8u, 5, 1, 1, -1) )
            ShutDown(0);
          break;
        case 6:
          v22 = 1;
          break;
      }
    }
  }
  AiPrint("Receive Start - Decompressing Data");
  v23 = calc_crc_long((int)v16, a1);
  LogInt((int)"Receive", a1, v23, a3, -999, -999, -999, -999);
  if ( gbUseRegularCompression )
  {
    a1 = DecodeData(v12, v16, a1);
    v18 = calc_crc_long((int)v12, a1);
  }
  else
  {
    v12 = (void *)v16;
    v18 = v23;
  }
  LogInt((int)"Receive", a1, v18, a2, -999, -999, -999, -999);
  sprintf(&v24, "%s%s", ".\\DATA\\", &gConfig + 340);
  v15 = open(&v24, 33537, 128);
  if ( v15 == -1 )
    FileError(&v24);
  _write(v15, v12, a1);
  _close(v15);
  if ( a1a )
    BaseFree(a1a, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 161);
  if ( v13 )
    BaseFree((void *)v13, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 162);
  if ( v16 )
    BaseFree((void *)v16, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 163);
  if ( v12 && v16 != v12 )
    BaseFree(v12, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF850 + 164);
  CreateJoinFile((int)byte_52497A, (int)byte_524994, (int)(&gConfig + 327));
  AiPrint("Receive End");
  if ( gpAdvManager->ready == 1 )
  {
    giBottomViewOverride = 0;
    advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
  }
  if ( track != -1 )
  {
    v8 = gpSoundManager->aiMusicOff;
    gpSoundManager->aiMusicOff = 1;
    soundManager::SwitchAmbientMusic(gpSoundManager, track);
    gpSoundManager->aiMusicOff = v8;
  }
  return 1;
}