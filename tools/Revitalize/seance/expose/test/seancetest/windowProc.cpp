signed int __stdcall windowProc(HWND hWnd, unsigned int Msg, int wParam, unsigned int lParam)
{
  signed int result; // eax@3
  int v5; // eax@5
  signed int v6; // eax@33
  signed int v7; // eax@35

  if ( Msg > WM_HIBERNATE || !shouldNotPassOnWindowMessage[Msg] )
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  if ( Msg <= WM_PAINT )
  {
    if ( Msg == WM_PAINT )
    {
      redrawWindow(hWnd);
      return 0;
    }
    switch ( Msg )
    {
      case WM_CREATE:
        v5 = getTickCount();
        srand(v5);
        SetTimer(hWnd, 1u, 0xAu, 0);
        GdiSetBatchLimit(1u);
        return 0;
      case WM_MOVE:
        if ( windowHandle )
        {
          windowStyles = GetWindowLongA(windowHandle, GWL_STYLE);
          if ( !(BYTE3(windowStyles) & 0x21) && !dword_4F0A0C )
          {
            if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
            {
              GetWindowRect(hWnd, &windowRect);
              *(&mainWindows + 7 * gameOrEditorIdx + 1) = windowRect.left;
              *(&mainWindows + 7 * gameOrEditorIdx + 2) = windowRect.top;
              propagateSettingChanges();
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
        if ( !windowHandle )
          goto LABEL_83;
        windowStyles = GetWindowLongA(windowHandle, GWL_STYLE);
        initiallyMinimized = windowStyles & WS_MINIMIZE;
        if ( !(BYTE3(windowStyles) & 0x20) )
          fancyDoNothing(0, 0);
        if ( BYTE3(windowStyles) & 0x21
          || (signed int)(unsigned __int16)lParam >= 240 && (signed int)(lParam >> 16) >= 160 )
        {
LABEL_83:
          couldBeScreenWidth = (unsigned __int16)lParam;
          couldBeScreenHeight = lParam >> 16;
          if ( (signed int)(unsigned __int16)lParam < 1 )
            couldBeScreenWidth = 1;
          if ( couldBeScreenHeight < 1 )
            couldBeScreenHeight = 1;
          if ( windowHandle
            && !(BYTE3(windowStyles) & 0x21)
            && !dword_4F0A0C
            && !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
          {
            *(&mainWindows + 7 * gameOrEditorIdx + 3) = couldBeScreenWidth;
            *(&mainWindows + 7 * gameOrEditorIdx + 4) = couldBeScreenHeight;
            propagateSettingChanges();
          }
          result = 0;
        }
        else
        {
          v6 = (unsigned __int16)lParam;
          if ( (signed int)(unsigned __int16)lParam <= 240 )
            v6 = 240;
          width = v6;
          v7 = lParam >> 16;
          if ( (signed int)(lParam >> 16) <= 160 )
            v7 = 160;
          heightNeededToDisplay = v7;
          setWindowRectangle(-1, -1, width, v7);
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
        return sub_485800(hWnd, WM_COMMAND, wParam, lParam);
      if ( Msg >= 0x100 && Msg <= 0x101 && !sub_4D0650(hWnd, Msg, wParam, lParam) )
        return 0;
      return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    if ( Msg > WM_RBUTTONDBLCLK )
    {
      if ( Msg == WM_QUERYNEWPALETTE )
        return sub_49D120();
      if ( Msg != WM_PALETTECHANGED )
      {
        if ( Msg == 953 && wParam == 1 )
          sub_402950(soundManager, soundManager->field_694, 0, soundManager->field_698, 1);
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
      }
      if ( (HWND)wParam != hWnd )
        return sub_49D120();
    }
    else
    {
      if ( Msg >= 0x200 )
      {
        if ( !translateToInputEvent(hWnd, Msg, wParam, lParam) )
          return 0;
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
      }
      if ( Msg == 275 )
      {
        windowStyles = getTickCount();
        if ( dword_513778 + 5 < windowStyles )
        {
          dword_513778 = windowStyles;
          sub_402DB0(0);
        }
        return 0;
      }
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  if ( Msg == WM_ACTIVATEAPP )
  {
    dword_4F0A10 = wParam;
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
  if ( windowHandle != hWnd || !sub_437700() )
  {
LABEL_57:
    dword_4F0A0C = 1;
    PostQuitMessage(0);
LABEL_58:
    terminate(0);
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  display_message_window("Are you sure you want to quit?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    DestroyWindow(hWnd);
  return 0;
}
