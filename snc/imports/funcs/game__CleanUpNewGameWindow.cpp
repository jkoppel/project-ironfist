{
  void *v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  for ( i = 0; i < 6; ++i )
  {
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 6);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 18);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 12);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 24);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 30);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 36);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 78);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 42);
    heroWindow::RemoveAndDeleteWidget(*((heroWindow **)v1 + 6374), i + 48);
  }
}