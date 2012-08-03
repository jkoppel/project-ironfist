{
  int v1; // [sp+Ch] [bp-34h]@8
  heroWindow *this; // [sp+1Ch] [bp-24h]@1
  int evt; // [sp+20h] [bp-20h]@7
  int v4; // [sp+24h] [bp-1Ch]@7
  int v5; // [sp+28h] [bp-18h]@7
  int v6; // [sp+38h] [bp-8h]@7
  int window; // [sp+3Ch] [bp-4h]@2

  this = (heroWindow *)operator new(68);
  if ( this )
    window = (int)heroWindow::heroWindow(this, 405, 8, "stpnet.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  if ( gbNoCDRom )
  {
    evt = 512;
    v4 = 5;
    v5 = 1;
    v6 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))SetupNetworkGameHandler,
    0);
  operator delete((void *)window);
  v1 = gpWindowManager->buttonPressedCode;
  switch ( v1 )
  {
    case 1:
      iMPExtendedType = 1;
      break;
    case 2:
      iMPExtendedType = 2;
      break;
    case 30721:
      return 0;
  }
  return 1;
}