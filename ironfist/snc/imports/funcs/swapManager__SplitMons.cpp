{
  heroWindowManager *result; // eax@9
  int v2; // [sp+Ch] [bp-44h]@1
  heroWindow *thisa; // [sp+18h] [bp-38h]@1
  int evt; // [sp+20h] [bp-30h]@6
  int v5; // [sp+24h] [bp-2Ch]@9
  int v6; // [sp+28h] [bp-28h]@9
  char *v7; // [sp+38h] [bp-18h]@9
  __int16 v8; // [sp+3Ch] [bp-14h]@1
  int v9; // [sp+40h] [bp-10h]@1
  int i; // [sp+44h] [bp-Ch]@15
  __int16 v11; // [sp+48h] [bp-8h]@1
  int v12; // [sp+4Ch] [bp-4h]@1

  v2 = this;
  v8 = 68;
  v9 = *(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101;
  v12 = *(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + 101;
  v11 = 1;
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    *(_DWORD *)&gpTownManager->_3[0] = heroWindow::heroWindow(thisa, 177, 20, "splitwin.bin");
  else
    *(_DWORD *)&gpTownManager->_3[0] = 0;
  if ( !*(_DWORD *)&gpTownManager->_3[0] )
    MemError();
  *(_DWORD *)&gpTownManager->_3[4] = 0;
  *(_DWORD *)&gpTownManager->_3[8] = *(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5);
  evt = 512;
  if ( *(_DWORD *)(v2 + 70) == *(_DWORD *)(v2 + 74) )
    sprintf(gText, "Move how many troops?");
  else
    sprintf(
      gText,
      "Move how many %s troops from %s to %s?",
      gArmyNames[*(_BYTE *)(*(_DWORD *)(v2 + 78) + v9)],
      *(_DWORD *)(v2 + 4 * *(_DWORD *)(v2 + 70) + 62) + 10,
      *(_DWORD *)(v2 + 4 * *(_DWORD *)(v2 + 74) + 62) + 10);
  v5 = 3;
  v6 = 1;
  v7 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)&gpTownManager->_3[0], (Event *)&evt);
  sprintf(gText, "%d", *(_DWORD *)&gpTownManager->_3[4]);
  v6 = 68;
  v7 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)&gpTownManager->_3[0], (Event *)&evt);
  heroWindowManager::DoDialog(
    gpWindowManager,
    *(heroWindow **)&gpTownManager->_3[0],
    (int (__fastcall *)(tag_message *))SplitArmyHandler,
    0);
  operator delete(*(void **)&gpTownManager->_3[0]);
  result = gpWindowManager;
  if ( gpWindowManager->buttonPressedCode == 30722 )
  {
    if ( *(_BYTE *)(*(_DWORD *)(v2 + 78) + v9) == *(_BYTE *)(*(_DWORD *)(v2 + 82) + v12) )
    {
      *(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5) -= *(_WORD *)&gpTownManager->_3[4];
      *(_WORD *)(v12 + 2 * *(_DWORD *)(v2 + 82) + 5) += *(_WORD *)&gpTownManager->_3[4];
      result = (heroWindowManager *)*(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5);
      if ( !*(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5) )
      {
        result = *(heroWindowManager **)(v2 + 78);
        *((_BYTE *)&result->vtable + v9) = -1;
      }
    }
    else
    {
      if ( *(_BYTE *)(*(_DWORD *)(v2 + 82) + v12) != -1 )
      {
        for ( i = 0; i < 5 && *(_BYTE *)(i + v12) != -1; ++i )
          ;
        if ( i < 5 )
          *(_DWORD *)(v2 + 82) = i;
      }
      *(_BYTE *)(*(_DWORD *)(v2 + 82) + v12) = *(_BYTE *)(*(_DWORD *)(v2 + 78) + v9);
      *(_WORD *)(v12 + 2 * *(_DWORD *)(v2 + 82) + 5) = *(_DWORD *)&gpTownManager->_3[4];
      *(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5) -= *(_WORD *)&gpTownManager->_3[4];
      result = (heroWindowManager *)*(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5);
      if ( !*(_WORD *)(v9 + 2 * *(_DWORD *)(v2 + 78) + 5) )
      {
        result = *(heroWindowManager **)(v2 + 78);
        *((_BYTE *)&result->vtable + v9) = -1;
      }
    }
  }
  return result;
}