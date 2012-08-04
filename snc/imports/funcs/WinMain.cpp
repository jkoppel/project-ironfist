{
  WPARAM result; // eax@3
  struct tagMSG Msg; // [sp+Ch] [bp-20h]@8
  DWORD v6; // [sp+28h] [bp-4h]@1

  hInstApp = instance;
  gEventHandle = CreateEventA(0, 0, 0, "Heroes II");
  v6 = GetLastError();
  if ( gEventHandle && v6 != ERROR_CLIENT_ALREADY_EXISTS )
  {
    memset(gcCommandLine, 0, 0x3Du);
    strncpy(gcCommandLine, lpCmdnLine, 0x3Cu);
    if ( EarlySetup() )
    {
      if ( AppInit(instance, prevInstance, nCmdShow, lpCmdnLine) )
      {
        while ( 1 )
        {
          while ( !PeekMessageA(&Msg, 0, 0, 0, 1u) )
          {
            if ( AppIdle() )
              WaitMessage();
          }
          if ( Msg.message == 18 )
            break;
          TranslateMessage(&Msg);
          DispatchMessageA(&Msg);
        }
        ShutDown(0);
        result = Msg.wParam;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    sprintf(gText, "Only one copy of %s may run at a time", "Heroes of Might and Magic II");
    MessageBoxA(0, gText, "Startup Error", 0x10u);
    result = 0;
  }
  return result;
}