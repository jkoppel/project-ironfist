{
  signed int result; // eax@33
  signed int v2; // [sp+Ch] [bp-24h]@11
  int v3; // [sp+14h] [bp-1Ch]@2
  int evt; // [sp+18h] [bp-18h]@1
  signed int v5; // [sp+2Ch] [bp-4h]@1

  evt = this;
  v5 = 0;
  if ( *(_DWORD *)this != 512 )
    goto LABEL_32;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 == 12 )
  {
    if ( *(_DWORD *)(this + 8) != 68 )
      goto LABEL_32;
    *(_DWORD *)(this + 4) = 7;
    GUIWindow::processMessage(*(GUIWindow **)&townManager->_3[0], (Event *)this);
    *(_DWORD *)&townManager->_3[4] = atoi(*(const char **)(evt + 24));
    if ( *(_DWORD *)&townManager->_3[4] < 0 )
      *(_DWORD *)&townManager->_3[4] = 0;
    if ( *(_DWORD *)&townManager->_3[4] >= *(_DWORD *)&townManager->_3[8] )
      *(_DWORD *)&townManager->_3[4] = *(_DWORD *)&townManager->_3[8] - 1;
LABEL_35:
    sprintf(globBuf, "%d", *(_DWORD *)&townManager->_3[4]);
    *(_DWORD *)evt = 512;
    *(_DWORD *)(evt + 4) = 3;
    *(_DWORD *)(evt + 8) = 68;
    *(_DWORD *)(evt + 24) = globBuf;
    GUIWindow::processMessage(*(GUIWindow **)&townManager->_3[0], (Event *)evt);
    GUIWindow::repaintComponentsInRange(*(GUIWindow **)&townManager->_3[0], 1, 68, 68);
    return 1;
  }
  if ( v3 != 13 )
    goto LABEL_32;
  v2 = *(_DWORD *)(this + 8);
  if ( v2 > 30721 )
  {
    if ( v2 == 30722 )
    {
      if ( *(_DWORD *)&townManager->_3[4] )
        HeroWindowManager::instance->buttonPressedCode = 30722;
      else
        HeroWindowManager::instance->buttonPressedCode = 30721;
      v5 = 1;
    }
    goto LABEL_32;
  }
  if ( v2 >= 30720 )
  {
    *(_DWORD *)&townManager->_3[4] = 0;
    HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(this + 8);
    v5 = 1;
    goto LABEL_32;
  }
  if ( v2 == 69 )
  {
    ++*(_DWORD *)&townManager->_3[4];
    if ( *(_DWORD *)&townManager->_3[4] >= *(_DWORD *)&townManager->_3[8] )
      *(_DWORD *)&townManager->_3[4] = *(_DWORD *)&townManager->_3[8] - 1;
    goto LABEL_35;
  }
  if ( v2 == 70 )
  {
    --*(_DWORD *)&townManager->_3[4];
    if ( *(_DWORD *)&townManager->_3[4] < 0 )
      *(_DWORD *)&townManager->_3[4] = 0;
    goto LABEL_35;
  }
LABEL_32:
  if ( v5 == 1 )
  {
    *(_DWORD *)(this + 8) = 10;
    *(_DWORD *)(this + 4) = *(_DWORD *)(this + 8);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
