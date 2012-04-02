{
  signed int result; // eax@2
  int v3; // ST98_4@19
  CreatureStack *thisa; // [sp+60h] [bp-74h]@1
  signed int v5; // [sp+64h] [bp-70h]@76
  signed int v6; // [sp+68h] [bp-6Ch]@47
  int v7; // [sp+6Ch] [bp-68h]@21
  int v8; // [sp+70h] [bp-64h]@24
  int offsetY; // [sp+74h] [bp-60h]@47
  signed int v10; // [sp+78h] [bp-5Ch]@47
  int offsetX; // [sp+7Ch] [bp-58h]@47
  signed int v12; // [sp+80h] [bp-54h]@24
  int v13; // [sp+8Ch] [bp-48h]@14
  signed int v14; // [sp+90h] [bp-44h]@14
  int v15; // [sp+94h] [bp-40h]@14
  float v16; // [sp+98h] [bp-3Ch]@18
  int i; // [sp+A0h] [bp-34h]@21
  int colDiff; // [sp+A4h] [bp-30h]@3
  signed int v19; // [sp+A8h] [bp-2Ch]@14
  int v20; // [sp+ACh] [bp-28h]@14
  int v21; // [sp+BCh] [bp-18h]@14
  float v22; // [sp+C4h] [bp-10h]@14
  float v23; // [sp+CCh] [bp-8h]@14
  float v24; // [sp+D0h] [bp-4h]@18

  thisa = this;
  if ( checkHexGridIdxBounds(hexIdx) )
  {
    colDiff = hexIdx % 13 - thisa->occupiedHex % 13;
    thisa->field_8E = 0;
    if ( colDiff <= 0 || thisa->facingRight )
    {
      if ( colDiff < 0 )
      {
        if ( thisa->facingRight == 1 )
        {
          thisa->field_8E = 1;
          thisa->facingRight = 1 - thisa->facingRight;
          if ( thisa->creature.creature_flags & TWO_HEXER )
          {
            ++thisa->occupiedHex;
            ++hexIdx;
          }
        }
      }
    }
    else
    {
      thisa->field_8E = 1;
      thisa->facingRight = 1 - thisa->facingRight;
      if ( thisa->creature.creature_flags & TWO_HEXER )
      {
        --thisa->occupiedHex;
        --hexIdx;
      }
    }
    if ( thisa->field_8E )
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    v19 = combatManager->combatGrid[thisa->occupiedHex].centerX;
    v14 = combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY;
    v23 = (double)v19;
    v22 = (double)v14;
    v20 = combatManager->combatGrid[hexIdx].centerX - v19;
    v15 = combatManager->combatGrid[hexIdx].occupyingCreatureBottomY - v14;
    v13 = (signed __int64)sqrt((double)(v15 * v15 + v20 * v20));
    v21 = 0;
    if ( *(_DWORD *)&thisa->form.field_AA[0] > 0 )
      v21 = (v13 + (*(_DWORD *)&thisa->form.field_AA[0] >> 1)) / *(_DWORD *)&thisa->form.field_AA[0];
    if ( v21 <= 0 )
      v21 = 1;
    v16 = (double)v20 / (double)v21;
    v24 = (double)v15 / (double)v21;
    combatManager->combatGrid[thisa->occupiedHex].stackIdx = -1;
    combatManager->combatGrid[thisa->occupiedHex].unitOwner = -1;
    combatManager->combatGrid[thisa->occupiedHex].notPrimarySquareOfTwoHexer = -1;
    if ( thisa->creature.creature_flags & TWO_HEXER )
    {
      v3 = thisa->occupiedHex + (thisa->facingRight < 1u ? -1 : 1);
      combatManager->combatGrid[v3].stackIdx = -1;
      combatManager->combatGrid[v3].unitOwner = -1;
      combatManager->combatGrid[v3].notPrimarySquareOfTwoHexer = -1;
    }
    if ( !combatGraphicsOff )
    {
      v7 = 0;
      CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 1, 1);
      Bitmap::blitToScreenSizedBmp(
        heroWindowManager->screenBuffer,
        combatManager->probablyBitmapForCombatScreen,
        0,
        0,
        0,
        0,
        0x280u,
        442);
      combatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
      thisa->animationType = 6;
      for ( i = 0; v21 > i; ++i )
      {
        CreatureForm::doSomething(&thisa->form, i + 1 == v21, i > 0);
        if ( v21 )
        {
          if ( i <= 0 )
            v8 = thisa->form.animationLengths[0];
          else
            v8 = 0;
          v12 = thisa->form.animationLengths[2];
          v7 = thisa->form.animationLengths[2];
          if ( i + 1 < v21 )
            v12 += thisa->form.animationLengths[3];
        }
        else
        {
          v12 = thisa->form.animationLengths[6];
          v8 = 0;
        }
        for ( thisa->animationFrame = 0; thisa->form.animationLengths[6] > thisa->animationFrame; ++thisa->animationFrame )
        {
          if ( thisa->animationFrame >= v8 && v8 + v12 > thisa->animationFrame )
          {
            v23 = v16 / (double)v12 + v23;
            v22 = v24 / (double)v12 + v22;
          }
          if ( thisa->animationFrame % thisa->form.animationLengths[6] == 1 )
          {
            if ( thisa->creatureIdx != 52 && thisa->creatureIdx != 53 || i )
            {
              if ( thisa->creatureIdx != 52 && thisa->creatureIdx != 53 || v21 - 1 != i )
                SoundManager::playSample(soundManager, thisa->combatSounds[0]);
              else
                SoundManager::playSample(soundManager, thisa->combatSounds[6]);
            }
            else
            {
              SoundManager::playSample(soundManager, thisa->combatSounds[5]);
              sleep(100);
            }
          }
          if ( i || thisa->animationFrame )
          {
            Bitmap::blitToScreenSizedBmp(
              combatManager->probablyBitmapForCombatScreen,
              heroWindowManager->screenBuffer,
              combatScreenRedrawRectLeft,
              combatScreenRedrawRectTop,
              combatScreenRedrawRectLeft,
              combatScreenRedrawRectTop,
              combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
              combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
            offsetX = combatScreenRedrawRectLeft;
            offsetY = combatScreenRedrawRectTop;
            v10 = combatScreenRedrawRectRight;
            v6 = combatScreenRedrawRectBot;
          }
          else
          {
            offsetX = 0;
            offsetY = 0;
            v10 = 639;
            v6 = 442;
          }
          combatScreenRedrawRectTop = 640;
          combatScreenRedrawRectLeft = 640;
          combatScreenRedrawRectBot = 0;
          combatScreenRedrawRectRight = 0;
          dword_4F7480 = 1;
          dword_4F7484 = 1;
          CreatureStack::draw(thisa, (signed __int64)v23, (signed __int64)v22, 0);
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
          if ( offsetX > combatScreenRedrawRectLeft )
            offsetX = combatScreenRedrawRectLeft;
          if ( offsetY > combatScreenRedrawRectTop )
            offsetY = combatScreenRedrawRectTop;
          if ( v10 < combatScreenRedrawRectRight )
            v10 = combatScreenRedrawRectRight;
          if ( combatScreenRedrawRectBot > v6 )
            v6 = combatScreenRedrawRectBot;
          sleepUntilPointer(&animationFrameSwitchTime);
          if ( thisa->animationFrame >= v8
            && (thisa->animationFrame + 1 < v7 || thisa->creatureIdx != 52 && thisa->creatureIdx != 53) )
            animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                      + (double)thisa->form.field_A2
                                                      * combatSpeedPercentages[*(_DWORD *)&combatSpeed]
                                                      / (double)v12);
          else
            animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                      + (double)thisa->form.field_A2
                                                      * combatSpeedPercentages[*(_DWORD *)&combatSpeed]
                                                      * 1.3
                                                      / (double)v12);
          HeroWindowManager::redrawRectangle(heroWindowManager, offsetX, offsetY, v10 - offsetX + 1, v6 - offsetY + 1);
          if ( thisa->form.animationLengths[6] - 1 == thisa->animationFrame )
          {
            v23 = (double)(i + 1) * v16 + (double)v19;
            v22 = (double)(i + 1) * v24 + (double)v14;
          }
        }
      }
    }
    CreatureStack::handleCreatureEvent(thisa, 0);
    combatManager->combatGrid[hexIdx].unitOwner = LOBYTE(combatManager->otherCurrentSideThing);
    combatManager->combatGrid[hexIdx].stackIdx = LOBYTE(combatManager->someSortOfStackIdx);
    combatManager->combatGrid[hexIdx].notPrimarySquareOfTwoHexer = -1;
    if ( thisa->creature.creature_flags & 1 )
    {
      v5 = hexIdx + (thisa->facingRight < 1u ? -1 : 1);
      combatManager->combatGrid[v5].unitOwner = LOBYTE(combatManager->otherCurrentSideThing);
      combatManager->combatGrid[v5].stackIdx = LOBYTE(combatManager->someSortOfStackIdx);
      combatManager->combatGrid[v5].notPrimarySquareOfTwoHexer = v5 >= hexIdx;
      combatManager->combatGrid[hexIdx].notPrimarySquareOfTwoHexer = v5 <= hexIdx;
    }
    thisa->occupiedHex = hexIdx;
    thisa->animationType = 7;
    thisa->animationFrame = 0;
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
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    CombatManager::handleMoatClosing(combatManager);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
