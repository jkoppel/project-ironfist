{
  int evt; // [sp+Ch] [bp-1Ch]@2
  int v2; // [sp+10h] [bp-18h]@2
  int v3; // [sp+14h] [bp-14h]@2
  char *v4; // [sp+24h] [bp-4h]@2

  sub_404EA0();
  if ( dword_4ED314 != dword_5235D4 )
  {
    dword_4ED314 = dword_5235D4;
    sprintf(
      globBuf,
      "You have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
      dword_5235D4 - 1);
    evt = 512;
    v2 = 3;
    v3 = 1;
    v4 = globBuf;
    GUIWindow::processMessage(eventWindow, (Event *)&evt);
    GUIWindow::repaintAndUpdateScreen(eventWindow);
  }
  return 0;
}
