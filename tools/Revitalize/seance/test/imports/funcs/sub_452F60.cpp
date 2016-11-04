{
  __int64 v4; // ST08_8@17
  __int64 v5; // ST08_8@17
  __int64 v6; // ST08_8@17
  __int64 v7; // ST08_8@17
  int v8; // [sp+0h] [bp-20h]@0
  __int16 v9; // [sp+4h] [bp-1Ch]@0
  int v10; // [sp+8h] [bp-18h]@0
  int v11; // [sp+Ch] [bp-14h]@1
  int j; // [sp+10h] [bp-10h]@11
  int i; // [sp+14h] [bp-Ch]@2
  int l; // [sp+14h] [bp-Ch]@15
  signed int m; // [sp+14h] [bp-Ch]@20
  signed int k; // [sp+1Ch] [bp-4h]@13

  v11 = (int)this;
  if ( soundManager->field_688 )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( *(_DWORD *)(v11 + 8 * i + 706) != -1 )
      {
        logUpTo7Ints((int)"SEO a", i, -999, -999, -999, -999, -999, -999);
        if ( a4 )
        {
          logUpTo7Ints((int)"SEO b", i, -999, -999, -999, -999, -999, -999);
          sub_403760((int)soundManager, *(_DWORD *)(*(_DWORD *)(v11 + 4 * *(_DWORD *)(v11 + 8 * i + 706) + 738) + 16));
          *(_DWORD *)(v11 + 8 * i + 706) = -1;
          *(_DWORD *)(v11 + 8 * i + 710) = 127;
        }
        else
        {
          *(_DWORD *)(v11 + 8 * i + 710) = 127;
        }
      }
    }
    if ( a2 != -1 && *(_DWORD *)&soundVolume )
    {
      *(_DWORD *)(v11 + 702) = 0;
      for ( j = 1; j <= 2; ++j )
      {
        sub_4537E0(v11, __PAIR__(a3, a2), 0, j);
        for ( k = 0; k < 4; ++k )
        {
          for ( l = 0; 2 * k > l; ++l )
          {
            HIDWORD(v4) = a3 - k;
            LODWORD(v4) = l + a2 - k;
            sub_4537E0(v11, v4, k, j);
            HIDWORD(v5) = l + a3 - k;
            LODWORD(v5) = k + a2;
            sub_4537E0(v11, v5, k, j);
            HIDWORD(v6) = k + a3;
            LODWORD(v6) = k + a2 - l;
            sub_4537E0(v11, v6, k, j);
            HIDWORD(v7) = k + a3 - l;
            LODWORD(v7) = a2 - k;
            sub_4537E0(v11, v7, k, j);
          }
        }
      }
      for ( m = 0; m < 4; ++m )
      {
        if ( *(_DWORD *)(v11 + 8 * m + 706) != -1 && *(_DWORD *)(v11 + 8 * m + 710) > 5 )
        {
          sub_403760((int)soundManager, *(_DWORD *)(*(_DWORD *)(v11 + 4 * *(_DWORD *)(v11 + 8 * m + 706) + 738) + 16));
          *(_DWORD *)(v11 + 8 * m + 706) = -1;
        }
        if ( *(_DWORD *)(v11 + 8 * m + 706) != -1 && (1 << *(_BYTE *)(v11 + 8 * m + 706)) & *(_DWORD *)(v11 + 702) )
          sub_4037F0(
            soundManager,
            *(HSAMPLE *)(*(_DWORD *)(v11 + 4 * *(_DWORD *)(v11 + 8 * m + 706) + 738) + 16),
            100,
            dword_4EA270[*(_DWORD *)(v11 + 8 * m + 710)],
            v8,
            v9,
            v10);
      }
    }
  }
}
