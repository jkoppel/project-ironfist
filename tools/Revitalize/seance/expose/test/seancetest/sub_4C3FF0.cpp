signed int __thiscall sub_4C3FF0(CombatManager *this, int a2, int a3)
{
  CombatManager *thisa; // [sp+Ch] [bp-28h]@1
  signed int v5; // [sp+10h] [bp-24h]@14
  signed int i; // [sp+14h] [bp-20h]@15
  signed int j; // [sp+14h] [bp-20h]@30
  signed int k; // [sp+14h] [bp-20h]@53
  signed int l; // [sp+14h] [bp-20h]@61
  signed int v10; // [sp+18h] [bp-1Ch]@14
  signed int v11; // [sp+1Ch] [bp-18h]@14
  signed int v12; // [sp+20h] [bp-14h]@14
  signed int v13; // [sp+24h] [bp-10h]@14
  signed int v14; // [sp+28h] [bp-Ch]@14
  int targY; // [sp+2Ch] [bp-8h]@14
  int targX; // [sp+30h] [bp-4h]@14

  thisa = this;
  if ( combatGraphicsOff )
    return 0;
  if ( a3 )
  {
    if ( this->playerID[this->currentActionSide] != -1
      && *(&byte_524758 + this->playerID[this->currentActionSide])
      && !this->notHandlingInputEvent )
      sub_4C3DD0(this, &this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx]);
    else
      memset(this->field_49F, 0, 0x75u);
  }
  if ( a2 )
    dword_51E3B8 = 0;
  if ( combatShadeLevel < 1 && !*(_DWORD *)&showCombatGrid )
    return 0;
  v10 = 0;
  targX = 639;
  targY = 442;
  v13 = 0;
  v12 = 0;
  v5 = 0;
  v11 = 0;
  v14 = 0;
  if ( combatShadeLevel < 1 )
    goto LABEL_58;
  for ( i = 0; i < 117; ++i )
  {
    if ( thisa->field_42A[i] != thisa->field_49F[i] )
      v14 = 1;
    if ( thisa->field_49F[i] )
      v5 = 1;
    if ( thisa->field_42A[i] )
      v11 = 1;
  }
  if ( !a2 )
  {
    if ( !v14 )
      return 0;
    if ( v11 )
    {
      for ( j = 0; j < 117; ++j )
      {
        if ( thisa->field_42A[j] != thisa->field_49F[j] || thisa->field_49F[j] )
        {
          if ( thisa->combatGrid[j].leftX < targX )
            targX = thisa->combatGrid[j].leftX;
          if ( thisa->combatGrid[j].topY < targY )
            targY = thisa->combatGrid[j].topY;
          if ( thisa->combatGrid[j].rightX > v13 )
            v13 = thisa->combatGrid[j].rightX;
          if ( thisa->combatGrid[j].otherY2 > v12 )
            v12 = thisa->combatGrid[j].otherY2;
        }
      }
      if ( targX < 67 )
        targX = 67;
      if ( targY < 63 )
        targY = 63;
      if ( v13 > 573 )
        v13 = 573;
      if ( v12 > 442 )
        v12 = 442;
      Bitmap::blitTo(
        thisa->couldBeBitmapForFieldItself,
        thisa->probablyBitmapForCombatScreen,
        targX,
        targY,
        targX - 67,
        targY - 63,
        v13 - targX + 1,
        v12 - targY + 1);
      v10 = 1;
    }
    goto LABEL_52;
  }
  if ( v5 )
  {
LABEL_52:
    if ( v5 )
    {
      for ( k = 0; k < 117; ++k )
      {
        if ( thisa->field_49F[k] )
        {
          sub_4D8580(
            thisa->combatScreenIcons[9],
            (int)thisa->probablyBitmapForCombatScreen,
            thisa->combatGrid[k].leftX,
            thisa->combatGrid[k].topY,
            1,
            thisa->field_49F[k] - 1,
            1,
            0,
            0,
            640,
            443);
          v10 = 1;
        }
      }
    }
  }
LABEL_58:
  if ( *(_DWORD *)&showCombatGrid && (!dword_51E3B8 || v10) )
  {
    for ( l = 0; l < 117; ++l )
    {
      if ( l % 13 && l % 13 != 12 )
        sub_4D82D0(
          thisa->combatScreenIcons[9],
          thisa->probablyBitmapForCombatScreen,
          thisa->combatGrid[l].leftX,
          thisa->combatGrid[l].topY,
          0,
          -30,
          1,
          0,
          0,
          0x280u,
          443);
    }
    v10 = 1;
    dword_51E3B8 = 1;
  }
  memcpy(thisa->field_42A, thisa->field_49F, 0x75u);
  return v10;
}
