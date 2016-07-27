{
  WPARAM result; // eax@3
  struct tagMSG Msg; // [sp+Ch] [bp-20h]@8
  DWORD v6; // [sp+28h] [bp-4h]@1

  hInstance = instance;
  hObject = CreateEventA(0, 0, 0, "Heroes II");
  v6 = GetLastError();
  if ( hObject && v6 != ERROR_CLIENT_ALREADY_EXISTS )
  {
    memset(command_line, 0, 0x3Du);
    strncpy(command_line, lpCmdnLine, 0x3Cu);
    if ( sub_42F7A0() )
    {
      if ( sub_484C30(instance, prevInstance, nCmdShow, lpCmdnLine) )
      {
        while ( 1 )
        {
          while ( !PeekMessageA(&Msg, 0, 0, 0, 1u) )
          {
            if ( sub_484F70() )
              WaitMessage();
          }
          if ( Msg.message == 18 )
            break;
          TranslateMessage(&Msg);
          DispatchMessageA(&Msg);
        }
        terminate(0);
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
    sprintf(globBuf, "Only one copy of %s may run at a time", "Heroes of Might and Magic II");
    MessageBoxA(0, globBuf, "Startup Error", 0x10u);
    result = 0;
  }
  return result;
}
