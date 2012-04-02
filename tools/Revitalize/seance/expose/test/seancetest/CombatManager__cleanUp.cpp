CombatManager *__thiscall CombatManager::cleanUp(CombatManager *this)
{
  CombatManager *result; // eax@34
  CombatManager *thisa; // [sp+Ch] [bp-34h]@1
  Bitmap *v3; // [sp+1Ch] [bp-24h]@8
  Bitmap *v4; // [sp+24h] [bp-1Ch]@5
  Bitmap *v5; // [sp+2Ch] [bp-14h]@3
  bool v6; // [sp+34h] [bp-Ch]@14
  signed int side; // [sp+38h] [bp-8h]@10
  signed int sidea; // [sp+38h] [bp-8h]@16
  signed int v9; // [sp+3Ch] [bp-4h]@13

  thisa = this;
  SoundManager::couldBePlayCDTrack(soundManager, -1);
  dword_4F7460 = 0;
  if ( !dword_4F0A0C )
  {
    memcpy(dword_524234->contents, thisa->_1, 0x300u);
    memcpy(palette->contents, thisa->_1, 0x300u);
  }
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  dword_4F19A0 = 0;
  sub_4C7320(0);
  v5 = thisa->couldBeBitmapForFieldItself;
  if ( v5 )
    ((void (__thiscall *)(_DWORD))v5->vtable->cleanUp)(v5);
  v4 = thisa->probablyBitmapForCombatScreen;
  if ( v4 )
    ((void (__thiscall *)(_DWORD))v4->vtable->cleanUp)(v4);
  if ( thisa->bitmap1 )
  {
    v3 = thisa->bitmap1;
    if ( v3 )
      ((void (__thiscall *)(_DWORD))v3->vtable->cleanUp)(v3);
  }
  for ( side = 0; side < 2; ++side )
    CombatManager::handleCreatureChanges(thisa, side);
  v9 = 0;
  v6 = thisa->playerID[1] == -1;
  for ( sidea = 0; sidea < 5; ++sidea )
  {
    if ( thisa->armies[v6]->creatureTypes[sidea] != -1 )
      v9 += thisa->armies[v6]->quantities[sidea];
  }
  if ( *(_BYTE *)(thisa->field_327B + 9) == 152 )
  {
    if ( v9 > 4000 )
      LOWORD(v9) = 4000;
    *(_WORD *)(thisa->field_327B + 4) = 8 * (v9 & 0xFFF) | *(_WORD *)(thisa->field_327B + 4) & 7;
  }
  if ( *(_BYTE *)(thisa->field_327B + 9) == 151
    && gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(thisa->field_327B + 4) >> 8) >> -5) + 3] != -1 )
    gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(thisa->field_327B + 4) >> 8) >> -5) + 4] = v9;
  if ( *(_BYTE *)(thisa->field_327B + 9) == 170
    && *(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(thisa->field_327B + 4) >> 8) >> -5)]._4[12] == 151
    && gameObject->_8[7
                    * *(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(thisa->field_327B + 4) >> 8) >> -5)]._4[14]
                    + 3] != -1 )
    gameObject->_8[7
                 * *(_WORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(thisa->field_327B + 4) >> 8) >> -5)]._4[14]
                 + 4] = v9;
  HeroWindowManager::removeWindow(HeroWindowManager::instance, thisa->window);
  CombatManager::freeCreatureStackObjects(thisa);
  CombatManager::releaseStaticObjectIcons(thisa);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->palette);
  operator delete(thisa->window);
  if ( !mouseShownAtCombatStart )
    MouseManager::disableCursor(mouseManager);
  thisa->ready = 0;
  result = thisa;
  thisa->checkedInsub4c3d60 = 0;
  return result;
}
