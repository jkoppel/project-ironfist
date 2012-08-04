{
  signed int result; // eax@2
  int v3; // ST98_4@19
  army *thisa; // [sp+60h] [bp-74h]@1
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
  if ( ValidHex(hexIdx) )
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
      combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
    v19 = gpCombatManager->combatGrid[thisa->occupiedHex].centerX;
    v14 = gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY;
    v23 = (double)v19;
    v22 = (double)v14;
    v20 = gpCombatManager->combatGrid[hexIdx].centerX - v19;
    v15 = gpCombatManager->combatGrid[hexIdx].occupyingCreatureBottomY - v14;
    v13 = (signed __int64)sqrt((double)(v15 * v15 + v20 * v20));
    v21 = 0;
    if ( *(_DWORD *)&thisa->gap_129[170] > 0 )
      v21 = (v13 + (*(_DWORD *)&thisa->gap_129[170] >> 1)) / *(_DWORD *)&thisa->gap_129[170];
    if ( v21 <= 0 )
      v21 = 1;
    v16 = (double)v20 / (double)v21;
    v24 = (double)v15 / (double)v21;
    gpCombatManager->combatGrid[thisa->occupiedHex].stackIdx = -1;
    gpCombatManager->combatGrid[thisa->occupiedHex].unitOwner = -1;
    gpCombatManager->combatGrid[thisa->occupiedHex].isOccupierNonPrimaryHex = -1;
    if ( thisa->creature.creature_flags & TWO_HEXER )
    {
      v3 = thisa->occupiedHex + (thisa->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v3].stackIdx = -1;
      gpCombatManager->combatGrid[v3].unitOwner = -1;
      gpCombatManager->combatGrid[v3].isOccupierNonPrimaryHex = -1;
    }
    if ( !gbNoShowCombat )
    {
      v7 = 0;
      combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 1, 1);
      bitmap::CopyTo(
        gpWindowManager->screenBuffer,
        gpCombatManager->probablyBitmapForCombatScreen,
        0,
        0,
        0,
        0,
        0x280u,
        442);
      gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
      thisa->animationType = 6;
      for ( i = 0; v21 > i; ++i )
      {
        BuildTempWalkSeq((SMonFrameInfo *)thisa->gap_129, i + 1 == v21, i > 0);
        if ( v21 )
        {
          if ( i <= 0 )
            v8 = thisa->gap_129[243];
          else
            v8 = 0;
          v12 = thisa->gap_129[245];
          v7 = thisa->gap_129[245];
          if ( i + 1 < v21 )
            v12 += thisa->gap_129[246];
        }
        else
        {
          v12 = thisa->gap_129[249];
          v8 = 0;
        }
        for ( thisa->animationFrame = 0; thisa->gap_129[249] > thisa->animationFrame; ++thisa->animationFrame )
        {
          if ( thisa->animationFrame >= v8 && v8 + v12 > thisa->animationFrame )
          {
            v23 = v16 / (double)v12 + v23;
            v22 = v24 / (double)v12 + v22;
          }
          if ( thisa->animationFrame % thisa->gap_129[249] == 1 )
          {
            if ( thisa->creatureIdx != 52 && thisa->creatureIdx != 53 || i )
            {
              if ( thisa->creatureIdx != 52 && thisa->creatureIdx != 53 || v21 - 1 != i )
                soundManager::MemorySample(gpSoundManager, thisa->combatSounds[0]);
              else
                soundManager::MemorySample(gpSoundManager, thisa->combatSounds[6]);
            }
            else
            {
              soundManager::MemorySample(gpSoundManager, thisa->combatSounds[5]);
              DelayMilli(100);
            }
          }
          if ( i || thisa->animationFrame )
          {
            bitmap::CopyTo(
              gpCombatManager->probablyBitmapForCombatScreen,
              gpWindowManager->screenBuffer,
              giMinExtentX,
              giMinExtentY,
              giMinExtentX,
              giMinExtentY,
              giMaxExtentX - giMinExtentX + 1,
              giMaxExtentY - giMinExtentY + 1);
            offsetX = giMinExtentX;
            offsetY = giMinExtentY;
            v10 = giMaxExtentX;
            v6 = giMaxExtentY;
          }
          else
          {
            offsetX = 0;
            offsetY = 0;
            v10 = 639;
            v6 = 442;
          }
          giMinExtentY = 640;
          giMinExtentX = 640;
          giMaxExtentY = 0;
          giMaxExtentX = 0;
          gbComputeExtent = 1;
          gbSaveBiggestExtent = 1;
          army::DrawToBuffer(thisa, (signed __int64)v23, (signed __int64)v22, 0);
          gbComputeExtent = 0;
          gbSaveBiggestExtent = 0;
          if ( giMinExtentX < 0 )
            giMinExtentX = 0;
          if ( giMinExtentY < 0 )
            giMinExtentY = 0;
          if ( giMaxExtentX > 639 )
            giMaxExtentX = 639;
          if ( giMaxExtentY > 442 )
            giMaxExtentY = 442;
          if ( offsetX > giMinExtentX )
            offsetX = giMinExtentX;
          if ( offsetY > giMinExtentY )
            offsetY = giMinExtentY;
          if ( v10 < giMaxExtentX )
            v10 = giMaxExtentX;
          if ( giMaxExtentY > v6 )
            v6 = giMaxExtentY;
          DelayTil(&glTimers);
          if ( thisa->animationFrame >= v8
            && (thisa->animationFrame + 1 < v7 || thisa->creatureIdx != 52 && thisa->creatureIdx != 53) )
            glTimers = (signed __int64)((double)KBTickCount()
                                      + (double)*(signed int *)&thisa->gap_129[162]
                                      * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]
                                      / (double)v12);
          else
            glTimers = (signed __int64)((double)KBTickCount()
                                      + (double)*(signed int *)&thisa->gap_129[162]
                                      * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]
                                      * 1.3
                                      / (double)v12);
          heroWindowManager::UpdateScreenRegion(gpWindowManager, offsetX, offsetY, v10 - offsetX + 1, v6 - offsetY + 1);
          if ( thisa->gap_129[249] - 1 == thisa->animationFrame )
          {
            v23 = (double)(i + 1) * v16 + (double)v19;
            v22 = (double)(i + 1) * v24 + (double)v14;
          }
        }
      }
    }
    army::CancelSpellType(thisa, 0);
    gpCombatManager->combatGrid[hexIdx].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
    gpCombatManager->combatGrid[hexIdx].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
    gpCombatManager->combatGrid[hexIdx].isOccupierNonPrimaryHex = -1;
    if ( thisa->creature.creature_flags & 1 )
    {
      v5 = hexIdx + (thisa->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v5].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
      gpCombatManager->combatGrid[v5].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
      gpCombatManager->combatGrid[v5].isOccupierNonPrimaryHex = v5 >= hexIdx;
      gpCombatManager->combatGrid[hexIdx].isOccupierNonPrimaryHex = v5 <= hexIdx;
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
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
    combatManager::TestRaiseDoor(gpCombatManager);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}