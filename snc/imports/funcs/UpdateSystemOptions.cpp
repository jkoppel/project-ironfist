{
  void *v1; // [sp+Ch] [bp-24h]@1
  int evt; // [sp+10h] [bp-20h]@1
  int v3; // [sp+14h] [bp-1Ch]@1
  int v4; // [sp+18h] [bp-18h]@1
  bool v5; // [sp+28h] [bp-8h]@1
  int v6; // [sp+2Ch] [bp-4h]@5

  v1 = this;
  evt = 512;
  v3 = 4;
  v4 = 10;
  v5 = *(_DWORD *)&Data != 0;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 11;
  if ( *(_DWORD *)&soundVolume )
    v5 = 3;
  else
    v5 = 2;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 12;
  v5 = *(_DWORD *)&walkSpeed + 4;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
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
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 14;
  v5 = (*(_DWORD *)&showRoute < 1u) + 13;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 15;
  if ( *(_DWORD *)&blackoutComputer )
    v5 = 9;
  else
    v5 = *(_DWORD *)&gConfig + 4;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 16;
  v5 = *(_DWORD *)&evilInterfaceUsage + 15;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 17;
  v5 = (*(_DWORD *)&slowVideo >= 1u) + 18;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 18;
  v5 = *(&bMenu + 6) + 20;
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v3 = 3;
  v4 = 20;
  v5 = (bool)onOffText[*(_DWORD *)&Data];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 21;
  v5 = (bool)onOffText[*(_DWORD *)&soundVolume];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 22;
  v5 = (bool)walkSpeedText[*(_DWORD *)&walkSpeed];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 23;
  v5 = (bool)musicQualityText[v6];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 24;
  v5 = (bool)onOffText[*(_DWORD *)&showRoute];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 25;
  if ( *(_DWORD *)&blackoutComputer )
    v5 = (bool)"Don't Show";
  else
    v5 = (bool)walkSpeedText[*(_DWORD *)&gConfig];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 26;
  v5 = (bool)gInterfaceTypeText[*(_DWORD *)&evilInterfaceUsage];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 27;
  v5 = (bool)off_4F71D4[-(*(_DWORD *)&slowVideo < 1u)];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  v4 = 28;
  v5 = (bool)cBWMouseText[*(&bMenu + 6)];
  heroWindow::BroadcastMessage(cPanel, (Event *)&evt);
  if ( !v1 )
    heroWindow::DrawWindow(cPanel, 1, 0, 32767);
}