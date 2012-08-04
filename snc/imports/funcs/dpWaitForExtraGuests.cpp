{
  int evt; // [sp+Ch] [bp-1Ch]@2
  int v2; // [sp+10h] [bp-18h]@2
  int v3; // [sp+14h] [bp-14h]@2
  char *v4; // [sp+24h] [bp-4h]@2

  dpProcessMessages();
  if ( giNumHumanPlayers != iLastMsgNumHumanPlayers )
  {
    giNumHumanPlayers = iLastMsgNumHumanPlayers;
    sprintf(
      gText,
      "You have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
      iLastMsgNumHumanPlayers - 1);
    evt = 512;
    v2 = 3;
    v3 = 1;
    v4 = gText;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&evt);
    heroWindow::DrawWindow(pNormalDialogWindow);
  }
  return 0;
}