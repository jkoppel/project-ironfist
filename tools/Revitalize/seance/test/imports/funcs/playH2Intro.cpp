{
  int v0; // eax@43
  int v1; // eax@121
  int v2; // [sp+0h] [bp-520h]@0
  int v3; // [sp+4h] [bp-51Ch]@0
  int v4; // [sp+8h] [bp-518h]@0
  signed int v5; // [sp+10h] [bp-510h]@140
  int v6; // [sp+14h] [bp-50Ch]@70
  char v7; // [sp+18h] [bp-508h]@106
  InputEvent a2; // [sp+34h] [bp-4ECh]@51
  int v9; // [sp+50h] [bp-4D0h]@117
  int v10; // [sp+54h] [bp-4CCh]@117
  int v11; // [sp+58h] [bp-4C8h]@117
  bool v12; // [sp+5Ch] [bp-4C4h]@109
  char v13; // [sp+60h] [bp-4C0h]@108
  int v14; // [sp+64h] [bp-4BCh]@108
  int v15; // [sp+68h] [bp-4B8h]@92
  int v16; // [sp+6Ch] [bp-4B4h]@90
  int v17; // [sp+70h] [bp-4B0h]@106
  int v18; // [sp+74h] [bp-4ACh]@123
  int v19; // [sp+8Ch] [bp-494h]@52
  int y; // [sp+90h] [bp-490h]@2
  int x; // [sp+94h] [bp-48Ch]@2
  int v22; // [sp+98h] [bp-488h]@26
  int v23; // [sp+9Ch] [bp-484h]@1
  int v24; // [sp+A0h] [bp-480h]@49
  char v25; // [sp+A8h] [bp-478h]@5
  int v26; // [sp+3ACh] [bp-174h]@1
  int v27; // [sp+3B4h] [bp-16Ch]@49
  int v28; // [sp+3B8h] [bp-168h]@49
  int v29; // [sp+3BCh] [bp-164h]@23
  char v30; // [sp+3C0h] [bp-160h]@15

  v23 = 1;
  dword_524F1C = 0;
  v26 = 0;
  if ( byte_524EC0 == 35 )
  {
    dword_50FEE0 = ResourceManager::getIconByFilename(resourceManager, "brothers.icn");
    retrieveVirtualCursorCoordinates(&x, &y);
    dword_5247B8 = x < 320;
  }
  changeMenu(dfltMenu);
  MouseManager::disableCursor(mouseManager);
  byte_524F18 = 1;
  memcpy(&v25, dword_524234->contents, 0x300u);
  if ( !soundDisabled && soundManager->hdidriver && *(_DWORD *)&soundVolume && byte_524EC0 != 36 )
  {
    dword_50FEDC = 1;
    if ( AIL_get_preference(15u) )
    {
      SmackSoundUseMSS(soundManager->hdidriver);
      debugLog("SSSS 1");
    }
    else
    {
      SmackSoundUseDirectSound(soundManager->hdidriver->system_data[2]);
      debugLog("SSSS 2");
    }
  }
  else
  {
    dword_50FEDC = 0;
  }
  if ( byte_4F74B8 && byte_524EC0 > 38 )
  {
    strcpy(&v30, "i:\\projects\\heroes\\art\\fin3d\\");
  }
  else
  {
    if ( byte_524EC0 == 67 )
      strcpy(&v30, ".\\DATA\\");
    else
      strcpy(&v30, "\\HEROES2\\ANIM\\");
  }
  if ( *(_DWORD *)&slowVideo )
    sprintf(globBuf, "%s%s.SMK", &v30, &aH2intro[45 * byte_524EC0 + 18]);
  else
    sprintf(globBuf, "%s%s.SMK", &v30, &aH2intro[45 * byte_524EC0]);
  if ( dword_50FEDC )
    v29 = 1040384;
  else
    v29 = 0;
  if ( byte_50FF36[45 * byte_524EC0] )
    v22 = 512;
  else
    v22 = 0;
  if ( dword_4F74A8 && byte_524EC0 == 30 && !*(_DWORD *)&slowVideo )
    v22 = 0;
  dword_510BEC = 0;
  if ( byte_524EC0 != 67 )
  {
    while ( !dword_510BEC )
    {
      dword_510BEC = SmackOpen(globBuf, v29 + v22, -1);
      if ( !dword_510BEC )
      {
        sub_4C7C60(HeroWindowManager::instance, 0, 128, 0);
        display_message_window("Error reading the Heroes 2 Expansion CD.  Retry?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( HeroWindowManager::instance->buttonPressedCode == 30726 )
          terminate("CDROM drive error.  Exiting.");
      }
    }
    SmackToBuffer(dword_510BEC, 0, 0, 640, 480, HeroWindowManager::instance->screenBuffer->contents, 0);
  }
  if ( strlen(&aH2intro[45 * byte_524EC0 + 9]) > 1 )
  {
    if ( *(_DWORD *)&slowVideo )
      sprintf(globBuf, "%s%s.SMK", &v30, &aH2intro[45 * byte_524EC0 + 27]);
    else
      sprintf(globBuf, "%s%s.SMK", &v30, &aH2intro[45 * byte_524EC0 + 9]);
    v0 = ((unsigned int)dword_50FEDC < 1) - 1;
    dword_510BF0 = SmackOpen(globBuf, v0 & 0xFE000, -1);
    if ( byte_50FF38[45 * byte_524EC0] )
    {
      if ( !*(_DWORD *)&slowVideo && byte_524EC0 != 67 )
        SmackToBuffer(
          dword_510BF0,
          *(__int16 *)((char *)&word_50FF39 + 45 * byte_524EC0),
          *(__int16 *)((char *)&word_50FF3B + 45 * byte_524EC0),
          640,
          480,
          HeroWindowManager::instance->screenBuffer->contents,
          0);
    }
  }
  sub_4D6A50(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0);
  renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  if ( byte_50FF34[45 * byte_524EC0] )
    sub_4C7C60(HeroWindowManager::instance, 1, 128, 0);
  v28 = 1;
  v27 = 0;
  v24 = 0;
  if ( byte_524EC0 == 35 )
  {
    passOnMessages();
    while ( InputManager::nextInputEvent(inputManager, &a2)->eventCode )
      v19 = 0;
  }
  while ( v28 )
  {
    if ( byte_524EC0 == 67 )
    {
      if ( !v27 )
      {
        MouseManager::loadMSE(mouseManager, "advmice.mse", 40, -999);
        sub_4CEA00(mouseManager);
        SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v2);
        dword_50FF08 = ResourceManager::getIconByFilename(resourceManager, "x_ivy.icn");
        if ( !dword_50FF08 )
          fatalOutOfMemoryError();
        Icon::drawToScreen(dword_50FF08, 0, 0, 0, 0);
        Icon::drawToScreen(dword_50FF08, 0, 0, 1, 0);
        sprintf(globBuf, "%s%s.SMK", &v30, "IVYPOL");
        dword_510BF0 = SmackOpen(globBuf, 0, -1);
        memcpy(dword_524234->contents, (const void *)(dword_510BF0 + 108), 0x300u);
        SmackClose(dword_510BF0);
        dword_510BF0 = 0;
        sub_458DD0(dword_524234->contents);
        sub_49CFB0(dword_524234->contents);
        memcpy(palette->contents, dword_524234->contents, 0x300u);
        sub_4C7C60(HeroWindowManager::instance, 0, 4, 0);
        v27 = 1;
      }
    }
    else
    {
      if ( !SmackWait(dword_510BEC) )
      {
        if ( byte_524EC0 == 3 && !v26 )
        {
          v26 = 1;
          SoundManager::otherPlayTrack(soundManager, 19, 0, -1, v2);
        }
        if ( (!v27 || *(_DWORD *)(dword_510BEC + 12) > 1u)
          && (byte_524EC0 != 2 || *(_DWORD *)(dword_510BEC + 12) - 1 != *(_DWORD *)(dword_510BEC + 884)) )
        {
          v6 = v27 || !byte_50FF34[45 * byte_524EC0];
          sub_458E20(dword_510BEC, 1, 1, v6, 0, v2, v3, v4);
        }
        if ( *(_DWORD *)(dword_510BEC + 884) || *(_DWORD *)(dword_510BEC + 12) <= 1u )
        {
          if ( !v27 )
          {
            if ( byte_524EC0 == 35 )
            {
              MouseManager::loadMSE(mouseManager, "advmice.mse", 40, -999);
              sub_4CEA00(mouseManager);
            }
            if ( byte_50FF34[45 * byte_524EC0] )
            {
              memcpy(palette->contents, dword_524234->contents, 0x300u);
              sub_4C7C60(HeroWindowManager::instance, 0, 4, 0);
            }
            if ( byte_524EC0 == 36 )
              SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v2);
            if ( byte_524EC0 == 72 )
              SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v2);
          }
          v27 = 1;
        }
      }
    }
    if ( dword_510BF0 && v27 && !SmackWait(dword_510BF0) )
    {
      if ( v24 && *(_DWORD *)(dword_510BF0 + 12) - 1 == *(_DWORD *)(dword_510BF0 + 884) )
      {
        v16 = 0;
        if ( !byte_50FF38[45 * byte_524EC0] || *(_DWORD *)&slowVideo )
        {
          if ( byte_524EC0 == 67 )
          {
            v15 = 1;
            v16 = 1;
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          v15 = 1;
        }
        sub_458E20(dword_510BF0, v15, v16, 0, 1, v2, v3, v4);
        dword_524F1C = 1;
        while ( SmackWait(dword_510BF0) )
          passOnMessages();
      }
      else
      {
        if ( byte_524EC0 == 67 )
          sub_458E20(dword_510BF0, 1, 1, 0, 1, v2, v3, v4);
        else
          sub_458E20(dword_510BF0, byte_50FF38[45 * byte_524EC0], 1, 0, 1, v2, v3, v4);
      }
      if ( dword_510BF0 && *(_DWORD *)(dword_510BF0 + 884) )
        v24 = 1;
    }
    passOnMessages();
    memcpy(&v17, InputManager::nextInputEvent(inputManager, (InputEvent *)&v7), 0x1Cu);
    switch ( v17 )
    {
      case 4:
        if ( byte_524EC0 == 35 )
        {
          retrieveVirtualCursorCoordinates(&v14, (int *)&v13);
          v12 = v14 < 320;
          if ( v12 != dword_5247B8 )
          {
            dword_5247B8 = v12;
            if ( v12 == 1 )
            {
              Icon::drawToScreen(dword_50FEE0, 0, 0, 0, 0);
              Icon::drawToScreen(dword_50FEE0, 0, 0, 3, 0);
            }
            else
            {
              Icon::drawToScreen(dword_50FEE0, 0, 0, 1, 0);
              Icon::drawToScreen(dword_50FEE0, 0, 0, 2, 0);
            }
            renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 49, 78, 0x21Au, 258, 49, 78);
          }
        }
        else
        {
          if ( byte_524EC0 == 67 )
          {
            retrieveVirtualCursorCoordinates(&v11, &v9);
            v10 = sub_45A440(v11, v9);
            if ( v10 != dword_5304C8 )
            {
              Icon::drawToScreen(dword_50FF08, 0, 0, 0, 0);
              renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
              dword_5304C8 = v10;
              if ( dword_510BF0 )
              {
                SmackClose(dword_510BF0);
                dword_510BF0 = 0;
              }
              if ( v10 != -1 )
              {
                byte_524F14 = v10 + 68;
                sprintf(globBuf, "%s%s.SMK", &v30, &aH2intro[45 * (char)(v10 + 68)]);
                v1 = ((unsigned int)dword_50FEDC < 1) - 1;
                dword_510BF0 = SmackOpen(globBuf, v1 & 0xFE000, -1);
                SmackToBuffer(
                  dword_510BF0,
                  *(__int16 *)((char *)&word_50FF39 + 45 * byte_524F14),
                  *(__int16 *)((char *)&word_50FF3B + 45 * byte_524F14),
                  640,
                  480,
                  HeroWindowManager::instance->screenBuffer->contents,
                  0);
                Icon::drawToScreen(dword_50FF08, 0, 0, 1, 0);
              }
            }
          }
        }
        break;
      case 1:
        if ( v18 != 62 )
          goto LABEL_124;
        break;
      case 32:
LABEL_124:
        if ( byte_524EC0 != 35 && byte_524EC0 != 67 )
          goto LABEL_126;
        break;
      case 8:
LABEL_126:
        if ( byte_524EC0 != 37 && (byte_524EC0 != 67 || dword_5304C8 != -1) )
          goto LABEL_155;
        break;
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:
        break;
    }
    if ( byte_524EC0 == 2 && *(_DWORD *)(dword_510BEC + 884) + 1 == *(_DWORD *)(dword_510BEC + 12) && !v26 )
    {
      v26 = 1;
      SoundManager::otherPlayTrack(soundManager, 43, 0, -1, v2);
    }
    if ( !byte_50FF37[45 * byte_524EC0] )
    {
      if ( dword_524F1C
        || dword_510BF0
        && (byte_524EC0 < 39 ? (*(_DWORD *)(dword_510BF0 + 884) < *(_DWORD *)(dword_510BF0 + 12) ? (v5 = 0) : (v5 = 1)) : (unsigned int)(*(_DWORD *)(dword_510BF0 + 12) - 1) > *(_DWORD *)(dword_510BF0 + 884) ? (v5 = 0) : (v5 = 1),
            v5 || !*(_DWORD *)(dword_510BF0 + 884) && v24)
        || !dword_510BF0
        && (*(_DWORD *)(dword_510BEC + 884) >= *(_DWORD *)(dword_510BEC + 12) || !*(_DWORD *)(dword_510BEC + 884) && v27) )
      {
        v28 = 0;
        dword_524EC4 = 1;
      }
    }
  }
