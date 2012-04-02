void __cdecl sub_4AB580()
{
  int v0; // [sp+3Ch] [bp-24h]@8
  int v1; // [sp+44h] [bp-1Ch]@8
  float v2; // [sp+48h] [bp-18h]@1
  int v3; // [sp+4Ch] [bp-14h]@9
  signed int v4; // [sp+4Ch] [bp-14h]@17
  int row; // [sp+50h] [bp-10h]@5
  int col; // [sp+54h] [bp-Ch]@3
  signed int v7; // [sp+58h] [bp-8h]@1
  float v8; // [sp+5Ch] [bp-4h]@1

  dword_532C50 = 0;
  dword_5305C0 = 1065353216;
  v2 = 0.0;
  v8 = 0.0;
  v7 = getArmyStrength(&dword_51D5BC->army, dword_51D5BC, 0, 0, 0, 0);
  if ( v7 < 100 )
    v7 = 100;
  Pathfinder::doSomething2(
    pathfinder,
    dword_51D5BC->x,
    dword_51D5BC->y,
    dword_51D5BC->_4[11],
    4 * *(_DWORD *)&dword_51D5BC->_4[16],
    *(_DWORD *)&dword_51D5BC->flags1 & 0x80,
    0,
    *(_DWORD *)&dword_51D5BC->_4[20],
    dword_51D5BC->secondarySkillLevel[0],
    -1i64,
    0,
    0);
  for ( col = 0; col < mapWidth; ++col )
  {
    for ( row = 0; row < mapHeight; ++row )
    {
      if ( *(&pathfinder->field_2414[col].field_4 + 9 * mapWidth * row) & 1 )
      {
        v1 = usedToCheckForBoatByCastle(advManager, col, row);
        v0 = *(_BYTE *)(v1 + 9);
        if ( v0 == 163 )
        {
          v3 = getArmyStrength(
                 &gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v1 + 4) >> 8) >> -5)].garrison,
                 0,
                 0,
                 0,
                 0,
                 0);
          if ( gameObject->_7[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v1 + 4) >> 8) >> -5)] == dword_51D5BC->probablyOwnerIdx )
          {
            if ( 2 * v7 < v3 )
              v2 = ((double)v3 / (double)(2 * v7) - 1.0)
                 * (double)(*(_DWORD *)&dword_51D5BC->_4[16] + 10)
                 / (double)(*(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * mapWidth * row) + 10)
                 + v2;
          }
          else
          {
            if ( v7 >> 1 < v3 )
              v8 = ((double)v3 / (double)(v7 >> 1) - 1.0)
                 * (double)(*(_DWORD *)&dword_51D5BC->_4[16] + 30)
                 / (double)(*(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * mapWidth * row) + 30)
                 + v8;
          }
        }
        else
        {
          if ( v0 == 170
            && gameObject->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v1 + 4) >> 8) >> -5)] != dword_51D5BC->probablyOwnerIdx )
          {
            v4 = getArmyStrength(
                   &gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v1 + 4) >> 8) >> -5)].army,
                   0,
                   0,
                   0,
                   0,
                   0);
            if ( v7 >> 1 < v4 )
              v8 = ((double)v4 / (double)(v7 >> 1) - 1.0)
                 * (double)(*(_DWORD *)&dword_51D5BC->_4[16] + 30)
                 / (double)(*(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * mapWidth * row) + 30)
                 + v8;
          }
        }
      }
    }
  }
  if ( v2 > 1.0 && v8 > 1.0 )
  {
    *(float *)&dword_5305C0 = 3.0 / (v2 + v8 + 2.0);
    dword_532C50 = 1;
  }
}
