{
  int v0; // eax@9
  int v1; // eax@12
  char v3; // [sp+10h] [bp-18h]@9
  unsigned int v4; // [sp+24h] [bp-4h]@1

  v4 = KBTickCount() % 0xF4240u;
  sprintf(idstr, "%06d", v4);
  oldsec = -1;
  remotestage = 0;
  localstage = 0;
  do
  {
    if ( ReadPacket() )
    {
      packet[packetlen] = 0;
      if ( packetlen != 10 || strncmp((int)packet, (int)"ID", 2) )
        continue;
      if ( !strncmp((int)&packet[2], (int)idstr, 6) )
      {
        sprintf(gText, "Duplicate ID Strings!\nSorry Please Try Again\n");
        GOut(gText);
        RemoteCleanup();
      }
      strncpy(remoteidstr, &packet[2], 6u);
      remotestage = byte_526DD1 - 48;
      localstage = byte_526DD1 - 48 + 1;
      oldsec = -1;
    }
    stime = KBTickCount();
    if ( stime / 1000 != oldsec / 1000 )
    {
      oldsec = stime;
      sprintf(&v3, "ID%s_%i", idstr, localstage);
      v0 = strlen((int)&v3);
      WriteModemPacket((int)&v3, v0);
    }
    PollSound();
  }
  while ( localstage < 2 );
  do
    v1 = ReadPacket();
  while ( (_BYTE)v1 );
  return v1;
}