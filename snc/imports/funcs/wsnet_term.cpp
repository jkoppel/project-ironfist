{
  if ( sd_dg != -1 )
    thunk_closesocket(sd_dg);
  if ( ppDPRcvBuffer )
    BaseFree(ppDPRcvBuffer, (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511BEC + 7);
  ppDPRcvBuffer = 0;
  if ( piDPRcvBufferSize )
    BaseFree(piDPRcvBufferSize, (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511BEC + 11);
  piDPRcvBufferSize = 0;
  thunk_WSACleanup();
  bHostFound = 0;
  sd_dg = -1;
  iWSLastMsgNumHumanPlayers = 1;
  iWSAttempts = 0;
  iWSNextTickCount = 0;
  iWSWaitForHostStatus = 0;
  _cfltcvt_init();
}