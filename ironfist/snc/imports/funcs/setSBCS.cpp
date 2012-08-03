{
  int result; // eax@1

  result = 0;
  memset(_mbctype, 0, 0x100u);
  _mbctype[256] = 0;
  __mbulinfo = 0;
  __mbcodepage = 0;
  __mblcid = 0;
  *(&__mbulinfo + 1) = 0;
  *(&__mbulinfo + 2) = 0;
  return result;
}