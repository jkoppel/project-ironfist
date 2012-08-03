{
  signed int result; // eax@2
  int v1; // [sp+Ch] [bp-40h]@15
  int v2; // [sp+28h] [bp-24h]@25
  heroWindow *this; // [sp+30h] [bp-1Ch]@10
  heroWindow *window; // [sp+34h] [bp-18h]@11
  char v5; // [sp+3Ch] [bp-10h]@4
  baseManager *a2; // [sp+48h] [bp-4h]@26

  if ( gbWaitForRemoteReceive )
    return 1;
  if ( gbInCampaign )
  {
    sprintf(&v5, "*.GMC");
  }
  else if ( xIsPlayingExpansionCampaign )
  {
    sprintf(&v5, "*.GXC");
  }
  else if ( gbRemoteOn && xNetHasOldPlayers )
  {
    NormalDialog(
      "At least one player does not have the Heroes II Expansion set.  You will only be able to choose from original Heroes II games.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    sprintf(&v5, "*.GM%d", iLastMsgNumHumanPlayers);
  }
  else
  {
    this = (heroWindow *)operator new(68);
    if ( this )
      window = heroWindow::heroWindow(this, 405, 8, "x_mapmnu.bin");
    else
      window = 0;
    if ( !window )
      MemError();
    heroWindowManager::DoDialog(gpWindowManager, window, (int (__fastcall *)(tag_message *))ExpStdGameHandler, 0);
    operator delete(window);
    v1 = LOWORD(gpWindowManager->buttonPressedCode);
    switch ( v1 )
    {
      case 1:
        LOBYTE(xIsExpansionMap) = 0;
        break;
      case 2:
        LOBYTE(xIsExpansionMap) = 1;
        break;
      case 30721:
        return 0;
    }
    if ( xIsExpansionMap )
      sprintf(&v5, "*.GX%d", iLastMsgNumHumanPlayers);
    else
      sprintf(&v5, "*.GM%d", iLastMsgNumHumanPlayers);
  }
  v2 = (int)operator new(1071);
  if ( v2 )
    a2 = (baseManager *)fileRequester::fileRequester(v2, 200, 58, 2, &v5, ".\\GAMES\\", &v5);
  else
    a2 = 0;
  if ( !a2 )
    MemError();
  if ( executive::DoDialog(gpExec, a2) == 30722 )
  {
    game::LoadGame(gpGame, gLastFilename, 0, 0);
    operator delete(a2);
    result = 1;
  }
  else
  {
    operator delete(a2);
    result = 0;
  }
  return result;
}