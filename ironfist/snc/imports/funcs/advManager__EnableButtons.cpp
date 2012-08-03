{
  advManager *result; // eax@1
  int evt; // [sp+10h] [bp-1Ch]@2
  int v4; // [sp+14h] [bp-18h]@2
  int v5; // [sp+18h] [bp-14h]@2
  int v6; // [sp+28h] [bp-4h]@2

  result = gpAdvManager;
  if ( gpAdvManager->ready == 1 )
  {
    evt = 512;
    v4 = 5;
    v6 = 2;
    v5 = 1;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    v5 = 2;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    v5 = 3;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    v5 = 4;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    v5 = 5;
    heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
    v5 = 6;
    result = (advManager *)heroWindow::BroadcastMessage(this->adventureScreen, (Event *)&evt);
  }
  return result;
}