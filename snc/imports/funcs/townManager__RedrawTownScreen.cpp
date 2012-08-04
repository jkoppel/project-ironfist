{
  townManager *thisa; // ST1C_4@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  townManager::DrawTown(this, 0, 1);
  evt.eventCode = 512;
  evt.messageType = 3;
  evt.fieldID = 902;
  evt.payload = thisa->infoMessage;
  heroWindow::BroadcastMessage(thisa->townScreen, (Event *)&evt);
  heroWindow::DrawWindow(thisa->townScreen, 0);
  strip::DrawIcons(thisa->garrisonDisplay, 0);
  strip::DrawIcons(thisa->visitingArmyDisplay, 0);
  bankBox::Update(thisa->bankbox, 0);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
}