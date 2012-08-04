{
  signed int result; // eax@15
  void *thisa; // [sp+10h] [bp-38h]@1
  heroWindow *thisb; // [sp+1Ch] [bp-2Ch]@1
  int v4; // [sp+20h] [bp-28h]@1
  int evt; // [sp+24h] [bp-24h]@7
  int v6; // [sp+28h] [bp-20h]@7
  int v7; // [sp+2Ch] [bp-1Ch]@7
  int v8; // [sp+3Ch] [bp-Ch]@7
  int window; // [sp+40h] [bp-8h]@2
  int v10; // [sp+44h] [bp-4h]@1

  thisa = this;
  advManager::TrimLoopingSounds((advManager *)this, 4);
  v10 = -1;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  v4 = *(_DWORD *)((char *)thisa + 678);
  advManager::DemobilizeCurrHero((advManager *)thisa);
  thisb = (heroWindow *)operator new(68);
  if ( thisb )
    window = (int)heroWindow::heroWindow(thisb, 144, 40, "cpanel.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  if ( gbRemoteOn )
  {
    evt = 512;
    v7 = 101;
    v6 = 5;
    v8 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
    v6 = 6;
    v8 = 2;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
    v7 = 102;
    v6 = 5;
    v8 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
    v6 = 6;
    v8 = 2;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))CPanelHandler,
    0);
  operator delete((void *)window);
  switch ( gpWindowManager->buttonPressedCode )
  {
    case 0x65:
    case 0x66:
    case 0x69:
      v10 = gpWindowManager->buttonPressedCode;
      break;
    case 0x6A:
      SaveGame();
      break;
    default:
      break;
  }
  if ( v4 )
    advManager::MobilizeCurrHero((advManager *)thisa, 0);
  if ( v10 == -1 )
  {
    result = 0;
  }
  else
  {
    gGameCommand = v10;
    result = 1;
  }
  return result;
}