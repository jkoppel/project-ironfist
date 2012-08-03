{
  void *v1; // [sp+10h] [bp-D8h]@1
  char a1; // [sp+14h] [bp-D4h]@21
  int i; // [sp+7Ch] [bp-6Ch]@2
  char v4; // [sp+80h] [bp-68h]@5

  v1 = this;
  LogStr("MS1");
  gbRemoteOn = 1;
  dword_5252AC = 0;
  inque = 0;
  dword_52636C = 0;
  outque = 0;
  iBaudBits = 115200 / *((_DWORD *)&modemBaudRate + gbDirectConnect);
  com_init(*((_DWORD *)&modemComPort + gbDirectConnect), 4u, 0);
  LogStr("MS2");
  if ( !gbDirectConnect )
  {
    for ( i = 0; i < 2; ++i )
    {
      if ( *((_DWORD *)&modemComPort + gbDirectConnect) < 1 )
        sprintf(&v4, "ATZ");
      else
        sprintf(&v4, (const char *)&gConfig + 174);
      PollSound();
      ModemCommand(&v4);
      DelayMilli(200);
      ModemCommand((const char *)L"\r");
      DelayMilli(100);
      PollSound();
    }
  }
  LogStr("MS3");
  if ( v1 == (void *)3 )
  {
    if ( !gbDirectConnect && Dial() )
    {
      RemoteCleanup();
      GameMode = 0;
    }
  }
  else
  {
    if ( v1 != (void *)4 )
      return;
    if ( !gbDirectConnect && Wait() )
    {
      RemoteCleanup();
      GameMode = 0;
    }
  }
  if ( gbDirectConnect )
  {
    LogStr("MS4");
    WFDCStage = 0;
    giWaitType = 7;
    strcpy(&a1, "Waiting for other computer to log in to direct connection.\n\nPress 'CANCEL' to abort.");
    NormalDialog(&a1, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !gbFunctionComplete )
      ShutDown(0);
    LogStr("MS5");
  }
  else
  {
    Connect();
  }
}