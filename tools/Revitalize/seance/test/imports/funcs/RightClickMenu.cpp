{
  char *v3; // ST28_4@74
  char *v4; // eax@74
  char *v5; // ST28_4@80
  char *v6; // eax@80
  __int16 v7; // ax@83
  void *v9; // [sp+18h] [bp-1F4h]@1
  GUIWindow *thisa; // [sp+24h] [bp-1E8h]@12
  bool v11; // [sp+2Ch] [bp-1E0h]@68
  signed int v12; // [sp+3Ch] [bp-1D0h]@89
  signed int v13; // [sp+3Ch] [bp-1D0h]@125
  int evt; // [sp+40h] [bp-1CCh]@154
  int v15; // [sp+44h] [bp-1C8h]@154
  int v16; // [sp+48h] [bp-1C4h]@154
  char *v17; // [sp+58h] [bp-1B4h]@154
  char v18; // [sp+5Ch] [bp-1B0h]@74
  char v19; // [sp+124h] [bp-E8h]@151
  Hero *v20; // [sp+1ECh] [bp-20h]@1
  char *a3a; // [sp+1F0h] [bp-1Ch]@8
  int xOff; // [sp+1F4h] [bp-18h]@4
  GUIWindow *window; // [sp+1F8h] [bp-14h]@13
  int v24; // [sp+1FCh] [bp-10h]@87
  int v25; // [sp+200h] [bp-Ch]@1
  int v26; // [sp+204h] [bp-8h]@17
  int v27; // [sp+208h] [bp-4h]@87

  v9 = this;
  v25 = 0;
  v20 = 0;
  if ( curPlayer->_1[0] == -1 )
    v20 = 0;
  else
    v20 = &gameObject->heroes[curPlayer->_1[0]];
  xOff = 32 * a2 - 57;
  if ( xOff < 30 )
    xOff = 30;
  if ( xOff + 160 > 464 )
    xOff = 304;
  a3a = (char *)(32 * a3 - 25);
  if ( (signed int)a3a < 16 )
    a3a = (char *)16;
  if ( (signed int)(a3a + 96) > 448 )
    a3a = (char *)352;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    window = GUIWindow_constructorFromFile(thisa, xOff, (int)a3a, "qwikinfo.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  v26 = 0;
  if ( a2 + *(_DWORD *)((char *)v9 + 470) >= 0
    && a2 + *(_DWORD *)((char *)v9 + 470) < mapWidth
    && a3 + *(_DWORD *)((char *)v9 + 474) >= 0
    && a3 + *(_DWORD *)((char *)v9 + 474) < mapHeight )
  {
    v25 = usedToCheckForBoatByCastle(
            (AdvManager *)v9,
            a2 + *(_DWORD *)((char *)v9 + 470),
            a3 + *(_DWORD *)((char *)v9 + 474));
    if ( *(&tileExplored[a2] + *(_DWORD *)((char *)v9 + 470) + mapWidth * (a3 + *(_DWORD *)((char *)v9 + 474))) & (unsigned __int8)byte_532C5C )
    {
      switch ( *(_BYTE *)(v25 + 9) & 0x7F )
      {
        case 0x29:
          sprintf(globBuf, "%s", "Artifact");
          break;
        case 0x19:
          if ( !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_0[("(not visited)" - "(already visited)") & (((gameObject->field_6236[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5)
                                                                                               + 278] & (1 << curPlayerIdx)) != 0)
                                                                      - 1)]);
          break;
        case 0xA:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_1[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[4]) != 0)
                                                                      - 1)]);
          break;
        case 0x3E:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_2[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[8]) != 0)
                                                                      - 1)]);
          break;
        case 0x45:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_3[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[12]) != 0)
                                                                      - 1)]);
          break;
        case 0x49:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_4[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[16]) != 0)
                                                                      - 1)]);
          break;
        case 0x42:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_5[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[20]) != 0)
                                                                      - 1)]);
          break;
        case 0x44:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_6[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[24]) != 0)
                                                                      - 1)]);
          break;
        case 0x56:
          if ( !v20 || !(*(_BYTE *)(v25 + 9) & 0x80) )
            goto LABEL_145;
          sprintf(
            globBuf,
            "%s\n\n%s",
            (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
            &aAlreadyVisit_7[("(not visited)" - "(already visited)") & ((((1 << ((*(_WORD *)(v25 + 4) >> 3) & 0x1F)) & *(_DWORD *)&v20->_5[28]) != 0)
                                                                      - 1)]);
          break;
        case 3:
          v26 = 2;
          goto LABEL_145;
        case 9:
          v26 = 4;
          goto LABEL_145;
        case 0x1A:
          v26 = 8;
          goto LABEL_145;
        case 7:
          v26 = 16;
          goto LABEL_145;
        case 0x46:
          v26 = 256;
          goto LABEL_145;
        case 0x54:
          v26 = 512;
          goto LABEL_145;
        case 0x5E:
          v26 = 4096;
          goto LABEL_145;
        case 0x43:
          v26 = 8192;
          goto LABEL_145;
        case 0:
        case 0x13:
        case 0x1C:
        case 0x2C:
        case 0x39:
          v11 = *(_BYTE *)(v25 + 3) != 255 && ((*(_BYTE *)(v25 + 2) >> 2) & 0x3F) != 47 || *(_BYTE *)(v25 + 7) != 255;
          sprintf(
            globBuf,
            "%s\n%s",
            terrainNames[(unsigned __int8)tileToTerrainType[*(_WORD *)v25]],
            &aNoDigging[("(digging ok)" - "(no digging)") & ((v11 != 0) - 1)]);
          break;
        case 0x40:
          sprintf(globBuf, "%s", (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)]);
          goto LABEL_74;
        case 0x17:
          if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5) + 3] == -1 )
          {
            sprintf(
              globBuf,
              "%s %s",
              resourceNames[gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5) + 2]],
              "Mine");
          }
          else
          {
            sprintf(
              globBuf,
              "%s %s",
              resourceNames[gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5) + 2]],
              "Mine");
