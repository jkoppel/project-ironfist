{
  signed int v8; // [sp+10h] [bp-18h]@201
  signed int v9; // [sp+14h] [bp-14h]@194
  int v10; // [sp+1Ch] [bp-Ch]@199
  int v11; // [sp+20h] [bp-8h]@182
  int v12; // [sp+24h] [bp-4h]@127

  if ( !a6 && !bShowIt )
    return;
  dword_524D10 = 32 * a3;
  ::y = 32 * a4;
  currentlyDrawnMapTile = advManager::GetCell(this, x, y);
  if ( !gbAllBlack && ((signed __int64)__PAIR__(y, x) < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT) )
  {
    idx = -1;
    if ( x == -1 )
    {
      if ( y == -1 )
      {
        idx = 16;
      }
      else if ( y == MAP_HEIGHT )
      {
        idx = 19;
      }
      else if ( y >= 0 && y < MAP_HEIGHT )
      {
        idx = (y & 3) + 32;
      }
    }
    else if ( x == MAP_WIDTH )
    {
      if ( y == -1 )
      {
        idx = 17;
      }
      else if ( y == MAP_HEIGHT )
      {
        idx = 18;
      }
      else if ( y >= 0 && y < MAP_HEIGHT )
      {
        idx = (y & 3) + 24;
      }
    }
    else if ( y == -1 )
    {
      if ( x >= 0 && x < MAP_WIDTH )
        idx = (x & 3) + 20;
    }
    else if ( y == MAP_HEIGHT && x >= 0 && x < MAP_WIDTH )
    {
      idx = (x & 3) + 28;
    }
    if ( idx == -1 )
      idx = (((unsigned __int64)(x + 16) >> 32) ^ abs(x + 16) & 3)
          + 4 * ((((unsigned __int64)(y + 16) >> 32) ^ abs(y + 16) & 3) - ((unsigned __int64)(y + 16) >> 32))
          - ((unsigned __int64)(x + 16) >> 32);
    TileToBitmap(this->stonTileset, idx, gpWindowManager->screenBuffer, dword_524D10, ::y);
    return;
  }
  if ( !gbAllBlack && (unsigned __int8)(*(&mapExtra[x] + MAP_WIDTH * y) & giCurWatchPlayerBit) || gbDrawingPuzzle )
  {
    dword_524CF8 = 0;
  }
  else
  {
    dword_524CF8 = 1;
    if ( gbAllBlack )
      dword_524D24 = 0;
    else
      dword_524D24 = advManager::GetCloudLookup(x, y);
    if ( !dword_524D24 )
    {
      if ( a5 & 0x20 )
        TileToBitmap(this->clofTileset, ((_BYTE)x + (_BYTE)y) & 3, gpWindowManager->screenBuffer, dword_524D10, ::y);
      return;
    }
    if ( dword_524D24 < 100 )
    {
      dword_524CD4 = 0;
    }
    else
    {
      dword_524CD4 = 1;
      dword_524D24 -= 100;
    }
    if ( (dword_524D24 == 1 || dword_524D24 == 5) && x & 1 )
      ++dword_524D24;
    if ( dword_524D24 == 3 && y & 1 )
      ++dword_524D24;
  }
  if ( !(a5 & 0x20) || gbDrawingPuzzle )
  {
    if ( a5 & 1 )
    {
      LOWORD(word_524CAC) = currentlyDrawnMapTile->field_8;
      LOWORD(word_524CAC) = (_WORD)word_524CAC << 14;
      LOWORD(word_524CAC) = word_524CAC | currentlyDrawnMapTile->tileType;
      TileToBitmap(this->groundTileset, (unsigned __int16)word_524CAC, gpWindowManager->screenBuffer, dword_524D10, ::y);
      if ( currentlyDrawnMapTile->flags & 1
        && (!gbDrawingPuzzle
         || ((LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F) != 56
         || HIBYTE(currentlyDrawnMapTile->field_2) != 140) )
      {
        if ( !gbDrawingPuzzle || bPuzzleDraw[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F] )
        {
          IconToBitmap(
            (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            HIBYTE(currentlyDrawnMapTile->field_2),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( currentlyDrawnMapTile->field_2 & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
                             HIBYTE(currentlyDrawnMapTile->field_2))->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              HIBYTE(currentlyDrawnMapTile->field_2) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( currentlyDrawnMapTile->field_A
        && *(_BYTE *)(this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A + 3) != 255 )
        dword_524EAC = this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A;
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( *(_BYTE *)(dword_524EAC + 4) & 1
          && (!gbDrawingPuzzle || bPuzzleDraw[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          IconToBitmap(
            (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              *(_BYTE *)(dword_524EAC + 3) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if ( *(_WORD *)dword_524EAC
          && *(_BYTE *)(this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
      if ( (currentlyDrawnMapTile->flags >> 1) & 1
        && !(currentlyDrawnMapTile->flags & 1)
        && (!gbDrawingPuzzle || bPuzzleDraw[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F]) )
      {
        IconToBitmap(
          (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
          gpWindowManager->screenBuffer,
          dword_524D10,
          ::y,
          HIBYTE(currentlyDrawnMapTile->field_2),
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if ( currentlyDrawnMapTile->field_2 & 1 )
        {
          dword_524CE4 = GetIconEntry(
                           (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
                           HIBYTE(currentlyDrawnMapTile->field_2))->someSortOfLength & 0x1F;
          IconToBitmap(
            (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            HIBYTE(currentlyDrawnMapTile->field_2) + this->field_202 % dword_524CE4 + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }
      if ( currentlyDrawnMapTile->field_A
        && *(_BYTE *)(this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A + 3) != 255 )
        dword_524EAC = this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A;
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( (*(_BYTE *)(dword_524EAC + 4) >> 1) & 1
          && !(*(_BYTE *)(dword_524EAC + 4) & 1)
          && (!gbDrawingPuzzle || bPuzzleDraw[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          IconToBitmap(
            (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              *(_BYTE *)(dword_524EAC + 3) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if ( *(_WORD *)dword_524EAC
          && *(_BYTE *)(this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
    if ( a5 & 2 )
    {
      if ( HIBYTE(currentlyDrawnMapTile->field_2) != 255
        && !(currentlyDrawnMapTile->flags & 1)
        && !((currentlyDrawnMapTile->flags >> 1) & 1)
        && !((currentlyDrawnMapTile->flags >> 2) & 1)
        && ((LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F) != 12
        && (!gbDrawingPuzzle || bPuzzleDraw[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F]) )
      {
        IconToBitmap(
          (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
          gpWindowManager->screenBuffer,
          dword_524D10,
          ::y,
          HIBYTE(currentlyDrawnMapTile->field_2),
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if ( currentlyDrawnMapTile->field_2 & 1 )
        {
          dword_524CE4 = GetIconEntry(
                           (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
                           HIBYTE(currentlyDrawnMapTile->field_2))->someSortOfLength & 0x1F;
          v12 = this->field_202 % dword_524CE4;
          if ( currentlyDrawnMapTile->objType == 223 )
          {
            if ( (unsigned __int8)(currentlyDrawnMapTile->flags >> 8) >> -5 )
              v12 = this->field_202 % (dword_524CE4 - 1);
            else
              v12 = dword_524CE4 - 1;
          }
          IconToBitmap(
            (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            v12 + HIBYTE(currentlyDrawnMapTile->field_2) + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }
      if ( currentlyDrawnMapTile->field_A
        && *(_BYTE *)(this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A + 3) != 255 )
        dword_524EAC = this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A;
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( !(*(_BYTE *)(dword_524EAC + 4) & 1)
          && !((*(_BYTE *)(dword_524EAC + 4) >> 1) & 1)
          && !((*(_BYTE *)(dword_524EAC + 4) >> 2) & 1)
          && ((*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F) != 12
          && (!gbDrawingPuzzle || bPuzzleDraw[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          IconToBitmap(
            (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              *(_BYTE *)(dword_524EAC + 3) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if ( *(_WORD *)dword_524EAC
          && *(_BYTE *)(this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
    if ( (a5 & 8 || a5 & 0x80) && !gbDrawingPuzzle )
    {
      dword_524D04 = 0;
      dword_524CDC = 0;
      if ( a5 & 8 )
      {
        if ( x > 0 )
        {
          dword_524D08 = (int)advManager::GetCell(this, x - 1, y);
          if ( *(_BYTE *)(dword_524D08 + 9) == 151 )
          {
            dword_524EA8 = (int)&gpGame->_8[7
                                          * (unsigned __int8)((unsigned __int8)(*(_WORD *)(dword_524D08 + 4) >> 8) >> -5)];
            if ( *(_BYTE *)(dword_524EA8 + 3) == 59 )
            {
              IconToBitmap(
                (icon *)this->field_CE[10],
                gpWindowManager->screenBuffer,
                dword_524D10 - 16,
                ::y,
                (x + y + this->field_202) % 15,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
            else if ( *(_BYTE *)(dword_524EA8 + 3) != -1 )
            {
              IconToBitmap(
                (icon *)this->field_CE[39],
                gpWindowManager->screenBuffer,
                dword_524D10 - 32,
                ::y,
                *(_BYTE *)(dword_524EA8 + 3) - 62,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          }
        }
        if ( ((LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F) == 12 )
        {
          if ( this->field_2B2 != x || this->field_2B6 != y )
          {
            IconToBitmap(
              (icon *)this->field_CE[20],
              gpWindowManager->screenBuffer,
              dword_524D10 + 16,
              ::y + 30,
              9 * HIBYTE(currentlyDrawnMapTile->field_2),
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( HIBYTE(currentlyDrawnMapTile->field_2) != 59 && HIBYTE(currentlyDrawnMapTile->field_2) != 60 )
              dword_524D14 = (unsigned __int8)monAnimDrawFrame[*(&this->field_20A + (x & 3))];
            else
              dword_524D14 = *(&this->field_20A + (x & 3)) % 6;
            IconToBitmap(
              (icon *)this->field_CE[20],
              gpWindowManager->screenBuffer,
              dword_524D10 + 16,
              ::y + 30,
              dword_524D14 + 9 * HIBYTE(currentlyDrawnMapTile->field_2) + 1,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
          else
          {
            IconToBitmap(
              (icon *)this->field_CE[20],
              gpWindowManager->screenBuffer,
              dword_524D10 + 16,
              ::y + 30,
              8 - (this->field_2BA < 1u) + 9 * HIBYTE(currentlyDrawnMapTile->field_2),
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( currentlyDrawnMapTile->objType == 171 )
      {
        dword_524E74 = -1;
        dword_524EA0 = 6;
        spriteIdx = advManager::GetCursorBaseFrame(gpGame->probablyArtifactGeneratedRandomly[8
                                                                                           * (unsigned __int8)((unsigned __int8)(currentlyDrawnMapTile->flags >> 8) >> -5)
                                                                                           + 106]);
        dword_524D04 = 1;
        dword_524D2C = -10;
      }
      else
      {
        dword_524D2C = 0;
        if ( currentlyDrawnMapTile->objType == 170 )
        {
          dword_524CDC = (int)&gpGame->heroes[(unsigned __int8)((unsigned __int8)(currentlyDrawnMapTile->flags >> 8) >> -5)];
          dword_524E74 = gpGame->players[*(_BYTE *)(dword_524CDC + 3)].color;
          dword_524EA0 = *(_BYTE *)(dword_524CDC + 227) & 0x80 ? 6 : *(_BYTE *)(dword_524CDC + 23);
          spriteIdx = advManager::GetCursorBaseFrame(*(_BYTE *)(dword_524CDC + 44));
          dword_524D04 = 1;
          if ( *(_BYTE *)(dword_524CDC + 227) & 0x80 )
            dword_524D2C = -10;
        }
      }
      if ( dword_524D04 )
      {
        if ( spriteIdx & 0x80 )
        {
          if ( a5 & 0x80 )
          {
            if ( this->field_276 && dword_524EA0 != 6 )
            {
              v11 = spriteIdx & 0x7F;
              if ( v11 == 51 )
                v11 = 56;
              if ( v11 == 50 )
                v11 = 57;
              if ( v11 == 49 )
                v11 = 58;
              if ( v11 == 47 )
                v11 = 55;
              if ( v11 == 46 )
                v11 = 55;
              if ( v11 < 9 || v11 >= 36 )
                v9 = 0;
              else
                v9 = 50;
              IconToBitmap(
                this->shadowIcon,
                gpWindowManager->screenBuffer,
                dword_524D10,
                ::y + 31,
                v9 + v11,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
            if ( this->field_276 && dword_524EA0 == 6 )
            {
              v10 = spriteIdx & 0x7F;
              if ( v10 < 9 || v10 >= 36 )
                v8 = 0;
              else
                v8 = 36;
              IconToBitmap(
                this->boatShadowIcon,
                gpWindowManager->screenBuffer,
                dword_524D10,
                dword_524D2C + ::y + 31,
                v8 + v10,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          }
          else
          {
            if ( dword_524EA0 == 6 && !(currentlyDrawnMapTile->field_8 & 4) )
              FlipIconToBitmap(
                this->frothIcon,
                gpWindowManager->screenBuffer,
                dword_524D10 + 32,
                dword_524D2C + ::y + 31,
                spriteIdx & 0x7F,
                1,
                0,
                0,
                480,
                480,
                0);
            FlipIconToBitmap(
              (icon *)this->heroIcons[dword_524EA0],
              gpWindowManager->screenBuffer,
              dword_524D10 + 32,
              dword_524D2C + ::y + 31,
              spriteIdx & 0x7F,
              1,
              0,
              0,
              480,
              480,
              0);
            if ( dword_524E74 != -1 )
            {
              if ( dword_524EA0 == 6 )
                FlipIconToBitmap(
                  (icon *)this->flagIcons2[dword_524E74],
                  gpWindowManager->screenBuffer,
                  dword_524D10 + 32,
                  dword_524D2C + ::y + 31,
                  spriteIdx & 0x7F,
                  1,
                  0,
                  0,
                  480,
                  480,
                  0);
              else
                FlipIconToBitmap(
                  (icon *)this->flagIcons1[dword_524E74],
                  gpWindowManager->screenBuffer,
                  dword_524D10 + 32,
                  ::y + 31,
                  (spriteIdx & 0x7F)
                + (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
                - ((unsigned __int64)this->field_202 >> 32)
                + 56,
                  1,
                  0,
                  0,
                  480,
                  480,
                  0);
            }
          }
        }
        else if ( a5 & 0x80 )
        {
          if ( this->field_276 && dword_524EA0 != 6 && a5 & 0x80 )
            IconToBitmap(
              this->shadowIcon,
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          if ( this->field_276 && dword_524EA0 == 6 )
            IconToBitmap(
              this->boatShadowIcon,
              gpWindowManager->screenBuffer,
              dword_524D10,
              dword_524D2C + ::y + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
        }
        else
        {
          if ( dword_524EA0 == 6 && !(currentlyDrawnMapTile->field_8 & 4) )
            IconToBitmap(
              this->frothIcon,
              gpWindowManager->screenBuffer,
              dword_524D10,
              dword_524D2C + ::y + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          IconToBitmap(
            (icon *)this->heroIcons[dword_524EA0],
            gpWindowManager->screenBuffer,
            dword_524D10,
            dword_524D2C + ::y + 31,
            spriteIdx,
            1,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( dword_524E74 != -1 )
          {
            if ( dword_524EA0 == 6 )
              IconToBitmap(
                (icon *)this->flagIcons2[dword_524E74],
                gpWindowManager->screenBuffer,
                dword_524D10,
                dword_524D2C + ::y + 31,
                spriteIdx & 0x7F,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            else
              IconToBitmap(
                (icon *)this->flagIcons1[dword_524E74],
                gpWindowManager->screenBuffer,
                dword_524D10,
                ::y + 31,
                (spriteIdx & 0x7F)
              + (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
              - ((unsigned __int64)this->field_202 >> 32)
              + 56,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
          }
        }
      }
      if ( this->field_272
        && currentlyDrawnMapTile->field_8 & 0x40
        && (!*(_DWORD *)&this->field_292[16] || a5 & 0x80)
        && this->viewX + 7 == x
        && this->viewY + 7 == y
        && !(a5 & 0x80) )
      {
        advManager::DrawCursorShadow(this);
        advManager::DrawCursor(this);
        *(_DWORD *)&this->field_292[16] = 1;
      }
    }
    if ( a5 & 4 || a5 & 0x40 )
    {
      if ( a5 & 4 && HIBYTE(currentlyDrawnMapTile->field_2) != 255 )
      {
        if ( (currentlyDrawnMapTile->flags >> 2) & 1
          && (!gbDrawingPuzzle || bPuzzleDraw[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F]) )
        {
          IconToBitmap(
            (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            HIBYTE(currentlyDrawnMapTile->field_2),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( currentlyDrawnMapTile->field_2 & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
                             HIBYTE(currentlyDrawnMapTile->field_2))->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[(LOBYTE(currentlyDrawnMapTile->field_2) >> 2) & 0x3F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              HIBYTE(currentlyDrawnMapTile->field_2) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if ( currentlyDrawnMapTile->field_A
          && *(_BYTE *)(this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A + 3) != 255 )
          dword_524EAC = this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A;
        else
          dword_524EAC = 0;
        while ( dword_524EAC )
        {
          if ( (*(_BYTE *)(dword_524EAC + 4) >> 2) & 1
            && (!gbDrawingPuzzle || bPuzzleDraw[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
          {
            IconToBitmap(
              (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              *(_BYTE *)(dword_524EAC + 3),
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
            {
              dword_524CE4 = GetIconEntry(
                               (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                               *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
              IconToBitmap(
                (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                gpWindowManager->screenBuffer,
                dword_524D10,
                ::y,
                *(_BYTE *)(dword_524EAC + 3) + this->field_202 % dword_524CE4 + 1,
                0,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          }
          if ( *(_WORD *)dword_524EAC
            && *(_BYTE *)(this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
            dword_524EAC = this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
          else
            dword_524EAC = 0;
        }
      }
      if ( currentlyDrawnMapTile->field_7 != 255
        && (a5 & 4 && !(((unsigned __int8)currentlyDrawnMapTile->field_6 >> 1) & 1)
         || a5 & 0x40 && ((unsigned __int8)currentlyDrawnMapTile->field_6 >> 1) & 1) )
      {
        if ( !gbDrawingPuzzle || bPuzzleDraw[((unsigned __int8)currentlyDrawnMapTile->field_6 >> 2) & 0x3F] )
        {
          IconToBitmap(
            (icon *)this->field_CE[((unsigned __int8)currentlyDrawnMapTile->field_6 >> 2) & 0x3F],
            gpWindowManager->screenBuffer,
            dword_524D10,
            ::y,
            currentlyDrawnMapTile->field_7,
            (((unsigned __int8)currentlyDrawnMapTile->field_6 >> 2) & 0x3F) == 14,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( currentlyDrawnMapTile->field_6 & 1 )
          {
            dword_524CE4 = GetIconEntry(
                             (icon *)this->field_CE[((unsigned __int8)currentlyDrawnMapTile->field_6 >> 2) & 0x3F],
                             currentlyDrawnMapTile->field_7)->someSortOfLength & 0x1F;
            IconToBitmap(
              (icon *)this->field_CE[((unsigned __int8)currentlyDrawnMapTile->field_6 >> 2) & 0x3F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              currentlyDrawnMapTile->field_7 + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( currentlyDrawnMapTile->field_A
        && *(_BYTE *)(this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A + 6) != 255 )
        dword_524EAC = this->map->field_4 - currentlyDrawnMapTile->field_A + 8 * currentlyDrawnMapTile->field_A;
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( a5 & 4 && !((*(_BYTE *)(dword_524EAC + 5) >> 1) & 1)
          || a5 & 0x40 && (*(_BYTE *)(dword_524EAC + 5) >> 1) & 1 )
        {
          if ( !gbDrawingPuzzle || bPuzzleDraw[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F] )
          {
            IconToBitmap(
              (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
              gpWindowManager->screenBuffer,
              dword_524D10,
              ::y,
              *(_BYTE *)(dword_524EAC + 6),
              ((*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F) == 14,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( *(_BYTE *)(dword_524EAC + 5) & 1 )
            {
              dword_524CE4 = GetIconEntry(
                               (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
                               *(_BYTE *)(dword_524EAC + 6))->someSortOfLength & 0x1F;
              IconToBitmap(
                (icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
                gpWindowManager->screenBuffer,
                dword_524D10,
                ::y,
                *(_BYTE *)(dword_524EAC + 6) + this->field_202 % dword_524CE4 + 1,
                0,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          }
        }
        if ( *(_WORD *)dword_524EAC
          && *(_BYTE *)(this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 6) != 255 )
          dword_524EAC = this->map->field_4 - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
  }
  else if ( dword_524CF8 )
  {
    if ( dword_524CD4 )
      FlipIconToBitmap(
        this->clopIcon,
        gpWindowManager->screenBuffer,
        dword_524D10 + 31,
        ::y,
        dword_524D24 - 1,
        0,
        0,
        0,
        0,
        0,
        0);
    else
      IconToBitmap(this->clopIcon, gpWindowManager->screenBuffer, dword_524D10, ::y, dword_524D24 - 1, 0, 0, 0, 0, 0, 0);
  }
  else if ( this->field_A2 && *(_WORD *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) )
  {
    if ( (*(_WORD *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) >> 8) & 1 )
      IconToBitmapColorTable(
        (icon *)this->field_CE[17],
        gpWindowManager->screenBuffer,
        dword_524D10 - 12,
        ::y + 2,
        (unsigned __int8)(*(_WORD *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) - 1),
        1,
        0,
        0,
        0x1E0u,
        480,
        0,
        gColorTableRed,
        1);
    else
      IconToBitmap(
        (icon *)this->field_CE[17],
        gpWindowManager->screenBuffer,
        dword_524D10 - 12,
        ::y + 2,
        (unsigned __int8)(*(_WORD *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) - 1),
        1,
        0,
        0,
        0x1E0u,
        480,
        0);
  }
}