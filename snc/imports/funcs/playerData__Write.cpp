{
  const void *v2; // ST18_4@1
  char v4; // [sp+10h] [bp-34h]@1

  v2 = this;
  _write(a2, this, 1);
  _write(a2, (char *)v2 + 1, 1);
  _write(a2, (char *)v2 + 2, 1);
  _write(a2, (char *)v2 + 3, 1);
  _write(a2, (char *)v2 + 4, 8);
  _write(a2, (char *)v2 + 12, 2);
  memset(&v4, 0, 0x30u);
  _write(a2, &v4, 42);
  _write(a2, &gpGame->_10[32], 1);
  _write(a2, (char *)v2 + 19, 1);
  _write(a2, (char *)v2 + 15, 4);
  _write(a2, (char *)v2 + 14, 1);
  _write(a2, (char *)v2 + 171, 1);
  _write(a2, (char *)v2 + 64, 1);
  _write(a2, (char *)v2 + 65, 1);
  _write(a2, (char *)v2 + 66, 1);
  _write(a2, (char *)v2 + 67, 1);
  _write(a2, (char *)v2 + 68, 1);
  _write(a2, (char *)v2 + 69, 1);
  _write(a2, (char *)v2 + 70, 1);
  _write(a2, (char *)v2 + 71, 72);
  _write(a2, (char *)v2 + 143, 28);
  _write(a2, (char *)v2 + 231, 28);
  _write(a2, (char *)v2 + 172, 1);
  _write(a2, (char *)v2 + 172, 1);
  return _write(a2, (char *)v2 + 173, 6);
}