signed int __cdecl sub_4BA290()
{
  signed int v1; // [sp+Ch] [bp-18h]@6
  GUIWindow *this; // [sp+1Ch] [bp-8h]@1
  GUIWindow *window; // [sp+20h] [bp-4h]@2

  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    window = GUIWindow_constructorFromFile(this, 405, 8, "stpbaud.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  HeroWindowManager::displayWindow(HeroWindowManager::instance, window, (int (__fastcall *)(InputEvent *))sub_4BBC50, 0);
  operator delete(window);
  v1 = HeroWindowManager::instance->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        *((_DWORD *)&modemBaudRate + dword_4F7478) = 2400;
        break;
      case 2:
        *((_DWORD *)&modemBaudRate + dword_4F7478) = 9600;
        break;
      case 3:
        *((_DWORD *)&modemBaudRate + dword_4F7478) = 19200;
        break;
      case 4:
        *((_DWORD *)&modemBaudRate + dword_4F7478) = 38400;
        break;
      default:
        return 1;
    }
  }
  return 1;
}
