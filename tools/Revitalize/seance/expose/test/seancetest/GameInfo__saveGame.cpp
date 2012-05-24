signed int __thiscall GameInfo::saveGame(GameInfo *this, const char *a2, int a3, char a4)
{
  GameInfo *thisa; // [sp+Ch] [bp-438h]@1
  int v6; // [sp+10h] [bp-434h]@30
  int v7; // [sp+14h] [bp-430h]@8
  char v8; // [sp+1Ch] [bp-428h]@29
  char v9; // [sp+98h] [bp-3ACh]@21
  int fd; // [sp+25Ch] [bp-1E8h]@25
  int i; // [sp+260h] [bp-1E4h]@8
  char v12; // [sp+264h] [bp-1E0h]@5
  char v13[8]; // [sp+428h] [bp-1Ch]@37
  char v14; // [sp+430h] [bp-14h]@35
  void *a1; // [sp+434h] [bp-10h]@1
  int v16; // [sp+438h] [bp-Ch]@49
  int v17; // [sp+43Ch] [bp-8h]@49
  int v18; // [sp+440h] [bp-4h]@27

  thisa = this;
  a1 = (void *)KBAlloc(0xC350u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF26C + 10);
  memset(a1, 0, 0xC350u);
  if ( !inExpansion )
    a4 = 1;
  sub_450880(advManager);
  if ( a3 )
  {
    if ( loadOrNewGameSelected )
    {
      sprintf(&v12, "%s.%s", a2, "GMC");
    }
    else
    {
      if ( byte_5304A0 )
      {
        sprintf(&v12, "%s.%s", a2, "GXC");
      }
      else
      {
        v7 = 0;
        for ( i = 0; i < 6; ++i )
        {
          if ( !thisa->couldBePlayerAlive[i] && dword_524810[i] )
            ++v7;
        }
        if ( !inExpansion || a4 )
          sprintf(&v12, "%s.GM%d", a2, v7);
        else
          sprintf(&v12, "%s.GX%d", a2, v7);
      }
    }
  }
  else
  {
    sprintf(&v12, a2);
  }
  if ( _strnicmp((unsigned __int8 *)&v12, (unsigned __int8 *)"RMT", 3) )
  {
    sprintf(&v9, "%s%s", ".\\GAMES\\", &v12);
    if ( _strnicmp((unsigned __int8 *)&v12, (unsigned __int8 *)"AUTOSAVE", 8)
      && _strnicmp((unsigned __int8 *)&v12, (unsigned __int8 *)"PLYREXIT", 8) )
      strcpy((int)&gameObject->_1[325]);
  }
  else
  {
    sprintf(&v9, "%s%s", ".\\DATA\\", &v12);
  }
  fd = _open(&v9, 33537, 128);
  if ( fd == -1 )
    sub_436DF0(&v9);
  v18 = -1;
  if ( !a4 )
    _write(fd, &v18, 4);
  _write(fd, &thisa->map.width, 4);
  _write(fd, &thisa->map.height, 4);
  _write(fd, &thisa->_1[676], 420);
  _write(fd, &thisa->_3[375], 65);
  _write(fd, &dword_52478C, 1);
  _write(fd, thisa, 2);
  _write(fd, &dword_524A74, 1);
  _write(fd, &dword_52343C, 1);
  _write(fd, &dword_523448, 1);
  _write(fd, &dword_523F10, 1);
  _write(fd, dword_5235E0, 126);
  memset(&v8, 0, 0x28u);
  _write(fd, &v8, 36);
  if ( byte_5304A0 )
  {
    v6 = 2;
    _write(fd, &v6, 4);
    _write(fd, &unk_530450, 79);
  }
  else
  {
    _write(fd, &loadOrNewGameSelected, 4);
    if ( loadOrNewGameSelected )
      _write(fd, &thisa->field_2, 327);
  }
  if ( !a4 )
    _write(fd, &inExpansion, 1);
  sub_4C2F30();
  _write(fd, &dword_524A78, 4);
  sub_419DB0(&thisa->_1[325], &v8);
  _write(fd, &v8, 14);
  _write(fd, &thisa->numPlayers, 1);
  v14 = curPlayerIdx;
  _write(fd, &v14, 1);
  _write(fd, &thisa->couldBeNumDefeatedPlayers, 1);
  _write(fd, thisa->couldBePlayerAlive, 6);
  for ( i = 0; i < 6; ++i )
  {
    v13[i] = LOBYTE(dword_524810[i]);
    if ( thisa->couldBePlayerAlive[i] )
      v13[i] = 0;
  }
  _write(fd, v13, 6);
  _write(fd, &thisa->day, 2);
  _write(fd, &thisa->week, 2);
  _write(fd, &thisa->month, 2);
  for ( i = 0; i < 6; ++i )
    sub_418870(&thisa->players[i], fd);
  _write(fd, &thisa->field_B52, 1);
  for ( i = 0; i < 54; ++i )
    Hero::write(&thisa->heroes[i], fd, (unsigned int)a4 < 1);
  _write(fd, thisa->relatedToHeroForHireStatus, 54);
  _write(fd, thisa->castles, 7200);
  _write(fd, thisa->_7, 72);
  _write(fd, &thisa->_7[72], 9);
  _write(fd, thisa->_8, 1008);
  _write(fd, &thisa->_8[1008], 144);
  if ( a4 )
    _write(fd, thisa->probablyArtifactGeneratedRandomly, 82);
  else
    _write(fd, thisa->probablyArtifactGeneratedRandomly, 103);
  _write(fd, &thisa->probablyArtifactGeneratedRandomly[103], 384);
  _write(fd, &thisa->field_6236[231], 48);
  _write(fd, thisa->obeliskVisitedMasks, 48);
  _write(fd, &thisa->_10[24], 1);
  _write(fd, &thisa->_10[25], 1);
  _write(fd, &thisa->_10[26], 1);
  _write(fd, &thisa->_10[45], 301);
  _write(fd, thisa->_10, 24);
  _write(fd, &thisa->_10[346], 4);
  _write(fd, &thisa->_10[348], 2 * *(_WORD *)&thisa->_10[346]);
  _write(fd, &thisa->_10[408], 4);
  _write(fd, &thisa->_10[410], 2 * *(_WORD *)&thisa->_10[408]);
  _write(fd, &thisa->_10[510], 4);
  _write(fd, &thisa->_10[512], 2 * *(_WORD *)&thisa->_10[510]);
  v17 = 1234;
  v16 = 9999;
  _write(fd, &v17, 4);
  _write(fd, &dword_5240A4, 4);
  _write(fd, &v17, 4);
  for ( i = 1; i < *(_DWORD *)&dword_5240A4; ++i )
  {
    _write(fd, &v17, 4);
    _write(fd, (char *)dword_5249EC + 2 * i, 2);
    if ( *((_DWORD *)dword_524784 + i) )
      _write(fd, *((LPCVOID *)dword_524784 + i), *((_WORD *)dword_5249EC + i));
    else
      _write(fd, a1, *((_WORD *)dword_5249EC + i));
  }
  _write(fd, &v17, 4);
  _write(fd, tileExplored, mapHeight * mapWidth);
  _write(fd, &v17, 4);
  MapTiles::save(&thisa->map, fd);
  _write(fd, &v17, 4);
  _close(fd);
  KBFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF26C + 237);
  return 1;
}
