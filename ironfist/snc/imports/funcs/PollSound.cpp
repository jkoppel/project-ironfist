{
  if ( !gbInPollSound )
  {
    gbInPollSound = 1;
    if ( KBTickCount() > timer2 && !gbPutzingWithMouseCtr )
    {
      timer2 = KBTickCount() + 13;
      mouseManager::NewUpdate(gpMouseManager, 0);
    }
    if ( KBTickCount() > timer1 )
    {
      if ( giCycleType != 1 && giCycleType != 3 )
        timer1 = KBTickCount() + 200;
      else
        timer1 = KBTickCount() + 110;
      bDoColorCycle = 1;
      if ( giGraphicsType == 1 )
      {
        if ( giMainVideoModeColorDepth != 8 )
        {
          timer1 += 300;
          if ( gbHeroMoving )
            bDoColorCycle = 0;
        }
      }
      if ( bDoColorCycle )
        CycleColors(0);
    }
    if ( KBTickCount() > globalSoundUpdateTimer )
    {
      globalSoundUpdateTimer = KBTickCount() + 30;
      if ( gbForegroundApp )
        soundManager::PollSound(gpSoundManager);
      PollRemote();
    }
    gbInPollSound = 0;
  }
}