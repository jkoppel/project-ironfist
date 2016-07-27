{
  int v1; // ST28_4@3
  const char *v3; // [sp+Ch] [bp-14h]@1
  int fd; // [sp+10h] [bp-10h]@1
  __int32 nbytes; // [sp+14h] [bp-Ch]@1
  void *a1; // [sp+18h] [bp-8h]@1

  v3 = this;
  nbytes = sub_4CADB0(this);
  a1 = KBAlloc(nbytes, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFDCC + 3);
  fd = _open(v3, 32768);
  if ( fd == -1 )
    sub_436DF0((void *)v3);
  _read(fd, a1, nbytes);
  v1 = sub_46DC60((int)a1, nbytes);
  _close(fd);
  KBFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFDCC + 14);
  return v1;
}
