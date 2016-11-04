{
  GUIWindow *result; // eax@13
  void *v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  if ( *(&byte_524758 + curPlayerIdx) )
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sub_41B5F0(gameObject, (const char *)&computerWalkSpeed + 327, 0, 1);
  if ( (gameObject->day != 1 || gameObject->week == 1 && gameObject->month == 1)
    && dword_4F7494
    && *(&byte_524758 + curPlayerIdx) )
  {
    soundManager->field_688 = 1;
    SoundManager::couldBePlayCDTrack(soundManager, 21);
    soundManager->field_688 = 0;
    dword_4F747C = getTickCount();
  }
  if ( gameObject->couldBePlayerAlive[curPlayerIdx] )
    sub_456A10();
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    sub_4293B0();
    dword_523ED4 = 1;
    soundManager->field_688 = 0;
  }
  sub_42C420(gameObject);
  AdvManager::heroSelectionGUIStuff((AdvManager *)v2, 1, 1);
  sub_44D170(v2, 1, 1);
  sub_44AA80((int)v2, 1, 0);
  sub_44D440(v2, 1, 1, 1);
  sub_455380(advManager);
  sub_4C3190(11, 0, 0, 0, -999, 0, 0);
  soundManager->field_688 = 1;
  result = (GUIWindow *)gameObject->_10[32];
  if ( gameObject->_10[32] && !dword_50EA80 )
  {
    dword_50EA80 = 1;
    sprintf(globBuf, "Someone is cheating!\n");
    result = display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  if ( debugLogLevel > 0 )
  {
    if ( !dword_50EA84 )
    {
      dword_50EA84 = 1;
      sprintf(globBuf, "Someone has their debug level set!\n");
      result = display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return result;
}
