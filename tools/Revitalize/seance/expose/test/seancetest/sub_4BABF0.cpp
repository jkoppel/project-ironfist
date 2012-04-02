signed int __cdecl sub_4BABF0()
{
  signed int v1; // [sp+Ch] [bp-40h]@23
  GUIWindow *v2; // [sp+1Ch] [bp-30h]@16
  GUIWindow *v3; // [sp+20h] [bp-2Ch]@12
  GUIWindow *v4; // [sp+24h] [bp-28h]@7
  GUIWindow *this; // [sp+28h] [bp-24h]@3
  int evt; // [sp+2Ch] [bp-20h]@22
  int v7; // [sp+30h] [bp-1Ch]@22
  int v8; // [sp+34h] [bp-18h]@22
  int v9; // [sp+44h] [bp-8h]@22
  int window; // [sp+48h] [bp-4h]@4

  debugLog("SMC 1");
  if ( dword_4F7478 )
  {
    if ( *((_DWORD *)&modemComPort + dword_4F7478) )
    {
      v4 = (GUIWindow *)operator new(0x44u);
      if ( v4 )
        window = (int)GUIWindow_constructorFromFile(v4, 405, 8, "stpdccfg.bin");
      else
        window = 0;
    }
    else
    {
      this = (GUIWindow *)operator new(0x44u);
      if ( this )
        window = (int)GUIWindow_constructorFromFile(this, 405, 8, "stpdc.bin");
      else
        window = 0;
    }
  }
  else
  {
    if ( *((_DWORD *)&modemComPort + dword_4F7478) )
    {
      v2 = (GUIWindow *)operator new(0x44u);
      if ( v2 )
        window = (int)GUIWindow_constructorFromFile(v2, 405, 8, "stpmcfg.bin");
      else
        window = 0;
    }
    else
    {
      v3 = (GUIWindow *)operator new(0x44u);
      if ( v3 )
        window = (int)GUIWindow_constructorFromFile(v3, 405, 8, "stpmodem.bin");
      else
        window = 0;
    }
  }
  if ( !window )
    fatalOutOfMemoryError();
  debugLog("SMC 2");
  if ( dword_4F1CBC )
  {
    evt = 512;
    v7 = 5;
    v8 = 1;
    v9 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  debugLog("SMC 3");
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_4BBEB0,
    0);
  debugLog("SMC 4");
  operator delete((void *)window);
  debugLog("SMC 5");
  v1 = HeroWindowManager::instance->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        debugLog("SMC 6");
        dword_523ED8 = 3;
        if ( !*((_DWORD *)&modemComPort + dword_4F7478) )
        {
          debugLog("SMC 7");
          if ( !sub_4BA3E0() )
            return 0;
          debugLog("SMC 8");
        }
        debugLog("SMC 9");
        if ( !dword_4F7478 )
          sub_4CAEF0("Please enter the telephone number.", (int)&unk_525240, 35, 0, 0, 1);
        debugLog("SMC a");
        break;
      case 2:
        dword_523ED8 = 4;
        if ( !*((_DWORD *)&modemComPort + dword_4F7478) && !sub_4BA3E0() )
          return 0;
        break;
      case 3:
        dword_51D960 = 1;
        break;
    }
  }
  return 1;
}
