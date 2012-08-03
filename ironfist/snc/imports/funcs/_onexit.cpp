{
  DWORD v1; // eax@2
  void *v2; // eax@2
  int v4; // ecx@4

  _lockexit();
  if ( _msize(__onexitbegin) < __onexitend - (signed int)__onexitbegin + 4 )
  {
    v1 = _msize(__onexitbegin);
    v2 = realloc((BOOL)__onexitbegin, v1 + 16);
    if ( !v2 )
    {
      _unlockexit();
      return 0;
    }
    v4 = (__onexitend - (_DWORD)__onexitbegin) & 0xFFFFFFFC;
    __onexitbegin = v2;
    __onexitend = (int)((char *)v2 + v4);
  }
  *(_DWORD *)__onexitend = a1;
  __onexitend += 4;
  _unlockexit();
  return a1;
}