signed int __cdecl sub_4BB840()
{
  signed int result; // eax@2
  int v1; // [sp+Ch] [bp-40h]@15
  int v2; // [sp+28h] [bp-24h]@25
  GUIWindow *this; // [sp+30h] [bp-1Ch]@10
  GUIWindow *window; // [sp+34h] [bp-18h]@11
  char v5; // [sp+3Ch] [bp-10h]@4
  AbstractManager *a2; // [sp+48h] [bp-4h]@26

  if ( dword_523F08 )
    return 1;
  if ( loadOrNewGameSelected )
  {
    sprintf(&v5, "*.GMC");
  }
  else
  {
    if ( byte_5304A0 )
    {
      sprintf(&v5, "*.GXC");
    }
    else
    {
      if ( dword_4F7494 && byte_51AC64 )
      {
        display_message_window(
          "At least one player does not have the Heroes II Expansion set.  You will only be able to choose from original Heroes II games.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        sprintf(&v5, "*.GM%d", dword_5235D4);
      }
      else
      {
        this = (GUIWindow *)operator new(0x44u);
        if ( this )
          window = GUIWindow_constructorFromFile(this, 405, 8, "x_mapmnu.bin");
        else
          window = 0;
        if ( !window )
          fatalOutOfMemoryError();
        HeroWindowManager::displayWindow(
          HeroWindowManager::instance,
          window,
          (int (__fastcall *)(InputEvent *))sub_4BC5E0,
          0);
        operator delete(window);
        v1 = LOWORD(HeroWindowManager::instance->buttonPressedCode);
        switch ( v1 )
        {
          case 1:
            LOBYTE(inExpansion) = 0;
            break;
          case 2:
            LOBYTE(inExpansion) = 1;
            break;
          case 30721:
            return 0;
        }
        if ( inExpansion )
          sprintf(&v5, "*.GX%d", dword_5235D4);
        else
          sprintf(&v5, "*.GM%d", dword_5235D4);
      }
    }
  }
  v2 = (int)operator new(0x42Fu);
  if ( v2 )
    a2 = (AbstractManager *)FileRequester_constructor(v2, 200, 58, 2, &v5, ".\\GAMES\\", &v5);
  else
    a2 = 0;
  if ( !a2 )
    fatalOutOfMemoryError();
  if ( ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2) == 30722 )
  {
    sub_41B5F0(gameObject, byte_5240B0, 0, 0);
    operator delete(a2);
    result = 1;
  }
  else
  {
    operator delete(a2);
    result = 0;
  }
  return result;
}
