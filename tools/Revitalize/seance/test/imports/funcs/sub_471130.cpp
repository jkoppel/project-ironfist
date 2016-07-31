{
  int v2; // [sp+Ch] [bp-84h]@58
  void *v3; // [sp+18h] [bp-78h]@1
  char v4; // [sp+1Ch] [bp-74h]@58
  char *v5; // [sp+20h] [bp-70h]@20
  int evt; // [sp+24h] [bp-6Ch]@1
  int v7; // [sp+28h] [bp-68h]@10
  int v8; // [sp+2Ch] [bp-64h]@10
  int v9; // [sp+3Ch] [bp-54h]@4
  char v10; // [sp+40h] [bp-50h]@52
  char v11; // [sp+74h] [bp-1Ch]@11
  int i; // [sp+78h] [bp-18h]@1

  v3 = this;
  evt = 512;
  for ( i = 0; *((_DWORD *)v3 + 2) > i; ++i )
  {
    if ( *((_BYTE *)v3 + i + 12) )
    {
      v9 = 1;
    }
    else
    {
      if ( *((_BYTE *)v3 + i + 20) )
        v9 = 0;
      else
        v9 = 2;
    }
    if ( *(_DWORD *)((char *)v3 + 67) == i )
      v9 += 3 * *(_DWORD *)v3 + 3;
    v7 = 4;
    v8 = i + 850;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  v7 = 9;
  v8 = 809;
  v9 = (int)globBuf;
  sprintf(globBuf, "x_track%d.icn", *(_DWORD *)v3 + 1);
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  v7 = 3;
  v9 = (int)globBuf;
  v8 = 801;
  sprintf(globBuf, "%d", *(_DWORD *)((char *)v3 + 67) + 1);
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 802;
  sprintf(globBuf, "%s", (&off_51A770[8 * *(_DWORD *)v3])[4 * *(_DWORD *)((char *)v3 + 67)]);
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 803;
  sprintf(globBuf, "%s", (&off_51A7F0[8 * *(_DWORD *)v3])[4 * *(_DWORD *)((char *)v3 + 67)]);
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 804;
  sprintf(globBuf, "%d", *((_WORD *)v3 + *(_DWORD *)((char *)v3 + 67) + 14));
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  v11 = 0;
  v8 = 805;
  strcpy(globBuf, byte_512CE8);
  for ( i = 0; i < 11; ++i )
  {
    if ( *((_BYTE *)v3 + i + 44) )
    {
      v11 = 1;
      strcat(globBuf, (&off_51A740)[4 * i]);
      strcat(globBuf, L"\n");
    }
  }
  if ( !v11 )
    sprintf(globBuf, "None");
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    v5 = (char *)&unk_512A40 + 120 * *(_DWORD *)v3 + 15 * *(_DWORD *)((char *)v3 + 67) + 5 * i;
    switch ( *v5 )
    {
      case 0:
        sprintf(globBuf, "%d %s", *(_WORD *)(v5 + 3), resourceNames[*(_WORD *)(v5 + 1)]);
        break;
      case 1:
        switch ( *(_WORD *)(v5 + 1) )
        {
          case 26:
            strcpy(globBuf, "Minor Scroll");
            break;
          case 10:
            strcpy(globBuf, "Mage's Ring");
            break;
          case 19:
            strcpy(globBuf, "Defender Helm");
            break;
          case 24:
            strcpy(globBuf, "Power Axe");
            break;
          case 23:
            strcpy(globBuf, "Dragon Sword");
            break;
          case 25:
            strcpy(globBuf, "Breastplate");
            break;
          case 16:
            strcpy(globBuf, "Fizbin Medal");
            break;
          case 17:
            strcpy(globBuf, "Thunder Mace");
            break;
          case 18:
            strcpy(globBuf, "Gauntlets");
            break;
          case 27:
            strcpy(globBuf, "Major Scroll");
            break;
          case 29:
            strcpy(globBuf, "Foremost Scroll");
            break;
          case 21:
            strcpy(globBuf, "Ballista");
            break;
          case 22:
            strcpy(globBuf, "Stealth Shield");
            break;
          case 33:
            strcpy(globBuf, "Nomad Boots");
            break;
          case 34:
            strcpy(globBuf, "Traveler's Boots");
            break;
          default:
            sprintf(globBuf, "%s", artifactNames[*(_WORD *)(v5 + 1)]);
            break;
        }
        break;
      case 2:
        if ( *(_WORD *)(v5 + 1) == 43 )
          sprintf(globBuf, "Summon Earth");
        else
          sprintf(globBuf, "%s", spell_names[*(_WORD *)(v5 + 1)]);
        break;
      case 3:
        if ( (*(_WORD *)(v5 + 3) != 1 || *(_WORD *)(v5 + 1) != 12)
          && (*(_WORD *)(v5 + 3) != 2 || *(_WORD *)(v5 + 1) != 2) )
          sprintf(globBuf, "%s %s", secondarySkillLevels[*(_WORD *)(v5 + 3)], secondary_skill_names[*(_WORD *)(v5 + 1)]);
        else
          sprintf(globBuf, "%s %s", off_51A904[*(_WORD *)(v5 + 3)], secondary_skill_names[*(_WORD *)(v5 + 1)]);
        break;
      case 4:
        strcpy(&v10, creaturePluralNames[*(_WORD *)(v5 + 1)]);
        v10 -= 32;
        sprintf(globBuf, "%d %s", *(_WORD *)(v5 + 3), &v10);
        break;
      case 5:
        sprintf(globBuf, "%d %s", *(_WORD *)(v5 + 1), "Puzzle Pieces");
        break;
      case 6:
        sprintf(globBuf, "%d %s", *(_WORD *)(v5 + 1), "Experience");
        break;
      case 7:
        sprintf(globBuf, "n/a");
        break;
      case 8:
        sprintf(globBuf, (&off_4F5AF8)[4 * *(_WORD *)(v5 + 1)]);
        break;
      case 9:
        sprintf(globBuf, "%s +%d", primarySkillNames[*(_WORD *)(v5 + 1)], *(_WORD *)(v5 + 3));
        break;
      case 0xA:
        v4 = 1;
        v2 = *(_WORD *)(v5 + 1);
        if ( v2 == 34 || v2 == 39 )
          v4 = 0;
        if ( v4 )
          sprintf(globBuf, "%s %s", spell_names[*(_WORD *)(v5 + 1)], "Scroll");
        else
          sprintf(globBuf, "%s", spell_names[*(_WORD *)(v5 + 1)]);
        break;
      default:
        break;
    }
    v8 = i + 806;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  for ( i = 0; i < 3; ++i )
  {
    v8 = i + 810;
    v7 = 4;
    if ( *(_DWORD *)((char *)v3 + 75) || !*((_BYTE *)v3 + *(_DWORD *)((char *)v3 + 67) + 12) )
      v9 = 9;
    else
      v9 = 8;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
    if ( *((_BYTE *)v3 + *(_DWORD *)((char *)v3 + 67) + 55) == i )
      v7 = 5;
    else
      v7 = 6;
    v9 = 4;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  if ( a2 )
    GUIWindow::repaintAndUpdateScreen(*(GUIWindow **)((char *)v3 + 71));
}
