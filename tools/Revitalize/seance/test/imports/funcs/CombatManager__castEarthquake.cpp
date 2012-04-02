{
  int v1; // eax@5
  int v2; // eax@7
  int v3; // ecx@7
  CombatManager *thisa; // [sp+14h] [bp-158h]@1
  int v5; // [sp+18h] [bp-154h]@13
  int v6; // [sp+1Ch] [bp-150h]@10
  Icon *res; // [sp+20h] [bp-14Ch]@45
  const void *v8; // [sp+24h] [bp-148h]@9
  void *v9; // [sp+28h] [bp-144h]@15
  int a3; // [sp+30h] [bp-13Ch]@31
  int a4[19]; // [sp+34h] [bp-138h]@31
  int v12; // [sp+80h] [bp-ECh]@20
  int i; // [sp+84h] [bp-E8h]@1
  int v14[4]; // [sp+88h] [bp-E4h]@34
  int m; // [sp+98h] [bp-D4h]@47
  int k; // [sp+9Ch] [bp-D0h]@15
  int l; // [sp+A0h] [bp-CCh]@20
  int v18; // [sp+A8h] [bp-C4h]@5
  int j; // [sp+ACh] [bp-C0h]@3
  int v20; // [sp+B0h] [bp-BCh]@5
  int v21[10]; // [sp+B4h] [bp-B8h]@43
  int v22; // [sp+DCh] [bp-90h]@38
  int v23[4]; // [sp+E0h] [bp-8Ch]@22
  size_t v24; // [sp+F0h] [bp-7Ch]@5
  int v25[30]; // [sp+F4h] [bp-78h]@1

  thisa = this;
  v25[0] = 2;
  v25[1] = 2;
  v25[2] = 4;
  v25[3] = 1;
  v25[4] = 3;
  v25[5] = -2;
  v25[6] = 0;
  v25[7] = -6;
  v25[8] = 2;
  v25[9] = -2;
  v25[10] = -1;
  v25[11] = 3;
  v25[12] = -5;
  v25[13] = 4;
  v25[14] = -8;
  v25[15] = 6;
  v25[16] = -4;
  v25[17] = 2;
  v25[18] = -1;
  v25[19] = 1;
  v25[20] = -3;
  v25[21] = -3;
  v25[22] = -7;
  v25[23] = -5;
  v25[24] = -5;
  v25[25] = -7;
  v25[26] = -2;
  v25[27] = -3;
  v25[28] = 0;
  v25[29] = 0;
  MouseManager::disableCursor(mouseManager);
  memcpy(thisa->probablyBitmapForCombatScreen->contents, HeroWindowManager::instance->screenBuffer->contents, 0x45380u);
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 0; j < 15; ++j )
    {
      v20 = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 15.0);
      yieldToGlobalUpdater();
      v24 = 640 - abs(v25[2 * j]);
      v18 = 443 - abs(v25[2 * j + 1]) - 1;
      v1 = v25[2 * j + 1];
      if ( v1 <= 0 )
        v1 = 0;
      v2 = 640 * v1;
      v3 = v25[2 * j];
      if ( v3 <= 0 )
        v3 = 0;
      v8 = &thisa->probablyBitmapForCombatScreen->contents[v3] + v2;
      if ( v25[2 * j] <= 0 )
        v6 = -v25[2 * j];
      else
        v6 = 0;
      if ( v25[2 * j + 1] <= 0 )
        v5 = -v25[2 * j + 1];
      else
        v5 = 0;
      v9 = &HeroWindowManager::instance->screenBuffer->contents[640 * v5] + v6;
      for ( k = 0; v18 > k; ++k )
      {
        memcpy(v9, v8, v24);
        v8 = (char *)v8 + 640;
        v9 = (char *)v9 + 640;
      }
      renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 443, 0, 0);
      sleepUntilPointer(&v20);
    }
  }
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  v12 = 0;
  for ( l = 0; l < 4; ++l )
  {
    v23[l] = thisa->wallStatus[l];
    if ( thisa->wallStatus[l] != 2 && thisa->wallStatus[l] != 6 && nextRandomInt(0, 100) < 75 )
    {
      ++v23[l];
      if ( thisa->wallStatus[l] != 2
        && thisa->wallStatus[l] != 1
        && thisa->wallStatus[l] != 6
        && thisa->wallStatus[l] != 5
        && nextRandomInt(0, 100) < 15 )
        ++v23[l];
      *(&a3 + 2 * v12) = wallAttackPointsForCatapult[l].x;
      a4[2 * v12++] = wallAttackPointsForCatapult[l].y + 25;
      if ( v23[l] == 2 || v23[l] == 6 )
        thisa->combatGrid[byte_4F4C30[11][l + 121]].probablyIsBlocked = 0;
    }
    v14[l] = thisa->turretStatus[l];
    if ( thisa->turretStatus[l] != 2 && nextRandomInt(0, 100) < 50 )
    {
      v14[l] = 2;
      *(&a3 + 2 * v12) = turretAttackPointsForCatapult[l].x;
      a4[2 * v12++] = turretAttackPointsForCatapult[l].y + 25;
    }
  }
  v22 = thisa->drawBridgePosition;
  if ( thisa->drawBridgePosition != 3 && nextRandomInt(0, 100) < 25 )
  {
    v22 = 3;
    *(&a3 + 2 * v12) = turretAttackPointsForCatapult[0].x;
    a4[2 * v12++] = (unsigned __int16)turretAttackPointsForCatapult[0].y + 25;
    *(&a3 + 2 * v12) = turretAttackPointsForCatapult[1].x;
    a4[2 * v12++] = (unsigned __int16)turretAttackPointsForCatapult[1].y + 25;
  }
  for ( l = 0; l < 10; ++l )
    v21[l] = unseededNextRand(0, 2);
  combatScreenRedrawRectLeft = 252;
  combatScreenRedrawRectTop = 0;
  combatScreenRedrawRectRight = 575;
  combatScreenRedrawRectBot = 442;
  if ( v12 )
  {
    res = ResourceManager::getIconByFilename(resourceManager, "lichclod.icn");
    for ( l = 0; l < 13; ++l )
    {
      animTimer = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 75.0);
      CombatManager::drawBattlefield(thisa, 0, 0, 1, 0, 0, 1, 0);
      for ( m = 0; m < v12; ++m )
      {
        if ( v21[m] <= l && l - v21[m] < 10 )
          rasterize(
            res,
            HeroWindowManager::instance->screenBuffer,
            *(&a3 + 2 * m),
            a4[2 * m],
            l - v21[m],
            1,
            0,
            0,
            0x280u,
            443,
            0);
      }
      HeroWindowManager::redrawRectangle(
        HeroWindowManager::instance,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
        combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      sleepUntilPointer(&animTimer);
      if ( l == 7 )
      {
        for ( m = 0; m < 4; ++m )
        {
          thisa->wallStatus[m] = LOBYTE(v23[m]);
          thisa->turretStatus[m] = LOBYTE(v14[m]);
        }
        thisa->drawBridgePosition = v22;
      }
    }
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
  }
  MouseManager::enableCursor(mouseManager);
}
