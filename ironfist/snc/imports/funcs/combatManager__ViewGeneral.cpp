{
  int result; // eax@2
  int v5; // ST40_4@19
  int v6; // ST3C_4@19
  char *v7; // ST38_4@19
  char *v8; // ST34_4@19
  char *v9; // ST30_4@19
  char *v10; // ST2C_4@19
  char *v11; // ST28_4@19
  int v12; // ST24_4@19
  char *v13; // ST20_4@19
  int v14; // ST1C_4@19
  char *v15; // ST18_4@19
  int v16; // ST14_4@19
  char *v17; // ST10_4@19
  char v18; // al@19
  combatManager *v19; // [sp+Ch] [bp-78h]@1
  heroWindow *thisa; // [sp+18h] [bp-6Ch]@3
  tag_message evt; // [sp+20h] [bp-64h]@3
  __int16 v22; // [sp+3Ch] [bp-48h]@3
  heroWindow *a2a; // [sp+40h] [bp-44h]@4
  __int16 v24; // [sp+48h] [bp-3Ch]@3
  __int16 v25; // [sp+4Ch] [bp-38h]@3
  __int16 v26; // [sp+50h] [bp-34h]@3
  __int16 v27; // [sp+54h] [bp-30h]@3
  __int16 v28; // [sp+58h] [bp-2Ch]@3
  __int16 v29; // [sp+5Ch] [bp-28h]@3
  int v30; // [sp+60h] [bp-24h]@19
  int v31; // [sp+64h] [bp-20h]@19
  __int16 v32; // [sp+68h] [bp-1Ch]@3
  __int16 v33; // [sp+6Ch] [bp-18h]@3
  __int16 v34; // [sp+70h] [bp-14h]@3
  __int16 v35; // [sp+74h] [bp-10h]@3
  __int16 v36; // [sp+78h] [bp-Ch]@3
  __int16 v37; // [sp+7Ch] [bp-8h]@3
  __int16 v38; // [sp+80h] [bp-4h]@3

  v19 = this;
  if ( this->heroes[a2] )
  {
    iViewGeneralWhichSide = a2;
    v27 = 1;
    v32 = 2;
    v24 = 3;
    v37 = 4;
    v29 = 30;
    v25 = 0;
    v38 = 7;
    v34 = 8;
    v22 = 9;
    v26 = 10;
    v36 = 11;
    v33 = 12;
    v35 = 13;
    v28 = 14;
    giCurGeneral = a2;
    evt.eventCode = 512;
    thisa = (heroWindow *)operator new(68);
    if ( thisa )
      a2a = heroWindow::heroWindow(thisa, 179, 60, "vgenwin.bin");
    else
      a2a = 0;
    if ( !a2a )
      MemError();
    sprintf(gText, "port%04d.icn", v19->heroes[a2]->heroID);
    evt.xCoordOrKeycode = 9;
    evt.yCoord = 2;
    evt.payload = gText;
    heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    if ( v19->heroes[a2]->field_E7[0] )
      evt.xCoordOrKeycode = 5;
    else
      evt.xCoordOrKeycode = 6;
    evt.yCoord = 30;
    evt.payload = (void *)4;
    heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    if ( v19->heroes[a2]->field_E7[0] )
    {
      evt.xCoordOrKeycode = 4;
      if ( v19->playerID[a2] == -1 )
        evt.payload = (void *)6;
      else
        evt.payload = (void *)gpGame->players[v19->playerID[a2]].color;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    }
    evt.xCoordOrKeycode = 4;
    evt.yCoord = 3;
    evt.payload = (void *)(gpGame->players[v19->heroes[a2]->probablyOwnerIdx].color + 1);
    heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    if ( v19->heroes[a2]->field_E7[0] )
      sprintf(gText, "Captain");
    else
      sprintf(gText, "%s the %s", v19->heroes[a2]->name, (&gAlignmentNames)[4 * v19->heroes[a2]->factionID]);
    evt.xCoordOrKeycode = 3;
    evt.yCoord = 1;
    evt.payload = gText;
    heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    v30 = armyGroup::GetMorale(
            (armyGroup *)((char *)&v19->heroes[a2 + 25] + 1),
            v19->heroes[a2],
            v19->castles[a2],
            gpCombatManager->armies[1 - a2]->creatureTypes);
    v31 = game::GetLuck(v19->heroes[a2], 0, v19->castles[a2]);
    v5 = 10 * hero::Stats(v19->heroes[a2], PRIMARY_SKILL_KNOWLEDGE);
    v6 = v19->heroes[a2]->spellpoints;
    v7 = off_4F6578;
    v8 = off_4F627C[v31];
    v9 = off_4F6574[0];
    v10 = off_4F629C[v30];
    v11 = off_4F6570[0];
    v12 = hero::Stats(v19->heroes[a2], PRIMARY_SKILL_KNOWLEDGE);
    v13 = off_4F656C[0];
    v14 = hero::Stats(v19->heroes[a2], PRIMARY_SKILL_SPELLPOWER);
    v15 = off_4F6568[0];
    v16 = hero::Stats(v19->heroes[a2], PRIMARY_SKILL_DEFENSE);
    v17 = off_4F6564[0];
    v18 = hero::Stats(v19->heroes[a2], 0);
    sprintf(
      gText,
      "\n%s%d\n%s%d\n%s%d\n%s%d\n%s%s\n%s%s\n\n%s%d/%d",
      off_4F6560[0],
      v18,
      v17,
      v16,
      v15,
      v14,
      v13,
      v12,
      v11,
      v10,
      v9,
      v8,
      v7,
      v6,
      v5);
    evt.xCoordOrKeycode = 3;
    evt.yCoord = 4;
    evt.payload = gText;
    heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    if ( !v19->heroes[a2]
      || !a3
      || !hero::HasArtifact(v19->heroes[a2], ARTIFACT_MAGIC_BOOK)
      || *(&v19->field_353F + a2)
      || v19->currentActionSide != giCurGeneral )
    {
      evt.xCoordOrKeycode = 6;
      evt.yCoord = 10;
      evt.payload = (void *)2;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4096;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    }
    if ( !a3
      || !v19->heroes[1 - v19->currentActionSide]
      || v19->currentActionSide != giCurGeneral
      || v19->heroes[a2]->field_E7[0] )
    {
      evt.xCoordOrKeycode = 6;
      evt.yCoord = 12;
      evt.payload = (void *)2;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4096;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    }
    if ( !a3
      || v19->currentActionSide != giCurGeneral
      || giCurGeneral == 1 && v19->castles[1]
      || v19->field_F377[0]
      || v19->field_F377[1]
      || v19->heroes[a2]->field_E7[0] )
    {
      evt.xCoordOrKeycode = 6;
      evt.yCoord = 11;
      evt.payload = (void *)2;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4096;
      heroWindow::BroadcastMessage(a2a, (Event *)&evt);
    }
    if ( a4 )
    {
      heroWindowManager::AddWindow(gpWindowManager, a2a, -1, 1);
      QuickViewWait();
      heroWindowManager::RemoveWindow(gpWindowManager, a2a);
    }
    else
    {
      heroWindowManager::DoDialog(gpWindowManager, a2a, (int (__fastcall *)(tag_message *))HandleViewGeneral, 0);
    }
    operator delete(a2a);
    combatManager::DrawFrame(v19, 1, 0, 0, 0, 75, 1, 1);
    if ( !a4 )
      combatManager::DoCommand((int)v19, gpWindowManager->buttonPressedCode);
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}