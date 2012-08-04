{
  signed int v3; // [sp+10h] [bp-24h]@6
  signed int i; // [sp+14h] [bp-20h]@6
  signed int j; // [sp+14h] [bp-20h]@12
  signed int k; // [sp+14h] [bp-20h]@18
  signed int l; // [sp+14h] [bp-20h]@24
  char v8[28]; // [sp+18h] [bp-1Ch]@6

  if ( giHighMemBuffer > 0 )
    a2 += giHighMemBuffer / 100;
  if ( MAP_WIDTH != 144 )
    ++a2;
  if ( a2 < 28 )
  {
    v3 = 0;
    memset(v8, 0, 0x1Cu);
    for ( i = 0; i < 4; ++i )
    {
      if ( this->field_2C2[i][0] >= 0 )
      {
        if ( this->field_2C2[i][0] < 28 )
          ++v8[this->field_2C2[i][0]];
      }
    }
    for ( j = 0; j < 28; ++j )
    {
      if ( v8[j] )
        ++v3;
    }
    if ( v3 < a2 )
    {
      for ( k = 0; ; ++k )
      {
        if ( k < 28 )
        {
          if ( v8[k] )
            continue;
          if ( !this->loopSamples[k] )
            continue;
          ++v8[k];
          ++v3;
          if ( v3 < a2 )
            continue;
        }
        break;
      }
    }
    for ( l = 0; l < 28; ++l )
    {
      if ( this->loopSamples[l] && !v8[l] )
      {
        resourceManager::Dispose(gpResourceManager, (resource *)this->loopSamples[l]);
        this->loopSamples[l] = 0;
      }
    }
  }
}