{
  signed int result; // eax@24
  char *v2; // eax@29
  char *v3; // eax@31
  char *v4; // eax@44
  char *v5; // eax@46
  char *v6; // eax@48
  char *v7; // eax@49
  int v8; // [sp+14h] [bp-30h]@71
  signed int v9; // [sp+18h] [bp-2Ch]@51
  void *evt; // [sp+20h] [bp-24h]@1
  int v11; // [sp+24h] [bp-20h]@105
  signed int building; // [sp+28h] [bp-1Ch]@1
  signed int v13; // [sp+30h] [bp-14h]@33
  int i; // [sp+30h] [bp-14h]@91
  signed int v15; // [sp+34h] [bp-10h]@1
  int v16; // [sp+38h] [bp-Ch]@52
  int v17; // [sp+38h] [bp-Ch]@97
  bool v18; // [sp+3Ch] [bp-8h]@1

  evt = this;
  building = -1;
  v18 = 0;
  v15 = 0;
  if ( *(_DWORD *)this == 4 || *(_DWORD *)this == 512 )
  {
    if ( *(_DWORD *)this == 4 )
    {
      heroWindowManager::ConvertToHover(gpWindowManager, (tag_message *)this);
      v15 = 1;
    }
    switch ( *((_DWORD *)evt + 2) )
    {
      case 0x44C:
        building = 15;
        break;
      case 0xD8:
        building = 216;
        break;
      case 0xD6:
        building = 214;
        break;
      default:
        if ( *((_DWORD *)evt + 2) < 600 || *((_DWORD *)evt + 2) >= 618 )
        {
          if ( *((_DWORD *)evt + 2) < 700 || *((_DWORD *)evt + 2) >= 718 )
          {
            if ( *((_DWORD *)evt + 2) >= 800 && *((_DWORD *)evt + 2) < 818 )
              building = *((_DWORD *)evt + 2) - 800;
          }
          else
          {
            building = *((_DWORD *)evt + 2) - 700;
          }
        }
        else
        {
          building = *((_DWORD *)evt + 2) - 600;
        }
        if ( building != -1 )
          building = (unsigned __int8)castleSlotsUse[building];
        break;
    }
  }
  if ( !v15 )
  {
    if ( *(_DWORD *)evt == 512 )
    {
      v8 = *((_DWORD *)evt + 1);
      if ( v8 == 12 )
        goto LABEL_120;
      if ( v8 == 13 )
      {
        if ( *((_DWORD *)evt + 2) == 30720 )
          v18 = 1;
        goto LABEL_115;
      }
      if ( v8 == 14 )
      {
LABEL_120:
        switch ( building + 1 )
        {
          case 215:
            if ( *((_BYTE *)evt + 13) & 2 )
            {
              NormalDialog(
                "{Spread Formation}\n\n'Spread' combat formation spreads your armies from the top to the bottom of the battlefield, with at least one empty space between each army.",
                4,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            else
            {
              gpTownManager->castle->_2[0] = 0;
              townManager::SetupCastle(gpTownManager, gpTownManager->curScreen, 1);
              heroWindow::DrawWindow(gpTownManager->curScreen);
            }
            break;
          case 217:
            if ( *((_BYTE *)evt + 13) & 2 )
            {
              NormalDialog(
                "{Grouped Formation}\n\n'Grouped' combat formation bunches your army together in the center of your side of the battlefield.",
                4,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            else
            {
              gpTownManager->castle->_2[0] = 1;
              townManager::SetupCastle(gpTownManager, gpTownManager->curScreen, 1);
              heroWindow::DrawWindow(gpTownManager->curScreen);
            }
            break;
          case 1:
            if ( *((_BYTE *)evt + 13) & 2
              || gpTownManager->castle->mageGuildLevel != 5 && (1 << building) & gpTownManager->field_156 )
              goto LABEL_91;
            break;
          case 2:
          case 3:
          case 4:
          case 5:
          case 8:
          case 9:
          case 10:
          case 11:
          case 12:
          case 13:
          case 14:
          case 16:
          case 20:
          case 21:
          case 22:
          case 23:
          case 24:
          case 25:
          case 26:
          case 27:
          case 28:
          case 29:
          case 30:
          case 31:
            if ( *((_BYTE *)evt + 13) & 2
              || !((1 << building) & gpTownManager->castle->buildingsBuiltFlags)
              && (1 << building) & gpTownManager->field_156 )
            {
LABEL_91:
              for ( i = 0;
                    gpTownManager->curBuilding > i && gpTownManager->buildingDisplays[i]->buildingCode != building;
                    ++i )
                ;
              v18 = townManager::BuyBuild(
                      gpTownManager,
                      building,
                      ((1 << building) & gpTownManager->field_152) == 0,
                      (*((_BYTE *)evt + 13) & 2) != 0);
            }
            break;
          case 0:
            switch ( *((_DWORD *)evt + 2) )
            {
              case 0x384:
              case 0x385:
                v17 = *((_DWORD *)evt + 2) - 900;
                goto LABEL_99;
              case 0x386:
              case 0x387:
                v17 = *((_DWORD *)evt + 2) - 902;
LABEL_99:
                if ( *((_BYTE *)evt + 13) & 2 )
                {
                  HeroView(gpCurPlayer->heroesForPurchase[v17], 1, 0);
                  heroWindow::DrawWindow(casWin);
                  bankBox::Update(gpTownManager->bankbox, 1);
                  heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
                }
                else
                {
                  v11 = gpTownManager->field_14E
                     || gpCurPlayer->resources[6] < gHeroGoldCost
                     || gpCurPlayer->numHeroes >= 8
                     || gpTownManager->castle->visitingHeroIdx != -1;
                  v18 = townManager::RecruitHero(gpTownManager, v17, v11);
                }
                break;
              default:
                goto LABEL_115;
            }
            break;
          default:
            break;
        }
      }
    }
LABEL_115:
    if ( v18 )
    {
      *((_DWORD *)evt + 2) = 10;
      *((_DWORD *)evt + 1) = *((_DWORD *)evt + 2);
      result = 2;
    }
    else
    {
      result = 1;
    }
    return result;
  }
  if ( *((_DWORD *)evt + 2) == gpTownManager->field_142 )
  {
    result = 1;
  }
  else
  {
    gpTownManager->field_142 = *((_DWORD *)evt + 2);
    switch ( building + 1 )
    {
      case 217:
        sprintf(gText, off_4F6418);
        break;
      case 215:
        sprintf(gText, off_4F641C);
        break;
      case 1:
        if ( (1 << building) & gpTownManager->field_156 )
        {
          if ( (1 << building) & gpTownManager->field_152 )
          {
            if ( gpTownManager->castle->buildingsBuiltFlags & 1 )
            {
              if ( gpTownManager->castle->mageGuildLevel == 5 )
              {
                v13 = 1;
              }
              else if ( CanBuy((int)&gpTownManager->castle->idx, 0) )
              {
                v13 = 3;
              }
              else
              {
                v13 = 2;
              }
            }
            else
            {
              v13 = 0;
            }
            strcpy(gText, (&cCastleInfo)[4 * v13]);
          }
          else
          {
            v3 = GetBuildingName(gpTownManager->castle->factionID, building);
            sprintf(gText, off_4F63F8, v3);
          }
        }
        else
        {
          v2 = GetBuildingName(gpTownManager->castle->factionID, building);
          sprintf(gText, off_4F63F4, v2);
        }
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 16:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:
        if ( BitTest(&gpGame->_7[72], gpTownManager->castle->idx) )
        {
          sprintf(gText, "Cannot build.  Already built here this turn.");
        }
        else if ( (1 << building) & gpTownManager->castle->buildingsBuiltFlags )
        {
          v4 = GetBuildingName(gpTownManager->castle->factionID, building);
          sprintf(gText, off_4F63F0, v4);
        }
        else if ( (1 << building) & gpTownManager->field_156 )
        {
          if ( (1 << building) & gpTownManager->field_152 )
          {
            v7 = GetBuildingName(gpTownManager->castle->factionID, building);
            sprintf(gText, off_4F63FC, v7);
          }
          else
          {
            v6 = GetBuildingName(gpTownManager->castle->factionID, building);
            sprintf(gText, off_4F63F8, v6);
          }
        }
        else
        {
          v5 = GetBuildingName(gpTownManager->castle->factionID, building);
          sprintf(gText, off_4F63F4, v5);
        }
        break;
      case 0:
        v9 = *((_DWORD *)evt + 2);
        if ( v9 > 30720 )
        {
LABEL_63:
          strcpy(gText, off_4F6414);
        }
        else if ( v9 == 30720 )
        {
          strcpy(gText, off_4F6410);
        }
        else
        {
          switch ( v9 )
          {
            case 900:
            case 901:
              v16 = *((_DWORD *)evt + 2) - 900;
              break;
            case 902:
            case 903:
              v16 = *((_DWORD *)evt + 2) - 902;
              break;
            default:
              goto LABEL_63;
          }
          if ( gpCurPlayer->resources[6] >= gHeroGoldCost )
          {
            if ( gpCurPlayer->numHeroes == 8 )
            {
              sprintf(gText, off_4F6404, 8);
            }
            else if ( gpTownManager->castle->visitingHeroIdx == -1 )
            {
              sprintf(
                gText,
                off_4F640C,
                gpGame->heroes[gpCurPlayer->heroesForPurchase[v16]].name,
                (&gAlignmentNames)[4 * gpGame->heroes[gpCurPlayer->heroesForPurchase[v16]].factionID]);
            }
            else
            {
              strcpy(gText, off_4F6408);
            }
          }
          else
          {
            strcpy(gText, off_4F6400);
          }
        }
        break;
      default:
        break;
    }
    *(_DWORD *)evt = 512;
    *((_DWORD *)evt + 1) = 3;
    *((_DWORD *)evt + 2) = 502;
    *((_DWORD *)evt + 6) = gText;
    heroWindow::BroadcastMessage(gpTownManager->curScreen, (Event *)evt);
    heroWindow::DrawWindow(gpTownManager->curScreen, 0, 500, 502);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, 18, 463, 0x25Cu, 16);
    result = 1;
  }
  return result;
}