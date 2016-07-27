{
  void *v2; // ST18_4@1
  char v4; // [sp+10h] [bp-34h]@1

  v2 = this;
  _read(fd, this, 1u);
  _read(fd, (char *)v2 + 1, 1u);
  _read(fd, (char *)v2 + 2, 1u);
  _read(fd, (char *)v2 + 3, 1u);
  _read(fd, (char *)v2 + 4, 8u);
  _read(fd, (char *)v2 + 12, 2u);
  _read(fd, &v4, 0x2Au);
  _read(fd, &gameObject->_10[32], 1u);
  _read(fd, (char *)v2 + 19, 1u);
  _read(fd, (char *)v2 + 15, 4u);
  _read(fd, (char *)v2 + 14, 1u);
  _read(fd, (char *)v2 + 171, 1u);
  _read(fd, (char *)v2 + 64, 1u);
  _read(fd, (char *)v2 + 65, 1u);
  _read(fd, (char *)v2 + 66, 1u);
  _read(fd, (char *)v2 + 67, 1u);
  _read(fd, (char *)v2 + 68, 1u);
  _read(fd, (char *)v2 + 69, 1u);
  _read(fd, (char *)v2 + 70, 1u);
  _read(fd, (char *)v2 + 71, 0x48u);
  _read(fd, (char *)v2 + 143, 0x1Cu);
  _read(fd, (char *)v2 + 231, 0x1Cu);
  _read(fd, (char *)v2 + 172, 1u);
  _read(fd, (char *)v2 + 172, 1u);
  return _read(fd, (char *)v2 + 173, 6u);
}
