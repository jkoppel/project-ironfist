{
  signed int result; // eax@16
  int v2; // [sp+Ch] [bp-28h]@7
  int v3; // [sp+14h] [bp-20h]@2
  void *v4; // [sp+18h] [bp-1Ch]@1
  signed int v5; // [sp+30h] [bp-4h]@1

  v4 = this;
  v5 = 0;
  if ( *(_DWORD *)this == 512 )
  {
    v3 = *((_DWORD *)this + 1);
    if ( v3 == 12 )
    {
      if ( *((_DWORD *)this + 2) == 2 )
      {
        HeroView(*(_BYTE *)(*(_DWORD *)&gpTownManager->_3[16] + 2), 1, 0);
        townManager::RedrawTownScreen(gpTownManager);
        heroWindow::DrawWindow(gpTownManager->curScreen);
        heroWindow::DrawWindow(*(heroWindow **)&gpTownManager->_3[0]);
        heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
      }
    }
    else if ( v3 == 13 )
    {
      v2 = *((_DWORD *)this + 2);
      if ( v2 == 30721 )
      {
        *(_DWORD *)&gpTownManager->_3[12] = -1;
        v5 = 1;
      }
      else if ( v2 == 30722 )
      {
        *(_DWORD *)&gpTownManager->_3[12] = 0;
        gpWindowManager->buttonPressedCode = *((_DWORD *)this + 2);
        v5 = 1;
      }
    }
  }
  if ( v5 == 1 )
  {
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}