{
  int evt; // [sp+10h] [bp-20h]@1
  int v2; // [sp+14h] [bp-1Ch]@4
  int v3; // [sp+18h] [bp-18h]@6
  int v4; // [sp+28h] [bp-8h]@6
  int i; // [sp+2Ch] [bp-4h]@1

  evt = 512;
  hero::UpdateArmies(this);
  for ( i = 0; i < 5; ++i )
  {
    if ( giHeroScreenSrcIndex == i )
      v2 = 5;
    else
      v2 = 6;
    v4 = 4;
    v3 = i + 102;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  heroWindow::DrawWindow(heroWin);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
}