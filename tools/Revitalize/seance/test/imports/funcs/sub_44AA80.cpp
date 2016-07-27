{
  int v3; // [sp+4Ch] [bp-74h]@1
  signed int v4; // [sp+50h] [bp-70h]@84
  signed int v5; // [sp+54h] [bp-6Ch]@76
  signed int v6; // [sp+58h] [bp-68h]@66
  signed int v7; // [sp+5Ch] [bp-64h]@46
  int v8; // [sp+60h] [bp-60h]@50
  int v9; // [sp+64h] [bp-5Ch]@44
  int v10; // [sp+64h] [bp-5Ch]@65
  int v11; // [sp+64h] [bp-5Ch]@75
  int v12; // [sp+64h] [bp-5Ch]@83
  int v13; // [sp+68h] [bp-58h]@39
  int v14; // [sp+6Ch] [bp-54h]@13
  float v15; // [sp+74h] [bp-4Ch]@111
  int v16; // [sp+78h] [bp-48h]@65
  signed int v17; // [sp+7Ch] [bp-44h]@109
  int i; // [sp+80h] [bp-40h]@20
  signed int v19; // [sp+88h] [bp-38h]@2
  int v20; // [sp+8Ch] [bp-34h]@2
  int v21; // [sp+90h] [bp-30h]@65
  int a4; // [sp+94h] [bp-2Ch]@109
  int j; // [sp+9Ch] [bp-24h]@33
  signed int v24; // [sp+A0h] [bp-20h]@2
  int v25; // [sp+A4h] [bp-1Ch]@2
  int v26; // [sp+ACh] [bp-14h]@22
  char v27; // [sp+B0h] [bp-10h]@1
  int v28; // [sp+B4h] [bp-Ch]@12
  int v29; // [sp+B8h] [bp-8h]@12
  unsigned __int8 *v30; // [sp+BCh] [bp-4h]@13

  v3 = this;
  v27 = 36;
  if ( a3 )
  {
    v24 = *(_DWORD *)(this + 470) - 2;
    v19 = *(_DWORD *)(this + 474) - 2;
    v25 = *(_DWORD *)(this + 470) + 16;
    v20 = *(_DWORD *)(this + 474) + 16;
    if ( v24 < 0 )
      v24 = 0;
    if ( v19 < 0 )
      v19 = 0;
    if ( mapWidth - 1 < v25 )
      v25 = mapWidth - 1;
    if ( mapHeight - 1 < v20 )
      v20 = mapHeight - 1;
  }
  else
  {
    v24 = 0;
    v19 = 0;
    v25 = mapWidth - 1;
    v20 = mapHeight - 1;
  }
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    advManager->field_37A = 0;
    v29 = 0;
    v28 = 0;
    switch ( mapHeight )
    {
      case 36:
        v30 = &HeroWindowManager::instance->screenBuffer->contents[128 * (20 * v19 + 80) + 480];
        v14 = 4 * v24;
        break;
      case 72:
        v30 = &HeroWindowManager::instance->screenBuffer->contents[128 * (10 * v19 + 80) + 480];
        v14 = 2 * v24;
        break;
      case 108:
        v30 = &HeroWindowManager::instance->screenBuffer->contents[128 * (5 * ((v19 + 2) / 3 + v19) + 80) + 480];
        v14 = (v24 + 2) / 3 + v24;
        v28 = v24 % 3;
        v29 = v19 % 3;
        break;
      default:
        v30 = &HeroWindowManager::instance->screenBuffer->contents[128 * (5 * v19 + 80) + 480];
        v14 = v24;
        break;
    }
    for ( i = v19; v20 >= i; ++i )
    {
      v26 = (int)&v30[v14];
      switch ( mapHeight )
      {
        case 36:
          v30 += 2560;
          break;
        case 72:
          v30 += 1280;
          break;
        case 108:
          ++v29;
          if ( v29 > 2 )
            v29 = 0;
          if ( v29 )
            v30 += 640;
          else
            v30 += 1280;
          break;
        case 144:
          v30 += 640;
          break;
        default:
          break;
      }
      for ( j = v24; j <= v25; ++j )
      {
        if ( !dword_4F7470 && (unsigned __int8)(*(&tileExplored[j] + mapWidth * i) & byte_532C5C) )
        {
          v13 = **(_DWORD **)(v3 + 174) + 12 * i * *(_DWORD *)(*(_DWORD *)(v3 + 174) + 8) + 12 * j;
          if ( *(_BYTE *)(v13 + 8) & 0x40 && *(_DWORD *)(v3 + 470) + 7 == j && *(_DWORD *)(v3 + 474) + 7 == i )
          {
            v27 = byte_4F0A48[gameObject->players[curPlayerIdx].color];
          }
          else
          {
            if ( (*(_BYTE *)(v13 + 9) & 0x7F) == 42 )
            {
              v9 = gameObject->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)];
              if ( curPlayerIdx == v9 )
              {
                if ( v9 < 0 )
                  v7 = 6;
                else
                  v7 = gameObject->players[v9].color;
                v27 = byte_4F0A48[v7];
              }
            }
            else
            {
              v8 = -1;
              if ( *(_BYTE *)(v13 + 3) == 255 )
              {
                if ( *(_BYTE *)(v13 + 7) != 255 )
                  v8 = (*(_BYTE *)(v13 + 6) >> 2) & 0x3F;
              }
              else
              {
                v8 = (*(_BYTE *)(v13 + 2) >> 2) & 0x3F;
              }
              if ( *(_BYTE *)(v13 + 9) == 35
                || v8 == 14
                && j > 0
                && mapWidth - 1 > j
                && *(_BYTE *)(**(_DWORD **)(v3 + 174)
                            + 12 * i * *(_DWORD *)(*(_DWORD *)(v3 + 174) + 8)
                            + 4 * (3 * j - 3)
                            + 9) == 163
                || *(_BYTE *)(**(_DWORD **)(v3 + 174)
                            + 12 * i * *(_DWORD *)(*(_DWORD *)(v3 + 174) + 8)
                            + 4 * (3 * j + 3)
                            + 9) == 163 )
                v8 = 35;
              if ( v8 != 62 || *(_BYTE *)(v13 + 9) != 103 )
              {
                switch ( v8 )
                {
                  case 35:
                  case 36:
                    v10 = gameObject->_7[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)];
                    v21 = gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)].field_4;
                    v16 = gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)].field_5;
                    if ( v10 < 0 )
                      v6 = 6;
                    else
                      v6 = gameObject->players[v10].color;
                    v27 = byte_4F0A48[v6];
                    if ( v16 - 2 > i || i > v16 || v21 - 2 > j || v21 + 2 < j )
                      goto LABEL_88;
                    break;
                  case 22:
                  case 23:
                  case 24:
                  case 25:
                  case 26:
                  case 27:
                  case 31:
                  case 32:
                  case 33:
                  case 34:
                  case 42:
                  case 43:
                  case 44:
                  case 49:
                    switch ( *(_BYTE *)(v13 + 9) )
                    {
                      case 1:
                      case 0x17:
                      case 0x1D:
                      case 0x81:
                      case 0x97:
                      case 0x9D:
                        v11 = gameObject->_8[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5) + 1008];
                        if ( v11 < 0 )
                          v5 = 6;
                        else
                          v5 = gameObject->players[v11].color;
                        v27 = byte_4F0A48[v5];
                        break;
                      default:
                        v27 = byte_4F0A28[(unsigned __int8)tileToTerrainType[*(_WORD *)v13]] + 3;
                        break;
                    }
                    break;
                  default:
