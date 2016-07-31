{
  __int16 imgIdx; // [sp+Ch] [bp-14h]@7
  GUIIcon *this; // [sp+10h] [bp-10h]@5
  int v2; // [sp+18h] [bp-8h]@3
  signed int i; // [sp+1Ch] [bp-4h]@1

  for ( i = 0; i < 3; ++i )
  {
    GUIWindow::removeComponent(dword_525228, (AbstractGUIComponent *)dword_525230[i]);
    v2 = dword_525230[i];
    if ( v2 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 4))(v2);
    dword_525230[i] = 0;
    this = (GUIIcon *)operator new(0x2Du);
    if ( this )
    {
      if ( dword_52523C == i )
        imgIdx = i + 4;
      else
        imgIdx = i;
      dword_525230[i] = (int)GUIIcon_constructor(
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
      dword_525230[i] = 0;
    }
    if ( !dword_525230[i] )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(dword_525228, (AbstractGUIComponent *)dword_525230[i], -1);
  }
  GUIWindow::repaintComponentsInRange(dword_525228, 1, 100, 102);
}
