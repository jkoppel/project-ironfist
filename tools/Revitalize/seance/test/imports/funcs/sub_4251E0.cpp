{
  char v1; // al@52
  int v2; // STD0_4@64
  int v3; // STC8_4@65
  __int16 v4; // ax@65
  int v5; // STC4_4@67
  __int16 v6; // ax@67
  __int16 v7; // ax@70
  __int16 v8; // ax@71
  int v9; // STBC_4@73
  int v10; // STB4_4@75
  int v11; // STAC_4@78
  int v12; // STA4_4@81
  int v13; // ST9C_4@84
  int v14; // ST94_4@87
  int v15; // ST8C_4@90
  int v16; // ST84_4@93
  int v17; // ST7C_4@96
  int v18; // ST74_4@99
  int v19; // ST6C_4@102
  int v20; // ST64_4@105
  int v21; // ST5C_4@108
  int v22; // ST54_4@111
  int v23; // ST4C_4@114
  int v24; // ST44_4@117
  int v25; // ST3C_4@121
  int v26; // ST34_4@125
  int v27; // ST2C_4@129
  int v28; // [sp+1Ch] [bp-DCh]@1
  int v29; // [sp+B4h] [bp-44h]@69
  int getPowerfulHero; // [sp+C8h] [bp-30h]@50
  int v31; // [sp+D0h] [bp-28h]@60
  signed int v32; // [sp+D4h] [bp-24h]@60
  int v33; // [sp+D4h] [bp-24h]@62
  signed int v34; // [sp+D8h] [bp-20h]@9
  int v35; // [sp+DCh] [bp-1Ch]@6
  signed int i; // [sp+E0h] [bp-18h]@6
  signed int j; // [sp+E0h] [bp-18h]@33
  signed int playerIdx; // [sp+E4h] [bp-14h]@4
  int playerIdxa; // [sp+E4h] [bp-14h]@31
  signed int playerIdxb; // [sp+E4h] [bp-14h]@136
  int k; // [sp+E8h] [bp-10h]@54
  int l; // [sp+ECh] [bp-Ch]@56
  signed int faction; // [sp+F0h] [bp-8h]@38
  int v44; // [sp+F4h] [bp-4h]@1

  v28 = (int)this;
  v44 = 0;
  *(_DWORD *)&dword_523448 = 0;
  *(_DWORD *)&dword_523F10 = unseededNextRand(0, 14);
  if ( *(_WORD *)(v28 + 1176) != 4 && unseededNextRand(1, 4) == 1 )
  {
    *(_DWORD *)&dword_523448 = 1;
    *(_DWORD *)&dword_523F10 = unseededNextRand(0, 56);
  }
  for ( playerIdx = 0; playerIdx < 72; ++playerIdx )
  {
    v35 = v28 + 100 * playerIdx + 2899;
    for ( i = 19; i <= 30; ++i )
    {
      if ( (1 << i) & *(_DWORD *)(v28 + 100 * playerIdx + 2923) )
      {
        v34 = creature_table[LOBYTE((&buildingShortNames[3 * *(_BYTE *)(v28 + 100 * playerIdx + 2902) + 27])[i + 1])].growth;
        if ( *(_BYTE *)(v28 + 100 * playerIdx + 2923) & 0x10 )
          v34 += 2;
        if ( i == 19 && *(_BYTE *)(v28 + 100 * playerIdx + 2924) & 8 )
          v34 += 8;
        if ( *(_BYTE *)(v28 + 100 * playerIdx + 2900) == -1 )
          v34 /= 2;
        if ( (signed int)*(_BYTE *)(v28 + 100 * playerIdx + 2900) >= 0
          && !*(_WORD *)(v35 + 2 * i - 8)
          && !dword_524810[*(_BYTE *)(v28 + 100 * playerIdx + 2900)] )
        {
          if ( gameObject->difficulty == 2 )
            v34 = (signed __int64)((double)v34 * 1.2);
          if ( gameObject->difficulty == 3 )
            v34 = (signed __int64)((double)v34 * 1.32);
          if ( gameObject->difficulty == 4 )
            v34 = (signed __int64)((double)v34 * 1.44);
        }
        if ( *(_DWORD *)&dword_523448 == 1 )
        {
          if ( LOBYTE((&buildingShortNames[3 * *(_BYTE *)(v28 + 100 * playerIdx + 2902) + 27])[i + 1]) == *(_DWORD *)&dword_523F10 )
            LOWORD(v34) = v34 + 5;
        }
        *(_WORD *)(v35 + 2 * i - 8) += v34;
      }
    }
  }
  for ( playerIdxa = 0; playerIdxa < 6; ++playerIdxa )
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( j == 1 )
        v44 = *(_BYTE *)(v28 + 250 * gameObject->players[playerIdxa].heroesForPurchase[0] + 10203);
      v44 = (v44 + unseededNextRand(1, 5)) % 6;
      faction = v44;
      if ( !j && (signed int)*(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxa + v28 + 1180)] + v28 + 1113) < 6 )
        faction = *(_BYTE *)(byte_524220[*(_BYTE *)(283 * playerIdxa + v28 + 1180)] + v28 + 1113);
      if ( gameObject->relatedToHeroForHireStatus[*(&gameObject->players[0].heroesForPurchase[284 * playerIdxa]
                                                  + j
                                                  - playerIdxa)] != 64
        || !(gameObject->heroes[*(&gameObject->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa)].flags3 & 1) )
      {
        if ( gameObject->relatedToHeroForHireStatus[*(&gameObject->players[0].heroesForPurchase[284 * playerIdxa]
                                                    + j
                                                    - playerIdxa)] == 64 )
          gameObject->relatedToHeroForHireStatus[*(&gameObject->players[0].heroesForPurchase[284 * playerIdxa]
                                                 + j
                                                 - playerIdxa)] = -1;
        if ( j == 1 && !dword_524810[playerIdxa] )
          faction = -1;
        getPowerfulHero = !dword_524810[playerIdxa] && gameObject->difficulty > 0;
        v1 = GameInfo::getRandomHeroFromHeroPool(gameObject, playerIdxa, faction, getPowerfulHero);
        *(&gameObject->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa) = v1;
        *(_BYTE *)(*(&gameObject->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa) + v28 + 23680) = 64;
      }
    }
  }
  for ( k = 0; mapHeight > k; ++k )
  {
    for ( l = 0; l < mapWidth; ++l )
    {
      switch ( *(_BYTE *)(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l + 9) )
      {
        case 0x98:
          v32 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                             + 12 * k * *(_DWORD *)(v28 + 2886)
                                                             + 12 * l
                                                             + 4) >> 8) >> -5);
          v31 = v32 / 7;
          if ( unseededNextRand(1, 7) <= v32 % 7 )
            ++v31;
          v33 = v31 + v32;
          if ( v33 > 4000 )
            LOWORD(v33) = 4000;
          v2 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
          *(_WORD *)(v2 + 4) = *(_WORD *)(v2 + 4) & 7 | 8
                                                      * (v33 | ((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                                           + 12
                                                                                           * k
                                                                                           * *(_DWORD *)(v28 + 2886)
                                                                                           + 12 * l
                                                                                           + 4) >> 8) >> -5) & 0);
          break;
        case 0xD2:
          v3 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
          v4 = *(_WORD *)(v3 + 4) & 7;
          LOBYTE(v4) = v4 | 8;
          *(_WORD *)(v3 + 4) = v4;
          break;
        case 0x96:
          if ( (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                            + 12 * k * *(_DWORD *)(v28 + 2886)
                                                            + 12 * l
                                                            + 4) >> 8) >> -5) != 255 )
          {
            v5 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            v6 = *(_WORD *)(v5 + 4) & 7;
            LOBYTE(v6) = v6 | 0x10;
            *(_WORD *)(v5 + 4) = v6;
          }
          break;
        case 0xDF:
          v29 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
          if ( unseededNextRand(0, 1) )
          {
            v7 = *(_WORD *)(v29 + 4) & 7;
            LOBYTE(v7) = v7 | 0x38;
            *(_WORD *)(v29 + 4) = v7;
          }
          else
          {
            v8 = *(_WORD *)(v29 + 4) & 7;
            LOBYTE(v8) = v8 | 0x30;
            *(_WORD *)(v29 + 4) = v8;
          }
          break;
        case 0xA8:
          v9 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
          *(_WORD *)(v9 + 4) = *(_WORD *)(v9 + 4) & 7 | 8 * unseededNextRand(1, 5);
          break;
        case 0x8D:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v10 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v10 + 4) = *(_WORD *)(v10 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v10 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(2, 4));
          }
          break;
        case 0x8E:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v11 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v11 + 4) = *(_WORD *)(v11 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v11 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(3, 6));
          }
          break;
        case 0x8F:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v12 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v12 + 4) = *(_WORD *)(v12 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v12 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(2, 4));
          }
          break;
        case 0x90:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v13 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v13 + 4) = *(_WORD *)(v13 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(5, 10));
          }
          break;
        case 0x91:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v14 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v14 + 4) = *(_WORD *)(v14 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v14 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(5, 10));
          }
          break;
        case 0xA2:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v15 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v15 + 4) = *(_WORD *)(v15 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v15 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(1, 3));
          }
          break;
        case 0xA5:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v16 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v16 + 4) = *(_WORD *)(v16 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v16 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(3, 6));
          }
          break;
        case 0xBB:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v17 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v17 + 4) = *(_WORD *)(v17 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v17 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(4, 8));
          }
          break;
        case 0xC1:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v18 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v18 + 4) = *(_WORD *)(v18 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(3, 6));
          }
          break;
        case 0xBA:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v19 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v19 + 4) = *(_WORD *)(v19 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v19 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(1, 4));
          }
          break;
        case 0xBD:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v20 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v20 + 4) = *(_WORD *)(v20 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v20 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(1, 3));
          }
          break;
        case 0xBC:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8161 )
          {
            v21 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v21 + 4) = *(_WORD *)(v21 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v21 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(10, 20));
          }
          break;
        case 0xD7:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v22 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v22 + 4) = *(_WORD *)(v22 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v22 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(3, 6));
          }
          break;
        case 0xCE:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v23 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v23 + 4) = *(_WORD *)(v23 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v23 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(4, 8));
          }
          break;
        case 0xC8:
          if ( (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 8171 )
          {
            v24 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v24 + 4) = *(_WORD *)(v24 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v24 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(5, 10));
          }
          break;
        case 0xD3:
          if ( !((*(_WORD *)(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l + 4) >> 3) & 0x80)
            && (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 220 )
          {
            v25 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v25 + 4) = *(_WORD *)(v25 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(1, 3));
          }
          break;
        case 0xCD:
          if ( !((*(_WORD *)(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l + 4) >> 3) & 0x80)
            && (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 220 )
          {
            v26 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v26 + 4) = *(_WORD *)(v26 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v26 + 4) >> 8) >> -5)
                                                           + (unsigned __int16)unseededNextRand(1, 3));
          }
          break;
        case 0x94:
          if ( !((*(_WORD *)(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l + 4) >> 3) & 0x80)
            && (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v28 + 2878)
                                                                        + 12 * k * *(_DWORD *)(v28 + 2886)
                                                                        + 12 * l
                                                                        + 4) >> 8) >> -5) < 220 )
          {
            v27 = *(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l;
            *(_WORD *)(v27 + 4) = *(_WORD *)(v27 + 4) & 7 | 8
                                                          * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v27 + 4) >> 8) >> -5)
                                                           + 1);
          }
          break;
        case 0xF9:
          sub_426B80(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l);
          break;
        case 0xFA:
          sub_426CB0(*(_DWORD *)(v28 + 2878) + 12 * k * *(_DWORD *)(v28 + 2886) + 12 * l);
          break;
        case 0x92:
        case 0x93:
        case 0x95:
        case 0x97:
        case 0x99:
        case 0x9A:
        case 0x9B:
        case 0x9C:
        case 0x9D:
        case 0x9E:
        case 0x9F:
        case 0xA0:
        case 0xA1:
        case 0xA3:
        case 0xA4:
        case 0xA6:
        case 0xA7:
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC:
        case 0xAD:
        case 0xAE:
        case 0xAF:
        case 0xB0:
        case 0xB1:
        case 0xB2:
        case 0xB3:
        case 0xB4:
        case 0xB5:
        case 0xB6:
        case 0xB7:
        case 0xB8:
        case 0xB9:
        case 0xBE:
        case 0xBF:
        case 0xC0:
        case 0xC2:
        case 0xC3:
        case 0xC4:
        case 0xC5:
        case 0xC6:
        case 0xC7:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xCF:
        case 0xD0:
        case 0xD1:
        case 0xD4:
        case 0xD5:
        case 0xD6:
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
        case 0xDD:
        case 0xDE:
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xE7:
        case 0xE8:
        case 0xE9:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:
        case 0xF0:
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:
        case 0xF8:
          continue;
      }
    }
  }
  for ( playerIdxb = 0; playerIdxb < 54; ++playerIdxb )
  {
    if ( *(_BYTE *)(v28 + 250 * playerIdxb + 10409) & 0x80 )
      *(_DWORD *)(v28 + 250 * playerIdxb + 10407) -= 8388608;
  }
  ++*(_WORD *)(v28 + 1176);
  sub_42DA40(v28);
  sub_41C4D0((void *)v28);
}
