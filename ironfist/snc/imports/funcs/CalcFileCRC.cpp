{
  int v1; // ST28_4@3
  const char *v3; // [sp+Ch] [bp-14h]@1
  UINT fd; // [sp+10h] [bp-10h]@1
  int nbytes; // [sp+14h] [bp-Ch]@1
  void *a1; // [sp+18h] [bp-8h]@1

  v3 = this;
  nbytes = FileSize(this);
  a1 = BaseAlloc(nbytes, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFDCC + 3);
  fd = open(v3, 32768);
  if ( fd == -1 )
    FileError((void *)v3);
  _read(fd, a1, nbytes);
  v1 = calc_crc_long((int)a1, nbytes);
  _close(fd);
  BaseFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFDCC + 14);
  return v1;
}