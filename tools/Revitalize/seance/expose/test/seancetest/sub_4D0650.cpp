signed int __fastcall sub_4D0650(HWND a1, int a2, int a3, unsigned int a4)
{
  InputEvent *evt; // esi@5
  InputManager *v6; // eax@9
  int v7; // ecx@9
  int v8; // eax@20
  unsigned __int8 v9; // cf@30

  if ( !inputManager )
    return 1;
  if ( inputManager->ready != 1 )
    return 1;
  evt = &inputManager->inputInstances[inputManager->currentInfoField];
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
        v6 = inputManager;
        v7 = inputManager->forSettingBitmask | 4;
        goto LABEL_18;
      case 0x2A:
        v6 = inputManager;
        v7 = inputManager->forSettingBitmask | 2;
        goto LABEL_18;
      case 0x36:
        v6 = inputManager;
        v7 = inputManager->forSettingBitmask | 1;
        goto LABEL_18;
      case 0x38:
        v6 = inputManager;
        v7 = inputManager->forSettingBitmask | 0x20;
LABEL_18:
        v6->forSettingBitmask = v7;
        break;
      default:
        break;
    }
  }
  else
  {
    if ( a2 == 257 )
    {
      evt->eventCode = 2;
      evt->xCoordOrKeycode = (a4 >> 16) & 0xFF;
      evt->yCoord = 0;
      evt->inputTypeBitmask = 0;
      switch ( evt->xCoordOrKeycode )
      {
        case 0x1D:
          v6 = inputManager;
          v7 = inputManager->forSettingBitmask & 0xFFFB;
          goto LABEL_18;
        case 0x2A:
          v6 = inputManager;
          v7 = inputManager->forSettingBitmask & 0xFFFD;
          goto LABEL_18;
        case 0x36:
          v6 = inputManager;
          v7 = inputManager->forSettingBitmask & 0xFFFE;
          goto LABEL_18;
        case 0x38:
          v6 = inputManager;
          v7 = inputManager->forSettingBitmask & 0xFFDF;
          goto LABEL_18;
        default:
          break;
      }
    }
  }
  if ( !evt->eventCode )
    goto LABEL_33;
  evt->inputTypeBitmask = inputManager->forSettingBitmask;
  ++inputManager->currentInfoField;
  inputManager->currentInfoField = (((unsigned __int64)inputManager->currentInfoField >> 32) ^ abs(inputManager->currentInfoField) & 0x3F)
                                 - ((unsigned __int64)inputManager->currentInfoField >> 32);
  v8 = inputManager->currentInputEvt;
  if ( inputManager->currentInfoField == v8 )
  {
    inputManager->currentInputEvt = v8 + 1;
    inputManager->currentInputEvt = (((unsigned __int64)inputManager->currentInputEvt >> 32) ^ abs(inputManager->currentInputEvt) & 0x3F)
                                  - ((unsigned __int64)inputManager->currentInputEvt >> 32);
  }
  inputManager->field_85A = 0;
  if ( HeroWindowManager::instance->ready != 1 )
    goto LABEL_33;
  if ( evt->eventCode == INPUT_KEYDOWN_EVENT_CODE )
  {
    if ( evt->xCoordOrKeycode == 88 && evt->inputTypeBitmask & 3 )
      HeroWindowManager::writeScreenshot(HeroWindowManager::instance);
    if ( evt->eventCode != 1 )
      goto LABEL_33;
    if ( evt->xCoordOrKeycode == 59 )
    {
      sub_49D030(0);
      sub_485800(windowHandle, 0x9C74u, 0);
    }
  }
  v9 = evt->eventCode < 1u;
  if ( evt->eventCode == 1 )
  {
    if ( evt->xCoordOrKeycode == 62 )
      sub_49D030((void *)(1 - *(&mainWindows + 7 * gameOrEditorIdx + 5)));
LABEL_33:
    v9 = evt->eventCode < 1u;
  }
  return v9;
}
