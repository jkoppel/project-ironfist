{
  const char *v2; // eax@19
  tag_monsterInfo *v3; // esi@24
  townManager *thisa; // [sp+Ch] [bp-A4h]@1
  int v5; // [sp+10h] [bp-A0h]@27
  tag_monsterInfo v6; // [sp+14h] [bp-9Ch]@24
  GUIMessage evt; // [sp+30h] [bp-80h]@11
  char v8; // [sp+4Ch] [bp-64h]@24
  __int16 v9; // [sp+74h] [bp-3Ch]@1
  int v10; // [sp+78h] [bp-38h]@20
  int i; // [sp+7Ch] [bp-34h]@1
  char v12; // [sp+80h] [bp-30h]@11
  __int16 v13; // [sp+90h] [bp-20h]@1
  __int16 v14; // [sp+94h] [bp-1Ch]@1
  char dwellingOffsetsForTier[8]; // [sp+98h] [bp-18h]@5
  __int16 v16; // [sp+A0h] [bp-10h]@1
  __int16 v17; // [sp+A4h] [bp-Ch]@1
  __int16 v18; // [sp+A8h] [bp-8h]@1
  __int16 v19; // [sp+ACh] [bp-4h]@1

  thisa = this;
  v14 = 1;
  v9 = 7;
  v13 = 13;
  v17 = 19;
  v16 = 25;
  v18 = 31;
  v19 = 37;
  for ( i = 0; i < 6; ++i )
  {
    if ( i == 5 && BYTE3(this->castle->buildingsBuiltFlags) & 0x40 )
    {
      dwellingOffsetsForTier[i] = 11;
    }
    else if ( i >= 1 && (1 << (i + 24)) & this->castle->buildingsBuiltFlags )
    {
      dwellingOffsetsForTier[i] = i + 5;
    }
    else
    {
      dwellingOffsetsForTier[i] = i;
    }
  }
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_ICON;
  sprintf(&v12, "cstl%s.icn", cHeroTypeShortName[this->castle->factionID]);
  evt.payload = &v12;
  for ( i = 0; i < 6; ++i )
  {
    evt.fieldID = i + 1;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  for ( i = 0; i < 6; ++i )
  {
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = i + 1;
    evt.payload = (void *)((unsigned __int8)dwellingOffsetsForTier[i] + 19);
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    sprintf(gText, "monh%04d.icn", gDwellingType[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]);
    evt.messageType = 9;
    evt.fieldID = i + 13;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  for ( i = 0; i < 6; ++i )
  {
    v2 = GetBuildingName(thisa->castle->factionID, (unsigned __int8)dwellingOffsetsForTier[i] + 19);
    sprintf(gText, v2);
    evt.fieldID = i + 7;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    if ( (1 << (dwellingOffsetsForTier[i] + 19)) & thisa->castle->buildingsBuiltFlags )
    {
      v10 = thisa->castle->numCreaturesInDwelling[(unsigned __int8)dwellingOffsetsForTier[i]];
      sprintf(gText, "Available:");
      evt.fieldID = i + 31;
      evt.payload = gText;
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      sprintf(gText, "%d", v10);
      evt.fieldID = i + 37;
      evt.payload = gText;
      heroWindow::BroadcastMessage(window, (Event *)&evt);
    }
    evt.fieldID = i + 19;
    strcpy(gText, gArmyNamesPlural[gDwellingType[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]]);
    gText[0] -= 32;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  for ( i = 0; i < 6; ++i )
  {
    v3 = &gMonsterDatabase[gDwellingType[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]];
    memcpy(&v6, v3, 0x18u);
    v6._ = v3->_;
    strcpy(gText, byte_4EF150);
    sprintf(&v8, "%s%d", cWellDetail[0], v6.attack);
    strcat(gText, &v8);
    sprintf(&v8, "\n%s%d", off_4F650C[0], v6.defense);
    strcat(gText, &v8);
    sprintf(&v8, "\n%s%d", off_4F6514[0], v6.min_damage);
    strcat(gText, &v8);
    if ( v6.min_damage != v6.max_damage )
    {
      sprintf(&v8, "-%d", v6.max_damage);
      strcat(gText, &v8);
    }
    sprintf(&v8, "\n%s%d", off_4F6518[0], (unsigned __int16)v6.hp);
    strcat(gText, &v8);
    sprintf(&v8, off_4F6524, speedText[v6.speed]);
    strcat(gText, &v8);
    if ( (1 << (dwellingOffsetsForTier[i] + 19)) & thisa->castle->buildingsBuiltFlags )
    {
      v5 = gMonsterDatabase[gDwellingType[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]].growth
         + 2;
      if ( !i && BYTE1(thisa->castle->buildingsBuiltFlags) & 8 )
        v5 = gMonsterDatabase[gDwellingType[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]].growth
           + 10;
      sprintf(&v8, off_4F6528, v5);
      strcat(gText, &v8);
    }
    evt.messageType = 3;
    evt.fieldID = i + 25;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
}