{
  LogStr("RC1");
  if ( gbRemoteOn )
  {
    LogStr("RC2");
    if ( !gbInRemoteMain )
    {
      if ( !gbInRemoteCleanup )
      {
        gbInRemoteCleanup = 1;
        LogStr("RC3");
        switch ( GameMode )
        {
          case 1:
          case 2:
            UnloadRemoteDriver(1);
            break;
          case 3:
          case 4:
            UnloadRemoteDriver(0);
            break;
          default:
            break;
        }
        gbRemoteOn = 0;
        xNetHasOldPlayers = 0;
        iInOrderCtr = 0;
        iCurLastID = 0;
        dword_512578 = -1;
        GameMode = 0;
        lLastHeartbeatSend = 0;
        gbInRemoteMain = 0;
        iIDCtr = 0;
        iTimesDropped = 0;
        bUseDirectPlay = 0;
        bUseWinsock = 0;
        bInTimeoutFail = 0;
        iMPNetProtocol = 0;
        iLastDiffSendTo = -2;
        gbGotFirstHeartbeat = 0;
        gbInRemoteCleanup = 0;
      }
    }
  }
}