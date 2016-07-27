{
  char *v1; // [sp+Ch] [bp-304h]@1
  char Text; // [sp+10h] [bp-300h]@2

  v1 = this;
  if ( !terminateUnexpectedlyLock )
  {
    debugLog("Shutdown");
    terminateUnexpectedlyLock = 1;
    dword_4F0A0C = 1;
    Text = 0;
    sub_4CEB90(mouseManager, 0);
    if ( v1 )
    {
      strcpy((int)&Text);
      sub_49D030(0);
      debugLog(&Text);
      MessageBoxA(windowHandle, &Text, "Unexpected Program Termination", 0x10u);
    }
    else
    {
      sprintf(&Text, "Bye!");
    }
    sub_45A240();
    sub_4022B0(soundManager);
    sub_4356E0();
    sub_4376B0();
    if ( dword_4F7494 )
      sub_438E80();
    if ( dword_524234 )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)dword_524234);
      dword_524234 = 0;
    }
    if ( bigFont )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)bigFont);
      bigFont = 0;
    }
    if ( smallFont )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)smallFont);
      smallFont = 0;
    }
    sub_46D360();
    ManagerManager__clear(managerManager);
    if ( hObject )
    {
      CloseHandle(hObject);
      hObject = 0;
    }
    if ( tileExplored )
      KBFree(tileExplored, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D8F8 + 71);
    tileExplored = 0;
    sub_4B8B90();
    deleteManyGlobalObjects();
    unknown_libname_12();
    sub_4C8D10();
    if ( poolOfMemoryBlockInfos )
      free((BOOL)poolOfMemoryBlockInfos);
    poolOfMemoryBlockInfos = 0;
    exit(0);
  }
}
