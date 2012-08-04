{
  char *singularName; // eax@1
  int result; // eax@3
  int creature; // [sp+Ch] [bp-60h]@1
  heroWindow *this; // [sp+10h] [bp-5Ch]@1
  char buf[40]; // [sp+14h] [bp-58h]@1
  GUIMessage evt; // [sp+3Ch] [bp-30h]@1
  char a1[1]; // [sp+58h] [bp-14h]@1
  int goldCosta; // [sp+74h] [bp+8h]@1
  int specialResourcea; // [sp+78h] [bp+Ch]@1

  creature = a2;
  this = window;
  singularName = GetMonsterName(a2);
  strcpy(a1, singularName);
  a1[0] -= 32;
  sprintf(buf, "%s %s", "Recruit", a1);
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  evt.fieldID = 64;
  evt.payload = buf;
  heroWindow::BroadcastMessage(this, (Event *)&evt);
  sprintf(buf, "%d", goldCosta);
  evt.fieldID = 73;
  heroWindow::BroadcastMessage(this, (Event *)&evt);
  if ( specialResourcea != -1 )
  {
    sprintf(buf, "%d", resourceAmt);
    evt.fieldID = 75;
    heroWindow::BroadcastMessage(this, (Event *)&evt);
  }
  sprintf(gText, "%s%d", "Available: ", numAvail);
  evt.fieldID = 67;
  evt.payload = gText;
  heroWindow::BroadcastMessage(this, (Event *)&evt);
  sprintf(gText, "monh%04d.icn", creature);
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_ICON;
  evt.fieldID = 66;
  evt.payload = gText;
  result = heroWindow::BroadcastMessage(this, (Event *)&evt);
  if ( specialResource != -1 )
  {
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = 74;
    evt.payload = (void *)specialResource;
    heroWindow::BroadcastMessage(this, (Event *)&evt);
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = 78;
    result = heroWindow::BroadcastMessage(this, (Event *)&evt);
  }
  return result;
}