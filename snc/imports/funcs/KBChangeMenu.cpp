{
  HMENU tempMenu; // [sp+Ch] [bp-4h]@1

  tempMenu = menu;
  if ( menu )
    hmnuCurrent = (HMENU *)menu;
  else
    tempMenu = hmnuCurrent;
  hmnuApp = tempMenu;
  if ( *(&bMenu + 7 * giCurExe) )
  {
    if ( tempMenu )
    {
      SetMenu(hwndApp, tempMenu);
      UpdateDfltMenu(tempMenu);
      UpdateAppSpecificMenus(tempMenu);
      DrawMenuBar(hwndApp);
    }
  }
  else
  {
    SetMenu(hwndApp, NULL);
    DrawMenuBar(hwndApp);
  }
}