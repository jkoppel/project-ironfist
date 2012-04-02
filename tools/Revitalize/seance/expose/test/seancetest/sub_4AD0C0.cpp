Player *__stdcall sub_4AD0C0(int a1)
{
  signed __int64 v1; // qax@1
  int v2; // ebx@13
  __int64 v3; // ST08_8@54
  int v4; // ebx@73
  int v5; // eax@73
  char *v6; // ST70_4@112
  char *v7; // ST74_4@112
  int v8; // ebx@112
  Player *result; // eax@121
  signed int v10; // [sp+40h] [bp-78h]@51
  char *v11; // [sp+44h] [bp-74h]@52
  int v12; // [sp+48h] [bp-70h]@49
  char v13; // [sp+4Ch] [bp-6Ch]@54
  char v14; // [sp+50h] [bp-68h]@54
  int v15; // [sp+54h] [bp-64h]@65
  char v16; // [sp+58h] [bp-60h]@54
  float v17; // [sp+5Ch] [bp-5Ch]@89
  int v18; // [sp+60h] [bp-58h]@65
  char v19; // [sp+64h] [bp-54h]@54
  int i; // [sp+68h] [bp-50h]@4
  int l; // [sp+6Ch] [bp-4Ch]@35
  int v22; // [sp+70h] [bp-48h]@73
  int v23; // [sp+74h] [bp-44h]@23
  int v24; // [sp+78h] [bp-40h]@107
  int k; // [sp+7Ch] [bp-3Ch]@17
  int j; // [sp+80h] [bp-38h]@6
  int m; // [sp+84h] [bp-34h]@44
  Hero *hero; // [sp+88h] [bp-30h]@9
  int col; // [sp+8Ch] [bp-2Ch]@42
  float v30; // [sp+90h] [bp-28h]@54
  int v31; // [sp+94h] [bp-24h]@3
  float v32; // [sp+98h] [bp-20h]@3
  int v33; // [sp+9Ch] [bp-1Ch]@107
  Castle *v34; // [sp+A0h] [bp-18h]@6
  int v35; // [sp+A4h] [bp-14h]@42
  int v36; // [sp+A8h] [bp-10h]@95
  int v37; // [sp+ACh] [bp-Ch]@17
  Player *v38; // [sp+B0h] [bp-8h]@63
  char v39; // [sp+B4h] [bp-4h]@54

  dword_532C54 = gameObject->day + 7 * (gameObject->week - 1) + 28 * (gameObject->month - 1);
  sub_4B12F0(a1);
  sub_4B27A0(a1);
  LODWORD(qword_50EAA8) = 0;
  dword_50EA90 = 0;
  v1 = (signed __int64)sub_4B28F0(a1);
  *(_DWORD *)&curPlayer->_4[88] = v1;
  *(_DWORD *)&curPlayer->_4[92] = *(_DWORD *)&curPlayer->_4[88] * (signed int)gameObject->field_B52 / 48;
  *(_DWORD *)&curPlayer->_4[96] = sub_4B1180(a1);
  dword_532C58 = 0;
  if ( dword_532C54 - byte_5306E8[a1] > 8 )
  {
    byte_532CD8[a1] = -1;
    byte_5306C8[a1] = -1;
  }
  v31 = 0;
  v32 = 0.0;
  if ( dword_532C54 <= 7 )
  {
    dword_51D58C = 0;
    for ( i = 0; curPlayer->numCastles > i; ++i )
    {
      v34 = &gameObject->castles[curPlayer->castlesOwned[i]];
      for ( j = 0; j < 54; ++j )
      {
        hero = &gameObject->heroes[j];
        if ( gameObject->heroes[j].probablyOwnerIdx >= 0 )
        {
          if ( hero->probablyOwnerIdx <= 5 )
          {
            if ( hero->probablyOwnerIdx != curPlayerIdx )
            {
              v2 = abs(hero->x - v34->field_4);
              if ( abs(hero->y - v34->field_5) + v2 < 16 )
              {
                dword_51D58C = 1050253722;
                goto LABEL_17;
              }
            }
          }
        }
      }
    }
  }
LABEL_17:
  v37 = 0;
  for ( k = 0; curPlayer->numHeroes > k; ++k )
  {
    hero = &gameObject->heroes[curPlayer->heroesOwned[k]];
    v32 = (double)getArmyStrength(&hero->army, hero, 0, 0, 0, 0);
    v37 = (signed __int64)((double)v37 + v32);
    *(float *)&hero->field_E7[1] = v32 * 0.00004 + 0.4;
  }
  for ( k = 0; curPlayer->numCastles > k; ++k )
  {
    v34 = &gameObject->castles[curPlayer->castlesOwned[k]];
    v32 = (double)getArmyStrength(&v34->garrison, 0, 0, 0, 0, 0);
    v37 = (signed __int64)((double)v37 + v32);
  }
  *(float *)&curPlayer->_4[100] = (double)(curPlayer->resources[6] + *(_DWORD *)&curPlayer->_4[84])
                                / (double)(v37 + 1000)
                                + *(float *)&curPlayer->_4[24];
  v23 = 0;
  for ( k = 4; k < 37; ++k )
    v23 += dword_4F2050[k];
  for ( k = 0; gameObject->numPlayers > k; ++k )
    *(float *)&gameObject->players[k]._4[108] = 1.0
                                              / (double)((signed int)gameObject->couldBeNumDefeatedPlayers
                                                       + (signed int)gameObject->numPlayers);
  *(float *)&curPlayer->_4[104] = (double)v23 / 33.0;
  for ( k = 0; k < 72; ++k )
    gameObject->castles[k].alignment = 0;
  for ( k = 0; curPlayer->numCastles > k; ++k )
    gameObject->castles[curPlayer->castlesOwned[k]].alignment = 0;
  memset(dword_51D5AC, 0, mapHeight * mapWidth);
  for ( l = 0; gameObject->numPlayers > l; ++l )
  {
    if ( l != curPlayerIdx && !sub_4B8CB0(l) )
    {
      for ( j = 0; gameObject->players[l].numHeroes > j; ++j )
      {
        v35 = (int)&gameObject->heroes[gameObject->players[l].heroesOwned[j]];
        Pathfinder::doSomething2(
          pathfinder,
          *(_DWORD *)(v35 + 25),
          *(_DWORD *)(v35 + 29),
          *(_BYTE *)(v35 + 44),
          *(_DWORD *)(v35 + 49) + 100,
          *(_DWORD *)(v35 + 227) & 0x80,
          1,
          *(_DWORD *)(v35 + 49) + 100,
          *(_BYTE *)(v35 + 116),
          -1i64,
          0,
          0);
        for ( col = 0; mapWidth > col; ++col )
        {
          for ( m = 0; m < mapWidth; ++m )
          {
            if ( *(&pathfinder->field_2414[col].field_4 + 9 * mapWidth * m) & 1 )
            {
              *((_BYTE *)dword_51D5AC + col + mapWidth * m) = 1;
              if ( m )
              {
                v12 = usedToCheckForBoatByCastle(advManager, col, m - 1);
                if ( *(_BYTE *)(v12 + 9) == 163 || (*(_BYTE *)(v12 + 9) & 0x7F) == 42 )
                {
                  v10 = sub_419C90(gameObject, col, m - 1);
                  if ( v10 != -1 )
                  {
                    v11 = (char *)&gameObject->castles[v10];
                    if ( gameObject->castles[v10].ownerIdx == curPlayerIdx )
                    {
                      if ( gameObject->castles[v10].buildingsBuiltFlags & 0x40 )
                      {
                        HIDWORD(v3) = (char *)gameObject + 250 * gameObject->castles[v10].visitingHeroIdx + 10180;
                        LODWORD(v3) = (char *)gameObject + 250 * gameObject->castles[v10].visitingHeroIdx + 10281;
                        sub_4AF410(
                          v35 + 101,
                          v35,
                          v3,
                          (int)&gameObject->castles[v10].garrison,
                          1,
                          gameObject->castles[v10].idx,
                          gameObject->castles[v10].ownerIdx,
                          (int)&v30,
                          (int)&v19,
                          (int *)&v16,
                          (int *)&v14,
                          (int *)&v13,
                          (int *)&v39);
                        if ( v30 > 0.7 )
                          v11[2] = 1;
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
  memset(dword_51D5A8, 7, mapHeight * mapWidth);
  for ( l = 0; gameObject->numPlayers > l; ++l )
  {
    if ( l != curPlayerIdx )
    {
      v38 = &gameObject->players[l];
      for ( j = 0; v38->numHeroes > j; ++j )
      {
        v18 = gameObject->heroes[v38->heroesOwned[j]].x;
        v15 = gameObject->heroes[v38->heroesOwned[j]].y;
        for ( col = v18 - 10; v18 + 10 >= col; ++col )
        {
          for ( m = v15 - 10; v15 + 10 >= m; ++m )
          {
            if ( col >= 0 )
            {
              if ( mapWidth > col )
              {
                if ( m >= 0 )
                {
                  if ( m < mapHeight )
                  {
                    v4 = abs(m - v15);
                    v5 = abs(col - v18);
                    v22 = abs(v5 + v4 - 4) >> 2;
                    if ( *((_BYTE *)dword_51D5A8 + col + mapWidth * m) > v22 )
                      *((_BYTE *)dword_51D5A8 + col + mapWidth * m) = v22;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  for ( k = 0; k < 54; ++k )
    dword_5304E8[k] = 1065353216;
  if ( gameObject->difficulty )
  {
    if ( gameObject->difficulty == 1 )
    {
      dword_51D5C0 = 1065353216;
      dword_51D5C4 = 1065353216;
    }
    else
    {
      *(float *)&dword_51D5C0 = (double)gameObject->difficulty * 0.07000000000000001 + 1.0;
      *(float *)&dword_51D5C4 = 1.1 - (double)gameObject->difficulty * 0.12;
    }
  }
  else
  {
    dword_51D5C0 = 1058642330;
    dword_51D5C4 = 1067869798;
  }
  if ( *(_DWORD *)&dword_52478C )
    dword_51D5C4 = 1036831949;
  v17 = 0.1;
  for ( k = 0; curPlayer->numCastles > k; ++k )
  {
    if ( gameObject->castles[curPlayer->castlesOwned[k]].buildingsBuiltFlags & 0x40 )
      v17 = v17 + 1.0;
    else
      v17 = v17 + 0.5;
  }
  v36 = (signed __int64)v17;
  dword_532CE4 = 3;
  if ( gameObject->numPlayers - gameObject->couldBeNumDefeatedPlayers == 2 )
    ++dword_532CE4;
  if ( gameObject->numPlayers - gameObject->couldBeNumDefeatedPlayers == 3 )
    ++dword_532CE4;
  if ( v36 >= 5 )
    ++dword_532CE4;
  if ( v36 >= 10 )
    ++dword_532CE4;
  if ( gameObject->_1[682] == 36 )
    --dword_532CE4;
  if ( gameObject->_1[682] >= 108 )
    ++dword_532CE4;
  v24 = 16;
  v33 = 22;
  if ( curPlayer->personality == 2 )
  {
    v24 = 8;
    v33 = 15;
  }
  if ( dword_532C54 < v24 )
  {
    if ( v36 == 1 )
    {
      if ( curPlayer->numHeroes == 1 )
      {
        v6 = (char *)&gameObject->heroes[curPlayer->heroesOwned[0]];
        v7 = (char *)&gameObject->castles[curPlayer->castlesOwned[0]];
        v8 = abs(gameObject->castles[curPlayer->castlesOwned[0]].field_4 - gameObject->heroes[curPlayer->heroesOwned[0]].x);
        if ( abs((unsigned __int8)v7[5] - *(_DWORD *)(v6 + 29)) + v8 < 18 )
          dword_532CE4 = 1;
      }
    }
  }
  if ( dword_532C54 < v33 && dword_532CE4 > 2 )
    dword_532CE4 = 2;
  if ( curPlayer->personality == 2 )
    ++v36;
  if ( v36 + 1 < dword_532CE4 )
    dword_532CE4 = v36 + 1;
  result = curPlayer;
  if ( curPlayer->_2 > dword_532CE4 )
  {
    result = curPlayer;
    dword_532CE4 = curPlayer->_2;
  }
  return result;
}
