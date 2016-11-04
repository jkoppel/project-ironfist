{
  TownManager *thisa; // ST1C_4@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  evt.fieldID = 902;
  evt.payload = this->infoMessage;
  GUIWindow::processMessage(this->townScreen, (Event *)&evt);
  GUIWindow::repaintComponentsInRange(thisa->townScreen, 0, 900, 902);
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 25, 464, 0x24Eu, 15);
}
