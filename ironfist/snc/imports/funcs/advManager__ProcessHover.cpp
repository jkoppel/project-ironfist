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
  if ( !InMapArea(a2, a3) )
  {
    if ( gpMouseManager->spriteIdx < 32 || gpMouseManager->spriteIdx >= 40 || !advManager::MouseInScrollZone() )
      mouseManager::SetPointer(gpMouseManager, 0);
    return 1;
  }
  if ( a2 > 480 )
  {
    mouseManager::SetPointer(gpMouseManager, 0);
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
    || *(_DWORD *)(thisa + 494) > MAP_WIDTH - 1
    || *(_DWORD *)(thisa + 498) > MAP_HEIGHT - 1
    || !(unsigned __int8)(*(&mapExtra[*(_DWORD *)(thisa + 494)] + MAP_WIDTH * *(_DWORD *)(thisa + 498)) & giCurPlayerBit) )
  {
    mouseManager::SetPointer(gpMouseManager, 0);
    return 1;
  }
  v8 = (int)advManager::GetCell((advManager *)thisa, *(_DWORD *)(thisa + 494), *(_DWORD *)(thisa + 498));
  if ( gpCurPlayer->curHeroIdx == -1 )
  {
    if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 35
      || gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx != giCurPlayer )
    {
      if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 42
        || gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].probablyOwnerIdx != giCurPlayer )
      {
        mouseManager::SetPointer(gpMouseManager, 0);
        result = 1;
      }
      else
      {
        mouseManager::SetPointer(gpMouseManager, 2);
        *(_DWORD *)(thisa + 54) = 2;
        result = 1;
      }
    }
    else
    {
      mouseManager::SetPointer(gpMouseManager, 3);
      *(_DWORD *)(thisa + 54) = 3;
      result = 1;
    }
    return result;
  }
  v7 = (char *)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  if ( v10 == gpGame->heroes[gpCurPlayer->curHeroIdx].x - *(_DWORD *)(thisa + 470)
    && v9 == gpGame->heroes[gpCurPlayer->curHeroIdx].y - *(_DWORD *)(thisa + 474) )
  {
    mouseManager::SetPointer(gpMouseManager, 2);
    *(_DWORD *)(thisa + 54) = 2;
    return 1;
  }
  if ( !(*(_BYTE *)(v8 + 8) & 8) )
  {
    if ( *(_DWORD *)(thisa + 634) != 6
      && !giGroundToTerrain[*(_WORD *)v8]
      && *(_BYTE *)(v8 + 9) != 170
      && *(_BYTE *)(v8 + 9) != 171
      && *(_BYTE *)(v8 + 9) != 160
      || *(_DWORD *)(thisa + 634) == 6 && giGroundToTerrain[*(_WORD *)v8] && *(_BYTE *)(v8 + 9) != 28 )
    {
      gpSearchArray->field_8 = 0;
      mouseManager::SetPointer(gpMouseManager, 0);
      return 1;
    }
    advManager::SeedTo(thisa, *(_QWORD *)(thisa + 494));
    if ( !(*(&gpSearchArray->field_2414[MAP_WIDTH * *(_DWORD *)(thisa + 498)].field_4 + 9 * *(_DWORD *)(thisa + 494)) & 1) )
    {
      mouseManager::SetPointer(gpMouseManager, 0);
      return 1;
    }
    if ( (signed int)*(__int16 *)((char *)&gpSearchArray->field_2414[MAP_WIDTH * *(_DWORD *)(thisa + 498)].field_2
                                + 9 * *(_DWORD *)(thisa + 494)) > *(_DWORD *)(v7 + 53) )
    {
      v6 = (*(__int16 *)((char *)&gpSearchArray->field_2414[MAP_WIDTH * *(_DWORD *)(thisa + 498)].field_2
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
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg);
        }
        else
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 6);
          *(_DWORD *)(thisa + 54) = 1;
        }
        return 1;
      case 0x1C:
        if ( *(_DWORD *)(thisa + 634) == 6 )
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 7);
        }
        else if ( *(&mapExtra[*(_DWORD *)(thisa + 494)] + MAP_WIDTH * *(_DWORD *)(thisa + 498)) & 0x80 )
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 5);
        }
        else
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 4);
        }
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      case 0x18:
        mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 5);
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      case 0x2A:
        if ( gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].probablyOwnerIdx == giCurPlayer )
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 8);
          *(_DWORD *)(thisa + 54) = 1;
        }
        else
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 5);
          *(_DWORD *)(thisa + 54) = 1;
        }
        return 1;
      case 0x23:
        if ( !(*(_BYTE *)(v8 + 9) & 0x80)
          || gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx == giCurPlayer
          || !town::HasGarrison(&gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)]) )
          goto LABEL_69;
        mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 5);
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
      default:
LABEL_69:
        if ( !(*(&mapExtra[*(_DWORD *)(thisa + 494)] + MAP_WIDTH * *(_DWORD *)(thisa + 498)) & 0x80)
          || *(_DWORD *)(thisa + 634) == 6
          || *(_BYTE *)(v8 + 9) & 0x80 && StopOnTrigger(v8) )
        {
          if ( *(_BYTE *)(v8 + 9) & 0x80 )
          {
            if ( *(_DWORD *)(thisa + 634) == 6 )
            {
              if ( giGroundToTerrain[*(_WORD *)v8] )
                mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 6);
              else
                mouseManager::SetPointer(gpMouseManager, v6 + 28);
            }
            else if ( giGroundToTerrain[*(_WORD *)v8] )
            {
              mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 9);
            }
            else
            {
              if ( *(_BYTE *)(v8 + 9) != 160 )
              {
                mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 4);
                return 1;
              }
              mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 9);
            }
          }
          else if ( *(_DWORD *)(thisa + 634) == 6 )
          {
            mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 6);
          }
          else
          {
            mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 4);
          }
        }
        else
        {
          mouseManager::SetPointer(gpMouseManager, spriteIdxArg + 5);
        }
        *(_DWORD *)(thisa + 54) = 1;
        return 1;
    }
  }
  if ( (*(_BYTE *)(v8 + 9) & 0x7F) != 35
    || gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v8 + 4) >> 8) >> -5)].ownerIdx != giCurPlayer )
  {
    gpSearchArray->field_8 = 0;
    mouseManager::SetPointer(gpMouseManager, 0);
    result = 1;
  }
  else
  {
    mouseManager::SetPointer(gpMouseManager, 3);
    *(_DWORD *)(thisa + 54) = 5;
    result = 1;
  }
  return result;
}