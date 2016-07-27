{
  void *v3; // [sp+Ch] [bp-24h]@1
  char v4; // [sp+10h] [bp-20h]@22
  int fd; // [sp+18h] [bp-18h]@1
  char v6; // [sp+1Ch] [bp-14h]@5
  int i; // [sp+20h] [bp-10h]@3
  unsigned __int8 buf; // [sp+24h] [bp-Ch]@5
  char v9; // [sp+28h] [bp-8h]@5

  v3 = this;
  sprintf(globBuf, "%s%s", ".\\MAPS\\", a2);
  fd = _open(globBuf, 32768);
  if ( fd == -1 )
    sub_436DF0(globBuf);
  _read(fd, (char *)v3 + 681, 0x1A4u);
  sub_46FE60((int)((char *)v3 + 2878), fd, 1);
  sub_42CD50(*(_DWORD *)((char *)v3 + 2886), *(_DWORD *)((char *)v3 + 2890));
  for ( i = 0; i < 72; ++i )
  {
    _read(fd, &buf, 1u);
    _read(fd, &v6, 1u);
    _read(fd, &v9, 1u);
    if ( buf != 255 )
    {
      *((_BYTE *)v3 + 100 * i + 2953) = 1;
      *((_BYTE *)v3 + 100 * i + 2903) = buf;
      *((_BYTE *)v3 + 100 * i + 2904) = v6;
      *((_BYTE *)v3 + 100 * i + 2902) = v9 & 0x7F;
      if ( v9 >= 0 )
        *(_DWORD *)((char *)v3 + 100 * i + 2923) |= 0x20u;
      else
        *(_DWORD *)((char *)v3 + 100 * i + 2923) |= 0x40u;
    }
  }
  for ( i = 0; i < 144; ++i )
  {
    if ( *(_DWORD *)((char *)v3 + 681) != 90 || i < 72 )
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
    if ( buf != 255 )
    {
      *((_BYTE *)v3 + 7 * i + 23737) = -1;
      *((_BYTE *)v3 + 7 * i + 23739) = buf;
      *((_BYTE *)v3 + 7 * i + 23740) = v6;
      *((_BYTE *)v3 + 7 * i + 23736) = v9;
    }
  }
  *(_DWORD *)((char *)v3 + 681) = 92;
  _read(fd, (char *)v3 + 2898, 1u);
  _read(fd, (char *)v3 + 25817, 2 * *((_BYTE *)v3 + 1099));
  *(_WORD *)((char *)v3 + 25815) = *((_BYTE *)v3 + 1099);
  _read(fd, (char *)v3 + 25879, 2 * *((_BYTE *)v3 + 1100));
  *(_WORD *)((char *)v3 + 25877) = *((_BYTE *)v3 + 1100);
  _read(fd, &dword_5240A4, 4u);
  dword_524784 = KBAlloc(4 * *(_DWORD *)&dword_5240A4, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF3C0 + 89);
  dword_5249EC = KBAlloc(2 * *(_DWORD *)&dword_5240A4, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF3C0 + 90);
  memset(dword_524784, 0, 4 * *(_DWORD *)&dword_5240A4);
  memset(dword_5249EC, 0, 2 * *(_DWORD *)&dword_5240A4);
  for ( i = 1; i < *(_DWORD *)&dword_5240A4; ++i )
  {
    _read(fd, (char *)dword_5249EC + 2 * i, 2u);
    *((_DWORD *)dword_524784 + i) = KBAlloc(
                                      *((_WORD *)dword_5249EC + i),
                                      "F:\\h2xsrc\\Source\\GAME.CPP",
                                      word_4EF3C0 + 98);
    _read(fd, *((void **)dword_524784 + i), *((_WORD *)dword_5249EC + i));
  }
  _read(fd, &v4, 2u);
  _close(fd);
  return 0;
}
