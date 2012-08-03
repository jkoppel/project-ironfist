void __thiscall GameInfo::loadGame(GameInfo *this, const char *a2, int a3, int a4)
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

  debugLog("LG1");
  if ( a3 )
  {
    sub_41AAA0(this);
  }
  else
  {
    debugLog("LG2");
    v14 = 0;
    dword_4EF268 = 0;
    HIBYTE(this->field_660D) = 1;
    if ( _strnicmp((unsigned __int8 *)a2, (unsigned __int8 *)"RMT", 3) )
      sprintf(&v8, "%s%s", ".\\GAMES\\", a2);
    else
      sprintf(&v8, "%s%s", ".\\DATA\\", a2);
    fd = _open(&v8, 32768);
    if ( fd == -1 )
      sub_436DF0(&v8);
    sub_4356E0();
    expansion[0] = 0;
    _read(fd, &buf, 4u);
    if ( buf == -1 )
    {
      expansion[0] = 1;
      _read(fd, &buf, 4u);
    }
    _read(fd, &v7, 4u);
    sub_42CD50(buf, v7);
    _read(fd, &this->_1[676], 0x1A4u);
    _read(fd, &this->_3[375], 0x41u);
    _read(fd, &dword_52478C, 1u);
    _read(fd, this, 2u);
    _read(fd, &dword_524A74, 1u);
    _read(fd, &dword_52343C, 1u);
    _read(fd, &dword_523448, 1u);
    _read(fd, &dword_523F10, 1u);
    _read(fd, dword_5235E0, 0x7Eu);
    _read(fd, &v5, 0x24u);
    _read(fd, &loadOrNewGameSelected, 4u);
    if ( loadOrNewGameSelected == 1 )
    {
      _read(fd, &this->field_2, 0x147u);
    }
    else
    {
      if ( loadOrNewGameSelected == 2 )
      {
        byte_5304A0 = 1;
        loadOrNewGameSelected = 0;
        _read(fd, &unk_530450, 0x4Fu);
      }
    }
    if ( expansion[0] )
      _read(fd, &inExpansion, 1u);
    sub_4C2F30();
    _read(fd, &dword_524A78, 4u);
    _read(fd, &v5, 0xEu);
    if ( _strnicmp((unsigned __int8 *)a2, (unsigned __int8 *)"RMT", 3) )
      sprintf(&gameObject->_1[325], a2);
    _read(fd, &this->numPlayers, 1u);
    _read(fd, &v12, 1u);
    curPlayerIdx = v12;
    _read(fd, &this->couldBeNumDefeatedPlayers, 1u);
    _read(fd, this->couldBePlayerAlive, 6u);
    _read(fd, v6, 6u);
    for ( i = 0; i < 6; ++i )
    {
      if ( v6[i] && v14 < dword_5235D4 )
      {
        ++v14;
        dword_524810[i] = 1;
      }
      else
      {
        dword_524810[i] = 0;
      }
    }
    for ( i = 0; i < 6; ++i )
    {
      if ( dword_524810[i] )
        *(&byte_524758 + i) = !dword_4F7494 || i == dword_524730;
      else
        *(&byte_524758 + i) = 0;
    }
    _read(fd, &this->day, 2u);
    _read(fd, &this->week, 2u);
    _read(fd, &this->month, 2u);
    dword_532C54 = this->day + 7 * (this->week - 1) + 28 * (this->month - 1);
    for ( i = 0; i < 6; ++i )
      sub_418AB0(&this->players[i], fd);
    _read(fd, &this->field_B52, 1u);
    for ( i = 0; i < 54; ++i )
      Hero::read(&this->heroes[i], fd, expansion[0]);
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
    _read(fd, &dword_5240A4, 4u);
    _read(fd, &v13, 4u);
    dword_524784 = (void *)KBAlloc(4 * *(_DWORD *)&dword_5240A4, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF318 + 203);
    dword_5249EC = (void *)KBAlloc(2 * *(_DWORD *)&dword_5240A4, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF318 + 204);
    memset(dword_524784, 0, 4 * *(_DWORD *)&dword_5240A4);
    memset(dword_5249EC, 0, 2 * *(_DWORD *)&dword_5240A4);
    for ( i = 1; i < *(_DWORD *)&dword_5240A4; ++i )
    {
      _read(fd, &v13, 4u);
      _read(fd, (char *)dword_5249EC + 2 * i, 2u);
      *((_DWORD *)dword_524784 + i) = KBAlloc(
                                        *((_WORD *)dword_5249EC + i),
                                        "F:\\h2xsrc\\Source\\GAME.CPP",
                                        word_4EF318 + 213);
      _read(fd, *((void **)dword_524784 + i), *((_WORD *)dword_5249EC + i));
    }
    _read(fd, &v13, 4u);
    _read(fd, tileExplored, mapHeight * mapWidth);
    _read(fd, &v13, 4u);
    MapTiles::load(&this->map, fd, 0);
    _read(fd, &v13, 4u);
    _close(fd);
    advManager->field_2A6 = 0;
    curPlayer = &gameObject->players[curPlayerIdx];
    byte_532C5C = 1 << curPlayerIdx;
    for ( dword_523EDC = curPlayerIdx; !*(&byte_524758 + dword_523EDC); dword_523EDC = (dword_523EDC + 1)
                                                                                     % this->numPlayers )
      ;
    byte_5306F0 = 1 << dword_523EDC;
    dword_524C14 = *(&byte_524758 + curPlayerIdx);
    sub_4292B0();
    debugLog("LG3");
    sub_444550(advManager, 0, -1);
  }
}
