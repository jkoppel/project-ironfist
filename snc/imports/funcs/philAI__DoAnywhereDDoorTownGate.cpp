{
  signed int result; // eax@2
  int v3; // ST44_4@24
  int v4; // [sp+Ch] [bp-38h]@1
  mapCell *v5; // [sp+10h] [bp-34h]@19
  int v6; // [sp+14h] [bp-30h]@4
  mapCell *v7; // [sp+18h] [bp-2Ch]@42
  int v8; // [sp+1Ch] [bp-28h]@24
  int row; // [sp+20h] [bp-24h]@10
  signed int i; // [sp+24h] [bp-20h]@25
  int col; // [sp+28h] [bp-1Ch]@8
  int v12; // [sp+2Ch] [bp-18h]@29
  int v13; // [sp+30h] [bp-14h]@0
  signed int v14; // [sp+34h] [bp-10h]@3
  int v15; // [sp+38h] [bp-Ch]@29
  char v16; // [sp+3Ch] [bp-8h]@41
  char v17; // [sp+40h] [bp-4h]@41

  v4 = (int)this;
  if ( gpCurAIHero->flags1 & 0x80 )
  {
    result = 0;
  }
  else
  {
    v14 = -1;
    if ( a1 <= 25 )
      v6 = Random(0, 125) - 50;
    else
      v6 = a1 + 1000;
    if ( !hero::HasSpell(gpCurAIHero, SPELL_DIMENSION_DOOR) || gpCurAIHero->spellpoints < 30 )
      goto LABEL_55;
    for ( col = 0; col < MAP_WIDTH; ++col )
    {
      for ( row = 0; row < MAP_HEIGHT; ++row )
      {
        if ( !(*(&gpSearchArray->field_2414[col].field_4 + 9 * row * MAP_WIDTH) & 1)
          && abs(col - gpCurAIHero->x) <= 7
          && abs(row - gpCurAIHero->y) <= 7
          && (gpCurAIHero->x != col || gpCurAIHero->y != row) )
        {
          v5 = advManager::GetCell(gpAdvManager, col, row);
          if ( giGroundToTerrain[v5->tileType] && (v5->objType & 0x80 || a1 < 25 && Random(0, 10) < 2) )
          {
            v3 = philAI::RVOfPosition(v4, col, row, 0, -1, -1, 0, -1, -1, 2);
            v8 = Random(0, 30) + v3;
            if ( v6 < v8 )
            {
              for ( i = 0; i < 3; ++i )
              {
                if ( i )
                {
                  if ( i == 1 )
                  {
                    v15 = col;
                    v12 = row + 1;
                  }
                  else
                  {
                    v15 = col + 1;
                    v12 = row;
                  }
                }
                else
                {
                  v15 = col - 1;
                  v12 = row;
                }
                if ( !(*(&gpSearchArray->field_2414[v15].field_4 + 9 * v12 * MAP_WIDTH) & 1)
                  && (gpCurAIHero->x != v15 || gpCurAIHero->y != v12) )
                {
                  if ( v15 >= 0 )
                  {
                    if ( MAP_WIDTH - 1 >= v15 )
                    {
                      if ( v12 >= 0 )
                      {
                        if ( MAP_HEIGHT - 1 >= v12 )
                        {
                          if ( !advManager::FindAdjacentMonster(
                                  gpAdvManager,
                                  __PAIR__(v12, v15),
                                  (int)&v17,
                                  (int)&v16,
                                  -1,
                                  -1) )
                          {
                            v7 = advManager::GetCell(gpAdvManager, v15, v12);
                            if ( giGroundToTerrain[v7->tileType] )
                            {
                              if ( !(v7->field_8 & 8)
                                && !(v7->objType & 0x80)
                                && (HIBYTE(v7->field_2) == 255 || v7->field_8 & 0x80) )
                              {
                                v14 = v15;
                                v13 = v12;
                                v6 = v8;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( v14 != -1 )
    {
      philAI::DimensionDoorTo(__PAIR__(v13, v14));
      result = 1;
    }
    else
    {
LABEL_55:
      result = 0;
    }
  }
  return result;
}