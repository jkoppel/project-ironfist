{
  int v2; // [sp+14h] [bp-28h]@1
  int evt; // [sp+18h] [bp-24h]@18
  int v4; // [sp+1Ch] [bp-20h]@18
  int v5; // [sp+20h] [bp-1Ch]@18
  int v6; // [sp+30h] [bp-Ch]@18
  char *v7; // [sp+34h] [bp-8h]@1
  int i; // [sp+38h] [bp-4h]@5

  v2 = a1;
  v7 = &rcvBufIn[1];
  switch ( rcvBufIn[0] )
  {
    case 1:
      *((_DWORD *)ppDPRcvBuffer + iDPRcvBufferHead) = BaseAlloc(
                                                        a1 - 1,
                                                        "F:\\h2xsrc\\Source\\Wsnetwin.cpp",
                                                        word_511CE0 + 10);
      memcpy(*((void **)ppDPRcvBuffer + iDPRcvBufferHead), &rcvBufIn[1], v2 - 1);
      *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferHead) = v2;
      iDPRcvBufferHead = (iDPRcvBufferHead + 1) % 200;
      break;
    case 2:
      if ( (unsigned __int8)GameMode == 1 )
      {
        if ( gbRemoteGameOpen )
        {
          for ( i = 1; i < iLastMsgNumHumanPlayers; ++i )
          {
            if ( *((_DWORD *)&giNetPosToDCOPos + i) == a2 || (char *)&gsNetPlayerInfo + 34 * i == v7 )
            {
              wsSendMessage(*((_DWORD *)&giNetPosToDCOPos + i), 4, 0, 0);
              return;
            }
          }
          *((_DWORD *)&giNetPosToDCOPos + iLastMsgNumHumanPlayers) = a2;
          LogInt((int)"Got HereIAm from ", a2, -999, -999, -999, -999, -999, -999);
          memcpy((char *)&gsNetPlayerInfo + 34 * iLastMsgNumHumanPlayers, v7, 0x22u);
          if ( !byte_526CFC[34 * iLastMsgNumHumanPlayers] )
            xNetHasOldPlayers = 1;
          wsSendMessage(*((_DWORD *)&giNetPosToDCOPos + iLastMsgNumHumanPlayers++), 4, 0, 0);
        }
        else
        {
          wsSendMessage(a2, 5, 0, 0);
        }
      }
      break;
    case 3:
      iLastMsgNumHumanPlayers = *v7;
      giThisNetPos = v7[1];
      LogInt((int)"WSMSGSTARTUP", giThisNetPos, a2, -999, -999, -999, -999, -999);
      memcpy(&giNetPosToDCOPos, v7 + 2, 0x18u);
      bStartUpInfoReceived = 1;
      break;
    case 5:
      sprintf(cWSTextBuffer, "The Host already has a game in progress and is not accepting new players.");
      NormalDialog(cWSTextBuffer, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      ShutDown(0);
      break;
    case 4:
      sprintf(cWSTextBuffer, "Waiting for other remote player to set up game.");
      evt = 512;
      v4 = 3;
      v5 = 1;
      v6 = (int)cWSTextBuffer;
      heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&evt);
      heroWindow::DrawWindow(pNormalDialogWindow);
      bHostFound = 1;
      break;
    default:
      sprintf(cWSTextBuffer, "Unknown message: %d\n", rcvBufIn[0]);
      if ( giDebugLevel > 0 )
      {
        sprintf(gText, cWSTextBuffer);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      LogStr(cWSTextBuffer);
      break;
  }
}