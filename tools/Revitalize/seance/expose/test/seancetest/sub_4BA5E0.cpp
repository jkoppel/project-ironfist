signed int __cdecl sub_4BA5E0()
{
  signed int v1; // [sp+Ch] [bp-34h]@6
  GUIWindow *this; // [sp+1Ch] [bp-24h]@1
  char v3; // [sp+20h] [bp-20h]@23
  int window; // [sp+38h] [bp-8h]@2
  int i; // [sp+3Ch] [bp-4h]@16

  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    window = (int)GUIWindow_constructorFromFile(this, 405, 8, "stphotst.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)window,
    (int (__fastcall *)(InputEvent *))sub_4BBD90,
    0);
  operator delete((void *)window);
  v1 = HeroWindowManager::instance->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        dword_5235D4 = 2;
        break;
      case 2:
        dword_5235D4 = 3;
        break;
      case 3:
        dword_5235D4 = 4;
        break;
      case 4:
        dword_5235D4 = 5;
        break;
      case 5:
        dword_5235D4 = 6;
        break;
      default:
        break;
    }
  }
  for ( i = 0; i < 6; ++i )
    strcpy(&dword_5235E0[21 * i], byte_51DA2C);
  if ( !byte_523004 )
  {
    sprintf(globBuf, "Do you wish to enter each player's name?");
    display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      for ( i = 0; i < dword_5235D4; ++i )
      {
        strcpy(&v3, byte_51DA5C);
        sprintf(globBuf, "Enter player %d's name.", i + 1);
        sub_4CAEF0(globBuf, (int)&dword_5235E0[21 * i], 20, &v3, 0, 1);
      }
    }
  }
  return 1;
}
