void __thiscall AdvManager::summonBoat(AdvManager *this)
{
  int v1; // ebx@28
  char *v2; // eax@32
  int height; // [sp+10h] [bp-3Ch]@40
  int y; // [sp+14h] [bp-38h]@38
  int x; // [sp+18h] [bp-34h]@36
  int width; // [sp+1Ch] [bp-30h]@40
  int v8; // [sp+20h] [bp-2Ch]@32
  signed int j; // [sp+2Ch] [bp-20h]@16
  signed int i; // [sp+30h] [bp-1Ch]@2
  int row; // [sp+34h] [bp-18h]@5
  signed int v12; // [sp+38h] [bp-14h]@1
  int col; // [sp+3Ch] [bp-10h]@5
  char *v14; // [sp+40h] [bp-Ch]@1
  MapTile *v15; // [sp+44h] [bp-8h]@1
  signed int v16; // [sp+48h] [bp-4h]@1

  v14 = (char *)&gameObject->heroes[curPlayer->_1[0]];
  v16 = 0;
  v12 = 0;
  v15 = AdvManager::getTile(this, this->viewX + 7, this->viewY + 7);
  if ( tileToTerrainType[v15->tileType] )
  {
    for ( i = 0; i < 8; ++i )
    {
      col = this->viewX + byte_4F1DC0[4 * i] + 7;
      row = this->viewY + byte_4F1DC1[4 * i] + 7;
      if ( col >= 0 )
      {
        if ( mapWidth > col )
        {
          if ( row >= 0 )
          {
            if ( row < mapHeight )
            {
              v15 = AdvManager::getTile(this, col, row);
              if ( HIBYTE(v15->field_2) == 255 )
              {
                if ( !v15->objType && !tileToTerrainType[v15->tileType] )
                {
                  v16 = 1;
                  break;
                }
              }
            }
          }
        }
      }
    }
    if ( v16 )
    {
      for ( j = 0; j < 48; ++j )
      {
        if ( gameObject->field_6236[j + 231] != -1
          && gameObject->probablyArtifactGeneratedRandomly[8 * j + 109] == (curPlayer->_1[0] | 0x80) )
        {
          v12 = 1;
          break;
        }
      }
      if ( !v12 )
      {
        for ( j = 0; j < 48; ++j )
        {
          if ( gameObject->field_6236[j + 231] != -1 )
          {
            if ( gameObject->probablyArtifactGeneratedRandomly[8 * j + 109] & 0x80 )
            {
              if ( gameObject->probablyArtifactGeneratedRandomly[8 * j + 110] == curPlayerIdx )
              {
                v1 = abs(gameObject->probablyArtifactGeneratedRandomly[8 * j + 105] - *(_DWORD *)(v14 + 29));
                if ( abs(gameObject->probablyArtifactGeneratedRandomly[8 * j + 104] - *(_DWORD *)(v14 + 25)) + v1 > 2 )
                {
                  v12 = 1;
                  break;
                }
              }
            }
          }
        }
      }
      if ( v12 )
      {
        v2 = (char *)gameObject + 8 * j;
        v8 = (int)(v2 + 24989);
        AdvManager::getTile(this, v2[24990], v2[24991]);
        sub_42CC90(*(_BYTE *)(v8 + 1), *(_BYTE *)(v8 + 2), *(_BYTE *)(v8 + 4), *(_BYTE *)(v8 + 5), 0, 5);
        if ( *(_BYTE *)(v8 + 1) >= this->viewX
          && *(_BYTE *)(v8 + 1) < this->viewX + 15
          && *(_BYTE *)(v8 + 2) >= this->viewY
          && *(_BYTE *)(v8 + 2) < this->viewY + 15 )
        {
          x = 32 * (*(_BYTE *)(v8 + 1) - this->viewX) - 48;
          if ( x < 16 )
            x = 16;
          y = 32 * (*(_BYTE *)(v8 + 2) - this->viewY) - 48;
          if ( y < 16 )
            y = 16;
          width = 112;
          height = 80;
          if ( x + 112 >= 464 )
            width = 464 - x;
          if ( y + 80 >= 464 )
            height = 464 - y;
          HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, x, y, width, height);
          sub_447C20(this, this->viewX, this->viewY, 0, 1);
          sub_4C7E00(HeroWindowManager::instance, x, y, width, height, -1, 0, 0);
        }
        *(_BYTE *)(v8 + 1) = LOBYTE(this->viewX) + byte_4F1DC0[4 * i] + 7;
        *(_BYTE *)(v8 + 2) = LOBYTE(this->viewY) + byte_4F1DC1[4 * i] + 7;
        *(_BYTE *)(v8 + 4) = v15->objType;
        *(_BYTE *)(v8 + 5) = v15->flags >> 3;
        v15->objType = -85;
        v15->flags = 8 * j | v15->flags & 7;
        HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 154, 152, 150, 136);
        sub_447C20(this, this->viewX, this->viewY, 0, 1);
        sub_4C7E00(HeroWindowManager::instance, 154, 152, 150, 136, -1, 0, 0);
      }
    }
  }
  sub_447A00(this, 0, 0);
  sub_4456D0(0, 0);
  if ( !v12 )
    display_message_window("Summon Boat failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
}
