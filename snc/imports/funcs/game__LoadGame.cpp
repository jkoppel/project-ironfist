{
  char v5; // [sp+10h] [bp-244h]@11
  char v6[12]; // [sp+3Ch] [bp-218h]@19
  int v7; // [sp+48h] [bp-20Ch]@11
  char v8; // [sp+4Ch] [bp-208h]@5
  char expansion[4]; // [sp+210h] [bp-44h]@9
  int fd; // [sp+214h] [bp-40h]@7
  int i; // [sp+240h] [bp-14h]@19
  char v12; // [sp+244h] [bp-10h]@19
  char v13; // [sp+248h] [bp-Ch]@45
  int v14; // [sp+24Ch] [bp-8h]@3
  int buf; // [sp+250h] [bp-4h]@9

  LogStr("LG1");
  if ( a3 )
  {
    game::SetupOrigData(this);
  }
  else
  {
    LogStr("LG2");
    v14 = 0;
    gbGameOver = 0;
    HIBYTE(this->field_660D) = 1;
    if ( strnicmp((unsigned __int8 *)a2, (unsigned __int8 *)"RMT", 3) )
      sprintf(&v8, "%s%s", ".\\GAMES\\", a2);
    else
      sprintf(&v8, "%s%s", ".\\DATA\\", a2);
    fd = open(&v8, 32768);
    if ( fd == -1 )
      FileError(&v8);
    ClearMapExtra();
    expansion[0] = 0;
    _read(fd, &buf, 4u);
    if ( buf == -1 )
    {
      expansion[0] = 1;
      _read(fd, &buf, 4u);
    }
    _read(fd, &v7, 4u);
    game::SetMapSize(buf, v7);
    _read(fd, &this->_1[676], 0x1A4u);
    _read(fd, &this->_3[375], 0x41u);
    _read(fd, &gbIAmGreatest, 1u);
    _read(fd, this, 2u);
    _read(fd, &giMonthType, 1u);
    _read(fd, &giMonthTypeExtra, 1u);
    _read(fd, &giWeekType, 1u);
    _read(fd, &giWeekTypeExtra, 1u);
    _read(fd, cPlayerNames, 0x7Eu);
    _read(fd, &v5, 0x24u);
    _read(fd, &gbInCampaign, 4u);
    if ( gbInCampaign == 1 )
    {
      _read(fd, &this->field_2, 0x147u);
    }
    else if ( gbInCampaign == 2 )
    {
      xIsPlayingExpansionCampaign = 1;
      gbInCampaign = 0;
      _read(fd, &xCampaign, 0x4Fu);
    }
    if ( expansion[0] )
      _read(fd, &xIsExpansionMap, 1u);
    advManager::PurgeMapChangeQueue();
    _read(fd, &giMapChangeCtr, 4u);
    _read(fd, &v5, 0xEu);
    if ( strnicmp((unsigned __int8 *)a2, (unsigned __int8 *)"RMT", 3) )
      sprintf(&gpGame->_1[325], a2);
    _read(fd, &this->numPlayers, 1u);
    _read(fd, &v12, 1u);
    giCurPlayer = v12;
    _read(fd, &this->couldBeNumDefeatedPlayers, 1u);
    _read(fd, this->couldBePlayerAlive, 6u);
    _read(fd, v6, 6u);
    for ( i = 0; i < 6; ++i )
    {
      if ( v6[i] && v14 < iLastMsgNumHumanPlayers )
      {
        ++v14;
        gbHumanPlayer[i] = 1;
      }
      else
      {
        gbHumanPlayer[i] = 0;
      }
    }
    for ( i = 0; i < 6; ++i )
    {
      if ( gbHumanPlayer[i] )
        *(&gbThisNetHumanPlayer + i) = !gbRemoteOn || i == giThisGamePos;
      else
        *(&gbThisNetHumanPlayer + i) = 0;
    }
    _read(fd, &this->day, 2u);
    _read(fd, &this->week, 2u);
    _read(fd, &this->month, 2u);
    giCurTurn = this->day + 7 * (this->week - 1) + 28 * (this->month - 1);
    for ( i = 0; i < 6; ++i )
      playerData::Read(&this->players[i], fd);
    _read(fd, &this->numObelisks, 1u);
    for ( i = 0; i < 54; ++i )
      hero::Read(&this->heroes[i], fd, expansion[0]);
    _read(fd, this->relatedToHeroForHireStatus, 0x36u);
    _read(fd, this->castles, 0x1C20u);
    _read(fd, this->_7, 0x48u);
    _read(fd, &this->_7[72], 9u);
    _read(fd, this->_8, 0x3F0u);
    _read(fd, &this->_8[1008], 0x90u);
    if ( expansion[0] )
      _read(fd, this->probablyArtifactGeneratedRandomly, 0x67u);
    else
      _read(fd, this->probablyArtifactGeneratedRandomly, 0x52u);
    _read(fd, &this->probablyArtifactGeneratedRandomly[103], 0x180u);
    _read(fd, &this->field_6236[231], 0x30u);
    _read(fd, this->obeliskVisitedMasks, 0x30u);
    _read(fd, &this->_10[24], 1u);
    _read(fd, &this->_10[25], 1u);
    _read(fd, &this->_10[26], 1u);
    _read(fd, &this->_10[45], 0x12Du);
    _read(fd, this->_10, 0x18u);
    _read(fd, &this->_10[346], 4u);
    _read(fd, &this->_10[348], 2 * *(_WORD *)&this->_10[346]);
    _read(fd, &this->_10[408], 4u);
    _read(fd, &this->_10[410], 2 * *(_WORD *)&this->_10[408]);
    _read(fd, &this->_10[510], 4u);
    _read(fd, &this->_10[512], 2 * *(_WORD *)&this->_10[510]);
    _read(fd, &v13, 4u);
    _read(fd, &iMaxMapExtra, 4u);
    _read(fd, &v13, 4u);
    ppMapExtra = BaseAlloc(4 * *(_DWORD *)&iMaxMapExtra, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF318 + 203);
    pwSizeOfMapExtra = BaseAlloc(2 * *(_DWORD *)&iMaxMapExtra, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF318 + 204);
    memset(ppMapExtra, 0, 4 * *(_DWORD *)&iMaxMapExtra);
    memset(pwSizeOfMapExtra, 0, 2 * *(_DWORD *)&iMaxMapExtra);
    for ( i = 1; i < *(_DWORD *)&iMaxMapExtra; ++i )
    {
      _read(fd, &v13, 4u);
      _read(fd, (char *)pwSizeOfMapExtra + 2 * i, 2u);
      *((_DWORD *)ppMapExtra + i) = BaseAlloc(
                                      *((_WORD *)pwSizeOfMapExtra + i),
                                      "F:\\h2xsrc\\Source\\GAME.CPP",
                                      word_4EF318 + 213);
      _read(fd, *((void **)ppMapExtra + i), *((_WORD *)pwSizeOfMapExtra + i));
    }
    _read(fd, &v13, 4u);
    _read(fd, mapExtra, MAP_HEIGHT * MAP_WIDTH);
    _read(fd, &v13, 4u);
    fullMap::Read(&this->map, fd, 0);
    _read(fd, &v13, 4u);
    _close(fd);
    gpAdvManager->field_2A6 = 0;
    gpCurPlayer = &gpGame->players[giCurPlayer];
    giCurPlayerBit = 1 << giCurPlayer;
    for ( giCurWatchPlayer = giCurPlayer;
          !*(&gbThisNetHumanPlayer + giCurWatchPlayer);
          giCurWatchPlayer = (giCurWatchPlayer + 1) % this->numPlayers )
      ;
    giCurWatchPlayerBit = 1 << giCurWatchPlayer;
    bShowIt = *(&gbThisNetHumanPlayer + giCurPlayer);
    game::SetupAdjacentMons();
    LogStr("LG3");
    advManager::CheckSetEvilInterface(gpAdvManager, 0, -1);
  }
}