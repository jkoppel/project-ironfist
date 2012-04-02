void __thiscall sub_4C4960(CombatManager *this, signed int hexIdx, int a3)
{
  Bitmap *v4; // [sp+10h] [bp-20h]@13
  int v5; // [sp+14h] [bp-1Ch]@26
  int v6; // [sp+18h] [bp-18h]@26
  int v7; // [sp+1Ch] [bp-14h]@26
  int v8; // [sp+20h] [bp-10h]@26
  int height; // [sp+24h] [bp-Ch]@18
  int heighta; // [sp+24h] [bp-Ch]@23
  int v11; // [sp+28h] [bp-8h]@26
  int v12; // [sp+2Ch] [bp-4h]@26

  if ( !this->field_F357 && !combatGraphicsOff && *(_DWORD *)&showCombatMouseHex && (!dword_4F31B0 || a3) )
  {
    if ( hexIdx < 0 || hexIdx >= 117 || !(hexIdx % 13) || hexIdx % 13 == 12 )
      hexIdx = -1;
    if ( this->shadedHex != hexIdx )
    {
      if ( !this->bitmap1 )
      {
        v4 = (Bitmap *)operator new(0x1Au);
        if ( v4 )
          this->bitmap1 = Bitmap_constructor(v4, 0, 44, 52);
        else
          this->bitmap1 = 0;
      }
      if ( this->shadedHex != -1 )
      {
        if ( this->combatGrid[this->shadedHex].topY + 51 <= 442 )
          height = 52;
        else
          height = 442 - this->combatGrid[this->shadedHex].topY + 1;
        Bitmap::blitTo(
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
        Bitmap::blitTo(
          this->probablyBitmapForCombatScreen,
          this->bitmap1,
          0,
          0,
          this->combatGrid[hexIdx].leftX,
          this->combatGrid[hexIdx].topY,
          44,
          heighta);
        sub_4D8580(
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
      v11 = combatScreenRedrawRectLeft;
      v12 = combatScreenRedrawRectTop;
      v5 = combatScreenRedrawRectRight;
      v6 = combatScreenRedrawRectBot;
      v7 = dword_4F7488;
      v8 = dword_4F7480;
      if ( this->shadedHex == -1 )
      {
        combatScreenRedrawRectLeft = 640;
        combatScreenRedrawRectTop = 480;
        combatScreenRedrawRectRight = 0;
        combatScreenRedrawRectBot = 0;
      }
      else
      {
        combatScreenRedrawRectLeft = this->combatGrid[this->shadedHex].leftX;
        combatScreenRedrawRectTop = this->combatGrid[this->shadedHex].topY;
        combatScreenRedrawRectRight = this->combatGrid[this->shadedHex].leftX + 43;
        combatScreenRedrawRectBot = this->combatGrid[this->shadedHex].topY + 51;
      }
      if ( hexIdx != -1 )
      {
        if ( this->combatGrid[hexIdx].leftX < combatScreenRedrawRectLeft )
          combatScreenRedrawRectLeft = this->combatGrid[hexIdx].leftX;
        if ( this->combatGrid[hexIdx].topY < combatScreenRedrawRectTop )
          combatScreenRedrawRectTop = this->combatGrid[hexIdx].topY;
        if ( this->combatGrid[hexIdx].leftX + 43 > combatScreenRedrawRectRight )
          combatScreenRedrawRectRight = this->combatGrid[hexIdx].leftX + 43;
        if ( this->combatGrid[hexIdx].topY + 51 > combatScreenRedrawRectBot )
          combatScreenRedrawRectBot = this->combatGrid[hexIdx].topY + 51;
      }
      if ( combatScreenRedrawRectBot > 442 )
        combatScreenRedrawRectBot = 442;
      dword_4F7488 = 1;
      dword_4F7480 = 1;
      Bitmap::blitToScreenSizedBmp(
        this->probablyBitmapForCombatScreen,
        HeroWindowManager::instance->screenBuffer,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
        combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      CombatManager::drawBattlefield(this, 0, 0, 0, 0, 75, 1, 1);
      HeroWindowManager::redrawRectangle(
        HeroWindowManager::instance,
        combatScreenRedrawRectLeft,
        combatScreenRedrawRectTop,
        combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
        combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      combatScreenRedrawRectLeft = v11;
      combatScreenRedrawRectTop = v12;
      combatScreenRedrawRectRight = v5;
      combatScreenRedrawRectBot = v6;
      dword_4F7488 = v7;
      dword_4F7480 = v8;
      this->shadedHex = hexIdx;
    }
  }
}
