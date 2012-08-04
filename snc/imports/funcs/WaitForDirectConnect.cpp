{
  unsigned int v0; // ST20_4@2
  int v2; // eax@12
  char v3; // [sp+14h] [bp-14h]@12

  if ( WFDCStage )
  {
    if ( WFDCStage == 1 )
    {
      if ( ReadPacket() )
      {
        packet[packetlen] = 0;
        if ( packetlen != 10 )
          return 0;
        if ( strncmp((int)packet, (int)"ID", 2) )
          return 0;
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
        v2 = strlen((int)&v3);
        WriteModemPacket((int)&v3, v2);
      }
      if ( localstage >= 2 )
        ++WFDCStage;
    }
    else if ( WFDCStage == 2 && !ReadPacket() )
    {
      return 1;
    }
  }
  else
  {
    v0 = KBTickCount() % 0xF4240u;
    sprintf(idstr, "%06d", v0);
    oldsec = -1;
    remotestage = 0;
    localstage = 0;
    ++WFDCStage;
  }
  return 0;
}