{
  int v4; // [sp+Ch] [bp-20h]@1
  int v5; // [sp+10h] [bp-1Ch]@1
  int X; // [sp+14h] [bp-18h]@3
  struct tagRECT Rect; // [sp+18h] [bp-14h]@2
  int Y; // [sp+28h] [bp-4h]@6

  v4 = y;
  v5 = x;
  if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
  {
    GetWindowRect(windowHandle, &Rect);
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
    AdjustWindowRect(&Rect, dwStyle, *(&mainWindows + 7 * gameOrEditorIdx));
    MoveWindow(windowHandle, X, Y, Rect.right - Rect.left + 1, Rect.bottom - Rect.top + 1, 1);
    *(&mainWindows + 7 * gameOrEditorIdx + 1) = X;
    *(&mainWindows + 7 * gameOrEditorIdx + 2) = Y;
    *(&mainWindows + 7 * gameOrEditorIdx + 3) = width;
    *(&mainWindows + 7 * gameOrEditorIdx + 4) = heightNeededToDisplay;
    propagateSettingChanges();
  }
}
