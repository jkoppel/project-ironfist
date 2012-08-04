{
  signed __int64 v0; // qax@1
  int v2; // [sp+18h] [bp-24h]@10
  mapCell *v3; // [sp+24h] [bp-18h]@10
  int v4; // [sp+28h] [bp-14h]@13
  int v5; // [sp+28h] [bp-14h]@18
  signed int v6; // [sp+2Ch] [bp-10h]@1
  int row; // [sp+30h] [bp-Ch]@8
  int col; // [sp+34h] [bp-8h]@6
  signed int v9; // [sp+38h] [bp-4h]@1

  v6 = -1;
  gbBerserk = 0;
  fBerserkFactor = 1065353216;
  v9 = philAI::FightValueOfStack(&gpCurAIHero->army, gpCurAIHero, 1, 0, 0, 0);
  LODWORD(v0) = gpCurPlayer;
  if ( !gpCurPlayer->personality )
  {
    v0 = (signed __int64)((double)v9 * 1.15);
    v9 = (signed __int64)((double)v9 * 1.15);
  }
  if ( v9 < 100 )
    v9 = 100;
  if ( v9 >= 30000 )
  {
    for ( col = 0; ; ++col )
    {
      LODWORD(v0) = MAP_WIDTH;
      if ( col >= MAP_WIDTH )
        break;
      for ( row = 0; row < MAP_HEIGHT; ++row )
      {
        v3 = advManager::GetCell(gpAdvManager, col, row);
        v2 = v3->objType;
        if ( v2 == 163 )
        {
          if ( gpGame->_7[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)] != gpCurAIHero->probablyOwnerIdx
            && gpGame->_7[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)] != -1 )
          {
            v4 = philAI::FightValueOfStack(
                   &gpGame->castles[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].garrison,
                   0,
                   1,
                   1,
                   (unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5),
                   0);
            LODWORD(v0) = v9;
            if ( v4 > v9 )
              return v0;
            if ( v6 < v4 )
              v6 = v4;
          }
        }
        else if ( v2 == 170
  && gpGame->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)] != gpCurAIHero->probablyOwnerIdx )
        {
          LODWORD(v0) = philAI::FightValueOfStack(
                          &gpGame->heroes[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].army,
                          0,
                          1,
                          gpGame->heroes[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].occupiedObjType == 163,
                          gpGame->heroes[(unsigned __int8)((unsigned __int8)(v3->flags >> 8) >> -5)].occupiedObjVal,
                          0);
          v5 = v0;
          LODWORD(v0) = 2 * v0;
          if ( (signed int)v0 > v9 )
            return v0;
          if ( 2 * v5 > v6 )
            v6 = 2 * v5;
        }
      }
    }
    if ( v6 > 0 )
    {
      LODWORD(v0) = v9;
      *(float *)&fBerserkFactor = (double)v6 * 0.75 / (double)v9;
      gbBerserk = 1;
    }
  }
  return v0;
}