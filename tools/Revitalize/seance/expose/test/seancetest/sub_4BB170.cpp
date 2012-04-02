int __cdecl sub_4BB170()
{
  int v0; // eax@49
  int v2; // [sp+Ch] [bp-5Ch]@45
  int v3; // [sp+10h] [bp-58h]@32
  signed int v4; // [sp+14h] [bp-54h]@25
  GUIWindow *v5; // [sp+30h] [bp-38h]@40
  GUIWindow *v6; // [sp+38h] [bp-30h]@27
  GUIWindow *this; // [sp+40h] [bp-28h]@18
  int evt; // [sp+44h] [bp-24h]@24
  int v9; // [sp+48h] [bp-20h]@24
  int v10; // [sp+4Ch] [bp-1Ch]@24
  int v11; // [sp+5Ch] [bp-Ch]@24
  int window; // [sp+60h] [bp-8h]@19
  int v13; // [sp+64h] [bp-4h]@1

  debugLog("Setup 0");
  v13 = 1;
  byte_5304A0 = 0;
  LOBYTE(inExpansion) = 0;
  loadOrNewGameSelected = 0;
  dword_5247B8 = 0;
  dword_523ED8 = 10;
  dword_524778 = 10;
  dword_5235D4 = 1;
  dword_523F08 = 0;
  dword_4F7478 = 0;
  dword_4F307C = 1;
  if ( dword_4F19A8 == -1 )
  {
    this = (GUIWindow *)operator new(0x44u);
    if ( this )
      window = (int)GUIWindow_constructorFromFile(this, 405, 8, "stpnewgm.bin");
    else
      window = 0;
    if ( !window )
      fatalOutOfMemoryError();
    if ( dword_4F1CBC )
    {
      evt = 512;
      v9 = 5;
      v11 = 4096;
      v10 = 1;
      GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
      v10 = 2;
      GUIWindow::processMessage((GUIWindow *)window, (Event *)&evt);
    }
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      (GUIWindow *)window,
      (int (__fastcall *)(InputEvent *))loadGameMenuCallback,
      0);
    operator delete((void *)window);
    v4 = LOWORD(HeroWindowManager::instance->buttonPressedCode);
    if ( v4 <= 30721 )
    {
      if ( v4 == 30721 )
      {
        v13 = 0;
        goto LABEL_69;
      }
      if ( v4 != 1 )
      {
        if ( v4 == 2 )
        {
          if ( (unsigned __int8)byte_523004 == 1 )
          {
            v6 = (GUIWindow *)operator new(0x44u);
            if ( v6 )
              window = (int)GUIWindow_constructorFromFile(v6, 405, 8, "x_loadcm.bin");
            else
              window = 0;
            if ( !window )
              fatalOutOfMemoryError();
            HeroWindowManager::displayWindow(
              HeroWindowManager::instance,
              (GUIWindow *)window,
              (int (__fastcall *)(InputEvent *))sub_4BC500,
              0);
            operator delete((void *)window);
            v3 = LOWORD(HeroWindowManager::instance->buttonPressedCode);
            switch ( v3 )
            {
              case 1:
                loadOrNewGameSelected = 1;
                break;
              case 2:
                byte_5304A0 = 1;
                LOBYTE(inExpansion) = 1;
                break;
              case 30721:
                v13 = 0;
                goto LABEL_69;
            }
          }
          else
          {
            v5 = (GUIWindow *)operator new(0x44u);
            if ( v5 )
              window = (int)GUIWindow_constructorFromFile(v5, 405, 8, "x_loadcm.bin");
            else
              window = 0;
            if ( !window )
              fatalOutOfMemoryError();
            HeroWindowManager::displayWindow(
              HeroWindowManager::instance,
              (GUIWindow *)window,
              (int (__fastcall *)(InputEvent *))sub_4BC500,
              0);
            operator delete((void *)window);
            v2 = LOWORD(HeroWindowManager::instance->buttonPressedCode);
            switch ( v2 )
            {
              case 1:
                loadOrNewGameSelected = 1;
                if ( !sub_4BA260() )
                {
                  v13 = 0;
                  goto LABEL_69;
                }
                break;
              case 2:
                byte_5304A0 = 1;
                LOBYTE(inExpansion) = 1;
                v0 = sub_472820();
                sub_4705C0((int)&unk_530450, v0);
                break;
              case 30721:
                v13 = 0;
                goto LABEL_69;
            }
          }
        }
        else
        {
          if ( v4 == 3 && !sub_4BAF10() )
          {
            v13 = 0;
            goto LABEL_69;
          }
        }
      }
    }
    debugLog(" Setup 1");
    if ( dword_524778 == 1 || !dword_524778 )
    {
      debugLog(" Setup 2");
      sub_46D4F0((void *)dword_523ED8);
      debugLog(" Setup 3");
      if ( dword_523ED8 == 2 || dword_523ED8 == 4 )
        dword_523F08 = 1;
    }
  }
  else
  {
    switch ( dword_4F19A8 )
    {
      case 40110:
      case 40127:
        dword_5235D4 = 2;
        dword_524778 = 2;
        break;
      case 40111:
      case 40128:
        dword_5235D4 = 3;
        dword_524778 = 2;
        break;
      case 40112:
      case 40129:
        dword_5235D4 = 4;
        dword_524778 = 2;
        break;
      case 40114:
      case 40131:
        dword_524778 = 1;
        dword_523ED8 = 1;
        goto LABEL_12;
      case 40115:
      case 40132:
        dword_524778 = 1;
        dword_523ED8 = 2;
        goto LABEL_12;
      case 40117:
      case 40134:
        dword_524778 = 0;
        dword_523ED8 = 3;
        goto LABEL_12;
      case 40118:
      case 40135:
        dword_524778 = 0;
        dword_523ED8 = 4;
        goto LABEL_12;
      case 40120:
      case 40137:
        dword_524778 = 0;
        dword_523ED8 = 3;
        dword_4F7478 = 1;
        goto LABEL_12;
      case 40121:
      case 40138:
        dword_524778 = 0;
        dword_523ED8 = 4;
        dword_4F7478 = 1;
LABEL_12:
        debugLog("Setup 0a");
        sub_46D4F0((void *)dword_523ED8);
        if ( dword_523ED8 == 2 || dword_523ED8 == 4 )
          dword_523F08 = 1;
        break;
      case 40102:
      case 40123:
        break;
    }
    dword_4F19A8 = -1;
    v13 = 1;
  }
LABEL_69:
  dword_4F307C = 0;
  return v13;
}
