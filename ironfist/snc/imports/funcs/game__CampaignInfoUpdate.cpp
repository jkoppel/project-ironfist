{
  void *v2; // [sp+14h] [bp-60h]@1
  unsigned __int8 v3; // [sp+18h] [bp-5Ch]@7
  char *v4; // [sp+1Ch] [bp-58h]@56
  int evt; // [sp+20h] [bp-54h]@1
  int v6; // [sp+24h] [bp-50h]@32
  int v7; // [sp+28h] [bp-4Ch]@32
  int v8; // [sp+38h] [bp-3Ch]@4
  char a1; // [sp+3Ch] [bp-38h]@81
  int i; // [sp+70h] [bp-4h]@1

  v2 = this;
  evt = 512;
  for ( i = 0; i < 13; ++i )
  {
    if ( *((_BYTE *)v2 + 12 * iCurViewSide + i + 162) )
    {
      v8 = 11;
    }
    else if ( i < 11 && (i < 4 ? (v3 = *((_BYTE *)v2 + 3)) : (v3 = *((_BYTE *)v2 + 2)), *((_BYTE *)v2 + 12 * v3 + i + 5)) )
    {
      v8 = 10;
    }
    else
    {
      v8 = 12;
    }
    if ( iCurViewMap == i )
    {
      if ( i != 4 || iCampaignTrackType != 1 )
      {
        if ( i != 4 || iCampaignTrackType != 2 )
        {
          if ( i + 1 <= 11 )
          {
            if ( i + 1 >= 5 )
            {
              if ( *((_BYTE *)v2 + 2) )
                v8 += 6;
              else
                v8 += 3;
            }
            else if ( *((_BYTE *)v2 + 3) )
            {
              v8 += 6;
            }
            else
            {
              v8 += 3;
            }
          }
          else if ( *((_BYTE *)v2 + 3) )
          {
            v8 += 3;
          }
          else
          {
            v8 += 6;
          }
        }
        else
        {
          v8 += 9;
        }
      }
      else
      {
        v8 += 12;
      }
    }
    v6 = 4;
    v7 = i + 850;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  }
  v6 = 9;
  v7 = 809;
  v8 = (int)gText;
  sprintf(gText, "ctrack%02d.icn", iCampaignTrackType);
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  v6 = 3;
  v8 = (int)gText;
  v7 = 801;
  if ( iCurViewMap == 11 )
    sprintf(gText, L"5");
  else
    sprintf(gText, "%d", iCurViewMap + 1);
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  v7 = 802;
  if ( iCurViewMap == 11 )
  {
    sprintf(gText, "%s", (&cCampaignName[12 * (1 - iCurViewSide)])[4 * iCurViewMap]);
  }
  else if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || iCurViewMap != 4 )
  {
    sprintf(gText, "%s", (&cCampaignName[12 * iCurViewSide])[4 * iCurViewMap]);
  }
  else
  {
    sprintf(gText, "%s", off_4F7134[12 * iCurViewSide]);
  }
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  v7 = 803;
  if ( iCurViewMap == 11 )
  {
    sprintf(gText, "%s", (&cCampaignDescription[12 * (1 - iCurViewSide)])[4 * iCurViewMap]);
  }
  else if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || iCurViewMap != 4 )
  {
    sprintf(gText, "%s", (&cCampaignDescription[12 * iCurViewSide])[4 * iCurViewMap]);
  }
  else
  {
    sprintf(gText, "%s", off_4F7194[12 * iCurViewSide]);
  }
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  v7 = 804;
  sprintf(gText, "%d", *(_WORD *)((char *)v2 + 24 * iCurViewSide + 2 * iCurViewMap + 29));
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  strcpy(gText, byte_51D1EC);
  for ( i = 0; i < 12; ++i )
  {
    if ( *((_BYTE *)v2 + i + 126) )
    {
      strcat(gText, (&cCampaignAwards)[4 * i]);
      strcat(gText, L"\n");
    }
  }
  v7 = 805;
  heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    if ( iCurViewMap == 11 )
    {
      v4 = (char *)&campaignChoices + 180 * (1 - iCurViewSide) + 15 * iCurViewMap + 5 * i;
    }
    else if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || iCurViewMap != 4 )
    {
      v4 = (char *)&campaignChoices + 180 * iCurViewSide + 15 * iCurViewMap + 5 * i;
    }
    else
    {
      v4 = (char *)&campaignChoices + 180 * iCurViewSide + 5 * i + 165;
    }
    switch ( *v4 )
    {
      case 0:
        sprintf(gText, "%d %s", *(_WORD *)(v4 + 3), gResourceNames[*(_WORD *)(v4 + 1)]);
        break;
      case 1:
        switch ( *(_WORD *)(v4 + 1) )
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
          default:
            sprintf(gText, "%s", gArtifactNames[*(_WORD *)(v4 + 1)]);
            break;
        }
        break;
      case 2:
        if ( *(_WORD *)(v4 + 1) == 43 )
          sprintf(gText, "Summon Earth");
        else
          sprintf(gText, "%s", gSpellNames[*(_WORD *)(v4 + 1)]);
        break;
      case 3:
        sprintf(gText, "%s %s", secondarySkillLevels[*(_WORD *)(v4 + 3)], gSecondarySkills[*(_WORD *)(v4 + 1)]);
        break;
      case 4:
        strcpy(&a1, gArmyNamesPlural[*(_WORD *)(v4 + 1)]);
        a1 -= 32;
        sprintf(gText, "%d %s", *(_WORD *)(v4 + 3), &a1);
        break;
      case 5:
        sprintf(gText, "%d %s", *(_WORD *)(v4 + 1), "Puzzle Pieces");
        break;
      case 6:
        sprintf(gText, "%d %s", *(_WORD *)(v4 + 1), "Experience");
        break;
      case 7:
        sprintf(gText, "n/a");
        break;
      case 8:
        sprintf(gText, (&gAlignmentNames)[4 * *(_WORD *)(v4 + 1)]);
        break;
      default:
        break;
    }
    v7 = i + 806;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  }
  for ( i = 0; i < 3; ++i )
  {
    v7 = i + 810;
    v6 = 4;
    if ( bCampaignViewOnly || !*(&gpGame->_1[12 * iCurViewSide + 157] + iCurViewMap) )
      v8 = 9;
    else
      v8 = 8;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
    if ( *((_BYTE *)v2 + 12 * iCurViewSide + iCurViewMap + 138) == i )
      v6 = 5;
    else
      v6 = 6;
    v8 = 4;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  }
  if ( a2 )
    heroWindow::DrawWindow(campWin);
}