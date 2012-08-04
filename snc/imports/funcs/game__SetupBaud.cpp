{
  signed int v1; // [sp+Ch] [bp-18h]@6
  heroWindow *this; // [sp+1Ch] [bp-8h]@1
  heroWindow *window; // [sp+20h] [bp-4h]@2

  this = (heroWindow *)operator new(68);
  if ( this )
    window = heroWindow::heroWindow(this, 405, 8, "stpbaud.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  heroWindowManager::DoDialog(gpWindowManager, window, (int (__fastcall *)(tag_message *))SetupBaudHandler, 0);
  operator delete(window);
  v1 = gpWindowManager->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        *((_DWORD *)&modemBaudRate + gbDirectConnect) = 2400;
        break;
      case 2:
        *((_DWORD *)&modemBaudRate + gbDirectConnect) = 9600;
        break;
      case 3:
        *((_DWORD *)&modemBaudRate + gbDirectConnect) = 19200;
        break;
      case 4:
        *((_DWORD *)&modemBaudRate + gbDirectConnect) = 38400;
        break;
      default:
        return 1;
    }
  }
  return 1;
}