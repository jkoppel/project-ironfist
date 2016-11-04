{
  void *a1; // [sp+Ch] [bp-48h]@1
  void *v1; // [sp+10h] [bp-44h]@1
  int fd; // [sp+1Ch] [bp-38h]@1
  __int32 nbytes; // [sp+20h] [bp-34h]@1
  char v4; // [sp+24h] [bp-30h]@1
  int v5; // [sp+44h] [bp-10h]@3
  void *v6; // [sp+48h] [bp-Ch]@1
  unsigned int v7; // [sp+4Ch] [bp-8h]@3
  size_t v8; // [sp+50h] [bp-4h]@3

  debugLog("C1");
  strcpy(&v4, "c:\\TEMP\\Z.DIF");
  nbytes = sub_4CADB0(&v4);
  a1 = KBAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 9);
  v1 = KBAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 10);
  v6 = KBAlloc(nbytes + 2000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 11);
  debugLog("C2");
  fd = _open(&v4, 32768);
  if ( fd == -1 )
    sub_436DF0(&v4);
  _read(fd, a1, nbytes);
  debugLog("C3");
  v5 = sub_46DC60((int)a1, nbytes);
  debugLog("C4");
  _close(fd);
  debugLog("C5");
  v7 = sub_4D63A0(v1, a1, nbytes);
  debugLog("C6");
  v8 = sub_4D6670(v6, v1, v7);
  debugLog("C7");
  sub_46DC60((int)v6, nbytes);
  sub_46DC60((int)a1, nbytes);
  KBFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 36);
  KBFree(v1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 37);
  KBFree(v6, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFEB4 + 38);
  debugLog("C8");
}
