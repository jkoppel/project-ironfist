{
  int v2; // ebx@16
  __int64 v3; // ST10_8@21
  void *v4; // [sp+Ch] [bp-40h]@1
  GUIWindow *thisa; // [sp+18h] [bp-34h]@6
  signed int v6; // [sp+1Ch] [bp-30h]@1
  int evt; // [sp+20h] [bp-2Ch]@9
  int v8; // [sp+24h] [bp-28h]@9
  int v9; // [sp+28h] [bp-24h]@9
  char *v10; // [sp+38h] [bp-14h]@9
  int i; // [sp+3Ch] [bp-10h]@9
  int v12; // [sp+40h] [bp-Ch]@1
  int v13; // [sp+44h] [bp-8h]@16
  int v14; // [sp+48h] [bp-4h]@1

  v4 = this;
  v6 = 1000;
  v12 = -1;
  v14 = (int)&gameObject->heroes[curPlayer->_1[0]];
  if ( !curPlayer->numCastles )
  {
    display_message_window("No available town.  Spell Failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    return;
  }
  if ( *(_BYTE *)(v14 + 227) & 0x80 )
  {
    display_message_window(
      "Spell Failed!!!  You must be on land for this spell to work.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    return;
  }
  if ( a2 != 58 )
  {
    for ( i = 0; curPlayer->numCastles > i; ++i )
    {
      v2 = abs(gameObject->castles[curPlayer->castlesOwned[i]].field_4 - *(_DWORD *)(v14 + 25));
      v13 = abs(gameObject->castles[curPlayer->castlesOwned[i]].field_5 - *(_DWORD *)(v14 + 29)) + v2;
      if ( v13 < v6 )
      {
        v6 = v13;
        v12 = i;
      }
    }
    goto LABEL_19;
  }
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    dword_524EA4 = GUIWindow_constructorFromFile(thisa, 159, 65, "townport.bin");
  else
    dword_524EA4 = 0;
  sprintf(globBuf, "{Town Portal}\n\nSelect town to port to.");
  evt = 512;
  v8 = 3;
  v9 = 1;
  v10 = globBuf;
  GUIWindow::processMessage(dword_524EA4, (Event *)&evt);
  for ( i = 0; curPlayer->numCastles > i; ++i )
  {
    sprintf(globBuf, gameObject->castles[curPlayer->castlesOwned[i]].name);
    evt = 512;
    v8 = 56;
    v9 = 100;
    v10 = globBuf;
    GUIWindow::processMessage(dword_524EA4, (Event *)&evt);
  }
  v8 = 54;
  v10 = 0;
  GUIWindow::processMessage(dword_524EA4, (Event *)&evt);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_524EA4,
    (int (__fastcall *)(InputEvent *))sub_454030,
    0);
  v12 = dword_524D28;
  operator delete(dword_524EA4);
  if ( HeroWindowManager::instance->buttonPressedCode != 30721 )
  {
LABEL_19:
    if ( gameObject->castles[curPlayer->castlesOwned[v12]].visitingHeroIdx == -1 )
    {
      SoundManager::couldBePlayCDTrack(soundManager, 1);
      HIDWORD(v3) = gameObject->castles[curPlayer->castlesOwned[v12]].field_5;
      LODWORD(v3) = gameObject->castles[curPlayer->castlesOwned[v12]].field_4;
      sub_453A20(v4, v14, v3, 0, 0);
      Hero::spendSpellPointsFor((Hero *)v14, a2);
      gameObject->castles[curPlayer->castlesOwned[v12]].visitingHeroIdx = *(_BYTE *)(v14 + 2);
      Castle::grantHeroSpellsFromMageGuild(&gameObject->castles[curPlayer->castlesOwned[v12]], 0);
      *(_WORD *)(v14 + 45) = 163;
      *(_WORD *)(v14 + 47) = curPlayer->castlesOwned[v12];
      SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)((char *)v4 + 166)]);
    }
    else
    {
      display_message_window("Nearest town occupied.  Spell Failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
}
