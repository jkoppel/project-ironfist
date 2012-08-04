{
  int v3; // [sp+Ch] [bp-8h]@1
  heroWindow *thisa; // [sp+10h] [bp-4h]@5

  v3 = this;
  *(_BYTE *)(this + 94) = !giHighScoreType || giHighScoreType == 2;
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  sprintf(gText, "hsbkg.icn");
  resourceManager::GetBackdrop(gpResourceManager, gText, gpWindowManager->screenBuffer, 1);
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    *(_DWORD *)(v3 + 95) = heroWindow::heroWindow(thisa, 0, 0, "hiscore.bin");
  else
    *(_DWORD *)(v3 + 95) = 0;
  if ( !*(_DWORD *)(v3 + 95) )
    MemError();
  highScoreManager::Update(v3);
  heroWindowManager::AddWindow(gpWindowManager, *(heroWindow **)(v3 + 95), -1, 1);
  *(_DWORD *)(v3 + 12) = 16384;
  *(_DWORD *)(v3 + 16) = a2;
  *(_DWORD *)(v3 + 50) = 1;
  strcpy((char *)(v3 + 20), "highScoreManager");
  KBChangeMenu(hmnuDflt);
  heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
  glTimers = KBTickCount() + 120;
  return 0;
}