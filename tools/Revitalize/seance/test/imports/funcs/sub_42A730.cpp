{
  void *result; // eax@1
  void *v2; // [sp+Ch] [bp-7Ch]@1
  int v3; // [sp+18h] [bp-70h]@23
  signed int v4; // [sp+24h] [bp-64h]@28
  signed int l; // [sp+28h] [bp-60h]@39
  int v6; // [sp+2Ch] [bp-5Ch]@7
  int j; // [sp+30h] [bp-58h]@3
  signed int m; // [sp+34h] [bp-54h]@45
  signed int n; // [sp+34h] [bp-54h]@63
  signed int ii; // [sp+34h] [bp-54h]@66
  int k; // [sp+38h] [bp-50h]@5
  int thisa; // [sp+3Ch] [bp-4Ch]@35
  char v13[56]; // [sp+40h] [bp-48h]@1
  int v14; // [sp+78h] [bp-10h]@12
  int v15; // [sp+7Ch] [bp-Ch]@12
  char v16; // [sp+80h] [bp-8h]@10
  int i; // [sp+84h] [bp-4h]@1

  v2 = this;
  result = memset(v13, 0, 0x36u);
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 0; ; ++j )
    {
      result = (void *)mapHeight;
      if ( j >= mapHeight )
        break;
      for ( k = 0; k < mapWidth; ++k )
      {
        v6 = *(_DWORD *)((char *)v2 + 2878) + 12 * j * *(_DWORD *)((char *)v2 + 2886) + 12 * k;
        if ( (*(_BYTE *)(v6 + 9) & 0x7F) == 55 || *(_BYTE *)(v6 + 9) == 251 )
        {
          v16 = (*(_BYTE *)(v6 + 9) & 0x7F) == 123;
          v14 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v6 + 4) >> 8) >> -5);
          v15 = *((_DWORD *)dword_524784 + v14);
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
              *(_BYTE *)v15 = byte_4F38A8[*(_BYTE *)v15];
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
                v3 = *((_BYTE *)v2 + byte_524220[gameObject->players[*(_BYTE *)v15].color] + 1113);
            }
            if ( *(_BYTE *)(v15 + 61) )
            {
              *((_BYTE *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10203) = v3;
            }
            else
            {
              v4 = sub_4199F0((int)v13, 9 * v3, 9, 1000, 0);
              if ( v4 == -1 )
              {
                v4 = sub_4199F0((int)v13, 0, 54, 10000, 0);
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
            thisa = (int)((char *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10180);
            if ( !v16 && *(_BYTE *)(v15 + 59) )
            {
              *((_BYTE *)v2 + 250 * *(_BYTE *)(v15 + 18) + 10221) = k;
              *(_BYTE *)(thisa + 42) = j;
              *(_BYTE *)(thisa + 43) = *(_BYTE *)(v15 + 60);
            }
            if ( *(_BYTE *)(v15 + 1) )
            {
              for ( l = 0; l < 5; ++l )
              {
                *(_WORD *)(thisa + 2 * l + 106) = *(_WORD *)(v15 + 2 * l + 7);
                if ( (signed int)*(_WORD *)(thisa + 2 * l + 106) <= 0 )
                  *(_BYTE *)(l + thisa + 101) = -1;
                else
                  *(_BYTE *)(l + thisa + 101) = *(_BYTE *)(l + v15 + 2);
              }
            }
            for ( m = 0; m < 3; ++m )
            {
              if ( (signed int)*(_BYTE *)(m + v15 + 19) >= 0 )
                grantArtifact((Hero *)thisa, (ARTIFACT)*(_BYTE *)(m + v15 + 19), 1, -1);
            }
            if ( *(_BYTE *)(v15 + 45) )
              strcpy((char *)(thisa + 10), (const char *)(v15 + 46));
            *(_DWORD *)(thisa + 57) = 0;
            giveXPToHero((Hero *)thisa, *(_DWORD *)(v15 + 23), 1);
            Hero::checkForLevelUp((Hero *)thisa);
            *(_DWORD *)(thisa + 25) = k;
            *(_DWORD *)(thisa + 29) = j;
            if ( v16 )
            {
              *(_BYTE *)(thisa + 3) = -1;
              *((_BYTE *)v2 + *(_BYTE *)(v15 + 18) + 23680) = 65;
            }
            else
            {
              *(_BYTE *)(thisa + 3) = *(_BYTE *)v15;
              *((_BYTE *)v2 + *(_BYTE *)(v15 + 18) + 23680) = *(_BYTE *)(thisa + 3);
              *((_BYTE *)v2
              + 284 * *(_BYTE *)(thisa + 3)
              + (*((_BYTE *)v2 + 283 * *(_BYTE *)(thisa + 3) + 1181))++
              - *(_BYTE *)(thisa + 3)
              + 1184) = *(_BYTE *)(thisa + 2);
            }
            if ( !v16
              && j > 0
              && *(_BYTE *)(*(_DWORD *)((char *)v2 + 2878) + 12 * (j - 1) * *(_DWORD *)((char *)v2 + 2886) + 12 * k + 9) == 163 )
            {
              --*(_BYTE *)(thisa + 42);
              --*(_DWORD *)(thisa + 29);
              *((_BYTE *)v2 + 100 * sub_419C90(v2, k, j - 1) + 2922) = *(_BYTE *)(thisa + 2);
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
              *(_DWORD *)(thisa + 144) = 0;
              for ( n = 0; n < 14; ++n )
              {
                *(_BYTE *)(n + thisa + 116) = 0;
                *(_BYTE *)(n + thisa + 130) = 0;
              }
              for ( ii = 0; ii < 8; ++ii )
              {
                if ( *(_BYTE *)(ii + v15 + 28) != -1 )
                  Hero::learnSecondarySkill((Hero *)thisa, *(_BYTE *)(ii + v15 + 28), *(_BYTE *)(ii + v15 + 36));
              }
            }
            if ( !v16 )
              explore(
                *(_DWORD *)(thisa + 25),
                *(_DWORD *)(thisa + 29),
                *(_BYTE *)(thisa + 3),
                byte_4F3B10[*(_BYTE *)(thisa + 119)]);
            KBFree(*((void **)dword_524784 + v14), (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF69C + 221);
            *((_DWORD *)dword_524784 + v14) = 0;
          }
        }
      }
    }
  }
  return result;
}
