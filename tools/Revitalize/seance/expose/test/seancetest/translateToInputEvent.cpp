bool __fastcall translateToInputEvent(HWND hWnd, int msg, int wParam, int lParam)
{
  int msga; // edi@1
  InputEvent *evt; // esi@7
  int v7; // eax@20
  int v8; // eax@22
  int y; // edx@27
  int x; // edi@27
  int v11; // eax@44
  int v12; // [sp-4h] [bp-10h]@37

  msga = msg;
  if ( !inputManager )
    return 1;
  if ( inputManager->ready != 1 )
    return 1;
  if ( inputManager->readingInputMutex )
    return 1;
  inputManager->readingInputMutex = 1;
  evt = &inputManager->inputInstances[inputManager->currentInfoField];
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
      SetCapture(windowHandle);
      goto LABEL_17;
    case WM_LBUTTONUP:
      evt->eventCode = INPUT_LEFT_UP_EVENT_CODE;
      if ( !ReleaseCapture() )
        debugLog("ReleaseCapture Failed");
      goto LABEL_17;
    case WM_LBUTTONDBLCLK:
      evt->eventCode = INPUT_LEFT_CLICK_EVENT_CODE;
      goto LABEL_17;
    case WM_RBUTTONDOWN:
      evt->eventCode = INPUT_RIGHT_CLICK;
      SetCapture(windowHandle);
      goto LABEL_17;
    case WM_RBUTTONUP:
      evt->eventCode = INPUT_RIGHT_UP_EVENT_CODE;
      if ( !ReleaseCapture() )
        debugLog("ReleaseCapture Failed");
      goto LABEL_17;
    case WM_RBUTTONDBLCLK:
      evt->eventCode = INPUT_RIGHT_CLICK;
LABEL_17:
      evt->xCoordOrKeycode = 640 * (signed __int16)lParam / couldBeScreenWidth;
      evt->yCoord = 480 * SHIWORD(lParam) / couldBeScreenHeight;
      evt->altXCoord = evt->xCoordOrKeycode;
      evt->altYCoord = evt->yCoord;
      if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
      {
        if ( !*(&mainWindows + 7 * gameOrEditorIdx + 6) )
        {
          if ( getTickCount() > dword_534758 )
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
                    dword_534758 = getTickCount() + 500;
                    MouseManager::setSpriteIdx(mouseManager, 1000);
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
    if ( mouseManager )
    {
      y = evt->yCoord;
      x = evt->xCoordOrKeycode;
      if ( !dword_51F6F4 )
      {
        if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) && *(&mainWindows + 7 * gameOrEditorIdx + 6) )
        {
          dword_51F6F4 = 1;
          if ( x < 0 || x >= 640 || y < 0 || y >= 480 )
          {
            if ( dword_51F6EC )
              goto LABEL_42;
            dword_51F6EC = 1;
            dword_51F6F0 = dword_4F19B0;
            if ( !dword_4F19B0 )
              goto LABEL_42;
            v12 = 0;
          }
          else
          {
            if ( dword_51F6EC )
            {
              dword_51F6EC = 0;
              MouseManager::setSpriteIdx(mouseManager, 1000);
            }
            if ( dword_51F6F0 == dword_4F19B0 )
              goto LABEL_42;
            v12 = 1;
          }
          sub_4CEB90(mouseManager, v12);
LABEL_42:
          dword_51F6F4 = 0;
          goto LABEL_43;
        }
      }
    }
  }
LABEL_43:
  if ( evt->eventCode )
  {
    evt->inputTypeBitmask = inputManager->forSettingBitmask;
    ++inputManager->currentInfoField;
    inputManager->currentInfoField = (((unsigned __int64)inputManager->currentInfoField >> 32) ^ abs(inputManager->currentInfoField) & 0x3F)
                                   - ((unsigned __int64)inputManager->currentInfoField >> 32);
    v11 = inputManager->currentInputEvt;
    if ( inputManager->currentInfoField == v11 )
    {
      inputManager->currentInputEvt = v11 + 1;
      inputManager->currentInputEvt = (((unsigned __int64)inputManager->currentInputEvt >> 32) ^ abs(inputManager->currentInputEvt) & 0x3F)
                                    - ((unsigned __int64)inputManager->currentInputEvt >> 32);
    }
  }
  inputManager->readingInputMutex = 0;
  return evt->eventCode < 1u;
}
