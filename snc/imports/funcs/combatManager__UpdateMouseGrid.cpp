{
  bitmap *v4; // [sp+10h] [bp-20h]@13
  int v5; // [sp+14h] [bp-1Ch]@26
  int v6; // [sp+18h] [bp-18h]@26
  int v7; // [sp+1Ch] [bp-14h]@26
  int v8; // [sp+20h] [bp-10h]@26
  int height; // [sp+24h] [bp-Ch]@18
  int heighta; // [sp+24h] [bp-Ch]@23
  int v11; // [sp+28h] [bp-8h]@26
  int v12; // [sp+2Ch] [bp-4h]@26

  if ( !this->field_F357 && !gbNoShowCombat && *(_DWORD *)&showCombatMouseHex && (!gbProcessingCombatAction || a3) )
  {
    if ( hexIdx < 0 || hexIdx >= 117 || !(hexIdx % 13) || hexIdx % 13 == 12 )
      hexIdx = -1;
    if ( this->shadedHex != hexIdx )
    {
      if ( !this->bitmap1 )
      {
        v4 = (bitmap *)operator new(26);
        if ( v4 )
          this->bitmap1 = bitmap::bitmap(v4, 0, 44, 52);
        else
          this->bitmap1 = 0;
      }
      if ( this->shadedHex != -1 )
      {
        if ( this->combatGrid[this->shadedHex].topY + 51 <= 442 )
          height = 52;
        else
          height = 442 - this->combatGrid[this->shadedHex].topY + 1;
        bitmap::CopyToCareful(
          this->bitmap1,
          this->probablyBitmapForCombatScreen,
          this->combatGrid[this->shadedHex].leftX,
          this->combatGrid[this->shadedHex].topY,
          0,
          0,
          44,
          height);
      }
      if ( hexIdx != -1 )
      {
        if ( this->combatGrid[hexIdx].topY + 51 <= 442 )
          heighta = 52;
        else
          heighta = 442 - this->combatGrid[hexIdx].topY + 1;
        bitmap::CopyToCareful(
          this->probablyBitmapForCombatScreen,
          this->bitmap1,
          0,
          0,
          this->combatGrid[hexIdx].leftX,
          this->combatGrid[hexIdx].topY,
          44,
          heighta);
        DimIconToBitmap(
          this->combatScreenIcons[9],
          (int)this->probablyBitmapForCombatScreen,
          this->combatGrid[hexIdx].leftX,
          this->combatGrid[hexIdx].topY,
          1,
          2,
          1,
          0,
          0,
          640,
          443);
      }
      v11 = giMinExtentX;
      v12 = giMinExtentY;
      v5 = giMaxExtentX;
      v6 = giMaxExtentY;
      v7 = gbLimitToExtent;
      v8 = gbComputeExtent;
      if ( this->shadedHex == -1 )
      {
        giMinExtentX = 640;
        giMinExtentY = 480;
        giMaxExtentX = 0;
        giMaxExtentY = 0;
      }
      else
      {
        giMinExtentX = this->combatGrid[this->shadedHex].leftX;
        giMinExtentY = this->combatGrid[this->shadedHex].topY;
        giMaxExtentX = this->combatGrid[this->shadedHex].leftX + 43;
        giMaxExtentY = this->combatGrid[this->shadedHex].topY + 51;
      }
      if ( hexIdx != -1 )
      {
        if ( this->combatGrid[hexIdx].leftX < giMinExtentX )
          giMinExtentX = this->combatGrid[hexIdx].leftX;
        if ( this->combatGrid[hexIdx].topY < giMinExtentY )
          giMinExtentY = this->combatGrid[hexIdx].topY;
        if ( this->combatGrid[hexIdx].leftX + 43 > giMaxExtentX )
          giMaxExtentX = this->combatGrid[hexIdx].leftX + 43;
        if ( this->combatGrid[hexIdx].topY + 51 > giMaxExtentY )
          giMaxExtentY = this->combatGrid[hexIdx].topY + 51;
      }
      if ( giMaxExtentY > 442 )
        giMaxExtentY = 442;
      gbLimitToExtent = 1;
      gbComputeExtent = 1;
      bitmap::CopyTo(
        this->probablyBitmapForCombatScreen,
        gpWindowManager->screenBuffer,
        giMinExtentX,
        giMinExtentY,
        giMinExtentX,
        giMinExtentY,
        giMaxExtentX - giMinExtentX + 1,
        giMaxExtentY - giMinExtentY + 1);
      combatManager::DrawFrame(this, 0, 0, 0, 0, 75, 1, 1);
      heroWindowManager::UpdateScreenRegion(
        gpWindowManager,
        giMinExtentX,
        giMinExtentY,
        giMaxExtentX - giMinExtentX + 1,
        giMaxExtentY - giMinExtentY + 1);
      giMinExtentX = v11;
      giMinExtentY = v12;
      giMaxExtentX = v5;
      giMaxExtentY = v6;
      gbLimitToExtent = v7;
      gbComputeExtent = v8;
      this->shadedHex = hexIdx;
    }
  }
}