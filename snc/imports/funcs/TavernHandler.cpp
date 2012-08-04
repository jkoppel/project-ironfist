{
  signed int result; // eax@4
  int v2; // [sp+Ch] [bp-14h]@3

  if ( this->inputEvt.eventCode == 512
    && this->guiMsg.messageType == 13
    && (v2 = this->inputEvt.yCoord, v2 >= 30720 && v2 <= 30722) )
  {
    gpWindowManager->buttonPressedCode = this->guiMsg.fieldID;
    this->guiMsg.fieldID = 10;
    this->guiMsg.messageType = this->guiMsg.fieldID;
    result = 2;
  }
  else
  {
    if ( KBTickCount() > glTimers )
    {
      this->inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
      this->inputEvt.xCoordOrKeycode = 4;
      this->inputEvt.yCoord = 2;
      ++*(_DWORD *)&gpGame->_10[616];
      this->inputEvt.payload = (void *)(*(_DWORD *)&gpGame->_10[616] % 20 + 2);
      heroWindow::BroadcastMessage(gpTownManager->curScreen, this);
      heroWindow::MoveWindow(gpTownManager->curScreen, 0, 0);
      glTimers = KBTickCount() + 75;
    }
    result = 1;
  }
  return result;
}