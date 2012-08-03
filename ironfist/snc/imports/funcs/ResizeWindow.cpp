{
  int v4; // [sp+Ch] [bp-20h]@1
  int v5; // [sp+10h] [bp-1Ch]@1
  int X; // [sp+14h] [bp-18h]@3
  struct tagRECT Rect; // [sp+18h] [bp-14h]@2
  int Y; // [sp+28h] [bp-4h]@6

  v4 = y;
  v5 = x;
  if ( !*(&bMenu + 7 * giCurExe + 5) )
  {
    GetWindowRect(hwndApp, &Rect);
    if ( v5 == -1 )
      X = Rect.left;
    else
      X = v5;
    if ( v4 == -1 )
      Y = Rect.top;
    else
      Y = v4;
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = width - 1;
    Rect.bottom = heightNeededToDisplay - 1;
    AdjustWindowRect(&Rect, giCurWindowsStyleFlags, *(&bMenu + 7 * giCurExe));
    MoveWindow(hwndApp, X, Y, Rect.right - Rect.left + 1, Rect.bottom - Rect.top + 1, 1);
    *(&bMenu + 7 * giCurExe + 1) = X;
    *(&bMenu + 7 * giCurExe + 2) = Y;
    *(&bMenu + 7 * giCurExe + 3) = width;
    *(&bMenu + 7 * giCurExe + 4) = heightNeededToDisplay;
    WritePrefs();
  }
}