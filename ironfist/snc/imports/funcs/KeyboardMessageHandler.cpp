{
  tag_message *evt; // esi@5
  inputManager *v6; // eax@9
  int v7; // ecx@9
  int v8; // eax@20
  unsigned __int8 v9; // cf@30

  if ( !gpInputManager )
    return 1;
  if ( gpInputManager->ready != 1 )
    return 1;
  evt = &gpInputManager->inputInstances[gpInputManager->currentInfoField];
  evt->inputTypeBitmask = 0;
  evt->altYCoord = 0;
  evt->altXCoord = 0;
  evt->yCoord = 0;
  evt->xCoordOrKeycode = 0;
  evt->eventCode = 0;
  if ( a2 == 256 )
  {
    evt->eventCode = 1;
    evt->xCoordOrKeycode = (a4 >> 16) & 0xFF;
    evt->yCoord = 0;
    evt->inputTypeBitmask = 0;
    switch ( evt->xCoordOrKeycode )
    {
      case 0x1D:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask | 4;
        goto LABEL_18;
      case 0x2A:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask | 2;
        goto LABEL_18;
      case 0x36:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask | 1;
        goto LABEL_18;
      case 0x38:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask | 0x20;
LABEL_18:
        v6->forSettingBitmask = v7;
        break;
      default:
        break;
    }
  }
  else if ( a2 == 257 )
  {
    evt->eventCode = 2;
    evt->xCoordOrKeycode = (a4 >> 16) & 0xFF;
    evt->yCoord = 0;
    evt->inputTypeBitmask = 0;
    switch ( evt->xCoordOrKeycode )
    {
      case 0x1D:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask & 0xFFFB;
        goto LABEL_18;
      case 0x2A:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask & 0xFFFD;
        goto LABEL_18;
      case 0x36:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask & 0xFFFE;
        goto LABEL_18;
      case 0x38:
        v6 = gpInputManager;
        v7 = gpInputManager->forSettingBitmask & 0xFFDF;
        goto LABEL_18;
      default:
        break;
    }
  }
  if ( evt->eventCode == 0 )
    goto LABEL_33;
  evt->inputTypeBitmask = gpInputManager->forSettingBitmask;
  ++gpInputManager->currentInfoField;
  gpInputManager->currentInfoField = (((unsigned __int64)gpInputManager->currentInfoField >> 32) ^ abs(gpInputManager->currentInfoField) & 0x3F)
                                   - ((unsigned __int64)gpInputManager->currentInfoField >> 32);
  v8 = gpInputManager->currentInputEvt;
  if ( gpInputManager->currentInfoField == v8 )
  {
    gpInputManager->currentInputEvt = v8 + 1;
    gpInputManager->currentInputEvt = (((unsigned __int64)gpInputManager->currentInputEvt >> 32) ^ abs(gpInputManager->currentInputEvt) & 0x3F)
                                    - ((unsigned __int64)gpInputManager->currentInputEvt >> 32);
  }
  gpInputManager->field_85A = 0;
  if ( gpWindowManager->ready != 1 )
    goto LABEL_33;
  if ( evt->eventCode == INPUT_KEYDOWN_EVENT_CODE )
  {
    if ( evt->xCoordOrKeycode == 88 && evt->inputTypeBitmask & 3 )
      heroWindowManager::ScreenShot(gpWindowManager);
    if ( evt->eventCode != 1 )
      goto LABEL_33;
    if ( evt->xCoordOrKeycode == 59 )
    {
      SetFullScreenStatus(0);
      AppCommand(hwndApp, 0, 0x9C74u, 0);
    }
  }
  v9 = evt->eventCode < 1u;
  if ( evt->eventCode == 1 )
  {
    if ( evt->xCoordOrKeycode == 62 )
      SetFullScreenStatus((void *)(1 - *(&bMenu + 7 * giCurExe + 5)));
LABEL_33:
    v9 = evt->eventCode < 1u;
  }
  return v9;
}