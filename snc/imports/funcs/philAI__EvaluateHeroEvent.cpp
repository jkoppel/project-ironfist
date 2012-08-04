{
  __int64 v5; // ST08_8@29
  float v7; // [sp+2Ch] [bp-34h]@24
  int v8; // [sp+30h] [bp-30h]@22
  int v9; // [sp+34h] [bp-2Ch]@21
  char *v10; // [sp+38h] [bp-28h]@21
  char *v11; // [sp+3Ch] [bp-24h]@22
  int v12; // [sp+40h] [bp-20h]@21
  char v13; // [sp+44h] [bp-1Ch]@29
  char v14; // [sp+48h] [bp-18h]@29
  char v15; // [sp+4Ch] [bp-14h]@29
  char v16; // [sp+50h] [bp-10h]@29
  float v17; // [sp+54h] [bp-Ch]@29
  int v18; // [sp+58h] [bp-8h]@3

  if ( gpGame->relatedToHeroForHireStatus[a1] == gpCurAIHero->probablyOwnerIdx )
  {
    if ( a4 )
    {
      if ( a4 == 1 )
        v18 = -20000;
      else
        v18 = -500;
    }
    else
    {
      v18 = 0;
    }
    if ( giCurTurn - *(_WORD *)&gpCurAIHero->_2[0] >= 4 || gpGame->heroes[a1].couldBeHeroIdx != gpCurAIHero->_2[2] )
      philAI::HeroInteractionAtHero((int)gpCurAIHero, (int)&gpGame->heroes[a1], 1, (int)&v18);
    gaiHeroLiveChance[a1] = 100;
  }
  else if ( OnMySide(gpGame->relatedToHeroForHireStatus[a1]) )
  {
    if ( a4 )
    {
      if ( a4 == 1 )
        v18 = -20000;
      else
        v18 = -1500;
    }
    else
    {
      v18 = 0;
    }
  }
  else if ( !*(_DWORD *)&gbIAmGreatest || gbHumanPlayer[gpGame->relatedToHeroForHireStatus[a1]] )
  {
    v18 = 0;
    v12 = 0;
    v9 = 0;
    v10 = (char *)&gpGame->heroes[a1];
    if ( gpGame->heroes[a1].occupiedObjType == 163 )
    {
      v11 = (char *)&gpGame->castles[gpGame->heroes[a1].occupiedObjVal];
      v9 = (int)&gpGame->castles[gpGame->heroes[a1].occupiedObjVal].garrison;
      v12 = philAI::ValueOfTown((int)&gpGame->castles[gpGame->heroes[a1].occupiedObjVal]);
      v8 = *v11;
      if ( v11[1] >= 0 )
      {
        if ( gbHumanPlayer[v11[1]] )
          v7 = *(float *)&gfAttackHumanBonus;
        else
          v7 = *(float *)&gfAttackComputerBonus;
        v12 = (signed __int64)(((double)(5 - (signed int)gpGame->numPlayers) * 0.25 * v7 + 1.0) * (double)v12);
      }
    }
    else
    {
      v8 = -1;
    }
    HIDWORD(v5) = v10;
    LODWORD(v5) = v10 + 101;
    philAI::ProbableOutcomeOfBattle(
      (int)&gpCurAIHero->army,
      (int)gpCurAIHero,
      v5,
      v9,
      (unsigned int)v9 >= 1,
      v8,
      v10[3],
      (int)&v17,
      (int)&v16,
      (int *)&v15,
      (int *)&v14,
      (int *)&v13,
      &v18);
    *(_DWORD *)a5 = (signed __int64)(v17 * 100.0);
    if ( v12 > 0 )
      v18 = (signed __int64)((double)v12 * v17 + (double)v18);
    if ( gbHumanPlayer[v10[3]] && v18 > 200 )
    {
      if ( gpCurPlayer->personality )
        v18 = (signed __int64)((double)v18 * 1.5);
      else
        v18 *= 2;
    }
    if ( v17 <= 0.75 )
    {
      if ( v17 <= 0.5 )
      {
        if ( v17 <= 0.4 )
        {
          if ( v17 <= 0.3 )
          {
            if ( v17 <= 0.2 )
              gaiHeroLiveChance[a1] = (signed __int64)(v17 * 100.0);
            else
              gaiHeroLiveChance[a1] = (signed __int64)(v17 * 113.0);
          }
          else
          {
            gaiHeroLiveChance[a1] = (signed __int64)(v17 * 125.0);
          }
        }
        else
        {
          gaiHeroLiveChance[a1] = (signed __int64)(v17 * 130.0);
        }
      }
      else
      {
        gaiHeroLiveChance[a1] = (signed __int64)(v17 * 136.0);
      }
    }
    else
    {
      gaiHeroLiveChance[a1] = 100;
    }
    if ( gaiHeroLiveChance[a1] > 100 )
      gaiHeroLiveChance[a1] = 100;
    if ( !a4 && v17 < 0.4 )
      v18 = (signed __int64)((3.0 - v17 * 2.0) * (double)v18);
    if ( !a4 && v17 < 0.2 )
      v18 = (signed __int64)((2.0 - v17 * 2.0) * (double)v18);
    if ( v18 < 0 )
      gbReduceByReload = 0;
    gbReduceByBerserk = 0;
    if ( v18 > 0
      && 70 - 5 * gpGame->difficulty > giCurTurn
      && !(unsigned __int8)(*(&mapExtra[a2] + a3 * MAP_WIDTH) & giCurPlayerBit) )
      v18 = 0;
  }
  else
  {
    v18 = 0;
    *(_DWORD *)a5 = 100;
  }
  return v18;
}