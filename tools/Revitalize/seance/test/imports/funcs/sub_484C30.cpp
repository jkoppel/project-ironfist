{
  HINSTANCE v4; // ST3C_4@1
  signed int result; // eax@3
  LPARAM v6; // eax@11
  HCURSOR v7; // eax@13
  HINSTANCE hInstance; // [sp+10h] [bp-40h]@1
  HMENU hMenu; // [sp+14h] [bp-3Ch]@8
  struct tagRECT Rect; // [sp+18h] [bp-38h]@7
  WNDCLASSA WndClass; // [sp+28h] [bp-28h]@2

  v4 = prevInstance;
  hInstance = instance;
  logUpTo7Ints((int)"hInstApp", (int)::hInstance, -999, -999, -999, -999, -999, -999);
  memset(shouldNotPassOnWindowMessage, 0, 0x400u);
  shouldNotPassOnWindowMessage[1] = 1;
  shouldNotPassOnWindowMessage[256] = 1;
  shouldNotPassOnWindowMessage[257] = 1;
  shouldNotPassOnWindowMessage[512] = 1;
  shouldNotPassOnWindowMessage[513] = 1;
  shouldNotPassOnWindowMessage[515] = 1;
  shouldNotPassOnWindowMessage[516] = 1;
  shouldNotPassOnWindowMessage[518] = 1;
  shouldNotPassOnWindowMessage[514] = 1;
  shouldNotPassOnWindowMessage[517] = 1;
  shouldNotPassOnWindowMessage[275] = 1;
  shouldNotPassOnWindowMessage[28] = 1;
  shouldNotPassOnWindowMessage[20] = 1;
  shouldNotPassOnWindowMessage[3] = 1;
  shouldNotPassOnWindowMessage[5] = 1;
  shouldNotPassOnWindowMessage[273] = 1;
  shouldNotPassOnWindowMessage[785] = 1;
  shouldNotPassOnWindowMessage[783] = 1;
  shouldNotPassOnWindowMessage[15] = 1;
  shouldNotPassOnWindowMessage[2] = 1;
  shouldNotPassOnWindowMessage[18] = 1;
  shouldNotPassOnWindowMessage[16] = 1;
  shouldNotPassOnWindowMessage[953] = 1;
  if ( v4
    || (WndClass.hCursor = NULL,
        WndClass.hIcon = LoadIconA(hInstance, "Heroes II"),
        WndClass.lpszMenuName = NULL,
        WndClass.lpszClassName = "Heroes II",
        WndClass.hbrBackground = (HBRUSH)COLOR_WINDOWFRAME,
        WndClass.hInstance = hInstance,
        WndClass.style = CS_BYTEALIGNCLIENT|CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW,
        WndClass.lpfnWndProc = (WNDPROC)windowProc,
        WndClass.cbWndExtra = 0,
        WndClass.cbClsExtra = 0,
        RegisterClassA(&WndClass)) )
  {
    if ( *(&mainWindows + 7 * gameOrEditorIdx) )
      dwStyle = 0x14CF0000u;
    else
      dwStyle = 0x14000000u;
    Rect.top = 0;
    Rect.left = 0;
    Rect.right = *(&mainWindows + 7 * gameOrEditorIdx + 3) - 1;
    Rect.bottom = *(&mainWindows + 7 * gameOrEditorIdx + 4) - 1;
    AdjustWindowRect(&Rect, dwStyle, *(&mainWindows + 7 * gameOrEditorIdx));
    if ( *(&mainWindows + 7 * gameOrEditorIdx) )
      hMenu = dfltMenu;
    else
      hMenu = 0;
    windowHandle = CreateWindowExA(
                     0,
                     "Heroes II",
                     "Heroes of Might and Magic II",
                     dwStyle,
                     *(&mainWindows + 7 * gameOrEditorIdx + 1),
                     *(&mainWindows + 7 * gameOrEditorIdx + 2),
                     Rect.right - Rect.left + 1,
                     Rect.bottom - Rect.top + 1,
                     0,
                     hMenu,
                     hInstance,
                     0);
    if ( windowHandle )
    {
      v6 = (LPARAM)LoadIconA(hInstance, "Heroes");
      PostMessageA(windowHandle, 0x80u, 0, v6);
      ShowWindow(windowHandle, nCmdShow);
      SetWindowLongA(windowHandle, -16, dwStyle);
      if ( !*(&mainWindows + 7 * gameOrEditorIdx) )
        sub_485B30(0);
      sub_49CE90();
      v7 = LoadCursorA(0, (LPCSTR)0x7F00);
      SetCursor(v7);
      showTitleScreen();
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
