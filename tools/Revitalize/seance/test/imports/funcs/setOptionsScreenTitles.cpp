{
  int screenIdxa; // [sp+Ch] [bp-2Ch]@1
  GUIWindow *windowa; // [sp+10h] [bp-28h]@1
  GUIMessage evt; // [sp+14h] [bp-24h]@4
  int i; // [sp+30h] [bp-8h]@1
  int numAffected; // [sp+34h] [bp-4h]@1

  screenIdxa = screenIdx;
  windowa = window;
  numAffected = 0;
  for ( i = 0; i < 73; ++i )
  {
    if ( title_infos[i].screenIdx == screenIdxa )
    {
      ++numAffected;
      evt.eventCode = INPUT_GUI_MESSAGE_CODE;
      evt.messageType = GUI_MESSAGE_SET_CONTENTS;
      evt.fieldID = title_infos[i].fieldID;
      evt.payload = title_infos[i].contents;
      GUIWindow::processMessage(windowa, (Event *)&evt);
    }
  }
}
