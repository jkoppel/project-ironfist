{
  __int16 v1; // ax@7
  __int16 v2; // ax@35
  __int16 v3; // ST100_2@36
  __int16 v4; // STFC_2@41
  __int16 v5; // STF8_2@42
  __int16 v6; // STF0_2@44
  __int16 v7; // ax@45
  __int16 v8; // ax@46
  __int16 v9; // ax@47
  __int16 v10; // ax@48
  __int16 v11; // ax@55
  __int16 v12; // STE8_2@56
  __int16 v13; // ax@59
  __int16 v14; // ax@61
  __int16 v15; // ax@63
  __int16 v16; // STE4_2@64
  __int16 v17; // STD4_2@69
  __int16 v18; // STD0_2@71
  __int16 v19; // STCC_2@72
  __int16 v20; // ax@74
  __int16 v21; // ax@75
  __int16 v22; // ax@76
  __int16 v23; // ax@77
  __int16 v24; // ax@85
  __int16 v25; // ax@86
  __int16 v26; // ax@88
  __int16 v27; // ax@89
  __int16 v28; // ax@143
  __int16 v29; // ax@145
  __int16 v30; // ax@146
  __int16 v31; // ax@150
  __int16 v32; // ax@156
  int v33; // ST40_4@167
  int v34; // ST3C_4@176
  int v35; // ST34_4@187
  int result; // eax@216
  int v37; // [sp+Ch] [bp-1D8h]@101
  int v38; // [sp+1Ch] [bp-1C8h]@1
  int v39; // [sp+100h] [bp-E4h]@249
  int v40[5]; // [sp+104h] [bp-E0h]@236
  int v41[5]; // [sp+118h] [bp-CCh]@236
  int v42[5]; // [sp+12Ch] [bp-B8h]@250
  int v43; // [sp+140h] [bp-A4h]@227
  int v44; // [sp+144h] [bp-A0h]@227
  int v45[5]; // [sp+148h] [bp-9Ch]@250
  int v46; // [sp+15Ch] [bp-88h]@171
  int v47; // [sp+160h] [bp-84h]@156
  int v48; // [sp+164h] [bp-80h]@156
  int v49; // [sp+168h] [bp-7Ch]@156
  int v50; // [sp+16Ch] [bp-78h]@156
  int v51; // [sp+170h] [bp-74h]@156
  int v52; // [sp+174h] [bp-70h]@156
  int v53; // [sp+178h] [bp-6Ch]@156
  int v54; // [sp+17Ch] [bp-68h]@156
  int v55; // [sp+180h] [bp-64h]@156
  int v56; // [sp+184h] [bp-60h]@156
  int v57; // [sp+188h] [bp-5Ch]@170
  int v58; // [sp+18Ch] [bp-58h]@18
  int v59; // [sp+190h] [bp-54h]@13
  int v60; // [sp+194h] [bp-50h]@162
  int v61; // [sp+198h] [bp-4Ch]@1
  int v62; // [sp+19Ch] [bp-48h]@1
  int v63; // [sp+1A0h] [bp-44h]@1
  int v64; // [sp+1A4h] [bp-40h]@1
  int k; // [sp+1A8h] [bp-3Ch]@162
  int v66; // [sp+1ACh] [bp-38h]@1
  int ii; // [sp+1B0h] [bp-34h]@265
  int v68; // [sp+1B4h] [bp-30h]@6
  int i; // [sp+1B8h] [bp-2Ch]@1
  int n; // [sp+1BCh] [bp-28h]@38
  int l; // [sp+1C0h] [bp-24h]@164
  int v72; // [sp+1C4h] [bp-20h]@207
  int j; // [sp+1C8h] [bp-1Ch]@3
  int v74; // [sp+1CCh] [bp-18h]@140
  int v75; // [sp+1D0h] [bp-14h]@1
  int v76; // [sp+1D4h] [bp-10h]@205
  int m; // [sp+1D8h] [bp-Ch]@205
  int v78; // [sp+1DCh] [bp-8h]@1
  int v79; // [sp+1E0h] [bp-4h]@1

  v38 = this;
  v78 = 1;
  v61 = 1;
  v66 = 1;
  v62 = 1;
  v63 = 1;
  v79 = 1;
  v75 = 1;
  v64 = 1;
  *(_WORD *)(this + 25979) = 0;
  memset((void *)(this + 25981), 0, 0x64u);
  for ( i = 0; i < mapHeight; ++i )
  {
    for ( j = 0; mapWidth > j; ++j )
    {
      v68 = *(_DWORD *)(v38 + 2878) + 12 * i * *(_DWORD *)(v38 + 2886) + 12 * j;
      switch ( *(_BYTE *)(v68 + 9) )
      {
        case 0xD5:
          v1 = *(_WORD *)(v68 + 4) & 7;
          LOBYTE(v1) = v1 | 0x60;
          for ( *(_WORD *)(v68 + 4) = v1;
                (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) == 12
             || (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) == 6;
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(0, 13) )
            ;
          break;
        case 0xAB:
          *(_BYTE *)(v68 + 2) &= 3u;
          *(_BYTE *)(v68 + 3) = -1;
          *(_WORD *)(v68 + 4) &= 7u;
          *(_BYTE *)(v68 + 9) = 0;
          sub_419870((void *)v38, j, i, 1);
          break;
        case 0xCF:
          v59 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5));
          *(_BYTE *)v59 = strlen((const char *)(v59 + 136)) > 1 && (signed int)*(_BYTE *)(v59 + 31) >= 1;
          break;
        case 0x93:
          *(_WORD *)(v38 + 2 * *(_WORD *)(v38 + 25979) + 25981) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5);
          v58 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5));
          *(_WORD *)(v58 + 38) = j;
          *(_WORD *)(v58 + 40) = i;
          *(_BYTE *)(v58 + 37) = 1;
          *(_WORD *)(v68 + 4) &= 7u;
          *(_BYTE *)(v68 + 9) = 0;
          *(_BYTE *)(v68 + 3) = -1;
          *(_BYTE *)(v68 + 2) &= 3u;
          ++*(_WORD *)(v38 + 25979);
          break;
        case 0x8A:
          *(_WORD *)(v68 + 4) = 8 * v61++ | *(_WORD *)(v68 + 4) & 7;
          break;
        case 0xBE:
          *(_WORD *)(v68 + 4) = 8 * v66++ | *(_WORD *)(v68 + 4) & 7;
          break;
        case 0xC5:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v62++;
          break;
        case 0xC9:
          *(_WORD *)(v68 + 4) = 8 * v63++ | *(_WORD *)(v68 + 4) & 7;
          break;
        case 0xC2:
          if ( j <= 0
            || *(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * i * *(_DWORD *)(v38 + 2886) + 4 * (3 * j - 3) + 9) != 194 )
            *(_WORD *)(v68 + 4) = 8 * v79++ | *(_WORD *)(v68 + 4) & 7;
          else
            *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                          * (*(_WORD *)(*(_DWORD *)(v38 + 2878)
                                                                      + 12 * i * *(_DWORD *)(v38 + 2886)
                                                                      + 4 * (3 * j - 3)
                                                                      + 4) >> 3);
          break;
        case 0xD6:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v64++;
          break;
        case 0x27:
          *(_BYTE *)(v68 + 9) |= 0x80u;
          break;
        case 0x99:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v78++;
          break;
        case 0xDA:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(0, 3);
          break;
        case 0x84:
          if ( sub_429930(v38, j, i, 55, 84) )
          {
            if ( unseededNextRand(0, 9) <= 2 )
            {
              v3 = GameInfo::randomArtifact((GameInfo *)v38, 14, 1);
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v3 + 2);
            }
            else
            {
              v2 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v2) = v2 | 8;
              *(_WORD *)(v68 + 4) = v2;
            }
          }
          else
          {
            *(_BYTE *)(v68 + 9) &= 0x7Fu;
          }
          break;
        case 0xD0:
          n = unseededNextRand(0, 100);
          if ( n >= 40 )
          {
            if ( n >= 50 )
            {
              v5 = unseededNextRand(0, 5);
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v5 + 16 * unseededNextRand(2, 5) + 1);
            }
            else
            {
              v4 = GameInfo::randomArtifact((GameInfo *)v38, 12, 1);
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v4 | 0x80);
            }
          }
          else
          {
            *(_WORD *)(v68 + 4) &= 7u;
          }
          break;
        case 0xD8:
          v6 = unseededNextRand(0, 5);
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v6 + 16 * unseededNextRand(1, 4) + 1);
          break;
        case 0x85:
          switch ( unseededNextRand(0, 99) % 10 )
          {
            case 0:
            case 1:
            case 2:
              v7 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v7) = v7 | 0x10;
              *(_WORD *)(v68 + 4) = v7;
              break;
            case 3:
              v8 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v8) = v8 | 0x18;
              *(_WORD *)(v68 + 4) = v8;
              break;
            case 4:
            case 5:
            case 6:
              v9 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v9) = v9 | 0x20;
              *(_WORD *)(v68 + 4) = v9;
              break;
            case 7:
            case 8:
            case 9:
              v10 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v10) = v10 | 0x28;
              *(_WORD *)(v68 + 4) = v10;
              break;
            default:
              continue;
          }
          continue;
        case 0x86:
          if ( tileToTerrainType[*(_WORD *)v68] )
          {
            n = unseededNextRand(0, 100);
            if ( n >= 32 )
            {
              if ( n >= 64 )
              {
                if ( n >= 95 )
                {
                  v16 = GameInfo::randomArtifact((GameInfo *)v38, 8, 1);
                  *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v16 | 0x100);
                }
                else
                {
                  v15 = *(_WORD *)(v68 + 4) & 7;
                  LOBYTE(v15) = v15 | 0x20;
                  *(_WORD *)(v68 + 4) = v15;
                }
              }
              else
              {
                v14 = *(_WORD *)(v68 + 4) & 7;
                LOBYTE(v14) = v14 | 0x18;
                *(_WORD *)(v68 + 4) = v14;
              }
            }
            else
            {
              v13 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v13) = v13 | 0x10;
              *(_WORD *)(v68 + 4) = v13;
            }
          }
          else
          {
            *(_BYTE *)(v68 + 9) = -95;
            n = unseededNextRand(0, 100);
            if ( n >= 20 )
            {
              if ( n >= 90 )
              {
                v12 = GameInfo::randomArtifact((GameInfo *)v38, 8, 1);
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (v12 | 0x100);
              }
              else
              {
                v11 = *(_WORD *)(v68 + 4) & 7;
                LOBYTE(v11) = v11 | 8;
                *(_WORD *)(v68 + 4) = v11;
              }
            }
            else
            {
              *(_WORD *)(v68 + 4) &= 7u;
            }
          }
          break;
        case 0x88:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | ((unsigned __int16)unseededNextRand(4, 6) << 7);
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                        * (unseededNextRand(0, 5) | (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5));
          break;
        case 0x8B:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 2) + 2);
          break;
        case 0xDC:
          n = unseededNextRand(0, 100);
          if ( n >= 60 )
          {
            if ( n >= 80 )
            {
              v19 = GameInfo::randomArtifact((GameInfo *)v38, 2, 1);
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v19;
            }
            else
            {
              v18 = GameInfo::randomArtifact((GameInfo *)v38, 4, 1);
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v18;
            }
          }
          else
          {
            v17 = GameInfo::randomArtifact((GameInfo *)v38, 8, 1);
            *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * v17;
          }
          break;
        case 0x8C:
        case 0xA0:
        case 0xDB:
          switch ( unseededNextRand(0, 99) % 10 )
          {
            case 0:
            case 1:
            case 2:
              v20 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v20) = v20 | 0x10;
              *(_WORD *)(v68 + 4) = v20;
              break;
            case 3:
            case 4:
            case 5:
              v21 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v21) = v21 | 0x18;
              *(_WORD *)(v68 + 4) = v21;
              break;
            case 6:
            case 7:
            case 8:
              v22 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v22) = v22 | 0x20;
              *(_WORD *)(v68 + 4) = v22;
              break;
            case 9:
              v23 = *(_WORD *)(v68 + 4) & 7;
              LOBYTE(v23) = v23 | 0x28;
              *(_WORD *)(v68 + 4) = v23;
              break;
            default:
              continue;
          }
          continue;
        case 0x8D:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(10, 25);
          break;
        case 0x8E:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(15, 40);
          break;
        case 0x8F:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 20) + 1);
          break;
        case 0x90:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 40) + 1);
          break;
        case 0x91:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(20, 50);
          break;
        case 0x96:
          v24 = *(_WORD *)(v68 + 4) & 7;
          LOBYTE(v24) = v24 | 8;
          *(_WORD *)(v68 + 4) = v24;
          break;
        case 0xD2:
          v25 = *(_WORD *)(v68 + 4) & 7;
          LOBYTE(v25) = v25 | 8;
          *(_WORD *)(v68 + 4) = v25;
          break;
        case 0xDF:
          if ( unseededNextRand(0, 1) )
          {
            v26 = *(_WORD *)(v68 + 4) & 7;
            LOBYTE(v26) = v26 | 0x38;
            *(_WORD *)(v68 + 4) = v26;
          }
          else
          {
            v27 = *(_WORD *)(v68 + 4) & 7;
            LOBYTE(v27) = v27 | 0x30;
            *(_WORD *)(v68 + 4) = v27;
          }
          break;
        case 0xC4:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                        * (v75++ | (unsigned __int16)((unsigned __int16)unseededNextRand(1, 3) << 6));
          break;
        case 0x98:
          if ( !((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) )
          {
            *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * sub_423760(*(_BYTE *)(v68 + 3));
            if ( *(_BYTE *)(v68 + 3) != 59 )
            {
              if ( *(_BYTE *)(v68 + 3) != 62
                && *(_BYTE *)(v68 + 3) != 63
                && *(_BYTE *)(v68 + 3) != 64
                && *(_BYTE *)(v68 + 3) != 65
                && unseededNextRand(0, 100) < 20 )
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                              * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) | 0x1000);
            }
          }
          break;
        case 0x9B:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * ((signed int)*(_BYTE *)(v68 + 3) >> 1);
          v37 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5);
          if ( (unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5 && v37 != 2 )
          {
            if ( v37 == 6 )
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(5, 10);
            else
              *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(3, 6);
          }
          else
          {
            *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(5, 10);
          }
          break;
        case 0x9F:
          for ( *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1);
                spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) - 1].level != 1;
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1) )
            ;
          break;
        case 0xCA:
          for ( *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1);
                spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) - 1].level != 2;
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1) )
            ;
          break;
        case 0xCB:
          for ( *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1);
                spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) - 1].level != 3;
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1) )
            ;
          break;
        case 0xCC:
          for ( *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1);
                spell_table[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) - 1].level != 5;
                *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(0, 64) + 1) )
            ;
          break;
        case 0xBB:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(15, 25);
          break;
        case 0xC1:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(10, 20);
          break;
        case 0xBA:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(7, 10);
          break;
        case 0xBD:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(3, 5);
          break;
        case 0xBC:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(20, 40);
          break;
        case 0xC8:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(20, 40);
          break;
        case 0xD3:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(4, 6) | 0x100);
          break;
        case 0xCD:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * (unseededNextRand(4, 6) | 0x100);
          break;
        case 0x94:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 0x810;
          break;
        case 0xD7:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(10, 20);
          break;
        case 0xCE:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(10, 25);
          break;
        case 0xA2:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(10, 20);
          break;
        case 0xA5:
          if ( sub_429930(v38, j, i, 41, 129) )
            *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(30, 50);
          else
            *(_BYTE *)(v68 + 9) &= 0x7Fu;
          break;
        case 0xA9:
          n = unseededNextRand(0, 99);
          v74 = (signed int)*(_BYTE *)(v68 + 3) >> 1;
          if ( v74 != 86 )
          {
            if ( n >= 60 )
            {
              if ( n >= 80 )
              {
                v47 = 9;
                v48 = 10;
                v49 = 19;
                v50 = 60;
                v51 = 35;
                v52 = 36;
                v53 = 37;
                v54 = 56;
                v55 = 45;
                v56 = 46;
                LOBYTE(v32) = *(_WORD *)(v68 + 4) & 7;
                HIBYTE(v32) = 8;
                *(_WORD *)(v68 + 4) = v32;
                if ( (unsigned __int8)artifactLevels[v74] == 8 )
                {
                  *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                                * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5) | 0x39);
                }
                else
                {
                  if ( (unsigned __int8)artifactLevels[v74] == 4 )
                    *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                                  * (*((_WORD *)&v47 + 2 * unseededNextRand(0, 3)) | (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5));
                  else
                    *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                                  * (*((_WORD *)&v51 + 2 * unseededNextRand(0, 5)) | (unsigned __int8)((unsigned __int8)(*(_WORD *)(v68 + 4) >> 8) >> -5));
                }
              }
              else
              {
                switch ( artifactLevels[v74] )
                {
                  case 8:
                    v31 = *(_WORD *)(v68 + 4) & 7;
                    LOBYTE(v31) = v31 | 0x18;
                    *(_WORD *)(v68 + 4) = v31;
                    break;
                  case 4:
                    *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                                  * ((unsigned __int16)(16 * unseededNextRand(0, 5)) | 6);
                    break;
                  case 2:
                    *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8
                                                                  * ((unsigned __int16)(16 * unseededNextRand(0, 5)) | 7);
                    break;
                }
              }
            }
            else
            {
              if ( n % 10 == 1 )
              {
                v28 = *(_WORD *)(v68 + 4) & 7;
                LOBYTE(v28) = v28 | 0x20;
                *(_WORD *)(v68 + 4) = v28;
              }
              else
              {
                if ( n % 10 == 2 )
                {
                  v29 = *(_WORD *)(v68 + 4) & 7;
                  LOBYTE(v29) = v29 | 0x28;
                  *(_WORD *)(v68 + 4) = v29;
                }
                else
                {
                  v30 = *(_WORD *)(v68 + 4) & 7;
                  LOBYTE(v30) = v30 | 8;
                  *(_WORD *)(v68 + 4) = v30;
                }
              }
            }
          }
          break;
        case 0xA3:
          v60 = sub_419C90((void *)v38, j, i);
          for ( k = i - 3; i + 1 >= k; ++k )
          {
            for ( l = j - 2; j + 2 >= l; ++l )
            {
              if ( !((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v38 + 2878) + 12 * k * *(_DWORD *)(v38 + 2886) + 12 * l + 4) >> 8) >> -5) )
              {
                v33 = *(_DWORD *)(v38 + 2878) + 12 * k * *(_DWORD *)(v38 + 2886) + 12 * l;
                *(_WORD *)(v33 + 4) = *(_WORD *)(v33 + 4) & 7 | 8 * v60;
              }
            }
          }
          v57 = v38 + 100 * v60 + 2899;
          *(_BYTE *)(v38 + 100 * v60 + 2906) = -1;
          *(_BYTE *)(v57 + 6) = *(_BYTE *)(v57 + 7);
          if ( mapHeight - 3 >= i )
          {
            v46 = usedToCheckForBoatByCastle(advManager, j - 1, i + 2);
            if ( tileToTerrainType[*(_WORD *)v46] )
            {
              v46 = usedToCheckForBoatByCastle(advManager, j + 1, i + 2);
              if ( !tileToTerrainType[*(_WORD *)v46] )
              {
                *(_BYTE *)(v57 + 6) = j + 1;
                *(_BYTE *)(v57 + 7) = i + 2;
              }
            }
            else
            {
              *(_BYTE *)(v57 + 6) = j - 1;
              *(_BYTE *)(v57 + 7) = i + 2;
            }
          }
          break;
        case 0x95:
          v34 = *(_DWORD *)(v38 + 2878) + 12 * i * *(_DWORD *)(v38 + 2886) + 12 * j;
          *(_WORD *)(v34 + 4) = *(_WORD *)(v34 + 4) & 7 | 8 * sub_419D20((void *)v38, j, i);
          break;
        case 0xC0:
          v60 = sub_419D20((void *)v38, j, i);
          *(_BYTE *)(7 * v60 + v38 + 23737) = 59;
          *(_BYTE *)(7 * v60 + v38 + 23738) = unseededNextRand(30, 60);
          goto LABEL_178;
        case 0x81:
        case 0x97:
        case 0x9D:
