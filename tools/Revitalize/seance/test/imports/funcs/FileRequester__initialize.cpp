{
  int v3; // [sp+Ch] [bp-44h]@1
  const char *filename; // [sp+10h] [bp-40h]@4
  GUIIcon *v5; // [sp+14h] [bp-3Ch]@10
  GUIWindow *thisa; // [sp+18h] [bp-38h]@1
  char v7[12]; // [sp+1Ch] [bp-34h]@25
  int evt; // [sp+28h] [bp-28h]@15
  int v9; // [sp+2Ch] [bp-24h]@15
  int v10; // [sp+30h] [bp-20h]@18
  int v11; // [sp+40h] [bp-10h]@18
  int i; // [sp+44h] [bp-Ch]@18
  int v13; // [sp+48h] [bp-8h]@16
  unsigned __int8 v14; // [sp+4Ch] [bp-4h]@16

  v3 = (int)this;
  strcpy(byte_5240B0, byte_4EDEC4);
  *(_DWORD *)(v3 + 682) = globalMenu1;
  changeMenu(dfltMenu);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
  {
    if ( *(_DWORD *)(v3 + 66) != 1 && *(_DWORD *)(v3 + 66) != 4 )
      filename = "request.bin";
    else
      filename = "requests.bin";
    *(_DWORD *)(v3 + 54) = GUIWindow_constructorFromFile(thisa, *(_DWORD *)(v3 + 58), *(_DWORD *)(v3 + 62), filename);
  }
  else
  {
    *(_DWORD *)(v3 + 54) = 0;
  }
  if ( !*(_DWORD *)(v3 + 54) )
    fatalOutOfMemoryError();
  v5 = (GUIIcon *)operator new(0x2Du);
  if ( v5 )
    *(_DWORD *)(v3 + 1067) = GUIIcon_constructor(
                               v5,
                               346,
                               (signed __int64)*(float *)&dword_522BEC,
                               8,
                               17,
                               "scrollcn.icn",
                               4,
                               0,
                               14,
                               16,
                               1);
  else
    *(_DWORD *)(v3 + 1067) = 0;
  if ( !*(_DWORD *)(v3 + 1067) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(*(GUIWindow **)(v3 + 54), *(AbstractGUIComponent **)(v3 + 1067), -1);
  evt = 512;
  v9 = 3;
  if ( *(_DWORD *)(v3 + 66) == 3 )
  {
    v14 = 1;
    strcpy((char *)(v3 + 691), &gameObject->_1[325]);
    v13 = sub_4C91C0((const char *)(v3 + 691), 46);
    if ( v13 )
      *(_BYTE *)v13 = 0;
    v10 = 15;
    v11 = v3 + 691;
    GUIWindow::processMessage(*(GUIWindow **)(v3 + 54), (Event *)&evt);
    v10 = 16;
    sprintf(globBuf, "File to Save:");
    v11 = (int)globBuf;
    GUIWindow::processMessage(*(GUIWindow **)(v3 + 54), (Event *)&evt);
    for ( i = 0; *(_DWORD *)(v3 + 1042) > i; ++i )
    {
      if ( !_strcmpi((const char *)(351 * i + *(_DWORD *)(v3 + 670)), (const char *)(v3 + 691)) )
        *(_DWORD *)(v3 + 1050) = i;
    }
  }
  else
  {
    v14 = 0;
    if ( *(_DWORD *)(v3 + 66) == 1 )
    {
      i = 0;
      memset(v7, 0, 9u);
      while ( i < 8 && byte_524740[i] && byte_524740[i] != 46 )
      {
        v7[i] = byte_524740[i];
        ++i;
      }
      for ( i = 0; *(_DWORD *)(v3 + 1042) > i; ++i )
      {
        if ( !_strcmpi((const char *)(351 * i + *(_DWORD *)(v3 + 670)), v7) )
        {
          *(_DWORD *)(v3 + 1050) = i;
          v14 = 1;
        }
      }
    }
    v10 = 16;
    sprintf(globBuf, "File to Load:");
    v11 = (int)globBuf;
    GUIWindow::processMessage(*(GUIWindow **)(v3 + 54), (Event *)&evt);
  }
  evt = 512;
  v9 = 51;
  v10 = 15;
  v11 = 201;
  GUIWindow::processMessage(*(GUIWindow **)(v3 + 54), (Event *)&evt);
  sub_40DA80(v3, 0);
  if ( *(_DWORD *)(v3 + 1050) != -1 )
    v14 = 1;
  HeroWindowManager::addWindow(HeroWindowManager::instance, *(GUIWindow **)(v3 + 54), -1, 1);
  if ( !*(_DWORD *)(v3 + 1042) )
    v14 = 0;
  if ( *(_DWORD *)(v3 + 66) == 3 && !_strcmpi((const char *)(v3 + 691), "NEWGAME") && *(_DWORD *)(v3 + 1050) == -1 )
    v14 = 1;
  sub_40C570(v3, v14);
  *(_DWORD *)(v3 + 12) = 16384;
  *(_DWORD *)(v3 + 16) = a2;
  *(_DWORD *)(v3 + 50) = 1;
  strcpy((char *)(v3 + 20), "fileRequester");
  return 0;
}
