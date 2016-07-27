{
  signed int result; // eax@2

  if ( disableMuchInitialization )
  {
    result = 0;
  }
  else
  {
    constructManyGlobalObjects();
    getScreenInfo();
    sub_4C9B60();
    if ( parseCommandLine() )
    {
      startNewDebugLog();
      debugLog("ES1");
      dword_50CAF0 = findCDDrive();
      sub_434B60();
      debugLog("ES2");
      result = 1;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}
