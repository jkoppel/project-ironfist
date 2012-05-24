CombatManager *__thiscall CombatManager_constructor(CombatManager *this)
{
  CreatureStack *i; // [sp+10h] [bp-10h]@4
  signed int v4; // [sp+14h] [bp-Ch]@4
  CombatHexTile *hexTile; // [sp+18h] [bp-8h]@1
  COMBAT_CONSTANTS v6; // [sp+1Ch] [bp-4h]@1

  AbstractManager_constructor((AbstractManager *)this);
  v6 = HEX_GRID_SIZE;
  for ( hexTile = this->combatGrid; ; ++hexTile )
  {
    --v6;
    if ( (signed int)v6 < 0 )
      break;
    CombatHexTile_constructor(hexTile);
  }
  Hero_constructor(&this->captains);
  v4 = 42;
  for ( i = (CreatureStack *)this->creatures; ; ++i )
  {
    --v4;
    if ( v4 < 0 )
      break;
    CreatureStack_constructor(i);
  }
  this->vtable = &combatManager_vtable;
  this->field_F373 = -1;
  this->otherCurrentSideThing = 1;
  this->currentActionSide = 1;
  this->field_F2BB = 0;
  this->field_F2B7 = 0;
  this->field_F2BF = 1;
  this->field_F2CF = 0;
  this->field_F35B = 0;
  LODWORD(this->field_F353) = -1;
  this->zeroedInHandleCatapult2 = LODWORD(this->field_F353);
  this->probablyCatapultImgIdx[0] = this->zeroedInHandleCatapult2;
  this->probablyCatapultImgIdx[1] = this->probablyCatapultImgIdx[0];
  *(_DWORD *)&this->_12[0] = 0;
  *(_DWORD *)&this->_12[4] = *(_DWORD *)&this->_12[0];
  this->isCastleBattle = 0;
  this->shadedHex = -1;
  this->checkedInsub4c3d60 = 0;
  strcpy((int)this->combatMessageRow1);
  strcpy((int)this->combatMessageRow2);
  return this;
}
