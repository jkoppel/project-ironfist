{
  int thisa; // [sp+10h] [bp-34h]@1
  GUIWindow *thisb; // [sp+1Ch] [bp-28h]@1
  int v3; // [sp+20h] [bp-24h]@1
  int evt; // [sp+24h] [bp-20h]@7
  int v5; // [sp+28h] [bp-1Ch]@7
  int v6; // [sp+2Ch] [bp-18h]@7
  int v7; // [sp+3Ch] [bp-8h]@7
  int window; // [sp+40h] [bp-4h]@2

  thisa = (int)this;
  sub_456000(this, 4);
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  v3 = *(_DWORD *)(thisa + 678);
  sub_450880((AdvManager *)thisa);
  thisb = (GUIWindow *)operator new(0x44u);
  if ( thisb )
    window = (int)GUIWindow_constructorFromFile(thisb, 144, 40, "apanel.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  if ( curPlayer->_1[0] == -1 )
  {
    evt = 512;
    v6 = 4;
    v5 = 6;
    v7 = 2;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
    v6 = 4;
    v5 = 5;
    v7 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_457450,
    0);
  operator delete((void *)window);
  switch ( HeroWindowManager::instance->buttonPressedCode )
  {
    case 3:
      if ( loadOrNewGameSelected )
      {
        sub_452F60((void *)thisa, -1, -1, 1);
        sub_4A8140(gameObject, 1, 0);
        sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
        sub_4506B0((void *)thisa, 1, 0);
        SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(thisa + 166)]);
      }
      else
      {
        if ( byte_5304A0 )
        {
          sub_452F60((void *)thisa, -1, -1, 1);
          sub_470DF0((int)&unk_530450, 1, 0);
          sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
          sub_4506B0((void *)thisa, 1, 0);
          SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(thisa + 166)]);
        }
        else
        {
          sub_45DC50(gameObject);
        }
      }
      break;
    case 4:
      sub_4469E0((void *)thisa, -1i64);
      break;
    case 1:
      sub_498F20((void *)thisa, 53, 0, 0);
      break;
    case 2:
      sub_456C40((void *)thisa);
      break;
    default:
      break;
  }
  if ( v3 )
    sub_450820(thisa, 0);
}
