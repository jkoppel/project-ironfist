{
  advManager *result; // eax@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@2

  result = gpAdvManager;
  if ( gpAdvManager->ready == 1 )
  {
    evt.eventCode = 512;
    evt.messageType = 6;
    evt.payload = (void *)2;
    evt.fieldID = 1;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    evt.fieldID = 2;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    evt.fieldID = 3;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    evt.fieldID = 4;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    evt.fieldID = 5;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    evt.fieldID = 6;
    result = (advManager *)heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
  }
  return result;
}