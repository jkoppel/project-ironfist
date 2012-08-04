{
  int v0; // eax@41
  int v1; // eax@116
  int v2; // [sp+0h] [bp-520h]@0
  int v3; // [sp+4h] [bp-51Ch]@0
  int v4; // [sp+8h] [bp-518h]@0
  bool v5; // [sp+10h] [bp-510h]@134
  int v6; // [sp+14h] [bp-50Ch]@68
  char v7; // [sp+18h] [bp-508h]@104
  tag_message a2; // [sp+34h] [bp-4ECh]@49
  int v9; // [sp+50h] [bp-4D0h]@112
  int v10; // [sp+54h] [bp-4CCh]@112
  int v11; // [sp+58h] [bp-4C8h]@112
  bool v12; // [sp+5Ch] [bp-4C4h]@106
  char v13; // [sp+60h] [bp-4C0h]@106
  int v14; // [sp+64h] [bp-4BCh]@106
  int v15; // [sp+68h] [bp-4B8h]@90
  int v16; // [sp+6Ch] [bp-4B4h]@88
  int v17; // [sp+70h] [bp-4B0h]@104
  int v18; // [sp+74h] [bp-4ACh]@118
  int v19; // [sp+8Ch] [bp-494h]@50
  int y; // [sp+90h] [bp-490h]@2
  int x; // [sp+94h] [bp-48Ch]@2
  int v22; // [sp+98h] [bp-488h]@24
  int v23; // [sp+9Ch] [bp-484h]@1
  int v24; // [sp+A0h] [bp-480h]@47
  char v25; // [sp+A8h] [bp-478h]@3
  int v26; // [sp+3ACh] [bp-174h]@1
  int v27; // [sp+3B4h] [bp-16Ch]@47
  int v28; // [sp+3B8h] [bp-168h]@47
  int v29; // [sp+3BCh] [bp-164h]@21
  char a1; // [sp+3C0h] [bp-160h]@13

  v23 = 1;
  gbLastFramePlayed = 0;
  v26 = 0;
  if ( bSmackNum == 35 )
  {
    brotherIcon = resourceManager::GetIcon(gpResourceManager, "brothers.icn");
    mouseManager::MouseCoords(&x, &y);
    *(_DWORD *)gbCampaignSideChoice = x < 320;
  }
  KBChangeMenu(hmnuDflt);
  mouseManager::HideColorPointer(gpMouseManager);
  bMainDone = 1;
  memcpy(&v25, gPalette->contents, 0x300u);
  if ( !gbNoSound && gpSoundManager->hdidriver && *(_DWORD *)&soundVolume && bSmackNum != 36 )
  {
    bSmackSound = 1;
    if ( AIL_get_preference(15u) )
    {
      SmackSoundUseMSS(gpSoundManager->hdidriver);
      LogStr("SSSS 1");
    }
    else
    {
      SmackSoundUseDirectSound(gpSoundManager->hdidriver->system_data[2]);
      LogStr("SSSS 2");
    }
  }
  else
  {
    bSmackSound = 0;
  }
  if ( byte_4F74B8 && bSmackNum > 38 )
  {
    strcpy(&a1, "i:\\projects\\heroes\\art\\fin3d\\");
  }
  else if ( bSmackNum == 67 )
  {
    strcpy(&a1, ".\\DATA\\");
  }
  else
  {
    strcpy(&a1, "\\HEROES2\\ANIM\\");
  }
  if ( *(_DWORD *)&slowVideo )
    sprintf(gText, "%s%s.SMK", &a1, &SmackOptions[45 * bSmackNum + 18]);
  else
    sprintf(gText, "%s%s.SMK", &a1, &SmackOptions[45 * bSmackNum]);
  if ( bSmackSound )
    v29 = 1040384;
  else
    v29 = 0;
  if ( byte_50FF36[45 * bSmackNum] )
    v22 = 512;
  else
    v22 = 0;
  if ( gbLowMemory && bSmackNum == 30 && !*(_DWORD *)&slowVideo )
    v22 = 0;
  smk1 = 0;
  if ( bSmackNum != 67 )
  {
    while ( !smk1 )
    {
      smk1 = SmackOpen(gText, v29 + v22, -1);
      if ( !smk1 )
      {
        heroWindowManager::FadeScreen(gpWindowManager, 0, 128, 0);
        NormalDialog("Error reading the Heroes 2 Expansion CD.  Retry?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( gpWindowManager->buttonPressedCode == 30726 )
          ShutDown("CDROM drive error.  Exiting.");
      }
    }
    SmackToBuffer(smk1, 0, 0, 640, 480, gpWindowManager->screenBuffer->contents, 0);
  }
  if ( (unsigned int)strlen((int)&SmackOptions[45 * bSmackNum + 9]) > 1 )
  {
    if ( *(_DWORD *)&slowVideo )
      sprintf(gText, "%s%s.SMK", &a1, &SmackOptions[45 * bSmackNum + 27]);
    else
      sprintf(gText, "%s%s.SMK", &a1, &SmackOptions[45 * bSmackNum + 9]);
    v0 = ((unsigned int)bSmackSound < 1) - 1;
    smk2 = SmackOpen(gText, v0 & 0xFE000, -1);
    if ( byte_50FF38[45 * bSmackNum] )
    {
      if ( !*(_DWORD *)&slowVideo && bSmackNum != 67 )
        SmackToBuffer(
          smk2,
          *(__int16 *)((char *)&word_50FF39 + 45 * bSmackNum),
          *(__int16 *)((char *)&word_50FF3B + 45 * bSmackNum),
          640,
          480,
          gpWindowManager->screenBuffer->contents,
          0);
    }
  }
  FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0);
  BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  if ( byte_50FF34[45 * bSmackNum] )
    heroWindowManager::FadeScreen(gpWindowManager, 1, 128, 0);
  v28 = 1;
  v27 = 0;
  v24 = 0;
  if ( bSmackNum == 35 )
  {
    Process1WindowsMessage();
    while ( inputManager::GetEvent(gpInputManager, &a2)->eventCode )
      v19 = 0;
  }
  while ( v28 )
  {
    if ( bSmackNum == 67 )
    {
      if ( !v27 )
      {
        mouseManager::SetPointer(gpMouseManager, "advmice.mse", 40, -999);
        mouseManager::ReallyShowPointer(gpMouseManager);
        soundManager::PlayAmbientMusic(gpSoundManager, 42, 0, -1, v2);
        backImage = resourceManager::GetIcon(gpResourceManager, "x_ivy.icn");
        if ( !backImage )
          MemError();
        icon::DrawToBuffer(backImage, 0, 0, 0, 0);
        icon::DrawToBuffer(backImage, 0, 0, 1, 0);
        sprintf(gText, "%s%s.SMK", &a1, "IVYPOL");
        smk2 = SmackOpen(gText, 0, -1);
        memcpy(gPalette->contents, (const void *)(smk2 + 108), 0x300u);
        SmackClose(smk2);
        smk2 = 0;
        ConvertSmackerPalette(gPalette->contents);
        UpdatePalette(gPalette->contents);
        memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
        heroWindowManager::FadeScreen(gpWindowManager, 0, 4, 0);
        v27 = 1;
      }
    }
    else if ( !SmackWait(smk1) )
    {
      if ( bSmackNum == 3 && !v26 )
      {
        v26 = 1;
        soundManager::PlayAmbientMusic(gpSoundManager, 19, 0, -1, v2);
      }
      if ( (!v27 || *(_DWORD *)(smk1 + 12) > 1u)
        && (bSmackNum != 2 || *(_DWORD *)(smk1 + 12) - 1 != *(_DWORD *)(smk1 + 884)) )
      {
        v6 = v27 || !byte_50FF34[45 * bSmackNum];
        DoAdvance(smk1, 1, 1, v6, 0, v2, v3, v4);
      }
      if ( *(_DWORD *)(smk1 + 884) || *(_DWORD *)(smk1 + 12) <= 1u )
      {
        if ( !v27 )
        {
          if ( bSmackNum == 35 )
          {
            mouseManager::SetPointer(gpMouseManager, "advmice.mse", 40, -999);
            mouseManager::ReallyShowPointer(gpMouseManager);
          }
          if ( byte_50FF34[45 * bSmackNum] )
          {
            memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
            heroWindowManager::FadeScreen(gpWindowManager, 0, 4, 0);
          }
          if ( bSmackNum == 36 )
            soundManager::PlayAmbientMusic(gpSoundManager, 42, 0, -1, v2);
          if ( bSmackNum == 72 )
            soundManager::PlayAmbientMusic(gpSoundManager, 42, 0, -1, v2);
        }
        v27 = 1;
      }
    }
    if ( smk2 && v27 && !SmackWait(smk2) )
    {
      if ( v24 && *(_DWORD *)(smk2 + 12) - 1 == *(_DWORD *)(smk2 + 884) )
      {
        v16 = 0;
        if ( !byte_50FF38[45 * bSmackNum] || *(_DWORD *)&slowVideo )
        {
          if ( bSmackNum == 67 )
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
        DoAdvance(smk2, v15, v16, 0, 1, v2, v3, v4);
        gbLastFramePlayed = 1;
        while ( SmackWait(smk2) )
          Process1WindowsMessage();
      }
      else if ( bSmackNum == 67 )
      {
        DoAdvance(smk2, 1, 1, 0, 1, v2, v3, v4);
      }
      else
      {
        DoAdvance(smk2, byte_50FF38[45 * bSmackNum], 1, 0, 1, v2, v3, v4);
      }
      if ( smk2 && *(_DWORD *)(smk2 + 884) )
        v24 = 1;
    }
    Process1WindowsMessage();
    memcpy(&v17, inputManager::GetEvent(gpInputManager, (tag_message *)&v7), 0x1Cu);
    switch ( v17 )
    {
      case 4:
        if ( bSmackNum == 35 )
        {
          mouseManager::MouseCoords(&v14, (int *)&v13);
          v12 = v14 < 320;
          if ( v12 != *(_DWORD *)gbCampaignSideChoice )
          {
            *(_DWORD *)gbCampaignSideChoice = v12;
            if ( v12 == 1 )
            {
              icon::DrawToBuffer(brotherIcon, 0, 0, 0, 0);
              icon::DrawToBuffer(brotherIcon, 0, 0, 3, 0);
            }
            else
            {
              icon::DrawToBuffer(brotherIcon, 0, 0, 1, 0);
              icon::DrawToBuffer(brotherIcon, 0, 0, 2, 0);
            }
            BlitBitmapToScreen(gpWindowManager->screenBuffer, 49, 78, 0x21Au, 258, 49, 78);
          }
        }
        else if ( bSmackNum == 67 )
        {
          mouseManager::MouseCoords(&v11, &v9);
          v10 = ExpansionCampaignRect(v11, v9);
          if ( v10 != xLastChoice )
          {
            icon::DrawToBuffer(backImage, 0, 0, 0, 0);
            BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
            xLastChoice = v10;
            if ( smk2 )
            {
              SmackClose(smk2);
              smk2 = 0;
            }
            if ( v10 != -1 )
            {
              byte_524F14 = v10 + 68;
              sprintf(gText, "%s%s.SMK", &a1, &SmackOptions[45 * (char)(v10 + 68)]);
              v1 = ((unsigned int)bSmackSound < 1) - 1;
              smk2 = SmackOpen(gText, v1 & 0xFE000, -1);
              SmackToBuffer(
                smk2,
                *(__int16 *)((char *)&word_50FF39 + 45 * byte_524F14),
                *(__int16 *)((char *)&word_50FF3B + 45 * byte_524F14),
                640,
                480,
                gpWindowManager->screenBuffer->contents,
                0);
              icon::DrawToBuffer(backImage, 0, 0, 1, 0);
            }
          }
        }
        break;
      case 1:
        if ( v18 != 62 )
          goto LABEL_119;
        break;
      case 32:
LABEL_119:
        if ( bSmackNum != 35 && bSmackNum != 67 )
          goto LABEL_121;
        break;
      case 8:
LABEL_121:
        if ( bSmackNum != 37 && (bSmackNum != 67 || xLastChoice != -1) )
          goto LABEL_145;
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
    if ( bSmackNum == 2 && *(_DWORD *)(smk1 + 884) + 1 == *(_DWORD *)(smk1 + 12) && !v26 )
    {
      v26 = 1;
      soundManager::PlayAmbientMusic(gpSoundManager, 43, 0, -1, v2);
    }
    if ( !byte_50FF37[45 * bSmackNum] )
    {
      if ( gbLastFramePlayed
        || smk2
        && (bSmackNum < 39 ? (v5 = *(_DWORD *)(smk2 + 884) >= *(_DWORD *)(smk2 + 12)) : (v5 = (unsigned int)(*(_DWORD *)(smk2 + 12) - 1) <= *(_DWORD *)(smk2 + 884)),
            v5 || !*(_DWORD *)(smk2 + 884) && v24)
        || !smk2 && (*(_DWORD *)(smk1 + 884) >= *(_DWORD *)(smk1 + 12) || !*(_DWORD *)(smk1 + 884) && v27) )
      {
        v28 = 0;
        gbPlayedThrough = 1;
      }
    }
  }
LABEL_145:
  if ( bSmackNum == 35 )
  {
    mouseManager::HideColorPointer(gpMouseManager);
    mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  }
  if ( byte_50FF35[45 * bSmackNum] )
  {
    memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
    heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 36);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  }
  else if ( !gbPlayedThrough && bSmackNum != 2 )
  {
    memcpy(gpBufferPalette->contents, gPalette->contents, 0x300u);
    heroWindowManager::FadeScreen(gpWindowManager, 1, 128, 0);
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 36);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
  }
  if ( bTesting )
    SmackSummary(smk1, smksum);
  if ( smk1 )
    SmackClose(smk1);
  smk1 = 0;
  if ( smk2 )
    SmackClose(smk2);
  smk2 = 0;
  if ( bSmackNum != 2 )
  {
    memcpy(gPalette->contents, &v25, 0x300u);
    UpdatePalette(gPalette->contents);
  }
  mouseManager::ShowColorPointer(gpMouseManager);
  if ( brotherIcon )
    resourceManager::Dispose(gpResourceManager, (resource *)brotherIcon);
  brotherIcon = 0;
  if ( backImage )
    resourceManager::Dispose(gpResourceManager, (resource *)backImage);
  backImage = 0;
}