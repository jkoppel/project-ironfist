{
  char *v3; // ST28_4@74
  char *v4; // eax@74
  char *v5; // ST28_4@80
  char *v6; // eax@80
  __int16 v7; // ax@83
  void *v9; // [sp+18h] [bp-1F4h]@1
  heroWindow *this; // [sp+24h] [bp-1E8h]@12
  bool v11; // [sp+2Ch] [bp-1E0h]@68
  signed int v12; // [sp+3Ch] [bp-1D0h]@89
  signed int v13; // [sp+3Ch] [bp-1D0h]@125
  Event evt; // [sp+40h] [bp-1CCh]@154
  char v15; // [sp+5Ch] [bp-1B0h]@74
  char a1; // [sp+124h] [bp-E8h]@151
  hero *v17; // [sp+1ECh] [bp-20h]@1
  int yOff; // [sp+1F0h] [bp-1Ch]@8
  int xOff; // [sp+1F4h] [bp-18h]@4
  heroWindow *window; // [sp+1F8h] [bp-14h]@13
  int v21; // [sp+1FCh] [bp-10h]@87
  mapCell *v22; // [sp+200h] [bp-Ch]@1
  int v23; // [sp+204h] [bp-8h]@17
  int v24; // [sp+208h] [bp-4h]@87

  v9 = ecx0;
  v22 = 0;
  v17 = 0;
  if ( gpCurPlayer->curHeroIdx == -1 )
    v17 = 0;
  else
    v17 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  xOff = 32 * a2 - 57;
  if ( xOff < 30 )
    xOff = 30;
  if ( xOff + 160 > 464 )
    xOff = 304;
  yOff = 32 * a3 - 25;
  if ( yOff < 16 )
    yOff = 16;
  if ( yOff + 96 > 448 )
    yOff = 352;
  this = (heroWindow *)operator new(68);
  if ( this )
    window = heroWindow::heroWindow(this, xOff, yOff, "qwikinfo.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  v23 = 0;
  if ( a2 + *(_DWORD *)((char *)v9 + 470) >= 0
    && a2 + *(_DWORD *)((char *)v9 + 470) < MAP_WIDTH
    && a3 + *(_DWORD *)((char *)v9 + 474) >= 0
    && a3 + *(_DWORD *)((char *)v9 + 474) < MAP_HEIGHT )
  {
    v22 = advManager::GetCell((advManager *)v9, a2 + *(_DWORD *)((char *)v9 + 470), a3 + *(_DWORD *)((char *)v9 + 474));
    if ( *(&mapExtra[a2] + *(_DWORD *)((char *)v9 + 470) + MAP_WIDTH * (a3 + *(_DWORD *)((char *)v9 + 474))) & (unsigned __int8)giCurPlayerBit )
    {
      switch ( v22->objType & 0x7F )
      {
        case 0x29:
          sprintf(gText, "%s", "Artifact");
          break;
        case 0x19:
          if ( !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_0[("(not visited)" - "(already visited)") & (((gpGame->field_6236[(unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5)
                                                                                           + 278] & (1 << giCurPlayer)) != 0)
                                                                      - 1)]);
          break;
        case 0xA:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_1[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[4]) != 0)
                                                                      - 1)]);
          break;
        case 0x3E:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_2[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[8]) != 0)
                                                                      - 1)]);
          break;
        case 0x45:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_3[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[12]) != 0)
                                                                      - 1)]);
          break;
        case 0x49:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_4[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[16]) != 0)
                                                                      - 1)]);
          break;
        case 0x42:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_5[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[20]) != 0)
                                                                      - 1)]);
          break;
        case 0x44:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_6[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[24]) != 0)
                                                                      - 1)]);
          break;
        case 0x56:
          if ( !v17 || !(v22->objType & 0x80) )
            goto LABEL_145;
          sprintf(
            gText,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
            &aAlreadyVisit_7[("(not visited)" - "(already visited)") & ((((1 << ((v22->flags >> 3) & 0x1F)) & *(_DWORD *)&v17->_5[28]) != 0)
                                                                      - 1)]);
          break;
        case 3:
          v23 = 2;
          goto LABEL_145;
        case 9:
          v23 = 4;
          goto LABEL_145;
        case 0x1A:
          v23 = 8;
          goto LABEL_145;
        case 7:
          v23 = 16;
          goto LABEL_145;
        case 0x46:
          v23 = 256;
          goto LABEL_145;
        case 0x54:
          v23 = 512;
          goto LABEL_145;
        case 0x5E:
          v23 = 4096;
          goto LABEL_145;
        case 0x43:
          v23 = 8192;
          goto LABEL_145;
        case 0:
        case 0x13:
        case 0x1C:
        case 0x2C:
        case 0x39:
          v11 = HIBYTE(v22->field_2) != 255 && ((LOBYTE(v22->field_2) >> 2) & 0x3F) != 47 || v22->field_7 != 255;
          sprintf(
            gText,
            "%s\n%s",
            terrainNames[(unsigned __int8)giGroundToTerrain[v22->tileType]],
            &aNoDigging[("(digging ok)" - "(no digging)") & ((v11 != 0) - 1)]);
          break;
        case 0x40:
          sprintf(gText, "%s", (&adventureMapLocations)[4 * (v22->objType & 0x7F)]);
          goto LABEL_74;
        case 0x17:
          if ( gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5) + 3] == -1 )
          {
            sprintf(
              gText,
              "%s %s",
              gResourceNames[gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5) + 2]],
              "Mine");
          }
          else
          {
            sprintf(
              gText,
              "%s %s",
              gResourceNames[gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5) + 2]],
              "Mine");
