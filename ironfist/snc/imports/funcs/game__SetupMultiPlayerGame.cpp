{
  signed int v1; // [sp+Ch] [bp-38h]@8
  heroWindow *this; // [sp+1Ch] [bp-28h]@1
  signed int v3; // [sp+20h] [bp-24h]@17
  int evt; // [sp+24h] [bp-20h]@7
  int v5; // [sp+28h] [bp-1Ch]@7
  int v6; // [sp+2Ch] [bp-18h]@7
  int v7; // [sp+3Ch] [bp-8h]@7
  int window; // [sp+40h] [bp-4h]@2

  this = (heroWindow *)operator new(68);
  if ( this )
    window = (int)heroWindow::heroWindow(this, 405, 8, "stpmp.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  if ( gbNoCDRom )
  {
    evt = 512;
    v5 = 5;
    v6 = 1;
    v7 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))SetupMultiPlayerGameHandler,
    0);
  operator delete((void *)window);
  gbDirectConnect = 0;
  v1 = gpWindowManager->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        iMPBaseType = 2;
        if ( game::SetupHotSeatGame() )
          return 1;
        return 0;
      case 2:
        iMPBaseType = 1;
        if ( game::SetupNetworkGame2() )
          return 1;
        return 0;
      case 4:
        gbDirectConnect = 1;
        break;
      case 3:
        gbDirectConnect = 0;
        break;
      default:
        return 1;
    }
    iMPBaseType = 0;
    v3 = 1;
    LogStr("Common Modem 1");
    while ( v3 )
    {
      LogStr("Common Modem 2");
      if ( !game::SetupModemGame() )
        return 0;
      LogStr("Common Modem 3");
      if ( gbDoModemConfig )
      {
        LogStr("Common Modem 4");
        gbDoModemConfig = 0;
        if ( !game::SetupComPort() )
          return 0;
        LogStr("Common Modem 5");
      }
      else
      {
        v3 = 0;
      }
      LogStr("Common Modem 6");
    }
    LogStr("Common Modem 7");
  }
  return 1;
}