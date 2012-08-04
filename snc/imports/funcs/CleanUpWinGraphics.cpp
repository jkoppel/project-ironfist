{
  if ( giGraphicsType == 1 )
    WGCleanUpWinGraphics();
  else
    DDCleanUpWinGraphics();
  return DisconnectDLLs();
}