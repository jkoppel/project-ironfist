{
  signed int v1; // [sp+Ch] [bp-40h]@23
  heroWindow *v2; // [sp+1Ch] [bp-30h]@16
  heroWindow *v3; // [sp+20h] [bp-2Ch]@12
  heroWindow *v4; // [sp+24h] [bp-28h]@7
  heroWindow *this; // [sp+28h] [bp-24h]@3
  int evt; // [sp+2Ch] [bp-20h]@22
  int v7; // [sp+30h] [bp-1Ch]@22
  int v8; // [sp+34h] [bp-18h]@22
  int v9; // [sp+44h] [bp-8h]@22
  int window; // [sp+48h] [bp-4h]@4

  LogStr("SMC 1");
  if ( gbDirectConnect )
  {
    if ( *((_DWORD *)&modemComPort + gbDirectConnect) )
    {
      v4 = (heroWindow *)operator new(68);
      if ( v4 )
        window = (int)heroWindow::heroWindow(v4, 405, 8, "stpdccfg.bin");
      else
        window = 0;
    }
    else
    {
      this = (heroWindow *)operator new(68);
      if ( this )
        window = (int)heroWindow::heroWindow(this, 405, 8, "stpdc.bin");
      else
        window = 0;
    }
  }
  else if ( *((_DWORD *)&modemComPort + gbDirectConnect) )
  {
    v2 = (heroWindow *)operator new(68);
    if ( v2 )
      window = (int)heroWindow::heroWindow(v2, 405, 8, "stpmcfg.bin");
    else
      window = 0;
  }
  else
  {
    v3 = (heroWindow *)operator new(68);
    if ( v3 )
      window = (int)heroWindow::heroWindow(v3, 405, 8, "stpmodem.bin");
    else
      window = 0;
  }
  if ( !window )
    MemError();
  LogStr("SMC 2");
  if ( gbNoCDRom )
  {
    evt = 512;
    v7 = 5;
    v8 = 1;
    v9 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  LogStr("SMC 3");
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))SetupModemGameHandler,
    0);
  LogStr("SMC 4");
  operator delete((void *)window);
  LogStr("SMC 5");
  v1 = gpWindowManager->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        LogStr("SMC 6");
        iMPExtendedType = 3;
        if ( !*((_DWORD *)&modemComPort + gbDirectConnect) )
        {
          LogStr("SMC 7");
          if ( !game::SetupComPort() )
            return 0;
          LogStr("SMC 8");
        }
        LogStr("SMC 9");
        if ( !gbDirectConnect )
          GetDataEntry("Please enter the telephone number.", (int)&numbuf, 35, 0, 0, 1);
        LogStr("SMC a");
        break;
      case 2:
        iMPExtendedType = 4;
        if ( !*((_DWORD *)&modemComPort + gbDirectConnect) && !game::SetupComPort() )
          return 0;
        break;
      case 3:
        gbDoModemConfig = 1;
        break;
    }
  }
  return 1;
}