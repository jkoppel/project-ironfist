{
  int result; // eax@3
  float v5; // [sp+1Ch] [bp-2Ch]@19
  signed int v6; // [sp+20h] [bp-28h]@17
  char v7; // [sp+24h] [bp-24h]@12
  char v8; // [sp+28h] [bp-20h]@12
  char v9; // [sp+2Ch] [bp-1Ch]@12
  char v10; // [sp+30h] [bp-18h]@12
  int i; // [sp+34h] [bp-14h]@6
  float v12; // [sp+38h] [bp-10h]@12
  int v13; // [sp+3Ch] [bp-Ch]@1
  int v14; // [sp+40h] [bp-8h]@5
  int v15; // [sp+44h] [bp-4h]@12

  v13 = 0;
  if ( gpGame->_8[a1 + 1008] == gpCurAIHero->probablyOwnerIdx || OnMySide(gpGame->_8[a1 + 1008]) )
  {
    result = v13;
  }
  else
  {
    if ( gpGame->_8[7 * a1 + 3] != -1 )
    {
      v14 = gpGame->_8[7 * a1 + 4];
      memset(gpMonGroup, 0xFFu, 5u);
      memset((char *)gpMonGroup + 5, 0, 0xAu);
      if ( v14 / 5 > 0 )
      {
        for ( i = 0; i < 5; ++i )
        {
          *((_BYTE *)gpMonGroup + i) = gpGame->_8[7 * a1 + 3];
          *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = v14 / 5;
        }
      }
      for ( i = v14 % 5 - 1; i >= 0; --i )
      {
        *((_BYTE *)gpMonGroup + i) = gpGame->_8[7 * a1 + 3];
        ++*(_WORD *)((char *)gpMonGroup + 2 * i + 5);
      }
      philAI::ProbableOutcomeOfBattle(
        (int)&gpCurAIHero->army,
        (int)gpCurAIHero,
        (unsigned int)gpMonGroup,
        0,
        0,
        0,
        -1,
        (int)&v12,
        (int)&v10,
        (int *)&v9,
        (int *)&v8,
        (int *)&v7,
        &v15);
      *(_DWORD *)a4 = (signed __int64)v12;
      v13 = v15;
    }
    if ( !*(_DWORD *)&gbIAmGreatest || gpGame->_8[a1 + 1008] < 0 || gbHumanPlayer[gpGame->_8[a1 + 1008]] )
    {
      v6 = (signed __int64)((double)gMineCharacteristics[gpGame->_8[7 * a1 + 2]]
                          * gafAITurnCostResource[gpGame->_8[7 * a1 + 2]]
                          * (double)*((_BYTE *)gaiTurnValueOfMine + a2 + a3 * MAP_WIDTH));
      if ( gpGame->_8[a1 + 1008] >= 0 )
      {
        if ( gbHumanPlayer[gpGame->_8[a1 + 1008]] )
          v5 = *(float *)&gfAttackHumanBonus;
        else
          v5 = *(float *)&gfAttackComputerBonus;
        v6 = (signed __int64)((double)v6 * v5);
      }
      v13 += v6;
      result = v13;
    }
    else
    {
      result = v13;
    }
  }
  return result;
}