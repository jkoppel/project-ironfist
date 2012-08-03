{
  int v3; // eax@3
  double v4; // st7@17
  double v5; // st7@19
  void *v6; // [sp+20h] [bp-270h]@1
  float v7; // [sp+24h] [bp-26Ch]@1
  int v8[72]; // [sp+28h] [bp-268h]@3
  int i; // [sp+148h] [bp-148h]@1
  float v10; // [sp+14Ch] [bp-144h]@1
  int v11; // [sp+150h] [bp-140h]@9
  int v12; // [sp+154h] [bp-13Ch]@3
  int v13[72]; // [sp+158h] [bp-138h]@11
  char v14; // [sp+278h] [bp-18h]@17
  int v15; // [sp+27Ch] [bp-14h]@18
  int v16; // [sp+280h] [bp-10h]@18
  int v17; // [sp+284h] [bp-Ch]@18
  int v18; // [sp+288h] [bp-8h]@1
  int v19; // [sp+28Ch] [bp-4h]@1

  v6 = this;
  v10 = 1.0;
  v7 = -99.0;
  v18 = 0;
  v19 = 0;
  for ( i = 0; gpCurPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
    v3 = philAI::FightValueOfStack((armyGroup *)(v12 + 8), 0, 0, 0, 0, 0);
    v8[i] = v3 + 400;
    v18 += v8[i];
    if ( *(_BYTE *)(v12 + 24) & 0x40 )
      v19 += 10;
    else
      v19 += 7;
  }
  if ( v19 < 1 )
    v19 = 1;
  v11 = v18 / v19;
  for ( i = 0; gpCurPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
    v13[i] = v11 * ((*(_DWORD *)(v12 + 24) & 0x40u) < 1 ? 7 : 10) + 400;
  }
  for ( i = 0; gpCurPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
    LogInt((int)"Turns Owned", *(_WORD *)(v12 + 85), -999, -999, -999, -999, -999, -999);
    if ( giCurTurn <= 3 || (signed int)*(_WORD *)(v12 + 85) >= 3 )
    {
      CheckDoMain(0, 0);
      philAI::GetBestBuilding(v6, v12, (int)&v14, (int)&v10);
      v4 = (double)(100 - Random(0, 10)) / 100.0 * v10;
      v10 = v4;
      if ( v4 > v7 )
      {
        v7 = v10;
        *(_DWORD *)a3 = *(_DWORD *)&v14;
        *(_DWORD *)(a3 + 4) = v15;
        *(_DWORD *)(a3 + 8) = v16;
        *(_DWORD *)(a3 + 12) = v17;
      }
      CheckDoMain(0, 0);
      philAI::GetBestCreature(v12, (int)&v14, (int)&v10);
      v10 = ((double)v13[i] / (double)v8[i] / 3.0 + 0.66) * v10;
      v5 = (double)(100 - Random(0, 10)) / 100.0 * v10;
      v10 = v5;
      if ( v5 > v7 )
      {
        v7 = v10;
        *(_DWORD *)a3 = *(_DWORD *)&v14;
        *(_DWORD *)(a3 + 4) = v15;
        *(_DWORD *)(a3 + 8) = v16;
        *(_DWORD *)(a3 + 12) = v17;
      }
      CheckDoMain(0, 0);
      if ( gpCurPlayer->numHeroes < giMaxHeroesForThisPlayer && *(_BYTE *)(v12 + 24) & 0x40 )
      {
        philAI::GetBestHero(v12, (int)&v14, (int)&v10);
        v10 = (double)(100 - Random(0, 10)) / 100.0 * v10;
        if ( bHeroBuiltThisTurn || giCurTurn <= 5 || v10 <= 0.0 )
        {
          if ( !gpCurPlayer->numHeroes )
            v10 = v10 + 500.0;
        }
        else if ( (*(_DWORD *)&gpCurPlayer->_4[84] < 1250 || gpCurPlayer->numHeroes >= giMaxHeroesForThisPlayer - 2)
  && gpCurPlayer->numHeroes > 1 )
        {
          if ( *(_DWORD *)&gpCurPlayer->_4[84] >= 1500 && gpCurPlayer->numHeroes < giMaxHeroesForThisPlayer - 1 )
            v10 = v10 * 1.3;
        }
        else
        {
          v10 = v10 + 500.0;
        }
        if ( v7 < (double)v10 )
        {
          v7 = v10;
          *(_DWORD *)a3 = *(_DWORD *)&v14;
          *(_DWORD *)(a3 + 4) = v15;
          *(_DWORD *)(a3 + 8) = v16;
          *(_DWORD *)(a3 + 12) = v17;
        }
      }
    }
  }
  LogInt((int)"BestBHC ", *(_DWORD *)(a3 + 4), (signed __int64)(v7 * 100.0), *(_DWORD *)(a3 + 8), 0, 0, -999, -999);
  if ( v7 < 0.02 )
    *(_DWORD *)(a3 + 4) = -1;
}