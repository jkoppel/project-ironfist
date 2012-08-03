{
  int v2; // [sp+Ch] [bp-84h]@58
  void *v3; // [sp+18h] [bp-78h]@1
  char v4; // [sp+1Ch] [bp-74h]@58
  char *v5; // [sp+20h] [bp-70h]@20
  int evt; // [sp+24h] [bp-6Ch]@1
  int v7; // [sp+28h] [bp-68h]@10
  int v8; // [sp+2Ch] [bp-64h]@10
  int v9; // [sp+3Ch] [bp-54h]@4
  char a1; // [sp+40h] [bp-50h]@52
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
    else if ( *((_BYTE *)v3 + i + 20) )
    {
      v9 = 0;
    }
    else
    {
      v9 = 2;
    }
    if ( *(_DWORD *)((char *)v3 + 67) == i )
      v9 += 3 * *(_DWORD *)v3 + 3;
    v7 = 4;
    v8 = i + 850;
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  v7 = 9;
  v8 = 809;
  v9 = (int)gText;
  sprintf(gText, "x_track%d.icn", *(_DWORD *)v3 + 1);
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  v7 = 3;
  v9 = (int)gText;
  v8 = 801;
  sprintf(gText, "%d", *(_DWORD *)((char *)v3 + 67) + 1);
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 802;
  sprintf(gText, "%s", (&xScenarioName[8 * *(_DWORD *)v3])[4 * *(_DWORD *)((char *)v3 + 67)]);
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 803;
  sprintf(gText, "%s", (&xScenarioDescription[8 * *(_DWORD *)v3])[4 * *(_DWORD *)((char *)v3 + 67)]);
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  v8 = 804;
  sprintf(gText, "%d", *((_WORD *)v3 + *(_DWORD *)((char *)v3 + 67) + 14));
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  v11 = 0;
  v8 = 805;
  strcpy(gText, byte_512CE8);
  for ( i = 0; i < 11; ++i )
  {
    if ( *((_BYTE *)v3 + i + 44) )
    {
      v11 = 1;
      strcat(gText, (&xCampaignAwards)[4 * i]);
      strcat(gText, L"\n");
    }
  }
  if ( !v11 )
    sprintf(gText, "None");
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    v5 = (char *)&xCampaignChoices + 120 * *(_DWORD *)v3 + 15 * *(_DWORD *)((char *)v3 + 67) + 5 * i;
    switch ( *v5 )
    {
      case 0:
        sprintf(gText, "%d %s", *(_WORD *)(v5 + 3), gResourceNames[*(_WORD *)(v5 + 1)]);
        break;
      case 1:
        switch ( *(_WORD *)(v5 + 1) )
        {
          case 26:
            strcpy(gText, "Minor Scroll");
            break;
          case 10:
            strcpy(gText, "Mage's Ring");
            break;
          case 19:
            strcpy(gText, "Defender Helm");
            break;
          case 24:
            strcpy(gText, "Power Axe");
            break;
          case 23:
            strcpy(gText, "Dragon Sword");
            break;
          case 25:
            strcpy(gText, "Breastplate");
            break;
          case 16:
            strcpy(gText, "Fizbin Medal");
            break;
          case 17:
            strcpy(gText, "Thunder Mace");
            break;
          case 18:
            strcpy(gText, "Gauntlets");
            break;
          case 27:
            strcpy(gText, "Major Scroll");
            break;
          case 29:
            strcpy(gText, "Foremost Scroll");
            break;
          case 21:
            strcpy(gText, "Ballista");
            break;
          case 22:
            strcpy(gText, "Stealth Shield");
            break;
          case 33:
            strcpy(gText, "Nomad Boots");
            break;
          case 34:
            strcpy(gText, "Traveler's Boots");
            break;
          default:
            sprintf(gText, "%s", gArtifactNames[*(_WORD *)(v5 + 1)]);
            break;
        }
        break;
      case 2:
        if ( *(_WORD *)(v5 + 1) == 43 )
          sprintf(gText, "Summon Earth");
        else
          sprintf(gText, "%s", gSpellNames[*(_WORD *)(v5 + 1)]);
        break;
      case 3:
        if ( (*(_WORD *)(v5 + 3) != 1 || *(_WORD *)(v5 + 1) != 12)
          && (*(_WORD *)(v5 + 3) != 2 || *(_WORD *)(v5 + 1) != 2) )
          sprintf(gText, "%s %s", secondarySkillLevels[*(_WORD *)(v5 + 3)], gSecondarySkills[*(_WORD *)(v5 + 1)]);
        else
          sprintf(gText, "%s %s", off_51A904[*(_WORD *)(v5 + 3)], gSecondarySkills[*(_WORD *)(v5 + 1)]);
        break;
      case 4:
        strcpy(&a1, gArmyNamesPlural[*(_WORD *)(v5 + 1)]);
        a1 -= 32;
        sprintf(gText, "%d %s", *(_WORD *)(v5 + 3), &a1);
        break;
      case 5:
        sprintf(gText, "%d %s", *(_WORD *)(v5 + 1), "Puzzle Pieces");
        break;
      case 6:
        sprintf(gText, "%d %s", *(_WORD *)(v5 + 1), "Experience");
        break;
      case 7:
        sprintf(gText, "n/a");
        break;
      case 8:
        sprintf(gText, (&gAlignmentNames)[4 * *(_WORD *)(v5 + 1)]);
        break;
      case 9:
        sprintf(gText, "%s +%d", gStatNames[*(_WORD *)(v5 + 1)], *(_WORD *)(v5 + 3));
        break;
      case 0xA:
        v4 = 1;
        v2 = *(_WORD *)(v5 + 1);
        if ( v2 == 34 || v2 == 39 )
          v4 = 0;
        if ( v4 )
          sprintf(gText, "%s %s", gSpellNames[*(_WORD *)(v5 + 1)], "Scroll");
        else
          sprintf(gText, "%s", gSpellNames[*(_WORD *)(v5 + 1)]);
        break;
      default:
        break;
    }
    v8 = i + 806;
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  for ( i = 0; i < 3; ++i )
  {
    v8 = i + 810;
    v7 = 4;
    if ( *(_DWORD *)((char *)v3 + 75) || !*((_BYTE *)v3 + *(_DWORD *)((char *)v3 + 67) + 12) )
      v9 = 9;
    else
      v9 = 8;
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
    if ( *((_BYTE *)v3 + *(_DWORD *)((char *)v3 + 67) + 55) == i )
      v7 = 5;
    else
      v7 = 6;
    v9 = 4;
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 71), (Event *)&evt);
  }
  if ( a2 )
    heroWindow::DrawWindow(*(heroWindow **)((char *)v3 + 71));
}