{
  int v8; // ecx@127
  int v9; // ST50_4@148
  int v10; // eax@146
  CombatManager *thisa; // [sp+20h] [bp-C8h]@1
  int offsetX; // [sp+24h] [bp-C4h]@22
  int offsetY; // [sp+28h] [bp-C0h]@19
  int offY; // [sp+34h] [bp-B4h]@96
  int imageIdx; // [sp+38h] [bp-B0h]@96
  int offX; // [sp+3Ch] [bp-ACh]@96
  unsigned __int8 v17[7]; // [sp+44h] [bp-A4h]@94
  Point16 v18[6][4]; // [sp+4Ch] [bp-9Ch]@94
  int v19; // [sp+ACh] [bp-3Ch]@151
  int colBound; // [sp+B0h] [bp-38h]@55
  int v21; // [sp+B4h] [bp-34h]@72
  int deltaX; // [sp+B8h] [bp-30h]@55
  int colStart; // [sp+BCh] [bp-2Ch]@55
  int i; // [sp+C0h] [bp-28h]@7
  int v25; // [sp+D4h] [bp-14h]@5
  int l; // [sp+DCh] [bp-Ch]@5
  int j; // [sp+E0h] [bp-8h]@47
  int k; // [sp+E4h] [bp-4h]@78

  thisa = this;
  if ( this->field_F357 || combatGraphicsOff || !this->checkedInsub4c3d60 )
    return;
  yieldToGlobalUpdater();
  mouseManager->couldBeShowMouse = 0;
  if ( a3 )
  {
    v25 = 0;
    for ( l = 0; l < 2; ++l )
    {
      for ( i = 0; i < 20; ++i )
      {
        if ( thisa->stuffHappenedToCreature[l][i] > 0 )
        {
          v25 = 1;
          dword_4F7480 = 1;
          dword_4F7484 = 1;
          dword_4F1998 = 1;
          CreatureStack::draw(
            &thisa->creatures[l][i],
            thisa->combatGrid[thisa->creatures[l][i].occupiedHex].centerX,
            thisa->combatGrid[thisa->creatures[l][i].occupiedHex].occupyingCreatureBottomY,
            0);
          dword_4F1998 = 0;
          dword_4F7480 = 0;
          dword_4F7484 = 0;
        }
      }
    }
    for ( l = 0; l < 2; ++l )
    {
      if ( *(&thisa->field_F41F + l) )
      {
        v25 = 1;
        dword_4F7480 = 1;
        dword_4F7484 = 1;
        dword_4F1998 = 1;
        Icon::drawToScreenAndSetRectBounds(
          thisa->heroIcon[l],
          (unsigned int)l < 1 ? 30 : 610,
          (unsigned int)l < 1 ? 183 : 148,
          *(&byte_4F4C30[thisa->heroType[l]][9 * thisa->heroIconIdxRelated[l] + 13]
          + thisa->countRelatedToSpellAnimation[l]),
          &thisa->heroBounds[l],
          1,
          0,
          0,
          0);
        dword_4F1998 = 0;
        dword_4F7480 = 0;
        dword_4F7484 = 0;
      }
      if ( thisa->field_F427[l] )
      {
        v25 = 1;
        dword_4F7480 = 1;
        dword_4F7484 = 1;
        dword_4F1998 = 1;
        if ( l )
          offsetY = ((((unsigned int)thisa->heroes[l]->field_E7[0] < 1) - 1) & 0xFFFFFFF3) + 148;
        else
          offsetY = 183;
        if ( l )
          offsetX = ((((unsigned int)thisa->heroes[l]->field_E7[0] < 1) - 1) & 5) + 610;
        else
          offsetX = 30;
        Icon::drawToScreenAndSetRectBounds(
          thisa->heroFlagIcon[l],
          offsetX,
          offsetY,
          thisa->heroFlagIconIdx[l],
          &thisa->heroFlagBounds[l],
          1,
          0,
          0,
          0);
        dword_4F1998 = 0;
        dword_4F7480 = 0;
        dword_4F7484 = 0;
      }
    }
    if ( a5 || !v25 )
      goto LABEL_168;
    --combatScreenRedrawRectLeft;
    --combatScreenRedrawRectTop;
    ++combatScreenRedrawRectRight;
    ++combatScreenRedrawRectBot;
    if ( combatScreenRedrawRectLeft < 0 )
      combatScreenRedrawRectLeft = 0;
    if ( combatScreenRedrawRectTop < 0 )
      combatScreenRedrawRectTop = 0;
    if ( combatScreenRedrawRectRight > 639 )
      combatScreenRedrawRectRight = 639;
    if ( combatScreenRedrawRectBot > 442 )
      combatScreenRedrawRectBot = 442;
  }
  if ( a7 )
  {
    if ( thisa->zeroedAfterAnimatingDeathAndHolySpells )
    {
      if ( a3 || a4 || dword_4F7488 )
        Bitmap::blitToScreenSizedBmp(
          thisa->probablyBitmapForCombatScreen,
          HeroWindowManager::instance->screenBuffer,
          combatScreenRedrawRectLeft,
          combatScreenRedrawRectTop,
          combatScreenRedrawRectLeft,
          combatScreenRedrawRectTop,
          combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
          combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      else
        Bitmap::blitToScreenSizedBmp(
          thisa->probablyBitmapForCombatScreen,
          HeroWindowManager::instance->screenBuffer,
          0,
          0,
          0,
          0,
          640u,
          443);
    }
    else
    {
      CombatManager::drawBackground(thisa);
    }
  }
  if ( a3 )
  {
    dword_4F7488 = 1;
    dword_4F7480 = 1;
  }
  for ( j = 0; j < 9; ++j )                     // row by row to get perspective right
  {
    if ( j == 1 && thisa->heroes[1] )
    {
      Icon::drawToScreenAndSetRectBounds(
        thisa->heroIcon[1],
        ((((unsigned int)thisa->heroes[1]->field_E7[0] < 1) - 1) & 5) + 610,
        ((((unsigned int)thisa->heroes[1]->field_E7[0] < 1) - 1) & 0xFFFFFFF3) + 148,
        *(&byte_4F4C30[thisa->heroType[1]][9 * thisa->heroIconIdxRelated[1] + 13]
        + thisa->countRelatedToSpellAnimation[1]),
        &thisa->heroBounds[1],
        1,
        0,
        0,
        0);
      Icon::drawToScreenAndSetRectBounds(
        thisa->heroFlagIcon[1],
        610,
        148,
        thisa->heroFlagIconIdx[1],
        &thisa->heroFlagBounds[1],
        1,
        0,
        0,
        0);
    }
    if ( j == 2 && thisa->heroes[0] )
    {
      Icon::drawToScreenAndSetRectBounds(
        thisa->heroIcon[0],
        30,
        183,
        *(&byte_4F4C30[thisa->heroType[0]][9 * thisa->heroIconIdxRelated[0] + 13]
        + thisa->countRelatedToSpellAnimation[0]),
        thisa->heroBounds,
        0,
        0,
        0,
        0);
      Icon::drawToScreenAndSetRectBounds(
        thisa->heroFlagIcon[0],
        30,
        183,
        thisa->heroFlagIconIdx[0],
        thisa->heroFlagBounds,
        0,
        0,
        0,
        0);
    }
    colStart = 1;
    colBound = 12;
    deltaX = 1;
    if ( thisa->isCastleBattle && j >= 5 )
    {
      colStart = 11;
      colBound = 0;
      deltaX = -1;
    }
    if ( thisa->isCastleBattle && j == 7 )
      Icon::drawToScreenAndSetRectBounds(
        thisa->combatScreenIcons[3],
        22,
        390,
        thisa->probablyCatapultImgIdx[0],
        &thisa->catapultBounds,
        0,
        0,
        0,
        0);
    if ( thisa->isCastleBattle && j == 4 && thisa->drawBridgePosition != 4 )
      Icon::drawToScreenAndSetRectBounds(
        thisa->combatScreenIcons[5],
        0,
        0,
        thisa->drawBridgePosition + 21,
        &thisa->drawbridgeBounds,
        0,
        0,
        0,
        0);
    if ( thisa->isCastleBattle && j == 5 && !thisa->drawBridgePosition )
      Icon::drawToScreenAndSetRectBounds(thisa->combatScreenIcons[5], 0, 0, 25, &thisa->field_F303, 0, 0, 0, 0);
    if ( thisa->isCastleBattle && j == 6 )
      Icon::drawToScreenAndSetRectBounds(
        thisa->combatScreenIcons[5],
        0,
        0,
        (unsigned int)thisa->ballistaDestroyed < 1 ? 20 : 26,
        &thisa->ballistaBounds,
        0,
        0,
        0,
        0);
    v21 = 0;
    if ( thisa->isCastleBattle && thisa->wallStatus[3] != 2 && thisa->wallStatus[3] != 6 )
    {
      v21 = 1;
      for ( l = 0; l < 4; ++l )
      {
        sub_4BD680(&thisa->combatGrid[114], l, 0);
        sub_4BD680(&thisa->combatGrid[115], l, 0);
      }
    }
    for ( k = colStart; k != colBound; k += deltaX )
      CombatHexTile::drawNonTopmostCorpses(&thisa->combatGrid[13 * j] + k);
    for ( k = colStart; k != colBound; k += deltaX )
      CombatHexTile::drawTopmostCorpse(&thisa->combatGrid[13 * j] + k);
    for ( l = 0; l < 4; ++l )
    {
      if ( l == 1 )
      {
        for ( k = colStart; k != colBound; k += deltaX )
        {
          if ( thisa->combatGrid[k + 13 * j].combatObjIdx != -1 )
            CombatHexTile::drawCombatObj(&thisa->combatGrid[13 * j] + k);
        }
      }
      for ( k = colStart; k != colBound; k += deltaX )
      {
        v18[0][0].x = 443;
        v18[0][0].y = 153;
        v18[0][1].x = 399;
        v18[0][1].y = 237;
        v18[0][2].x = 399;
        v18[0][2].y = 321;
        v18[0][3].x = 443;
        v18[0][3].y = 405;
        v18[1][0].x = 443;
        v18[1][0].y = 153;
        v18[1][1].x = 399;
        v18[1][1].y = 237;
        v18[1][2].x = 399;
        v18[1][2].y = 321;
        v18[1][3].x = 443;
        v18[1][3].y = 405;
        v18[2][0].x = 443;
        v18[2][0].y = 153;
        v18[2][1].x = 399;
        v18[2][1].y = 237;
        v18[2][2].x = 399;
        v18[2][2].y = 321;
        v18[2][3].x = 443;
        v18[2][3].y = 405;
        v18[3][0].x = 443;
        v18[3][0].y = 153;
        v18[3][1].x = 399;
        v18[3][1].y = 237;
        v18[3][2].x = 399;
        v18[3][2].y = 321;
        v18[3][3].x = 443;
        v18[3][3].y = 405;
        v18[4][0].x = 443;
        v18[4][0].y = 153;
        v18[4][1].x = 399;
        v18[4][1].y = 237;
        v18[4][2].x = 399;
        v18[4][2].y = 321;
        v18[4][3].x = 443;
        v18[4][3].y = 405;
        v18[5][0].x = 443;
        v18[5][0].y = 153;
        v18[5][1].x = 399;
        v18[5][1].y = 237;
        v18[5][2].x = 399;
        v18[5][2].y = 321;
        v18[5][3].x = 443;
        v18[5][3].y = 405;
        v17[0] = 0;
        v17[1] = 4;
        v17[2] = 8;
        v17[3] = 23;
        v17[4] = 27;
        v17[5] = 35;
        v17[6] = 31;
        if ( thisa->isCastleBattle && !l )
        {
          imageIdx = 0;
          offX = 0;
          offY = 0;
          switch ( k + 13 * j )
          {
            case 9:
              imageIdx = v17[thisa->wallStatus[0]] + 5;
              break;
            case 34:
              imageIdx = v17[thisa->wallStatus[1]] + 6;
              break;
            case 86:
              imageIdx = v17[thisa->wallStatus[2]] + 7;
              break;
            case 113:
              imageIdx = v17[thisa->wallStatus[3]] + 8;
              break;
            case 22:
              imageIdx = thisa->turretStatus[0] + 17;
              offX = *(_DWORD *)v18[thisa->castles[1]->factionID] & 0xFFFF;
              offY = v18[thisa->castles[1]->factionID][0].y;
              break;
            case 47:
              imageIdx = thisa->turretStatus[1] + 17;
              offX = v18[thisa->castles[1]->factionID][1].x;
              offY = v18[thisa->castles[1]->factionID][1].y;
              break;
            case 73:
              imageIdx = thisa->turretStatus[2] + 17;
              offX = v18[thisa->castles[1]->factionID][2].x;
              offY = v18[thisa->castles[1]->factionID][2].y;
              break;
            case 100:
              imageIdx = thisa->turretStatus[3] + 17;
              offX = v18[thisa->castles[1]->factionID][3].x;
              offY = v18[thisa->castles[1]->factionID][3].y;
              break;
            case 59:
              if ( thisa->drawBridgePosition != 3 )
                imageIdx = 4;
              break;
            default:
              break;
          }
          if ( imageIdx )
            Icon::drawToScreenAndSetRectBounds(
              thisa->combatScreenIcons[5],
              offX,
              offY,
              imageIdx,
              (H2RECT *)((char *)&thisa->combatGrid[13 * j].drawingBounds + 98 * k),
              0,
              0,
              0,
              0);
        }
        if ( !v21 || k + 13 * j != 114 && k + 13 * j != 115 )
          sub_4BD680(&thisa->combatGrid[13 * j] + k, l, 0);
      }
    }
    if ( thisa->isCastleBattle
      && BYTE1(thisa->castles[1]->buildingsBuiltFlags) & 0x10
      && (j != 4 || thisa->drawBridgePosition == 4) )
    {
      if ( moatHexes[j] != dword_4F546C
        && moatHexes[j] != dword_4F5470
        && moatHexes[j] != dword_4F5464
        && moatHexes[j] != dword_4F5468 )
      {
        if ( thisa->combatGrid[moatHexes[j]].unitOwner != -1 )
          goto LABEL_150;
      }
      else
      {
        if ( abs(dword_4F546C - dword_4F5464) <= 1 )
          goto LABEL_150;
        v8 = dword_4F5464 / 13;
        if ( dword_4F5464 / 13 <= dword_4F546C / 13 )
          v8 = dword_4F546C / 13;
        if ( v8 == j )
        {
          if ( combatManager->drawBridgePosition == 4 || dword_4F546C / 13 != 4 && dword_4F5464 / 13 != 4 )
          {
            v10 = dword_4F5464;
            if ( dword_4F5464 <= dword_4F546C )
              v10 = dword_4F546C;
            v9 = dword_4F5474 + thisa->combatGrid[dword_4F5464].occupyingCreatureBottomY - 9;
            rasterize(
              thisa->combatScreenIcons[14],
              HeroWindowManager::instance->screenBuffer,
              0,
              0,
              0,
              1,
              0,
              v9,
              0x280u,
              thisa->combatGrid[v10].occupyingCreatureBottomY + 5 - v9 + 1,
              0);
          }
          else
          {
            if ( (dword_4F546C / 13 != 4 || dword_4F5464 / 13 != 3)
              && (dword_4F546C / 13 != 3 || dword_4F5464 / 13 != 4) )
            {
              if ( dword_4F5464 <= dword_4F546C )
              {
                if ( moatHexes[j] == dword_4F546C || moatHexes[j] == dword_4F5470 )
                {
LABEL_150:
                  Icon::drawToScreenAndSetRectBounds(
                    thisa->combatScreenIcons[13],
                    0,
                    0,
                    j,
                    &thisa->moatPartBounds[j],
                    0,
                    0,
                    0,
                    0);
                  sub_4BD680((CombatHexTile *)&thisa->field_49F[98 * moatHexes[j] + 19], 100, 1);
                  sub_4BD680(&thisa->combatGrid[moatHexes[j]], 100, 1);
                  sub_4BD680(&thisa->combatGrid[moatHexes[j] + 1], 100, 1);
                  goto LABEL_151;
                }
              }
              else
              {
                if ( moatHexes[j] == dword_4F5464 || moatHexes[j] == dword_4F5468 )
                  goto LABEL_150;
              }
            }
          }
        }
      }
    }
LABEL_151:
    v19 = 0;
  }
  if ( *(_DWORD *)&combatArmyInfoLevel > 0 && *(_DWORD *)&thisa->_15[100] != -1 )
  {
    sub_4C66F0(thisa, 0, 0);
    sub_4C66F0(thisa, 1, 0);
  }
  mouseManager->couldBeShowMouse = 1;
  yieldToGlobalUpdater();
  if ( a3 || a4 )
  {
    dword_4F7488 = 0;
    dword_4F7480 = 0;
    if ( waitUntilItIsTime )
      sleepUntilPointer(&animationFrameSwitchTime);
    animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                              + (double)a6 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
    dword_4F745C = 0;
    if ( redrawAll == 1 )
    {
      if ( combatScreenRedrawRectBot > 442 )
        combatScreenRedrawRectBot = 442;
      fullScreenRelated = 0;
      HeroWindowManager::redrawRectangle(
        HeroWindowManager::instance,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
        combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      fullScreenRelated = 1;
    }
  }
  else
  {
    if ( redrawAll == 1 )
    {
      if ( waitUntilItIsTime )
        sleepUntilPointer(&animationFrameSwitchTime);
      dword_4F745C = 1;
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + (double)a6 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
      sub_4C3D60(thisa);
    }
  }
LABEL_168:
  mouseManager->couldBeShowMouse = 1;
  yieldToGlobalUpdater();
}
