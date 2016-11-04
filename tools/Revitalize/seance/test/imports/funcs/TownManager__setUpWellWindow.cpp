{
  const char *v2; // eax@19
  creatureStats *v3; // esi@24
  TownManager *thisa; // [sp+Ch] [bp-A4h]@1
  int v5; // [sp+10h] [bp-A0h]@27
  char v6; // [sp+14h] [bp-9Ch]@24
  int v7; // [sp+1Ch] [bp-94h]@26
  char v8; // [sp+20h] [bp-90h]@24
  char v9; // [sp+21h] [bp-8Fh]@24
  char v10; // [sp+22h] [bp-8Eh]@24
  char v11; // [sp+23h] [bp-8Dh]@24
  __int16 v12; // [sp+2Ch] [bp-84h]@24
  GUIMessage evt; // [sp+30h] [bp-80h]@11
  char v14; // [sp+4Ch] [bp-64h]@24
  __int16 v15; // [sp+74h] [bp-3Ch]@1
  int v16; // [sp+78h] [bp-38h]@20
  int i; // [sp+7Ch] [bp-34h]@1
  char v18; // [sp+80h] [bp-30h]@11
  __int16 v19; // [sp+90h] [bp-20h]@1
  __int16 v20; // [sp+94h] [bp-1Ch]@1
  char dwellingOffsetsForTier[8]; // [sp+98h] [bp-18h]@5
  __int16 v22; // [sp+A0h] [bp-10h]@1
  __int16 v23; // [sp+A4h] [bp-Ch]@1
  __int16 v24; // [sp+A8h] [bp-8h]@1
  __int16 v25; // [sp+ACh] [bp-4h]@1

  thisa = this;
  v20 = 1;
  v15 = 7;
  v19 = 13;
  v23 = 19;
  v22 = 25;
  v24 = 31;
  v25 = 37;
  for ( i = 0; i < 6; ++i )
  {
    if ( i == 5 && BYTE3(this->castle->buildingsBuiltFlags) & 0x40 )
    {
      dwellingOffsetsForTier[i] = 11;
    }
    else
    {
      if ( i >= 1 && (1 << (i + 24)) & this->castle->buildingsBuiltFlags )
        dwellingOffsetsForTier[i] = i + 5;
      else
        dwellingOffsetsForTier[i] = i;
    }
  }
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_ICON;
  sprintf(&v18, "cstl%s.icn", faction_short_names[this->castle->factionID]);
  evt.payload = &v18;
  for ( i = 0; i < 6; ++i )
  {
    evt.fieldID = i + 1;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  for ( i = 0; i < 6; ++i )
  {
    evt.messageType = GUI_MESSAGE_SET_IMG_IDX;
    evt.fieldID = i + 1;
    evt.payload = (void *)((unsigned __int8)dwellingOffsetsForTier[i] + 19);
    GUIWindow::processMessage(window, (Event *)&evt);
    sprintf(
      globBuf,
      "monh%04d.icn",
      dwelling_creatures[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]);
    evt.messageType = 9;
    evt.fieldID = i + 13;
    evt.payload = globBuf;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  for ( i = 0; i < 6; ++i )
  {
    v2 = buildingName(thisa->castle->factionID, (unsigned __int8)dwellingOffsetsForTier[i] + 19);
    sprintf(globBuf, v2);
    evt.fieldID = i + 7;
    evt.payload = globBuf;
    GUIWindow::processMessage(window, (Event *)&evt);
    if ( (1 << (dwellingOffsetsForTier[i] + 19)) & thisa->castle->buildingsBuiltFlags )
    {
      v16 = thisa->castle->numCreaturesInDwelling[(unsigned __int8)dwellingOffsetsForTier[i]];
      sprintf(globBuf, "Available:");
      evt.fieldID = i + 31;
      evt.payload = globBuf;
      GUIWindow::processMessage(window, (Event *)&evt);
      sprintf(globBuf, "%d", v16);
      evt.fieldID = i + 37;
      evt.payload = globBuf;
      GUIWindow::processMessage(window, (Event *)&evt);
    }
    evt.fieldID = i + 19;
    strcpy(
      globBuf,
      creaturePluralNames[dwelling_creatures[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]]);
    globBuf[0] -= 32;
    evt.payload = globBuf;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  for ( i = 0; i < 6; ++i )
  {
    v3 = &creature_table[dwelling_creatures[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]];
    memcpy(&v6, v3, 0x18u);
    v12 = v3->_;
    strcpy(globBuf, byte_4EF150);
    sprintf(&v14, "%s%d", off_4F6508[0], v8);
    strcat(globBuf, &v14);
    sprintf(&v14, "\n%s%d", off_4F650C[0], v9);
    strcat(globBuf, &v14);
    sprintf(&v14, "\n%s%d", off_4F6514[0], v10);
    strcat(globBuf, &v14);
    if ( v10 != v11 )
    {
      sprintf(&v14, "-%d", v11);
      strcat(globBuf, &v14);
    }
    sprintf(&v14, "\n%s%d", off_4F6518[0], (unsigned __int16)v7);
    strcat(globBuf, &v14);
    sprintf(&v14, off_4F6524, *(&off_4F64B8 + SBYTE3(v7)));
    strcat(globBuf, &v14);
    if ( (1 << (dwellingOffsetsForTier[i] + 19)) & thisa->castle->buildingsBuiltFlags )
    {
      v5 = creature_table[dwelling_creatures[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]].growth
         + 2;
      if ( !i && BYTE1(thisa->castle->buildingsBuiltFlags) & 8 )
        v5 = creature_table[dwelling_creatures[thisa->castle->factionID][(unsigned __int8)dwellingOffsetsForTier[i]]].growth
           + 10;
      sprintf(&v14, off_4F6528, v5);
      strcat(globBuf, &v14);
    }
    evt.messageType = 3;
    evt.fieldID = i + 25;
    evt.payload = globBuf;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
}
