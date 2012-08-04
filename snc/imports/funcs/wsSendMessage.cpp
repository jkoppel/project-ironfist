{
  char v4; // ST2C_1@1
  int v5; // eax@13
  int v6; // [sp+10h] [bp-24h]@1
  struct sockaddr to; // [sp+1Ch] [bp-18h]@3
  int i; // [sp+2Ch] [bp-8h]@4
  char *buf; // [sp+30h] [bp-4h]@1

  v4 = a2;
  v6 = a1;
  buf = (char *)BaseAlloc(a3 + 1, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511C30 + 2);
  *buf = v4;
  if ( a3 )
    memcpy(buf + 1, a4, a3);
  to.sa_family = 2;
  *(_WORD *)&to.sa_data[0] = thunk_htons(0x7D0u);
  if ( v6 )
  {
    *(_DWORD *)&to.sa_data[2] = v6;
    iRc = thunk_sendto(sd_dg, buf, a3 + 1, 0, &to, 16);
    if ( iRc == -1 )
    {
      v5 = thunk_WSAGetLastError();
      sprintf(cWSTextBuffer, "Error During sendto(): %d", v5);
      NormalDialog(cWSTextBuffer, 5, -1, -1, -1, 0, -1, 0, -1, 0);
      return;
    }
  }
  else
  {
    for ( i = 0; i < iLastMsgNumHumanPlayers; ++i )
    {
      if ( i != giThisNetPos )
      {
        while ( 1 )
        {
          *(_DWORD *)&to.sa_data[2] = *((_DWORD *)&giNetPosToDCOPos + i);
          iRc = thunk_sendto(sd_dg, buf, a3 + 1, 0, &to, 16);
          if ( iRc != -1 )
            break;
          thunk_WSAGetLastError();
          DelayMilli(300);
        }
      }
    }
  }
  BaseFree(buf, (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511C30 + 57);
}