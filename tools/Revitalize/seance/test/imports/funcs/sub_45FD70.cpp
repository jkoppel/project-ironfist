{
  int v1; // ST0C_4@5
  char *v2; // eax@5
  int evt; // [sp+Ch] [bp-1Ch]@5
  int v4; // [sp+10h] [bp-18h]@5
  int v5; // [sp+14h] [bp-14h]@5
  int v6; // [sp+24h] [bp-4h]@5

  sub_45F910();
  if ( dword_5235D4 != dword_511788 )
  {
    if ( dword_52340C != -1 && dword_523410 <= dword_5235D4 )
      return 1;
    dword_511788 = dword_5235D4;
    v1 = dword_5235D4 - 1;
    v2 = inet_ntoa(in);
    sprintf(
      cp,
      "Hosting game at %s.\n\nYou have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
      v2,
      v1);
    evt = 512;
    v4 = 3;
    v5 = 1;
    v6 = (int)cp;
    GUIWindow::processMessage(eventWindow, (Event *)&evt);
    GUIWindow::repaintAndUpdateScreen(eventWindow);
  }
  return 0;
}
