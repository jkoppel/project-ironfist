signed int __cdecl sub_4BA820()
{
  int v1; // [sp+Ch] [bp-34h]@8
  GUIWindow *this; // [sp+1Ch] [bp-24h]@1
  int evt; // [sp+20h] [bp-20h]@7
  int v4; // [sp+24h] [bp-1Ch]@7
  int v5; // [sp+28h] [bp-18h]@7
  int v6; // [sp+38h] [bp-8h]@7
  int window; // [sp+3Ch] [bp-4h]@2

  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    window = (int)GUIWindow_constructorFromFile(this, 405, 8, "stpnet.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  if ( dword_4F1CBC )
  {
    evt = 512;
    v4 = 5;
    v5 = 1;
    v6 = 4096;
    GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
  }
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_4BC0F0,
    0);
  operator delete((void *)window);
  v1 = HeroWindowManager::instance->buttonPressedCode;
  switch ( v1 )
  {
    case 1:
      dword_523ED8 = 1;
      break;
    case 2:
      dword_523ED8 = 2;
      break;
    case 30721:
      return 0;
  }
  return 1;
}
