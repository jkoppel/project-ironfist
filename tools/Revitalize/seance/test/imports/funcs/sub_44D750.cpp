{
  void *v2; // [sp+Ch] [bp-38h]@1
  GUIIcon *v3; // [sp+10h] [bp-34h]@45
  GUIIcon *v4; // [sp+14h] [bp-30h]@32
  GUIIcon *v5; // [sp+18h] [bp-2Ch]@20
  GUIIcon *v6; // [sp+1Ch] [bp-28h]@7
  GUIIcon *thisa; // [sp+20h] [bp-24h]@2
  int evt; // [sp+24h] [bp-20h]@1
  int v9; // [sp+28h] [bp-1Ch]@19
  int v10; // [sp+2Ch] [bp-18h]@19
  int v11; // [sp+3Ch] [bp-8h]@19
  int v12; // [sp+40h] [bp-4h]@1

  v2 = this;
  v12 = 0;
  evt = 512;
  if ( dword_50EAA0 != 4 )
  {
    v12 = 1;
    dword_50EAB0 = 1;
    sub_44D610(this);
    dword_50EAA0 = 4;
    thisa = (GUIIcon *)operator new(0x2Du);
    if ( thisa )
      *(_DWORD *)((char *)v2 + 58) = GUIIcon_constructor(thisa, 480, 392, 143, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 58) = 0;
    if ( !*(_DWORD *)((char *)v2 + 58) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 58), 1000);
    v6 = (GUIIcon *)operator new(0x2Du);
    if ( v6 )
      *(_DWORD *)((char *)v2 + 62) = GUIIcon_constructor(v6, 493, 403, 118, 51, "hourglas.icn", 0, 0, 2001, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 62) = 0;
    if ( !*(_DWORD *)((char *)v2 + 62) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 62), 1010);
  }
  if ( dword_50EAB0 || getTickCount() - dword_50F3D0 > 300 )
  {
    dword_50F3D0 = getTickCount();
    dword_524CB0 = *(_DWORD *)((char *)v2 + 510);
    if ( getTickCount() - dword_50F3D4 > 300 )
    {
      dword_50F3D4 = getTickCount();
      ++dword_50EA90;
      if ( dword_50EA90 >= 20 )
        dword_50EA90 = 16;
      v12 = 1;
      if ( *(_DWORD *)((char *)v2 + 70) )
      {
        v9 = 4;
        v10 = 2003;
        v11 = dword_50EA90 + 11;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v2 + 154), (Event *)&evt);
      }
      else
      {
        v5 = (GUIIcon *)operator new(0x2Du);
        if ( v5 )
          *(_DWORD *)((char *)v2 + 70) = GUIIcon_constructor(
                                           v5,
                                           559,
                                           405,
                                           50,
                                           47,
                                           "hourglas.icn",
                                           dword_50EA90 + 11,
                                           0,
                                           2003,
                                           16,
                                           1);
        else
          *(_DWORD *)((char *)v2 + 70) = 0;
        if ( !*(_DWORD *)((char *)v2 + 70) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 70), 1020);
      }
    }
  }
  if ( dword_50EAB0 || dword_50EAA4 != curPlayerIdx )
  {
    v12 = 1;
    dword_50EAA4 = curPlayerIdx;
    if ( curPlayerIdx != curPlayerIdx )
      LODWORD(qword_50EAA8) = 0;
    if ( *(_DWORD *)((char *)v2 + 66) )
    {
      v9 = 4;
      v10 = 2002;
      v11 = gameObject->players[(char)curPlayerIdx].color;
      GUIWindow::processMessage(*(GUIWindow **)((char *)v2 + 154), (Event *)&evt);
    }
    else
    {
      v4 = (GUIIcon *)operator new(0x2Du);
      if ( v4 )
        *(_DWORD *)((char *)v2 + 66) = GUIIcon_constructor(
                                         v4,
                                         495,
                                         405,
                                         50,
                                         47,
                                         "brcrest.icn",
                                         gameObject->players[(char)curPlayerIdx].color,
                                         0,
                                         2002,
                                         16,
                                         1);
      else
        *(_DWORD *)((char *)v2 + 66) = 0;
      if ( !*(_DWORD *)((char *)v2 + 66) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 66), 1030);
    }
  }
  if ( dword_50EAB0
    || SHIDWORD(qword_50EAA8) > (signed int)qword_50EAA8
    || SHIDWORD(qword_50EAA8) < 0
    || SHIDWORD(qword_50EAA8) < (signed int)qword_50EAA8 && getTickCount() - dword_50EA94 >= 700 )
  {
    v12 = 1;
    HIDWORD(qword_50EAA8) = qword_50EAA8;
    dword_50EA94 = getTickCount();
    if ( *(_DWORD *)((char *)v2 + 74) )
    {
      v9 = 4;
      v10 = 2004;
      v11 = qword_50EAA8 + 1;
      GUIWindow::processMessage(*(GUIWindow **)((char *)v2 + 154), (Event *)&evt);
    }
    else
    {
      v3 = (GUIIcon *)operator new(0x2Du);
      if ( v3 )
        *(_DWORD *)((char *)v2 + 74) = GUIIcon_constructor(
                                         v3,
                                         559,
                                         405,
                                         50,
                                         47,
                                         "hourglas.icn",
                                         qword_50EAA8 + 1,
                                         0,
                                         2004,
                                         16,
                                         1);
      else
        *(_DWORD *)((char *)v2 + 74) = 0;
      if ( !*(_DWORD *)((char *)v2 + 74) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 74), 1040);
    }
  }
  return v12;
}
