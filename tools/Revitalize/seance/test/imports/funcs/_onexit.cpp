{
  size_t v1; // eax@2
  void *v2; // eax@2
  int v4; // ecx@4

  _lockexit();
  if ( _msize(dword_538F2C) < dword_538F28 - (signed int)dword_538F2C + 4 )
  {
    v1 = _msize(dword_538F2C);
    v2 = realloc(dword_538F2C, v1 + 16);
    if ( !v2 )
    {
      _unlockexit();
      return 0;
    }
    v4 = (dword_538F28 - (_DWORD)dword_538F2C) & 0xFFFFFFFC;
    dword_538F2C = v2;
    dword_538F28 = (int)((char *)v2 + v4);
  }
  *(_DWORD *)dword_538F28 = a1;
  dword_538F28 += 4;
  _unlockexit();
  return a1;
}
