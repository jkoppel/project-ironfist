{
  const char *singularName; // eax@1
  int result; // eax@3
  int creature; // [sp+Ch] [bp-60h]@1
  GUIWindow *this; // [sp+10h] [bp-5Ch]@1
  char buf[40]; // [sp+14h] [bp-58h]@1
  GUIMessage evt; // [sp+3Ch] [bp-30h]@1
  char v12[1]; // [sp+58h] [bp-14h]@1

  creature = a2;
  this = window;
  singularName = getCreatureSingularName(a2);
  strcpy(v12, singularName);
  v12[0] -= 32;
  sprintf(buf, "%s %s", "Recruit", v12);
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  evt.fieldID = 64;
  evt.payload = buf;
  GUIWindow::processMessage(this, (Event *)&evt);
  sprintf(buf, "%d", goldCost);
  evt.fieldID = 73;
  GUIWindow::processMessage(this, (Event *)&evt);
  if ( specialResource != -1 )
  {
    sprintf(buf, "%d", resourceAmt);
    evt.fieldID = 75;
    GUIWindow::processMessage(this, (Event *)&evt);
  }
  sprintf(globBuf, "%s%d", "Available: ", numAvail);
  evt.fieldID = 67;
  evt.payload = globBuf;
  GUIWindow::processMessage(this, (Event *)&evt);
  sprintf(globBuf, "monh%04d.icn", creature);
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_ICON;
  evt.fieldID = 66;
  evt.payload = globBuf;
  result = GUIWindow::processMessage(this, (Event *)&evt);
  if ( specialResource != -1 )
  {
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = 74;
    evt.payload = (void *)specialResource;
    GUIWindow::processMessage(this, (Event *)&evt);
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = 78;
    result = GUIWindow::processMessage(this, (Event *)&evt);
  }
  return result;
}
