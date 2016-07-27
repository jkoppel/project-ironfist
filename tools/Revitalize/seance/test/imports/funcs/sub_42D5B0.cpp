{
  int v3; // ST24_4@1
  char v4; // ST40_1@9
  int v5; // eax@15
  int v6; // [sp+10h] [bp-30h]@1
  int v7; // [sp+14h] [bp-2Ch]@1
  void *v8; // [sp+18h] [bp-28h]@3
  __int32 nbytes; // [sp+1Ch] [bp-24h]@1
  int fd; // [sp+20h] [bp-20h]@1
  int fda; // [sp+20h] [bp-20h]@5
  void *buf2; // [sp+24h] [bp-1Ch]@1
  int buf; // [sp+2Ch] [bp-14h]@1
  int v14; // [sp+30h] [bp-10h]@9
  __int32 a1a; // [sp+34h] [bp-Ch]@5
  __int32 v16; // [sp+38h] [bp-8h]@7
  int v17; // [sp+3Ch] [bp-4h]@13

  v3 = a2;
  v6 = a1;
  buf2 = 0;
  v7 = 0;
  sprintf(globBuf, "%s%s", ".\\DATA\\", a2);
  nbytes = sub_4CADB0(globBuf);
  buf = (int)KBAlloc(nbytes, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 13);
  sprintf(globBuf, "%s%s", ".\\DATA\\", v3);
  fd = _open(globBuf, 32768);
  if ( fd == -1 )
    sub_436DF0(globBuf);
  _read(fd, (void *)buf, nbytes);
  _close(fd);
  v8 = KBAlloc(0xAAE60u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 22);
  if ( *(_BYTE *)buf )
  {
    sprintf(globBuf, "%s%s", ".\\DATA\\", v6);
    a1a = sub_4CADB0(globBuf);
    buf2 = KBAlloc(a1a, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 33);
    sprintf(globBuf, "%s%s", ".\\DATA\\", v6);
    fda = _open(globBuf, 32768);
    if ( fda == -1 )
      sub_436DF0(globBuf);
    _read(fda, buf2, a1a);
    _close(fda);
    memcpy(v8, buf2, a1a);
    v16 = 2;
    while ( nbytes > v16 )
    {
      v4 = (signed int)*(_BYTE *)(v16 + buf) >> 7;
      v14 = sub_42CF40(buf, (int)&v16);
      if ( v4 )
      {
        memcpy((char *)v8 + v7, (const void *)(buf + v16), v14);
        v7 += v14;
        v16 += v14;
      }
      else
      {
        v7 += v14;
      }
    }
  }
  else
  {
    memcpy(v8, (const void *)(buf + 2), nbytes - 2);
    v7 = nbytes - 2;
  }
  sprintf(globBuf, "%s%s", ".\\DATA\\", a3);
  v17 = _open(globBuf, 33537, 128);
  if ( v17 == -1 )
    sub_436DF0(globBuf);
  _write(v17, v8, v7);
  _close(v17);
  v5 = sub_46DC60((int)v8, v7);
  logUpTo7Ints((int)"New Join CRC", v5, v7, -999, -999, -999, -999, -999);
  sprintf(globBuf, "%s%s", ".\\DATA\\", v6);
  v17 = _open(globBuf, 33537, 128);
  if ( v17 == -1 )
    sub_436DF0(globBuf);
  _write(v17, v8, v7);
  _close(v17);
  if ( buf2 )
    KBFree(buf2, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 83);
  if ( buf )
    KBFree((void *)buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 85);
  if ( v8 )
    KBFree(v8, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFB9C + 87);
}
