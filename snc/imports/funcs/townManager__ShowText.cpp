{
  townManager *thisa; // ST1C_4@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  evt.fieldID = 902;
  evt.payload = this->infoMessage;
  heroWindow::BroadcastMessage(this->townScreen, (Event *)&evt);
  heroWindow::DrawWindow(thisa->townScreen, 0, 900, 902);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, 25, 464, 0x24Eu, 15);
}