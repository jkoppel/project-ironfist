{
  Event evt; // [sp+10h] [bp-1Ch]@2

  if ( gheroWin )
  {
    *(_QWORD *)&evt.guiMsg.eventCode = INPUT_GUI_MESSAGE_CODE;
    evt.guiMsg.fieldID = 303;
    evt.guiMsg.payload = this;
    heroWindow::BroadcastMessage(gheroWin, &evt);
    heroWindow::DrawWindow(gheroWin, 0, 300, 303);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 459, 0x280u, 20);
  }
}