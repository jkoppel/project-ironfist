{
  int result; // eax@15
  int v2; // [sp+Ch] [bp-1F0h]@1
  int evt; // [sp+10h] [bp-1ECh]@6
  int v4; // [sp+14h] [bp-1E8h]@6
  int v5; // [sp+18h] [bp-1E4h]@6
  int v6; // [sp+28h] [bp-1D4h]@7
  char v7; // [sp+2Ch] [bp-1D0h]@2
  int v8; // [sp+18Ch] [bp-70h]@1
  int fd; // [sp+190h] [bp-6Ch]@4
  int i; // [sp+194h] [bp-68h]@15
  char buf; // [sp+198h] [bp-64h]@19
  char v12; // [sp+1A9h] [bp-53h]@33
  int v13; // [sp+1D2h] [bp-2Ah]@18
  int v14; // [sp+1D6h] [bp-26h]@36
  char v15; // [sp+1DEh] [bp-1Eh]@30

  v2 = this;
  v8 = 0;
  if ( *(_BYTE *)(this + 94) )
    sprintf(&v7, "%sCAMPAIGN.HS", ".\\DATA\\");
  else
    sprintf(&v7, "%sSTANDARD.HS", ".\\DATA\\");
  fd = _open(&v7, 32768);
  if ( fd == -1 )
    v8 = 1;
  sprintf(globBuf, "hsbkg.icn");
  ResourceManager::dumpImageToScreen(resourceManager, globBuf, HeroWindowManager::instance->screenBuffer, 1);
  evt = 512;
  v5 = 102;
  v4 = 4;
  if ( *(_BYTE *)(v2 + 94) )
    v6 = 7;
  else
    v6 = 6;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
  if ( *(_BYTE *)(v2 + 94) )
    v5 = 147;
  else
    v5 = 100;
  v4 = 6;
  v6 = 6;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
  if ( *(_BYTE *)(v2 + 94) )
    v5 = 100;
  else
    v5 = 147;
  v4 = 5;
  v6 = 6;
  result = GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
  for ( i = 0; i < 10; ++i )
  {
    if ( v8 )
      v13 = -1;
    else
      _read(fd, &buf, 0x64u);
    if ( v13 == -1 )
    {
      *(_WORD *)(v2 + 2 * i + 74) = 0;
      sprintf(globBuf, byte_4EDB4C);
    }
    else
    {
      *(_WORD *)(v2 + 2 * i + 74) = sub_4357C0(v13, (unsigned int)*(_BYTE *)(v2 + 94) < 1);
    }
    if ( v13 == -1 )
      v4 = 6;
    else
      v4 = 5;
    v5 = i + 201;
    v6 = 6;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    v5 = i + 221;
    v6 = 6;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    if ( v13 != -1 )
    {
      *(_WORD *)(v2 + 2 * i + 54) = (*(_WORD *)(v2 + 2 * i + 54) + 1) % 18;
      v5 = i + 201;
      v4 = 4;
      v6 = 9 * *(_WORD *)(v2 + 2 * i + 74) + (unsigned __int8)byte_50F100[*(_WORD *)(v2 + 2 * i + 54)] + 1;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
      v5 = i + 221;
      v4 = 4;
      v6 = 9 * *(_WORD *)(v2 + 2 * i + 74);
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    }
    v4 = 3;
    v6 = (int)globBuf;
    sprintf(globBuf, byte_4EDB50);
    v5 = 4 * i + 106;
    if ( v13 != -1 )
      sprintf(globBuf, &buf);
    if ( v15 )
      strcat(globBuf, "\n(Cheater)");
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    sprintf(globBuf, byte_4EDB60);
    v5 = 4 * i + 107;
    if ( v13 != -1 )
      sprintf(globBuf, &v12);
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    sprintf(globBuf, byte_4EDB64);
    v5 = 4 * i + 108;
    if ( v13 != -1 )
    {
      if ( *(_BYTE *)(v2 + 94) )
        sprintf(globBuf, "%d", v13);
      else
        sprintf(globBuf, "%d", v14);
    }
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    sprintf(globBuf, byte_4EDB70);
    v5 = 4 * i + 109;
    sprintf(globBuf, byte_4EDB74);
    if ( !*(_BYTE *)(v2 + 94) && v13 != -1 )
      sprintf(globBuf, "%d", v13);
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    v4 = 52;
    v5 = 4 * i + 107;
    if ( *(_BYTE *)(v2 + 94) )
      v6 = 295;
    else
      v6 = 241;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    v5 = 4 * i + 108;
    if ( *(_BYTE *)(v2 + 94) )
      v6 = 467;
    else
      v6 = 400;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    result = dword_4F749C;
    if ( i == dword_4F749C )
    {
      if ( (!*(_BYTE *)(v2 + 94) || dword_4F74A0 == 1) && (*(_BYTE *)(v2 + 94) || dword_4F74A0 != 1) )
      {
        v4 = 8;
        v6 = 1;
      }
      else
      {
        v4 = 8;
        v6 = 2;
      }
      v5 = 4 * i + 106;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
      v5 = 4 * i + 107;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
      v5 = 4 * i + 108;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
      v5 = 4 * i + 109;
      result = GUIWindow::processMessage(*(GUIWindow **)(v2 + 95), (Event *)&evt);
    }
  }
  if ( !v8 )
    result = _close(fd);
  return result;
}
