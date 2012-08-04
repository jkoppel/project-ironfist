{
  void *result; // eax@1
  void *v2; // [sp+Ch] [bp-7Ch]@1
  int v3; // [sp+18h] [bp-70h]@20
  signed int v4; // [sp+24h] [bp-64h]@25
  signed int l; // [sp+28h] [bp-60h]@36
  int v6; // [sp+2Ch] [bp-5Ch]@7
  int j; // [sp+30h] [bp-58h]@3
  signed int m; // [sp+34h] [bp-54h]@42
  signed int n; // [sp+34h] [bp-54h]@60
  signed int ii; // [sp+34h] [bp-54h]@63
  int k; // [sp+38h] [bp-50h]@5
  int hro; // [sp+3Ch] [bp-4Ch]@32
  char v13[56]; // [sp+40h] [bp-48h]@1
  int v14; // [sp+78h] [bp-10h]@9
  int v15; // [sp+7Ch] [bp-Ch]@9
  char v16; // [sp+80h] [bp-8h]@9
  int i; // [sp+84h] [bp-4h]@1

  v2 = this;
  result = memset(v13, 0, 0x36u);
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 0; ; ++j )
    {
      result = (void *)MAP_HEIGHT;
      if ( j >= MAP_HEIGHT )
        break;
      for ( k = 0; k < MAP_WIDTH; ++k )
      {
        v6 = *(_DWORD *)((char *)v2 + 2878) + 12 * j * *(_DWORD *)((char *)v2 + 2886) + 12 * k;
        if ( (*(_BYTE *)(v6 + 9) & 0x7F) == 55 || *(_BYTE *)(v6 + 9) == 251 )
        {
          v16 = (*(_BYTE *)(v6 + 9) & 0x7F) == 123;
          v14 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v6 + 4) >> 8) >> -5);
          v15 = *((_DWORD *)ppMapExtra + v14);
          if ( !i )
          {
            if ( !*(_BYTE *)(v15 + 17) || (signed int)*(_BYTE *)(v15 + 18) >= 54 || v13[*(_BYTE *)(v15 + 18)] )
            {
              *(_BYTE *)(v15 + 61) = 0;
            }
            else
            {
              v13[*(_BYTE *)(v15 + 18)] = 1;
              *(_BYTE *)(v15 + 61) = 1;
            }
            if ( v16 )
            {
              *(_BYTE *)v15 = -1;
            }
            else
            {
              *(_BYTE *)v15 = *(_BYTE *)(v6 + 3) / 7;
              *(_BYTE *)v15 = gcColorToPlayerPos[*(_BYTE *)v15];
            }
          }
          if ( i == 1 )
          {
            if ( v16 )
            {
              v3 = *(_BYTE *)(v15 + 60);
            }
            else
            {
              v3 = *(_BYTE *)(v6 + 3) % 7;
              if ( v3 == 6 )
                v3 = *((_BYTE *)v2 + gcColorToSetupPos[gpGame->players[*(_BYTE *)v15].color] + 1113);
            }
            if ( *(_BYTE *)(v15 + 61) )
            {
              *((_BYTE *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10203) = v3;
            }
            else
            {
              v4 = game::RandomScan((int)v13, 9 * v3, 9, 1000, 0);
              if ( v4 == -1 )
              {
                v4 = game::RandomScan((int)v13, 0, 54, 10000, 0);
                v3 = v4 / 9;
              }
              v13[v4] = 1;
              *((_BYTE *)v2 + 250 * v4 + 10203) = v3;
              if ( *(_BYTE *)(v15 + 17) && (signed int)*(_BYTE *)(v15 + 18) >= 54 )
                *((_BYTE *)v2 + 250 * v4 + 10204) = *(_BYTE *)(v15 + 18);
              *(_BYTE *)(v15 + 18) = v4;
            }
          }
          if ( i == 2 )
          {
            hro = (int)((char *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10180);
            if ( !v16 && *(_BYTE *)(v15 + 59) )
            {
              *((_BYTE *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10221) = k;
              *(_BYTE *)(hro + 42) = j;
              *(_BYTE *)(hro + 43) = *(_BYTE *)(v15 + 60);
            }
            if ( *(_BYTE *)(v15 + 1) )
            {
              for ( l = 0; l < 5; ++l )
              {
                *(_WORD *)(hro + 2 * l + 106) = *(_WORD *)(v15 + 2 * l + 7);
                if ( (signed int)*(_WORD *)(hro + 2 * l + 106) <= 0 )
                  *(_BYTE *)(l + hro + 101) = -1;
                else
                  *(_BYTE *)(l + hro + 101) = *(_BYTE *)(l + v15 + 2);
              }
            }
            for ( m = 0; m < 3; ++m )
            {
              if ( (signed int)*(_BYTE *)(m + v15 + 19) >= 0 )
                GiveArtifact((hero *)hro, (ARTIFACT)*(_BYTE *)(m + v15 + 19), 1, -1);
            }
            if ( *(_BYTE *)(v15 + 45) )
              strcpy((char *)(hro + 10), (char *)(v15 + 46));
            *(_DWORD *)(hro + 57) = 0;
            advManager::GiveExperience((hero *)hro, *(_DWORD *)(v15 + 23), 1);
            hero::CheckLevel((hero *)hro);
            *(_DWORD *)(hro + 25) = k;
            *(_DWORD *)(hro + 29) = j;
            if ( v16 )
            {
              *(_BYTE *)(hro + 3) = -1;
              *((_BYTE *)v2 + *(_BYTE *)(v15 + 18) + 23680) = 65;
            }
            else
            {
              *(_BYTE *)(hro + 3) = *(_BYTE *)v15;
              *((_BYTE *)v2 + *(_BYTE *)(v15 + 18) + 23680) = *(_BYTE *)(hro + 3);
              *((_BYTE *)v2
              + 284 * *(_BYTE *)(hro + 3)
              + (*((_BYTE *)v2 + 283 * *(_BYTE *)(hro + 3) + 1181))++
              - *(_BYTE *)(hro + 3)
              + 1184) = *(_BYTE *)(hro + 2);
            }
            if ( !v16
              && j > 0
              && *(_BYTE *)(*(_DWORD *)((char *)v2 + 2878) + 12 * (j - 1) * *(_DWORD *)((char *)v2 + 2886) + 12 * k + 9) == 163 )
            {
              --*(_BYTE *)(hro + 42);
              --*(_DWORD *)(hro + 29);
              *((_BYTE *)v2 + 100 * game::GetTownId(v2, k, j - 1) + 2922) = *(_BYTE *)(hro + 2);
            }
            if ( v16 )
            {
              *(_WORD *)(v6 + 4) = *(_WORD *)(v6 + 4) & 7 | 8 * *(_BYTE *)(v15 + 18);
            }
            else
            {
              *(_BYTE *)(v6 + 2) &= 3u;
              *(_BYTE *)(v6 + 3) = -1;
              *(_WORD *)(v6 + 4) &= 7u;
              *(_BYTE *)(v6 + 9) = 0;
            }
            if ( *(_BYTE *)(v15 + 27) )
            {
              *(_DWORD *)(hro + 144) = 0;
              for ( n = 0; n < 14; ++n )
              {
                *(_BYTE *)(n + hro + 116) = 0;
                *(_BYTE *)(n + hro + 130) = 0;
              }
              for ( ii = 0; ii < 8; ++ii )
              {
                if ( *(_BYTE *)(ii + v15 + 28) != -1 )
                  hero::GiveSS((hero *)hro, *(_BYTE *)(ii + v15 + 28), *(_BYTE *)(ii + v15 + 36));
              }
            }
            if ( !v16 )
              game::SetVisibility(
                *(_DWORD *)(hro + 25),
                *(_DWORD *)(hro + 29),
                *(_BYTE *)(hro + 3),
                giVisRange[*(_BYTE *)(hro + 119)]);
            BaseFree(*((void **)ppMapExtra + v14), (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF69C + 221);
            *((_DWORD *)ppMapExtra + v14) = 0;
          }
        }
      }
    }
  }
  return result;
}