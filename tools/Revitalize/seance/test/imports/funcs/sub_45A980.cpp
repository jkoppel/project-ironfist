{
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  *(_BYTE *)(this + 1146) = 0;
  *(_BYTE *)(this + 1147) = dword_5235D4;
  if ( *(_DWORD *)(this + 25496) )
  {
    sub_45BA00((void *)this);
    sub_45AA00(v2, a2);
    sub_45BB00(v2);
    sub_45C180(v2);
    GUIWindow::repaintAndUpdateScreen(*(GUIWindow **)(v2 + 25496));
  }
}
