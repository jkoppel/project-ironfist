{
  char v4; // [sp+10h] [bp-20h]@22
  int fd; // [sp+18h] [bp-18h]@1
  char v6; // [sp+1Ch] [bp-14h]@5
  int i; // [sp+20h] [bp-10h]@3
  char buf; // [sp+24h] [bp-Ch]@5
  char v9; // [sp+28h] [bp-8h]@5

  sprintf(gText, "%s%s", ".\\MAPS\\", a2);
  fd = open(gText, 32768);
  if ( fd == -1 )
    FileError(gText);
  _read(fd, &this->_1[676], 0x1A4u);
  fullMap::Read(&this->map, fd, 1);
  game::SetMapSize(this->map.width, this->map.height);
  for ( i = 0; i < 72; ++i )
  {
    _read(fd, &buf, 1u);
    _read(fd, &v6, 1u);
    _read(fd, &v9, 1u);
    if ( (unsigned __int8)buf != 255 )
    {
      this->castles[i].field_36 = 1;
      this->castles[i].field_4 = buf;
      this->castles[i].field_5 = v6;
      this->castles[i].factionID = v9 & 0x7F;
      if ( v9 >= 0 )
        this->castles[i].buildingsBuiltFlags |= 0x20u;
      else
        this->castles[i].buildingsBuiltFlags |= 0x40u;
    }
  }
  for ( i = 0; i < 144; ++i )
  {
    if ( *(_DWORD *)&this->_1[676] != 90 || i < 72 )
    {
      _read(fd, &buf, 1u);
      _read(fd, &v6, 1u);
      _read(fd, &v9, 1u);
    }
    else
    {
      buf = -1;
      v6 = -1;
      v9 = -1;
    }
    if ( (unsigned __int8)buf != 255 )
    {
      this->_8[7 * i + 3] = -1;
      this->_8[7 * i + 5] = buf;
      this->_8[7 * i + 6] = v6;
      this->_8[7 * i + 2] = v9;
    }
  }
  *(_DWORD *)&this->_1[676] = 92;
  _read(fd, &this->numObelisks, 1u);
  _read(fd, &this->_10[348], 2 * this->_3[373]);
  *(_WORD *)&this->_10[346] = this->_3[373];
  _read(fd, &this->_10[410], 2 * this->_3[374]);
  *(_WORD *)&this->_10[408] = this->_3[374];
  _read(fd, &iMaxMapExtra, 4u);
  ppMapExtra = BaseAlloc(4 * *(_DWORD *)&iMaxMapExtra, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF3C0 + 89);
  pwSizeOfMapExtra = BaseAlloc(2 * *(_DWORD *)&iMaxMapExtra, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF3C0 + 90);
  memset(ppMapExtra, 0, 4 * *(_DWORD *)&iMaxMapExtra);
  memset(pwSizeOfMapExtra, 0, 2 * *(_DWORD *)&iMaxMapExtra);
  for ( i = 1; i < *(_DWORD *)&iMaxMapExtra; ++i )
  {
    _read(fd, (char *)pwSizeOfMapExtra + 2 * i, 2u);
    *((_DWORD *)ppMapExtra + i) = BaseAlloc(
                                    *((_WORD *)pwSizeOfMapExtra + i),
                                    "F:\\h2xsrc\\Source\\GAME.CPP",
                                    word_4EF3C0 + 98);
    _read(fd, *((void **)ppMapExtra + i), *((_WORD *)pwSizeOfMapExtra + i));
  }
  _read(fd, &v4, 2u);
  _close(fd);
  return 0;
}