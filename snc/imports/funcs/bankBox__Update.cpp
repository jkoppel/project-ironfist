{
  bankBox *thisa; // [sp+Ch] [bp-30h]@1
  tag_message evt; // [sp+10h] [bp-2Ch]@1
  int i; // [sp+2Ch] [bp-10h]@1
  char v5; // [sp+30h] [bp-Ch]@3

  thisa = this;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = GUI_MESSAGE_SET_CONTENTS;
  for ( i = 0; i < 6; ++i )
  {
    sprintf(&v5, "%d", thisa->player->resources[i]);
    evt.yCoord = i + 2030;
    evt.payload = &v5;
    heroWindow::BroadcastMessage(thisa->window, (Event *)&evt);
  }
  sprintf(&v5, "%d", thisa->player->resources[6]);
  evt.yCoord = 2036;
  evt.payload = &v5;
  heroWindow::BroadcastMessage(thisa->window, (Event *)&evt);
  heroWindow::DrawWindow(thisa->window, updateScreen);
}