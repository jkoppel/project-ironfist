{
  LogStr("GUON1");
  if ( (unsigned __int8)GameMode == 1 )
  {
    giWaitType = 4;
    sprintf(gText, "Initializing network.\n\n  Press 'CANCEL' to abort.");
    NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !gbFunctionComplete )
      ShutDown(0);
    giWaitType = 1;
    sprintf(gText, "Waiting On Guest.\n\n  Press 'CANCEL' to abort.");
    LogStr("GUON2");
    NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    LogStr("GUON3");
    if ( !gbFunctionComplete )
      ShutDown(0);
    LogStr("GUON4");
  }
  else if ( (unsigned __int8)GameMode == 2 )
  {
    giWaitType = 3;
    sprintf(gText, "Initializing network.\n\n  Press 'CANCEL' to abort.");
    NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !gbFunctionComplete )
      ShutDown(0);
    giWaitType = 2;
    sprintf(gText, "Waiting On Host.\n\n  Press 'CANCEL' to abort.");
    NormalDialog(gText, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !gbFunctionComplete )
      ShutDown(0);
  }
  LogStr("GUON5");
  return 0;
}