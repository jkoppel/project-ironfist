{
  int v5; // eax@7
  int v6; // ecx@11
  int v7; // [sp+Ch] [bp-44h]@1
  int v8; // [sp+10h] [bp-40h]@1
  signed int nbytes; // [sp+14h] [bp-3Ch]@5
  void *buf; // [sp+18h] [bp-38h]@5
  UINT v11; // [sp+20h] [bp-30h]@8
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
  KBTickCount();
  buf2 = 0;
  v17 = 0;
  a1a = 0;
  v14 = 0;
  v19 = 0;
  if ( a5 || iLastDiffSendTo != -1 && iLastDiffSendTo != a4 )
    v19 = 1;
  iLastDiffSendTo = a4;
  sprintf(gText, "%s%s", ".\\DATA\\", v7);
  nbytes = FileSize(gText);
  buf = BaseAlloc(nbytes, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 24);
  sprintf(gText, "%s%s", ".\\DATA\\", v7);
  fd = open(gText, 32768);
  if ( fd == -1 )
    FileError(gText);
  _read(fd, buf, nbytes);
  _close(fd);
  v5 = calc_crc_long((int)buf, nbytes);
  LogInt((int)"Orig Join CRC", v5, nbytes, -999, -999, -999, -999, -999);
  if ( !a5 )
  {
    sprintf(gText, "%s%s", ".\\DATA\\", v8);
    a1a = FileSize(gText);
    buf2 = BaseAlloc(a1a, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 45);
    sprintf(gText, "%s%s", ".\\DATA\\", v8);
    v11 = open(gText, 32768);
    if ( v11 == -1 )
      FileError(gText);
    _read(v11, buf2, a1a);
    _close(v11);
  }
  v6 = a1a;
  if ( a1a <= nbytes )
    v6 = nbytes;
  v17 = BaseAlloc(v6 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 55);
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
            WriteDiffHeaderInfo(1, v16, (int)v17, (int)&v14);
            memcpy((char *)v17 + v14, (char *)buf + v21, v16);
            v14 += v16;
            v21 += v16;
            v16 = 0;
          }
          WriteDiffHeaderInfo(0, i, (int)v17, (int)&v14);
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
    WriteDiffHeaderInfo(1, a1a - v21, (int)v17, (int)&v14);
    memcpy((char *)v17 + v14, (char *)buf + v21, v16);
    v14 += v16;
    v21 += v16;
    v16 = 0;
  }
  sprintf(gText, "%s%s", ".\\DATA\\", a3);
  v20 = open(gText, 33537, 128);
  if ( v20 == -1 )
    FileError(gText);
  _write(v20, v17, v14);
  _close(v20);
  sprintf(gText, "%s%s", ".\\DATA\\", v8);
  v20 = open(gText, 33537, 128);
  if ( v20 == -1 )
    FileError(gText);
  _write(v20, buf, nbytes);
  _close(v20);
  if ( buf2 )
    BaseFree(buf2, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 161);
  if ( buf )
    BaseFree(buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 163);
  if ( v17 )
    BaseFree(v17, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA80 + 165);
}