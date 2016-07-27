{
  int result; // eax@5
  char v2; // ST70_1@40
  char v3; // ST70_1@41
  char v4; // ST70_1@42
  char v5; // ST70_1@43
  int thisa; // [sp+18h] [bp-34h]@1
  int v7; // [sp+2Ch] [bp-20h]@32
  int v8; // [sp+30h] [bp-1Ch]@9
  int v9; // [sp+34h] [bp-18h]@13
  int a5; // [sp+38h] [bp-14h]@4
  signed int i; // [sp+3Ch] [bp-10h]@1
  int a4; // [sp+40h] [bp-Ch]@6
  int v13; // [sp+48h] [bp-4h]@13

  thisa = (int)this;
  word_522FB4 = -1;
  word_522FB8 = -1;
  word_522F90 = 0;
  for ( i = 0; i < 7; ++i )
    word_522FA0[i] = 0;
  for ( a5 = 0; ; ++a5 )
  {
    result = mapHeight;
    if ( a5 >= mapHeight )
      break;
    for ( a4 = 0; a4 < mapWidth; ++a4 )
    {
      v8 = *(_DWORD *)(thisa + 2878) + 12 * a5 * *(_DWORD *)(thisa + 2886) + 12 * a4;
      switch ( *(_BYTE *)(v8 + 9) )
      {
        case 0xAC:
          word_522FB4 = a4;
          word_522FB8 = a5;
          word_522F90 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5);
          *(_BYTE *)(v8 + 9) = 0;
          *(_BYTE *)(v8 + 2) &= 3u;
          *(_BYTE *)(v8 + 3) = -1;
          continue;
        case 0xB0:
          sub_427520((void *)thisa, a4, a5, 0);
          continue;
        case 0xB1:
          sub_427520((void *)thisa, a4, a5, 1);
          continue;
        case 0xAF:
          v13 = 80;
          v9 = 2000;
          goto LABEL_18;
        case 0xB3:
          v13 = 0;
          v9 = 400;
          goto LABEL_18;
        case 0xB4:
          v13 = 400;
          v9 = 1000;
          goto LABEL_18;
        case 0xB5:
          v13 = 1000;
          v9 = 2500;
          goto LABEL_18;
        case 0xB6:
          v13 = 2500;
          v9 = 100000;
LABEL_18:
          if ( ((*(_BYTE *)(v8 + 2) >> 2) & 0x3F) == 12
            && (signed int)*(_BYTE *)(v8 + 3) >= 67
            && (signed int)*(_BYTE *)(v8 + 3) <= 70 )
          {
            switch ( *(_BYTE *)(v8 + 3) )
            {
              case 0x43:
                v13 = 0;
                v9 = 400;
                break;
              case 0x44:
                v13 = 400;
                v9 = 1000;
                break;
              case 0x45:
                v13 = 1000;
                v9 = 2500;
                break;
              case 0x46:
                v13 = 2500;
                v9 = 100000;
                break;
              default:
                break;
            }
          }
          *(_BYTE *)(v8 + 9) = -104;
          for ( *(_BYTE *)(v8 + 3) = unseededNextRand(0, 65);
                creature_table[*(_BYTE *)(v8 + 3)].fight_value <= v13
             || creature_table[*(_BYTE *)(v8 + 3)].fight_value >= v9;
                *(_BYTE *)(v8 + 3) = unseededNextRand(0, 65) )
            ;
          break;
        case 0xAE:
          *(_BYTE *)(v8 + 9) = -101;
          v7 = unseededNextRand(0, 6);
          sub_4270A0((GameInfo *)thisa, a4 - 1, a5, a4 - 1, a5, 46, 16, 16, 46, 2 * v7, -1, -1);
          sub_4270A0((GameInfo *)thisa, a4, a5, a4, a5, 46, 17, 17, 46, 2 * v7 + 1, -1, -1);
          if ( v7 && v7 != 2 )
          {
            if ( v7 == 6 )
              *(_WORD *)(v8 + 4) = *(_WORD *)(v8 + 4) & 7 | 8 * unseededNextRand(5, 10);
            else
              *(_WORD *)(v8 + 4) = *(_WORD *)(v8 + 4) & 7 | 8 * unseededNextRand(3, 7);
          }
          else
          {
            *(_WORD *)(v8 + 4) = *(_WORD *)(v8 + 4) & 7 | 8 * unseededNextRand(8, 16);
          }
          break;
        case 0xAD:
          v2 = GameInfo::randomArtifact((GameInfo *)thisa, 14, 0);
          *(_BYTE *)(v8 + 9) = -87;
          sub_4270A0((GameInfo *)thisa, a4 - 1, a5, a4 - 1, a5, 11, 162, 162, 11, 2 * v2, -1, -1);
          sub_4270A0((GameInfo *)thisa, a4, a5, a4, a5, 11, 163, 163, 11, 2 * v2 + 1, -1, -1);
          break;
        case 0xF4:
          v3 = GameInfo::randomArtifact((GameInfo *)thisa, 8, 0);
          *(_BYTE *)(v8 + 9) = -87;
          sub_4270A0((GameInfo *)thisa, a4 - 1, a5, a4 - 1, a5, 11, 166, 166, 11, 2 * v3, -1, -1);
          sub_4270A0((GameInfo *)thisa, a4, a5, a4, a5, 11, 167, 167, 11, 2 * v3 + 1, -1, -1);
          break;
        case 0xF5:
          v4 = GameInfo::randomArtifact((GameInfo *)thisa, 4, 0);
          *(_BYTE *)(v8 + 9) = -87;
          sub_4270A0((GameInfo *)thisa, a4 - 1, a5, a4 - 1, a5, 11, 168, 168, 11, 2 * v4, -1, -1);
          sub_4270A0((GameInfo *)thisa, a4, a5, a4, a5, 11, 169, 169, 11, 2 * v4 + 1, -1, -1);
          break;
        case 0xF6:
          v5 = GameInfo::randomArtifact((GameInfo *)thisa, 2, 0);
          *(_BYTE *)(v8 + 9) = -87;
          sub_4270A0((GameInfo *)thisa, a4 - 1, a5, a4 - 1, a5, 11, 170, 170, 11, 2 * v5, -1, -1);
          sub_4270A0((GameInfo *)thisa, a4, a5, a4, a5, 11, 171, 171, 11, 2 * v5 + 1, -1, -1);
          break;
        case 0xB2:
          sub_4276F0(thisa, a4, a5);
          break;
        default:
          continue;
      }
    }
  }
  return result;
}
