{
  int evt; // [sp+14h] [bp-1Ch]@1
  int v2; // [sp+18h] [bp-18h]@1
  int v3; // [sp+1Ch] [bp-14h]@1
  void *v4; // [sp+2Ch] [bp-4h]@1

  evt = 512;
  v2 = 3;
  v3 = 1;
  v4 = this;
  GUIWindow::processMessage(eventWindow, (Event *)&evt);
  GUIWindow::repaintComponentsInRange(eventWindow, 0, 0, 36864);
  GUIWindow::repaintComponentsInRange(eventWindow, 1, -65535, -256);
}
