{
  if ( !lockUsedInGlobalUpdatesOnTimer )
  {
    lockUsedInGlobalUpdatesOnTimer = 1;
    if ( getTickCount() > timer2 && !mouseSemaphore1 )
    {
      timer2 = getTickCount() + 13;
      sub_4CE410(mouseManager, 0);
    }
    if ( getTickCount() > timer1 )
    {
      if ( dword_4F19A0 != 1 && dword_4F19A0 != 3 )
        timer1 = getTickCount() + 200;
      else
        timer1 = getTickCount() + 110;
      dword_524A60 = 1;
      if ( graphicsLibraryToUse == 1 )
      {
        if ( bitspixel != 8 )
        {
          timer1 += 300;
          if ( dword_4F3084 )
            dword_524A60 = 0;
        }
      }
      if ( dword_524A60 )
        sub_4C7320(0);
    }
    if ( getTickCount() > globalSoundUpdateTimer )
    {
      globalSoundUpdateTimer = getTickCount() + 30;
      if ( dword_4F0A10 )
        sub_403E60(soundManager);
      sub_46E500();
    }
    lockUsedInGlobalUpdatesOnTimer = 0;
  }
}
