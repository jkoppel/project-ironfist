{
  TownManager *thisa; // ST1C_4@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  TownManager::paintTown(this, 0, 1);
  evt.eventCode = 512;
  evt.messageType = 3;
  evt.fieldID = 902;
  evt.payload = thisa->infoMessage;
  GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
  GUIWindow::repaint(thisa->townScreen, 0);
  ArmyDisplay::paint(thisa->garrisonDisplay, 0);
  ArmyDisplay::paint(thisa->visitingArmyDisplay, 0);
  Bankbox::refreshCaptions(thisa->bankbox, 0);
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
}
