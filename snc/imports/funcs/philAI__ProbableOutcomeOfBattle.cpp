{
  float v13; // ST94_4@29
  float v14; // [sp+74h] [bp-40h]@55
  float v15; // [sp+78h] [bp-3Ch]@3
  float v16; // [sp+7Ch] [bp-38h]@3
  float v17; // [sp+80h] [bp-34h]@8
  float v18; // [sp+8Ch] [bp-28h]@30
  signed int i; // [sp+90h] [bp-24h]@34
  signed int j; // [sp+90h] [bp-24h]@45
  float v21; // [sp+9Ch] [bp-18h]@7
  int v22; // [sp+A0h] [bp-14h]@1
  float v23; // [sp+A8h] [bp-Ch]@1
  float v24; // [sp+ACh] [bp-8h]@1
  int v25; // [sp+B0h] [bp-4h]@1

  v22 = 0;
  v25 = 0;
  v23 = (double)philAI::FightValueOfStack((armyGroup *)a1, (hero *)a2, 1, 0, 0, a5);
  v24 = (double)philAI::FightValueOfStack((armyGroup *)a3, HIDWORD(a3), 1, a5, a6, 0);
  if ( a4 )
    v24 = (double)philAI::FightValueOfStack((armyGroup *)a4, 0, 1, 0, 0, 0) + v24;
  v15 = (double)philAI::FightValueOfStack((armyGroup *)a1, (hero *)a2, 0, 0, 0, 0);
  v16 = (double)philAI::FightValueOfStack((armyGroup *)a3, HIDWORD(a3), 0, 0, 0, 0);
  if ( a4 )
    v16 = (double)philAI::FightValueOfStack((armyGroup *)a4, 0, 0, 0, 0, 0) + v16;
  if ( a5 )
    v24 = v24 * 1.11;
  v21 = v24;
  if ( a7 == -1 )
  {
    v17 = ((double)gpGame->difficulty * 0.15 + 0.7) * v23;
    if ( !gpCurPlayer->personality )
      v17 = v17 * 1.08;
  }
  else
  {
    v17 = v23;
    if ( gbHumanPlayer[a7] )
    {
      v21 = v24 * 1.14;
    }
    else if ( !gpCurPlayer->personality )
    {
      v17 = v23 * 1.08;
    }
  }
  if ( v17 < 1.0 )
    v17 = 1.0;
  if ( v21 < 1.0 )
    v21 = 1.0;
  pow();
  pow();
  *(float *)a8 = v17 / (v21 + v17);
  if ( *(float *)a8 >= 0.08 )
  {
    if ( *(float *)a8 >= 0.12 )
    {
      if ( *(float *)a8 >= 0.2 )
      {
        if ( *(float *)a8 >= 0.3 )
        {
          if ( *(float *)a8 < 0.4 )
            *(float *)a8 = *(float *)a8 - 0.02;
        }
        else
        {
          *(float *)a8 = *(float *)a8 - 0.04;
        }
      }
      else
      {
        *(float *)a8 = *(float *)a8 - 0.05;
      }
    }
    else
    {
      *(float *)a8 = *(float *)a8 - 0.07000000000000001;
    }
  }
  else
  {
    *(_DWORD *)a8 = 0;
  }
  *(_DWORD *)a9 = (signed __int64)((1.0 - *(float *)a8) * v15);
  *a10 = (signed __int64)(v16 * *(float *)a8);
  *a11 = (signed __int64)((1.0 - *(float *)a8) * v15 + (double)*(signed int *)a9 * *(float *)a8);
  *a12 = (signed __int64)((1.0 - *(float *)a8) * (double)*a10 + v16 * *(float *)a8);
  v13 = 1.33 - *(float *)&gpCurPlayer->_4[24];
  *a13 = (signed __int64)((double)-*a11 * v13 * v13);
  if ( a7 >= 0 )
  {
    v18 = *(float *)&gpCurPlayer->_4[24] + 0.66;
    if ( gbHumanPlayer[a7] )
      *a13 = (signed __int64)((double)*a12 * v18 * v18 * *(float *)&gfAttackHumanBonus + (double)*a13);
    else
      *a13 = (signed __int64)((double)*a12 * *(float *)&gfAttackComputerBonus * v18 * v18 + (double)*a13);
  }
  *a13 = (signed __int64)((double)*a13 * *(float *)&gpCurPlayer->_4[100]);
  if ( a2 )
  {
    for ( i = 0; i < 14; ++i )
    {
      if ( (signed int)*(_BYTE *)(i + a2 + 213) >= 0 )
      {
        if ( (signed int)*(_BYTE *)(i + a2 + 213) < 37 )
          v22 += gArtifactBaseRV[*(_BYTE *)(a2 + i + 213)];
      }
    }
    if ( gpGame->winConditionType == 2 && *(_BYTE *)(a2 + 2) == gpGame->winConditionArgument )
      v22 += 50000;
    *a13 = (signed __int64)((double)*a13 - (1.0 - *(float *)a8) * (double)(v22 + 1400));
    *a13 = (signed __int64)((double)game::ExperienceValueOfStack(a3, SHIDWORD(a3))
                          * *(float *)(a2 + 232)
                          * *(float *)a8
                          * 0.8
                          + (double)*a13);
  }
  if ( HIDWORD(a3) )
  {
    for ( j = 0; j < 14; ++j )
    {
      if ( (signed int)*(_BYTE *)(j + HIDWORD(a3) + 213) >= 0 && (signed int)*(_BYTE *)(j + HIDWORD(a3) + 213) < 37 )
        v25 += gArtifactBaseRV[*(_BYTE *)(HIDWORD(a3) + j + 213)];
    }
    if ( gpGame->_2[0] == 2 && *(_BYTE *)(HIDWORD(a3) + 2) == *(_WORD *)&gpGame->_2[1] )
      v25 += 50000;
    if ( gbHumanPlayer[*(_BYTE *)(HIDWORD(a3) + 3)] )
      v14 = *(float *)&gfAttackHumanBonus;
    else
      v14 = *(float *)&gfAttackComputerBonus;
    *a13 = (signed __int64)((double)(v25 + 1250) * v14 * *(float *)a8 + (double)*a13);
  }
  if ( giDebugLevel >= 9 )
  {
    LogInt(
      (int)"POBA",
      (signed __int64)v17,
      (signed __int64)v21,
      (signed __int64)(*(float *)&gpCurPlayer->_4[24] * 100.0),
      0,
      v22,
      v25,
      (signed __int64)*(float *)&gpCurPlayer->_4[100]);
    LogInt(
      (int)"POB",
      (signed __int64)v23,
      (signed __int64)v24,
      (signed __int64)(*(float *)a8 * 100.0),
      *a10,
      *a11,
      *a12,
      *a13);
  }
}