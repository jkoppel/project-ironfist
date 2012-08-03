{
  int v2; // ST24_4@8
  int v3; // eax@8
  int v5; // ecx@14
  int v6; // ecx@15
  char v8; // [sp+1Ah] [bp-Ah]@0
  int v9; // [sp+1Ch] [bp-8h]@5
  int v10; // [sp+20h] [bp-4h]@1

  v10 = (int)GetRemoteData(1, a2);
  if ( v10 && (*(_BYTE *)(v10 + 5) == 2 || *(_BYTE *)(v10 + 5) == 3) )
  {
    switch ( *(_BYTE *)(v10 + 6) )
    {
      case 1:
        v9 = *(_DWORD *)(v10 + 21);
        if ( !game::ReceiveSaveGame(*(_DWORD *)(v10 + 9), *(_DWORD *)(v10 + 13), *(_DWORD *)(v10 + 17), *(_BYTE *)v10) )
          ShutDown(0);
        if ( v9 )
        {
          LOBYTE(v2) = *(_BYTE *)v10;
          v3 = NetPosToGamePos((void *)*(_BYTE *)v10);
          *(_WORD *)((char *)&v2 + 1) = (unsigned __int8)v3;
          BYTE3(v2) = 1;
          LOBYTE(v3) = v8;
          v3 <<= 16;
          LOWORD(v3) = 257;
          ReceiveRemotePlayerExit(v2, v3);
        }
        advManager::LoadRemote(this);
        return 0;
      case 11:
        PopNetBox((const char *)(v10 + 9), (void *)*(_BYTE *)v10);
        return 0;
      case 21:
        if ( dword_4F7474 )
          return v10;
        advManager::DoNetCombat(this, v10);
        break;
      case 31:
        LogStr("Receive Remote Player Exit");
        LOBYTE(v5) = *(_BYTE *)(v10 + 15);
        v5 <<= 16;
        LOWORD(v5) = *(_WORD *)(v10 + 13);
        ReceiveRemotePlayerExit(*(_DWORD *)(v10 + 9), v5);
        return 0;
      case 33:
        LogStr("Host Reports Player Exit");
        LOBYTE(v6) = *(_BYTE *)(v10 + 15);
        v6 <<= 16;
        LOWORD(v6) = *(_WORD *)(v10 + 13);
        ReceiveHostReportsPlayerExit(*(_BYTE *)v10, 0, *(_DWORD *)(v10 + 9), v6);
        return 0;
      case 41:
        advManager::ProcessIncomingGroupMapChange(this, (const void *)(v10 + 9));
        return 0;
      default:
        return v10;
    }
  }
  return 0;
}