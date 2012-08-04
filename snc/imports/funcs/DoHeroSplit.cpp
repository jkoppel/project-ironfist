{
  void *result; // eax@6
  int v3; // [sp+Ch] [bp-38h]@1
  int v4; // [sp+10h] [bp-34h]@1
  heroWindow *this; // [sp+1Ch] [bp-28h]@1
  int evt; // [sp+20h] [bp-24h]@6
  int v7; // [sp+24h] [bp-20h]@6
  int v8; // [sp+28h] [bp-1Ch]@6
  char *v9; // [sp+38h] [bp-Ch]@6
  __int16 v10; // [sp+3Ch] [bp-8h]@1
  __int16 v11; // [sp+40h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  v11 = 1;
  v10 = 68;
  this = (heroWindow *)operator new(68);
  if ( this )
    *(_DWORD *)&gpTownManager->_3[0] = heroWindow::heroWindow(this, 177, 20, "splitwin.bin");
  else
    *(_DWORD *)&gpTownManager->_3[0] = 0;
  if ( !*(_DWORD *)&gpTownManager->_3[0] )
    MemError();
  *(_DWORD *)&gpTownManager->_3[4] = 0;
  *(_DWORD *)&gpTownManager->_3[8] = gpHVHero->army.quantities[v3];
  evt = 512;
  sprintf(gText, "Move how many troops?");
  v7 = 3;
  v8 = 1;
  v9 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)&gpTownManager->_3[0], (Event *)&evt);
  sprintf(gText, "%d", *(_DWORD *)&gpTownManager->_3[4]);
  v8 = 68;
  v9 = gText;
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
    result = gpTownManager;
    if ( *(_DWORD *)&gpTownManager->_3[4] )
    {
      if ( gpHVHero->army.creatureTypes[v3] == gpHVHero->army.creatureTypes[v4] )
      {
        gpHVHero->army.quantities[v3] -= *(_WORD *)&gpTownManager->_3[4];
        gpHVHero->army.quantities[v4] += *(_WORD *)&gpTownManager->_3[4];
        result = (void *)gpHVHero->army.quantities[v3];
        if ( !gpHVHero->army.quantities[v3] )
        {
          result = (void *)v3;
          gpHVHero->army.creatureTypes[v3] = -1;
        }
      }
      else
      {
        gpHVHero->army.quantities[v3] -= *(_WORD *)&gpTownManager->_3[4];
        gpHVHero->army.quantities[v4] = *(_DWORD *)&gpTownManager->_3[4];
        gpHVHero->army.creatureTypes[v4] = gpHVHero->army.creatureTypes[v3];
        result = (void *)gpHVHero->army.quantities[v3];
        if ( !gpHVHero->army.quantities[v3] )
        {
          result = (void *)v3;
          gpHVHero->army.creatureTypes[v3] = -1;
        }
      }
    }
  }
  return result;
}