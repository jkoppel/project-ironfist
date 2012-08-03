{
  signed int v1; // [sp+Ch] [bp-34h]@6
  heroWindow *this; // [sp+1Ch] [bp-24h]@1
  char a1; // [sp+20h] [bp-20h]@23
  int window; // [sp+38h] [bp-8h]@2
  int i; // [sp+3Ch] [bp-4h]@16

  this = (heroWindow *)operator new(68);
  if ( this )
    window = (int)heroWindow::heroWindow(this, 405, 8, "stphotst.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))SetupHotSeatGameHandler,
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
        iLastMsgNumHumanPlayers = 2;
        break;
      case 2:
        iLastMsgNumHumanPlayers = 3;
        break;
      case 3:
        iLastMsgNumHumanPlayers = 4;
        break;
      case 4:
        iLastMsgNumHumanPlayers = 5;
        break;
      case 5:
        iLastMsgNumHumanPlayers = 6;
        break;
      default:
        break;
    }
  }
  for ( i = 0; i < 6; ++i )
    strcpy(&cPlayerNames[21 * i], byte_51DA2C);
  if ( !giSetupGameType )
  {
    sprintf(gText, "Do you wish to enter each player's name?");
    NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( gpWindowManager->buttonPressedCode == 30725 )
    {
      for ( i = 0; i < iLastMsgNumHumanPlayers; ++i )
      {
        strcpy(&a1, byte_51DA5C);
        sprintf(gText, "Enter player %d's name.", i + 1);
        GetDataEntry(gText, (int)&cPlayerNames[21 * i], 20, &a1, 0, 1);
      }
    }
  }
  return 1;
}