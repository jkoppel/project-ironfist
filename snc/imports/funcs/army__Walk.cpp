{
  int v4; // ST3C_4@78
  int v6; // [sp+1Ch] [bp-24h]@26
  int v7; // [sp+20h] [bp-20h]@80
  int i; // [sp+24h] [bp-1Ch]@47
  int v9; // [sp+28h] [bp-18h]@77
  signed int v10; // [sp+30h] [bp-10h]@1
  int offsetY; // [sp+34h] [bp-Ch]@26
  int v12; // [sp+38h] [bp-8h]@26
  int offsetX; // [sp+3Ch] [bp-4h]@26

  v10 = army::GetAdjacentCellIndex(this, this->occupiedHex, a2);
  if ( this->owningSide == 1
    && gpCombatManager->isCastleBattle
    && (v10 == 58 || v10 == 59 || v10 == 60 && this->owningSide == 1 && this->creature.creature_flags & 1)
    && gpCombatManager->drawBridgePosition == 4 )
  {
    this->animationType = 7;
    this->animationFrame = 0;
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
    combatManager::LowerDoor(gpCombatManager);
    a4 = 0;
  }
  giWalkingFrom = this->occupiedHex;
  if ( this->creature.creature_flags & 1 )
    giWalkingFrom2 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
  else
    giWalkingFrom2 = -1;
  giWalkingTo = v10;
  if ( this->creature.creature_flags & 1 )
    giWalkingTo2 = v10 + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
  else
    giWalkingTo2 = -1;
  giWalkingYMod = 0;
  BuildTempWalkSeq((SMonFrameInfo *)this->gap_129, a3, a4);
  this->field_8A = a2;
  if ( !a4 )
  {
    giMinExtentY = 640;
    giMinExtentX = 640;
    giMaxExtentY = 0;
    giMaxExtentX = 0;
    gbComputeExtent = 1;
    gbSaveBiggestExtent = 1;
    gbReturnAfterComputeExtent = 1;
    army::DrawToBuffer(
      this,
      gpCombatManager->combatGrid[this->occupiedHex].centerX,
      gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY,
      0);
    gbReturnAfterComputeExtent = 0;
    gbSaveBiggestExtent = 0;
    gbComputeExtent = 0;
  }
  if ( giMinExtentX < 0 )
    giMinExtentX = 0;
  if ( giMinExtentY < 0 )
    giMinExtentY = 0;
  if ( giMaxExtentX > 639 )
    giMaxExtentX = 639;
  if ( giMaxExtentY > 442 )
    giMaxExtentY = 442;
  offsetX = giMinExtentX;
  offsetY = giMinExtentY;
  v12 = giMaxExtentX;
  v6 = giMaxExtentY;
  this->field_8E = 0;
  if ( a2 >= 3 )
  {
    if ( this->facingRight == 1 )
    {
      this->field_8E = 1;
      this->facingRight = 1 - this->facingRight;
      if ( this->creature.creature_flags & 1 )
        ++this->occupiedHex;
    }
  }
  else if ( !this->facingRight )
  {
    this->field_8E = 1;
    this->facingRight = 1 - this->facingRight;
    if ( this->creature.creature_flags & 1 )
      --this->occupiedHex;
  }
  if ( !a2 || a2 == 5 )
    this->field_6 = 0;
  if ( a2 == 2 || a2 == 3 )
    this->field_6 = 3;
  this->animationFrame = 0;
  this->animationType = 6;
  if ( !gbNoShowCombat )
    soundManager::MemorySample(gpSoundManager, this->combatSounds[0]);
  if ( !a4 )
  {
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
    combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 1, 1);
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
    if ( !gbNoShowCombat )
      bitmap::CopyTo(
        gpWindowManager->screenBuffer,
        gpCombatManager->probablyBitmapForCombatScreen,
        0,
        0,
        0,
        0,
        0x280u,
        443);
    gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
  }
  if ( !gbNoShowCombat )
  {
    for ( i = 0; this->gap_129[249] > i; ++i )
    {
      this->animationFrame = i;
      if ( a4 || i )
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
        if ( giMinExtentX < 0 )
          giMinExtentX = 0;
        if ( giMinExtentY < 0 )
          giMinExtentY = 0;
        if ( giMaxExtentX > 639 )
          giMaxExtentX = 639;
        if ( giMaxExtentY > 442 )
          giMaxExtentY = 442;
        offsetX = giMinExtentX;
        offsetY = giMinExtentY;
        v12 = giMaxExtentX;
        v6 = giMaxExtentY;
      }
      giMinExtentY = 640;
      giMinExtentX = 640;
      giMaxExtentY = 0;
      giMaxExtentX = 0;
      gbComputeExtent = 1;
      gbSaveBiggestExtent = 1;
      gbReturnAfterComputeExtent = 1;
      army::DrawToBuffer(
        this,
        gpCombatManager->combatGrid[this->occupiedHex].centerX,
        gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY,
        0);
      gbReturnAfterComputeExtent = 0;
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
      gbCurrArmyDrawn = 0;
      gbComputeExtent = 1;
      gbLimitToExtent = 1;
      this->field_11D = 0;
      combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 0, 1);
      this->field_11D = 1;
      gbLimitToExtent = 0;
      gbComputeExtent = 0;
      gbCurrArmyDrawn = 1;
      if ( giMinExtentX < offsetX )
        offsetX = giMinExtentX;
      if ( offsetY > giMinExtentY )
        offsetY = giMinExtentY;
      if ( giMaxExtentX > v12 )
        v12 = giMaxExtentX;
      if ( giMaxExtentY > v6 )
        v6 = giMaxExtentY;
      DelayTil(&glTimers);
      glTimers = (signed __int64)((double)KBTickCount()
                                + (double)*(signed int *)&this->gap_129[162]
                                * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]
                                / (double)this->gap_129[249]);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, offsetX, offsetY, v12 - offsetX + 1, v6 - offsetY + 1);
    }
  }
  v9 = army::GetAdjacentCellIndex(this, this->occupiedHex, a2);
  gpCombatManager->combatGrid[this->occupiedHex].stackIdx = -1;
  gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
  gpCombatManager->combatGrid[this->occupiedHex].isOccupierNonPrimaryHex = -1;
  if ( this->creature.creature_flags & 1 )
  {
    v4 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v4].stackIdx = -1;
    gpCombatManager->combatGrid[v4].unitOwner = -1;
    gpCombatManager->combatGrid[v4].isOccupierNonPrimaryHex = -1;
  }
  gpCombatManager->combatGrid[v9].unitOwner = LOBYTE(this->owningSide);
  gpCombatManager->combatGrid[v9].stackIdx = LOBYTE(this->stackIdx);
  gpCombatManager->combatGrid[v9].isOccupierNonPrimaryHex = -1;
  if ( this->creature.creature_flags & 1 )
  {
    v7 = v9 + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v7].unitOwner = LOBYTE(this->owningSide);
    gpCombatManager->combatGrid[v7].stackIdx = LOBYTE(this->stackIdx);
    gpCombatManager->combatGrid[v7].isOccupierNonPrimaryHex = v9 <= v7;
    gpCombatManager->combatGrid[v9].isOccupierNonPrimaryHex = v9 >= v7;
  }
  this->occupiedHex = v9;
  if ( this->field_8E )
  {
    this->facingRight = 1 - this->facingRight;
    if ( this->creature.creature_flags & TWO_HEXER )
    {
      if ( this->facingRight )
        --this->occupiedHex;
      else
        ++this->occupiedHex;
    }
    this->field_8E = 0;
  }
  giWalkingFrom = -1;
  giWalkingFrom2 = -1;
  giWalkingTo = -1;
  giWalkingTo2 = -1;
  this->field_6 = 1;
  if ( a3 == 1 )
  {
    this->animationType = 7;
    this->animationFrame = 0;
    combatManager::DrawFrame(gpCombatManager, 1, 1, 0, 0, 75, 1, 1);
  }
}