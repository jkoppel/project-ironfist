{
  int v2; // eax@20
  int v3; // eax@32
  int v4; // eax@41
  int v6; // [sp+Ch] [bp-44h]@1
  const char *filename; // [sp+10h] [bp-40h]@4
  iconWidget *v8; // [sp+14h] [bp-3Ch]@10
  heroWindow *thisa; // [sp+18h] [bp-38h]@1
  char a2a[12]; // [sp+1Ch] [bp-34h]@25
  int evt; // [sp+28h] [bp-28h]@15
  int v12; // [sp+2Ch] [bp-24h]@15
  int v13; // [sp+30h] [bp-20h]@18
  int v14; // [sp+40h] [bp-10h]@18
  int i; // [sp+44h] [bp-Ch]@18
  int v16; // [sp+48h] [bp-8h]@16
  unsigned __int8 v17; // [sp+4Ch] [bp-4h]@16

  v6 = (int)this;
  strcpy(gLastFilename, byte_4EDEC4);
  *(_DWORD *)(v6 + 682) = hmnuCurrent;
  KBChangeMenu(hmnuDflt);
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
  {
    if ( *(_DWORD *)(v6 + 66) != 1 && *(_DWORD *)(v6 + 66) != 4 )
      filename = "request.bin";
    else
      filename = "requests.bin";
    *(_DWORD *)(v6 + 54) = heroWindow::heroWindow(thisa, *(_DWORD *)(v6 + 58), *(_DWORD *)(v6 + 62), filename);
  }
  else
  {
    *(_DWORD *)(v6 + 54) = 0;
  }
  if ( !*(_DWORD *)(v6 + 54) )
    MemError();
  v8 = (iconWidget *)operator new(45);
  if ( v8 )
    *(_DWORD *)(v6 + 1067) = iconWidget::iconWidget(
                               v8,
                               346,
                               (signed __int64)*(float *)&fGutterTravelLength,
                               8,
                               17,
                               "scrollcn.icn",
                               4,
                               0,
                               14,
                               16,
                               1);
  else
    *(_DWORD *)(v6 + 1067) = 0;
  if ( !*(_DWORD *)(v6 + 1067) )
    MemError();
  heroWindow::AddWidget(*(heroWindow **)(v6 + 54), *(widget **)(v6 + 1067), -1);
  evt = 512;
  v12 = 3;
  if ( *(_DWORD *)(v6 + 66) == 3 )
  {
    v17 = 1;
    strcpy((char *)(v6 + 691), &gpGame->_1[325]);
    v16 = FindLastToken((const char *)(v6 + 691), 46);
    if ( v16 )
      *(_BYTE *)v16 = 0;
    v13 = 15;
    v14 = v6 + 691;
    heroWindow::BroadcastMessage(*(heroWindow **)(v6 + 54), (Event *)&evt);
    v13 = 16;
    sprintf(gText, "File to Save:");
    v14 = (int)gText;
    heroWindow::BroadcastMessage(*(heroWindow **)(v6 + 54), (Event *)&evt);
    for ( i = 0; *(_DWORD *)(v6 + 1042) > i; ++i )
    {
      LOBYTE(v2) = stricmp((char *)(351 * i + *(_DWORD *)(v6 + 670)), (char *)(v6 + 691));
      if ( !v2 )
        *(_DWORD *)(v6 + 1050) = i;
    }
  }
  else
  {
    v17 = 0;
    if ( *(_DWORD *)(v6 + 66) == 1 )
    {
      i = 0;
      memset(a2a, 0, 9u);
      while ( i < 8 && gMapName[i] && gMapName[i] != 46 )
      {
        a2a[i] = gMapName[i];
        ++i;
      }
      for ( i = 0; *(_DWORD *)(v6 + 1042) > i; ++i )
      {
        LOBYTE(v3) = stricmp((char *)(351 * i + *(_DWORD *)(v6 + 670)), a2a);
        if ( !v3 )
        {
          *(_DWORD *)(v6 + 1050) = i;
          v17 = 1;
        }
      }
    }
    v13 = 16;
    sprintf(gText, "File to Load:");
    v14 = (int)gText;
    heroWindow::BroadcastMessage(*(heroWindow **)(v6 + 54), (Event *)&evt);
  }
  evt = 512;
  v12 = 51;
  v13 = 15;
  v14 = 201;
  heroWindow::BroadcastMessage(*(heroWindow **)(v6 + 54), (Event *)&evt);
  fileRequester::Update(v6, 0);
  if ( *(_DWORD *)(v6 + 1050) != -1 )
    v17 = 1;
  heroWindowManager::AddWindow(gpWindowManager, *(heroWindow **)(v6 + 54), -1, 1);
  if ( !*(_DWORD *)(v6 + 1042) )
    v17 = 0;
  if ( *(_DWORD *)(v6 + 66) == 3 )
  {
    LOBYTE(v4) = stricmp((char *)(v6 + 691), "NEWGAME");
    if ( !v4 )
    {
      if ( *(_DWORD *)(v6 + 1050) == -1 )
        v17 = 1;
    }
  }
  fileRequester::SetOK(v6, v17);
  *(_DWORD *)(v6 + 12) = 16384;
  *(_DWORD *)(v6 + 16) = a2;
  *(_DWORD *)(v6 + 50) = 1;
  strcpy((char *)(v6 + 20), "fileRequester");
  return 0;
}