{
  char v0; // [sp+Ch] [bp-Ch]@3
  char v1; // [sp+Dh] [bp-Bh]@3
  char v2; // [sp+Eh] [bp-Ah]@3
  char v3; // [sp+Fh] [bp-9h]@3
  char v4; // [sp+10h] [bp-8h]@3
  int v5; // [sp+14h] [bp-4h]@3

  if ( gbGameInitialized )
  {
    if ( gbRemoteOn )
    {
      v0 = giThisNetPos;
      v1 = giThisGamePos;
      v2 = gbThisNetGotAdventureControl;
      v3 = 0;
      v4 = 0;
      v5 = giThisNetPos == 0;
      LogStr("HRSE1");
      TransmitRemoteData(&v0, v5, 7u, 31, 0, 0, 2);
      LogStr("HRSE2");
      DelayMilli(500);
    }
  }
}