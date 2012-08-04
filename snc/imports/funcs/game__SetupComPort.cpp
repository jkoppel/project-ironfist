{
  signed int result; // eax@11
  signed int v1; // [sp+Ch] [bp-40h]@6
  heroWindow *this; // [sp+1Ch] [bp-30h]@1
  heroWindow *window; // [sp+20h] [bp-2Ch]@2
  char a2; // [sp+24h] [bp-28h]@18

  LogStr("SCP 1");
  this = (heroWindow *)operator new(68);
  if ( this )
    window = heroWindow::heroWindow(this, 405, 8, "stpcom.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  LogStr("SCP 2");
  heroWindowManager::DoDialog(gpWindowManager, window, (int (__fastcall *)(tag_message *))SetupComPortHandler, 0);
  operator delete(window);
  LogStr("SCP 3");
  v1 = gpWindowManager->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        *((_DWORD *)&modemComPort + gbDirectConnect) = 1;
        break;
      case 2:
        *((_DWORD *)&modemComPort + gbDirectConnect) = 2;
        break;
      case 3:
        *((_DWORD *)&modemComPort + gbDirectConnect) = 3;
        break;
      case 4:
        *((_DWORD *)&modemComPort + gbDirectConnect) = 4;
        break;
      default:
        break;
    }
  }
  LogStr("SCP 4");
  if ( game::SetupBaud() )
  {
    LogStr("SCP 5");
    if ( !gbDirectConnect )
    {
      strcpy((char *)&gConfig + 174, "ATZ");
      sprintf(gText, "%s", &gConfig + 174);
      GetDataEntry(
        "Please enter any special initialization string required by your modem, or hit 'ENTER' to accept the default.",
        (int)&a2,
        40,
        gText,
        0,
        1);
      strcpy((char *)&gConfig + 174, &a2);
    }
    WritePrefs();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}