LABEL_74:
            v3 = gArmyNamesPlural[gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5) + 3]];
            v4 = advManager::GetArmySizeName(
                   gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5) + 4],
                   2);
            sprintf(&v15, "\n\nguarded by %s %s", v4, v3);
            strcat(gText, &v15);
          }
          break;
        case 0x1B:
          sprintf(gText, "%s", *(char **)((char *)gResourceNames + 2 * (HIBYTE(v22->field_2) & 0xFE)));
          break;
        case 0x18:
          if ( advManager::IsCrystalBallInEffect(
                 a2 + *(_DWORD *)((char *)v9 + 470),
                 a3 + *(_DWORD *)((char *)v9 + 474),
                 8) )
          {
            sprintf(
              gText,
              "%d %s",
              (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5),
              gArmyNamesPlural[HIBYTE(v22->field_2)]);
          }
          else
          {
            v5 = gArmyNamesPlural[HIBYTE(v22->field_2)];
            v6 = advManager::GetArmySizeName((unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5), 1);
            sprintf(gText, "%s %s", v6, v5);
          }
          break;
        case 0x77:
        case 0x78:
          if ( v22->objType & 0x80 )
          {
            v7 = v22->flags >> 3;
            sprintf(gText, (&adventureMapLocations)[4 * (v22->objType & 0x7F)], xBarrierColor[v7 & 7]);
            gText[0] = toupper(gText[0]);
          }
          else
          {
            sprintf(gText, "%s", terrainNames[(unsigned __int8)giGroundToTerrain[v22->tileType]]);
          }
          break;
        case 0x7A:
          if ( HIBYTE(v22->field_2) == 255 )
          {
            v21 = v22->field_7;
            v24 = ((unsigned __int8)v22->field_6 >> 2) & 0x3F;
          }
          else
          {
            v21 = HIBYTE(v22->field_2);
            v24 = (LOBYTE(v22->field_2) >> 2) & 0x3F;
          }
          v12 = -1;
          if ( v24 == 61 )
          {
            if ( v21 >= 0 )
            {
              if ( v21 >= 4 )
              {
                if ( v21 < 72 )
                {
                  v12 = 1;
                  v23 = 4194304;
                }
              }
              else
              {
                v12 = 0;
              }
            }
          }
          else if ( v24 == 62 )
          {
            if ( v21 >= 0 )
            {
              if ( v21 >= 5 )
              {
                if ( v21 >= 10 )
                {
                  if ( v21 >= 47 )
                  {
                    if ( v21 < 111 )
                    {
                      v12 = 6;
                      v23 = 2097152;
                    }
                  }
                  else
                  {
                    v12 = 5;
                    v23 = 1048576;
                  }
                }
                else
                {
                  v12 = -1;
                }
              }
              else
              {
                v12 = 4;
                v23 = 8388608;
              }
            }
          }
          else if ( v24 == 63 && v21 >= 0 )
          {
            if ( v21 >= 32 )
            {
              if ( v21 < 59 )
                v12 = 3;
            }
            else
            {
              v12 = 2;
            }
          }
          if ( v12 == -1 )
            sprintf(gText, "Unknown");
          else
            sprintf(gText, (&off_4F7220)[4 * v12]);
          if ( v17 && v23 )
          {
            strcat(gText, "\n\n");
            strcat(
              gText,
              &aAlreadyVisit_8[("(not visited)" - "(already visited)") & (((*(_DWORD *)&v17->flags1 & v23) != 0) - 1)]);
          }
          break;
        case 0x79:
          if ( v22->field_7 == 255 )
          {
            v21 = HIBYTE(v22->field_2);
            v24 = (LOBYTE(v22->field_2) >> 2) & 0x3F;
          }
          else
          {
            v21 = v22->field_7;
            v24 = ((unsigned __int8)v22->field_6 >> 2) & 0x3F;
          }
          v13 = -1;
          if ( v24 == 61 && v21 >= 72 )
          {
            if ( v21 >= 78 )
            {
              if ( v21 >= 112 )
              {
                if ( v21 >= 120 )
                {
                  if ( v21 >= 129 )
                  {
                    if ( v21 < 137 )
                      v13 = 4;
                  }
                  else
                  {
                    v13 = 3;
                  }
                }
                else
                {
                  v13 = 2;
                }
              }
              else
              {
                v13 = 1;
              }
            }
            else
            {
              v13 = 0;
            }
          }
          if ( v13 == -1 )
            sprintf(gText, "Unknown");
          else
            sprintf(gText, (&off_4F7240)[4 * v13]);
          break;
        case 0x67:
          if ( ((LOBYTE(v22->field_2) >> 2) & 0x3F) != 62 )
            goto LABEL_145;
          sprintf(gText, "Reefs");
          break;
        default:
