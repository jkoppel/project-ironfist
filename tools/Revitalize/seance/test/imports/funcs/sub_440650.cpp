{
  int v2; // [sp+1Ch] [bp-44h]@1
  GUIWindow *thisa; // [sp+2Ch] [bp-34h]@11
  int evt; // [sp+34h] [bp-2Ch]@16
  int v5; // [sp+38h] [bp-28h]@16
  int v6; // [sp+3Ch] [bp-24h]@16
  char *v7; // [sp+4Ch] [bp-14h]@16
  int i; // [sp+50h] [bp-10h]@1
  __int16 v9; // [sp+54h] [bp-Ch]@11
  __int16 v10; // [sp+58h] [bp-8h]@11
  int window; // [sp+5Ch] [bp-4h]@12

  v2 = this;
  dword_524CA0 = 0;
  for ( i = 0; i < 20; ++i )
  {
    if ( *(_DWORD *)(1154 * i + 24234 * *(_DWORD *)(this + 62127) + this + 13765) >= 0 )
    {
      if ( *(_DWORD *)(1154 * i + 24234 * *(_DWORD *)(this + 62127) + this + 13797) > 0 )
        dword_524CA0 += *(_DWORD *)(1154 * i + 24234 * *(_DWORD *)(this + 62127) + this + 13797)
                      * creature_table[*(_DWORD *)(1154 * i + 24234 * *(_DWORD *)(this + 62127) + this + 13765)].cost;
    }
  }
  if ( Hero::hasArtifact(*(Hero **)(this + 4 * *(_DWORD *)(this + 62127) + 12935), ARTIFACT_STATESMANS_QUILL) )
    dword_524CA0 = (signed __int64)((double)dword_524CA0 * 0.1);
  else
    dword_524CA0 = (signed __int64)((double)dword_524CA0 * 0.5);
  dword_524CA0 = (signed __int64)((1.0
                                 - (double)*(_BYTE *)(*(_DWORD *)(v2 + 4 * *(_DWORD *)(v2 + 62127) + 12935) + 120) * 0.2)
                                * (double)dword_524CA0);
  v9 = 1;
  v10 = 30;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    window = (int)GUIWindow_constructorFromFile(thisa, 74, 80, "surrendr.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  evt = 512;
  v5 = 9;
  v6 = 1;
  sprintf(globBuf, "port%04d.icn", *(_BYTE *)(*(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 12935) + 24));
  v7 = globBuf;
  GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  if ( *(_BYTE *)(*(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 12935) + 231) )
    v5 = 5;
  else
    v5 = 6;
  v6 = 30;
  v7 = (char *)4;
  GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  if ( *(_BYTE *)(*(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 12935) + 231) )
  {
    v5 = 4;
    if ( *(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 13615) == -1 )
      v7 = (char *)6;
    else
      v7 = (char *)gameObject->players[*(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 13615)].color;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  v7 = globBuf;
  v5 = 3;
  v6 = 2;
  sprintf(
    globBuf,
    "%s states:\n\n\"I will accept your surrender and grant you and your troops safe passage for the price of %d gold.\"",
    *(_DWORD *)(v2 + 4 * (1 - *(_DWORD *)(v2 + 62127)) + 12935) + 10,
    dword_524CA0);
  GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  HeroWindowManager::displayWindow(HeroWindowManager::instance, (GUIWindow *)window, sub_432E90, 0);
  operator delete((void *)window);
  return HeroWindowManager::instance->buttonPressedCode == 30722;
}
