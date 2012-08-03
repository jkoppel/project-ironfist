{
  tag_message *v1; // esi@1
  signed int result; // eax@2
  int v3; // eax@6

  v1 = evt;
  if ( !bDataEntryTime )
  {
    ++bDataEntryTime;
    evt->eventCode = 8;
    evt->xCoordOrKeycode = inBoxX;
    evt->yCoord = inBoxY;
    heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)evt);
    return 1;
  }
  if ( bDataEntryTime == 1 )
  {
    ++bDataEntryTime;
LABEL_10:
    evt->eventCode = 512;
    evt->yCoord = 10;
    evt->xCoordOrKeycode = 7;
    heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)evt);
    if ( strlen((const char *)v1->payload) != 0 )
    {
      memset(cDEDest, 0, iDEMaxLen);
      strncpy(cDEDest, (const char *)v1->payload, iDEMaxLen - 1);
      v1->eventCode = 512;
      v1->xCoordOrKeycode = 3;
      v1->yCoord = 10;
      v1->payload = cDEDest;
      heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)v1);
      heroWindow::DrawWindow((heroWindow *)DataEntryWin, 1, 10, 10);
      if ( !gbTextEntryEscaped )
      {
        gpWindowManager->buttonPressedCode = v1->yCoord;
        result = 2;
        v1->yCoord = 10;
        v1->xCoordOrKeycode = 10;
        return result;
      }
    }
    return EventWindowHandler(v1);
  }
  if ( evt->eventCode != 512 )
    return EventWindowHandler(v1);
  v3 = evt->xCoordOrKeycode;
  if ( v3 == 12 )
  {
    if ( evt->yCoord != 10 )
      return EventWindowHandler(v1);
    goto LABEL_10;
  }
  if ( v3 != 13 || evt->yCoord != 30722 )
    return EventWindowHandler(v1);
  result = 2;
  evt->yCoord = 10;
  evt->xCoordOrKeycode = 10;
  return result;
}