{
  signed int result; // eax@3
  int thisa; // [sp+10h] [bp-28h]@1
  int spriteIdxArg; // [sp+14h] [bp-24h]@49
  int v6; // [sp+18h] [bp-20h]@46
  char *v7; // [sp+1Ch] [bp-1Ch]@27
  int v8; // [sp+20h] [bp-18h]@19
  int v9; // [sp+28h] [bp-10h]@4
  int v10; // [sp+2Ch] [bp-Ch]@4

  thisa = (int)this;
  if ( !sub_4385B0(a2, a3) )
  {
    if ( mouseManager->spriteIdx < 32 || mouseManager->spriteIdx >= 40 || !sub_455750() )
      MouseManager::setSpriteIdx(mouseManager, 0);
    return 1;
  }
  if ( a2 > 480 )
  {
    MouseManager::setSpriteIdx(mouseManager, 0);
    return 1;
  }
  v10 = a2 / 32;
  v9 = a3 / 32;
  if ( a2 / 32 < 0 )
    v10 = 0;
  if ( v9 < 0 )
    v9 = 0;
  if ( v10 > 14 )
    v10 = 14;
  if ( v9 > 14 )
    v9 = 14;
  if ( *(_DWORD *)(thisa + 486) == v10 && *(_DWORD *)(thisa + 490) == v9 )
    return 1;
  *(_DWORD *)(thisa + 54) = -1;
  *(_DWORD *)(thisa + 486) = v10;
  *(_DWORD *)(thisa + 490) = v9;
  *(_DWORD *)(thisa + 494) = v10 + *(_DWORD *)(thisa + 470);
  *(_DWORD *)(thisa + 498) = v9 + *(_DWORD *)(thisa + 474);
  if ( *(_QWORD *)(thisa + 494) < 0i64
    || *(_DWORD *)(thisa + 494) > mapWidth - 1
    || *(_DWORD *)(thisa + 498) > mapHeight - 1
    || !(unsigned __int8)(*(&tileExplored[*(_DWORD *)(thisa + 494)] + mapWidth * *(_DWORD *)(thisa + 498)) & byte_532C5C) )
  {
    MouseManager::setSpriteIdx(mouseManager, 0);
    return 1;
  }
  v8 = usedToCheckForBoatByCastle((AdvManager *)thisa, *(_DWORD *)(thisa + 494), *(_DWORD *)(thisa + 498));
  if ( curPlayer->_1[0] == -1 )
  {
    if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 35
      || gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx != curPlayerIdx )
    {
      if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 42
        || gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].probablyOwnerIdx != curPlayerIdx )
      {
        MouseManager::setSpriteIdx(mouseManager, 0);
        result = 1;
      }
      else
      {
        MouseManager::setSpriteIdx(mouseManager, 2);
        *(_DWORD *)(thisa + 54) = 2;
        result = 1;
      }
    }
    else
    {
      MouseManager::setSpriteIdx(mouseManager, 3);
      *(_DWORD *)(thisa + 54) = 3;
      result = 1;
    }
    return result;
  }
  v7 = (char *)&gameObject->heroes[curPlayer->_1[0]];
  if ( v10 == gameObject->heroes[curPlayer->_1[0]].x - *(_DWORD *)(thisa + 470)
    && v9 == gameObject->heroes[curPlayer->_1[0]].y - *(_DWORD *)(thisa + 474) )
  {
    MouseManager::setSpriteIdx(mouseManager, 2);
    *(_DWORD *)(thisa + 54) = 2;
    return 1;
  }
  if ( !(*(_BYTE *)(v8 + 8) & 8) )
  {
    if ( *(_DWORD *)(thisa + 634) != 6
      && !tileToTerrainType[*(_WORD *)v8]
      && *(_BYTE *)(v8 + 9) != 170
      && *(_BYTE *)(v8 + 9) != 171
      && *(_BYTE *)(v8 + 9) != 160
      || *(_DWORD *)(thisa + 634) == 6 && tileToTerrainType[*(_WORD *)v8] && *(_BYTE *)(v8 + 9) != 28 )
    {
      pathfinder->field_8 = 0;
      MouseManager::setSpriteIdx(mouseManager, 0);
      return 1;
    }
    sub_455240(thisa, *(_QWORD *)(thisa + 494));
    if ( !(*(&pathfinder->field_2414[mapWidth * *(_DWORD *)(thisa + 498)].field_4 + 9 * *(_DWORD *)(thisa + 494)) & 1) )
    {
      MouseManager::setSpriteIdx(mouseManager, 0);
      return 1;
    }
    if ( (signed int)*(__int16 *)((char *)&pathfinder->field_2414[mapWidth * *(_DWORD *)(thisa + 498)].field_2
                                + 9 * *(_DWORD *)(thisa + 494)) > *(_DWORD *)(v7 + 53) )
    {
      v6 = (*(__int16 *)((char *)&pathfinder->field_2414[mapWidth * *(_DWORD *)(thisa + 498)].field_2
                       + 9 * *(_DWORD *)(thisa + 494))
          - *(_DWORD *)(v7 + 53))
         / *(_DWORD *)(v7 + 49)
         + 1;
      if ( v6 > 3 )
        v6 = 3;
    }
    else
    {
      v6 = 0;
    }
    spriteIdxArg = 6 * v6;
    switch ( *(_BYTE *)(v8 + 9) & 0x7F )
    {
      case 0x2B:
        if ( *(_DWORD *)(thisa + 634) == 6 )
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg);
        }
        else
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 6);
          *(_DWORD *)(thisa + 54) = 1;
        }
        return 1;
      case 0x1C:
        if ( *(_DWORD *)(thisa + 634) == 6 )
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 7);
        }
        else
        {
          if ( *(&tileExplored[*(_DWORD *)(thisa + 494)] + mapWidth * *(_DWORD *)(thisa + 498)) & 0x80 )
            MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 5);
          else
            MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 4);
        }
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      case 0x18:
        MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 5);
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      case 0x2A:
        if ( gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].probablyOwnerIdx == curPlayerIdx )
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 8);
          *(_DWORD *)(thisa + 54) = 1;
        }
        else
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 5);
          *(_DWORD *)(thisa + 54) = 1;
        }
        return 1;
      case 0x23:
        if ( !(*(_BYTE *)(v8 + 9) & 0x80)
          || gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx == curPlayerIdx
          || !Castle::hasGarrison(&gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)]) )
          goto LABEL_69;
        MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 5);
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      default:
LABEL_69:
        if ( !(*(&tileExplored[*(_DWORD *)(thisa + 494)] + mapWidth * *(_DWORD *)(thisa + 498)) & 0x80)
          || *(_DWORD *)(thisa + 634) == 6
          || *(_BYTE *)(v8 + 9) & 0x80 && sub_458D40(v8) )
        {
          if ( *(_BYTE *)(v8 + 9) & 0x80 )
          {
            if ( *(_DWORD *)(thisa + 634) == 6 )
            {
              if ( tileToTerrainType[*(_WORD *)v8] )
                MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 6);
              else
                MouseManager::setSpriteIdx(mouseManager, v6 + 28);
            }
            else
            {
              if ( tileToTerrainType[*(_WORD *)v8] )
              {
                MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 9);
              }
              else
              {
                if ( *(_BYTE *)(v8 + 9) != 160 )
                {
                  MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 4);
                  return 1;
                }
                MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 9);
              }
            }
          }
          else
          {
            if ( *(_DWORD *)(thisa + 634) == 6 )
              MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 6);
            else
              MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 4);
          }
        }
        else
        {
          MouseManager::setSpriteIdx(mouseManager, spriteIdxArg + 5);
        }
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
    }
  }
  if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 35
    || gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx != curPlayerIdx )
  {
    pathfinder->field_8 = 0;
    MouseManager::setSpriteIdx(mouseManager, 0);
    result = 1;
  }
  else
  {
    MouseManager::setSpriteIdx(mouseManager, 3);
    *(_DWORD *)(thisa + 54) = 5;
    result = 1;
  }
  return result;
}
