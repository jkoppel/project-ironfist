{
  int v3; // [sp+Ch] [bp-8h]@1
  GUIWindow *thisa; // [sp+10h] [bp-4h]@5

  v3 = this;
  *(_BYTE *)(this + 94) = !dword_4F74A0 || dword_4F74A0 == 2;
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  sprintf(globBuf, "hsbkg.icn");
  ResourceManager::dumpImageToScreen(resourceManager, globBuf, HeroWindowManager::instance->screenBuffer, 1);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    *(_DWORD *)(v3 + 95) = GUIWindow_constructorFromFile(thisa, 0, 0, "hiscore.bin");
  else
    *(_DWORD *)(v3 + 95) = 0;
  if ( !*(_DWORD *)(v3 + 95) )
    fatalOutOfMemoryError();
  sub_4079A0(v3);
  HeroWindowManager::addWindow(HeroWindowManager::instance, *(GUIWindow **)(v3 + 95), -1, 1);
  *(_DWORD *)(v3 + 12) = 16384;
  *(_DWORD *)(v3 + 16) = a2;
  *(_DWORD *)(v3 + 50) = 1;
  strcpy((char *)(v3 + 20), "highScoreManager");
  changeMenu(dfltMenu);
  sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
  animationFrameSwitchTime = getTickCount() + 120;
  return 0;
}
