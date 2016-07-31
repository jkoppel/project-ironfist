{
  void *thisa; // [sp+14h] [bp-70h]@1
  InputEvent a2a; // [sp+18h] [bp-6Ch]@32
  void *v14; // [sp+34h] [bp-50h]@20
  void *a1; // [sp+38h] [bp-4Ch]@20
  void *v16; // [sp+3Ch] [bp-48h]@20
  void *v17; // [sp+40h] [bp-44h]@20
  void *v18; // [sp+44h] [bp-40h]@20
  int v19; // [sp+48h] [bp-3Ch]@18
  char v20; // [sp+4Ch] [bp-38h]@20
  char v21; // [sp+50h] [bp-34h]@32
  char v22; // [sp+6Ch] [bp-18h]@20
  int v23; // [sp+70h] [bp-14h]@13
  int v24; // [sp+74h] [bp-10h]@7
  int v25; // [sp+78h] [bp-Ch]@13
  int v26; // [sp+80h] [bp-4h]@4

  thisa = this;
  if ( debugLogLevel == 4 )
    return sub_4946E0(this, a2, a3, (int)a4, a5, a6, (int)a7, a8, a9, a10, a11);
  dword_4F7474 = 1;
  if ( a3 )
    v26 = *(_BYTE *)(a3 + 3);
  else
    v26 = -1;
  if ( a6 )
  {
    v24 = *(_BYTE *)(a6 + 3);
  }
  else
  {
    if ( a5 )
      v24 = *(_BYTE *)(a5 + 1);
    else
      v24 = -1;
  }
  if ( a10 == -1 )
    a10 = unseededNextRand(1, 1000);
  sub_450880((AdvManager *)thisa);
  v25 = curPlayerIdx;
  v23 = dword_524C14;
  if ( v26 < 0 || v24 < 0 || !dword_524810[v24] )
    goto LABEL_36;
  if ( *(&byte_524758 + v24) )
  {
    if ( !*(&byte_524758 + v26) )
    {
      dword_524C14 = 1;
      sub_423E20();
      sprintf(
        globBuf,
        "%s's %s is under attack!",
        &dword_5235E0[21 * v24],
        &aTown_1[("Hero" - "Town") & ((a5 != 0) - 1)]);
      sub_4295B0((int)globBuf, v24);
    }
    goto LABEL_36;
  }
  dword_523430 = dword_523F14;
  dword_523434 = *((_BYTE *)&byte_5247A0 + v24);
  sub_493F00(a2, SBYTE4(a2), a3, a4, (const void *)a5, a6, a7, a8, a9, a10, *((_BYTE *)&byte_5247A0 + v24), 0, 0, 0);
  if ( dword_524810[v26] )
  {
LABEL_36:
    dword_524C14 = 1;
    sub_474730(combatManager, a2, a3, (int)a4, a5, a6, (int)a7, a2, SHIDWORD(a2), a10);
    if ( dword_4F74AC <= 2900 )
    {
      if ( dword_4F74AC > 900 )
        dword_4F7490 = 1;
    }
    else
    {
      dword_4F7490 = 2;
    }
    ManagerManager::switchToManager(managerManager, (AbstractManager *)combatManager);
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
    dword_4F7490 = 0;
    goto LABEL_41;
  }
  while ( 1 )
  {
    yieldToGlobalUpdater();
    sub_4D6A50(HeroWindowManager::instance->screenBuffer, 30, 30, 4u, 4, 0);
    v19 = sub_455D20(thisa);
    if ( v19 )
    {
      if ( *(_BYTE *)(v19 + 6) == 21 )
        break;
    }
    passOnMessages();
    memcpy(&v21, InputManager::nextInputEvent(inputManager, &a2a), 0x1Cu);
    sub_455F30(thisa, (int)&v21, 1);
  }
  sub_494270(
    v19,
    (int)&v20,
    (int)&a2,
    (int)((char *)&a2 + 4),
    &v17,
    &a1,
    &v18,
    &v16,
    &v14,
    (int)&a8,
    (int)&a9,
    (int)&a10,
    (int)&v22,
    (int)&isRetreating,
    (int)&isSurrendering);
  if ( a1 )
  {
    memcpy((void *)a4, a1, 0xFu);
    KBFree(a1, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 113);
  }
  if ( v14 )
  {
    memcpy((void *)a7, v14, 0xFu);
    KBFree(v14, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 119);
  }
  if ( v18 )
  {
    memcpy((void *)a5, v18, 0x64u);
    KBFree(v18, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 125);
  }
  if ( v16 )
  {
    memcpy((void *)a6, v16, 0xFAu);
    KBFree(v16, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 131);
  }
  if ( v17 )
  {
    memcpy((void *)a3, v17, 0xFAu);
    KBFree(v17, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 137);
  }
  combatManager->winningSide = v22;
LABEL_41:
  if ( a3 )
    Hero::checkForLevelUp((Hero *)a3);
  if ( a6 )
    Hero::checkForLevelUp((Hero *)a6);
  if ( a11 )
  {
    switch ( combatManager->winningSide + 1 )
    {
      case 1:
        if ( !isRetreating )
          sub_48F450(a6, a3);
        sub_48F630((int)thisa, a6);
        break;
      case 2:
        if ( !isRetreating )
          sub_48F450(a3, a6);
        sub_48F630((int)thisa, a3);
        break;
      case 0:
        sub_48F630((int)thisa, a3);
        sub_48F630((int)thisa, a6);
        break;
      case 4:
        break;
    }
  }
  dword_524C14 = v23;
  curPlayerIdx = v25;
  if ( dword_524810[v25] )
  {
    sub_485C90(1);
  }
  else
  {
    sub_429420();
    sub_423DE0();
    sub_485C90(0);
  }
  sub_450820((int)thisa, 0);
  if ( a11 )
    isRetreating = 0;
  dword_4F7474 = 0;
  while ( mouseManager->cursorDisabled )
    MouseManager::enableCursor(mouseManager);
  return combatManager->winningSide;
}
