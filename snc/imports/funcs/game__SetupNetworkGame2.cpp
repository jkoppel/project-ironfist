{
  signed int v1; // [sp+Ch] [bp-ECh]@11
  heroWindow *this; // [sp+1Ch] [bp-DCh]@1
  int v3; // [sp+20h] [bp-D8h]@10
  int v4; // [sp+24h] [bp-D4h]@10
  int v5; // [sp+28h] [bp-D0h]@10
  int v6; // [sp+38h] [bp-C0h]@10
  int evt; // [sp+3Ch] [bp-BCh]@8
  int v8; // [sp+40h] [bp-B8h]@8
  int v9; // [sp+44h] [bp-B4h]@8
  int v10; // [sp+54h] [bp-A4h]@8
  int window; // [sp+58h] [bp-A0h]@2
  int v12; // [sp+5Ch] [bp-9Ch]@6
  HMODULE v13; // [sp+60h] [bp-98h]@9
  struct _OSVERSIONINFOA VersionInformation; // [sp+64h] [bp-94h]@6

  this = (heroWindow *)operator new(68);
  if ( this )
    window = (int)heroWindow::heroWindow(this, 405, 8, "stpnet2.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  memset(&VersionInformation, 0, 0x94u);
  VersionInformation.dwOSVersionInfoSize = 148;
  v12 = GetVersionExA(&VersionInformation);
  LogInt((int)"Version", v12, VersionInformation.dwPlatformId, -999, -999, -999, -999, -999);
  if ( v12 && VersionInformation.dwPlatformId == 2 )
  {
    evt = 512;
    v8 = 5;
    v10 = 4096;
    v9 = 3;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  v13 = 0;
  v13 = LoadLibraryA("DPLAYX.DLL");
  if ( !v13 )
  {
    v3 = 512;
    v4 = 5;
    v6 = 4096;
    v5 = 1;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&v3);
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))SetupNetworkGame2Handler,
    0);
  operator delete((void *)window);
  v1 = gpWindowManager->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        iMPNetProtocol = 1;
        break;
      case 2:
        iMPNetProtocol = 2;
        break;
      case 3:
        iMPNetProtocol = 3;
        break;
      case 4:
        iMPNetProtocol = 4;
        break;
      default:
        return game::SetupNetworkGame() != 0;
    }
  }
  return game::SetupNetworkGame() != 0;
}