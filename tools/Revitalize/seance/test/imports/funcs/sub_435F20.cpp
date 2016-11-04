{
  signed int v2; // eax@4
  signed int v3; // eax@25
  signed int v4; // eax@58
  size_t v5; // eax@58
  void *v6; // [sp+1Ch] [bp-148h]@1
  InputEvent a2a; // [sp+24h] [bp-140h]@30
  int this; // [sp+40h] [bp-124h]@7
  int v9; // [sp+44h] [bp-120h]@79
  void *v10; // [sp+48h] [bp-11Ch]@14
  int v11; // [sp+4Ch] [bp-118h]@2
  int v12; // [sp+50h] [bp-114h]@7
  int v13; // [sp+54h] [bp-110h]@2
  InputEvent v14; // [sp+58h] [bp-10Ch]@30
  int v15; // [sp+74h] [bp-F0h]@2
  int v16; // [sp+78h] [bp-ECh]@7
  int v17; // [sp+7Ch] [bp-E8h]@12
  InputEvent evt; // [sp+80h] [bp-E4h]@12
  int v19; // [sp+9Ch] [bp-C8h]@12
  int i; // [sp+A0h] [bp-C4h]@72
  int v21; // [sp+A4h] [bp-C0h]@58
  int v22; // [sp+A8h] [bp-BCh]@12
  int v23; // [sp+ACh] [bp-B8h]@2
  GUIWindow *window; // [sp+B0h] [bp-B4h]@8
  int v25; // [sp+B4h] [bp-B0h]@42
  char str; // [sp+B8h] [bp-ACh]@12
  char v27[151]; // [sp+B9h] [bp-ABh]@67
  int v28; // [sp+150h] [bp-14h]@12
  int v29; // [sp+154h] [bp-10h]@12
  int v30; // [sp+158h] [bp-Ch]@12
  int v31; // [sp+15Ch] [bp-8h]@12
  int v32; // [sp+160h] [bp-4h]@2

  v6 = a2;
  if ( !dword_4F7494 )
    return;
  v32 = 120;
  v11 = 1;
  v15 = 20;
  v13 = 54;
  v23 = 0;
  if ( a1 )
  {
    if ( (signed int)a2 < 0 )
    {
      sprintf(globBuf, a1);
      globBuf[120] = 0;
      sub_436B00(globBuf, 6);
    }
    else
    {
      sprintf(globBuf, "%s:  %s", (char *)&dword_526CE0 + 34 * (_DWORD)a2 + 4, a1);
      globBuf[120] = 0;
      v2 = sub_435DC0(v6);
      sub_436B00(globBuf, gameObject->players[v2].color);
    }
    v23 = getTickCount();
  }
  v16 = 0;
  v12 = dword_524C14;
  dword_524C14 = 1;
  dword_5247A8 = 0;
  this = (int)operator new(0x44u);
  if ( this )
    window = GUIWindow_constructorFromFile((GUIWindow *)this, 0, 411, "netbox.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  evt.eventCode = 512;
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = byte_524240;
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 2;
  evt.payload = &byte_524240[140];
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 3;
  evt.payload = &byte_524240[280];
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 4;
  evt.payload = &byte_524240[420];
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 20;
  evt.payload = (void *)(byte_524C40 + 1);
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 21;
  evt.payload = (void *)(byte_524C41 + 1);
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 22;
  evt.payload = (void *)(byte_524C42 + 1);
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 23;
  evt.payload = (void *)(byte_524C43 + 1);
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.yCoord = 24;
  evt.payload = (void *)(gameObject->players[sub_435DC0((void *)dword_523F14)].color + 1);
  GUIWindow::processMessage(window, (Event *)&evt);
  HeroWindowManager::addWindow(HeroWindowManager::instance, window, -1, 1);
  v28 = 0;
  v29 = 0;
  v30 = 1;
  v31 = 0;
  v17 = 0;
  v22 = 1;
  v19 = 0;
  strcpy(&str, byte_50D8C4);
  sub_4D0F50(inputManager, 0);
  while ( !v29 )
  {
    yieldToGlobalUpdater();
    v10 = sub_46E3F0(0);
    if ( v10 )
    {
      if ( *((_BYTE *)v10 + 5) == 3 )
      {
        v10 = sub_46E3F0(1);
        if ( *((_BYTE *)v10 + 6) == 41 )
        {
          dword_4F1CC0 = 1;
          if ( advManager->ready == 1 )
          {
            dword_524C14 = v12;
            sub_4C2E60(advManager, (char *)v10 + 9);
            dword_524C14 = 1;
            v19 = 1;
          }
          dword_4F1CC0 = 0;
          v30 = 1;
        }
      }
      else
      {
        if ( *((_BYTE *)v10 + 5) == 2 )
        {
          if ( *((_BYTE *)v10 + 6) == 11 )
          {
            v10 = sub_46E3F0(1);
            sprintf(globBuf, "%s:  %s", (char *)&dword_526CE0 + 34 * *(_BYTE *)v10 + 4, (char *)v10 + 9);
            v3 = sub_435DC0((void *)*(_BYTE *)v10);
            sub_436B00(globBuf, gameObject->players[v3].color);
            v22 = 1;
            if ( v23 )
              v23 = getTickCount();
          }
          else
          {
            sub_436B00("[ Incoming data, must exit... ]", 6);
            v22 = 1;
            v28 = 1;
          }
        }
        else
        {
          v10 = sub_46E3F0(1);
        }
      }
    }
    passOnMessages();
    memcpy(&v14, InputManager::nextInputEvent(inputManager, &a2a), sizeof(v14));
    if ( v14.eventCode == 1 )
    {
      v23 = 0;
      if ( v14.xCoordOrKeycode <= 27 )
      {
        if ( v14.xCoordOrKeycode == 27 )
          goto LABEL_32;
        if ( v14.xCoordOrKeycode == 10 )
        {
          v17 = 1;
          goto LABEL_54;
        }
LABEL_37:
        if ( LOBYTE(v14.xCoordOrKeycode) >= 0x20u )
        {
          if ( LOBYTE(v14.xCoordOrKeycode) <= 0x7Fu )
          {
            if ( v16 < 93 )
            {
              if ( v14.xCoordOrKeycode )
              {
                *(&str + v16) = 0;
                v25 = Font::getFlattenedStringWidth(smallFont, &str);
                if ( v25 + 50 < 602 )
                {
                  *(&str + v16++) = LOBYTE(v14.xCoordOrKeycode);
                  v30 = 1;
                  v31 = 0;
                }
              }
            }
          }
        }
        goto LABEL_54;
      }
      if ( v14.xCoordOrKeycode != 127 )
      {
        if ( v14.xCoordOrKeycode == 0x3B00 )
        {
LABEL_32:
          v29 = 1;
          goto LABEL_54;
        }
        goto LABEL_37;
      }
      if ( v16 > 0 )
        --v16;
      v30 = 1;
      v31 = 1;
    }
LABEL_54:
    if ( !v30 && getTickCount() > animationFrameSwitchTime )
    {
      v31 = 1 - v31;
      v30 = 1;
    }
    if ( v17 )
    {
      v17 = 0;
      *(&str + v16) = 0;
      v4 = sub_435DC0((void *)dword_523F14);
      sub_436B00(&str, gameObject->players[v4].color);
      v5 = strlen(&str);
      v21 = sub_46E1D0(&str, 127, v5 + 1, 11, 1, 1, -1);
      if ( !v21 )
        terminate(0);
      v16 = 0;
      strcpy(&str, byte_50D8F0);
      v30 = 1;
      v22 = 1;
    }
    if ( v22 )
    {
      v22 = 0;
      evt.eventCode = 512;
      evt.xCoordOrKeycode = 3;
      evt.yCoord = 1;
      evt.payload = byte_524240;
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 2;
      evt.payload = &byte_524240[140];
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 3;
      evt.payload = &byte_524240[280];
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 4;
      evt.payload = &byte_524240[420];
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.yCoord = 20;
      evt.payload = (void *)(byte_524C40 + 1);
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 21;
      evt.payload = (void *)(byte_524C41 + 1);
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 22;
      evt.payload = (void *)(byte_524C42 + 1);
      GUIWindow::processMessage(window, (Event *)&evt);
      evt.yCoord = 23;
      evt.payload = (void *)(byte_524C43 + 1);
      GUIWindow::processMessage(window, (Event *)&evt);
      GUIWindow::repaintAndUpdateScreen(window);
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 411, 0x27Fu, 68);
    }
    if ( v30 )
    {
      v30 = 0;
      animationFrameSwitchTime = getTickCount() + 360;
      if ( v31 )
        *(&str + v16) = 95;
      else
        *(&str + v16) = 31;
      v27[v16] = 0;
      evt.eventCode = 512;
      evt.xCoordOrKeycode = 3;
      evt.yCoord = 5;
      evt.payload = &str;
      GUIWindow::processMessage(window, (Event *)&evt);
      GUIWindow::repaintAndUpdateScreen(window);
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 465, 0x27Fu, 12);
    }
    if ( v23 && getTickCount() > v23 + 6000 )
      v29 = 1;
    if ( v28 )
    {
      for ( i = 0; i < 20; ++i )
      {
        yieldToGlobalUpdater();
        sleep(75);
      }
      v29 = 1;
    }
  }
  sub_4D0F50(inputManager, 1);
  if ( v19 && dword_5247A8 )
  {
    dword_4F1CC4 = 0;
    HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
    dword_4F1CC4 = 1;
    v9 = dword_524C14;
    dword_524C14 = 1;
    sub_4506B0(advManager, 1, 0);
    dword_524C14 = v9;
  }
  else
  {
    HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
  }
  dword_524C14 = v12;
}
