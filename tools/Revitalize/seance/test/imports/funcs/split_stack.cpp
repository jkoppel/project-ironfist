{
  void *result; // eax@6
  int v3; // [sp+Ch] [bp-38h]@1
  int v4; // [sp+10h] [bp-34h]@1
  GUIWindow *this; // [sp+1Ch] [bp-28h]@1
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
  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    *(_DWORD *)&townManager->_3[0] = GUIWindow_constructorFromFile(this, 177, 20, "splitwin.bin");
  else
    *(_DWORD *)&townManager->_3[0] = 0;
  if ( !*(_DWORD *)&townManager->_3[0] )
    fatalOutOfMemoryError();
  *(_DWORD *)&townManager->_3[4] = 0;
  *(_DWORD *)&townManager->_3[8] = viewedHero->army.quantities[v3];
  evt = 512;
  sprintf(globBuf, "Move how many troops?");
  v7 = 3;
  v8 = 1;
  v9 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)&townManager->_3[0], (Event *)&evt);
  sprintf(globBuf, "%d", *(_DWORD *)&townManager->_3[4]);
  v8 = 68;
  v9 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)&townManager->_3[0], (Event *)&evt);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    *(GUIWindow **)&townManager->_3[0],
    (int (__fastcall *)(InputEvent *))sub_416BC0,
    0);
  operator delete(*(void **)&townManager->_3[0]);
  result = HeroWindowManager::instance;
  if ( HeroWindowManager::instance->buttonPressedCode == 30722 )
  {
    result = townManager;
    if ( *(_DWORD *)&townManager->_3[4] )
    {
      if ( viewedHero->army.creatureTypes[v3] == viewedHero->army.creatureTypes[v4] )
      {
        viewedHero->army.quantities[v3] -= *(_WORD *)&townManager->_3[4];
        viewedHero->army.quantities[v4] += *(_WORD *)&townManager->_3[4];
        result = (void *)viewedHero->army.quantities[v3];
        if ( !viewedHero->army.quantities[v3] )
        {
          result = (void *)v3;
          viewedHero->army.creatureTypes[v3] = -1;
        }
      }
      else
      {
        viewedHero->army.quantities[v3] -= *(_WORD *)&townManager->_3[4];
        viewedHero->army.quantities[v4] = *(_DWORD *)&townManager->_3[4];
        viewedHero->army.creatureTypes[v4] = viewedHero->army.creatureTypes[v3];
        result = (void *)viewedHero->army.quantities[v3];
        if ( !viewedHero->army.quantities[v3] )
        {
          result = (void *)v3;
          viewedHero->army.creatureTypes[v3] = -1;
        }
      }
    }
  }
  return result;
}
