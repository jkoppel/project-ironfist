{
  int creatureFormBin; // eax@25
  char v14; // al@44
  char v15; // al@50
  signed int v16; // eax@78
  game *thisa; // [sp+Ch] [bp-D4h]@1
  char v19; // [sp+14h] [bp-CCh]@32
  iconWidget *v20; // [sp+1Ch] [bp-C4h]@85
  iconWidget *v21; // [sp+20h] [bp-C0h]@30
  heroWindow *thisb; // [sp+24h] [bp-BCh]@17
  int v23; // [sp+2Ch] [bp-B4h]@77
  int v24; // [sp+30h] [bp-B0h]@77
  signed int imgIdx; // [sp+34h] [bp-ACh]@77
  widget *v26; // [sp+38h] [bp-A8h]@86
  signed __int16 v27; // [sp+3Ch] [bp-A4h]@75
  char v28; // [sp+40h] [bp-A0h]@73
  int v29; // [sp+4Ch] [bp-94h]@56
  int evt; // [sp+50h] [bp-90h]@1
  int v31; // [sp+54h] [bp-8Ch]@38
  int v32; // [sp+58h] [bp-88h]@38
  char *v33; // [sp+68h] [bp-78h]@38
  __int16 v34; // [sp+6Ch] [bp-74h]@1
  int v35; // [sp+70h] [bp-70h]@15
  char a1; // [sp+74h] [bp-6Ch]@26
  __int16 v37; // [sp+84h] [bp-5Ch]@1
  int i; // [sp+88h] [bp-58h]@4
  int idx; // [sp+8Ch] [bp-54h]@28
  __int16 v40; // [sp+90h] [bp-50h]@1
  int v41; // [sp+94h] [bp-4Ch]@39
  int v42; // [sp+98h] [bp-48h]@65
  char v43; // [sp+9Ch] [bp-44h]@38
  icon *res; // [sp+BCh] [bp-24h]@28
  __int16 v45; // [sp+C0h] [bp-20h]@1
  char *buf; // [sp+C4h] [bp-1Ch]@38
  __int16 v47; // [sp+C8h] [bp-18h]@1
  int v48; // [sp+CCh] [bp-14h]@43
  tag_monsterInfo *creatureInfo; // [sp+D0h] [bp-10h]@14
  widget *guiObj; // [sp+D4h] [bp-Ch]@34
  __int16 v51; // [sp+D8h] [bp-8h]@1
  __int16 v52; // [sp+DCh] [bp-4h]@1
  int a12a; // [sp+110h] [bp+30h]@38

  thisa = this;
  v37 = 86;
  v45 = 164;
  v47 = 1;
  v40 = 2;
  v51 = 3;
  v52 = 4;
  v34 = 5;
  evt = 512;
  iViewArmyFrame = 0;
  iViewArmyType = creat;
  iViewArmyNumTroops = a5;
  gbAllowUpgrade = 0;
  if ( a6 && (gpAdvManager->ready == 1 || gpTownManager->ready == 1) )
  {
    for ( i = 20; i <= 24; ++i )
    {
      if ( LOBYTE((&gTownObjNames[3 * *(_BYTE *)(a6 + 3) + 27])[i + 1]) == creat )
      {
        if ( (1 << (i + 5)) & *(_DWORD *)(a6 + 24) )
        {
          gbAllowUpgrade = 1;
          iViewArmyUpgradeToType = creat + 1;
        }
      }
    }
    if ( (creat == CREATURE_GREEN_DRAGON || creat == CREATURE_RED_DRAGON) && *(_BYTE *)(a6 + 27) & 0x40 )
    {
      gbAllowUpgrade = 1;
      iViewArmyUpgradeToType = CREATURE_BLACK_DRAGON;
    }
  }
  creatureInfo = &gMonsterDatabase[creat];
  if ( a11 )
    v35 = a11 + 186;
  else
    v35 = (int)&gMonsterDatabase[creat];
  thisb = (heroWindow *)operator new(68);
  if ( thisb )
    *(_DWORD *)&thisa->_10[612] = heroWindow::heroWindow(thisb, 19, 75, "armywin.bin");
  else
    *(_DWORD *)&thisa->_10[612] = 0;
  if ( !*(_DWORD *)&thisa->_10[612] )
    MemError();
  if ( a8 == 1 )
    viewArmyFacingWIPXMod = -1;
  else
    viewArmyFacingWIPXMod = 1;
  creatureFormBin = resourceManager::MakeId(gpResourceManager, cArmyFrameFileNames[creat], 1);
  resourceManager::PointToFile(gpResourceManager, creatureFormBin);
  resourceManager::ReadBlock(gpResourceManager, &sViewArmyMonFrameInfo, 821u);
  ModifyFrameInfo(&sViewArmyMonFrameInfo, creat);
  BuildTempWalkSeq(&sViewArmyMonFrameInfo, 0, 1);
  *(_DWORD *)&viewArmyBaseX = 167;
  if ( gbLowMemory )
    sprintf(&a1, "monh%04d.icn", creat);
  else
    strcpy(&a1, cMonFilename[creat]);
  res = resourceManager::GetIcon(gpResourceManager, &a1);
  idx = byte_522DB5[0];
  *(_DWORD *)&viewArmyBaseX += viewArmyFacingWIPXMod * (GetIconEntry(res, byte_522DB5[0])->width / 2);
  *(_DWORD *)&viewArmyBaseX += viewArmyFacingWIPXMod * byte_522CA5[0]
                             + viewArmyFacingWIPXMod * GetIconEntry(res, idx)->offsetX;
  *(_DWORD *)&viewArmyBaseY = 138;
  *(_DWORD *)&viewArmyBaseY = GetIconEntry(res, idx)->height / 2 + 138;
  if ( gbLowMemory )
  {
    *(_DWORD *)&viewArmyBaseX = 126;
    *(_DWORD *)&viewArmyBaseY = 93;
  }
  v21 = (iconWidget *)operator new(45);
  if ( v21 )
  {
    if ( gbLowMemory )
      v19 = 0;
    else
      v19 = byte_522DB5[0];
    guiObj = (widget *)iconWidget::iconWidget(v21, viewArmyBaseX, viewArmyBaseY, 86, 149, &a1, v19, a8 < 1, 5, 16, 1);
  }
  else
  {
    guiObj = 0;
  }
  if ( !guiObj )
    MemError();
  heroWindow::AddWidget(*(heroWindow **)&thisa->_10[612], guiObj, -1);
  resourceManager::Dispose(gpResourceManager, (resource *)res);
  strcpy(&v43, gArmyNames[creat]);
  v43 -= 32;
  v31 = 3;
  v32 = 3;
  v33 = &v43;
  heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  buf = (char *)BaseAlloc(0x226u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF4B0 + 147);
  if ( a12a )
    v41 = armyGroup::GetMorale(a12, hro, (town *)a6, 0);
  else
    v41 = 0;
  if ( HIBYTE(creatureInfo->creature_flags) & 4 )
    v41 = 0;
  sprintf(buf, byte_4EF4EC);
  v48 = 0;
  sprintf(gText, "%s%d", cArmyDetail[0], creatureInfo->attack);
  strcat(buf, gText);
  if ( hro )
  {
    v14 = hero::Stats(hro, 0);
    v48 += v14;
  }
  if ( a11 )
    v48 = *(_BYTE *)(a11 + 198) - creatureInfo->attack;
  if ( v48 )
  {
    sprintf(gText, " (%d)", v48 + creatureInfo->attack);
    strcat(buf, gText);
  }
  v48 = 0;
  sprintf(gText, "\n%s%d", off_4F64E4[0], creatureInfo->defense);
  strcat(buf, gText);
  if ( hro )
  {
    v15 = hero::Stats(hro, PRIMARY_SKILL_DEFENSE);
    v48 += v15;
  }
  if ( a11 )
    v48 = *(_BYTE *)(a11 + 199) - creatureInfo->defense;
  if ( v48 )
  {
    sprintf(gText, " (%d)", v48 + creatureInfo->defense);
    strcat(buf, gText);
  }
  if ( creatureInfo->creature_flags & 4 )
  {
    v29 = *(_BYTE *)(v35 + 16);
    if ( v29 > 0 )
    {
      if ( gpCombatManager->ready == 1 )
        sprintf(gText, "\n%s%d", off_4F64E8[0], v29);
      else
        sprintf(gText, "\n%s%d", off_4F6500, v29);
      strcat(buf, gText);
    }
  }
  sprintf(gText, "\n%s%d", off_4F64EC[0], creatureInfo->min_damage);
  strcat(buf, gText);
  if ( creatureInfo->min_damage != creatureInfo->max_damage )
  {
    sprintf(gText, "-%d", creatureInfo->max_damage);
    strcat(buf, gText);
  }
  sprintf(gText, "\n%s%d", off_4F64F0[0], creatureInfo->hp);
  strcat(buf, gText);
  if ( gpCombatManager->ready == 1 )
  {
    sprintf(gText, "\n%s%d", "Hit Points Left: ", creatureInfo->hp - *(_DWORD *)(a11 + 162));
    strcat(buf, gText);
  }
  sprintf(gText, "\n%s%s", off_4F64F4[0], speedText[*(_BYTE *)(v35 + 11)]);
  strcat(buf, gText);
  sprintf(gText, "\n%s%s", off_4F64F8[0], off_4F629C[v41]);
  strcat(buf, gText);
  v42 = game::GetLuck(hro, (army *)a11, (town *)a6);
  sprintf(gText, "\n%s%s", off_4F64FC[0], off_4F627C[v42]);
  strcat(buf, gText);
  v32 = 4;
  v33 = buf;
  heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  if ( !gbAllowUpgrade )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 500;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a7 )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 30723;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a9 )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 30720;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a5 >= 1 )
  {
    sprintf(&v28, "%d", a5);
    v31 = 3;
    v32 = 2;
    v33 = &v28;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  }
  else
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 1;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
    v32 = 2;
    heroWindow::BroadcastMessage(*(heroWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a11 )
  {
    v27 = 169;
    if ( a9 )
      v27 = 181;
    v23 = 44 - *(_DWORD *)(a11 + 262);
    v24 = 10 - *(_DWORD *)(a11 + 262) + 420 - v23 * *(_DWORD *)(a11 + 262) / 2;
    imgIdx = -1;
    for ( i = 0; ; ++i )
    {
      v16 = *(_DWORD *)(a11 + 262);
      if ( v16 >= 6 )
        v16 = 6;
      if ( v16 <= i )
        break;
      ++imgIdx;
      while ( imgIdx < 15 && !*(_BYTE *)(imgIdx + a11 + 266) )
        ++imgIdx;
      v20 = (iconWidget *)operator new(45);
      if ( v20 )
        v26 = (widget *)iconWidget::iconWidget(
                          v20,
                          v24 + v23 * (_WORD)i,
                          v27 + 14,
                          0,
                          0,
                          "spellinl.icn",
                          imgIdx,
                          0,
                          i + 200,
                          16,
                          1);
      else
        v26 = 0;
      if ( !v26 )
        MemError();
      heroWindow::AddWidget(*(heroWindow **)&thisa->_10[612], v26, -1);
    }
  }
  glTimers = KBTickCount() + 90;
  *(_DWORD *)&thisa->_10[616] = 0;
  if ( a9 )
  {
    heroWindowManager::AddWindow(gpWindowManager, *(heroWindow **)&thisa->_10[612], -1, 1);
    QuickViewWait();
    heroWindowManager::RemoveWindow(gpWindowManager, *(heroWindow **)&thisa->_10[612]);
  }
  else
  {
    heroWindowManager::DoDialog(
      gpWindowManager,
      *(heroWindow **)&thisa->_10[612],
      (int (__fastcall *)(tag_message *))ViewArmyHandler,
      0);
    if ( gbDismissArmy && a12 )
    {
      a12->creatureTypes[a13] = -1;
      a12->quantities[a13] = 0;
    }
    if ( gbUpgradeArmy && a12 )
      a12->creatureTypes[a13] = iViewArmyUpgradeToType;
  }
  BaseFree(buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF4B0 + 356);
  return operator delete(*(void **)&thisa->_10[612]);
}