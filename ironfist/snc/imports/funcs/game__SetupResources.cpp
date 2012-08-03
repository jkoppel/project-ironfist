{
  int result; // eax@3
  int evt; // [sp+10h] [bp-20h]@1
  int v2; // [sp+14h] [bp-1Ch]@3
  int v3; // [sp+18h] [bp-18h]@3
  char *v4; // [sp+28h] [bp-8h]@3
  int i; // [sp+2Ch] [bp-4h]@1

  evt = 512;
  for ( i = 0; i < 7; ++i )
  {
    v2 = 3;
    v4 = gText;
    sprintf(gText, "%d", gpCurPlayer->resources[i]);
    v3 = i + 30;
    result = heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  }
  return result;
}