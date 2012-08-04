{
  signed int result; // eax@2

  if ( bEarlySetupDone )
  {
    result = 0;
  }
  else
  {
    InitMainClasses();
    GetGraphicsInfo();
    ReadPrefs();
    if ( InterpretCommandLine() )
    {
      LogTruncate();
      LogStr("ES1");
      iCDRomErr = SetupCDDrive();
      InitVars();
      LogStr("ES2");
      result = 1;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}