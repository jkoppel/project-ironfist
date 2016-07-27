{
  int v5; // eax@7
  int v6; // ecx@11
  int v7; // [sp+Ch] [bp-44h]@1
  int v8; // [sp+10h] [bp-40h]@1
  __int32 nbytes; // [sp+14h] [bp-3Ch]@5
  void *buf; // [sp+18h] [bp-38h]@5
  int v11; // [sp+20h] [bp-30h]@8
  signed int i; // [sp+28h] [bp-28h]@20
  void *buf2; // [sp+2Ch] [bp-24h]@1
  unsigned int v14; // [sp+30h] [bp-20h]@1
  int fd; // [sp+34h] [bp-1Ch]@5
  size_t v16; // [sp+38h] [bp-18h]@15
  void *v17; // [sp+3Ch] [bp-14h]@1
  int a1a; // [sp+40h] [bp-10h]@1
  int v19; // [sp+44h] [bp-Ch]@1
  int v20; // [sp+48h] [bp-8h]@36
  int v21; // [sp+4Ch] [bp-4h]@15

  v7 = a2;
  v8 = a1;
  getTickCount();
  buf2 = 0;
  v17 = 0;
  a1a = 0;
  v14 = 0;
  v19 = 0;
  if ( a5 || dword_4F31B8 != -1 && dword_4F31B8 != a4 )
    v19 = 1;
  dword_4F31B8 = a4;
  sprintf(globBuf, "%s%s", ".\\DATA\\", v7);
  nbytes = sub_4CADB0(globBuf);
  buf = KBAlloc(nbytes, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 24);
  sprintf(globBuf, "%s%s", ".\\DATA\\", v7);
  fd = _open(globBuf, 32768);
  if ( fd == -1 )
    sub_436DF0(globBuf);
  _read(fd, buf, nbytes);
  _close(fd);
  v5 = sub_46DC60((int)buf, nbytes);
  logUpTo7Ints((int)"Orig Join CRC", v5, nbytes, -999, -999, -999, -999, -999);
  if ( !a5 )
  {
    sprintf(globBuf, "%s%s", ".\\DATA\\", v8);
    a1a = sub_4CADB0(globBuf);
    buf2 = KBAlloc(a1a, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 45);
    sprintf(globBuf, "%s%s", ".\\DATA\\", v8);
    v11 = _open(globBuf, 32768);
    if ( v11 == -1 )
      sub_436DF0(globBuf);
    _read(v11, buf2, a1a);
    _close(v11);
  }
  v6 = a1a;
  if ( a1a <= nbytes )
    v6 = nbytes;
  v17 = KBAlloc(v6 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 55);
  if ( v19 )
  {
    *(_BYTE *)v17 = 0;
    *((_BYTE *)v17 + 1) = 0;
    memcpy((char *)v17 + 2, buf, nbytes);
    v14 = nbytes + 2;
  }
  else
  {
    *(_BYTE *)v17 = 1;
    *((_BYTE *)v17 + 1) = 0;
    v14 = 2;
    v21 = 0;
    v16 = 0;
    while ( (signed int)(v16 + v21) < a1a && (signed int)(v16 + v21) < nbytes )
    {
      if ( *((_BYTE *)buf2 + v16 + v21) == *((_BYTE *)buf + v16 + v21) )
      {
        for ( i = 1;
              (signed int)(v16 + i + v21) < a1a
           && (signed int)(v16 + i + v21) < nbytes
           && *((_BYTE *)buf2 + v16 + i + v21) == *((_BYTE *)buf + v16 + i + v21);
              ++i )
          ;
        if ( i > 3 )
        {
          if ( v16 )
          {
            sub_42CE40(1, v16, (int)v17, (int)&v14);
            memcpy((char *)v17 + v14, (char *)buf + v21, v16);
            v14 += v16;
            v21 += v16;
            v16 = 0;
          }
          sub_42CE40(0, i, (int)v17, (int)&v14);
          v21 += i;
        }
        else
        {
          v16 += i;
        }
      }
      else
      {
        while ( (signed int)(v16 + v21) < a1a
             && (signed int)(v16 + v21) < nbytes
             && *((_BYTE *)buf2 + v16 + v21) != *((_BYTE *)buf + v16 + v21) )
          ++v16;
      }
    }
    v16 = a1a - v21;
    sub_42CE40(1, a1a - v21, (int)v17, (int)&v14);
    memcpy((char *)v17 + v14, (char *)buf + v21, v16);
    v14 += v16;
    v21 += v16;
    v16 = 0;
  }
  sprintf(globBuf, "%s%s", ".\\DATA\\", a3);
  v20 = _open(globBuf, 33537, 128);
  if ( v20 == -1 )
    sub_436DF0(globBuf);
  _write(v20, v17, v14);
  _close(v20);
  sprintf(globBuf, "%s%s", ".\\DATA\\", v8);
  v20 = _open(globBuf, 33537, 128);
  if ( v20 == -1 )
    sub_436DF0(globBuf);
  _write(v20, buf, nbytes);
  _close(v20);
  if ( buf2 )
    KBFree(buf2, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 161);
  if ( buf )
    KBFree(buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 163);
  if ( v17 )
    KBFree(v17, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 165);
}
