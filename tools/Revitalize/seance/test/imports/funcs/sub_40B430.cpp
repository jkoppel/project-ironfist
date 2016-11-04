{
  signed int result; // eax@2
  void *buf; // [sp+Ch] [bp-Ch]@1
  int fd; // [sp+14h] [bp-4h]@1

  buf = a2;
  sprintf(globBuf, "%s%s", ".\\MAPS\\", a1);
  fd = _open(globBuf, 32768);
  if ( fd == -1 )
  {
    result = 0;
  }
  else
  {
    _read(fd, buf, 0x1A4u);
    _close(fd);
    result = 1;
  }
  return result;
}
