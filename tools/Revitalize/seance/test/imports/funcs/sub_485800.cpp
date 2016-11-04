{
  signed int result; // eax@9

  switch ( a2 )
  {
    case MENU_BUTTON_ABOUT:
      DialogBoxParamA(hInstance, "HEROES", this, (DLGPROC)sub_485530, 0);
      goto LABEL_11;
    case MENU_BUTTON_MANUAL:
      WinHelpA(windowHandle, ".\\HELP\\HEROES2.HLP", 0xBu, 0);
      goto LABEL_11;
    case MENU_BUTTON_640X480:
      setWindowRectangle(-1, -1, 0x280u, 0x1E0u);
      goto LABEL_11;
    case MENU_BUTTON_800X600:
      setWindowRectangle(-1, -1, 0x320u, 0x258u);
      goto LABEL_11;
    case MENU_BUTTON_1024X768:
      setWindowRectangle(-1, -1, 0x400u, 0x300u);
      goto LABEL_11;
    case MENU_BUTTON_1280X1024:
      setWindowRectangle(-1, -1, 0x500u, 0x400u);
      goto LABEL_11;
    case MENU_BUTTON_FULLSCREEN:
      sub_49D030((void *)(1 - *(&mainWindows + 7 * gameOrEditorIdx + 5)));
LABEL_11:
      result = 0;
      break;
    default:
      result = sub_437780(a2);
      break;
  }
  return result;
}
