signed int __cdecl sub_4BAF10()
{
  signed int v1; // [sp+Ch] [bp-38h]@8
  GUIWindow *this; // [sp+1Ch] [bp-28h]@1
  signed int v3; // [sp+20h] [bp-24h]@17
  int evt; // [sp+24h] [bp-20h]@7
  int v5; // [sp+28h] [bp-1Ch]@7
  int v6; // [sp+2Ch] [bp-18h]@7
  int v7; // [sp+3Ch] [bp-8h]@7
  int window; // [sp+40h] [bp-4h]@2

  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    window = (int)GUIWindow_constructorFromFile(this, 405, 8, "stpmp.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  if ( dword_4F1CBC )
  {
    evt = 512;
    v5 = 5;
    v6 = 1;
    v7 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_4BBFE0,
    0);
  operator delete((void *)window);
  dword_4F7478 = 0;
  v1 = HeroWindowManager::instance->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        dword_524778 = 2;
        if ( sub_4BA5E0() )
          return 1;
        return 0;
      case 2:
        dword_524778 = 1;
        if ( sub_4BA950() )
          return 1;
        return 0;
      case 4:
        dword_4F7478 = 1;
        break;
      case 3:
        dword_4F7478 = 0;
        break;
      default:
        return 1;
    }
    dword_524778 = 0;
    v3 = 1;
    debugLog("Common Modem 1");
    while ( v3 )
    {
      debugLog("Common Modem 2");
      if ( !sub_4BABF0() )
        return 0;
      debugLog("Common Modem 3");
      if ( dword_51D960 )
      {
        debugLog("Common Modem 4");
        dword_51D960 = 0;
        if ( !sub_4BA3E0() )
          return 0;
        debugLog("Common Modem 5");
      }
      else
      {
        v3 = 0;
      }
      debugLog("Common Modem 6");
    }
    debugLog("Common Modem 7");
  }
  return 1;
}
