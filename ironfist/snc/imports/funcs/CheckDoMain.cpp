{
  int result; // eax@2
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+14h] [bp-Ch]@5
  int v5; // [sp+18h] [bp-8h]@5
  int v6; // [sp+1Ch] [bp-4h]@5

  v3 = a2;
  if ( KBTickCount() > iLastFrameRateTimer + 15 || (result = KBTickCount(), result > glTimers) )
  {
    Process1WindowsMessage();
    PollSound();
    if ( KBTickCount() > glTimers )
    {
      if ( !v3 )
      {
        v4 = bShowIt;
        v6 = *(_DWORD *)&gpAdvManager->_2[0];
        v5 = *(_DWORD *)&gpAdvManager->_2[4];
        gbDrawSavedCursor = 1;
        bShowIt = !*(_DWORD *)&blackoutComputer && !gbRemoteOn;
        if ( !bShowIt )
          bSpecialHideCursor = 1;
        if ( advManager::ComboDraw(gpAdvManager, *(_DWORD *)&gpAdvManager->_2[0], *(_DWORD *)&gpAdvManager->_2[4], 0) )
          advManager::UpdateScreen(gpAdvManager, 0, 0);
        else
          advManager::UpdBottomView(gpAdvManager, 0, 1, 1);
        bShowIt = v4;
        gbDrawSavedCursor = 0;
        bSpecialHideCursor = 0;
        *(_DWORD *)&gpAdvManager->_2[0] = v6;
        *(_DWORD *)&gpAdvManager->_2[4] = v5;
      }
      glTimers = KBTickCount() + 120;
    }
    result = KBTickCount();
    iLastFrameRateTimer = result;
  }
  return result;
}