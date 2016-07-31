{
  int v4; // ST3C_4@78
  CreatureStack *thisa; // [sp+18h] [bp-28h]@1
  int v6; // [sp+1Ch] [bp-24h]@26
  int v7; // [sp+20h] [bp-20h]@80
  signed int i; // [sp+24h] [bp-1Ch]@47
  signed int v9; // [sp+28h] [bp-18h]@77
  signed int v10; // [sp+30h] [bp-10h]@1
  int offsetY; // [sp+34h] [bp-Ch]@26
  int v12; // [sp+38h] [bp-8h]@26
  int offsetX; // [sp+3Ch] [bp-4h]@26

  thisa = this;
  v10 = CreatureStack::getHexNeighbor(this, this->occupiedHex, a2);
  if ( thisa->owningSide == 1
    && combatManager->isCastleBattle
    && (v10 == 58 || v10 == 59 || v10 == 60 && thisa->owningSide == 1 && thisa->creature.creature_flags & 1)
    && combatManager->drawBridgePosition == 4 )
  {
    thisa->animationType = 7;
    thisa->animationFrame = 0;
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    CombatManager::animateDrawbridgeOpening(combatManager);
    a4 = 0;
  }
  dword_4F5464 = thisa->occupiedHex;
  if ( thisa->creature.creature_flags & 1 )
    dword_4F5468 = thisa->occupiedHex + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
  else
    dword_4F5468 = -1;
  dword_4F546C = v10;
  if ( thisa->creature.creature_flags & 1 )
    dword_4F5470 = v10 + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
  else
    dword_4F5470 = -1;
  dword_4F5474 = 0;
  CreatureForm::doSomething(&thisa->form, a3, a4);
  thisa->field_8A = a2;
  if ( !a4 )
  {
    combatScreenRedrawRectTop = 640;
    combatScreenRedrawRectLeft = 640;
    combatScreenRedrawRectBot = 0;
    combatScreenRedrawRectRight = 0;
    dword_4F7480 = 1;
    dword_4F7484 = 1;
    dword_4F1998 = 1;
    CreatureStack::draw(
      thisa,
      combatManager->combatGrid[thisa->occupiedHex].centerX,
      combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
      0);
    dword_4F1998 = 0;
    dword_4F7484 = 0;
    dword_4F7480 = 0;
  }
  if ( combatScreenRedrawRectLeft < 0 )
    combatScreenRedrawRectLeft = 0;
  if ( combatScreenRedrawRectTop < 0 )
    combatScreenRedrawRectTop = 0;
  if ( combatScreenRedrawRectRight > 639 )
    combatScreenRedrawRectRight = 639;
  if ( combatScreenRedrawRectBot > 442 )
    combatScreenRedrawRectBot = 442;
  offsetX = combatScreenRedrawRectLeft;
  offsetY = combatScreenRedrawRectTop;
  v12 = combatScreenRedrawRectRight;
  v6 = combatScreenRedrawRectBot;
  thisa->field_8E = 0;
  if ( a2 >= 3 )
  {
    if ( thisa->facingRight == 1 )
    {
      thisa->field_8E = 1;
      thisa->facingRight = 1 - thisa->facingRight;
      if ( thisa->creature.creature_flags & 1 )
        ++thisa->occupiedHex;
    }
  }
  else
  {
    if ( !thisa->facingRight )
    {
      thisa->field_8E = 1;
      thisa->facingRight = 1 - thisa->facingRight;
      if ( thisa->creature.creature_flags & 1 )
        --thisa->occupiedHex;
    }
  }
  if ( !a2 || a2 == 5 )
    thisa->field_6 = 0;
  if ( a2 == 2 || a2 == 3 )
    thisa->field_6 = 3;
  thisa->animationFrame = 0;
  thisa->animationType = 6;
  if ( !combatGraphicsOff )
    SoundManager::playSample(soundManager, thisa->combatSounds[0]);
  if ( !a4 )
  {
    combatManager->combatGrid[thisa->occupiedHex].unitOwner = -1;
    CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 1, 1);
    combatManager->combatGrid[thisa->occupiedHex].unitOwner = LOBYTE(combatManager->otherCurrentSideThing);
    if ( !combatGraphicsOff )
      Bitmap::blitToScreenSizedBmp(
        HeroWindowManager::instance->screenBuffer,
        combatManager->probablyBitmapForCombatScreen,
        0,
        0,
        0,
        0,
        0x280u,
        443);
    combatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
  }
  if ( !combatGraphicsOff )
  {
    for ( i = 0; thisa->form.animationLengths[6] > i; ++i )
    {
      thisa->animationFrame = i;
      if ( a4 || i )
      {
        Bitmap::blitToScreenSizedBmp(
          combatManager->probablyBitmapForCombatScreen,
          HeroWindowManager::instance->screenBuffer,
          combatScreenRedrawRectLeft,
          combatScreenRedrawRectTop,
          combatScreenRedrawRectLeft,
          combatScreenRedrawRectTop,
          combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
          combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
        if ( combatScreenRedrawRectLeft < 0 )
          combatScreenRedrawRectLeft = 0;
        if ( combatScreenRedrawRectTop < 0 )
          combatScreenRedrawRectTop = 0;
        if ( combatScreenRedrawRectRight > 639 )
          combatScreenRedrawRectRight = 639;
        if ( combatScreenRedrawRectBot > 442 )
          combatScreenRedrawRectBot = 442;
        offsetX = combatScreenRedrawRectLeft;
        offsetY = combatScreenRedrawRectTop;
        v12 = combatScreenRedrawRectRight;
        v6 = combatScreenRedrawRectBot;
      }
      combatScreenRedrawRectTop = 640;
      combatScreenRedrawRectLeft = 640;
      combatScreenRedrawRectBot = 0;
      combatScreenRedrawRectRight = 0;
      dword_4F7480 = 1;
      dword_4F7484 = 1;
      dword_4F1998 = 1;
      CreatureStack::draw(
        thisa,
        combatManager->combatGrid[thisa->occupiedHex].centerX,
        combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
        0);
      dword_4F1998 = 0;
      dword_4F7480 = 0;
      dword_4F7484 = 0;
      if ( combatScreenRedrawRectLeft < 0 )
        combatScreenRedrawRectLeft = 0;
      if ( combatScreenRedrawRectTop < 0 )
        combatScreenRedrawRectTop = 0;
      if ( combatScreenRedrawRectRight > 639 )
        combatScreenRedrawRectRight = 639;
      if ( combatScreenRedrawRectBot > 442 )
        combatScreenRedrawRectBot = 442;
      dword_4F748C = 0;
      dword_4F7480 = 1;
      dword_4F7488 = 1;
      thisa->field_11D = 0;
      CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 0, 1);
      thisa->field_11D = 1;
      dword_4F7488 = 0;
      dword_4F7480 = 0;
      dword_4F748C = 1;
      if ( combatScreenRedrawRectLeft < offsetX )
        offsetX = combatScreenRedrawRectLeft;
      if ( offsetY > combatScreenRedrawRectTop )
        offsetY = combatScreenRedrawRectTop;
      if ( combatScreenRedrawRectRight > v12 )
        v12 = combatScreenRedrawRectRight;
      if ( combatScreenRedrawRectBot > v6 )
        v6 = combatScreenRedrawRectBot;
      sleepUntilPointer(&animationFrameSwitchTime);
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + (double)thisa->form.field_A2
                                                * combatSpeedPercentages[*(_DWORD *)&combatSpeed]
                                                / (double)thisa->form.animationLengths[6]);
      HeroWindowManager::redrawRectangle(
        HeroWindowManager::instance,
        offsetX,
        offsetY,
        v12 - offsetX + 1,
        v6 - offsetY + 1);
    }
  }
  v9 = CreatureStack::getHexNeighbor(thisa, thisa->occupiedHex, a2);
  combatManager->combatGrid[thisa->occupiedHex].stackIdx = -1;
  combatManager->combatGrid[thisa->occupiedHex].unitOwner = -1;
  combatManager->combatGrid[thisa->occupiedHex].notPrimarySquareOfTwoHexer = -1;
  if ( thisa->creature.creature_flags & 1 )
  {
    v4 = thisa->occupiedHex + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
    combatManager->combatGrid[v4].stackIdx = -1;
    combatManager->combatGrid[v4].unitOwner = -1;
    combatManager->combatGrid[v4].notPrimarySquareOfTwoHexer = -1;
  }
  combatManager->combatGrid[v9].unitOwner = LOBYTE(thisa->owningSide);
  combatManager->combatGrid[v9].stackIdx = LOBYTE(thisa->stackIdx);
  combatManager->combatGrid[v9].notPrimarySquareOfTwoHexer = -1;
  if ( thisa->creature.creature_flags & 1 )
  {
    v7 = v9 + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
    combatManager->combatGrid[v7].unitOwner = LOBYTE(thisa->owningSide);
    combatManager->combatGrid[v7].stackIdx = LOBYTE(thisa->stackIdx);
    combatManager->combatGrid[v7].notPrimarySquareOfTwoHexer = v9 <= v7;
    combatManager->combatGrid[v9].notPrimarySquareOfTwoHexer = v9 >= v7;
  }
  thisa->occupiedHex = v9;
  if ( thisa->field_8E )
  {
    thisa->facingRight = 1 - thisa->facingRight;
    if ( thisa->creature.creature_flags & TWO_HEXER )
    {
      if ( thisa->facingRight )
        --thisa->occupiedHex;
      else
        ++thisa->occupiedHex;
    }
    thisa->field_8E = 0;
  }
  dword_4F5464 = -1;
  dword_4F5468 = -1;
  dword_4F546C = -1;
  dword_4F5470 = -1;
  thisa->field_6 = 1;
  if ( a3 == 1 )
  {
    thisa->animationType = 7;
    thisa->animationFrame = 0;
    CombatManager::drawBattlefield(combatManager, 1, 1, 0, 0, 75, 1, 1);
  }
}
