{
  signed int result; // eax@2
  void *buf; // [sp+Ch] [bp-Ch]@1
  UINT fd; // [sp+14h] [bp-4h]@1

  buf = a2;
  sprintf(gText, "%s%s", ".\\MAPS\\", a1);
  fd = open(gText, 32768);
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