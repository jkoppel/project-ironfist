{
  int v2; // [sp+14h] [bp-Ch]@1
  signed int i; // [sp+18h] [bp-8h]@4
  const void *v4; // [sp+1Ch] [bp-4h]@1

  v2 = a1;
  v4 = &rcvBufIn[1];
  switch ( rcvBufIn[0] )
  {
    case 1:
      *((_DWORD *)ppDPRcvBuffer + iDPRcvBufferHead) = BaseAlloc(
                                                        a1 - 1,
                                                        "F:\\h2xsrc\\Source\\dpnetwin.cpp",
                                                        word_4ED5D0 + 8);
      memcpy(*((void **)ppDPRcvBuffer + iDPRcvBufferHead), &rcvBufIn[1], v2 - 1);
      *((_DWORD *)piDPRcvBufferSize + iDPRcvBufferHead) = v2;
      iDPRcvBufferHead = (iDPRcvBufferHead + 1) % 200;
      break;
    case 2:
      if ( (unsigned __int8)GameMode == 1 )
      {
        for ( i = 1; i < iLastMsgNumHumanPlayers; ++i )
        {
          if ( *((_DWORD *)&giNetPosToDCOPos + i) == a2 )
          {
            dpSendMessage(a2, 4, 0, 0);
            return;
          }
        }
        if ( gbRemoteGameOpen )
        {
          *((_DWORD *)&giNetPosToDCOPos + iLastMsgNumHumanPlayers) = a2;
          memcpy((char *)&gsNetPlayerInfo + 34 * iLastMsgNumHumanPlayers, v4, 0x22u);
          if ( !byte_526CFC[34 * iLastMsgNumHumanPlayers] )
            xNetHasOldPlayers = 1;
          dpSendMessage(a2, 4, 0, 0);
          ++iLastMsgNumHumanPlayers;
        }
        else
        {
          dpSendMessage(a2, 5, 0, 0);
        }
      }
      break;
    case 4:
      giHostAcceptStatus = 1;
      break;
    case 5:
      giHostAcceptStatus = 2;
      break;
    case 3:
      iLastMsgNumHumanPlayers = *(_BYTE *)v4;
      giThisNetPos = rcvBufIn[2];
      LogInt((int)"DPMSGSTARTUP", giThisNetPos, a2, -999, -999, -999, -999, -999);
      memcpy(&giNetPosToDCOPos, &rcvBufIn[3], 0x18u);
      bStartUpInfoReceived = 1;
      break;
    default:
      sprintf(gText, "Unknown message: %d\n", rcvBufIn[0]);
      LogStr(gText);
      break;
  }
}