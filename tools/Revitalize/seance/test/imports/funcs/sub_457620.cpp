{
  signed int result; // eax@15
  int thisa; // [sp+10h] [bp-38h]@1
  GUIWindow *thisb; // [sp+1Ch] [bp-2Ch]@1
  int v4; // [sp+20h] [bp-28h]@1
  int evt; // [sp+24h] [bp-24h]@7
  int v6; // [sp+28h] [bp-20h]@7
  int v7; // [sp+2Ch] [bp-1Ch]@7
  int v8; // [sp+3Ch] [bp-Ch]@7
  int window; // [sp+40h] [bp-8h]@2
  int v10; // [sp+44h] [bp-4h]@1

  thisa = (int)this;
  sub_456000(this, 4);
  v10 = -1;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  v4 = *(_DWORD *)(thisa + 678);
  sub_450880((AdvManager *)thisa);
  thisb = (GUIWindow *)operator new(0x44u);
  if ( thisb )
    window = (int)GUIWindow_constructorFromFile(thisb, 144, 40, "cpanel.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  if ( dword_4F7494 )
  {
    evt = 512;
    v7 = 101;
    v6 = 5;
    v8 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
    v6 = 6;
    v8 = 2;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
    v7 = 102;
    v6 = 5;
    v8 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
    v6 = 6;
    v8 = 2;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_457810,
    0);
  operator delete((void *)window);
  switch ( HeroWindowManager::instance->buttonPressedCode )
  {
    case 0x65:
    case 0x66:
    case 0x69:
      v10 = HeroWindowManager::instance->buttonPressedCode;
      break;
    case 0x6A:
      sub_451750();
      break;
    default:
      break;
  }
  if ( v4 )
    sub_450820(thisa, 0);
  if ( v10 == -1 )
  {
    result = 0;
  }
  else
  {
    dword_523408 = v10;
    result = 1;
  }
  return result;
}
