{
  int v1; // edx@41
  char *v2; // edi@44
  int v3; // esi@44
  int v4; // edx@59
  void *v5; // [sp+14h] [bp-6Ch]@1
  signed int v6; // [sp+1Ch] [bp-64h]@39
  char v7[8]; // [sp+20h] [bp-60h]@39
  void *v8; // [sp+28h] [bp-58h]@41
  int v9; // [sp+2Ch] [bp-54h]@44
  void *v10; // [sp+34h] [bp-4Ch]@56
  int i; // [sp+38h] [bp-48h]@1
  int a2; // [sp+7Ch] [bp-4h]@5

  v5 = this;
  gbInRemoteMain = 1;
  bGotGameType = 0;
  LogStr("In Remote Main");
  LogStr("RM 1");
  for ( i = 0; i < 6; ++i )
  {
    lLastHeartbeatReceive[i] = 1999999999;
    sprintf((char *)&gsNetPlayerInfo + 34 * i + 4, "Player %d", i + 1);
  }
  LogStr("RM 2");
  gbRemoteGameOpen = 1;
  if ( bLastMouseOffscreen )
    a2 = bLastOnscreenMouseColor;
  else
    a2 = gbColorMice;
  mouseManager::SetColorMice(gpMouseManager, 0);
  LogStr("RM 3");
  gbInNetSetup = 1;
  if ( iMPNetProtocol == 1 )
  {
    bUseDirectPlay = 1;
  }
  else if ( iMPNetProtocol == 2 )
  {
    bUseWinsock = 1;
  }
  else
  {
    bUseWinsock = 0;
    bUseDirectPlay = 0;
  }
  LogStr("RM 4");
  memset(&sMapChangeQueue, 0, 0x86Cu);
  for ( i = 0; i < 128; ++i )
    rcvBuf[i] = 0;
  LogStr("RM 5");
  memset(&iLastIds, 0, 0x1Eu);
  GameMode = (char)v5;
  LogStr("RM 6");
  memset(&gsNetPlayerInfo, 0, 0xCCu);
  memset(&gsThisNetPlayerInfo, 0, 0x22u);
  LogStr("RM 7");
  if ( giTCPHostStatus == -1 )
  {
    GetDataEntry(
      "Please enter a 'handle' by which you will be known.",
      (int)&unk_526CBC,
      20,
      (const char *)&gConfig + 392,
      1u,
      0);
  }
  else if ( strlen((int)gcTCPName) )
  {
    strcpy((char *)&gsThisNetPlayerInfo + 4, gcTCPName);
  }
  else
  {
    strcpy((char *)&gsThisNetPlayerInfo + 4, (char *)&gConfig + 392);
  }
  strcpy((char *)&gConfig + 392, (char *)&gsThisNetPlayerInfo + 4);
  WritePrefs();
  strcpy((char *)&gsThisNetPlayerInfo, (char *)&gConfig + 290);
  byte_526CD1 = 2;
  byte_526CD2 = 1;
  byte_526CD3 = 1;
  byte_526CD4 = 1;
  xNetHasOldPlayers = 0;
  switch ( v5 )
  {
    case 1u:
      memcpy(&gsNetPlayerInfo, &gsThisNetPlayerInfo, 0x22u);
      giThisNetPos = 0;
      goto LABEL_24;
    case 2u:
      giThisNetPos = 1;
LABEL_24:
      if ( bUseDirectPlay )
      {
        gbRemoteOn = 1;
        dpnet_init();
      }
      else if ( bUseWinsock )
      {
        wsnet_init();
        gbRemoteOn = 1;
      }
      else
      {
        nbnet_init();
        gbRemoteOn = 1;
      }
      break;
    case 3u:
      LogStr("MH1");
      gbRemoteOn = 1;
      memcpy(&gsNetPlayerInfo, &gsThisNetPlayerInfo, 0x22u);
      giThisNetPos = 0;
      ModemSetup(v5);
      LogStr("MH2");
      break;
    case 4u:
      gbRemoteOn = 1;
      giThisNetPos = 1;
      ModemSetup(v5);
      break;
    default:
      break;
  }
  if ( !bUseDirectPlay && !bUseWinsock )
    iLastMsgNumHumanPlayers = 2;
  iIDCtr = 100000000 * (giThisNetPos + 1);
  gbInNetSetup = 0;
  mouseManager::SetColorMice(gpMouseManager, a2);
  if ( !bUseDirectPlay && !bUseWinsock )
  {
    LogStr("RM 2");
    if ( giThisNetPos )
    {
      LogStr("RM 5");
      TransmitRemoteData(&gsThisNetPlayerInfo, 0, 0x22u, 34, 1, 1, -1);
      LogStr("RM 6");
    }
    else
    {
      v6 = 1;
      memset(v7, 0, 6u);
      while ( v6 )
      {
        PollSound();
        LogStr("RM 3");
        v8 = GetRemoteData(1, v1);
        LogStr("RM 4");
        if ( v8 )
        {
          if ( *((_BYTE *)v8 + 5) == 2 )
          {
            if ( *((_BYTE *)v8 + 6) == 34 )
            {
              v9 = *(_BYTE *)v8;
              v2 = (char *)&gsNetPlayerInfo + 34 * v9;
              v3 = (int)((char *)v8 + 9);
              memcpy(v2, (char *)v8 + 9, 0x20u);
              *((_WORD *)v2 + 16) = *(_WORD *)(v3 + 32);
              v7[v9] = 1;
              if ( !byte_526CFC[34 * v9] )
                xNetHasOldPlayers = 1;
            }
          }
        }
        v6 = 0;
        for ( i = 1; iLastMsgNumHumanPlayers > i; ++i )
        {
          if ( !v7[i] )
            v6 = 1;
        }
      }
    }
  }
  v10 = 0;
  if ( giThisNetPos )
  {
    while ( !bGotGameType )
    {
      PollSound();
      v10 = GetRemoteData(1, v4);
      if ( v10 && *((_BYTE *)v10 + 5) == 2 && *((_BYTE *)v10 + 6) == 62 )
      {
        bGotGameType = 1;
        giSetupGameType = 1;
      }
      if ( v10 && *((_BYTE *)v10 + 5) == 2 && *((_BYTE *)v10 + 6) == 61 )
      {
        bGotGameType = 1;
        giSetupGameType = 0;
      }
    }
  }
  else
  {
    TransmitRemoteData(0, 127, 0, ((unsigned int)(unsigned __int8)giSetupGameType - 1 < 1) + 61, 1, 1, -1);
  }
  LogStr("Out Remote Main");
  gbInRemoteMain = 0;
}