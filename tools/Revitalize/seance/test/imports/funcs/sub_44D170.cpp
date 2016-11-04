{
  void *v3; // [sp+14h] [bp-30h]@1
  int evt; // [sp+20h] [bp-24h]@2
  int v5; // [sp+24h] [bp-20h]@4
  int v6; // [sp+28h] [bp-1Ch]@4
  int v7; // [sp+38h] [bp-Ch]@7
  unsigned int v8; // [sp+3Ch] [bp-8h]@4
  int i; // [sp+40h] [bp-4h]@2

  v3 = this;
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    evt = 512;
    for ( i = 0; i < 4; ++i )
    {
      v8 = *(&curPlayer->castlesOwned[i] + HIBYTE(curPlayer->field_45));
      v5 = 8;
      v6 = i + 32;
      if ( LOBYTE(curPlayer->field_45) == -1 || LOBYTE(curPlayer->field_45) != v8 || dword_4F7470 )
        v7 = 36;
      else
        v7 = 153;
      GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
      v6 = i + 16;
      if ( v8 == -1 || dword_4F7470 )
      {
        v5 = 4;
        v7 = i + 5;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
        v5 = 6;
        v7 = 2;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
        v5 = 6;
        v7 = 4;
        v6 = i + 300;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
      }
      else
      {
        v5 = 5;
        v7 = 2;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
        v5 = 4;
        v7 = gameObject->castles[v8].factionID + 9;
        if ( !(gameObject->castles[v8].buildingsBuiltFlags & 0x40) )
          v7 += 6;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
        if ( sub_4D05D8((int)&gameObject->_7[72], v8) )
          v5 = 5;
        else
          v5 = 6;
        v7 = 4;
        v6 = i + 300;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 154), (Event *)&evt);
      }
    }
    *(_WORD *)(*(_DWORD *)((char *)v3 + 182) + 26) = curPlayer->numCastles >= 5 ? (unsigned __int16)(signed __int64)((double)HIBYTE(curPlayer->field_45) * (74.0 / (double)((signed int)curPlayer->numCastles - 4)) + 195.0) : 232;
    if ( a2 )
      GUIWindow::repaint(*(GUIWindow **)((char *)v3 + 154), a3);
  }
}
