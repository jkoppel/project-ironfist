void __cdecl sub_4D4C20()
{
  unsigned int v0; // eax@23
  int v1; // [sp+10h] [bp-38h]@45
  unsigned __int16 v2; // [sp+14h] [bp-34h]@43
  int v3; // [sp+18h] [bp-30h]@43
  int v4; // [sp+1Ch] [bp-2Ch]@40
  int v5; // [sp+20h] [bp-28h]@40
  int v6; // [sp+24h] [bp-24h]@38
  signed int v7; // [sp+28h] [bp-20h]@0
  signed int v8; // [sp+2Ch] [bp-1Ch]@0
  int v9; // [sp+30h] [bp-18h]@36
  signed int m; // [sp+38h] [bp-10h]@24
  int v11; // [sp+3Ch] [bp-Ch]@24
  signed int i; // [sp+40h] [bp-8h]@12
  int j; // [sp+40h] [bp-8h]@15
  signed int k; // [sp+40h] [bp-8h]@18
  int l; // [sp+40h] [bp-8h]@21
  signed int n; // [sp+40h] [bp-8h]@36
  int ii; // [sp+44h] [bp-4h]@4

  dword_5347A0 = dword_5347A4 + 1;
  if ( dword_5347A4 + 1 > 1024 )
  {
    sub_4D42B0();
    if ( dword_537920 )
    {
      sprintf(globBuf, "bucket sorting ...\n");
      debugLog(globBuf);
    }
    for ( i = 0; i <= 65536; ++i )
      *((_DWORD *)dword_51FDC8 + i) = 0;
    for ( j = 0; dword_5347A4 >= j; ++j )
      ++*((_DWORD *)dword_51FDC8 + (*((_DWORD *)dword_51FDC0 + j) >> 16));
    for ( k = 1; k <= 65536; ++k )
      *((_DWORD *)dword_51FDC8 + k) += *((_DWORD *)dword_51FDC8 + k - 1);
    for ( l = 0; dword_5347A4 >= l; ++l )
    {
      v0 = *((_DWORD *)dword_51FDC0 + l);
      --*((_DWORD *)dword_51FDC8 + (v0 >> 16));
      *((_DWORD *)dword_51FDC4 + *((_DWORD *)dword_51FDC8 + (v0 >> 16))) = l;
    }
    sub_4D4340();
    v11 = dword_5347A0;
    for ( m = 1; m <= 5; ++m )
    {
      switch ( m )
      {
        case 1:
          v8 = 2;
          v7 = 15;
          break;
        case 2:
          v8 = 16;
          v7 = 255;
          break;
        case 3:
          v8 = 256;
          v7 = 4095;
          break;
        case 4:
          v8 = 4096;
          v7 = 65535;
          break;
        case 5:
          v8 = 65536;
          v7 = 900000;
          break;
        default:
          unknown_libname_27();
          break;
      }
      if ( v8 <= dword_5347A0 )
      {
        v9 = 0;
        for ( n = 0; n <= 65535; ++n )
        {
          v6 = *((_DWORD *)dword_51FDC8 + n + 1) - *((_DWORD *)dword_51FDC8 + n);
          if ( v6 >= v8 && v7 >= v6 )
          {
            v4 = *((_DWORD *)dword_51FDC8 + n);
            v5 = *((_DWORD *)dword_51FDC8 + n + 1) - 1;
            ++v9;
            v11 -= v6;
            if ( dword_537920 )
            {
              sprintf(globBuf, "   %d -> %d:  cand %5d,   freq = %6d,   notdone = %6d", v8, v7, v9, v6, v11);
              debugLog(globBuf);
            }
            sub_4D4510(v4, v5);
            if ( v6 < 65535 )
            {
              v3 = v4;
              v2 = 0;
              while ( v5 >= v3 )
              {
                v1 = *((_DWORD *)dword_51FDC4 + v3);
                sub_4D3B40(v1, v2);
                if ( v1 < 16 )
                  sub_4D3B40(v1 + dword_5347A0, v2);
                ++v3;
                ++v2;
              }
            }
            if ( dword_537920 )
            {
              sprintf(globBuf, L" ");
              debugLog(globBuf);
            }
          }
        }
      }
    }
  }
  else
  {
    if ( dword_537920 )
    {
      sprintf(globBuf, "trivialSort ...\n");
      debugLog(globBuf);
    }
    for ( ii = 0; ii <= dword_5347A4; ++ii )
      *((_DWORD *)dword_51FDC4 + ii) = ii;
    sub_4D4B10();
    if ( dword_537920 )
    {
      sprintf(globBuf, "trivialSort done.\n");
      debugLog(globBuf);
    }
  }
}
