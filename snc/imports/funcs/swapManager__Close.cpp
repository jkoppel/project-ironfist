{
  int v1; // ST10_4@1
  int evt; // [sp+1Ch] [bp-1Ch]@1
  int v4; // [sp+20h] [bp-18h]@1
  int v5; // [sp+24h] [bp-14h]@1
  int v6; // [sp+34h] [bp-4h]@1

  v1 = this;
  resourceManager::Dispose(gpResourceManager, *(resource **)(this + 58));
  heroWindowManager::RemoveWindow(gpWindowManager, *(heroWindow **)(v1 + 54));
  operator delete(*(void **)(v1 + 54));
  *(_DWORD *)(v1 + 50) = 0;
  gpAdvManager->ready = 1;
  evt = 512;
  v4 = 5;
  v6 = 2;
  v5 = 1;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v5 = 2;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v5 = 3;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v5 = 4;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v5 = 5;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v5 = 6;
  return heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
}