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

  if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
  {
    sprintf(
      globBuf,
      "About to initiate TCP/IP connection.  Heroes II will now drop from full screen mode to windowed mode, so that any Windows 95 generated dialog boxes can be seen.\n\nWhen the connection is successfully made, you can return to full screen mode by pressing 'F4'.");
    display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    sub_49D030(0);
  }
  dword_4F7494 = 1;
  dword_4ED2E8 = KBAlloc(0x320u, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511798 + 10);
  dword_4ED2EC = KBAlloc(0x320u, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511798 + 11);
  memset(dword_4ED2E8, 0, 0x320u);
  memset(dword_4ED2EC, 0, 0x320u);
  wVersionRequested = 257;
  dword_524F40 = WSAStartup(0x101u, &stru_524F50);
  if ( dword_524F40 )
  {
    v0 = WSAGetLastError();
    sprintf(cp, "Error During WSAStartup(): %d", v0);
    terminate(cp);
  }
  connectionSocket = socket(2, 2, 0);
  if ( connectionSocket == -1 )
  {
    v1 = WSAGetLastError();
    sprintf(cp, "Error During socket(): %d", v1);
    terminate(cp);
  }
  dword_4F7494 = 1;
  sock_name.sa_family = 2;
  word_5250E2 = htons(0x7D0u);
  dword_5250E4 = htonl(0);
  dword_524F40 = bind(connectionSocket, &sock_name, 16);
  if ( dword_524F40 == -1 )
  {
    v2 = WSAGetLastError();
    sprintf(cp, "Error During bind(): %d", v2);
    terminate(cp);
  }
  argp = 1;
  dword_524F40 = ioctlsocket(connectionSocket, -2147195266, &argp);
  if ( dword_524F40 == -1 )
  {
    v3 = WSAGetLastError();
    sprintf(cp, "Error During ioctlsocket(): %d", v3);
    terminate(cp);
  }
  dword_524F40 = gethostname(&name, 255);
  if ( dword_524F40 == -1 )
  {
    v4 = WSAGetLastError();
    sprintf(cp, "Error During gethostname(): %d", v4);
    terminate(cp);
  }
  v19 = gethostbyname(&name);
  in = (struct in_addr)**(_DWORD **)v19->h_addr_list;
  v5 = inet_ntoa(in);
  sprintf(cp, "%s", v5);
  *((_DWORD *)&dword_522B78 + dword_523F14) = inet_addr(cp);
  if ( (unsigned __int8)byte_51257C == 1 )
  {
    dword_524750 = 11;
    if ( dword_52340C == -1 )
    {
      v8 = inet_ntoa(in);
      sprintf(cp, "Hosting game at %s\n\nWaiting On Guest(s).\n\n  Press 'CANCEL' to abort.", v8);
      display_message_window(cp, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    else
    {
      v6 = dword_523410 - 1;
      v7 = inet_ntoa(in);
      sprintf(
        cp,
        "Hosting game at %s.\n\nYou have %d guest(s) out of an expected total of %d guest(s) now logged in.  Click 'CANCEL' to move on without waiting for additional guests.",
        v7,
        0,
        v6);
      display_message_window(cp, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    if ( !dword_523018 )
      terminate(0);
    dword_511788 = dword_5235D4;
    dword_524750 = 12;
    if ( dword_52340C == -1 )
    {
      v12 = dword_5235D4 - 1;
      v13 = inet_ntoa(in);
      sprintf(
        cp,
        "Hosting game at %s.\n\nYou have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
        v13,
        v12);
      display_message_window(cp, 5, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    else
    {
      if ( dword_523410 > 2 )
      {
        v9 = dword_523410 - 1;
        v10 = dword_5235D4 - 1;
        v11 = inet_ntoa(in);
        sprintf(
          cp,
          "Hosting game at %s.\n\nYou have %d guest(s) out of an expected total of %d guest(s) now logged in.  Click 'CANCEL' to move on without waiting for additional guests.",
          v11,
          v10,
          v9);
        display_message_window(cp, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      }
    }
    dword_524A6C = 0;
    v15 = dword_5235D4;
    memcpy(&v17, &dword_522B78, 0x18u);
    for ( i = 1; dword_5235D4 > i; ++i )
    {
      v16 = i;
      sub_45F5F0(*((_DWORD *)&dword_522B78 + i), 3, 0x1Au, &v15);
    }
  }
  else
  {
    while ( 1 )
    {
      if ( dword_52340C != -1 && strlen(byte_5235B8) )
      {
        strcpy(cp, byte_5235B8);
        strcpy(byte_5235B8, byte_511B78);
      }
      else
      {
        sub_4CAEF0("Enter the host IP address.\n(i.e. 220.415.119.223)", (int)cp, 20, 0, 0, 1);
      }
      *(_DWORD *)&dword_522B78 = inet_addr(cp);
      if ( *(_DWORD *)&dword_522B78 != -1 )
        break;
      display_message_window("Error in IP Address, please try again.", 5, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    dword_524750 = 13;
    sprintf(cp, "Searching for host.");
    display_message_window(cp, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !dword_523018 )
      terminate(0);
  }
  return 0;
}
