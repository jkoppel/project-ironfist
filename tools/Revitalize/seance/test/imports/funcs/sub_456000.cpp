{
  int result; // eax@2
  void *v3; // [sp+Ch] [bp-28h]@1
  signed int v4; // [sp+10h] [bp-24h]@6
  signed int i; // [sp+14h] [bp-20h]@6
  signed int j; // [sp+14h] [bp-20h]@12
  signed int k; // [sp+14h] [bp-20h]@18
  signed int l; // [sp+14h] [bp-20h]@24
  char v9[28]; // [sp+18h] [bp-1Ch]@6

  v3 = this;
  if ( dword_4F74AC > 0 )
  {
    result = dword_4F74AC / 100;
    a2 += dword_4F74AC / 100;
  }
  if ( mapWidth != 144 )
    ++a2;
  if ( a2 < 28 )
  {
    v4 = 0;
    memset(v9, 0, 0x1Cu);
    for ( i = 0; i < 4; ++i )
    {
      if ( *(_DWORD *)((char *)v3 + 8 * i + 706) >= 0 )
      {
        if ( *(_DWORD *)((char *)v3 + 8 * i + 706) < 28 )
          ++v9[*(_DWORD *)((char *)v3 + 8 * i + 706)];
      }
    }
    for ( j = 0; j < 28; ++j )
    {
      if ( v9[j] )
        ++v4;
    }
    result = a2;
    if ( v4 < a2 )
    {
      for ( k = 0; ; ++k )
      {
        if ( k < 28 )
        {
          result = v9[k];
          if ( v9[k] )
            continue;
          result = k;
          if ( !*(_DWORD *)((char *)v3 + 4 * k + 738) )
            continue;
          ++v9[k];
          ++v4;
          result = a2;
          if ( v4 < a2 )
            continue;
        }
        break;
      }
    }
    for ( l = 0; l < 28; ++l )
    {
      result = l;
      if ( *(_DWORD *)((char *)v3 + 4 * l + 738) )
      {
        result = v9[l];
        if ( !v9[l] )
        {
          ResourceManager::reduceReferenceCountToResource(
            resourceManager,
            *(AbstractResource **)((char *)v3 + 4 * l + 738));
          result = l;
          *(_DWORD *)((char *)v3 + 4 * l + 738) = 0;
        }
      }
    }
  }
  return result;
}
