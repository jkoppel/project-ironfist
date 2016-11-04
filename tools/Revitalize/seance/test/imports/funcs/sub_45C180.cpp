{
  __int16 v1; // ax@44
  int v2; // [sp+Ch] [bp-2Ch]@1
  int evt; // [sp+10h] [bp-28h]@1
  int v4; // [sp+14h] [bp-24h]@1
  int v5; // [sp+18h] [bp-20h]@1
  int v6; // [sp+28h] [bp-10h]@1
  int i; // [sp+2Ch] [bp-Ch]@1
  bool v8; // [sp+34h] [bp-4h]@21

  v2 = this;
  strcpy(globBuf, (const char *)(this + 739));
  evt = 512;
  v4 = 3;
  v5 = 64;
  v6 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
  v4 = 6;
  v6 = 4;
  for ( i = 0; i < 5; ++i )
  {
    v5 = i + 67;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
  }
  v4 = 5;
  v5 = *(_BYTE *)(v2 + 1125) + 67;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
  if ( dword_5235D4 > 1 )
  {
    for ( i = 0; i < 3; ++i )
    {
      sprintf(globBuf, (&dword_524F28)[4 * i]);
      v4 = 3;
      v5 = i + 74;
      v6 = (int)globBuf;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    }
  }
  for ( i = 0; *(_BYTE *)(v2 + 707) > i; ++i )
  {
    if ( *(_BYTE *)(i + v2 + 1119) == 10 )
    {
      sprintf(globBuf, byte_5113C4);
    }
    else
    {
      if ( strlen(&dword_5235E0[21 * *(_BYTE *)(i + v2 + 1119)]) )
        sprintf(globBuf, &dword_5235E0[21 * *(_BYTE *)(i + v2 + 1119)]);
      else
        sprintf(globBuf, "Player %d", *(_BYTE *)(i + v2 + 1119) + 1);
    }
    v4 = 3;
    v5 = i + 24;
    v6 = (int)globBuf;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    if ( *(_BYTE *)(v2 + 1145) == i )
      v4 = 5;
    else
      v4 = 6;
    v5 = i + 18;
    v6 = 4;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    v8 = !*(_BYTE *)(i + v2 + 1139) && (dword_5235D4 <= 1 || *(_BYTE *)(i + v2 + 1119) == 10);
    v4 = 4;
    v5 = i + 12;
    if ( *(_BYTE *)(i + v2 + 1119) == 10 )
      v6 = ((unsigned int)v8 < 1 ? 3 : 15) + *(_BYTE *)(i + v2 + 1101);
    else
      v6 = ((unsigned int)v8 < 1 ? 9 : 21) + *(_BYTE *)(i + v2 + 1101);
    if ( dword_5235D4 > 1 )
      v6 += 24;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    if ( v8 )
      v4 = 6;
    else
      v4 = 5;
    v6 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    v4 = 4;
    v5 = i + 48;
    if ( *(_BYTE *)(i + v2 + 1119) == 10 )
      v6 = 78;
    else
      v6 = *(_BYTE *)(i + v2 + 1107);
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    if ( *(_BYTE *)(i + v2 + 1119) == 10 )
      v4 = 6;
    else
      v4 = 5;
    v6 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    v8 = *(_BYTE *)(*(_BYTE *)(i + v2 + 1101) + v2 + 719) != 7;
    v4 = 5;
    v6 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    v4 = 4;
    v5 = i + 36;
    v6 = ((unsigned int)v8 < 1 ? 51 : 70) + *(_BYTE *)(i + v2 + 1113);
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    sprintf(globBuf, (&off_4F5AF8)[4 * *(_BYTE *)(i + v2 + 1113)]);
    v4 = 3;
    v5 = i + 78;
    v6 = (int)globBuf;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
    if ( v8 )
      v4 = 6;
    else
      v4 = 5;
    v6 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
  }
  v1 = sub_42C980(v2);
  gameObject->field_0 = v1;
  v4 = 3;
  v5 = 66;
  sprintf(globBuf, "%s %d%%", "Rating", gameObject->field_0);
  v6 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 25496), (Event *)&evt);
  sub_45DBA0(0);
}
