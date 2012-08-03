{
  HMENU hMenu; // [sp+Ch] [bp-Ch]@1

  hMenu = hMenua;
  if ( *(&bMenu + 7 * giCurExe) )
  {
    if ( giMainVideoModeWidth <= 640 )
      EnableMenuItem(hMenua, MENU_BUTTON_640X480, MF_GRAYED);
    if ( giMainVideoModeWidth <= 800 )
      EnableMenuItem(hMenu, MENU_BUTTON_800X600, MF_GRAYED);
    if ( giMainVideoModeWidth <= 1024 )
      EnableMenuItem(hMenu, MENU_BUTTON_1024X768, MF_GRAYED);
    if ( giMainVideoModeWidth <= 1280 )
      EnableMenuItem(hMenu, MENU_BUTTON_1280X1024, MF_GRAYED);
    if ( !gbDDrawAttached )
      EnableMenuItem(hMenu, MENU_BUTTON_FULLSCREEN, MF_GRAYED);
  }
}