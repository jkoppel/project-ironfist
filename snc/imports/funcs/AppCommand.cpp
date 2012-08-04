{
  signed int result; // eax@9

  switch ( a2 )
  {
    case MENU_BUTTON_ABOUT:
      DialogBoxParamA(hInstApp, "HEROES", this, (DLGPROC)AppAbout, 0);
      goto LABEL_11;
    case MENU_BUTTON_MANUAL:
      WinHelpA(hwndApp, ".\\HELP\\HEROES2.HLP", 0xBu, 0);
      goto LABEL_11;
    case MENU_BUTTON_640X480:
      ResizeWindow(-1, -1, 0x280u, 0x1E0u);
      goto LABEL_11;
    case MENU_BUTTON_800X600:
      ResizeWindow(-1, -1, 0x320u, 0x258u);
      goto LABEL_11;
    case MENU_BUTTON_1024X768:
      ResizeWindow(-1, -1, 0x400u, 0x300u);
      goto LABEL_11;
    case MENU_BUTTON_1280X1024:
      ResizeWindow(-1, -1, 0x500u, 0x400u);
      goto LABEL_11;
    case MENU_BUTTON_FULLSCREEN:
      SetFullScreenStatus((void *)(1 - *(&bMenu + 7 * giCurExe + 5)));
LABEL_11:
      result = 0;
      break;
    default:
      result = HandleAppSpecificMenuCommands(a2, edx0);
      break;
  }
  return result;
}