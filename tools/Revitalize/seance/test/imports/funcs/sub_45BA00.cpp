{
  void *v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  for ( i = 0; i < 6; ++i )
  {
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 6);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 18);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 12);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 24);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 30);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 36);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 78);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 42);
    GUIWindow::removeComponentByID(*((GUIWindow **)v1 + 6374), i + 48);
  }
}
