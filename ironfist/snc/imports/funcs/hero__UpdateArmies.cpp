{
  int result; // eax@4
  hero *v2; // [sp+Ch] [bp-24h]@1
  int evt; // [sp+10h] [bp-20h]@1
  int v4; // [sp+14h] [bp-1Ch]@4
  int v5; // [sp+18h] [bp-18h]@4
  int v6; // [sp+28h] [bp-8h]@4
  int i; // [sp+2Ch] [bp-4h]@1

  v2 = this;
  evt = 512;
  for ( i = 0; i < 5; ++i )
  {
    if ( v2->army.creatureTypes[i] == -1 )
    {
      v4 = 4;
      v5 = i + 87;
      v6 = 2;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v4 = 6;
      v5 = i + 92;
      v6 = 4;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v5 = i + 97;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v5 = i + 102;
      result = heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
    else
    {
      v4 = 4;
      v5 = i + 87;
      v6 = gMonsterDatabase[v2->army.creatureTypes[i]].faction + 4;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v4 = 9;
      sprintf(gText, "monh%04d.icn", v2->army.creatureTypes[i]);
      v5 = i + 92;
      v6 = (int)gText;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v4 = 5;
      v6 = 4;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      sprintf(gText, "%d", v2->army.quantities[i]);
      v4 = 3;
      v5 = i + 97;
      v6 = (int)gText;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v4 = 5;
      v6 = 4;
      result = heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
  }
  return result;
}