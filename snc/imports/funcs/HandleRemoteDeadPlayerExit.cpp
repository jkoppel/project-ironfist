{
  int v1; // eax@5
  int v2; // ST1C_4@5
  char v3; // [sp+16h] [bp-2h]@0

  if ( giThisGamePos == a1 )
  {
    if ( !game::TransmitSaveGame(gpGame, (giThisNetPos + 1) % iLastMsgNumHumanPlayers, 1, 0) )
      ShutDown(0);
    RemoteCleanup();
  }
  else
  {
    v1 = a1;
    LOBYTE(v2) = *((_BYTE *)&gbGamePosToNetPos + a1);
    *(_WORD *)((char *)&v2 + 1) = (unsigned __int8)a1;
    BYTE3(v2) = 0;
    LOBYTE(v1) = v3;
    v1 <<= 16;
    LOWORD(v1) = 1;
    ReceiveRemotePlayerExit(v2, v1);
  }
}