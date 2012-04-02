void __thiscall sub_495160(char *this)
{
  Event evt; // [sp+10h] [bp-1Ch]@2

  if ( dword_518DC4 )
  {
    *(_QWORD *)&evt.guiMsg.eventCode = INPUT_GUI_MESSAGE_CODE;
    evt.guiMsg.fieldID = 303;
    evt.guiMsg.payload = this;
    GUIWindow::processMessage(dword_518DC4, &evt);
    GUIWindow::repaintComponentsInRange(dword_518DC4, 0, 300, 303);
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 459, 0x280u, 20);
  }
}
