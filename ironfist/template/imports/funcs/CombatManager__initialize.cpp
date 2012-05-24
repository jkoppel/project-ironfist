{
  int v2; // edx@12
  void *v3; // ecx@12
  int v4; // eax@14
  int v6; // [sp+0h] [bp-30h]@0
  CombatManager *thisa; // [sp+Ch] [bp-24h]@1
  GUIWindow *window; // [sp+10h] [bp-20h]@7
  Bitmap *v9; // [sp+1Ch] [bp-14h]@4
  Bitmap *thisb; // [sp+20h] [bp-10h]@1
  sample_resource res; // [sp+24h] [bp-Ch]@7
  int oldShowCombatMouse; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  debugLog("Op1");
  memcpy(thisa->_1, dword_524234->contents, 0x300u);
  mouseManager->field_7E = 1;
  oldShowCombatMouse = *(_DWORD *)&showCombatMouseHex;
  *(_DWORD *)&showCombatMouseHex = 0;
  thisa->otherCombatMessageRelatedTime = 0;
  thisa->combatMessageRelatedTime = 0;
  thisa->couldBeShouldResetCombatMessage = 0;
  thisa->checkedInsub4c3d60 = 0;
  SoundManager::otherPlayTrack(soundManager, -1, 0, -1, v6);
  thisb = (Bitmap *)operator new(0x1Au);
  if ( thisb )
    thisa->couldBeBitmapForFieldItself = Bitmap_constructor(thisb, 0, 507, 380);
  else
    thisa->couldBeBitmapForFieldItself = 0;
  v9 = (Bitmap *)operator new(0x1Au);
  if ( v9 )
    thisa->probablyBitmapForCombatScreen = Bitmap_constructor(v9, 0, 640, 443);
  else
    thisa->probablyBitmapForCombatScreen = 0;
  thisa->bitmap1 = 0;
  thisa->field_F553 = -1;
  thisa->field_F557 = -1;
  memset(thisa->field_49F, 0, 0x75u);
  CombatManager::loadManyCombatImages(thisa);
  CombatManager::initializeArmyAndHeroData(thisa);
  CombatManager::initializeBattlefield(thisa);
  memset(thisa->field_42A, 0, 0x75u);
  CombatManager::doCombatRound(thisa, 0);
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  debugLog("Op2");
  res = playSample("PREBATTL.82M");
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  dword_4F19A0 = thisa->field_31EA;
  sub_4C7320(1);
  sub_4C7320(1);
  nextCreatureEffectAnimation = 0;
  nextCreatureEffectAnimationIdx = -1;
  mouseManager->field_7E = 0;
  MouseManager::loadMSE(mouseManager, "cmbtmous.mse", 6, -999);
  mouseShownAtCombatStart = MouseManager::mouseEnabled(mouseManager);
  MouseManager::enableCursor(mouseManager);
  window = (GUIWindow *)operator new(0x44u);
  if ( window )
    thisa->window = GUIWindow_constructorFromFile(window, 0, 0, "cmbtwin.bin");
  else
    thisa->window = 0;
  if ( !thisa->window )
    fatalOutOfMemoryError();
  HeroWindowManager::addWindow(HeroWindowManager::instance, thisa->window, -1, 1);
  thisa->checkedInsub4c3d60 = 1;
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  animationFrameSwitchTime = getTickCount();
  thisa->palette = ResourceManager::getPal(resourceManager, "kb.pal");
  changeMenu(combatMenu);
  CombatManager::displayCombatMessage(thisa, byte_5130C4, 1, 1, 0);
  *(_DWORD *)&showCombatMouseHex = oldShowCombatMouse;
  v3 = palette->contents;
  if ( thisa->palette->contents != v3 )
    memcpy_0(v3, v2, thisa->palette->contents, palette->contents, 0x300u);
  sub_4C7C60(HeroWindowManager::instance, 0, 8, thisa->palette);
  dword_4F7460 = 1;
  waitForSampleToFinish(-1, res);
  debugLog("Op3");
  v4 = nextRandomInt(2, 4);
  SoundManager::couldBePlayCDTrack(soundManager, v4);
  nextCombatAnimationTime = getTickCount();
  sub_441850(thisa);
  debugLog("Op4");
  InputManager::resetInfoFields(inputManager);
  sub_440ED0(thisa);
  thisa->type = 512;
  thisa->idx = a2;
  thisa->ready = 1;
  strcpy(thisa->name, "combatManager");
  debugLog("Op5");
  return 0;
}
