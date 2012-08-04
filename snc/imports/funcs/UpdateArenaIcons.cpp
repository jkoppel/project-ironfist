{
  __int16 imgIdx; // [sp+Ch] [bp-14h]@7
  iconWidget *this; // [sp+10h] [bp-10h]@5
  int v2; // [sp+18h] [bp-8h]@3
  signed int i; // [sp+1Ch] [bp-4h]@1

  for ( i = 0; i < 3; ++i )
  {
    heroWindow::RemoveWidget(arenaWinPtr, (widget *)skillWidget[i]);
    v2 = skillWidget[i];
    if ( v2 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 4))(v2);
    skillWidget[i] = 0;
    this = (iconWidget *)operator new(45);
    if ( this )
    {
      if ( choice == i )
        imgIdx = i + 4;
      else
        imgIdx = i;
      skillWidget[i] = (int)iconWidget::iconWidget(
                              this,
                              60 * i + 84,
                              244,
                              39,
                              34,
                              "xprimary.icn",
                              imgIdx,
                              0,
                              i + 100,
                              16,
                              1);
    }
    else
    {
      skillWidget[i] = 0;
    }
    if ( !skillWidget[i] )
      MemError();
    heroWindow::AddWidget(arenaWinPtr, (widget *)skillWidget[i], -1);
  }
  heroWindow::DrawWindow(arenaWinPtr, 1, 100, 102);
}