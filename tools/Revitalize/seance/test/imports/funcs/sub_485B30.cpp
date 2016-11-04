{
  BOOL v1; // ST1C_4@3
  BOOL v2; // ST20_4@3

  if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) || !this )
  {
    v1 = *(&mainWindows + 7 * gameOrEditorIdx + 3);
    v2 = *(&mainWindows + 7 * gameOrEditorIdx + 4);
    *(&mainWindows + 7 * gameOrEditorIdx) = this;
    changeMenu(0);
    *(&mainWindows + 7 * gameOrEditorIdx + 3) = v1;
    *(&mainWindows + 7 * gameOrEditorIdx + 4) = v2;
    propagateSettingChanges();
    GetWindowLongA(windowHandle, -16);
    if ( *(&mainWindows + 7 * gameOrEditorIdx) )
      dwStyle = 349110272;
    else
      dwStyle = 335544320;
    SetWindowLongA(windowHandle, -16, dwStyle);
    ShowWindow(windowHandle, 8);
    setWindowRectangle(-1, -1, *(&mainWindows + 7 * gameOrEditorIdx + 3), *(&mainWindows + 7 * gameOrEditorIdx + 4));
  }
}
