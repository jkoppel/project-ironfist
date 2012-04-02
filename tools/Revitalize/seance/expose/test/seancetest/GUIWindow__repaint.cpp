void __thiscall GUIWindow::repaint(GUIWindow *this, int updateScreen)
{
  GUIWindow::repaintComponentsInRange(this, updateScreen, -65535, 65535);
}
