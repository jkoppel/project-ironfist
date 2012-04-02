{
  int creatureFormBin; // eax@25
  char v14; // al@44
  char v15; // al@50
  signed int v16; // eax@78
  GameInfo *thisa; // [sp+Ch] [bp-D4h]@1
  char v19; // [sp+14h] [bp-CCh]@32
  GUIIcon *v20; // [sp+1Ch] [bp-C4h]@85
  GUIIcon *v21; // [sp+20h] [bp-C0h]@30
  GUIWindow *thisb; // [sp+24h] [bp-BCh]@17
  int v23; // [sp+2Ch] [bp-B4h]@77
  int v24; // [sp+30h] [bp-B0h]@77
  signed int imgIdx; // [sp+34h] [bp-ACh]@77
  AbstractGUIComponent *v26; // [sp+38h] [bp-A8h]@86
  signed __int16 v27; // [sp+3Ch] [bp-A4h]@75
  char v28; // [sp+40h] [bp-A0h]@73
  int v29; // [sp+4Ch] [bp-94h]@56
  int evt; // [sp+50h] [bp-90h]@1
  int v31; // [sp+54h] [bp-8Ch]@38
  int v32; // [sp+58h] [bp-88h]@38
  char *v33; // [sp+68h] [bp-78h]@38
  __int16 v34; // [sp+6Ch] [bp-74h]@1
  int v35; // [sp+70h] [bp-70h]@15
  char filename; // [sp+74h] [bp-6Ch]@26
  __int16 v37; // [sp+84h] [bp-5Ch]@1
  int i; // [sp+88h] [bp-58h]@4
  int idx; // [sp+8Ch] [bp-54h]@28
  __int16 v40; // [sp+90h] [bp-50h]@1
  int v41; // [sp+94h] [bp-4Ch]@39
  int v42; // [sp+98h] [bp-48h]@65
  char v43; // [sp+9Ch] [bp-44h]@38
  Icon *res; // [sp+BCh] [bp-24h]@28
  __int16 v45; // [sp+C0h] [bp-20h]@1
  char *buf; // [sp+C4h] [bp-1Ch]@38
  __int16 v47; // [sp+C8h] [bp-18h]@1
  int v48; // [sp+CCh] [bp-14h]@43
  creatureStats *creatureInfo; // [sp+D0h] [bp-10h]@14
  AbstractGUIComponent *guiObj; // [sp+D4h] [bp-Ch]@34
  __int16 v51; // [sp+D8h] [bp-8h]@1
  __int16 v52; // [sp+DCh] [bp-4h]@1

  thisa = this;
  v37 = 86;
  v45 = 164;
  v47 = 1;
  v40 = 2;
  v51 = 3;
  v52 = 4;
  v34 = 5;
  evt = 512;
  dword_522FC8 = 0;
  dword_522FD8 = creat;
  dword_522C38 = a5;
  dword_522F80 = 0;
  if ( a6 && (advManager->ready == 1 || townManager->ready == 1) )
  {
    for ( i = 20; i <= 24; ++i )
    {
      if ( LOBYTE((&buildingShortNames[3 * *(_BYTE *)(a6 + 3) + 27])[i + 1]) == creat )
      {
        if ( (1 << (i + 5)) & *(_DWORD *)(a6 + 24) )
        {
          dword_522F80 = 1;
          stackWindowDisplayedCreature = creat + 1;
        }
      }
    }
    if ( (creat == CREATURE_GREEN_DRAGON || creat == CREATURE_RED_DRAGON) && *(_BYTE *)(a6 + 27) & 0x40 )
    {
      dword_522F80 = 1;
      stackWindowDisplayedCreature = CREATURE_BLACK_DRAGON;
    }
  }
  creatureInfo = &creature_table[creat];
  if ( a11 )
    v35 = a11 + 186;
  else
    v35 = (int)&creature_table[creat];
  thisb = (GUIWindow *)operator new(0x44u);
  if ( thisb )
    *(_DWORD *)&thisa->_10[612] = GUIWindow_constructorFromFile(thisb, 19, 75, "armywin.bin");
  else
    *(_DWORD *)&thisa->_10[612] = 0;
  if ( !*(_DWORD *)&thisa->_10[612] )
    fatalOutOfMemoryError();
  if ( a8 == 1 )
    dword_522F78 = -1;
  else
    dword_522F78 = 1;
  creatureFormBin = ResourceManager::setResource(resourceManager, creature_form_table[creat], 1);
  ResourceManager::pointToFile(resourceManager, creatureFormBin);
  ResourceManager::readFromCurrentFile(resourceManager, &byte_522C40, 821u);
  CreatureForm::doSomethingElse(&byte_522C40, creat);
  CreatureForm::doSomething(&byte_522C40, 0, 1);
  *(_DWORD *)&xGlob = 167;
  if ( dword_4F74A8 )
    sprintf(&filename, "monh%04d.icn", creat);
  else
    strcpy(&filename, creatureIconNames[creat]);
  res = ResourceManager::getIconByFilename(resourceManager, &filename);
  idx = byte_522DB5[0];
  *(_DWORD *)&xGlob += dword_522F78 * (getNthHeader(res, byte_522DB5[0])->width / 2);
  *(_DWORD *)&xGlob += dword_522F78 * byte_522CA5[0] + dword_522F78 * getNthHeader(res, idx)->offsetX;
  *(_DWORD *)&dword_522F94 = 138;
  *(_DWORD *)&dword_522F94 = getNthHeader(res, idx)->height / 2 + 138;
  if ( dword_4F74A8 )
  {
    *(_DWORD *)&xGlob = 126;
    *(_DWORD *)&dword_522F94 = 93;
  }
  v21 = (GUIIcon *)operator new(0x2Du);
  if ( v21 )
  {
    if ( dword_4F74A8 )
      v19 = 0;
    else
      v19 = byte_522DB5[0];
    guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                       v21,
                                       xGlob,
                                       dword_522F94,
                                       86,
                                       149,
                                       &filename,
                                       v19,
                                       a8 < 1,
                                       5,
                                       16,
                                       1);
  }
  else
  {
    guiObj = 0;
  }
  if ( !guiObj )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(*(GUIWindow **)&thisa->_10[612], guiObj, -1);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
  strcpy(&v43, creatureSingularNames[creat]);
  v43 -= 32;
  v31 = 3;
  v32 = 3;
  v33 = &v43;
  GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  buf = (char *)KBAlloc(0x226u, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EF4B0 + 147);
  if ( a12 )
    v41 = ArmyInfo::computeMorale(a12, a10, (Castle *)a6, 0);
  else
    v41 = 0;
  if ( HIBYTE(creatureInfo->creature_flags) & 4 )
    v41 = 0;
  sprintf(buf, byte_4EF4EC);
  v48 = 0;
  sprintf(globBuf, "%s%d", off_4F64E0[0], creatureInfo->attack);
  strcat(buf, globBuf);
  if ( a10 )
  {
    v14 = Hero::getPrimarySkill(a10, 0);
    v48 += v14;
  }
  if ( a11 )
    v48 = *(_BYTE *)(a11 + 198) - creatureInfo->attack;
  if ( v48 )
  {
    sprintf(globBuf, " (%d)", v48 + creatureInfo->attack);
    strcat(buf, globBuf);
  }
  v48 = 0;
  sprintf(globBuf, "\n%s%d", off_4F64E4[0], creatureInfo->defense);
  strcat(buf, globBuf);
  if ( a10 )
  {
    v15 = Hero::getPrimarySkill(a10, PRIMARY_SKILL_DEFENSE);
    v48 += v15;
  }
  if ( a11 )
    v48 = *(_BYTE *)(a11 + 199) - creatureInfo->defense;
  if ( v48 )
  {
    sprintf(globBuf, " (%d)", v48 + creatureInfo->defense);
    strcat(buf, globBuf);
  }
  if ( creatureInfo->creature_flags & 4 )
  {
    v29 = *(_BYTE *)(v35 + 16);
    if ( v29 > 0 )
    {
      if ( combatManager->ready == 1 )
        sprintf(globBuf, "\n%s%d", off_4F64E8[0], v29);
      else
        sprintf(globBuf, "\n%s%d", off_4F6500, v29);
      strcat(buf, globBuf);
    }
  }
  sprintf(globBuf, "\n%s%d", off_4F64EC[0], creatureInfo->min_damage);
  strcat(buf, globBuf);
  if ( creatureInfo->min_damage != creatureInfo->max_damage )
  {
    sprintf(globBuf, "-%d", creatureInfo->max_damage);
    strcat(buf, globBuf);
  }
  sprintf(globBuf, "\n%s%d", off_4F64F0[0], creatureInfo->hp);
  strcat(buf, globBuf);
  if ( combatManager->ready == 1 )
  {
    sprintf(globBuf, "\n%s%d", "Hit Points Left: ", creatureInfo->hp - *(_DWORD *)(a11 + 162));
    strcat(buf, globBuf);
  }
  sprintf(globBuf, "\n%s%s", off_4F64F4[0], *(&off_4F64B8 + *(_BYTE *)(v35 + 11)));
  strcat(buf, globBuf);
  sprintf(globBuf, "\n%s%s", off_4F64F8[0], off_4F629C[v41]);
  strcat(buf, globBuf);
  v42 = computeLuck(a10, (CreatureStack *)a11, (Castle *)a6);
  sprintf(globBuf, "\n%s%s", off_4F64FC[0], off_4F627C[v42]);
  strcat(buf, globBuf);
  v32 = 4;
  v33 = buf;
  GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  if ( !dword_522F80 )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 500;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a7 )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 30723;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a9 )
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 30720;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  }
  if ( a5 >= 1 )
  {
    sprintf(&v28, "%d", a5);
    v31 = 3;
    v32 = 2;
    v33 = &v28;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
  }
  else
  {
    v31 = 6;
    v33 = (char *)6;
    v32 = 1;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
    v32 = 2;
    GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[612], (Event *)&evt);
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
      v20 = (GUIIcon *)operator new(0x2Du);
      if ( v20 )
        v26 = (AbstractGUIComponent *)GUIIcon_constructor(
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
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)&thisa->_10[612], v26, -1);
    }
  }
  animationFrameSwitchTime = getTickCount() + 90;
  *(_DWORD *)&thisa->_10[616] = 0;
  if ( a9 )
  {
    HeroWindowManager::addWindow(HeroWindowManager::instance, *(GUIWindow **)&thisa->_10[612], -1, 1);
    waitForMouseRelease();
    HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)&thisa->_10[612]);
  }
  else
  {
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      *(GUIWindow **)&thisa->_10[612],
      (int (__fastcall *)(InputEvent *))stackInfoWindowCallback,
      0);
    if ( dword_522FCC && a12 )
    {
      a12->creatureTypes[a13] = -1;
      a12->quantities[a13] = 0;
    }
    if ( dword_522C3C && a12 )
      a12->creatureTypes[a13] = stackWindowDisplayedCreature;
  }
  KBFree(buf, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF4B0 + 356);
  return operator delete(*(void **)&thisa->_10[612]);
}
