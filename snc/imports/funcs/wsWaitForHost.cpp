{
  if ( iWSWaitForHostStatus )
  {
    if ( iWSWaitForHostStatus == 1 )
    {
      wsProcessMessages();
      if ( bStartUpInfoReceived )
        return 1;
    }
  }
  else
  {
    if ( KBTickCount() < iWSNextTickCount )
      return 0;
    wsProcessMessages();
    if ( bHostFound )
    {
      ++iWSWaitForHostStatus;
      return 0;
    }
    wsSendMessage(0, 2, 0x22u, &gsThisNetPlayerInfo);
    iWSNextTickCount = KBTickCount() + 3000;
    ++iWSAttempts;
    if ( iWSAttempts > 15 )
    {
      sprintf(cWSTextBuffer, "The Host is not responding.  Keep waiting?");
      NormalDialog(cWSTextBuffer, 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode != 30725 )
        ShutDown(0);
      iWSAttempts = 0;
    }
  }
  return 0;
}