LABEL_178:
          v60 = sub_419D20((void *)v38, j, i);
          for ( k = i - 1; i >= k; ++k )
          {
            for ( l = j - 2; j + 1 >= l; ++l )
            {
              if ( (j - 2 != l || *(_BYTE *)(v68 + 9) == 129)
                && (!((unsigned __int8)(*(_WORD *)(*(_DWORD *)(v38 + 2878)
                                                 + 12 * k * *(_DWORD *)(v38 + 2886)
                                                 + 12 * l
                                                 + 4) >> 8) >> -5)
                 || !((*(_BYTE *)(v68 + 9) & 0x7F ^ *(_BYTE *)(*(_DWORD *)(v38 + 2878)
                                                             + 12 * k * *(_DWORD *)(v38 + 2886)
                                                             + 12 * l
                                                             + 9)) & 0x7F)) )
              {
                v35 = *(_DWORD *)(v38 + 2878) + 12 * k * *(_DWORD *)(v38 + 2886) + 12 * l;
                *(_WORD *)(v35 + 4) = *(_WORD *)(v35 + 4) & 7 | 8 * v60;
              }
            }
          }
          break;
        case 0xA8:
          *(_WORD *)(v68 + 4) = *(_WORD *)(v68 + 4) & 7 | 8 * unseededNextRand(1, 5);
          break;
        case 0xF7:
          sub_420A10(v68);
          break;
        case 0xF8:
          sub_420A80(v68);
          break;
        case 0xFA:
          sub_426CB0(v68);
          break;
        case 0xF9:
          sub_426B80(v68);
          break;
        default:
          continue;
      }
    }
  }
  for ( i = 0; i < mapHeight; ++i )
  {
    for ( j = 0; mapWidth > j; ++j )
    {
      v68 = *(_DWORD *)(v38 + 2878) + 12 * i * *(_DWORD *)(v38 + 2886) + 12 * j;
      if ( *(_BYTE *)(v68 + 3) != 255 && (*(_WORD *)(v68 + 4) >> 1) & 1 )
      {
        v76 = 1;
        for ( m = *(_WORD *)(v68 + 10); m; m = *(_WORD *)v72 )
        {
          v72 = *(_DWORD *)(v38 + 2882) - m + 8 * m;
          if ( *(_BYTE *)(v72 + 3) != 255 && !((*(_BYTE *)(v72 + 4) >> 1) & 1) )
            v76 = 0;
        }
        if ( v76 )
          *(_BYTE *)(v68 + 8) |= 0x80u;
      }
    }
  }
  for ( i = 0; ; ++i )
  {
    result = mapHeight;
    if ( i >= mapHeight )
      break;
    for ( j = 0; mapWidth > j; ++j )
    {
      v68 = *(_DWORD *)(v38 + 2878) + 12 * i * *(_DWORD *)(v38 + 2886) + 12 * j;
      if ( (*(_BYTE *)(v68 + 9) & 0x7F) == 103 && ((*(_BYTE *)(v68 + 2) >> 2) & 0x3F) == 62 )
        *(_BYTE *)(v68 + 8) |= 8u;
      if ( *(_BYTE *)(v68 + 3) != 255
        && !(*(_BYTE *)(v68 + 9) & 0x80)
        && !(*(_BYTE *)(v68 + 8) & 0x80)
        && *(_BYTE *)(v68 + 7) != 255 )
        *(_BYTE *)(v68 + 8) |= 8u;
      v44 = 0;
      v43 = 0;
      if ( !(*(_BYTE *)(v68 + 8) & 8)
        && mapHeight - 1 > i
        && *(_BYTE *)(v68 + 3) != 255
        && !(*(_BYTE *)(v68 + 9) & 0x80)
        && !(*(_BYTE *)(v68 + 8) & 0x80)
        && *(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 3) != 255
        && !(*(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 9) & 0x80)
        && !(*(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 8) & 0x80) )
      {
        if ( !((*(_WORD *)(v68 + 4) >> 1) & 1) )
        {
          v40[v44] = (*(_BYTE *)(v68 + 2) >> 2) & 0x3F;
          v41[v44++] = *(_BYTE *)(v68 + 3);
        }
        if ( *(_WORD *)(v68 + 10) )
          v72 = *(_DWORD *)(v38 + 2882) + 7 * *(_WORD *)(v68 + 10);
        else
          v72 = 0;
        while ( v44 < 5 && v72 )
        {
          if ( *(_BYTE *)(v72 + 3) != 255 && !((*(_BYTE *)(v72 + 4) >> 1) & 1) )
          {
            v40[v44] = (*(_BYTE *)(v72 + 2) >> 1) & 0x7F;
            v41[v44++] = *(_BYTE *)(v72 + 3);
          }
          if ( *(_WORD *)v72 )
            v72 = *(_DWORD *)(v38 + 2882) + 7 * *(_WORD *)v72;
          else
            v72 = 0;
        }
        v39 = *(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j;
        if ( !((*(_WORD *)(v39 + 4) >> 1) & 1) )
        {
          v45[v43] = (*(_BYTE *)(v39 + 2) >> 2) & 0x3F;
          v42[v43++] = *(_BYTE *)(v39 + 3);
        }
        if ( *(_WORD *)(v39 + 10) )
          v72 = *(_DWORD *)(v38 + 2882) + 7 * *(_WORD *)(v39 + 10);
        else
          v72 = 0;
        while ( v43 < 5 && v72 )
        {
          if ( *(_BYTE *)(v72 + 3) != 255 && !((*(_BYTE *)(v72 + 4) >> 1) & 1) )
          {
            v45[v43] = (*(_BYTE *)(v72 + 2) >> 1) & 0x7F;
            v42[v43++] = *(_BYTE *)(v72 + 3);
          }
          if ( *(_WORD *)v72 )
            v72 = *(_DWORD *)(v38 + 2882) + 7 * *(_WORD *)v72;
          else
            v72 = 0;
        }
        for ( n = 0; v44 > n; ++n )
        {
          for ( ii = 0; v43 > ii; ++ii )
          {
            if ( v45[ii] == v40[n] || v40[n] >= 35 && v40[n] <= 38 && v45[ii] >= 35 && v45[ii] <= 38 )
              *(_BYTE *)(v68 + 8) |= 8u;
          }
        }
      }
      if ( mapHeight - 1 > i
        && (*(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 9) == 163
         || *(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 9) == 176
         || *(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 9) == 177) )
        *(_BYTE *)(v68 + 8) |= 8u;
      if ( *(_BYTE *)(v68 + 3) != 255
        && !(*(_BYTE *)(v68 + 9) & 0x80)
        && !(*(_BYTE *)(v68 + 8) & 0x80)
        && (mapHeight - 1 == i
         || *(_BYTE *)(*(_DWORD *)(v38 + 2878) + 12 * (i + 1) * *(_DWORD *)(v38 + 2886) + 12 * j + 8) & 4) )
        *(_BYTE *)(v68 + 8) |= 8u;
    }
  }
  return result;
}
