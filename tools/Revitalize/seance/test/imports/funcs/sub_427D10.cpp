{
  int result; // eax@2
  int v2; // [sp+Ch] [bp-14h]@1
  int v3; // [sp+10h] [bp-10h]@5
  int j; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@1

  v2 = this;
  memset((void *)(this + 24886), 0, 0x67u);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( mapWidth <= i )
      break;
    for ( j = 0; j < mapHeight; ++j )
    {
      v3 = *(_DWORD *)(v2 + 2878) + 12 * j * *(_DWORD *)(v2 + 2886) + 12 * i;
      if ( *(_BYTE *)(v3 + 9) == 169 )
        *(_BYTE *)(((signed int)*(_BYTE *)(v3 + 3) >> 1) + v2 + 24886) = 1;
    }
  }
  return result;
}
