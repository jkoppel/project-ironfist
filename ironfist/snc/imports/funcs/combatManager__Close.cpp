{
  combatManager *result; // eax@31
  bitmap *v3; // [sp+1Ch] [bp-24h]@8
  bitmap *v4; // [sp+24h] [bp-1Ch]@5
  bitmap *v5; // [sp+2Ch] [bp-14h]@3
  bool v6; // [sp+34h] [bp-Ch]@13
  signed int side; // [sp+38h] [bp-8h]@10
  signed int sidea; // [sp+38h] [bp-8h]@13
  signed int v9; // [sp+3Ch] [bp-4h]@13

  soundManager::SwitchAmbientMusic(gpSoundManager, -1);
  gbLimitedCombatUpdatePalette = 0;
  if ( !gbClosingApp )
  {
    memcpy(gPalette->contents, this->_1, 0x300u);
    memcpy(gpBufferPalette->contents, this->_1, 0x300u);
  }
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  giCycleType = 0;
  CycleColors(0);
  v5 = this->couldBeBitmapForFieldItself;
  if ( v5 )
    ((void (__thiscall *)(bitmap *))v5->vtable->cleanUp)(v5);
  v4 = this->probablyBitmapForCombatScreen;
  if ( v4 )
    ((void (__thiscall *)(bitmap *))v4->vtable->cleanUp)(v4);
  if ( this->bitmap1 )
  {
    v3 = this->bitmap1;
    if ( v3 )
      ((void (__thiscall *)(bitmap *))v3->vtable->cleanUp)(v3);
  }
  for ( side = 0; side < 2; ++side )
    combatManager::UpdateArmyGroup(this, side);
  v9 = 0;
  v6 = this->playerID[1] == -1;
  for ( sidea = 0; sidea < 5; ++sidea )
  {
    if ( this->armies[v6]->creatureTypes[sidea] != -1 )
      v9 += this->armies[v6]->quantities[sidea];
  }
  if ( *(_BYTE *)(this->field_327B + 9) == 152 )
  {
    if ( v9 > 4000 )
      LOWORD(v9) = 4000;
    *(_WORD *)(this->field_327B + 4) = 8 * (v9 & 0xFFF) | *(_WORD *)(this->field_327B + 4) & 7;
  }
  if ( *(_BYTE *)(this->field_327B + 9) == 151
    && gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(this->field_327B + 4) >> 8) >> -5) + 3] != -1 )
    gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(this->field_327B + 4) >> 8) >> -5) + 4] = v9;
  if ( *(_BYTE *)(this->field_327B + 9) == 170
    && gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(this->field_327B + 4) >> 8) >> -5)].occupiedObjType == 151
    && gpGame->_8[7
                * gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(this->field_327B + 4) >> 8) >> -5)].occupiedObjVal
                + 3] != -1 )
    gpGame->_8[7
             * gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(this->field_327B + 4) >> 8) >> -5)].occupiedObjVal
             + 4] = v9;
  heroWindowManager::RemoveWindow(gpWindowManager, this->window);
  combatManager::FreeArmies(this);
  combatManager::FreeIcons(this);
  resourceManager::Dispose(gpResourceManager, (resource *)this->palette);
  operator delete(this->window);
  if ( !bMouseWasVis )
    mouseManager::HideColorPointer(gpMouseManager);
  this->ready = 0;
  result = this;
  this->checkedInsub4c3d60 = 0;
  return result;
}