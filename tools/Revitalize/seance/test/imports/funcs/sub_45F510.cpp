{
  if ( connectionSocket != -1 )
    closesocket(connectionSocket);
  if ( dword_4ED2E8 )
    KBFree(dword_4ED2E8, (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511BEC + 7);
  dword_4ED2E8 = 0;
  if ( dword_4ED2EC )
    KBFree(dword_4ED2EC, (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511BEC + 11);
  dword_4ED2EC = 0;
  WSACleanup();
  dword_511780 = 0;
  connectionSocket = -1;
  dword_511788 = 1;
  dword_51178C = 0;
  dword_511790 = 0;
  dword_511794 = 0;
  _cfltcvt_init();
}