LABEL_74:
            v3 = creaturePluralNames[gameObject->_8[7
                                                  * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5)
                                                  + 3]];
            v4 = sub_44F960(
                   gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5) + 4],
                   2);
            sprintf(&v18, "\n\nguarded by %s %s", v4, v3);
            strcat(globBuf, &v18);
          }
          break;
        case 0x1B:
          sprintf(globBuf, "%s", *(char **)((char *)resourceNames + 2 * (*(_BYTE *)(v25 + 3) & 0xFE)));
          break;
        case 0x18:
          if ( sub_458C60(a2 + *(_DWORD *)((char *)v9 + 470), a3 + *(_DWORD *)((char *)v9 + 474), 8) )
          {
            sprintf(
              globBuf,
              "%d %s",
              (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5),
              creaturePluralNames[*(_BYTE *)(v25 + 3)]);
          }
          else
          {
            v5 = creaturePluralNames[*(_BYTE *)(v25 + 3)];
            v6 = sub_44F960((unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5), 1);
            sprintf(globBuf, "%s %s", v6, v5);
          }
          break;
        case 0x77:
        case 0x78:
          if ( *(_BYTE *)(v25 + 9) & 0x80 )
          {
            v7 = *(_WORD *)(v25 + 4) >> 3;
            sprintf(globBuf, (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)], gateColors[v7 & 7]);
            globBuf[0] = toupper(globBuf[0]);
          }
          else
          {
            sprintf(globBuf, "%s", terrainNames[(unsigned __int8)tileToTerrainType[*(_WORD *)v25]]);
          }
          break;
        case 0x7A:
          if ( *(_BYTE *)(v25 + 3) == 255 )
          {
            v24 = *(_BYTE *)(v25 + 7);
            v27 = (*(_BYTE *)(v25 + 6) >> 2) & 0x3F;
          }
          else
          {
            v24 = *(_BYTE *)(v25 + 3);
            v27 = (*(_BYTE *)(v25 + 2) >> 2) & 0x3F;
          }
          v12 = -1;
          if ( v27 == 61 )
          {
            if ( v24 >= 0 )
            {
              if ( v24 >= 4 )
              {
                if ( v24 < 72 )
                {
                  v12 = 1;
                  v26 = 4194304;
                }
              }
              else
              {
                v12 = 0;
              }
            }
          }
          else
          {
            if ( v27 == 62 )
            {
              if ( v24 >= 0 )
              {
                if ( v24 >= 5 )
                {
                  if ( v24 >= 10 )
                  {
                    if ( v24 >= 47 )
                    {
                      if ( v24 < 111 )
                      {
                        v12 = 6;
                        v26 = 2097152;
                      }
                    }
                    else
                    {
                      v12 = 5;
                      v26 = 1048576;
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
                  v26 = 8388608;
                }
              }
            }
            else
            {
              if ( v27 == 63 && v24 >= 0 )
              {
                if ( v24 >= 32 )
                {
                  if ( v24 < 59 )
                    v12 = 3;
                }
                else
                {
                  v12 = 2;
                }
              }
            }
          }
          if ( v12 == -1 )
            sprintf(globBuf, "Unknown");
          else
            sprintf(globBuf, (&off_4F7220)[4 * v12]);
          if ( v20 && v26 )
          {
            strcat(globBuf, "\n\n");
            strcat(
              globBuf,
              &aAlreadyVisit_8[("(not visited)" - "(already visited)") & (((*(_DWORD *)&v20->flags1 & v26) != 0) - 1)]);
          }
          break;
        case 0x79:
          if ( *(_BYTE *)(v25 + 7) == 255 )
          {
            v24 = *(_BYTE *)(v25 + 3);
            v27 = (*(_BYTE *)(v25 + 2) >> 2) & 0x3F;
          }
          else
          {
            v24 = *(_BYTE *)(v25 + 7);
            v27 = (*(_BYTE *)(v25 + 6) >> 2) & 0x3F;
          }
          v13 = -1;
          if ( v27 == 61 && v24 >= 72 )
          {
            if ( v24 >= 78 )
            {
              if ( v24 >= 112 )
              {
                if ( v24 >= 120 )
                {
                  if ( v24 >= 129 )
                  {
                    if ( v24 < 137 )
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
            sprintf(globBuf, "Unknown");
          else
            sprintf(globBuf, (&off_4F7240)[4 * v13]);
          break;
        case 0x67:
          if ( ((*(_BYTE *)(v25 + 2) >> 2) & 0x3F) != 62 )
            goto LABEL_145;
          sprintf(globBuf, "Reefs");
          break;
        default:
LABEL_145:
          if ( v26 && v20 )
            sprintf(
              globBuf,
              "%s\n\n%s",
              (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)],
              &aAlreadyVisited[("(not visited)" - "(already visited)") & (((*(_DWORD *)&v20->flags1 & v26) != 0) - 1)]);
          else
            sprintf(globBuf, "%s", (&adventureMapLocations)[4 * (*(_BYTE *)(v25 + 9) & 0x7F)]);
          break;
      }
    }
    else
    {
      sprintf(globBuf, "%s", "Uncharted Territory");
    }
  }
  else
  {
    sprintf(globBuf, "%s", "Border");
  }
  strcpy(&v19, globBuf);
  if ( debugLogLevel > 0 && v25 )
    sprintf(
      globBuf,
      "gi%d obtile%d obi%d ot%d ei%d bl%d %s X%d Y%d",
      *(_WORD *)v25,
      (*(_BYTE *)(v25 + 2) >> 2) & 0x3F,
      *(_BYTE *)(v25 + 3),
      *(_BYTE *)(v25 + 9),
      (unsigned __int8)((unsigned __int8)(*(_WORD *)(v25 + 4) >> 8) >> -5),
      *(_BYTE *)(v25 + 8) & 8,
      &v19,
      a2 + *(_DWORD *)((char *)v9 + 470),
      a3 + *(_DWORD *)((char *)v9 + 474));
  evt = 512;
  v15 = 3;
  v16 = 1;
  v17 = globBuf;
  GUIWindow::processMessage(window, (Event *)&evt);
  HeroWindowManager::addWindow(HeroWindowManager::instance, window, -1, 1);
  waitForMouseRelease();
  HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
  return operator delete(window);
}
