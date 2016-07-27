{
  int result; // eax@1
  void *v5; // [sp+10h] [bp-8h]@1
  signed int v6; // [sp+14h] [bp-4h]@1

  v5 = this;
  v6 = 0;
  result = a2;
  dword_50EAB0 = a2;
  if ( dword_52405C == 6 )
    return result;
  if ( dword_52405C > 0 )
  {
    if ( getTickCount() <= dword_524798 )
    {
      switch ( dword_52405C )
      {
        case 1:
          v6 = sub_44DC70(v5);
          break;
        case 2:
          v6 = sub_44E340(v5);
          break;
        case 5:
          v6 = sub_44DFE0(v5);
          break;
      }
      goto LABEL_20;
    }
    dword_52405C = 0;
  }
  if ( *(&byte_524758 + curPlayerIdx) && !dword_4F7470 && gameObject->players[curPlayerIdx].color == curPlayer->color )
  {
    if ( curPlayer->_1[0] == -1 )
      v6 = sub_44E340(v5);
    else
      v6 = sub_44E6B0(v5);
  }
  else
  {
    v6 = sub_44D750(v5);
  }
LABEL_20:
  if ( v6 && a3 )
  {
    GUIWindow::repaintComponentsInRange(*(GUIWindow **)((char *)v5 + 154), 0, 2000, 2200);
    if ( a4 )
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 480, 392, 0x8Fu, 71);
  }
  return dword_50EAB0;
}
