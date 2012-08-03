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
  mapCell *v18; // [sp+3Ch] [bp-78h]@5
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
  FillBitmapArea(gpWindowManager->screenBuffer, 16, 16, 0x1C0u, 448, 36);
  memset(v30, 1u, 0x40u);
  v31 = 0;
  v32 = 0;
  v33 = 0;
  for ( row = iVWMapOriginY; iVWMapOriginY + iVWViewableCells > row; ++row )
  {
    for ( col = iVWMapOriginX; iVWViewableCells + iVWMapOriginX > col; ++col )
    {
      v18 = advManager::GetCell((advManager *)thisa, col, row);
      if ( (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
        || iVWDrawAllTerrains
        || iVWWhatToDraw == 51
        && ((v18->objType & 0x7F) == 35
         || v18->objType == 170
         && gpGame->heroes[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5)].occupiedObjType == 163) )
      {
        mirror = 0;
        v20 = iVWXPixelOffset + giViewWorldScale * (col - iVWMapOriginX);
        y = iVWYPixelOffset + giViewWorldScale * (row - iVWMapOriginY);
        v22 = giGroundShape[v18->tileType] & 0x7F;
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
        if ( v18->field_8 & 2 )
          mirror = 1;
        if ( v18->field_8 & 1 )
          spriteIdx += 9;
        if ( spriteIdx )
          spriteIdx += 3;
        else
          spriteIdx = ((_BYTE)col + 2 * (_BYTE)row) & 3;
        spriteIdx += 21 * (unsigned __int8)giGroundToTerrain[v18->tileType];
        if ( (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit) || iVWDrawAllTerrains )
        {
          if ( mirror == 1 )
            v6 = giViewWorldScale - 1;
          else
            v6 = 0;
          icon::DrawToBuffer(pVWGround, v6 + v20, y, spriteIdx, mirror);
        }
        if ( v18->flags & 1 && HIBYTE(v18->field_2) != 255 && v30[(LOBYTE(v18->field_2) >> 2) & 0x3F] )
          IconToBitmapScale(
            *(_DWORD *)((char *)thisa + 4 * ((LOBYTE(v18->field_2) >> 2) & 0x3F) + 206),
            (int)gpWindowManager->screenBuffer,
            v20,
            y,
            HIBYTE(v18->field_2),
            0,
            0,
            0,
            0x280u,
            480,
            giViewWorldScale);
        if ( v18->field_A
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A + 3) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A;
        else
          v27 = 0;
        while ( v27 )
        {
          if ( *(_BYTE *)(v27 + 4) & 1 && *(_BYTE *)(v27 + 3) != 255 && v30[(*(_BYTE *)(v27 + 2) >> 1) & 0x7F] )
            IconToBitmapScale(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 2) >> 1) & 0x7F) + 206),
              (int)gpWindowManager->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 3),
              0,
              0,
              0,
              0x280u,
              480,
              giViewWorldScale);
          if ( *(_WORD *)v27
            && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27 + 3) != 255 )
            v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27;
          else
            v27 = 0;
        }
        if ( !(v18->flags & 1) && HIBYTE(v18->field_2) != 255 && v30[(LOBYTE(v18->field_2) >> 2) & 0x3F] )
          IconToBitmapScale(
            *(_DWORD *)((char *)thisa + 4 * ((LOBYTE(v18->field_2) >> 2) & 0x3F) + 206),
            (int)gpWindowManager->screenBuffer,
            v20,
            y,
            HIBYTE(v18->field_2),
            0,
            0,
            0,
            0x280u,
            480,
            giViewWorldScale);
        if ( v18->field_A
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A + 3) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A;
        else
          v27 = 0;
        while ( v27 )
        {
          if ( !(*(_BYTE *)(v27 + 4) & 1) && *(_BYTE *)(v27 + 3) != 255 && v30[(*(_BYTE *)(v27 + 2) >> 1) & 0x7F] )
            IconToBitmapScale(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 2) >> 1) & 0x7F) + 206),
              (int)gpWindowManager->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 3),
              0,
              0,
              0,
              0x280u,
              480,
              giViewWorldScale);
          if ( *(_WORD *)v27
            && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27 + 3) != 255 )
            v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - *(_WORD *)v27 + 8 * *(_WORD *)v27;
          else
            v27 = 0;
        }
        if ( v18->field_7 != 255 && v30[((unsigned __int8)v18->field_6 >> 2) & 0x3F] )
          IconToBitmapScale(
            *(_DWORD *)((char *)thisa + 4 * (((unsigned __int8)v18->field_6 >> 2) & 0x3F) + 206),
            (int)gpWindowManager->screenBuffer,
            v20,
            y,
            v18->field_7,
            0,
            0,
            0,
            0x280u,
            480,
            giViewWorldScale);
        if ( v18->field_A
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A + 6) != 255 )
          v27 = *(_DWORD *)(*(_DWORD *)((char *)thisa + 174) + 4) - v18->field_A + 8 * v18->field_A;
        else
          v27 = 0;
        while ( v27 )
        {
          if ( v30[(*(_BYTE *)(v27 + 5) >> 2) & 0x3F] )
            IconToBitmapScale(
              *(_DWORD *)((char *)thisa + 4 * ((*(_BYTE *)(v27 + 5) >> 2) & 0x3F) + 206),
              (int)gpWindowManager->screenBuffer,
              v20,
              y,
              *(_BYTE *)(v27 + 6),
              0,
              0,
              0,
              0x280u,
              480,
              giViewWorldScale);
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
    v28 = (unsigned int)&gpWindowManager->screenBuffer->contents[640 * row + 16];
    v29 = v28 + 448;
    while ( v28 < v29 )
    {
      *(_BYTE *)v28 = gColorTableNoCycle[*(_BYTE *)v28];
      ++v28;
    }
  }
  for ( row = iVWMapOriginY; iVWMapOriginY + iVWViewableCells > row; ++row )
  {
    for ( col = iVWMapOriginX; iVWViewableCells + iVWMapOriginX > col; ++col )
    {
      v18 = advManager::GetCell((advManager *)thisa, col, row);
      v20 = iVWXPixelOffset + (giViewWorldScale >> 1) + giViewWorldScale * (col - iVWMapOriginX);
      y = iVWYPixelOffset + (giViewWorldScale >> 1) + giViewWorldScale * (row - iVWMapOriginY);
      if ( v18->objType == 169
        && (iVWDrawAllObjs
         || (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
         || iVWWhatToDraw == 50) )
        IconToBitmap(
          pVWMisc,
          gpWindowManager->screenBuffer,
          v20 - byte_51921C[12 * giViewWorldScaleLookup],
          y - byte_51921D[12 * giViewWorldScaleLookup],
          14,
          1,
          16,
          16,
          0x1C0u,
          448,
          (unsigned int)(iVWWhatToDraw - 50) < 1 ? 0xD6 : 0);
      if ( (v18->objType == 163
         || v18->objType == 170
         && gpGame->heroes[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5)].occupiedObjType == 163)
        && (iVWDrawAllObjs
         || (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
         || iVWWhatToDraw == 51) )
      {
        if ( v18->objType == 163 )
          v17 = gpGame->_7[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5)];
        else
          v17 = gpGame->_7[gpGame->heroes[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5)].occupiedObjVal];
        if ( v17 >= 0 )
          v17 = gpGame->players[v17].color;
        else
          v17 = 6;
        v13 = -2;
        v14 = -3;
        v15 = -6;
        v10 = 5;
        v11 = 7;
        v12 = 10;
        if ( iVWWhatToDraw == 51 )
          a11 = v17 + 215;
        else
          a11 = 0;
        FlipIconToBitmap(
          pVWFlags,
          gpWindowManager->screenBuffer,
          v20 + *(&v13 + giViewWorldScaleLookup) - byte_519220[12 * giViewWorldScaleLookup],
          y - byte_519221[12 * giViewWorldScaleLookup],
          v17,
          1,
          16,
          16,
          448,
          448,
          a11);
        if ( iVWWhatToDraw == 51 )
          v4 = v17 + 215;
        else
          v4 = 0;
        IconToBitmap(
          pVWFlags,
          gpWindowManager->screenBuffer,
          v20 + *(&v10 + giViewWorldScaleLookup) - byte_519220[12 * giViewWorldScaleLookup],
          y - byte_519221[12 * giViewWorldScaleLookup],
          v17,
          1,
          16,
          16,
          0x1C0u,
          448,
          v4);
      }
      v26 = gpCurPlayer->curHeroIdx != -1
         && gpGame->heroes[gpCurPlayer->curHeroIdx].x == col
         && gpGame->heroes[gpCurPlayer->curHeroIdx].y == row;
      if ( v18->objType == 170 || v26 )
      {
        if ( iVWDrawAllObjs
          || (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
          || iVWWhatToDraw == 52 )
        {
          v17 = v26 ? gpGame->relatedToHeroForHireStatus[gpCurPlayer->curHeroIdx] : gpGame->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5)];
          if ( v17 >= 0 )
          {
            spriteIdx = gpGame->players[v17].color;
            if ( iVWWhatToDraw == 52 )
              v3 = spriteIdx + 215;
            else
              v3 = 0;
            IconToBitmap(
              pVWMisc,
              gpWindowManager->screenBuffer,
              v20 - byte_519218[12 * giViewWorldScaleLookup],
              y - byte_519219[12 * giViewWorldScaleLookup],
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
      if ( v18->objType == 155
        && (iVWDrawAllObjs
         || (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
         || iVWWhatToDraw == 49) )
      {
        spriteIdx = (signed int)HIBYTE(v18->field_2) >> 1;
        IconToBitmap(
          pVWMisc,
          gpWindowManager->screenBuffer,
          v20 - byte_51921A[12 * giViewWorldScaleLookup],
          y - byte_51921B[12 * giViewWorldScaleLookup],
          13,
          1,
          16,
          16,
          0x1C0u,
          448,
          (unsigned int)(iVWWhatToDraw - 49) < 1 ? 0xDD : 0);
        IconToBitmap(
          pVWLetters,
          gpWindowManager->screenBuffer,
          v20 - byte_519222[12 * giViewWorldScaleLookup],
          y - byte_519223[12 * giViewWorldScaleLookup],
          spriteIdx,
          1,
          16,
          16,
          0x1C0u,
          448,
          0);
      }
      if ( (v18->objType == 151 || v18->objType == 157 || v18->objType == 129)
        && (iVWDrawAllObjs
         || (unsigned __int8)(*(&mapExtra[col] + row * MAP_WIDTH) & giCurPlayerBit)
         || iVWWhatToDraw == 48) )
      {
        v17 = gpGame->_8[(unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5) + 1008];
        if ( v17 < 0 )
          spriteIdx = 6;
        else
          spriteIdx = gpGame->players[v17].color;
        if ( iVWWhatToDraw == 48 )
          v2 = spriteIdx + 215;
        else
          v2 = 0;
        IconToBitmap(
          pVWMisc,
          gpWindowManager->screenBuffer,
          v20 - byte_51921E[12 * giViewWorldScaleLookup],
          y - byte_51921F[12 * giViewWorldScaleLookup],
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
        v21 = gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v18->flags >> 8) >> -5) + 2];
        IconToBitmap(
          pVWLetters,
          gpWindowManager->screenBuffer,
          v20 - byte_519222[12 * giViewWorldScaleLookup],
          y + *(&v7 + giViewWorldScaleLookup) - byte_519223[12 * giViewWorldScaleLookup],
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
  heroWindowManager::UpdateScreenRegion(gpWindowManager, 16, 16, 0x1C0u, 448);
}