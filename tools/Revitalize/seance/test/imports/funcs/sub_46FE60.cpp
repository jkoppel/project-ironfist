{
  int result; // eax@16
  int thisa; // [sp+Ch] [bp-30h]@1
  void *v5; // [sp+28h] [bp-14h]@13
  void *buf; // [sp+2Ch] [bp-10h]@2
  int j; // [sp+30h] [bp-Ch]@4
  int i; // [sp+34h] [bp-8h]@2
  int k; // [sp+38h] [bp-4h]@13

  thisa = this;
  _read(fd, (void *)(this + 8), 4u);
  _read(fd, (void *)(thisa + 12), 4u);
  MapTiles::initialize((MapTiles *)thisa, *(_DWORD *)(thisa + 8), *(_DWORD *)(thisa + 12));
  if ( a3 )
  {
    buf = operator new(20 * *(_DWORD *)(thisa + 12) * *(_DWORD *)(thisa + 8));
    _read(fd, buf, 20 * *(_DWORD *)(thisa + 12) * *(_DWORD *)(thisa + 8));
    for ( i = 0; *(_DWORD *)(thisa + 8) > i; ++i )
    {
      for ( j = 0; *(_DWORD *)(thisa + 12) > j; ++j )
        memcpy(
          (void *)(*(_DWORD *)thisa + 12 * i + 12 * j * *(_DWORD *)(thisa + 8)),
          (char *)buf + 20 * i + 20 * j * *(_DWORD *)(thisa + 8),
          0xCu);
    }
    operator delete(buf);
  }
  else
  {
    _read(fd, *(void **)thisa, 12 * *(_DWORD *)(thisa + 12) * *(_DWORD *)(thisa + 8));
  }
  _read(fd, (void *)(thisa + 16), 4u);
  if ( *(_DWORD *)(thisa + 4) )
    operator delete(*(void **)(thisa + 4));
  *(_DWORD *)(thisa + 4) = operator new(7 * *(_DWORD *)(thisa + 16));
  if ( a3 )
  {
    v5 = operator new(15 * *(_DWORD *)(thisa + 16));
    _read(fd, v5, 15 * *(_DWORD *)(thisa + 16));
    for ( k = 0; *(_DWORD *)(thisa + 16) > k; ++k )
      memcpy((void *)(*(_DWORD *)(thisa + 4) - k + 8 * k), (char *)v5 + 15 * k, 7u);
    result = operator delete(v5);
  }
  else
  {
    result = _read(fd, *(void **)(thisa + 4), 7 * *(_DWORD *)(thisa + 16));
  }
  return result;
}
