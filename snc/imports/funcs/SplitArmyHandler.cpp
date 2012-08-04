{
  signed int result; // eax@33
  int v2; // [sp+Ch] [bp-24h]@11
  int v3; // [sp+14h] [bp-1Ch]@2
  Event *evt; // [sp+18h] [bp-18h]@1
  signed int v5; // [sp+2Ch] [bp-4h]@1

  evt = this;
  v5 = 0;
  if ( this->inputEvt.eventCode != 512 )
    goto LABEL_32;
  v3 = this->inputEvt.xCoordOrKeycode;
  if ( v3 == 12 )
  {
    if ( this->inputEvt.yCoord != 68 )
      goto LABEL_32;
    this->inputEvt.xCoordOrKeycode = 7;
    heroWindow::BroadcastMessage(*(heroWindow **)&gpTownManager->_3[0], this);
    *(_DWORD *)&gpTownManager->_3[4] = atoi((int *)evt->inputEvt.payload);
    if ( *(_DWORD *)&gpTownManager->_3[4] < 0 )
      *(_DWORD *)&gpTownManager->_3[4] = 0;
    if ( *(_DWORD *)&gpTownManager->_3[4] >= *(_DWORD *)&gpTownManager->_3[8] )
      *(_DWORD *)&gpTownManager->_3[4] = *(_DWORD *)&gpTownManager->_3[8] - 1;
LABEL_35:
    sprintf(gText, "%d", *(_DWORD *)&gpTownManager->_3[4]);
    evt->inputEvt.eventCode = 512;
    evt->inputEvt.xCoordOrKeycode = 3;
    evt->inputEvt.yCoord = 68;
    evt->inputEvt.payload = gText;
    heroWindow::BroadcastMessage(*(heroWindow **)&gpTownManager->_3[0], evt);
    heroWindow::DrawWindow(*(heroWindow **)&gpTownManager->_3[0], 1, 68, 68);
    return 1;
  }
  if ( v3 != 13 )
    goto LABEL_32;
  v2 = this->inputEvt.yCoord;
  if ( v2 > 30721 )
  {
    if ( v2 == 30722 )
    {
      if ( *(_DWORD *)&gpTownManager->_3[4] )
        gpWindowManager->buttonPressedCode = 30722;
      else
        gpWindowManager->buttonPressedCode = 30721;
      v5 = 1;
    }
    goto LABEL_32;
  }
  if ( v2 >= 30720 )
  {
    *(_DWORD *)&gpTownManager->_3[4] = 0;
    gpWindowManager->buttonPressedCode = this->inputEvt.yCoord;
    v5 = 1;
    goto LABEL_32;
  }
  if ( v2 == 69 )
  {
    ++*(_DWORD *)&gpTownManager->_3[4];
    if ( *(_DWORD *)&gpTownManager->_3[4] >= *(_DWORD *)&gpTownManager->_3[8] )
      *(_DWORD *)&gpTownManager->_3[4] = *(_DWORD *)&gpTownManager->_3[8] - 1;
    goto LABEL_35;
  }
  if ( v2 == 70 )
  {
    --*(_DWORD *)&gpTownManager->_3[4];
    if ( *(_DWORD *)&gpTownManager->_3[4] < 0 )
      *(_DWORD *)&gpTownManager->_3[4] = 0;
    goto LABEL_35;
  }
LABEL_32:
  if ( v5 == 1 )
  {
    this->inputEvt.yCoord = 10;
    this->inputEvt.xCoordOrKeycode = this->inputEvt.yCoord;
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}