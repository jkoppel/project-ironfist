{
  struct tagMSG Msg; // [sp+Ch] [bp-20h]@1
  int now; // [sp+28h] [bp-4h]@3

  while ( PeekMessageA(&Msg, NULL, 0, 0, PM_REMOVE) )
  {
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  now = KBTickCount();
  if ( now - lLastAilServe > 20 )
  {
    lLastAilServe = now;
    if ( !gbNoSound )
      soundManager::ServiceSound();
  }
  if ( now - lLastGetMessage > 150 )
  {
    lLastGetMessage = now;
    if ( GetMessageA(&Msg, NULL, 0, 0) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
}