BOOL __thiscall MapTiles::load(MapTiles *ecx0, UINT fd, int isNewGame)
{
  BOOL result; // eax@16
  void *v5; // [sp+28h] [bp-14h]@13
  void *buf; // [sp+2Ch] [bp-10h]@2
  int j; // [sp+30h] [bp-Ch]@4
  int i; // [sp+34h] [bp-8h]@2
  int k; // [sp+38h] [bp-4h]@13

  _read(fd, &ecx0->width, 4u);
  _read(fd, &ecx0->height, 4u);
  MapTiles::initialize(ecx0, ecx0->width, ecx0->height);
  if ( isNewGame )
  {
    buf = operator new(20 * ecx0->height * ecx0->width);
    _read(fd, buf, 20 * ecx0->height * ecx0->width);
    for ( i = 0; ecx0->width > i; ++i )
    {
      for ( j = 0; ecx0->height > j; ++j )
        memcpy(&ecx0->tiles[j * ecx0->width] + i, (char *)buf + 20 * i + 20 * j * ecx0->width, 0xCu);
    }
    operator delete(buf);
  }
  else
  {
    _read(fd, ecx0->tiles, 12 * ecx0->height * ecx0->width);
  }
  _read(fd, &ecx0->field_10, 4u);
  if ( ecx0->field_4 )
    operator delete((void *)ecx0->field_4);
  ecx0->field_4 = (int)operator new(7 * ecx0->field_10);
  if ( isNewGame )
  {
    v5 = operator new(15 * ecx0->field_10);
    _read(fd, v5, 15 * ecx0->field_10);
    for ( k = 0; ecx0->field_10 > k; ++k )
      memcpy((void *)(ecx0->field_4 - k + 8 * k), (char *)v5 + 15 * k, 7u);
    result = operator delete(v5);
  }
  else
  {
    result = _read(fd, (void *)ecx0->field_4, 7 * ecx0->field_10);
  }
  return result;
}
