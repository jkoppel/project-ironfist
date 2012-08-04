{
  int v1; // ST0C_4@5
  char *v2; // eax@5
  int evt; // [sp+Ch] [bp-1Ch]@5
  int v4; // [sp+10h] [bp-18h]@5
  int v5; // [sp+14h] [bp-14h]@5
  int v6; // [sp+24h] [bp-4h]@5

  wsProcessMessages();
  if ( iLastMsgNumHumanPlayers != iWSLastMsgNumHumanPlayers )
  {
    if ( giTCPHostStatus != -1 && giTCPNumPlayers <= iLastMsgNumHumanPlayers )
      return 1;
    iWSLastMsgNumHumanPlayers = iLastMsgNumHumanPlayers;
    v1 = iLastMsgNumHumanPlayers - 1;
    v2 = thunk_inet_ntoa(gIn_addrIP);
    sprintf(
      cWSTextBuffer,
      "Hosting game at %s.\n\nYou have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
      v2,
      v1);
    evt = 512;
    v4 = 3;
    v5 = 1;
    v6 = (int)cWSTextBuffer;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&evt);
    heroWindow::DrawWindow(pNormalDialogWindow);
  }
  return 0;
}