LABEL_88:
                    switch ( *(_BYTE *)(v13 + 9) )
                    {
                      case 1:
                      case 0x17:
                      case 0x1D:
                      case 0x81:
                      case 0x97:
                      case 0x9D:
                        v12 = gameObject->_8[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5) + 1008];
                        if ( v12 < 0 )
                          v4 = 6;
                        else
                          v4 = gameObject->players[v12].color;
                        v27 = byte_4F0A48[v4];
                        break;
                      default:
                        v27 = byte_4F0A28[(unsigned __int8)tileToTerrainType[*(_WORD *)v13]];
                        break;
                    }
                    break;
                }
              }
              else
              {
                v27 = byte_4F0A28[(unsigned __int8)tileToTerrainType[*(_WORD *)v13]] + 3;
              }
            }
          }
        }
        else
        {
          v27 = 36;
        }
        switch ( mapHeight )
        {
          case 36:
            memset((void *)v26, (unsigned __int8)v27, 4u);
            memset((void *)(v26 + 640), (unsigned __int8)v27, 4u);
            memset((void *)(v26 + 1280), (unsigned __int8)v27, 4u);
            memset((void *)(v26 + 1920), (unsigned __int8)v27, 4u);
            v26 += 4;
            break;
          case 72:
            memset((void *)v26, (unsigned __int8)v27, 2u);
            memset((void *)(v26 + 640), (unsigned __int8)v27, 2u);
            v26 += 2;
            break;
          case 108:
            if ( v28 )
            {
              if ( v29 )
              {
                *(_BYTE *)v26++ = v27;
              }
              else
              {
                *(_BYTE *)v26 = v27;
                *(_BYTE *)(v26++ + 640) = v27;
              }
            }
            else
            {
              if ( v29 )
              {
                *(_BYTE *)v26 = v27;
                *(_BYTE *)(v26 + 1) = v27;
                v26 += 2;
              }
              else
              {
                *(_BYTE *)v26 = v27;
                *(_BYTE *)(v26 + 1) = v27;
                *(_BYTE *)(v26 + 640) = v27;
                *(_BYTE *)(v26 + 641) = v27;
                v26 += 2;
              }
            }
            ++v28;
            if ( v28 > 2 )
              v28 = 0;
            break;
          case 144:
            *(_BYTE *)v26++ = v27;
            break;
          default:
            continue;
        }
      }
    }
    a4 = -1;
    v17 = 0;
    if ( dword_519244 )
    {
      switch ( mapHeight )
      {
        case 36:
          v15 = 4.0;
          v17 = 1;
          break;
        case 72:
          v15 = 2.0;
          if ( dword_51923C > 6 )
            a4 = 6;
          else
            v17 = 1;
          break;
        case 108:
          v15 = 1.33;
          if ( dword_51923C > 4 )
          {
            if ( dword_51923C == 6 )
              a4 = 9;
            else
              a4 = 8;
          }
          else
          {
            v17 = 1;
          }
          break;
        default:
          v15 = 1.0;
          if ( dword_51923C == 4 )
          {
            a4 = 7;
          }
          else
          {
            if ( dword_51923C == 6 )
              a4 = 6;
            else
              a4 = 4;
          }
          break;
      }
    }
    else
    {
      switch ( mapHeight )
      {
        case 36:
          a4 = 5;
          v15 = 4.0;
          break;
        case 72:
          a4 = 3;
          v15 = 2.0;
          break;
        case 108:
          a4 = 2;
          v15 = 1.33;
          break;
        default:
          a4 = 1;
          v15 = 1.0;
          break;
      }
    }
    if ( !v17 )
    {
      if ( dword_519244 )
        sub_4CF530(
          *(Icon **)(v3 + 462),
          (signed __int64)((double)dword_52FF5C * v15 + 480.0),
          (signed __int64)((double)dword_52FF60 * v15 + 16.0),
          a4,
          -75,
          0,
          480,
          16,
          0x90u,
          144);
      else
        sub_4CF530(
          *(Icon **)(v3 + 462),
          (signed __int64)((double)*(signed int *)(v3 + 470) * v15 + 480.0),
          (signed __int64)((double)*(signed int *)(v3 + 474) * v15 + 16.0),
          a4,
          -75,
          0,
          480,
          16,
          0x90u,
          144);
    }
    if ( a2 )
    {
      if ( a3 )
        HeroWindowManager::redrawRectangle(
          HeroWindowManager::instance,
          (signed __int64)((double)v24 * v15 + 480.0),
          (signed __int64)((double)v19 * v15 + 16.0),
          (signed __int64)((double)(v25 - v24 + 1) * v15),
          (signed __int64)((double)(v20 - v19 + 1) * v15));
      else
        HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 480, 16, 0x90u, 144);
    }
  }
}
