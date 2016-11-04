{
  signed int result; // eax@16
  int v2; // [sp+Ch] [bp-28h]@7
  int v3; // [sp+14h] [bp-20h]@2
  int v4; // [sp+18h] [bp-1Ch]@1
  signed int v5; // [sp+30h] [bp-4h]@1

  v4 = this;
  v5 = 0;
  if ( *(_DWORD *)this == 512 )
  {
    v3 = *(_DWORD *)(this + 4);
    if ( v3 == 12 )
    {
      if ( *(_DWORD *)(this + 8) == 2 )
      {
        sub_497970(*(_BYTE *)(*(_DWORD *)&townManager->_3[16] + 2), 1, 0);
        TownManager::paint(townManager);
        GUIWindow::repaintAndUpdateScreen(townManager->curScreen);
        GUIWindow::repaintAndUpdateScreen(*(GUIWindow **)&townManager->_3[0]);
        sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
      }
    }
    else
    {
      if ( v3 == 13 )
      {
        v2 = *(_DWORD *)(this + 8);
        if ( v2 == 30721 )
        {
          *(_DWORD *)&townManager->_3[12] = -1;
          v5 = 1;
        }
        else
        {
          if ( v2 == 30722 )
          {
            *(_DWORD *)&townManager->_3[12] = 0;
            HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(this + 8);
            v5 = 1;
          }
        }
      }
    }
  }
  if ( v5 == 1 )
  {
    *(_DWORD *)(v4 + 8) = 10;
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(v4 + 8);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
