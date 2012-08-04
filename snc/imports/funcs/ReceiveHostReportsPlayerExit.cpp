{
  heroWindow *result; // eax@4
  int v5; // [sp+10h] [bp-200h]@1
  char msg; // [sp+14h] [bp-1FCh]@12
  int v7; // [sp+208h] [bp-8h]@1
  int i; // [sp+20Ch] [bp-4h]@17

  v5 = a1;
  v7 = 0;
  if ( !a2 )
  {
    if ( (_BYTE)a4 )
    {
      if ( (char)a3 == giThisNetPos )
      {
        RemoteCleanup();
        sprintf(gText, "You have been eliminated from the game!!!");
        result = NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        gbGameOver = 1;
        giEndSequence = 0;
        return result;
      }
      sprintf(gText, "%s has been vanquished!", (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4);
      NormalDialog(gText, 1, -1, -1, 9, gpGame->players[SBYTE1(a3)].color, -1, -1, -1, 5000);
    }
    else if ( BYTE2(a4) )
    {
      if ( BYTE3(a3) )
        sprintf(
          &msg,
          "Host player %s reports that player %s has been timed out of the game.  The game will continue with a computer player filling in for %s.",
          (char *)&gsNetPlayerInfo + 34 * a1 + 4,
          (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4,
          (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4);
      else
        sprintf(
          &msg,
          "Host player %s reports that player %s has exited the game.  The game will continue with a computer player filling in for %s.",
          (char *)&gsNetPlayerInfo + 34 * a1 + 4,
          (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4,
          (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4);
      v7 = 1;
    }
    else
    {
      game::SaveGame(gpGame, "PLYREXIT", 1, 0);
      sprintf(
        gText,
        "%s left the game, and the %s decided to terminate the entire game.  The game has been saved as 'PLYREXIT'.  Do you wish to play on alone with the computer taking over for all human players?",
        (char *)&gsNetPlayerInfo + 34 * (char)a3 + 4,
        (char *)&gsNetPlayerInfo + 34 * v5 + 4);
      NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        DropDownToOnePlayer();
      }
      else
      {
        RemoteCleanup();
        ShutDown(0);
      }
    }
  }
  if ( (char)a3 < giThisNetPos )
    --giThisNetPos;
  gbHumanPlayer[SBYTE1(a3)] = 0;
  for ( i = (char)a3; i < 5; ++i )
  {
    lLastHeartbeatReceive[i] = dword_526DB4[i];
    *((_DWORD *)&giNetPosToDCOPos + i) = dword_522B7C[i];
    strcpy((char *)&gsNetPlayerInfo + 34 * i + 4, (char *)&gsNetPlayerInfo + 34 * (i + 1) + 4);
  }
  for ( i = 0; i < 6; ++i )
  {
    if ( *((_BYTE *)&gbGamePosToNetPos + i) == (char)a3 )
    {
      *((_BYTE *)&gbGamePosToNetPos + i) = -1;
    }
    else if ( *((_BYTE *)&gbGamePosToNetPos + i) > (char)a3 )
    {
      --*((_BYTE *)&gbGamePosToNetPos + i);
    }
  }
  --iLastMsgNumHumanPlayers;
  iLastDiffSendTo = -2;
  result = (heroWindow *)SBYTE2(a3);
  if ( BYTE2(a3) )
    result = (heroWindow *)ComputeAdvNetControl();
  if ( v7 )
    result = NormalDialog(&msg, 1, -1, -1, -1, -1, -1, -1, -1, 5000);
  return result;
}