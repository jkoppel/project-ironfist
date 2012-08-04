{
  int msga; // edi@1
  tag_message *evt; // esi@7
  int v7; // eax@20
  int v8; // eax@22
  int y; // edx@27
  int x; // edi@27
  int v11; // eax@44
  int v12; // [sp-4h] [bp-10h]@37

  msga = msg;
  if ( !gpInputManager )
    return 1;
  if ( gpInputManager->ready != 1 )
    return 1;
  if ( gpInputManager->readingInputMutex )
    return 1;
  gpInputManager->readingInputMutex = 1;
  evt = &gpInputManager->inputInstances[gpInputManager->currentInfoField];
  evt->inputTypeBitmask = 0;
  evt->altYCoord = 0;
  evt->altXCoord = 0;
  evt->yCoord = 0;
  evt->xCoordOrKeycode = 0;
  evt->eventCode = 0;
  switch ( msg )
  {
    case WM_MOUSEFIRST:
      evt->eventCode = INPUT_MOUSEMOVE_EVENT_CODE;
      goto LABEL_17;
    case WM_LBUTTONDOWN:
      evt->eventCode = INPUT_LEFT_CLICK_EVENT_CODE;
      SetCapture(hwndApp);
      goto LABEL_17;
    case WM_LBUTTONUP:
      evt->eventCode = INPUT_LEFT_UP_EVENT_CODE;
      if ( !ReleaseCapture() )
        LogStr("ReleaseCapture Failed");
      goto LABEL_17;
    case WM_LBUTTONDBLCLK:
      evt->eventCode = INPUT_LEFT_CLICK_EVENT_CODE;
      goto LABEL_17;
    case WM_RBUTTONDOWN:
      evt->eventCode = INPUT_RIGHT_CLICK;
      SetCapture(hwndApp);
      goto LABEL_17;
    case WM_RBUTTONUP:
      evt->eventCode = INPUT_RIGHT_UP_EVENT_CODE;
      if ( !ReleaseCapture() )
        LogStr("ReleaseCapture Failed");
      goto LABEL_17;
    case WM_RBUTTONDBLCLK:
      evt->eventCode = INPUT_RIGHT_CLICK;
LABEL_17:
      evt->xCoordOrKeycode = 640 * (signed __int16)lParam / iMainWinScreenWidth;
      evt->yCoord = 480 * SHIWORD(lParam) / iMainWinScreenHeight;
      evt->altXCoord = evt->xCoordOrKeycode;
      evt->altYCoord = evt->yCoord;
      if ( !*(&bMenu + 7 * giCurExe + 5) )
      {
        if ( !*(&bMenu + 7 * giCurExe + 6) )
        {
          if ( KBTickCount() > iLastBWOnScreenCheck )
          {
            v7 = evt->xCoordOrKeycode;
            if ( v7 > 3 )
            {
              if ( v7 < 636 )
              {
                v8 = evt->yCoord;
                if ( v8 > 3 )
                {
                  if ( v8 < 476 )
                  {
                    iLastBWOnScreenCheck = KBTickCount() + 500;
                    mouseManager::SetPointer(gpMouseManager, 1000);
                  }
                }
              }
            }
          }
        }
      }
      break;
    default:
      break;
  }
  if ( msga == WM_MOUSEMOVE )
  {
    if ( gpMouseManager )
    {
      y = evt->yCoord;
      x = evt->xCoordOrKeycode;
      if ( !bInCheckChangeCursor )
      {
        if ( !*(&bMenu + 7 * giCurExe + 5) && *(&bMenu + 7 * giCurExe + 6) )
        {
          bInCheckChangeCursor = 1;
          if ( x < 0 || x >= 640 || y < 0 || y >= 480 )
          {
            if ( bLastMouseOffscreen )
              goto LABEL_42;
            bLastMouseOffscreen = 1;
            bLastOnscreenMouseColor = gbColorMice;
            if ( !gbColorMice )
              goto LABEL_42;
            v12 = 0;
          }
          else
          {
            if ( bLastMouseOffscreen )
            {
              bLastMouseOffscreen = 0;
              mouseManager::SetPointer(gpMouseManager, 1000);
            }
            if ( bLastOnscreenMouseColor == gbColorMice )
              goto LABEL_42;
            v12 = 1;
          }
          mouseManager::SetColorMice(gpMouseManager, v12);
LABEL_42:
          bInCheckChangeCursor = 0;
          goto LABEL_43;
        }
      }
    }
  }
LABEL_43:
  if ( evt->eventCode )
  {
    evt->inputTypeBitmask = gpInputManager->forSettingBitmask;
    ++gpInputManager->currentInfoField;
    gpInputManager->currentInfoField = (((unsigned __int64)gpInputManager->currentInfoField >> 32) ^ abs(gpInputManager->currentInfoField) & 0x3F)
                                     - ((unsigned __int64)gpInputManager->currentInfoField >> 32);
    v11 = gpInputManager->currentInputEvt;
    if ( gpInputManager->currentInfoField == v11 )
    {
      gpInputManager->currentInputEvt = v11 + 1;
      gpInputManager->currentInputEvt = (((unsigned __int64)gpInputManager->currentInputEvt >> 32) ^ abs(gpInputManager->currentInputEvt) & 0x3F)
                                      - ((unsigned __int64)gpInputManager->currentInputEvt >> 32);
    }
  }
  gpInputManager->readingInputMutex = 0;
  return evt->eventCode < 1u;
}