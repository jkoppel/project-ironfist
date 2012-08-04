{
  signed int i; // [sp+Ch] [bp-4h]@1

  RemoteCleanup();
  iLastMsgNumHumanPlayers = 1;
  for ( i = 0; i < 6; ++i )
  {
    if ( giThisNetPos != i )
      gbHumanPlayer[i] = 0;
  }
  return ComputeAdvNetControl();
}