LABEL_155:
  if ( byte_524EC0 == 35 )
  {
    MouseManager::disableCursor(mouseManager);
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  }
  if ( byte_50FF35[45 * byte_524EC0] )
  {
    memcpy(palette->contents, dword_524234->contents, 0x300u);
    sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
    sub_4D6A50(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 36);
    renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  }
  else
  {
    if ( !dword_524EC4 && byte_524EC0 != 2 )
    {
      memcpy(palette->contents, dword_524234->contents, 0x300u);
      sub_4C7C60(HeroWindowManager::instance, 1, 128, 0);
      sub_4D6A50(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 36);
      renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
    }
  }
  if ( dword_510BE8 )
    SmackSummary(dword_510BEC, smackSummaryBuf);
  if ( dword_510BEC )
    SmackClose(dword_510BEC);
  dword_510BEC = 0;
  if ( dword_510BF0 )
    SmackClose(dword_510BF0);
  dword_510BF0 = 0;
  if ( byte_524EC0 != 2 )
  {
    memcpy(dword_524234->contents, &v25, 0x300u);
    sub_49CFB0(dword_524234->contents);
  }
  MouseManager::enableCursor(mouseManager);
  if ( dword_50FEE0 )
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)dword_50FEE0);
  dword_50FEE0 = 0;
  if ( dword_50FF08 )
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)dword_50FF08);
  dword_50FF08 = 0;
}
