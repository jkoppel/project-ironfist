{
  __int16 v10; // ST54_2@186
  __int16 v11; // ST50_2@195
  __int16 v12; // ST4C_2@202
  heroWindow *result; // eax@227
  int a2a; // [sp+14h] [bp-118h]@1
  char *msga; // [sp+18h] [bp-114h]@1
  textWidget *v16; // [sp+34h] [bp-F8h]@212
  border *v17; // [sp+38h] [bp-F4h]@207
  textWidget *v18; // [sp+3Ch] [bp-F0h]@201
  textWidget *v19; // [sp+40h] [bp-ECh]@194
  textWidget *v20; // [sp+44h] [bp-E8h]@185
  iconWidget *v21; // [sp+48h] [bp-E4h]@178
  iconWidget *v22; // [sp+4Ch] [bp-E0h]@171
  iconWidget *v23; // [sp+50h] [bp-DCh]@164
  iconWidget *v24; // [sp+54h] [bp-D8h]@157
  iconWidget *v25; // [sp+58h] [bp-D4h]@152
  iconWidget *v26; // [sp+5Ch] [bp-D0h]@145
  iconWidget *v27; // [sp+60h] [bp-CCh]@138
  iconWidget *this; // [sp+64h] [bp-C8h]@132
  heroWindow *v29; // [sp+68h] [bp-C4h]@48
  char *plusOneBuf; // [sp+6Ch] [bp-C0h]@201
  __int16 height; // [sp+70h] [bp-BCh]@117
  int a3; // [sp+74h] [bp-B8h]@185
  int a3a; // [sp+74h] [bp-B8h]@190
  widget *v34; // [sp+78h] [bp-B4h]@208
  int borderSpriteIdx; // [sp+7Ch] [bp-B0h]@78
  signed int v36; // [sp+84h] [bp-A8h]@7
  heroWindow *v37; // [sp+88h] [bp-A4h]@13
  int spriteIdx; // [sp+8Ch] [bp-A0h]@218
  int v39; // [sp+90h] [bp-9Ch]@41
  char *content; // [sp+94h] [bp-98h]@212
  signed int v41; // [sp+98h] [bp-94h]@7
  tag_message event; // [sp+9Ch] [bp-90h]@53
  int v43; // [sp+B8h] [bp-74h]@13
  int v44; // [sp+BCh] [bp-70h]@13
  textWidget *component; // [sp+C0h] [bp-6Ch]@69
  int i; // [sp+C4h] [bp-68h]@15
  int v47; // [sp+C8h] [bp-64h]@7
  int v48; // [sp+CCh] [bp-60h]@7
  int numLines; // [sp+D0h] [bp-5Ch]@13
  int msgHeight; // [sp+D4h] [bp-58h]@13
  int v51; // [sp+D8h] [bp-54h]@7
  int width; // [sp+DCh] [bp-50h]@7
  int v53; // [sp+E0h] [bp-4Ch]@18
  int v54; // [sp+E4h] [bp-48h]@13
  int v55; // [sp+E8h] [bp-44h]@13
  int v56; // [sp+ECh] [bp-40h]@13
  int windowType; // [sp+F0h] [bp-3Ch]@39
  char a1; // [sp+F4h] [bp-38h]@48
  int imgArgs[2]; // [sp+104h] [bp-28h]@13
  int v60; // [sp+10Ch] [bp-20h]@41
  int buf[2]; // [sp+110h] [bp-1Ch]@70
  int imgTypes[2]; // [sp+118h] [bp-14h]@13
  signed int protoCategory; // [sp+120h] [bp-Ch]@218
  widget *guiObj; // [sp+124h] [bp-8h]@69

  a2a = a2;
  msga = msg;
  if ( !gbRemoteOn )
    a10 = 0;
  if ( a10 <= 1 || a10 >= 20000 )
    giDialogTimeout = a10;
  else
    giDialogTimeout = KBTickCount() + a10;
  v51 = 0;
  v47 = 0;
  v36 = 100;
  width = 0;
  v48 = 0;
  v41 = 0;
  if ( img1Type == 25 && img1Arg >= 100 )
  {
    img1Arg -= 100;
    v41 = 1;
  }
  if ( img1Type >= 19 && img1Type <= 24 )
    img1Type = -1;
  v37 = pNormalDialogWindow;
  v54 = giResType1;
  v44 = giResExtra1;
  v56 = giResType2;
  v43 = giResExtra2;
  giResType1 = img1Type;
  giResExtra1 = img1Arg;
  giResType2 = img2Type;
  giResExtra2 = img2Arg;
  imgTypes[0] = img1Type;
  imgArgs[0] = img1Arg;
  imgTypes[1] = img2Type;
  imgArgs[1] = img2Arg;
  numLines = font::LineLength(bigFont, msga, 244);
  msgHeight = 16 * numLines;
  v55 = 0;
  if ( a2a != 4 )
    msgHeight += 39;
  for ( i = 0; i < 2; ++i )
  {
    switch ( imgTypes[i] )
    {
      case 7:
        v53 = 76;
        break;
      case 10:
        v53 = 28;
        break;
      case 11:
        v53 = 57;
        break;
      case 12:
        v53 = 62;
        break;
      case 13:
        v53 = 59;
        break;
      case 14:
        v53 = (unsigned int)(imgArgs[i] + 1) < 1 ? 64 : 76;
        break;
      case 9:
        v53 = 55;
        break;
      case 15:
        v53 = 111;
        break;
      case 6:
        v53 = 26;
        break;
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        v53 = 44;
        break;
      case 8:
        v53 = 79;
        break;
      case 17:
        v53 = 81;
        break;
      case 18:
        v53 = 105;
        break;
      case 25:
        v53 = 105;
        break;
      default:
        v53 = 0;
        break;
    }
    if ( v53 > v55 )
      v55 = v53;
  }
  if ( v55 > 0 )
    msgHeight += v55 + 14;
  windowType = (msgHeight - 25) / 45;
  if ( windowType > 6 )
    windowType = 6;
  v60 = 306;
  v39 = 45 * windowType + 180;
  if ( x == -1 || v60 + x >= 639 )
    x = 159;
  if ( y == -1 || v39 + y >= 479 )
  {
    y = (480 - v39) / 2;
    if ( y > 28 )
      y = 28;
  }
  sprintf(&a1, "evntwin%d.bin", windowType);
  v29 = (heroWindow *)operator new(68);
  if ( v29 )
    pNormalDialogWindow = heroWindow::heroWindow(v29, x, y, &a1);
  else
    pNormalDialogWindow = 0;
  if ( !pNormalDialogWindow )
    MemError();
  event.eventCode = INPUT_GUI_MESSAGE_CODE;
  event.xCoordOrKeycode = 6;
  event.payload = (void *)6;
  if ( a2a != 7 && a2a != 8 )
  {
    event.yCoord = 30727;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  }
  if ( a2a != 7 )
  {
    event.yCoord = 30728;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  }
  if ( a2a != 6 && a2a != 3 )
  {
    event.yCoord = 30721;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  }
  if ( a2a != 5 && a2a != 1 && a2a != 3 )
  {
    event.yCoord = 30722;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  }
  if ( a2a != 2 )
  {
    event.yCoord = 30725;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
    event.yCoord = 30726;
    heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  }
  for ( i = 0; i < 2; ++i )
  {
    guiObj = 0;
    component = 0;
    if ( imgTypes[i] == -1 )
      break;
    buf[i] = (int)BaseAlloc(80u, "F:\\h2xsrc\\Source\\KB.CPP", word_50DFC8 + 187);
    if ( imgTypes[i] > 6 )
    {
      switch ( imgTypes[i] )
      {
        case 8:
          sprintf((char *)buf[i], "%s", gSpellNames[imgArgs[i]]);
          strcpy(&a1, "spells.icn");
          LOWORD(borderSpriteIdx) = gsSpellInfo[imgArgs[i]].spriteIdx;
          break;
        case 9:
          sprintf((char *)buf[i], "%s", unk_50E028);
          strcpy(&a1, "brcrest.icn");
          borderSpriteIdx = imgArgs[i];
          break;
        case 25:
          sprintf((char *)buf[i], "%s", unk_50E03C);
          strcpy(&a1, "primskil.icn");
          LOWORD(borderSpriteIdx) = 4;
          break;
        case 18:
          sprintf((char *)buf[i], "%s", &unk_50E054);
          strcpy(&a1, "strip.icn");
          LOWORD(borderSpriteIdx) = 12;
          break;
        case 17:
          sprintf((char *)buf[i], "%s", gSecondarySkills[imgArgs[i] / 3]);
          strcpy(&a1, "secskill.icn");
          borderSpriteIdx = imgArgs[i] / 3 + 1;
          break;
        case 15:
          sprintf((char *)buf[i], "%s", &unk_50E07C);
          sprintf(&a1, "surrendr.icn");
          LOWORD(borderSpriteIdx) = 4;
          break;
        default:
          if ( imgTypes[i] != 14 && imgTypes[i] != 12 && imgTypes[i] != 13 && imgTypes[i] != 10 && imgTypes[i] != 11 )
          {
            strcpy((char *)buf[i], byte_50E0A8);
            strcpy(&a1, "resource.icn");
            borderSpriteIdx = imgTypes[i];
          }
          else
          {
            strcpy((char *)buf[i], byte_50E094);
            strcpy(&a1, "expmrl.icn");
            borderSpriteIdx = imgTypes[i] - 10;
            if ( imgTypes[i] == 14 && imgArgs[i] != -1 )
              sprintf((char *)buf[i], "%d", imgArgs[i]);
          }
          break;
      }
    }
    else
    {
      if ( imgArgs[i] <= 0 )
      {
        if ( imgArgs[i] )
        {
          if ( imgArgs[i] >= -100000 )
            sprintf((char *)buf[i], "%d/day", -imgArgs[i]);
          else
            sprintf((char *)buf[i], "%d", imgArgs[i] + 100000);
        }
        else
        {
          strcpy((char *)buf[i], byte_50DFF8);
        }
      }
      else
      {
        sprintf((char *)buf[i], "%d", imgArgs[i]);
      }
      strcpy(&a1, "resource.icn");
      borderSpriteIdx = imgTypes[i];
    }
    switch ( imgTypes[i] )
    {
      case 25:
        width = 94;
        v53 = 105;
        break;
      case 7:
        width = 76;
        v53 = 76;
        break;
      case 10:
        width = 64;
        v53 = 28;
        break;
      case 11:
        width = 64;
        v53 = 57;
        break;
      case 12:
        width = 64;
        v53 = 62;
        break;
      case 13:
        width = 64;
        v53 = 59;
        break;
      case 14:
        width = 64;
        v53 = 64;
        break;
      case 9:
        width = 50;
        v53 = 55;
        break;
      case 15:
        width = 111;
        v53 = 105;
        break;
      case 6:
        width = 76;
        v53 = 26;
        break;
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        width = 38;
        v53 = 32;
        break;
      case 8:
        width = 70;
        v53 = 55;
        break;
      case 17:
        width = 75;
        v53 = 65;
        break;
      case 18:
        width = 94;
        v53 = 105;
        break;
      default:
        break;
    }
    height = v53;
    if ( strlen(buf[i]) )
      v53 += 12;
    if ( i )
    {
      v51 = v60 - 87;
    }
    else if ( imgTypes[1] == -1 )
    {
      v51 = (v60 - 17) / 2 + 17;
    }
    else
    {
      v51 = 104;
    }
    v47 = v39 - v53 - 48;
    if ( a2a != 4 )
      v47 -= 39;
    if ( imgTypes[0] == 17 && imgTypes[1] == 17 )
    {
      if ( i )
        v51 += 4;
      else
        v51 -= 4;
    }
    this = (iconWidget *)operator new(45);
    if ( this )
      guiObj = (widget *)iconWidget::iconWidget(
                           this,
                           v51 + ((unsigned int)(imgTypes[i] - 8) < 1 ? 2 : 0) - width / 2,
                           v47,
                           width,
                           height,
                           &a1,
                           borderSpriteIdx,
                           0,
                           -1,
                           ((unsigned int)(imgTypes[i] - 8) < 1) + 16,
                           1);
    else
      guiObj = 0;
    if ( !guiObj )
      MemError();
    heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    if ( imgTypes[i] == 7 )
    {
      v27 = (iconWidget *)operator new(45);
      if ( v27 )
        guiObj = (widget *)iconWidget::iconWidget(
                             v27,
                             v51 - width / 2 + 6,
                             v47 + 6,
                             76,
                             76,
                             "artifact.icn",
                             LOWORD(imgArgs[i]) + 1,
                             0,
                             -1,
                             16,
                             1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    }
    if ( imgTypes[i] == 25 )
    {
      v26 = (iconWidget *)operator new(45);
      if ( v26 )
        guiObj = (widget *)iconWidget::iconWidget(
                             v26,
                             v51 - width / 2 + 6,
                             v47 + 6,
                             82,
                             93,
                             "primskil.icn",
                             imgArgs[i],
                             0,
                             -1,
                             16,
                             1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
      strcpy((char *)buf[i], gStatNames[imgArgs[i]]);
    }
    if ( imgTypes[i] == 18 )
    {
      v25 = (iconWidget *)operator new(45);
      if ( v25 )
        guiObj = (widget *)iconWidget::iconWidget(
                             v25,
                             v51 - width / 2 + 6,
                             v47 + 6,
                             82,
                             93,
                             "strip.icn",
                             gMonsterDatabase[imgArgs[i]].faction + 4,
                             0,
                             -1,
                             16,
                             1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
      sprintf(gText, "monh%04d.icn", imgArgs[i]);
      v24 = (iconWidget *)operator new(45);
      if ( v24 )
        guiObj = (widget *)iconWidget::iconWidget(v24, v51 - width / 2 + 6, v47 + 6, 82, 93, gText, 0, 0, -1, 16, 1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    }
    if ( imgTypes[i] == 9 )
    {
      v23 = (iconWidget *)operator new(45);
      if ( v23 )
        guiObj = (widget *)iconWidget::iconWidget(
                             v23,
                             v51 - width / 2 - 4,
                             v47 - 4,
                             58,
                             55,
                             "brcrest.icn",
                             6,
                             0,
                             -1,
                             16,
                             1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    }
    if ( imgTypes[i] == 17 )
    {
      v22 = (iconWidget *)operator new(45);
      if ( v22 )
        guiObj = (widget *)iconWidget::iconWidget(
                             v22,
                             v51 - width / 2 - 3,
                             v47 - 3,
                             71,
                             81,
                             "secskill.icn",
                             15,
                             0,
                             -1,
                             16,
                             1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    }
    if ( imgTypes[i] == 15 )
    {
      sprintf(&a1, "port%04d.icn", imgArgs[i]);
      v21 = (iconWidget *)operator new(45);
      if ( v21 )
        guiObj = (widget *)iconWidget::iconWidget(v21, v51 - width / 2 + 5, v47 + 5, 101, 95, &a1, 0, 0, -1, 16, 1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, guiObj, -1);
    }
    if ( imgTypes[i] == 17 )
    {
      a3 = v47 + v53 - 72;
      v20 = (textWidget *)operator new(43);
      if ( v20 )
      {
        v10 = v36++;
        component = textWidget::textWidget(
                      v20,
                      v51 - 50,
                      a3,
                      100,
                      (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
                      (char *)buf[i],
                      "smalfont.fnt",
                      1,
                      v10,
                      512,
                      1);
      }
      else
      {
        component = 0;
      }
      if ( !component )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, (widget *)component, -1);
      buf[i] = (int)BaseAlloc(0x50u, "F:\\h2xsrc\\Source\\KB.CPP", word_50DFC8 + 431);
      a3a = v47 + v53 - 24;
      sprintf((char *)buf[i], "%s", secondarySkillLevels[imgArgs[i] % 3 + 1]);
    }
    else if ( imgTypes[i] == 25 )
    {
      a3a = v47 + v53 - 93;
    }
    else
    {
      a3a = v47 + v53 - 10;
    }
    v19 = (textWidget *)operator new(43);
    if ( v19 )
    {
      v11 = v36++;
      component = textWidget::textWidget(
                    v19,
                    v51 - 50,
                    a3a,
                    100,
                    (unsigned int)(imgTypes[i] - 8) < 1 ? 24 : 12,
                    (char *)buf[i],
                    "smalfont.fnt",
                    1,
                    v11,
                    512,
                    1);
    }
    else
    {
      component = 0;
    }
    if ( !component )
      MemError();
    heroWindow::AddWidget(pNormalDialogWindow, (widget *)component, -1);
    if ( imgTypes[i] == 25 && v41 )
    {
      plusOneBuf = (char *)BaseAlloc(5u, "F:\\h2xsrc\\Source\\KB.CPP", word_50DFC8 + 457);
      strcpy(plusOneBuf, "+1 ");
      v18 = (textWidget *)operator new(43);
      if ( v18 )
      {
        v12 = v36++;
        component = textWidget::textWidget(
                      v18,
                      v51 - 50,
                      v47 + (_WORD)v53 - 22,
                      100,
                      16,
                      plusOneBuf,
                      "bigfont.fnt",
                      1,
                      v12,
                      512,
                      1);
      }
      else
      {
        component = 0;
      }
      if ( !component )
        MemError();
      heroWindow::AddWidget(pNormalDialogWindow, (widget *)component, -1);
    }
    v17 = (border *)operator new(42);
    if ( v17 )
      v34 = (widget *)border::border(v17, v51 - width / 2, v47, width, v53, i + 7700, 1, 0, 0);
    else
      v34 = 0;
    heroWindow::AddWidget(pNormalDialogWindow, v34, -1);
  }
  event.eventCode = 512;
  event.xCoordOrKeycode = 3;
  event.yCoord = 1;
  event.payload = msga;
  heroWindow::BroadcastMessage(pNormalDialogWindow, (Event *)&event);
  if ( writeOr == 1 )
  {
    content = (char *)BaseAlloc(3u, "F:\\h2xsrc\\Source\\KB.CPP", word_50DFC8 + 493);
    strcpy(content, "or");
    v16 = (textWidget *)operator new(43);
    if ( v16 )
      component = textWidget::textWidget(v16, v60 / 2 - 10, v47 + 43, 40, 12, content, "smalfont.fnt", 1, v36, 512, 1);
    else
      component = 0;
    if ( !component )
      MemError();
    heroWindow::AddWidget(pNormalDialogWindow, (widget *)component, -1);
  }
  protoCategory = gpMouseManager->cursorCategory;
  spriteIdx = gpMouseManager->spriteIdx;
  while ( gpMouseManager->cursorDisabled )
    mouseManager::ShowColorPointer(gpMouseManager);
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  if ( a2a != 6 && a2a != 5 )
  {
    if ( a2a == 4 )
    {
      heroWindowManager::AddWindow(gpWindowManager, pNormalDialogWindow, -1, 1);
      QuickViewWait();
      heroWindowManager::RemoveWindow(gpWindowManager, pNormalDialogWindow);
    }
    else
    {
      heroWindowManager::DoDialog(gpWindowManager, pNormalDialogWindow, EventWindowHandler, 0);
    }
  }
  else
  {
    heroWindowManager::DoDialog(gpWindowManager, pNormalDialogWindow, (int (__fastcall *)(tag_message *))WaitHandler, 0);
  }
  operator delete(pNormalDialogWindow);
  mouseManager::SetPointer(gpMouseManager, byte_50E1C0, spriteIdx, protoCategory);
  giResType1 = v54;
  giResExtra1 = v44;
  giResType2 = v56;
  giResExtra2 = v43;
  result = v37;
  pNormalDialogWindow = v37;
  return result;
}