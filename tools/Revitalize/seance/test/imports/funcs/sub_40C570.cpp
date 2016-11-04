{
  int v3; // [sp+Ch] [bp-20h]@1
  int evt; // [sp+10h] [bp-1Ch]@1
  int v5; // [sp+14h] [bp-18h]@2
  int v6; // [sp+18h] [bp-14h]@4
  int v7; // [sp+28h] [bp-4h]@5

  v3 = this;
  evt = 512;
  if ( a2 )
    v5 = 6;
  else
    v5 = 5;
  v6 = 30722;
  if ( *(_DWORD *)(this + 50) == 1 )
    v7 = 8;
  else
    v7 = 4096;
  GUIWindow::processMessage(*(GUIWindow **)(this + 54), (Event *)&evt);
  if ( a2 )
    v5 = 5;
  else
    v5 = 6;
  v7 = 2;
  return GUIWindow::processMessage(*(GUIWindow **)(v3 + 54), (Event *)&evt);
}
