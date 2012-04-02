signed int __thiscall sub_4CB280(InputEvent *evt)
{
  InputEvent *v1; // esi@1
  signed int result; // eax@2
  int v3; // eax@6

  v1 = evt;
  if ( !dword_532E5C )
  {
    ++dword_532E5C;
    evt->eventCode = 8;
    evt->xCoordOrKeycode = dword_532E64;
    evt->yCoord = dword_532E60;
    GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)evt);
    return 1;
  }
  if ( dword_532E5C == 1 )
  {
    ++dword_532E5C;
LABEL_10:
    evt->eventCode = 512;
    evt->yCoord = 10;
    evt->xCoordOrKeycode = 7;
    GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)evt);
    if ( strlen((const char *)v1->payload) != 0 )
    {
      memset(dword_532E6C, 0, dword_532E74);
      strncpy(dword_532E6C, (const char *)v1->payload, dword_532E74 - 1);
      v1->eventCode = 512;
      v1->xCoordOrKeycode = 3;
      v1->yCoord = 10;
      v1->payload = dword_532E6C;
      GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)v1);
      GUIWindow::repaintComponentsInRange((GUIWindow *)dword_532E68, 1, 10, 10);
      if ( !dword_523ED0 )
      {
        HeroWindowManager::instance->buttonPressedCode = v1->yCoord;
        result = 2;
        v1->yCoord = 10;
        v1->xCoordOrKeycode = 10;
        return result;
      }
    }
    return sub_432A10(v1);
  }
  if ( evt->eventCode != 512 )
    return sub_432A10(v1);
  v3 = evt->xCoordOrKeycode;
  if ( v3 == 12 )
  {
    if ( evt->yCoord != 10 )
      return sub_432A10(v1);
    goto LABEL_10;
  }
  if ( v3 != 13 || evt->yCoord != 30722 )
    return sub_432A10(v1);
  result = 2;
  evt->yCoord = 10;
  evt->xCoordOrKeycode = 10;
  return result;
}
