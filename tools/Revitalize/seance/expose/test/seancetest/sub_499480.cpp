void __thiscall sub_499480(void *this)
{
  void *thisa; // [sp+10h] [bp-A4h]@1
  int v2; // [sp+14h] [bp-A0h]@155
  int v3; // [sp+18h] [bp-9Ch]@137
  int v4; // [sp+1Ch] [bp-98h]@119
  int a11; // [sp+20h] [bp-94h]@116
  int v6; // [sp+24h] [bp-90h]@32
  char v7; // [sp+28h] [bp-8Ch]@157
  char v8; // [sp+29h] [bp-8Bh]@157
  char v9; // [sp+2Ah] [bp-8Ah]@157
  char v10; // [sp+2Ch] [bp-88h]@115
  char v11; // [sp+2Dh] [bp-87h]@115
  char v12; // [sp+2Eh] [bp-86h]@115
  char v13; // [sp+30h] [bp-84h]@115
  char v14; // [sp+31h] [bp-83h]@115
  char v15; // [sp+32h] [bp-82h]@115
  int mirror; // [sp+34h] [bp-80h]@11
  int v17; // [sp+38h] [bp-7Ch]@110
  int v18; // [sp+3Ch] [bp-78h]@5
  int y; // [sp+40h] [bp-74h]@11
  int v20; // [sp+44h] [bp-70h]@11
  int v21; // [sp+48h] [bp-6Ch]@157
  int v22; // [sp+4Ch] [bp-68h]@11
  int spriteIdx; // [sp+50h] [bp-64h]@1
  int row; // [sp+58h] [bp-5Ch]@1
  int col; // [sp+5Ch] [bp-58h]@3
  bool v26; // [sp+60h] [bp-54h]@125
  int v27; // [sp+64h] [bp-50h]@41
  unsigned int v28; // [sp+6Ch] [bp-48h]@90
  unsigned int v29; // [sp+70h] [bp-44h]@90
  char v30[11]; // [sp+74h] [bp-40h]@1
  char v31; // [sp+7Fh] [bp-35h]@1
  char v32; // [sp+81h] [bp-33h]@1
  char v33; // [sp+82h] [bp-32h]@1

  thisa = this;
  spriteIdx = 0;
  sub_4D6A50(HeroWindowManager::instance->screenBuffer, 16, 16, 0x1C0u, 448, 36);
  memset(v30, 1, 0x40u);
  v31 = 0;
  v32 = 0;
  v33 = 0;
  for ( row = dword_52FF60; dword_52FF60 + dword_52FF68 > row; ++row )
  {
    for ( col = dword_52FF5C; dword_52FF68 + dword_52FF5C > col; ++col )
    {
      v18 = usedToCheckForBoatByCastle((AdvManager *)thisa, col, row);
      if ( (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
        || dword_52FF44
        || dword_52FF3C == 51
        && ((*(_BYTE *)(v18 + 9) & 0x7F) == 35
         || *(_BYTE *)(v18 + 9) == 170
         && *(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)]._4[12] == 163) )
      {
        mirror = 0;
        v20 = dword_52FF4C + dword_51923C * (col - dword_52FF5C);
        y = dword_52FF50 + dword_51923C * (row - dword_52FF60);
        v22 = byte_4F0150[*(_WORD *)v18] & 0x7F;
        switch ( v22 )
        {
          case 0:
          case 9:
          case 18:
          case 19:
          case 20:
          case 21:
            spriteIdx = 0;
            break;
          case 1:
          case 12:
          case 15:
          case 16:
            spriteIdx = 1;
            break;
          case 2:
          case 10:
          case 11:
            spriteIdx = 2;
            break;
          case 3:
          case 13:
          case 14:
          case 17:
            spriteIdx = 3;
            break;
          case 4:
            spriteIdx = 4;
            break;
          case 5:
            spriteIdx = 5;
            break;
          case 6:
            spriteIdx = 6;
            break;
          case 7:
            spriteIdx = 7;
            break;
          case 8:
            spriteIdx = 8;
            break;
          default:
            break;
        }
        if ( *(_BYTE *)(v18 + 8) & 2 )
          mirror = 1;
        if ( *(_BYTE *)(v18 + 8) & 1 )
          spriteIdx += 9;
        if ( spriteIdx )
          spriteIdx += 3;
        else
          spriteIdx = ((_BYTE)col + 2 * (_BYTE)row) & 3;
        spriteIdx += 21 * (unsigned __int8)tileToTerrainType[*(_WORD *)v18];
        if ( (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C) || dword_52FF44 )
        {
          if ( mirror == 1 )
            v6 = dword_51923C - 1;
          else
            v6 = 0;
          Icon::drawToScreen(dword_52FF48, v6 + v20, y, spriteIdx, mirror);
        }
        if ( *(_WORD *)(v18 + 4) & 1 && *(_BYTE *)(v18 + 3) != 255 && v30[(*(_BYTE *)(v18 + 2) >> 2) & 0x3F] )
          sub_4D7880(
            *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v18 + 2) >> 2) & 0x3F) + 206),
            (int)HeroWindowManager::instance->screenBuffer,
            v20,
            y,
            *(_BYTE *)(v18 + 3),
            0,
            0,
            0,
            0x280u,
            480,
            dword_51923C);
        if ( *(_WORD *)(v18 + 10)
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4)
                      - *(_WORD *)(v18 + 10)
                      + 8 * *(_WORD *)(v18 + 10)
                      + 3) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)(v18 + 10) + 8 * *(_WORD *)(v18 + 10);
        else
          v27 = 0;
        while ( v27 )
        {
          if ( *(_BYTE *)(v27 + 4) & 1 && *(_BYTE *)(v27 + 3) != 255 && v30[(*(_BYTE *)(v27 + 2) >> 1) & 0x7F] )
            sub_4D7880(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 2) >> 1) & 0x7F) + 206),
              (int)HeroWindowManager::instance->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 3),
              0,
              0,
              0,
              0x280u,
              480,
              dword_51923C);
          if ( *(_WORD *)v27
            && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27 + 3) != 255 )
            v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27;
          else
            v27 = 0;
        }
        if ( !(*(_WORD *)(v18 + 4) & 1) && *(_BYTE *)(v18 + 3) != 255 && v30[(*(_BYTE *)(v18 + 2) >> 2) & 0x3F] )
          sub_4D7880(
            *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v18 + 2) >> 2) & 0x3F) + 206),
            (int)HeroWindowManager::instance->screenBuffer,
            v20,
            y,
            *(_BYTE *)(v18 + 3),
            0,
            0,
            0,
            0x280u,
            480,
            dword_51923C);
        if ( *(_WORD *)(v18 + 10)
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4)
                      - *(_WORD *)(v18 + 10)
                      + 8 * *(_WORD *)(v18 + 10)
                      + 3) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)(v18 + 10) + 8 * *(_WORD *)(v18 + 10);
        else
          v27 = 0;
        while ( v27 )
        {
          if ( !(*(_BYTE *)(v27 + 4) & 1) && *(_BYTE *)(v27 + 3) != 255 && v30[(*(_BYTE *)(v27 + 2) >> 1) & 0x7F] )
            sub_4D7880(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 2) >> 1) & 0x7F) + 206),
              (int)HeroWindowManager::instance->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 3),
              0,
              0,
              0,
              0x280u,
              480,
              dword_51923C);
          if ( *(_WORD *)v27
            && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27 + 3) != 255 )
            v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27;
          else
            v27 = 0;
        }
        if ( *(_BYTE *)(v18 + 7) != 255 && v30[(*(_BYTE *)(v18 + 6) >> 2) & 0x3F] )
          sub_4D7880(
            *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v18 + 6) >> 2) & 0x3F) + 206),
            (int)HeroWindowManager::instance->screenBuffer,
            v20,
            y,
            *(_BYTE *)(v18 + 7),
            0,
            0,
            0,
            0x280u,
            480,
            dword_51923C);
        if ( *(_WORD *)(v18 + 10)
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4)
                      - *(_WORD *)(v18 + 10)
                      + 8 * *(_WORD *)(v18 + 10)
                      + 6) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)(v18 + 10) + 8 * *(_WORD *)(v18 + 10);
        else
          v27 = 0;
        while ( v27 )
        {
          if ( v30[(*(_BYTE *)(v27 + 5) >> 2) & 0x3F] )
            sub_4D7880(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 5) >> 2) & 0x3F) + 206),
              (int)HeroWindowManager::instance->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 6),
              0,
              0,
              0,
              0x280u,
              480,
              dword_51923C);
          if ( *(_WORD *)v27
            && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27 + 6) != 255 )
            v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27;
          else
            v27 = 0;
        }
      }
    }
  }
  for ( row = 16; row < 464; ++row )
  {
    v28 = (unsigned int)&HeroWindowManager::instance->screenBuffer->contents[640 * row + 16];
    v29 = v28 + 448;
    while ( v28 < v29 )
    {
      *(_BYTE *)v28 = byte_4F1890[*(_BYTE *)v28];
      ++v28;
    }
  }
  for ( row = dword_52FF60; dword_52FF60 + dword_52FF68 > row; ++row )
  {
    for ( col = dword_52FF5C; dword_52FF68 + dword_52FF5C > col; ++col )
    {
      v18 = usedToCheckForBoatByCastle((AdvManager *)thisa, col, row);
      v20 = dword_52FF4C + (dword_51923C >> 1) + dword_51923C * (col - dword_52FF5C);
      y = dword_52FF50 + (dword_51923C >> 1) + dword_51923C * (row - dword_52FF60);
      if ( *(_BYTE *)(v18 + 9) == 169
        && (dword_52FF40 || (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
                         || dword_52FF3C == 50) )
        rasterize(
          dword_52FF58,
          HeroWindowManager::instance->screenBuffer,
          v20 - byte_51921C[12 * dword_519240],
          y - byte_51921D[12 * dword_519240],
          14,
          1,
          16,
          16,
          0x1C0u,
          448,
          (unsigned int)(dword_52FF3C - 50) < 1 ? 0xD6 : 0);
      if ( (*(_BYTE *)(v18 + 9) == 163
         || *(_BYTE *)(v18 + 9) == 170
         && *(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)]._4[12] == 163)
        && (dword_52FF40 || (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
                         || dword_52FF3C == 51) )
      {
        if ( *(_BYTE *)(v18 + 9) == 163 )
          v17 = gameObject->_7[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)];
        else
          v17 = gameObject->_7[*(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)]._4[14]];
        if ( v17 >= 0 )
          v17 = gameObject->players[v17].color;
        else
          v17 = 6;
        v13 = -2;
        v14 = -3;
        v15 = -6;
        v10 = 5;
        v11 = 7;
        v12 = 10;
        if ( dword_52FF3C == 51 )
          a11 = v17 + 215;
        else
          a11 = 0;
        rasterizeMirrored(
          dword_52FF54,
          HeroWindowManager::instance->screenBuffer,
          v20 + *(&v13 + dword_519240) - byte_519220[12 * dword_519240],
          y - byte_519221[12 * dword_519240],
          v17,
          1,
          16,
          16,
          448,
          448,
          a11);
        if ( dword_52FF3C == 51 )
          v4 = v17 + 215;
        else
          v4 = 0;
        rasterize(
          dword_52FF54,
          HeroWindowManager::instance->screenBuffer,
          v20 + *(&v10 + dword_519240) - byte_519220[12 * dword_519240],
          y - byte_519221[12 * dword_519240],
          v17,
          1,
          16,
          16,
          0x1C0u,
          448,
          v4);
      }
      v26 = curPlayer->_1[0] != -1
         && gameObject->heroes[curPlayer->_1[0]].x == col
         && gameObject->heroes[curPlayer->_1[0]].y == row;
      if ( *(_BYTE *)(v18 + 9) == 170 || v26 )
      {
        if ( dword_52FF40
          || (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
          || dword_52FF3C == 52 )
        {
          v17 = v26 ? gameObject->relatedToHeroForHireStatus[curPlayer->_1[0]] : gameObject->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5)];
          if ( v17 >= 0 )
          {
            spriteIdx = gameObject->players[v17].color;
            if ( dword_52FF3C == 52 )
              v3 = spriteIdx + 215;
            else
              v3 = 0;
            rasterize(
              dword_52FF58,
              HeroWindowManager::instance->screenBuffer,
              v20 - byte_519218[12 * dword_519240],
              y - byte_519219[12 * dword_519240],
              spriteIdx + 7,
              1,
              16,
              16,
              0x1C0u,
              448,
              v3);
          }
        }
      }
      if ( *(_BYTE *)(v18 + 9) == 155
        && (dword_52FF40 || (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
                         || dword_52FF3C == 49) )
      {
        spriteIdx = (signed int)*(_BYTE *)(v18 + 3) >> 1;
        rasterize(
          dword_52FF58,
          HeroWindowManager::instance->screenBuffer,
          v20 - byte_51921A[12 * dword_519240],
          y - byte_51921B[12 * dword_519240],
          13,
          1,
          16,
          16,
          0x1C0u,
          448,
          (unsigned int)(dword_52FF3C - 49) < 1 ? 0xDD : 0);
        rasterize(
          dword_52FF38,
          HeroWindowManager::instance->screenBuffer,
          v20 - byte_519222[12 * dword_519240],
          y - byte_519223[12 * dword_519240],
          spriteIdx,
          1,
          16,
          16,
          0x1C0u,
          448,
          0);
      }
      if ( (*(_BYTE *)(v18 + 9) == 151 || *(_BYTE *)(v18 + 9) == 157 || *(_BYTE *)(v18 + 9) == 129)
        && (dword_52FF40 || (unsigned __int8)(*(&tileExplored[col] + row * mapWidth) & byte_532C5C)
                         || dword_52FF3C == 48) )
      {
        v17 = gameObject->_8[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5) + 1008];
        if ( v17 < 0 )
          spriteIdx = 6;
        else
          spriteIdx = gameObject->players[v17].color;
        if ( dword_52FF3C == 48 )
          v2 = spriteIdx + 215;
        else
          v2 = 0;
        rasterize(
          dword_52FF58,
          HeroWindowManager::instance->screenBuffer,
          v20 - byte_51921E[12 * dword_519240],
          y - byte_51921F[12 * dword_519240],
          spriteIdx,
          1,
          16,
          16,
          0x1C0u,
          448,
          v2);
        v7 = 0;
        v8 = 0;
        v9 = 2;
        v21 = gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5) + 2];
        rasterize(
          dword_52FF38,
          HeroWindowManager::instance->screenBuffer,
          v20 - byte_519222[12 * dword_519240],
          y + *(&v7 + dword_519240) - byte_519223[12 * dword_519240],
          v21,
          1,
          16,
          16,
          0x1C0u,
          448,
          0);
      }
    }
  }
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 16, 16, 0x1C0u, 448);
}
