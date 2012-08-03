{
  signed int result; // eax@3
  int v5; // eax@5
  signed int v6; // eax@33
  signed int v7; // eax@35

  if ( Msg > WM_HIBERNATE || !bProcessMessage[Msg] )
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  if ( Msg <= WM_PAINT )
  {
    if ( Msg == WM_PAINT )
    {
      AppPaint(hWnd);
      return 0;
    }
    switch ( Msg )
    {
      case WM_CREATE:
        v5 = KBTickCount();
        srand(v5);
        SetTimer(hWnd, 1u, 0xAu, 0);
        GdiSetBatchLimit(1u);
        return 0;
      case WM_MOVE:
        if ( hwndApp )
        {
          lTemp = GetWindowLongA(hwndApp, GWL_STYLE);
          if ( !(BYTE3(lTemp) & 0x21) && !gbClosingApp )
          {
            if ( !*(&bMenu + 7 * giCurExe + 5) )
            {
              GetWindowRect(hWnd, &rcTemp);
              *(&bMenu + 7 * giCurExe + 1) = rcTemp.left;
              *(&bMenu + 7 * giCurExe + 2) = rcTemp.top;
              WritePrefs();
            }
          }
          result = 0;
        }
        else
        {
          result = 0;
        }
        return result;
      case WM_SIZE:
        if ( !hwndApp )
          goto LABEL_83;
        lTemp = GetWindowLongA(hwndApp, GWL_STYLE);
        gbMinimized = lTemp & WS_MINIMIZE;
        if ( !(BYTE3(lTemp) & 0x20) )
          EarlyResizeWindow(0, 0);
        if ( BYTE3(lTemp) & 0x21 || (signed int)(unsigned __int16)lParam >= 240 && (signed int)(lParam >> 16) >= 160 )
        {
LABEL_83:
          iMainWinScreenWidth = (unsigned __int16)lParam;
          iMainWinScreenHeight = lParam >> 16;
          if ( (signed int)(unsigned __int16)lParam < 1 )
            iMainWinScreenWidth = 1;
          if ( iMainWinScreenHeight < 1 )
            iMainWinScreenHeight = 1;
          if ( hwndApp && !(BYTE3(lTemp) & 0x21) && !gbClosingApp && !*(&bMenu + 7 * giCurExe + 5) )
          {
            *(&bMenu + 7 * giCurExe + 3) = iMainWinScreenWidth;
            *(&bMenu + 7 * giCurExe + 4) = iMainWinScreenHeight;
            WritePrefs();
          }
          result = 0;
        }
        else
        {
          v6 = (unsigned __int16)lParam;
          if ( (signed int)(unsigned __int16)lParam <= 240 )
            v6 = 240;
          iTempX = v6;
          v7 = lParam >> 16;
          if ( (signed int)(lParam >> 16) <= 160 )
            v7 = 160;
          iTempY = v7;
          ResizeWindow(-1, -1, iTempX, v7);
          result = 0;
        }
        return result;
      case WM_DESTROY:
        goto LABEL_57;
      default:
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  if ( Msg > WM_ACTIVATEAPP )
  {
    if ( Msg <= WM_COMMAND )
    {
      if ( Msg == WM_COMMAND )
        return AppCommand(hWnd, WM_COMMAND, wParam, lParam);
      if ( Msg >= 0x100 && Msg <= 0x101 && !KeyboardMessageHandler(hWnd, Msg, wParam, lParam) )
        return 0;
      return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    if ( Msg > WM_RBUTTONDBLCLK )
    {
      if ( Msg == WM_QUERYNEWPALETTE )
        return QueryNewPalette();
      if ( Msg != WM_PALETTECHANGED )
      {
        if ( Msg == 953 && wParam == 1 )
          soundManager::CDPlay(gpSoundManager, gpSoundManager->field_694, 0, gpSoundManager->field_698, 1);
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
      }
      if ( (HWND)wParam != hWnd )
        return QueryNewPalette();
    }
    else
    {
      if ( Msg >= 0x200 )
      {
        if ( !MouseMessageHandler(hWnd, Msg, wParam, lParam) )
          return 0;
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
      }
      if ( Msg == 275 )
      {
        lTemp = KBTickCount();
        if ( lLastGTimerTickCount + 5 < lTemp )
        {
          lLastGTimerTickCount = lTemp;
          UpdateTimers(0);
        }
        return 0;
      }
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  if ( Msg == WM_ACTIVATEAPP )
  {
    gbForegroundApp = wParam;
    return 0;
  }
  if ( Msg != WM_CLOSE )
  {
    if ( Msg != WM_QUIT )
    {
      if ( Msg == WM_ERASEBKGND )
        return 1;
      return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    goto LABEL_58;
  }
  if ( hwndApp != hWnd || !GameUnsaved() )
  {
LABEL_57:
    gbClosingApp = 1;
    PostQuitMessage(0);
LABEL_58:
    ShutDown(0);
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  NormalDialog("Are you sure you want to quit?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( gpWindowManager->buttonPressedCode == 30725 )
    DestroyWindow(hWnd);
  return 0;
}