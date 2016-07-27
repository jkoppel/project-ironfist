{
  int v2; // eax@105
  int v3; // ST74_4@110
  int v4; // ST6C_4@110
  int v5; // ST34_4@110
  int v6; // ebx@116
  int v7; // ebx@116
  int v8; // ebx@126
  int v9; // ebx@137
  int v10; // ebx@137
  int v11; // ecx@158
  int v12; // ecx@164
  int thisa; // [sp+10h] [bp-6Ch]@1
  double v14; // [sp+14h] [bp-68h]@151
  int v15; // [sp+1Ch] [bp-60h]@133
  int v16; // [sp+20h] [bp-5Ch]@130
  int v17; // [sp+2Ch] [bp-50h]@171
  char *v18; // [sp+30h] [bp-4Ch]@0
  char v19; // [sp+34h] [bp-48h]@0
  signed int v20; // [sp+38h] [bp-44h]@76
  signed int v21; // [sp+38h] [bp-44h]@90
  signed int k; // [sp+3Ch] [bp-40h]@78
  signed int l; // [sp+3Ch] [bp-40h]@95
  signed int v24; // [sp+44h] [bp-38h]@53
  int v25; // [sp+4Ch] [bp-30h]@7
  int faction; // [sp+50h] [bp-2Ch]@87
  int v27; // [sp+54h] [bp-28h]@42
  signed int j; // [sp+54h] [bp-28h]@57
  signed int m; // [sp+54h] [bp-28h]@108
  int v30; // [sp+54h] [bp-28h]@116
  signed int n; // [sp+54h] [bp-28h]@148
  signed int ii; // [sp+54h] [bp-28h]@188
  signed int playerIdx; // [sp+58h] [bp-24h]@7
  signed int playerIdxa; // [sp+58h] [bp-24h]@15
  signed int playerIdxb; // [sp+58h] [bp-24h]@20
  signed int playerIdxc; // [sp+58h] [bp-24h]@23
  signed int playerIdxd; // [sp+58h] [bp-24h]@26
  signed int playerIdxe; // [sp+58h] [bp-24h]@29
  signed int playerIdxf; // [sp+58h] [bp-24h]@32
  signed int playerIdxg; // [sp+58h] [bp-24h]@35
  signed int playerIdxh; // [sp+58h] [bp-24h]@42
  int playerIdxi; // [sp+58h] [bp-24h]@51
  int playerIdxj; // [sp+58h] [bp-24h]@69
  signed int playerIdxk; // [sp+58h] [bp-24h]@106
  int playerIdxl; // [sp+58h] [bp-24h]@116
  signed int playerIdxm; // [sp+58h] [bp-24h]@144
  signed int playerIdxn; // [sp+58h] [bp-24h]@169
  signed int v48; // [sp+60h] [bp-1Ch]@116
  int v49; // [sp+64h] [bp-18h]@158
  int v50; // [sp+64h] [bp-18h]@164
  int v51; // [sp+68h] [bp-14h]@7
  int v52; // [sp+6Ch] [bp-10h]@1
  signed int i; // [sp+74h] [bp-8h]@55
  int v54; // [sp+78h] [bp-4h]@116

  thisa = (int)this;
  v52 = sub_4C91C0(byte_524740, 46);
  if ( v52 && sub_48C5F0((int *)(v52 + 1), (int *)"MX2") )
    LOBYTE(inExpansion) = 1;
  if ( inExpansion )
    dword_4F19B8[5] |= 4u;
  else
    dword_4F19B8[5] &= 0xFFFFFFFBu;
  dword_523F1C = 1;
  curPlayerIdx = 0;
  curPlayer = gameObject->players;
  byte_532C5C = 1;
  byte_5306F0 = 1;
  dword_523EDC = 0;
  v51 = unseededNextRand(0, 5);
  v25 = dword_5235D4;
  for ( playerIdx = 0; playerIdx < 6; ++playerIdx )
  {
    if ( gameObject->_1[702] > playerIdx )
    {
      if ( *(_BYTE *)(playerIdx + thisa + 1119) == 10 )
        byte_523F28[playerIdx] = v25++;
      else
        byte_523F28[playerIdx] = *(_BYTE *)(playerIdx + thisa + 1119);
    }
    else
    {
      byte_523F28[playerIdx] = -1;
    }
  }
  for ( playerIdxa = 0; playerIdxa < 6; ++playerIdxa )
  {
    *(_BYTE *)(283 * playerIdxa + thisa + 1180) = -1;
    byte_4F38A8[playerIdxa] = -1;
    byte_524220[playerIdxa] = -1;
    if ( gameObject->_4[playerIdxa] == 7 )
      gameObject->_4[playerIdxa] = v51;
    v51 = (v51 + 1) % 6;
  }
  for ( playerIdxb = 0; *(_BYTE *)(thisa + 1166) > playerIdxb; ++playerIdxb )
    byte_524220[*(_BYTE *)(playerIdxb + thisa + 1101)] = playerIdxb;
  for ( playerIdxc = 0; *(_BYTE *)(thisa + 1166) > playerIdxc; ++playerIdxc )
    *(_BYTE *)(283 * byte_523F28[playerIdxc] + thisa + 1180) = *(_BYTE *)(playerIdxc + thisa + 1101);
  for ( playerIdxd = 0; *(_BYTE *)(thisa + 1166) > playerIdxd; ++playerIdxd )
    byte_4F38A8[*(_BYTE *)(283 * playerIdxd + thisa + 1180)] = playerIdxd;
  for ( playerIdxe = 0; *(_BYTE *)(thisa + 1166) > playerIdxe; ++playerIdxe )
  {
    *(_BYTE *)(283 * playerIdxe + thisa + 1248) = 0;
    *(_BYTE *)(283 * playerIdxe + thisa + 1250) = 0;
    *(_BYTE *)(283 * playerIdxe + thisa + 1249) = -1;
    *(_BYTE *)(283 * playerIdxe + thisa + 1181) = 0;
    *(_BYTE *)(283 * playerIdxe + thisa + 1183) = 0;
    *(_BYTE *)(283 * playerIdxe + thisa + 1182) = -1;
  }
  sub_427FF0((void *)thisa);
  strcpy(byte_524740, a2);
  sub_420AB0((void *)thisa, (int)byte_524740);
  sub_427D10(thisa);
  sub_428580((void *)thisa);
  sub_429B90((void *)thisa);
  GameInfo::initializeCastles((GameInfo *)thisa);
  sub_420960();
  for ( playerIdxf = 0; playerIdxf < 6; ++playerIdxf )
    *(_BYTE *)(283 * playerIdxf + thisa + 1352) = 0;
  sub_41E350(thisa);
  sub_42A730((void *)thisa);
  *(_BYTE *)(thisa + 1167) = 0;
  for ( playerIdxg = *(_BYTE *)(thisa + 1166); playerIdxg < 6; ++playerIdxg )
    *(_BYTE *)(playerIdxg + thisa + 1168) = 1;
  if ( *(_BYTE *)(thisa + 710) == 4 || *(_BYTE *)(thisa + 710) == 2 )
  {
    *(_BYTE *)(thisa + 711) = 1;
    *(_BYTE *)(thisa + 712) = 0;
  }
  if ( *(_BYTE *)(thisa + 710) == 4 )
  {
    v27 = 0;
    for ( playerIdxh = 0; playerIdxh < 6; ++playerIdxh )
    {
      if ( *(_BYTE *)(playerIdxh + thisa + 689) )
        ++v27;
      if ( *(_WORD *)(thisa + 713) + 1 == v27 )
      {
        *(_WORD *)(thisa + 729) = playerIdxh;
        playerIdxh = 99;
      }
    }
  }
  if ( *(_BYTE *)(thisa + 710) == 3 )
    *(_BYTE *)(thisa + 711) = 1;
  for ( playerIdxi = 0; *(_BYTE *)(thisa + 1166) > playerIdxi; ++playerIdxi )
  {
    *(_BYTE *)(283 * playerIdxi + thisa + 1244) = 0;
    *(_BYTE *)(283 * playerIdxi + thisa + 1245) = -1;
    *(_BYTE *)(283 * playerIdxi + thisa + 1246) = -1;
    v24 = -1;
    if ( !*(_BYTE *)(thisa + 718) && (signed int)*(_BYTE *)(283 * playerIdxi + thisa + 1248) > 0 )
    {
      for ( i = 0; i < 2; ++i )
      {
        for ( j = 0; *(_BYTE *)(283 * playerIdxi + thisa + 1248) > j; ++j )
        {
          if ( v24 == -1
            && *(_BYTE *)(100 * *(_BYTE *)(j + 283 * playerIdxi + thisa + 1251) + thisa + 2922) == -1
            && (*(_BYTE *)(100 * *(_BYTE *)(j + 283 * playerIdxi + thisa + 1251) + thisa + 2923) & 0x40 || i == 1) )
            v24 = j;
        }
      }
    }
    if ( v24 != -1 )
    {
      *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184) = GameInfo::getRandomHeroFromHeroPool((GameInfo *)thisa, playerIdxi, *(_BYTE *)(100 * *(_BYTE *)(v24 + 283 * playerIdxi + thisa + 1251) + thisa + 2902), 0);
      *(_BYTE *)(*(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
               + thisa
               + 23680) = playerIdxi;
      *(_BYTE *)(thisa
               + 250
               * *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
               + 10183) = playerIdxi;
      *(_DWORD *)(thisa
                + 250
                * *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
                + 10205) = *(_BYTE *)(100 * *(_BYTE *)(v24 + 283 * playerIdxi + thisa + 1251) + thisa + 2903);
      *(_DWORD *)(thisa
                + 250
                * *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
                + 10209) = *(_BYTE *)(100 * *(_BYTE *)(v24 + 283 * playerIdxi + thisa + 1251) + thisa + 2904);
      *(_BYTE *)(100 * *(_BYTE *)(v24 + 283 * playerIdxi + thisa + 1251) + thisa + 2922) = *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184);
      explore(
        *(_DWORD *)(thisa
                  + 250
                  * *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
                  + 10205),
        *(_DWORD *)(thisa
                  + 250
                  * *(_BYTE *)(*(_BYTE *)(283 * playerIdxi + thisa + 1181) - playerIdxi + 284 * playerIdxi + thisa + 1184)
                  + 10209),
        playerIdxi,
        byte_4F3B10[*(_BYTE *)(thisa + 250 * *(_BYTE *)(283 * playerIdxi + thisa + 1184) + 10299)]);
      ++*(_BYTE *)(283 * playerIdxi + thisa + 1181);
    }
  }
  for ( playerIdxj = 0; *(_BYTE *)(thisa + 1166) > playerIdxj; ++playerIdxj )
  {
    if ( playerIdxj || !loadOrNewGameSelected || !*(_BYTE *)(thisa + 127) && !*(_BYTE *)(thisa + 132) )
      goto LABEL_195;
    v20 = *(_BYTE *)(thisa + 127) ? 2 : 5;
    for ( k = 0; k < 54 && (*(_BYTE *)(thisa + 250 * k + 10203) != v20 || *(_BYTE *)(k + thisa + 23680) != -1); ++k )
      ;
    if ( k < 54 )
    {
      if ( *(_BYTE *)(thisa + 127) )
      {
        *(_DWORD *)(thisa + 250 * k + 10237) += 5000;
        Hero::checkForLevelUp((Hero *)(thisa + 250 * k + 10180));
        strcpy((char *)(thisa + 250 * k + 10190), "Sister Eliza");
        *(_BYTE *)(thisa + 250 * k + 10204) = 56;
      }
      else
      {
        *(_DWORD *)(thisa + 250 * k + 10237) += 5000;
        Hero::checkForLevelUp((Hero *)(thisa + 250 * k + 10180));
        strcpy((char *)(thisa + 250 * k + 10190), "Brother Brax");
        *(_BYTE *)(thisa + 250 * k + 10204) = 59;
      }
      *(_BYTE *)(thisa + 1192) = k;
      *(_BYTE *)(*(_BYTE *)(thisa + 1192) + thisa + 23680) = 64;
      faction = *(_BYTE *)(thisa + 250 * k + 10203);
    }
    else
    {
LABEL_195:
      if ( !byte_5304A0 || playerIdxj )
        goto LABEL_196;
      v21 = -1;
      if ( sub_470560(&unk_530450, 6) )
      {
        v21 = 4;
        v18 = sub_4728E0((int)&unk_530450);
        v19 = 64;
      }
      else
      {
        if ( sub_470560(&unk_530450, 7) )
        {
          v21 = 1;
          v18 = sub_472920((int)&unk_530450);
          v19 = 63;
        }
      }
      if ( v21 == -1 )
        goto LABEL_196;
      for ( l = 0; l < 54 && (*(_BYTE *)(thisa + 250 * l + 10203) != v21 || *(_BYTE *)(l + thisa + 23680) != -1); ++l )
        ;
      if ( l >= 54 )
      {
LABEL_196:
        faction = unseededNextRand(0, 5);
        if ( (signed int)*(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxj + thisa + 1180)] + thisa + 1113) < 6 )
          faction = *(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxj + thisa + 1180)] + thisa + 1113);
        *(_BYTE *)(283 * playerIdxj + thisa + 1192) = GameInfo::getRandomHeroFromHeroPool(
                                                        (GameInfo *)thisa,
                                                        playerIdxj,
                                                        faction,
                                                        0);
        *(_BYTE *)(*(_BYTE *)(283 * playerIdxj + thisa + 1192) + thisa + 23680) = 64;
      }
      else
      {
        *(_DWORD *)(thisa + 250 * l + 10237) = 5000;
        Hero::checkForLevelUp((Hero *)(thisa + 250 * l + 10180));
        strcpy((char *)(thisa + 250 * l + 10190), v18);
        *(_BYTE *)(thisa + 250 * l + 10204) = v19;
        *(_BYTE *)(thisa + 1192) = l;
        *(_BYTE *)(*(_BYTE *)(thisa + 1192) + thisa + 23680) = 64;
        faction = *(_BYTE *)(thisa + 250 * l + 10203);
      }
    }
    v2 = unseededNextRand(1, 5);
    *(_BYTE *)(283 * playerIdxj + thisa + 1193) = GameInfo::getRandomHeroFromHeroPool(
                                                    (GameInfo *)thisa,
                                                    playerIdxj,
                                                    (faction + v2) % 6,
                                                    0);
    *(_BYTE *)(*(_BYTE *)(283 * playerIdxj + thisa + 1193) + thisa + 23680) = 64;
  }
  for ( playerIdxk = 0; *(_BYTE *)(thisa + 1166) > playerIdxk; ++playerIdxk )
  {
    for ( m = 0; *(_BYTE *)(283 * playerIdxk + thisa + 1181) > m; ++m )
    {
      v3 = *(_DWORD *)(thisa + 250 * *(_BYTE *)(m + 283 * playerIdxk + thisa + 1184) + 10205);
      v4 = *(_DWORD *)(thisa + 250 * *(_BYTE *)(m + 283 * playerIdxk + thisa + 1184) + 10209);
      *(_WORD *)(thisa + 250 * *(_BYTE *)(m + 283 * playerIdxk + thisa + 1184) + 10225) = *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v4 * *(_DWORD *)(thisa + 2886) + 12 * v3 + 9);
      *(_WORD *)(thisa + 250 * *(_BYTE *)(m + 283 * playerIdxk + thisa + 1184) + 10227) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(thisa + 2878) + 12 * v4 * *(_DWORD *)(thisa + 2886) + 12 * v3 + 4) >> 8) >> -5);
      *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v4 * *(_DWORD *)(thisa + 2886) + 12 * v3 + 9) = -86;
      v5 = *(_DWORD *)(thisa + 2878) + 12 * v4 * *(_DWORD *)(thisa + 2886) + 12 * v3;
      *(_WORD *)(v5 + 4) = *(_WORD *)(v5 + 4) & 7 | 8 * *(_BYTE *)(m + 283 * playerIdxk + thisa + 1184);
    }
    if ( (signed int)*(_BYTE *)(283 * playerIdxk + thisa + 1181) <= 0 )
    {
      if ( (signed int)*(_BYTE *)(283 * playerIdxk + thisa + 1248) > 0 )
        *(_BYTE *)(283 * playerIdxk + thisa + 1249) = *(_BYTE *)(283 * playerIdxk + thisa + 1251);
    }
    else
    {
      *(_BYTE *)(283 * playerIdxk + thisa + 1182) = *(_BYTE *)(283 * playerIdxk + thisa + 1184);
    }
  }
  playerIdxl = -1;
  v30 = -1;
  v48 = 0;
  v6 = unseededNextRand(1, 30);
  v7 = unseededNextRand(1, 20) + v6;
  v54 = unseededNextRand(1, 20) + v7;
  while ( 1 )
  {
    if ( playerIdxl >= 9 )
    {
      if ( v30 >= 9 )
      {
        if ( mapWidth - 10 >= playerIdxl )
        {
          if ( mapHeight - 10 >= v30 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v30 * *(_DWORD *)(thisa + 2886) + 12 * playerIdxl + 3) == 255 )
            {
              if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v30 * *(_DWORD *)(thisa + 2886) + 12 * playerIdxl + 7) == 255 )
              {
                if ( tileToTerrainType[*(_WORD *)(*(_DWORD *)(thisa + 2878)
                                                + 12 * v30 * *(_DWORD *)(thisa + 2886)
                                                + 12 * playerIdxl)] )
                {
                  if ( dword_5235D4 != 1 )
                    break;
                  if ( v48 >= 200 )
                    break;
                  v8 = abs(v30 - *(_DWORD *)(thisa + 250 * *(_BYTE *)(thisa + 1184) + 10209));
                  if ( abs(playerIdxl - *(_DWORD *)(thisa + 250 * *(_BYTE *)(thisa + 1184) + 10205)) + v8 > v54 )
                    break;
                }
              }
            }
          }
        }
      }
    }
    if ( v48 >= 400 || word_522FB4 <= 0 )
    {
      playerIdxl = unseededNextRand(9, mapWidth - 10);
      v30 = unseededNextRand(9, mapHeight - 10);
    }
    else
    {
      if ( word_522F90 )
        v16 = unseededNextRand(-word_522F90, word_522F90);
      else
        v16 = 0;
      playerIdxl = v16 + word_522FB4;
      if ( word_522F90 )
        v15 = unseededNextRand(-word_522F90, word_522F90);
      else
        v15 = 0;
      v30 = v15 + word_522FB8;
    }
    v9 = unseededNextRand(1, 30);
    v10 = unseededNextRand(1, 20) + v9;
    v54 = unseededNextRand(1, 20) + v10;
    ++v48;
  }
  *(_BYTE *)(thisa + 25493) = playerIdxl;
  *(_BYTE *)(thisa + 25494) = v30;
  *(_BYTE *)(thisa + 25495) = unseededNextRand(0, 7);
  if ( loadOrNewGameSelected
    && (!*(_BYTE *)(thisa + 2) && *(_BYTE *)(thisa + 4) == 7 || *(_BYTE *)(thisa + 2) == 1 && *(_BYTE *)(thisa + 4) == 8) )
    *(_BYTE *)(thisa + 25495) = 6;
  for ( playerIdxm = 0; *(_BYTE *)(thisa + 1166) > playerIdxm; ++playerIdxm )
  {
    if ( dword_524810[playerIdxm] )
    {
      *(_DWORD *)(283 * playerIdxm + thisa + 1195) = 3;
      memcpy((void *)(thisa + 283 * playerIdxm + 1323), (char *)&unk_4F1E00 + 28 * *(_BYTE *)(thisa + 1125), 0x1Cu);
      if ( *(_BYTE *)(playerIdxm + thisa + 1107) )
      {
        for ( n = 0; n < 7; ++n )
        {
          if ( *(_BYTE *)(playerIdxm + thisa + 1107) == 1 )
            v14 = 0.85;
          else
            v14 = 0.7;
          *(_DWORD *)(283 * playerIdxm + 4 * n + thisa + 1323) = (signed __int64)((double)*(signed int *)(283 * playerIdxm + 4 * n + thisa + 1323)
                                                                                * v14);
        }
      }
    }
    else
    {
      *(_DWORD *)(283 * playerIdxm + thisa + 1195) = unseededNextRand(0, 2);
      memcpy((void *)(thisa + 283 * playerIdxm + 1323), (char *)&unk_4F1E90 + 28 * *(_BYTE *)(thisa + 1125), 0x1Cu);
    }
  }
  sub_4292B0();
  if ( *(_BYTE *)(thisa + 715) == 2 )
  {
    v49 = *(_WORD *)(thisa + 716);
    v11 = *(_WORD *)(thisa + 727);
    *(_WORD *)(thisa + 716) = 0;
    if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v11 * *(_DWORD *)(thisa + 2886) + 12 * v49 + 9) == 170 )
    {
      *(_WORD *)(thisa + 716) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(thisa + 2878)
                                                                             + 12 * v11 * *(_DWORD *)(thisa + 2886)
                                                                             + 12 * v49
                                                                             + 4) >> 8) >> -5);
    }
    else
    {
      if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * (v11 - 1) * *(_DWORD *)(thisa + 2886) + 12 * v49 + 9) == 170 )
        *(_WORD *)(thisa + 716) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(thisa + 2878)
                                                                               + 12
                                                                               * (v11 - 1)
                                                                               * *(_DWORD *)(thisa + 2886)
                                                                               + 12 * v49
                                                                               + 4) >> 8) >> -5);
      else
        *(_BYTE *)(thisa + 715) = 0;
    }
  }
  if ( *(_BYTE *)(thisa + 710) == 2 )
  {
    v50 = *(_WORD *)(thisa + 713);
    v12 = *(_WORD *)(thisa + 725);
    *(_WORD *)(thisa + 713) = 0;
    if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * v12 * *(_DWORD *)(thisa + 2886) + 12 * v50 + 9) == 170 )
    {
      *(_WORD *)(thisa + 713) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(thisa + 2878)
                                                                             + 12 * v12 * *(_DWORD *)(thisa + 2886)
                                                                             + 12 * v50
                                                                             + 4) >> 8) >> -5);
    }
    else
    {
      if ( *(_BYTE *)(*(_DWORD *)(thisa + 2878) + 12 * (v12 - 1) * *(_DWORD *)(thisa + 2886) + 12 * v50 + 9) == 170 )
        *(_WORD *)(thisa + 713) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(thisa + 2878)
                                                                               + 12
                                                                               * (v12 - 1)
                                                                               * *(_DWORD *)(thisa + 2886)
                                                                               + 12 * v50
                                                                               + 4) >> 8) >> -5);
      else
        *(_BYTE *)(thisa + 710) = 0;
    }
  }
  for ( playerIdxn = 0; *(_BYTE *)(thisa + 1166) > playerIdxn; ++playerIdxn )
  {
    v17 = 0;
    if ( (signed int)*(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxn + thisa + 1180)] + thisa + 1113) < 0
      || (signed int)*(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxn + thisa + 1180)] + thisa + 1113) >= 6 )
    {
      if ( *(_BYTE *)(283 * playerIdxn + thisa + 1248) )
      {
        v17 = gameObject->castles[*(_BYTE *)(283 * playerIdxn + thisa + 1251)].factionID;
      }
      else
      {
        if ( *(_BYTE *)(283 * playerIdxn + thisa + 1181) )
          v17 = gameObject->heroes[*(_BYTE *)(283 * playerIdxn + thisa + 1184)].factionID;
      }
    }
    else
    {
      v17 = *(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxn + thisa + 1180)] + thisa + 1113);
    }
    *(_BYTE *)(283 * playerIdxn + thisa + 1351) = v17 == 1 || v17 == 3 || v17 == 5;
    if ( loadOrNewGameSelected && !playerIdxn )
      *(_BYTE *)(thisa + 1351) = *(_BYTE *)(thisa + 2) == 1;
    for ( ii = 0; gameObject->players[playerIdxn].numCastles > ii; ++ii )
      Castle::grantHeroSpellsFromMageGuild(&gameObject->castles[gameObject->players[playerIdxn].castlesOwned[ii]], 0);
    gameObject->players[playerIdxn]._2 = gameObject->players[playerIdxn].numHeroes;
  }
  sub_4AD070();
  dword_523F1C = 0;
  sub_42DA40(thisa);
  sub_444550(advManager, 0, -1);
}
