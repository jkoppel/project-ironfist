{
  BOOL v1; // ST1C_4@3
  BOOL v2; // ST20_4@3

  if ( !*(&bMenu + 7 * giCurExe + 5) || !this )
  {
    v1 = *(&bMenu + 7 * giCurExe + 3);
    v2 = *(&bMenu + 7 * giCurExe + 4);
    *(&bMenu + 7 * giCurExe) = this;
    KBChangeMenu(0);
    *(&bMenu + 7 * giCurExe + 3) = v1;
    *(&bMenu + 7 * giCurExe + 4) = v2;
    WritePrefs();
    GetWindowLongA(hwndApp, -16);
    if ( *(&bMenu + 7 * giCurExe) )
      giCurWindowsStyleFlags = 349110272;
    else
      giCurWindowsStyleFlags = 335544320;
    SetWindowLongA(hwndApp, -16, giCurWindowsStyleFlags);
    ShowWindow(hwndApp, 8);
    ResizeWindow(-1, -1, *(&bMenu + 7 * giCurExe + 3), *(&bMenu + 7 * giCurExe + 4));
  }
}