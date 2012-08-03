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

  lastPP = last + 1;
  if ( last + 1 > 1024 )
  {
    stripe();
    if ( veryVerbose )
    {
      sprintf(gText, "bucket sorting ...\n");
      LogStr(gText);
    }
    for ( i = 0; i <= 65536; ++i )
      *((_DWORD *)ftab + i) = 0;
    for ( j = 0; last >= j; ++j )
      ++*((_DWORD *)ftab + (*((_DWORD *)words + j) >> 16));
    for ( k = 1; k <= 65536; ++k )
      *((_DWORD *)ftab + k) += *((_DWORD *)ftab + k - 1);
    for ( l = 0; last >= l; ++l )
    {
      v0 = *((_DWORD *)words + l);
      --*((_DWORD *)ftab + (v0 >> 16));
      *((_DWORD *)zptr + *((_DWORD *)ftab + (v0 >> 16))) = l;
    }
    copyOffsetWords();
    v11 = lastPP;
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
          panic();
          break;
      }
      if ( v8 <= lastPP )
      {
        v9 = 0;
        for ( n = 0; n <= 65535; ++n )
        {
          v6 = *((_DWORD *)ftab + n + 1) - *((_DWORD *)ftab + n);
          if ( v6 >= v8 && v7 >= v6 )
          {
            v4 = *((_DWORD *)ftab + n);
            v5 = *((_DWORD *)ftab + n + 1) - 1;
            ++v9;
            v11 -= v6;
            if ( veryVerbose )
            {
              sprintf(gText, "   %d -> %d:  cand %5d,   freq = %6d,   notdone = %6d", v8, v7, v9, v6, v11);
              LogStr(gText);
            }
            qsortFull(v4, v5);
            if ( v6 < 65535 )
            {
              v3 = v4;
              v2 = 0;
              while ( v5 >= v3 )
              {
                v1 = *((_DWORD *)zptr + v3);
                SETREST16(v1, v2);
                if ( v1 < 16 )
                  SETREST16(v1 + lastPP, v2);
                ++v3;
                ++v2;
              }
            }
            if ( veryVerbose )
            {
              sprintf(gText, L" ");
              LogStr(gText);
            }
          }
        }
      }
    }
  }
  else
  {
    if ( veryVerbose )
    {
      sprintf(gText, "trivialSort ...\n");
      LogStr(gText);
    }
    for ( ii = 0; ii <= last; ++ii )
      *((_DWORD *)zptr + ii) = ii;
    shellTrivial();
    if ( veryVerbose )
    {
      sprintf(gText, "trivialSort done.\n");
      LogStr(gText);
    }
  }
}