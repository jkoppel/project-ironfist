{
  HMENU tempMenu; // [sp+Ch] [bp-4h]@1

  tempMenu = menu;
  if ( menu )
    globalMenu1 = (HMENU *)menu;
  else
    tempMenu = globalMenu1;
  globalMenu2 = tempMenu;
  if ( *(&mainWindows + 7 * gameOrEditorIdx) )
  {
    if ( tempMenu )
    {
      SetMenu(windowHandle, tempMenu);
      disableTooLargeDisplayControls(tempMenu);
      handleSwitchingToAdventureMenu(tempMenu);
      DrawMenuBar(windowHandle);
    }
  }
  else
  {
    SetMenu(windowHandle, NULL);
    DrawMenuBar(windowHandle);
  }
}
