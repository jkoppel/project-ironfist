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
  LogInt((int)"hInstApp", (int)hInstApp, -999, -999, -999, -999, -999, -999);
  memset(bProcessMessage, 0, 0x400u);
  bProcessMessage[1] = 1;
  bProcessMessage[256] = 1;
  bProcessMessage[257] = 1;
  bProcessMessage[512] = 1;
  bProcessMessage[513] = 1;
  bProcessMessage[515] = 1;
  bProcessMessage[516] = 1;
  bProcessMessage[518] = 1;
  bProcessMessage[514] = 1;
  bProcessMessage[517] = 1;
  bProcessMessage[275] = 1;
  bProcessMessage[28] = 1;
  bProcessMessage[20] = 1;
  bProcessMessage[3] = 1;
  bProcessMessage[5] = 1;
  bProcessMessage[273] = 1;
  bProcessMessage[785] = 1;
  bProcessMessage[783] = 1;
  bProcessMessage[15] = 1;
  bProcessMessage[2] = 1;
  bProcessMessage[18] = 1;
  bProcessMessage[16] = 1;
  bProcessMessage[953] = 1;
  if ( v4
    || (WndClass.hCursor = NULL,
        WndClass.hIcon = LoadIconA(hInstance, "Heroes II"),
        WndClass.lpszMenuName = NULL,
        WndClass.lpszClassName = "Heroes II",
        WndClass.hbrBackground = (HBRUSH)COLOR_WINDOWFRAME,
        WndClass.hInstance = hInstance,
        WndClass.style = CS_BYTEALIGNCLIENT|CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW,
        WndClass.lpfnWndProc = (WNDPROC)AppWndProc,
        WndClass.cbWndExtra = 0,
        WndClass.cbClsExtra = 0,
        RegisterClassA(&WndClass)) )
  {
    if ( *(&bMenu + 7 * giCurExe) )
      giCurWindowsStyleFlags = 0x14CF0000u;
    else
      giCurWindowsStyleFlags = 0x14000000u;
    Rect.top = 0;
    Rect.left = 0;
    Rect.right = *(&bMenu + 7 * giCurExe + 3) - 1;
    Rect.bottom = *(&bMenu + 7 * giCurExe + 4) - 1;
    AdjustWindowRect(&Rect, giCurWindowsStyleFlags, *(&bMenu + 7 * giCurExe));
    if ( *(&bMenu + 7 * giCurExe) )
      hMenu = hmnuDflt;
    else
      hMenu = 0;
    hwndApp = CreateWindowExA(
                0,
                "Heroes II",
                "Heroes of Might and Magic II",
                giCurWindowsStyleFlags,
                *(&bMenu + 7 * giCurExe + 1),
                *(&bMenu + 7 * giCurExe + 2),
                Rect.right - Rect.left + 1,
                Rect.bottom - Rect.top + 1,
                0,
                hMenu,
                hInstance,
                0);
    if ( hwndApp )
    {
      v6 = (LPARAM)LoadIconA(hInstance, "Heroes");
      PostMessageA(hwndApp, 0x80u, 0, v6);
      ShowWindow(hwndApp, nCmdShow);
      SetWindowLongA(hwndApp, -16, giCurWindowsStyleFlags);
      if ( !*(&bMenu + 7 * giCurExe) )
        SetMenuStatus(0);
      InitGraphics();
      v7 = LoadCursorA(0, (LPCSTR)0x7F00);
      SetCursor(v7);
      oldmain();
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