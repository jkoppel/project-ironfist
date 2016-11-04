{
  signed int result; // eax@4
  int v2; // [sp+Ch] [bp-14h]@3

  if ( this->inputEvt.eventCode == 512
    && this->guiMsg.messageType == 13
    && (v2 = this->inputEvt.yCoord, v2 >= 30720 && v2 <= 30722) )
  {
    HeroWindowManager::instance->buttonPressedCode = this->guiMsg.fieldID;
    this->guiMsg.fieldID = 10;
    this->guiMsg.messageType = this->guiMsg.fieldID;
    result = 2;
  }
  else
  {
    if ( getTickCount() > animationFrameSwitchTime )
    {
      this->inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
      this->inputEvt.xCoordOrKeycode = 4;
      this->inputEvt.yCoord = 2;
      ++*(_DWORD *)&gameObject->_10[616];
      this->inputEvt.payload = (void *)(*(_DWORD *)&gameObject->_10[616] % 20 + 2);
      GUIWindow::processMessage(townManager->curScreen, this);
      GUIWindow::move(townManager->curScreen, 0, 0);
      animationFrameSwitchTime = getTickCount() + 75;
    }
    result = 1;
  }
  return result;
}
