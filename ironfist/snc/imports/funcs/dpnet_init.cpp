{
  __int16 result; // ax@2
  char v1; // [sp+10h] [bp-2Ch]@19
  char v2; // [sp+11h] [bp-2Bh]@21
  char v3; // [sp+12h] [bp-2Ah]@19
  FARPROC v4; // [sp+2Ch] [bp-10h]@5
  int i; // [sp+30h] [bp-Ch]@19
  int v6; // [sp+34h] [bp-8h]@14
  FARPROC v7; // [sp+38h] [bp-4h]@5

  if ( lpIDC )
  {
    result = 0;
  }
  else
  {
    ppDPRcvBuffer = BaseAlloc(0x320u, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 7);
    piDPRcvBufferSize = BaseAlloc(0x320u, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 8);
    memset(ppDPRcvBuffer, 0, 0x320u);
    memset(piDPRcvBufferSize, 0, 0x320u);
    hinstDplayx = LoadLibraryA("DPLAYX.DLL");
    if ( !hinstDplayx )
      ShutDown("Can't load 'DPLAYX.DLL'");
    v7 = 0;
    v4 = GetProcAddress(hinstDplayx, "DirectPlayCreate");
    if ( !v4 )
      ShutDown("Can't load 'DPLAYX.DLL'");
    v7 = GetProcAddress(hinstDplayx, "DirectPlayEnumerateA");
    if ( !v7 )
      ShutDown("Can't load 'DPLAYX.DLL'");
    ((void (__cdecl *)(signed int (__stdcall *)(int, const CHAR *, int, int, int), _DWORD))v7)(dpEnumServiceProvider, 0);
    if ( iMPNetProtocol == 1 )
    {
      g_lpGuid = IPXGuid;
    }
    else if ( iMPNetProtocol == 2 )
    {
      g_lpGuid = TCPGuid;
    }
    v6 = ((int (__cdecl *)(SOCKET, int *, _DWORD))v4)(g_lpGuid, &lpIDC, 0);
    if ( v6 )
      DPSD(v6, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 41);
    if ( (unsigned __int8)GameMode == 1 )
    {
      gbRemoteGameOpen = 1;
      giWaitType = 8;
      sprintf(gText, "Waiting On Guest.\n\n  Press 'CANCEL' to abort.");
      NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !gbFunctionComplete )
        ShutDown(0);
      giNumHumanPlayers = iLastMsgNumHumanPlayers;
      giWaitType = 9;
      sprintf(
        gText,
        "You have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
        iLastMsgNumHumanPlayers - 1);
      NormalDialog(gText, 5, -1, -1, -1, 0, -1, 0, -1, 0);
      gbRemoteGameOpen = 0;
      v1 = iLastMsgNumHumanPlayers;
      memcpy(&v3, &giNetPosToDCOPos, 0x18u);
      for ( i = 1; i < iLastMsgNumHumanPlayers; ++i )
      {
        v2 = i;
        dpSendMessage(*((_DWORD *)&giNetPosToDCOPos + i), 3, 0x1Au, &v1);
      }
    }
    else
    {
      giWaitType = 10;
      sprintf(gText, "Waiting for other remote player to set up game.");
      NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !gbFunctionComplete )
        ShutDown(0);
    }
    result = 0;
  }
  return result;
}