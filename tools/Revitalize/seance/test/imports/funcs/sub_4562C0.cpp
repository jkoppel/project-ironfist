{
  AdvManager *result; // eax@1
  int v2; // [sp+Ch] [bp-20h]@1
  int evt; // [sp+10h] [bp-1Ch]@2
  int v4; // [sp+14h] [bp-18h]@2
  int v5; // [sp+18h] [bp-14h]@2
  int v6; // [sp+28h] [bp-4h]@2

  v2 = this;
  result = advManager;
  if ( advManager->ready == 1 )
  {
    evt = 512;
    v4 = 5;
    v6 = 2;
    v5 = 1;
    GUIWindow::processMessage(*(GUIWindow **)(this + 154), (Event *)&evt);
    v5 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 154), (Event *)&evt);
    v5 = 3;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 154), (Event *)&evt);
    v5 = 4;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 154), (Event *)&evt);
    v5 = 5;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 154), (Event *)&evt);
    v5 = 6;
    result = (AdvManager *)GUIWindow::processMessage(*(GUIWindow **)(v2 + 154), (Event *)&evt);
  }
  return result;
}
