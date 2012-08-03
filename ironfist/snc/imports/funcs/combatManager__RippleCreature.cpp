{
  float v4; // ST40_4@39
  float v6; // [sp+28h] [bp-40h]@2
  signed int a6; // [sp+30h] [bp-38h]@2
  signed int i; // [sp+38h] [bp-30h]@15
  float v9; // [sp+3Ch] [bp-2Ch]@2
  signed int y; // [sp+40h] [bp-28h]@8
  int ya; // [sp+40h] [bp-28h]@32
  unsigned int v12; // [sp+4Ch] [bp-1Ch]@15
  int v13; // [sp+50h] [bp-18h]@35
  int v14; // [sp+50h] [bp-18h]@37
  army *v15; // [sp+54h] [bp-14h]@1
  float *buf; // [sp+58h] [bp-10h]@8
  signed int v17; // [sp+5Ch] [bp-Ch]@2
  int v18; // [sp+60h] [bp-8h]@18
  int v19; // [sp+64h] [bp-4h]@18

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
  combatManager::ResetLimitCreature(this);
  ++this->stuffHappenedToCreature[side][stackIdx];
  if ( a4 == 2 )
    combatManager::DrawFrame(gpCombatManager, 0, 1, 1, 0, 75, 1, 1);
  else
    combatManager::DrawFrame(gpCombatManager, 1, 1, 1, 0, 75, 1, 1);
  gyModify = BaseAlloc(480u, "F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 44);
  buf = (float *)BaseAlloc(0x780u, "F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 45);
  memset(gyModify, 0u, 480u);
  for ( y = 0; y < 480; ++y )
    buf[y] = (sin((double)(y % 62) / 20.0) - 0.5) * 2.0;
  v15->field_125 = gyModify;
  LODWORD(v15->field_4E) = 0;
  giMinExtentX -= 10;
  giMaxExtentX += 10;
  if ( giMinExtentX < 0 )
    giMinExtentX = 0;
  if ( giMaxExtentX > 639 )
    giMaxExtentX = 639;
  v12 = giMaxExtentY - giMinExtentY + 1;
  for ( i = 10; i < 70; i += v17 )
  {
    v18 = abs(20 - i % 40) - 10;
    v19 = (i - 10) / 10 + 1;
    if ( a4 == 2 )
    {
      v19 = 7 - v19;
    }
    else if ( !a4 )
    {
      if ( (i - 10) / 10 == -1 )
        v19 = 5;
      else
        v19 = 8 - v19;
    }
    if ( i <= 20 || i >= 60 || v18 != -3 && v18 != -1 && v18 && v18 != 1 && v18 != 3 )
    {
      memset((char *)gyModify + giMinExtentY, 0, v12);
      for ( ya = giMinExtentY; giMaxExtentY > ya; ++ya )
      {
        if ( a4 == 2 )
          v13 = ya + 2 * i - giMaxExtentY - 20;
        else
          v13 = giMinExtentY + 2 * i - 20 - ya;
        v14 = v13 + 15;
        if ( v14 >= 0 )
        {
          if ( v14 < 480 )
          {
            v4 = ((double)v19 * v6 + v9) * (double)v18;
            *((_BYTE *)gyModify + ya) = (signed __int64)(buf[v14] * v4);
          }
        }
      }
      if ( a4 == 1 && i >= 50 )
        memset(
          (char *)gyModify + giMinExtentY - 1,
          0x7Fu,
          (signed int)(v12 * (21 - (70 - i))) / 20 + giMinExtentY + 1 - (giMinExtentY - 1) + 1);
      if ( a4 == 2 && i < 30 )
        memset(
          (char *)gyModify + giMinExtentY - 1,
          0x7Fu,
          giMaxExtentY - 1 - (signed int)(v12 * (i - 9)) / 20 - (giMinExtentY - 1) + 1);
      gbLimitToExtent = 1;
      combatManager::DrawFrame(gpCombatManager, 1, 0, 1, 0, a6, 1, 1);
    }
  }
  DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 500.0));
  v15->field_125 = NULL;
  LODWORD(v15->field_4E) = 1;
  BaseFree(gyModify, (int)"F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 142);
  BaseFree(buf, (int)"F:\\h2xsrc\\Source\\SPELLS.CPP", twoFiveEightSeven + 143);
  gyModify = 0;
  if ( a4 != 1 )
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
}