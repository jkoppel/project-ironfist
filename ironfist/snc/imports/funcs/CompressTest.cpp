{
  void *a1; // [sp+Ch] [bp-48h]@1
  void *v1; // [sp+10h] [bp-44h]@1
  UINT fd; // [sp+1Ch] [bp-38h]@1
  int nbytes; // [sp+20h] [bp-34h]@1
  char v4; // [sp+24h] [bp-30h]@1
  int v5; // [sp+44h] [bp-10h]@3
  void *v6; // [sp+48h] [bp-Ch]@1
  int v7; // [sp+4Ch] [bp-8h]@3
  int v8; // [sp+50h] [bp-4h]@3

  LogStr("C1");
  strcpy(&v4, "c:\\TEMP\\Z.DIF");
  nbytes = FileSize(&v4);
  a1 = BaseAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 9);
  v1 = BaseAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 10);
  v6 = BaseAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 11);
  LogStr("C2");
  fd = open(&v4, 32768);
  if ( fd == -1 )
    FileError(&v4);
  _read(fd, a1, nbytes);
  LogStr("C3");
  v5 = calc_crc_long((int)a1, nbytes);
  LogStr("C4");
  _close(fd);
  LogStr("C5");
  v7 = EncodeData(v1, a1, nbytes);
  LogStr("C6");
  v8 = DecodeData(v6, v1, v7);
  LogStr("C7");
  calc_crc_long((int)v6, nbytes);
  calc_crc_long((int)a1, nbytes);
  BaseFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 36);
  BaseFree(v1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 37);
  BaseFree(v6, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 38);
  LogStr("C8");
}