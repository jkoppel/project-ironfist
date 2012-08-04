{
  int v0; // ST40_4@29
  int v1; // eax@29
  int v2; // ST34_4@43
  int v3; // eax@43
  int a2; // [sp+Ch] [bp-30h]@18
  __int16 v5; // [sp+18h] [bp-24h]@0
  char v6; // [sp+1Ah] [bp-22h]@0
  signed int v7; // [sp+1Ch] [bp-20h]@33
  __int16 v8; // [sp+24h] [bp-18h]@0
  char v9; // [sp+26h] [bp-16h]@0
  char v10; // [sp+28h] [bp-14h]@12
  void *i; // [sp+2Ch] [bp-10h]@22
  signed int j; // [sp+2Ch] [bp-10h]@48
  signed int k; // [sp+2Ch] [bp-10h]@69
  signed int l; // [sp+2Ch] [bp-10h]@74
  signed int m; // [sp+2Ch] [bp-10h]@78
  int v16; // [sp+30h] [bp-Ch]@12
  signed int v17; // [sp+34h] [bp-8h]@55
  int v18; // [sp+38h] [bp-4h]@12

  if ( gbRemoteOn && !gbInRemoteCleanup )
  {
    if ( iMPBaseType )
    {
      if ( iMPBaseType == 1 )
      {
        if ( bUseDirectPlay )
        {
          dpProcessMessages();
        }
        else if ( bUseWinsock )
        {
          wsProcessMessages();
        }
        else
        {
          nb_thr_ctl();
        }
      }
    }
    else
    {
      comm_wrt_task();
    }
    if ( !gbInNetSetup )
    {
      v16 = 0;
      v18 = gbInPollSound;
      v10 = 0;
      if ( KBTickCount() - lLastHeartbeatSend > 5000 )
      {
        sndBuf = giThisNetPos;
        byte_52710D = 4;
        word_52710F = 0;
        if ( gbThisNetGotAdventureControl )
          byte_52710E = iCurHourGlassPhase | (unsigned __int8)(16 * (giCurPlayer + 1)) | 0x80;
        else
          byte_52710E = 0;
        if ( giThisNetPos && !gbThisNetGotAdventureControl )
          a2 = 0;
        else
          a2 = 127;
        SendRemoteData((int)&sndBuf, a2, 0xAu);
        lLastHeartbeatSend = KBTickCount();
      }
      if ( giThisNetPos )
      {
        v7 = 60000;
        if ( giThisNetPos != 1 )
          v7 = 90000;
        if ( KBTickCount() > v7 + lLastHeartbeatReceive[0] && !bInTimeoutFail )
        {
          bInTimeoutFail = 1;
          gbInPollSound = 0;
          if ( giThisNetPos == 1 )
            sprintf(
              gText,
              "%s's computer is not responding.  Do you wish to keep waiting for a response?",
              (char *)&gsNetPlayerInfo + 4);
          else
            sprintf(
              gText,
              "Your remote connection to the other players appears to be broken.  Do you wish to keep waiting for a response?");
          NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( gpWindowManager->buttonPressedCode == 30725 )
          {
            lLastHeartbeatReceive[0] = KBTickCount();
          }
          else if ( giThisNetPos == 1 )
          {
            LOBYTE(v2) = 0;
            v3 = NetPosToGamePos(0);
            BYTE1(v2) = v3;
            HIWORD(v2) = 257;
            LOBYTE(v5) = 0;
            LOBYTE(v3) = v6;
            v3 <<= 16;
            LOWORD(v3) = v5;
            ReceiveRemotePlayerExit(v2, v3);
          }
          else
          {
            game::SaveGame(gpGame, "PLYREXIT", 1, 0);
            sprintf(
              gText,
              "The current game has been saved as 'PLYREXIT'. Do you wish to keep playing with the computer filling in for the other humans?");
            NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
            if ( gpWindowManager->buttonPressedCode == 30725 )
              DropDownToOnePlayer();
            else
              ShutDown(byte_5128E8);
          }
          gbInPollSound = v18;
          bInTimeoutFail = 1;
        }
      }
      else
      {
        for ( i = 0; iLastMsgNumHumanPlayers > (signed int)i; i = (char *)i + 1 )
        {
          if ( (void *)giThisNetPos != i
            && lLastHeartbeatReceive[(signed int)i] + 60000 < KBTickCount()
            && !bInTimeoutFail )
          {
            bInTimeoutFail = 1;
            gbInPollSound = 0;
            sprintf(
              gText,
              "%s's computer is not responding.  Do you wish to keep waiting for a response?",
              (char *)&gsNetPlayerInfo + 34 * (_DWORD)i + 4);
            NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
            if ( gpWindowManager->buttonPressedCode == 30725 )
            {
              lLastHeartbeatReceive[(signed int)i] = KBTickCount();
            }
            else
            {
              LOBYTE(v0) = (_BYTE)i;
              v1 = NetPosToGamePos(i);
              BYTE1(v0) = v1;
              HIWORD(v0) = 257;
              LOBYTE(v8) = 0;
              LOBYTE(v1) = v9;
              v1 <<= 16;
              LOWORD(v1) = v8;
              ReceiveRemotePlayerExit(v0, v1);
            }
            gbInPollSound = v18;
            bInTimeoutFail = 0;
          }
        }
      }
      for ( j = 0; j < 128; ++j )
      {
        if ( rcvBuf[j] )
          ++v16;
      }
      if ( v16 == 128 )
        v10 = 1;
      v17 = 1;
      while ( v17 )
      {
LABEL_57:
        v17 = ReceiveRemoteData(0, rcvBufIn, 127);
        if ( v17 && rcvBufIn[0] != giThisNetPos )
        {
          if ( byte_52732D == 1 )
          {
            dword_512578 = dword_527329;
            return;
          }
          if ( byte_52732D == 4 )
          {
            lLastHeartbeatReceive[rcvBufIn[0]] = KBTickCount();
            if ( byte_52732E & 0x80 && !gbThisNetGotAdventureControl )
              LODWORD(iCurHourGlassPhase) = byte_52732E & 0xF;
            return;
          }
          if ( v10 )
            return;
          if ( byte_52732D == 2 )
          {
            sndBuf = giThisNetPos;
            dword_527109 = dword_527329;
            byte_52710D = 1;
            word_52710F = 0;
            SendRemoteData((int)&sndBuf, rcvBufIn[0], 9u);
          }
          for ( k = 0; k < 128; ++k )
          {
            if ( rcvBuf[k] && *(_DWORD *)(rcvBuf[k] + 1) == dword_527329 )
              goto LABEL_57;
          }
          for ( l = 0; l < 30; ++l )
          {
            if ( *((_DWORD *)&iLastIds + l) == dword_527329 )
              goto LABEL_57;
          }
          for ( m = 0; m < 128; ++m )
          {
            if ( !rcvBuf[m] )
            {
              rcvBuf[m] = (int)BaseAlloc(0x100u, "F:\\h2xsrc\\Source\\REMOTE.CPP", word_512748 + 235);
              iInOrder[m] = iInOrderCtr++;
              memcpy((void *)rcvBuf[m], rcvBufIn, 0x100u);
              ++v16;
              *((_DWORD *)&iLastIds + iCurLastID) = dword_527329;
              iCurLastID = (iCurLastID + 1) % 30;
              if ( v16 == 128 )
                return;
              goto LABEL_57;
            }
          }
        }
      }
    }
  }
}