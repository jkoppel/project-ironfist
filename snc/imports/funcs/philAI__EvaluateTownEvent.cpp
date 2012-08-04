{
  __int64 v5; // ST08_8@25
  float v7; // [sp+2Ch] [bp-28h]@31
  int v8; // [sp+30h] [bp-24h]@24
  char v9; // [sp+34h] [bp-20h]@25
  char v10; // [sp+38h] [bp-1Ch]@25
  char v11; // [sp+3Ch] [bp-18h]@25
  char v12; // [sp+40h] [bp-14h]@25
  float v13; // [sp+44h] [bp-10h]@25
  int v14; // [sp+48h] [bp-Ch]@1
  town *this; // [sp+4Ch] [bp-8h]@1
  int v16; // [sp+50h] [bp-4h]@25

  v14 = 0;
  this = &gpGame->castles[a1];
  if ( gpGame->_7[a1] == gpCurAIHero->probablyOwnerIdx )
  {
    if ( this->visitingHeroIdx == -1 )
    {
      v14 = 0;
      if ( giCurTurn - *(_WORD *)&gpCurAIHero->_2[3] >= 4 || gpCurAIHero->_2[5] != this->idx )
      {
        philAI::HeroInteractionAtTown((int)gpCurAIHero, (signed int)this, 1, (int)&v14);
        v14 = (signed __int64)((double)v14 * *(float *)&dword_5304E8[gpCurAIHero->couldBeHeroIdx]);
      }
    }
    else if ( a4 )
    {
      v14 = -500;
    }
    else
    {
      v14 = 0;
    }
    gbReduceByReload = 0;
  }
  else if ( OnMySide(gpGame->_7[a1]) )
  {
    if ( a4 )
      v14 = -1500;
    else
      v14 = 0;
  }
  else if ( !*(_DWORD *)&gbIAmGreatest || gpGame->_7[a1] < 0 || gbHumanPlayer[gpGame->_7[a1]] )
  {
    if ( gpGame->difficulty >= 3
      || 40 - 8 * gpGame->difficulty <= giCurTurn
      || (unsigned __int8)(*(&mapExtra[a2] + a3 * MAP_WIDTH) & giCurPlayerBit) )
    {
      v8 = philAI::ValueOfTown((int)this);
      if ( gpGame->castles[a1].visitingHeroIdx == -1 )
      {
        if ( town::HasGarrison(this) )
        {
          philAI::ProbableOutcomeOfBattle(
            (int)&gpCurAIHero->army,
            (int)gpCurAIHero,
            (unsigned int)&this->garrison,
            0,
            1,
            a1,
            this->ownerIdx,
            (int)&v13,
            (int)&v12,
            (int *)&v11,
            (int *)&v10,
            (int *)&v9,
            &v16);
        }
        else
        {
          v13 = 1.0;
          v16 = 0;
        }
      }
      else
      {
        HIDWORD(v5) = (char *)gpGame + 250 * this->visitingHeroIdx + 10180;
        LODWORD(v5) = (char *)gpGame + 250 * this->visitingHeroIdx + 10281;
        philAI::ProbableOutcomeOfBattle(
          (int)&gpCurAIHero->army,
          (int)gpCurAIHero,
          v5,
          (int)&this->garrison,
          1,
          a1,
          this->ownerIdx,
          (int)&v13,
          (int)&v12,
          (int *)&v11,
          (int *)&v10,
          (int *)&v9,
          &v16);
      }
      *(_DWORD *)a5 = (signed __int64)(v13 * 100.0);
      if ( this->ownerIdx >= 0 )
      {
        if ( gbHumanPlayer[this->ownerIdx] )
          v7 = *(float *)&gfAttackHumanBonus;
        else
          v7 = *(float *)&gfAttackComputerBonus;
        v8 = (signed __int64)(((double)(5 - (signed int)gpGame->numPlayers) * 0.25 + 0.9) * v7 * (double)v8);
      }
      v14 = (signed __int64)((double)v8 * v13 + (double)v16);
      if ( gpGame->_7[a1] != -1 )
        gbReduceByBerserk = 0;
    }
    else
    {
      v14 = 0;
    }
  }
  else
  {
    v14 = 0;
  }
  if ( this->ownerIdx != -1 && gbHumanPlayer[this->ownerIdx] && v14 > 200 )
  {
    if ( gpCurPlayer->personality )
      v14 = (signed __int64)((double)v14 * 1.3);
    else
      v14 = (signed __int64)((double)v14 * 1.6);
  }
  return v14;
}