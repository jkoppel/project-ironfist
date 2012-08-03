{
  int v2; // edx@12
  void *v3; // ecx@12
  int v4; // eax@14
  int v6; // [sp+0h] [bp-30h]@0
  combatManager *thisa; // [sp+Ch] [bp-24h]@1
  heroWindow *window; // [sp+10h] [bp-20h]@7
  bitmap *v9; // [sp+1Ch] [bp-14h]@4
  bitmap *thisb; // [sp+20h] [bp-10h]@1
  sample_resource res; // [sp+24h] [bp-Ch]@7
  int oldShowCombatMouse; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  LogStr("Op1");
  memcpy(thisa->_1, gPalette->contents, 0x300u);
  gpMouseManager->field_7E = 1;
  oldShowCombatMouse = *(_DWORD *)&showCombatMouseHex;
  *(_DWORD *)&showCombatMouseHex = 0;
  thisa->otherCombatMessageRelatedTime = 0;
  thisa->combatMessageRelatedTime = 0;
  thisa->couldBeShouldResetCombatMessage = 0;
  thisa->checkedInsub4c3d60 = 0;
  soundManager::PlayAmbientMusic(gpSoundManager, -1, 0, -1, v6);
  thisb = (bitmap *)operator new(26);
  if ( thisb )
    thisa->couldBeBitmapForFieldItself = bitmap::bitmap(thisb, 0, 507, 380);
  else
    thisa->couldBeBitmapForFieldItself = 0;
  v9 = (bitmap *)operator new(26);
  if ( v9 )
    thisa->probablyBitmapForCombatScreen = bitmap::bitmap(v9, 0, 640, 443);
  else
    thisa->probablyBitmapForCombatScreen = 0;
  thisa->bitmap1 = 0;
  thisa->field_F553 = -1;
  thisa->field_F557 = -1;
  memset(thisa->field_49F, 0, 0x75u);
  combatManager::LoadIcons(thisa);
  combatManager::InitNonVisualVars(thisa);
  combatManager::SetupAndLoadObstacles(thisa);
  memset(thisa->field_42A, 0, 0x75u);
  combatManager::GetNextArmy(thisa, 0);
  thisa->zeroedAfterAnimatingDeathAndHolySpells = 0;
  LogStr("Op2");
  res = LoadPlaySample("PREBATTL.82M");
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  giCycleType = thisa->field_31EA;
  CycleColors(1);
  CycleColors(1);
  gCurLoadedSpellIcon = 0;
  gCurLoadedSpellEffect = -1;
  gpMouseManager->field_7E = 0;
  mouseManager::SetPointer(gpMouseManager, "cmbtmous.mse", 6, -999);
  bMouseWasVis = mouseManager::IsVis(gpMouseManager);
  mouseManager::ShowColorPointer(gpMouseManager);
  window = (heroWindow *)operator new(68);
  if ( window )
    thisa->window = heroWindow::heroWindow(window, 0, 0, "cmbtwin.bin");
  else
    thisa->window = 0;
  if ( !thisa->window )
    MemError();
  heroWindowManager::AddWindow(gpWindowManager, thisa->window, -1, 1);
  thisa->checkedInsub4c3d60 = 1;
  combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
  glTimers = KBTickCount();
  thisa->palette = resourceManager::GetPalette(gpResourceManager, "kb.pal");
  KBChangeMenu(hmnuCmbt);
  combatManager::CombatMessage(thisa, byte_5130C4, 1, 1, 0);
  *(_DWORD *)&showCombatMouseHex = oldShowCombatMouse;
  v3 = gpBufferPalette->contents;
  if ( thisa->palette->contents != v3 )
    memmove(v3, v2, thisa->palette->contents, gpBufferPalette->contents, 0x300u);
  heroWindowManager::FadeScreen(gpWindowManager, 0, 8, thisa->palette);
  gbLimitedCombatUpdatePalette = 1;
  WaitEndSample(-1, res);
  LogStr("Op3");
  v4 = SRandom(2, 4);
  soundManager::SwitchAmbientMusic(gpSoundManager, v4);
  nextCombatAnimationTime = KBTickCount();
  combatManager::ResetCycleTimers(thisa);
  LogStr("Op4");
  inputManager::Flush(gpInputManager);
  combatManager::ResetMouse(thisa);
  thisa->type = 512;
  thisa->idx = a2;
  thisa->ready = 1;
  strcpy(thisa->name, "combatManager");
  LogStr("Op5");
  return 0;
}