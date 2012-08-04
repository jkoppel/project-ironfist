{
  townManager *thisa; // [sp+Ch] [bp-30h]@1
  heroWindow *window; // [sp+18h] [bp-24h]@1
  int evt; // [sp+1Ch] [bp-20h]@6
  int v5; // [sp+20h] [bp-1Ch]@6
  int v6; // [sp+24h] [bp-18h]@6
  char *v7; // [sp+34h] [bp-8h]@6
  int v8; // [sp+38h] [bp-4h]@1

  thisa = this;
  v8 = 0;
  window = (heroWindow *)operator new(68);
  if ( window )
    thisa->curScreen = heroWindow::heroWindow(window, 162, 10, "tavwin.bin");
  else
    thisa->curScreen = 0;
  if ( !thisa->curScreen )
    MemError();
  SetWinText(thisa->curScreen, 22);
  sprintf(gText, "A generous tip for the barkeep yields the following rumor:\n\n%s", &gpGame->_10[45]);
  evt = 512;
  v5 = 3;
  v6 = 601;
  v7 = gText;
  heroWindow::BroadcastMessage(thisa->curScreen, (Event *)&evt);
  heroWindowManager::DoDialog(gpWindowManager, thisa->curScreen, (int (__fastcall *)(tag_message *))TavernHandler, 0);
  return operator delete(thisa->curScreen);
}