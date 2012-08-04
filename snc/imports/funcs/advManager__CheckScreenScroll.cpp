{
  void *v1; // [sp+Ch] [bp-14h]@1
  int v2; // [sp+10h] [bp-10h]@2
  int v3; // [sp+14h] [bp-Ch]@2
  int y; // [sp+18h] [bp-8h]@2
  int x; // [sp+1Ch] [bp-4h]@2

  v1 = this;
  if ( KBTickCount() - iLastScrollTime > 70 )
  {
    iLastScrollTime = KBTickCount();
    v2 = *(_DWORD *)((char *)v1 + 470);
    v3 = *(_DWORD *)((char *)v1 + 474);
    mouseManager::MouseCoords(&x, &y);
    if ( x >= 0 && x < 640 && y >= 0 && y < 480 )
    {
      if ( x >= 16 )
      {
        if ( x <= 623 )
        {
          if ( y >= 16 )
          {
            if ( y > 464 )
              advManager::ScreenScroll((advManager *)v1, 4, 1);
          }
          else
          {
            advManager::ScreenScroll((advManager *)v1, 0, 1);
          }
        }
        else if ( y >= 16 )
        {
          if ( y <= 464 )
            advManager::ScreenScroll((advManager *)v1, 2, 1);
          else
            advManager::ScreenScroll((advManager *)v1, 3, 1);
        }
        else
        {
          advManager::ScreenScroll((advManager *)v1, 1, 1);
        }
      }
      else if ( y >= 16 )
      {
        if ( y <= 464 )
          advManager::ScreenScroll((advManager *)v1, 6, 1);
        else
          advManager::ScreenScroll((advManager *)v1, 5, 1);
      }
      else
      {
        advManager::ScreenScroll((advManager *)v1, 7, 1);
      }
    }
    if ( gpMouseManager->spriteIdx >= 32 && gpMouseManager->spriteIdx < 40 && *(_DWORD *)((char *)v1 + 470) == v2 )
    {
      if ( *(_DWORD *)((char *)v1 + 474) == v3 )
        mouseManager::SetPointer(gpMouseManager, 0);
    }
  }
}