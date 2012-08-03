{
  signed __int64 v1; // qax@1
  int v2; // ebx@13
  __int64 v3; // ST08_8@54
  int v4; // ebx@73
  int v5; // eax@73
  char *v6; // ST70_4@112
  char *v7; // ST74_4@112
  int v8; // ebx@112
  playerData *result; // eax@121
  signed int v10; // [sp+40h] [bp-78h]@51
  char *v11; // [sp+44h] [bp-74h]@52
  mapCell *v12; // [sp+48h] [bp-70h]@49
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
  hero *hro; // [sp+88h] [bp-30h]@9
  int col; // [sp+8Ch] [bp-2Ch]@42
  float v30; // [sp+90h] [bp-28h]@54
  int v31; // [sp+94h] [bp-24h]@3
  float v32; // [sp+98h] [bp-20h]@3
  int v33; // [sp+9Ch] [bp-1Ch]@107
  town *v34; // [sp+A0h] [bp-18h]@6
  int v35; // [sp+A4h] [bp-14h]@42
  int v36; // [sp+A8h] [bp-10h]@95
  int v37; // [sp+ACh] [bp-Ch]@17
  playerData *v38; // [sp+B0h] [bp-8h]@63
  char v39; // [sp+B4h] [bp-4h]@54

  giCurTurn = gpGame->day + 7 * (gpGame->week - 1) + 28 * (gpGame->month - 1);
  philAI::GetTurnAttentionValue(a1);
  philAI::TurnCostResource(a1);
  LODWORD(iCurHourGlassPhase) = 0;
  iSandAnim = 0;
  v1 = (signed __int64)philAI::TurnValueOfObelisk(a1);
  *(_DWORD *)&gpCurPlayer->_4[88] = v1;
  *(_DWORD *)&gpCurPlayer->_4[92] = *(_DWORD *)&gpCurPlayer->_4[88] * (signed int)gpGame->numObelisks / 48;
  *(_DWORD *)&gpCurPlayer->_4[96] = philAI::MeanRVOfUnexploredTerritory(a1);
  bHeroBuiltThisTurn = 0;
  if ( giCurTurn - giBuildBoatStuffTurn[a1] > 8 )
  {
    giBuildShipyard[a1] = -1;
    giBuildBoat[a1] = -1;
  }
  v31 = 0;
  v32 = 0.0;
  if ( giCurTurn <= 7 )
  {
    dword_51D58C = 0;
    for ( i = 0; gpCurPlayer->numCastles > i; ++i )
    {
      v34 = &gpGame->castles[gpCurPlayer->castlesOwned[i]];
      for ( j = 0; j < 54; ++j )
      {
        hro = &gpGame->heroes[j];
        if ( gpGame->heroes[j].probablyOwnerIdx >= 0 )
        {
          if ( hro->probablyOwnerIdx <= 5 )
          {
            if ( hro->probablyOwnerIdx != giCurPlayer )
            {
              v2 = abs(hro->x - v34->field_4);
              if ( abs(hro->y - v34->field_5) + v2 < 16 )
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
  for ( k = 0; gpCurPlayer->numHeroes > k; ++k )
  {
    hro = &gpGame->heroes[gpCurPlayer->heroesOwned[k]];
    v32 = (double)philAI::FightValueOfStack(&hro->army, hro, 0, 0, 0, 0);
    v37 = (signed __int64)((double)v37 + v32);
    *(float *)&hro->field_E7[1] = v32 * 0.00004 + 0.4;
  }
  for ( k = 0; gpCurPlayer->numCastles > k; ++k )
  {
    v34 = &gpGame->castles[gpCurPlayer->castlesOwned[k]];
    v32 = (double)philAI::FightValueOfStack(&v34->garrison, 0, 0, 0, 0, 0);
    v37 = (signed __int64)((double)v37 + v32);
  }
  *(float *)&gpCurPlayer->_4[100] = (double)(gpCurPlayer->resources[6] + *(_DWORD *)&gpCurPlayer->_4[84])
                                  / (double)(v37 + 1000)
                                  + *(float *)&gpCurPlayer->_4[24];
  v23 = 0;
  for ( k = 4; k < 37; ++k )
    v23 += gArtifactBaseRV[k];
  for ( k = 0; gpGame->numPlayers > k; ++k )
    *(float *)&gpGame->players[k]._4[108] = 1.0
                                          / (double)((signed int)gpGame->couldBeNumDefeatedPlayers
                                                   + (signed int)gpGame->numPlayers);
  *(float *)&gpCurPlayer->_4[104] = (double)v23 / 33.0;
  for ( k = 0; k < 72; ++k )
    gpGame->castles[k].alignment = 0;
  for ( k = 0; gpCurPlayer->numCastles > k; ++k )
    gpGame->castles[gpCurPlayer->castlesOwned[k]].alignment = 0;
  memset(gaiEnemyHeroReachable, 0, MAP_HEIGHT * MAP_WIDTH);
  for ( l = 0; gpGame->numPlayers > l; ++l )
  {
    if ( l != giCurPlayer && !OnMySide(l) )
    {
      for ( j = 0; gpGame->players[l].numHeroes > j; ++j )
      {
        v35 = (int)&gpGame->heroes[gpGame->players[l].heroesOwned[j]];
        searchArray::SeedPosition(
          gpSearchArray,
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
        for ( col = 0; MAP_WIDTH > col; ++col )
        {
          for ( m = 0; m < MAP_WIDTH; ++m )
          {
            if ( *(&gpSearchArray->field_2414[col].field_4 + 9 * MAP_WIDTH * m) & 1 )
            {
              *((_BYTE *)gaiEnemyHeroReachable + col + MAP_WIDTH * m) = 1;
              if ( m )
              {
                v12 = advManager::GetCell(gpAdvManager, col, m - 1);
                if ( v12->objType == 163 || (v12->objType & 0x7F) == 42 )
                {
                  v10 = game::GetTownId(gpGame, col, m - 1);
                  if ( v10 != -1 )
                  {
                    v11 = (char *)&gpGame->castles[v10];
                    if ( gpGame->castles[v10].ownerIdx == giCurPlayer )
                    {
                      if ( gpGame->castles[v10].buildingsBuiltFlags & 0x40 )
                      {
                        HIDWORD(v3) = (char *)gpGame + 250 * gpGame->castles[v10].visitingHeroIdx + 10180;
                        LODWORD(v3) = (char *)gpGame + 250 * gpGame->castles[v10].visitingHeroIdx + 10281;
                        philAI::ProbableOutcomeOfBattle(
                          v35 + 101,
                          v35,
                          v3,
                          (int)&gpGame->castles[v10].garrison,
                          1,
                          gpGame->castles[v10].idx,
                          gpGame->castles[v10].ownerIdx,
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
  memset(gaiTurnValueOfMine, 7u, MAP_HEIGHT * MAP_WIDTH);
  for ( l = 0; gpGame->numPlayers > l; ++l )
  {
    if ( l != giCurPlayer )
    {
      v38 = &gpGame->players[l];
      for ( j = 0; v38->numHeroes > j; ++j )
      {
        v18 = gpGame->heroes[v38->heroesOwned[j]].x;
        v15 = gpGame->heroes[v38->heroesOwned[j]].y;
        for ( col = v18 - 10; v18 + 10 >= col; ++col )
        {
          for ( m = v15 - 10; v15 + 10 >= m; ++m )
          {
            if ( col >= 0 )
            {
              if ( MAP_WIDTH > col )
              {
                if ( m >= 0 )
                {
                  if ( m < MAP_HEIGHT )
                  {
                    v4 = abs(m - v15);
                    v5 = abs(col - v18);
                    v22 = abs(v5 + v4 - 4) >> 2;
                    if ( *((_BYTE *)gaiTurnValueOfMine + col + MAP_WIDTH * m) > v22 )
                      *((_BYTE *)gaiTurnValueOfMine + col + MAP_WIDTH * m) = v22;
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
  if ( gpGame->difficulty )
  {
    if ( gpGame->difficulty == 1 )
    {
      gfAttackHumanBonus = 1065353216;
      gfAttackComputerBonus = 1065353216;
    }
    else
    {
      *(float *)&gfAttackHumanBonus = (double)gpGame->difficulty * 0.07000000000000001 + 1.0;
      *(float *)&gfAttackComputerBonus = 1.1 - (double)gpGame->difficulty * 0.12;
    }
  }
  else
  {
    gfAttackHumanBonus = 1058642330;
    gfAttackComputerBonus = 1067869798;
  }
  if ( *(_DWORD *)&gbIAmGreatest )
    gfAttackComputerBonus = 1036831949;
  v17 = 0.1;
  for ( k = 0; gpCurPlayer->numCastles > k; ++k )
  {
    if ( gpGame->castles[gpCurPlayer->castlesOwned[k]].buildingsBuiltFlags & 0x40 )
      v17 = v17 + 1.0;
    else
      v17 = v17 + 0.5;
  }
  v36 = (signed __int64)v17;
  giMaxHeroesForThisPlayer = 3;
  if ( gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers == 2 )
    ++giMaxHeroesForThisPlayer;
  if ( gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers == 3 )
    ++giMaxHeroesForThisPlayer;
  if ( v36 >= 5 )
    ++giMaxHeroesForThisPlayer;
  if ( v36 >= 10 )
    ++giMaxHeroesForThisPlayer;
  if ( gpGame->_1[682] == 36 )
    --giMaxHeroesForThisPlayer;
  if ( gpGame->_1[682] >= 108 )
    ++giMaxHeroesForThisPlayer;
  v24 = 16;
  v33 = 22;
  if ( gpCurPlayer->personality == 2 )
  {
    v24 = 8;
    v33 = 15;
  }
  if ( giCurTurn < v24 )
  {
    if ( v36 == 1 )
    {
      if ( gpCurPlayer->numHeroes == 1 )
      {
        v6 = (char *)&gpGame->heroes[gpCurPlayer->heroesOwned[0]];
        v7 = (char *)&gpGame->castles[gpCurPlayer->castlesOwned[0]];
        v8 = abs(gpGame->castles[gpCurPlayer->castlesOwned[0]].field_4 - gpGame->heroes[gpCurPlayer->heroesOwned[0]].x);
        if ( abs((unsigned __int8)v7[5] - *(_DWORD *)(v6 + 29)) + v8 < 18 )
          giMaxHeroesForThisPlayer = 1;
      }
    }
  }
  if ( giCurTurn < v33 && giMaxHeroesForThisPlayer > 2 )
    giMaxHeroesForThisPlayer = 2;
  if ( gpCurPlayer->personality == 2 )
    ++v36;
  if ( v36 + 1 < giMaxHeroesForThisPlayer )
    giMaxHeroesForThisPlayer = v36 + 1;
  result = gpCurPlayer;
  if ( gpCurPlayer->_2 > giMaxHeroesForThisPlayer )
  {
    result = gpCurPlayer;
    giMaxHeroesForThisPlayer = gpCurPlayer->_2;
  }
  return result;
}