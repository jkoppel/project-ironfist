int __thiscall sub_4BDEC0(int this)
{
  int v1; // ST10_4@1
  int evt; // [sp+1Ch] [bp-1Ch]@1
  int v4; // [sp+20h] [bp-18h]@1
  int v5; // [sp+24h] [bp-14h]@1
  int v6; // [sp+34h] [bp-4h]@1

  v1 = this;
  ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)(this + 58));
  HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)(v1 + 54));
  operator delete(*(void **)(v1 + 54));
  *(_DWORD *)(v1 + 50) = 0;
  advManager->ready = 1;
  evt = 512;
  v4 = 5;
  v6 = 2;
  v5 = 1;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v5 = 2;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v5 = 3;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v5 = 4;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v5 = 5;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v5 = 6;
  return GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
}
