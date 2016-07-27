{
  void *v1; // [sp+10h] [bp-D8h]@1
  char msg; // [sp+14h] [bp-D4h]@21
  int i; // [sp+7Ch] [bp-6Ch]@2
  char v4; // [sp+80h] [bp-68h]@5

  v1 = this;
  debugLog("MS1");
  dword_4F7494 = 1;
  dword_5252AC = 0;
  dword_5252A8 = 0;
  dword_52636C = 0;
  dword_526368 = 0;
  dword_5122FC = 115200 / *((_DWORD *)&modemBaudRate + dword_4F7478);
  sub_4BCC50(*((_DWORD *)&modemComPort + dword_4F7478), 4u, 0);
  debugLog("MS2");
  if ( !dword_4F7478 )
  {
    for ( i = 0; i < 2; ++i )
    {
      if ( *((_DWORD *)&modemComPort + dword_4F7478) < 1 )
        sprintf(&v4, "ATZ");
      else
        sprintf(&v4, (const char *)&computerWalkSpeed + 174);
      yieldToGlobalUpdater();
      sub_4642D0(&v4);
      sleep(200);
      sub_4642D0((const char *)L"\r");
      sleep(100);
      yieldToGlobalUpdater();
    }
  }
  debugLog("MS3");
  if ( v1 == (void *)3 )
  {
    if ( !dword_4F7478 && sub_4640B0() )
    {
      sub_46D360();
      byte_51257C = 0;
    }
  }
  else
  {
    if ( v1 != (void *)4 )
      return;
    if ( !dword_4F7478 && sub_464150() )
    {
      sub_46D360();
      byte_51257C = 0;
    }
  }
  if ( dword_4F7478 )
  {
    debugLog("MS4");
    dword_526314 = 0;
    dword_524750 = 7;
    strcpy(&msg, "Waiting for other computer to log in to direct connection.\n\nPress 'CANCEL' to abort.");
    display_message_window(&msg, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !dword_523018 )
      terminate(0);
    debugLog("MS5");
  }
  else
  {
    sub_4645A0();
  }
}
