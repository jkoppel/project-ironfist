{
  int v0; // eax@4
  int v1; // eax@6
  int v2; // eax@8
  int v3; // eax@10
  int v4; // eax@12
  char *v5; // eax@13
  int v6; // ST1C_4@15
  char *v7; // eax@15
  char *v8; // eax@16
  int v9; // ST1C_4@21
  int v10; // ST18_4@21
  char *v11; // eax@21
  int v12; // ST1C_4@23
  char *v13; // eax@23
  char v15; // [sp+Ch] [bp-128h]@24
  char v16; // [sp+Dh] [bp-127h]@26
  char v17; // [sp+Eh] [bp-126h]@24
  char name; // [sp+28h] [bp-10Ch]@11
  struct hostent *v19; // [sp+128h] [bp-Ch]@13
  int i; // [sp+12Ch] [bp-8h]@24
  u_long argp; // [sp+130h] [bp-4h]@9

  if ( *(&bMenu + 7 * giCurExe + 5) )
  {
    sprintf(
      gText,
      "About to initiate TCP/IP connection.  Heroes II will now drop from full screen mode to windowed mode, so that any Windows 95 generated dialog boxes can be seen.\n\nWhen the connection is successfully made, you can return to full screen mode by pressing 'F4'.");
    NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    SetFullScreenStatus(0);
  }
  gbRemoteOn = 1;
  ppDPRcvBuffer = BaseAlloc(0x320u, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511798 + 10);
  piDPRcvBufferSize = BaseAlloc(0x320u, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511798 + 11);
  memset(ppDPRcvBuffer, 0, 0x320u);
  memset(piDPRcvBufferSize, 0, 0x320u);
  wVer = 257;
  iRc = thunk_WSAStartup(0x101u, &wsadata);
  if ( iRc )
  {
    v0 = thunk_WSAGetLastError();
    sprintf(cWSTextBuffer, "Error During WSAStartup(): %d", v0);
    ShutDown(cWSTextBuffer);
  }
  sd_dg = thunk_socket(2, 2, 0);
  if ( sd_dg == -1 )
  {
    v1 = thunk_WSAGetLastError();
    sprintf(cWSTextBuffer, "Error During socket(): %d", v1);
    ShutDown(cWSTextBuffer);
  }
  gbRemoteOn = 1;
  saddr_loc.sa_family = 2;
  word_5250E2 = thunk_htons(0x7D0u);
  dword_5250E4 = thunk_htonl(0);
  iRc = thunk_bind(sd_dg, &saddr_loc, 16);
  if ( iRc == -1 )
  {
    v2 = thunk_WSAGetLastError();
    sprintf(cWSTextBuffer, "Error During bind(): %d", v2);
    ShutDown(cWSTextBuffer);
  }
  argp = 1;
  iRc = thunk_ioctlsocket(sd_dg, -2147195266, &argp);
  if ( iRc == -1 )
  {
    v3 = thunk_WSAGetLastError();
    sprintf(cWSTextBuffer, "Error During ioctlsocket(): %d", v3);
    ShutDown(cWSTextBuffer);
  }
  iRc = thunk_gethostname(&name, 255);
  if ( iRc == -1 )
  {
    v4 = thunk_WSAGetLastError();
    sprintf(cWSTextBuffer, "Error During gethostname(): %d", v4);
    ShutDown(cWSTextBuffer);
  }
  v19 = thunk_gethostbyname(&name);
  gIn_addrIP = (struct in_addr)**(_DWORD **)v19->h_addr_list;
  v5 = thunk_inet_ntoa(gIn_addrIP);
  sprintf(cWSTextBuffer, "%s", v5);
  *((_DWORD *)&giNetPosToDCOPos + giThisNetPos) = thunk_inet_addr(cWSTextBuffer);
  if ( (unsigned __int8)GameMode == 1 )
  {
    giWaitType = 11;
    if ( giTCPHostStatus == -1 )
    {
      v8 = thunk_inet_ntoa(gIn_addrIP);
      sprintf(cWSTextBuffer, "Hosting game at %s\n\nWaiting On Guest(s).\n\n  Press 'CANCEL' to abort.", v8);
      NormalDialog(cWSTextBuffer, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    else
    {
      v6 = giTCPNumPlayers - 1;
      v7 = thunk_inet_ntoa(gIn_addrIP);
      sprintf(
        cWSTextBuffer,
        "Hosting game at %s.\n\nYou have %d guest(s) out of an expected total of %d guest(s) now logged in.  Click 'CANCEL' to move on without waiting for additional guests.",
        v7,
        0,
        v6);
      NormalDialog(cWSTextBuffer, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    if ( !gbFunctionComplete )
      ShutDown(0);
    iWSLastMsgNumHumanPlayers = iLastMsgNumHumanPlayers;
    giWaitType = 12;
    if ( giTCPHostStatus == -1 )
    {
      v12 = iLastMsgNumHumanPlayers - 1;
      v13 = thunk_inet_ntoa(gIn_addrIP);
      sprintf(
        cWSTextBuffer,
        "Hosting game at %s.\n\nYou have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
        v13,
        v12);
      NormalDialog(cWSTextBuffer, 5, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    else if ( giTCPNumPlayers > 2 )
    {
      v9 = giTCPNumPlayers - 1;
      v10 = iLastMsgNumHumanPlayers - 1;
      v11 = thunk_inet_ntoa(gIn_addrIP);
      sprintf(
        cWSTextBuffer,
        "Hosting game at %s.\n\nYou have %d guest(s) out of an expected total of %d guest(s) now logged in.  Click 'CANCEL' to move on without waiting for additional guests.",
        v11,
        v10,
        v9);
      NormalDialog(cWSTextBuffer, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    gbRemoteGameOpen = 0;
    v15 = iLastMsgNumHumanPlayers;
    memcpy(&v17, &giNetPosToDCOPos, 0x18u);
    for ( i = 1; iLastMsgNumHumanPlayers > i; ++i )
    {
      v16 = i;
      wsSendMessage(*((_DWORD *)&giNetPosToDCOPos + i), 3, 0x1Au, &v15);
    }
  }
  else
  {
    while ( 1 )
    {
      if ( giTCPHostStatus != -1 && strlen((int)gcTCPAddress) )
      {
        strcpy(cWSTextBuffer, gcTCPAddress);
        strcpy(gcTCPAddress, byte_511B78);
      }
      else
      {
        GetDataEntry("Enter the host IP address.\n(i.e. 220.415.119.223)", (int)cWSTextBuffer, 20, 0, 0, 1);
      }
      *(_DWORD *)&giNetPosToDCOPos = thunk_inet_addr(cWSTextBuffer);
      if ( *(_DWORD *)&giNetPosToDCOPos != -1 )
        break;
      NormalDialog("Error in IP Address, please try again.", 5, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    giWaitType = 13;
    sprintf(cWSTextBuffer, "Searching for host.");
    NormalDialog(cWSTextBuffer, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !gbFunctionComplete )
      ShutDown(0);
  }
  return 0;
}