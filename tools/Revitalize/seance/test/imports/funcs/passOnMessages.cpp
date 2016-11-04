{
  struct tagMSG Msg; // [sp+Ch] [bp-20h]@1
  int now; // [sp+28h] [bp-4h]@3

  while ( PeekMessageA(&Msg, NULL, 0, 0, PM_REMOVE) )
  {
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  now = getTickCount();
  if ( now - passOnMessagesTimer1 > 20 )
  {
    passOnMessagesTimer1 = now;
    if ( !soundDisabled )
      serveSound();
  }
  if ( now - passOnMessagesTimer2 > 150 )
  {
    passOnMessagesTimer2 = now;
    if ( GetMessageA(&Msg, NULL, 0, 0) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
}
