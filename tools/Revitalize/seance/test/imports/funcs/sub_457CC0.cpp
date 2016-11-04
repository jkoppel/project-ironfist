{
  void *v1; // [sp+Ch] [bp-24h]@1
  int evt; // [sp+10h] [bp-20h]@1
  int v3; // [sp+14h] [bp-1Ch]@1
  int v4; // [sp+18h] [bp-18h]@1
  int v5; // [sp+28h] [bp-8h]@2
  int v6; // [sp+2Ch] [bp-4h]@8

  v1 = this;
  evt = 512;
  v3 = 4;
  v4 = 10;
  if ( *(_DWORD *)&musicVolume )
    v5 = 1;
  else
    v5 = 0;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 11;
  if ( *(_DWORD *)&soundVolume )
    v5 = 3;
  else
    v5 = 2;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 12;
  v5 = *(_DWORD *)&walkSpeed + 4;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 13;
  if ( *(_DWORD *)&useCDMusic )
  {
    if ( *(_DWORD *)&useOpera )
      v6 = 2;
    else
      v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  v5 = v6 + 10;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 14;
  v5 = (*(_DWORD *)&showRoute < 1u) + 13;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 15;
  if ( *(_DWORD *)&blackoutComputer )
    v5 = 9;
  else
    v5 = *(_DWORD *)&computerWalkSpeed + 4;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 16;
  v5 = *(_DWORD *)&evilInterfaceUsage + 15;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 17;
  v5 = (*(_DWORD *)&slowVideo >= 1u) + 18;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 18;
  v5 = *(&mainWindows + 6) + 20;
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v3 = 3;
  v4 = 20;
  v5 = (int)off_4F62B0[*(_DWORD *)&musicVolume];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 21;
  v5 = (int)off_4F62B0[*(_DWORD *)&soundVolume];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 22;
  v5 = (int)off_4F62E0[*(_DWORD *)&walkSpeed];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 23;
  v5 = (int)off_4F69A8[v6];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 24;
  v5 = (int)off_4F62B0[*(_DWORD *)&showRoute];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 25;
  if ( *(_DWORD *)&blackoutComputer )
    v5 = (int)"Don't Show";
  else
    v5 = (int)off_4F62E0[*(_DWORD *)&computerWalkSpeed];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 26;
  v5 = (int)off_4F6F20[*(_DWORD *)&evilInterfaceUsage];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 27;
  v5 = (int)off_4F71D4[-(*(_DWORD *)&slowVideo < 1u)];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  v4 = 28;
  v5 = (int)off_4F6F30[*(&mainWindows + 6)];
  GUIWindow::processMessage(dword_524E9C, (Event *)&evt);
  if ( !v1 )
    GUIWindow::repaintComponentsInRange(dword_524E9C, 1, 0, 32767);
}
