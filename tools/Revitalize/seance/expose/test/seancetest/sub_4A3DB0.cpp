void __thiscall sub_4A3DB0(CombatManager *this, int side, int stackIdx, int a4)
{
  float v4; // ST40_4@39
  CombatManager *thisa; // [sp+24h] [bp-44h]@1
  float v6; // [sp+28h] [bp-40h]@2
  signed int a6; // [sp+30h] [bp-38h]@2
  signed int i; // [sp+38h] [bp-30h]@15
  float v9; // [sp+3Ch] [bp-2Ch]@2
  signed int y; // [sp+40h] [bp-28h]@8
  int ya; // [sp+40h] [bp-28h]@32
  size_t v12; // [sp+4Ch] [bp-1Ch]@15
  int v13; // [sp+50h] [bp-18h]@35
  int v14; // [sp+50h] [bp-18h]@37
  CreatureStack *v15; // [sp+54h] [bp-14h]@1
  float *buf; // [sp+58h] [bp-10h]@8
  signed int v17; // [sp+5Ch] [bp-Ch]@2
  int v18; // [sp+60h] [bp-8h]@18
  int v19; // [sp+64h] [bp-4h]@18

  thisa = this;
  v15 = &this->creatures[side][stackIdx];
  if ( a4 )
  {
    v17 = 1;
    a6 = 30;
    v9 = 0.2;
    v6 = 0.1;
  }
  else
  {
    v17 = 2;
    a6 = 20;
    v9 = 0.30000001;
    v6 = 0.050000001;
  }
  CombatManager::resetStuffHapenedToCreature(this);
  ++thisa->stuffHappenedToCreature[side][stackIdx];
  if ( a4 == 2 )
    CombatManager::drawBattlefield(combatManager, 0, 1, 1, 0, 75, 1, 1);
  else
    CombatManager::drawBattlefield(combatManager, 1, 1, 1, 0, 75, 1, 1);
  dword_51A400 = KBAlloc(480u, "F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 44);
  buf = (float *)KBAlloc(0x780u, "F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 45);
  memset(dword_51A400, 0, 480u);
  for ( y = 0; y < 480; ++y )
  {
    sub_4DEFC0();
    buf[y] = ((double)(y % 62) / 20.0 - 0.5) * 2.0;
  }
  v15->field_125 = (int)dword_51A400;
  LODWORD(v15->field_4E) = 0;
  combatScreenRedrawRectLeft -= 10;
  combatScreenRedrawRectRight += 10;
  if ( combatScreenRedrawRectLeft < 0 )
    combatScreenRedrawRectLeft = 0;
  if ( combatScreenRedrawRectRight > 639 )
    combatScreenRedrawRectRight = 639;
  v12 = combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1;
  for ( i = 10; i < 70; i += v17 )
  {
    v18 = abs(20 - i % 40) - 10;
    v19 = (i - 10) / 10 + 1;
    if ( a4 == 2 )
    {
      v19 = 7 - v19;
    }
    else
    {
      if ( !a4 )
      {
        if ( (i - 10) / 10 == -1 )
          v19 = 5;
        else
          v19 = 8 - v19;
      }
    }
    if ( i <= 20 || i >= 60 || v18 != -3 && v18 != -1 && v18 && v18 != 1 && v18 != 3 )
    {
      memset((char *)dword_51A400 + combatScreenRedrawRectTop, 0, v12);
      for ( ya = combatScreenRedrawRectTop; combatScreenRedrawRectBot > ya; ++ya )
      {
        if ( a4 == 2 )
          v13 = ya + 2 * i - combatScreenRedrawRectBot - 20;
        else
          v13 = combatScreenRedrawRectTop + 2 * i - 20 - ya;
        v14 = v13 + 15;
        if ( v14 >= 0 )
        {
          if ( v14 < 480 )
          {
            v4 = ((double)v19 * v6 + v9) * (double)v18;
            *((_BYTE *)dword_51A400 + ya) = (signed __int64)(buf[v14] * v4);
          }
        }
      }
      if ( a4 == 1 && i >= 50 )
        memset(
          (char *)dword_51A400 + combatScreenRedrawRectTop - 1,
          127,
          (signed int)(v12 * (21 - (70 - i))) / 20 + combatScreenRedrawRectTop + 1 - (combatScreenRedrawRectTop - 1) + 1);
      if ( a4 == 2 && i < 30 )
        memset(
          (char *)dword_51A400 + combatScreenRedrawRectTop - 1,
          127,
          combatScreenRedrawRectBot - 1 - (signed int)(v12 * (i - 9)) / 20 - (combatScreenRedrawRectTop - 1) + 1);
      dword_4F7488 = 1;
      CombatManager::drawBattlefield(combatManager, 1, 0, 1, 0, a6, 1, 1);
    }
  }
  sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 500.0));
  v15->field_125 = 0;
  LODWORD(v15->field_4E) = 1;
  KBFree(dword_51A400, (int)"F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 142);
  KBFree(buf, (int)"F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 143);
  dword_51A400 = 0;
  if ( a4 != 1 )
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
}
