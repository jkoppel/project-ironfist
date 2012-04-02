void __thiscall AdvManager::drawAdventureMap(AdvManager *this, __int64 a2, int a3, int a4, char a5, int a6)
{
  signed int v7; // [sp+10h] [bp-18h]@200
  signed int v8; // [sp+14h] [bp-14h]@193
  int v9; // [sp+1Ch] [bp-Ch]@198
  int v10; // [sp+20h] [bp-8h]@181
  int v11; // [sp+24h] [bp-4h]@127

  if ( !a6 && !dword_524C14 )
    return;
  dword_524D10 = 32 * a3;
  y = 32 * a4;
  dword_524D00 = usedToCheckForBoatByCastle(this, a2, SHIDWORD(a2));
  if ( !dword_4F7470 && (a2 < 0 || (signed int)a2 >= mapWidth || SHIDWORD(a2) >= mapHeight) )
  {
    dword_524CEC = -1;
    if ( (_DWORD)a2 == -1 )
    {
      if ( HIDWORD(a2) == -1 )
      {
        dword_524CEC = 16;
      }
      else
      {
        if ( HIDWORD(a2) == mapHeight )
        {
          dword_524CEC = 19;
        }
        else
        {
          if ( SHIDWORD(a2) >= 0 && SHIDWORD(a2) < mapHeight )
            dword_524CEC = (BYTE4(a2) & 3) + 32;
        }
      }
    }
    else
    {
      if ( (_DWORD)a2 == mapWidth )
      {
        if ( HIDWORD(a2) == -1 )
        {
          dword_524CEC = 17;
        }
        else
        {
          if ( HIDWORD(a2) == mapHeight )
          {
            dword_524CEC = 18;
          }
          else
          {
            if ( SHIDWORD(a2) >= 0 && SHIDWORD(a2) < mapHeight )
              dword_524CEC = (BYTE4(a2) & 3) + 24;
          }
        }
      }
      else
      {
        if ( HIDWORD(a2) == -1 )
        {
          if ( (signed int)a2 >= 0 && (signed int)a2 < mapWidth )
            dword_524CEC = (a2 & 3) + 20;
        }
        else
        {
          if ( HIDWORD(a2) == mapHeight && (signed int)a2 >= 0 && (signed int)a2 < mapWidth )
            dword_524CEC = (a2 & 3) + 28;
        }
      }
    }
    if ( dword_524CEC == -1 )
      dword_524CEC = (((unsigned __int64)((signed int)a2 + 16) >> 32) ^ abs(a2 + 16) & 3)
                   + 4
                   * ((((unsigned __int64)(HIDWORD(a2) + 16) >> 32) ^ abs(BYTE4(a2) + 16) & 3)
                    - ((unsigned __int64)(HIDWORD(a2) + 16) >> 32))
                   - ((unsigned __int64)((signed int)a2 + 16) >> 32);
    sub_4D7124((int)this->stonTileset, dword_524CEC, (int)HeroWindowManager::instance->screenBuffer, dword_524D10, y);
    return;
  }
  if ( !dword_4F7470 && (unsigned __int8)(*(&tileExplored[(_DWORD)a2] + mapWidth * HIDWORD(a2)) & byte_5306F0)
    || dword_4F5460 )
  {
    dword_524CF8 = 0;
  }
  else
  {
    dword_524CF8 = 1;
    if ( dword_4F7470 )
      dword_524D24 = 0;
    else
      dword_524D24 = sub_448150(a2, SHIDWORD(a2));
    if ( !dword_524D24 )
    {
      if ( a5 & 0x20 )
        sub_4D7124(
          (int)this->clofTileset,
          ((_BYTE)a2 + BYTE4(a2)) & 3,
          (int)HeroWindowManager::instance->screenBuffer,
          dword_524D10,
          y);
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
    if ( (dword_524D24 == 1 || dword_524D24 == 5) && a2 & 1 )
      ++dword_524D24;
    if ( dword_524D24 == 3 && BYTE4(a2) & 1 )
      ++dword_524D24;
  }
  if ( !(a5 & 0x20) || dword_4F5460 )
  {
    if ( a5 & 1 )
    {
      word_524CAC = *(_BYTE *)(dword_524D00 + 8);
      word_524CAC <<= 14;
      word_524CAC |= *(_WORD *)dword_524D00;
      sub_4D7124(
        (int)this->groundTileset,
        (unsigned __int16)word_524CAC,
        (int)HeroWindowManager::instance->screenBuffer,
        dword_524D10,
        y);
      if ( *(_WORD *)(dword_524D00 + 4) & 1
        && (!dword_4F5460 || ((*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F) != 56 || *(_BYTE *)(dword_524D00 + 3) != 140) )
      {
        if ( !dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F] )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524D00 + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524D00 + 2) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
                             *(_BYTE *)(dword_524D00 + 3))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
              *(_BYTE *)(dword_524D00 + 3) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( *(_WORD *)(dword_524D00 + 10)
        && *(_BYTE *)(this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10) + 3) != 255 )
        dword_524EAC = this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10);
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( *(_BYTE *)(dword_524EAC + 4) & 1
          && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
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
          && *(_BYTE *)(this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
      if ( (*(_WORD *)(dword_524D00 + 4) >> 1) & 1
        && !(*(_WORD *)(dword_524D00 + 4) & 1)
        && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F]) )
      {
        rasterize(
          (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
          HeroWindowManager::instance->screenBuffer,
          dword_524D10,
          y,
          *(_BYTE *)(dword_524D00 + 3),
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if ( *(_BYTE *)(dword_524D00 + 2) & 1 )
        {
          dword_524CE4 = getNthHeader(
                           (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
                           *(_BYTE *)(dword_524D00 + 3))->someSortOfLength & 0x1F;
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524D00 + 3) + this->field_202 % dword_524CE4 + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }
      if ( *(_WORD *)(dword_524D00 + 10)
        && *(_BYTE *)(this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10) + 3) != 255 )
        dword_524EAC = this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10);
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( (*(_BYTE *)(dword_524EAC + 4) >> 1) & 1
          && !(*(_BYTE *)(dword_524EAC + 4) & 1)
          && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
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
          && *(_BYTE *)(this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
    if ( a5 & 2 )
    {
      if ( *(_BYTE *)(dword_524D00 + 3) != 255
        && !(*(_WORD *)(dword_524D00 + 4) & 1)
        && !((*(_WORD *)(dword_524D00 + 4) >> 1) & 1)
        && !((*(_WORD *)(dword_524D00 + 4) >> 2) & 1)
        && ((*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F) != 12
        && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F]) )
      {
        rasterize(
          (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
          HeroWindowManager::instance->screenBuffer,
          dword_524D10,
          y,
          *(_BYTE *)(dword_524D00 + 3),
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if ( *(_BYTE *)(dword_524D00 + 2) & 1 )
        {
          dword_524CE4 = getNthHeader(
                           (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
                           *(_BYTE *)(dword_524D00 + 3))->someSortOfLength & 0x1F;
          v11 = this->field_202 % dword_524CE4;
          if ( *(_BYTE *)(dword_524D00 + 9) == 223 )
          {
            if ( (unsigned __int8)(*(_WORD *)(dword_524D00 + 4) >> 8) >> -5 )
              v11 = this->field_202 % (dword_524CE4 - 1);
            else
              v11 = dword_524CE4 - 1;
          }
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            v11 + *(_BYTE *)(dword_524D00 + 3) + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }
      if ( *(_WORD *)(dword_524D00 + 10)
        && *(_BYTE *)(this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10) + 3) != 255 )
        dword_524EAC = this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10);
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( !(*(_BYTE *)(dword_524EAC + 4) & 1)
          && !((*(_BYTE *)(dword_524EAC + 4) >> 1) & 1)
          && !((*(_BYTE *)(dword_524EAC + 4) >> 2) & 1)
          && ((*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F) != 12
          && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524EAC + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                             *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
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
          && *(_BYTE *)(this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
          dword_524EAC = this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
    if ( (a5 & 8 || a5 & 0x80) && !dword_4F5460 )
    {
      dword_524D04 = 0;
      dword_524CDC = 0;
      if ( a5 & 8 )
      {
        if ( (signed int)a2 > 0 )
        {
          dword_524D08 = usedToCheckForBoatByCastle(this, a2 - 1, SHIDWORD(a2));
          if ( *(_BYTE *)(dword_524D08 + 9) == 151 )
          {
            dword_524EA8 = (int)&gameObject->_8[7
                                              * (unsigned __int8)((unsigned __int8)(*(_WORD *)(dword_524D08 + 4) >> 8) >> -5)];
            if ( *(_BYTE *)(dword_524EA8 + 3) == 59 )
            {
              rasterize(
                (Icon *)this->field_CE[10],
                HeroWindowManager::instance->screenBuffer,
                dword_524D10 - 16,
                y,
                ((signed int)a2 + HIDWORD(a2) + this->field_202) % 15,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
            else
            {
              if ( *(_BYTE *)(dword_524EA8 + 3) != -1 )
                rasterize(
                  (Icon *)this->field_CE[39],
                  HeroWindowManager::instance->screenBuffer,
                  dword_524D10 - 32,
                  y,
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
        if ( ((*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F) == 12 )
        {
          if ( *(_QWORD *)&this->field_2B2 == a2 )
          {
            rasterize(
              (Icon *)this->field_CE[20],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10 + 16,
              y + 30,
              8 - (this->field_2BA < 1u) + 9 * *(_BYTE *)(dword_524D00 + 3),
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
          else
          {
            rasterize(
              (Icon *)this->field_CE[20],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10 + 16,
              y + 30,
              9 * *(_BYTE *)(dword_524D00 + 3),
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( *(_BYTE *)(dword_524D00 + 3) != 59 && *(_BYTE *)(dword_524D00 + 3) != 60 )
              dword_524D14 = (unsigned __int8)byte_50F100[*(&this->field_20A + (a2 & 3))];
            else
              dword_524D14 = *(&this->field_20A + (a2 & 3)) % 6;
            rasterize(
              (Icon *)this->field_CE[20],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10 + 16,
              y + 30,
              dword_524D14 + 9 * *(_BYTE *)(dword_524D00 + 3) + 1,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( *(_BYTE *)(dword_524D00 + 9) == 171 )
      {
        dword_524E74 = -1;
        dword_524EA0 = 6;
        spriteIdx = sub_4C0550(gameObject->probablyArtifactGeneratedRandomly[8
                                                                           * (unsigned __int8)((unsigned __int8)(*(_WORD *)(dword_524D00 + 4) >> 8) >> -5)
                                                                           + 106]);
        dword_524D04 = 1;
        dword_524D2C = -10;
      }
      else
      {
        dword_524D2C = 0;
        if ( *(_BYTE *)(dword_524D00 + 9) == 170 )
        {
          dword_524CDC = (int)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(dword_524D00 + 4) >> 8) >> -5)];
          dword_524E74 = gameObject->players[*(_BYTE *)(dword_524CDC + 3)].color;
          dword_524EA0 = *(_BYTE *)(dword_524CDC + 227) & 0x80 ? 6 : *(_BYTE *)(dword_524CDC + 23);
          spriteIdx = sub_4C0550(*(_BYTE *)(dword_524CDC + 44));
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
              v10 = spriteIdx & 0x7F;
              if ( v10 == 51 )
                v10 = 56;
              if ( v10 == 50 )
                v10 = 57;
              if ( v10 == 49 )
                v10 = 58;
              if ( v10 == 47 )
                v10 = 55;
              if ( v10 == 46 )
                v10 = 55;
              if ( v10 < 9 || v10 >= 36 )
                v8 = 0;
              else
                v8 = 50;
              rasterize(
                this->shadowIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                y + 31,
                v8 + v10,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
            if ( this->field_276 && dword_524EA0 == 6 )
            {
              v9 = spriteIdx & 0x7F;
              if ( v9 < 9 || v9 >= 36 )
                v7 = 0;
              else
                v7 = 36;
              rasterize(
                this->boatShadowIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                dword_524D2C + y + 31,
                v7 + v9,
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
            if ( dword_524EA0 == 6 && !(*(_BYTE *)(dword_524D00 + 8) & 4) )
              rasterizeMirrored(
                this->frothIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10 + 32,
                dword_524D2C + y + 31,
                spriteIdx & 0x7F,
                1,
                0,
                0,
                480,
                480,
                0);
            rasterizeMirrored(
              (Icon *)this->heroIcons[dword_524EA0],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10 + 32,
              dword_524D2C + y + 31,
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
                rasterizeMirrored(
                  (Icon *)this->flagIcons2[dword_524E74],
                  HeroWindowManager::instance->screenBuffer,
                  dword_524D10 + 32,
                  dword_524D2C + y + 31,
                  spriteIdx & 0x7F,
                  1,
                  0,
                  0,
                  480,
                  480,
                  0);
              else
                rasterizeMirrored(
                  (Icon *)this->flagIcons1[dword_524E74],
                  HeroWindowManager::instance->screenBuffer,
                  dword_524D10 + 32,
                  y + 31,
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
        else
        {
          if ( a5 & 0x80 )
          {
            if ( this->field_276 && dword_524EA0 != 6 && a5 & 0x80 )
              rasterize(
                this->shadowIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                y + 31,
                spriteIdx,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            if ( this->field_276 && dword_524EA0 == 6 )
              rasterize(
                this->boatShadowIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                dword_524D2C + y + 31,
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
            if ( dword_524EA0 == 6 && !(*(_BYTE *)(dword_524D00 + 8) & 4) )
              rasterize(
                this->frothIcon,
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                dword_524D2C + y + 31,
                spriteIdx,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            rasterize(
              (Icon *)this->heroIcons[dword_524EA0],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              dword_524D2C + y + 31,
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
                rasterize(
                  (Icon *)this->flagIcons2[dword_524E74],
                  HeroWindowManager::instance->screenBuffer,
                  dword_524D10,
                  dword_524D2C + y + 31,
                  spriteIdx & 0x7F,
                  1,
                  0,
                  0,
                  0x1E0u,
                  480,
                  0);
              else
                rasterize(
                  (Icon *)this->flagIcons1[dword_524E74],
                  HeroWindowManager::instance->screenBuffer,
                  dword_524D10,
                  y + 31,
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
      }
      if ( this->field_272
        && *(_BYTE *)(dword_524D00 + 8) & 0x40
        && (!*(_DWORD *)&this->field_292[16] || a5 & 0x80)
        && this->viewX + 7 == (_DWORD)a2
        && this->viewY + 7 == HIDWORD(a2)
        && !(a5 & 0x80) )
      {
        sub_4C01E0((int)this);
        sub_4BFBE0((int)this);
        *(_DWORD *)&this->field_292[16] = 1;
      }
    }
    if ( a5 & 4 || a5 & 0x40 )
    {
      if ( a5 & 4 && *(_BYTE *)(dword_524D00 + 3) != 255 )
      {
        if ( (*(_WORD *)(dword_524D00 + 4) >> 2) & 1
          && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F]) )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524D00 + 3),
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524D00 + 2) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
                             *(_BYTE *)(dword_524D00 + 3))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 2) >> 2) & 0x3F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
              *(_BYTE *)(dword_524D00 + 3) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if ( *(_WORD *)(dword_524D00 + 10)
          && *(_BYTE *)(this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10) + 3) != 255 )
          dword_524EAC = this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10);
        else
          dword_524EAC = 0;
        while ( dword_524EAC )
        {
          if ( (*(_BYTE *)(dword_524EAC + 4) >> 2) & 1
            && (!dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F]) )
          {
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
              *(_BYTE *)(dword_524EAC + 3),
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( *(_BYTE *)(dword_524EAC + 2) & 1 )
            {
              dword_524CE4 = getNthHeader(
                               (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                               *(_BYTE *)(dword_524EAC + 3))->someSortOfLength & 0x1F;
              rasterize(
                (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 2) >> 1) & 0x7F],
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                y,
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
            && *(_BYTE *)(this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 3) != 255 )
            dword_524EAC = this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
          else
            dword_524EAC = 0;
        }
      }
      if ( *(_BYTE *)(dword_524D00 + 7) != 255
        && (a5 & 4 && !((*(_BYTE *)(dword_524D00 + 6) >> 1) & 1) || a5 & 0x40 && (*(_BYTE *)(dword_524D00 + 6) >> 1) & 1) )
      {
        if ( !dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524D00 + 6) >> 2) & 0x3F] )
        {
          rasterize(
            (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 6) >> 2) & 0x3F],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10,
            y,
            *(_BYTE *)(dword_524D00 + 7),
            ((*(_BYTE *)(dword_524D00 + 6) >> 2) & 0x3F) == 14,
            0,
            0,
            0x1E0u,
            480,
            0);
          if ( *(_BYTE *)(dword_524D00 + 6) & 1 )
          {
            dword_524CE4 = getNthHeader(
                             (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 6) >> 2) & 0x3F],
                             *(_BYTE *)(dword_524D00 + 7))->someSortOfLength & 0x1F;
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524D00 + 6) >> 2) & 0x3F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
              *(_BYTE *)(dword_524D00 + 7) + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      if ( *(_WORD *)(dword_524D00 + 10)
        && *(_BYTE *)(this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10) + 6) != 255 )
        dword_524EAC = this->field_AE[1] - *(_WORD *)(dword_524D00 + 10) + 8 * *(_WORD *)(dword_524D00 + 10);
      else
        dword_524EAC = 0;
      while ( dword_524EAC )
      {
        if ( a5 & 4 && !((*(_BYTE *)(dword_524EAC + 5) >> 1) & 1)
          || a5 & 0x40 && (*(_BYTE *)(dword_524EAC + 5) >> 1) & 1 )
        {
          if ( !dword_4F5460 || byte_4F0B50[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F] )
          {
            rasterize(
              (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
              HeroWindowManager::instance->screenBuffer,
              dword_524D10,
              y,
              *(_BYTE *)(dword_524EAC + 6),
              ((*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F) == 14,
              0,
              0,
              0x1E0u,
              480,
              0);
            if ( *(_BYTE *)(dword_524EAC + 5) & 1 )
            {
              dword_524CE4 = getNthHeader(
                               (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
                               *(_BYTE *)(dword_524EAC + 6))->someSortOfLength & 0x1F;
              rasterize(
                (Icon *)this->field_CE[(*(_BYTE *)(dword_524EAC + 5) >> 2) & 0x3F],
                HeroWindowManager::instance->screenBuffer,
                dword_524D10,
                y,
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
          && *(_BYTE *)(this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC + 6) != 255 )
          dword_524EAC = this->field_AE[1] - *(_WORD *)dword_524EAC + 8 * *(_WORD *)dword_524EAC;
        else
          dword_524EAC = 0;
      }
    }
  }
  else
  {
    if ( dword_524CF8 )
    {
      if ( dword_524CD4 )
        rasterizeMirrored(
          this->clopIcon,
          HeroWindowManager::instance->screenBuffer,
          dword_524D10 + 31,
          y,
          dword_524D24 - 1,
          0,
          0,
          0,
          0,
          0,
          0);
      else
        rasterize(
          this->clopIcon,
          HeroWindowManager::instance->screenBuffer,
          dword_524D10,
          y,
          dword_524D24 - 1,
          0,
          0,
          0,
          0,
          0,
          0);
    }
    else
    {
      if ( this->field_A2 && *(_WORD *)(2 * a2 + 2 * mapWidth * HIDWORD(a2) + this->field_9E) )
      {
        if ( (*(_WORD *)(2 * a2 + 2 * mapWidth * HIDWORD(a2) + this->field_9E) >> 8) & 1 )
          rasterizeWithSubstitution(
            (Icon *)this->field_CE[17],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10 - 12,
            y + 2,
            (unsigned __int8)(*(_WORD *)(2 * a2 + 2 * mapWidth * HIDWORD(a2) + this->field_9E) - 1),
            1,
            0,
            0,
            0x1E0u,
            480,
            0,
            bloodlustPaletteTransform,
            1);
        else
          rasterize(
            (Icon *)this->field_CE[17],
            HeroWindowManager::instance->screenBuffer,
            dword_524D10 - 12,
            y + 2,
            (unsigned __int8)(*(_WORD *)(2 * a2 + 2 * mapWidth * HIDWORD(a2) + this->field_9E) - 1),
            1,
            0,
            0,
            0x1E0u,
            480,
            0);
      }
    }
  }
}
