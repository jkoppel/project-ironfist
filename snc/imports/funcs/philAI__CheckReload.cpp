{
  int v0; // [sp+3Ch] [bp-24h]@8
  mapCell *v1; // [sp+44h] [bp-1Ch]@8
  float v2; // [sp+48h] [bp-18h]@1
  int v3; // [sp+4Ch] [bp-14h]@9
  signed int v4; // [sp+4Ch] [bp-14h]@17
  int row; // [sp+50h] [bp-10h]@5
  int col; // [sp+54h] [bp-Ch]@3
  signed int v7; // [sp+58h] [bp-8h]@1
  float v8; // [sp+5Ch] [bp-4h]@1

  gbTroopReload = 0;
  fReduceFactor = 1065353216;
  v2 = 0.0;
  v8 = 0.0;
  v7 = philAI::FightValueOfStack(&gpCurAIHero->army, gpCurAIHero, 0, 0, 0, 0);
  if ( v7 < 100 )
    v7 = 100;
  searchArray::SeedPosition(
    gpSearchArray,
    gpCurAIHero->x,
    gpCurAIHero->y,
    HIBYTE(gpCurAIHero->field_2B),
    4 * *(_DWORD *)&gpCurAIHero->field_31,
    *(_DWORD *)&gpCurAIHero->flags1 & 0x80,
    0,
    *(_DWORD *)&gpCurAIHero->field_35,
    gpCurAIHero->secondarySkillLevel[0],
    -1i64,
    0,
    0);
  for ( col = 0; col < MAP_WIDTH; ++col )
  {
    for ( row = 0; row < MAP_HEIGHT; ++row )
    {
      if ( *(&gpSearchArray->field_2414[col].field_4 + 9 * MAP_WIDTH * row) & 1 )
      {
        v1 = advManager::GetCell(gpAdvManager, col, row);
        v0 = v1->objType;
        if ( v0 == 163 )
        {
          v3 = philAI::FightValueOfStack(
                 &gpGame->castles[(unsigned __int8)((unsigned __int8)(v1->flags >> 8) >> -5)].garrison,
                 0,
                 0,
                 0,
                 0,
                 0);
          if ( gpGame->_7[(unsigned __int8)((unsigned __int8)(v1->flags >> 8) >> -5)] == gpCurAIHero->probablyOwnerIdx )
          {
            if ( 2 * v7 < v3 )
              v2 = ((double)v3 / (double)(2 * v7) - 1.0)
                 * (double)(*(_DWORD *)&gpCurAIHero->field_31 + 10)
                 / (double)(*(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * MAP_WIDTH * row) + 10)
                 + v2;
          }
          else if ( v7 >> 1 < v3 )
          {
            v8 = ((double)v3 / (double)(v7 >> 1) - 1.0)
               * (double)(*(_DWORD *)&gpCurAIHero->field_31 + 30)
               / (double)(*(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * MAP_WIDTH * row) + 30)
               + v8;
          }
        }
        else if ( v0 == 170
  && gpGame->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(v1->flags >> 8) >> -5)] != gpCurAIHero->probablyOwnerIdx )
        {
          v4 = philAI::FightValueOfStack(
                 &gpGame->heroes[(unsigned __int8)((unsigned __int8)(v1->flags >> 8) >> -5)].army,
                 0,
                 0,
                 0,
                 0,
                 0);
          if ( v7 >> 1 < v4 )
            v8 = ((double)v4 / (double)(v7 >> 1) - 1.0)
               * (double)(*(_DWORD *)&gpCurAIHero->field_31 + 30)
               / (double)(*(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * MAP_WIDTH * row) + 30)
               + v8;
        }
      }
    }
  }
  if ( v2 > 1.0 && v8 > 1.0 )
  {
    *(float *)&fReduceFactor = 3.0 / (v2 + v8 + 2.0);
    gbTroopReload = 1;
  }
}