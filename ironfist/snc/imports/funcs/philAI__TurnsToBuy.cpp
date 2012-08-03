{
  double v1; // st7@7
  float v3; // [sp+14h] [bp-Ch]@1
  signed int i; // [sp+18h] [bp-8h]@1
  float v5; // [sp+1Ch] [bp-4h]@5

  v3 = 0.0;
  for ( i = 0; i < 7; ++i )
  {
    if ( gpCurPlayer->resources[i] < *(_DWORD *)(a1 + 4 * i) )
    {
      if ( *(_DWORD *)&gpCurPlayer->_4[4 * i + 60] <= 0 )
        v5 = 99.0;
      else
        v5 = (double)((*(_DWORD *)(a1 + 4 * i) - gpCurPlayer->resources[i]) / *(_DWORD *)&gpCurPlayer->_4[4 * i + 60] + 1);
      v1 = v5;
      if ( v3 >= (double)v5 )
        v1 = v3;
      v3 = v1;
    }
  }
  return v3;
}