LABEL_145:
          if ( v23 && v17 )
            sprintf(
              gText,
              "%s\n\n%s",
              (&adventureMapLocations)[4 * (v22->objType & 0x7F)],
              &aAlreadyVisited[("(not visited)" - "(already visited)") & (((*(_DWORD *)&v17->flags1 & v23) != 0) - 1)]);
          else
            sprintf(gText, "%s", (&adventureMapLocations)[4 * (v22->objType & 0x7F)]);
          break;
      }
    }
    else
    {
      sprintf(gText, "%s", "Uncharted Territory");
    }
  }
  else
  {
    sprintf(gText, "%s", "Border");
  }
  strcpy(&a1, gText);
  if ( giDebugLevel > 0 && v22 )
    sprintf(
      gText,
      "gi%d obtile%d obi%d ot%d ei%d bl%d %s X%d Y%d",
      v22->tileType,
      (LOBYTE(v22->field_2) >> 2) & 0x3F,
      HIBYTE(v22->field_2),
      v22->objType,
      (unsigned __int8)((unsigned __int8)(v22->flags >> 8) >> -5),
      v22->field_8 & 8,
      &a1,
      a2 + *(_DWORD *)((char *)v9 + 470),
      a3 + *(_DWORD *)((char *)v9 + 474));
  *(_QWORD *)&evt.inputEvt.eventCode = 12884902400i64;
  evt.inputEvt.yCoord = 1;
  evt.inputEvt.payload = gText;
  heroWindow::BroadcastMessage(window, &evt);
  heroWindowManager::AddWindow(gpWindowManager, window, -1, 1);
  QuickViewWait();
  heroWindowManager::RemoveWindow(gpWindowManager, window);
  return operator delete(window);
}