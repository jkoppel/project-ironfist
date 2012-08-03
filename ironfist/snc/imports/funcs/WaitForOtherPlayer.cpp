{
  int v0; // edx@1
  int v2; // [sp+Ch] [bp-Ch]@3
  void *v3; // [sp+10h] [bp-8h]@1
  signed int v4; // [sp+14h] [bp-4h]@1

  v4 = 0;
  PollSound();
  v3 = GetRemoteData(1, v0);
  if ( v3 && *((_BYTE *)v3 + 5) == 2 )
  {
    v2 = *((_BYTE *)v3 + 6);
    if ( v2 == 1 )
    {
      v4 = game::ReceiveSaveGame(
             *(_DWORD *)((char *)v3 + 9),
             *(_DWORD *)((char *)v3 + 13),
             *(_DWORD *)((char *)v3 + 17),
             *(_BYTE *)v3);
    }
    else if ( v2 == 32 )
    {
      memcpy(&gbGamePosToNetPos, (char *)v3 + 9, 6u);
      gbUseRegularCompression = *((_BYTE *)v3 + 15);
      gbUseDiffCompression = *((_BYTE *)v3 + 16);
      memcpy(&gsNetPlayerInfo, (char *)v3 + 17, 0xCCu);
      giThisGamePos = NetPosToGamePos((void *)giThisNetPos);
    }
  }
  return v4;
}