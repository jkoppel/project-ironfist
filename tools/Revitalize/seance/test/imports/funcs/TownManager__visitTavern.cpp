{
  TownManager *thisa; // [sp+Ch] [bp-30h]@1
  GUIWindow *window; // [sp+18h] [bp-24h]@1
  int evt; // [sp+1Ch] [bp-20h]@6
  int v5; // [sp+20h] [bp-1Ch]@6
  int v6; // [sp+24h] [bp-18h]@6
  char *v7; // [sp+34h] [bp-8h]@6
  int v8; // [sp+38h] [bp-4h]@1

  thisa = this;
  v8 = 0;
  window = (GUIWindow *)operator new(0x44u);
  if ( window )
    thisa->curScreen = GUIWindow_constructorFromFile(window, 162, 10, "tavwin.bin");
  else
    thisa->curScreen = 0;
  if ( !thisa->curScreen )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(thisa->curScreen, 22);
  sprintf(globBuf, "A generous tip for the barkeep yields the following rumor:\n\n%s", &gameObject->_10[45]);
  evt = 512;
  v5 = 3;
  v6 = 601;
  v7 = globBuf;
  GUIWindow::processMessage(thisa->curScreen, (Event *)&evt);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    thisa->curScreen,
    (int (__fastcall *)(InputEvent *))tavernWindowCallback,
    0);
  return operator delete(thisa->curScreen);
}
