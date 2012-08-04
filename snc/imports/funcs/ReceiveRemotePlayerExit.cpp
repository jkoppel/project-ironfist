{
  void *v2; // eax@2
  int v3; // eax@26
  signed int v4; // [sp+Ch] [bp-10h]@1
  int i; // [sp+10h] [bp-Ch]@15

  v4 = 0;
  lLastHeartbeatReceive[(char)a1] = 199999999;
  game::SaveGame(gpGame, "PLYREXIT", 1, 0);
  if ( (_BYTE)a2 )
  {
    BYTE2(a2) = 1;
    v2 = (void *)(char)a1;
    if ( (char)a1 == giThisNetPos )
    {
      v4 = 1;
    }
    else
    {
      sprintf(gText, "%s has been vanquished!", (char *)&gsNetPlayerInfo + 34 * (char)a1 + 4);
      v2 = NormalDialog(gText, 1, -1, -1, 9, gpGame->players[SBYTE1(a1)].color, -1, -1, -1, 5000);
      BYTE2(a2) = 1;
    }
  }
  else
  {
    if ( BYTE3(a1) )
      sprintf(
        gText,
        "%s has been timed out of the game.  The current game has been saved as 'PLYREXIT'.  Do you wish to continue playing with a computer player filling in for %s?",
        (char *)&gsNetPlayerInfo + 34 * (char)a1 + 4,
        (char *)&gsNetPlayerInfo + 34 * (char)a1 + 4);
    else
      sprintf(
        gText,
        "%s is exiting the game.  The current game has been saved as 'PLYREXIT'.  Do you wish to continue playing with a computer player filling in for %s?",
        (char *)&gsNetPlayerInfo + 34 * (char)a1 + 4,
        (char *)&gsNetPlayerInfo + 34 * (char)a1 + 4);
    NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
    v2 = gpWindowManager;
    BYTE2(a2) = gpWindowManager->buttonPressedCode == 30725;
  }
  if ( iLastMsgNumHumanPlayers == 2 )
  {
    if ( (_BYTE)a2 && !BYTE1(a2) )
      TransmitRemoteData(&a1, 1 - giThisNetPos, 7u, 33, 1, 1, -1);
    if ( !v4 )
    {
      --iLastMsgNumHumanPlayers;
      gbHumanPlayer[SBYTE1(a1)] = 0;
      RemoteCleanup();
      ComputeAdvNetControl();
    }
  }
  else
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( (char)a1 != i || !(_BYTE)a2 || BYTE1(a2) )
      {
        v2 = (void *)(char)a1;
        if ( (char)a1 == i )
          continue;
        v2 = (void *)iLastMsgNumHumanPlayers;
        if ( i >= iLastMsgNumHumanPlayers )
          continue;
        v2 = (void *)i;
        if ( giThisNetPos == i )
          continue;
      }
      v2 = (void *)TransmitRemoteData(&a1, i, 7u, 33, 1, 1, -1);
    }
    if ( !v4 )
    {
      LOBYTE(v2) = BYTE2(a2);
      v3 = (_DWORD)v2 << 16;
      LOWORD(v3) = a2;
      ReceiveHostReportsPlayerExit(0, 1, a1, v3);
    }
  }
  if ( v4 )
  {
    sprintf(gText, "You have been eliminated from the game!!!");
    RemoteCleanup();
    NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    gbGameOver = 1;
    giEndSequence = 0;
  }
  else if ( !BYTE2(a2) )
  {
    ShutDown(0);
  }
}