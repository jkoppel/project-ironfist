void __thiscall sub_4A85D0(void *this, int a2)
{
  void *v2; // [sp+14h] [bp-60h]@1
  unsigned __int8 v3; // [sp+18h] [bp-5Ch]@7
  char *v4; // [sp+1Ch] [bp-58h]@56
  int evt; // [sp+20h] [bp-54h]@1
  int v6; // [sp+24h] [bp-50h]@32
  int v7; // [sp+28h] [bp-4Ch]@32
  int v8; // [sp+38h] [bp-3Ch]@4
  char v9; // [sp+3Ch] [bp-38h]@81
  int i; // [sp+70h] [bp-4h]@1

  v2 = this;
  evt = 512;
  for ( i = 0; i < 13; ++i )
  {
    if ( *((_BYTE *)v2 + 12 * dword_5304D8 + i + 162) )
    {
      v8 = 11;
    }
    else
    {
      if ( i < 11 && (i < 4 ? (v3 = *((_BYTE *)v2 + 3)) : (v3 = *((_BYTE *)v2 + 2)), *((_BYTE *)v2 + 12 * v3 + i + 5)) )
        v8 = 10;
      else
        v8 = 12;
    }
    if ( dword_5304DC == i )
    {
      if ( i != 4 || dword_5304D0 != 1 )
      {
        if ( i != 4 || dword_5304D0 != 2 )
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
            else
            {
              if ( *((_BYTE *)v2 + 3) )
                v8 += 6;
              else
                v8 += 3;
            }
          }
          else
          {
            if ( *((_BYTE *)v2 + 3) )
              v8 += 3;
            else
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
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  }
  v6 = 9;
  v7 = 809;
  v8 = (int)globBuf;
  sprintf(globBuf, "ctrack%02d.icn", dword_5304D0);
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  v6 = 3;
  v8 = (int)globBuf;
  v7 = 801;
  if ( dword_5304DC == 11 )
    sprintf(globBuf, L"5");
  else
    sprintf(globBuf, "%d", dword_5304DC + 1);
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  v7 = 802;
  if ( dword_5304DC == 11 )
  {
    sprintf(globBuf, "%s", (&off_4F7108[12 * (1 - dword_5304D8)])[4 * dword_5304DC]);
  }
  else
  {
    if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || dword_5304DC != 4 )
      sprintf(globBuf, "%s", (&off_4F7108[12 * dword_5304D8])[4 * dword_5304DC]);
    else
      sprintf(globBuf, "%s", off_4F7134[12 * dword_5304D8]);
  }
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  v7 = 803;
  if ( dword_5304DC == 11 )
  {
    sprintf(globBuf, "%s", (&off_4F7168[12 * (1 - dword_5304D8)])[4 * dword_5304DC]);
  }
  else
  {
    if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || dword_5304DC != 4 )
      sprintf(globBuf, "%s", (&off_4F7168[12 * dword_5304D8])[4 * dword_5304DC]);
    else
      sprintf(globBuf, "%s", off_4F7194[12 * dword_5304D8]);
  }
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  v7 = 804;
  sprintf(globBuf, "%d", *(_WORD *)((char *)v2 + 24 * dword_5304D8 + 2 * dword_5304DC + 29));
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  strcpy(globBuf, byte_51D1EC);
  for ( i = 0; i < 12; ++i )
  {
    if ( *((_BYTE *)v2 + i + 126) )
    {
      strcat(globBuf, (&off_4F70D8)[4 * i]);
      strcat(globBuf, L"\n");
    }
  }
  v7 = 805;
  GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    if ( dword_5304DC == 11 )
    {
      v4 = (char *)&unk_4F5488 + 180 * (1 - dword_5304D8) + 15 * dword_5304DC + 5 * i;
    }
    else
    {
      if ( *((_BYTE *)v2 + 2) == *((_BYTE *)v2 + 3) || dword_5304DC != 4 )
        v4 = (char *)&unk_4F5488 + 180 * dword_5304D8 + 15 * dword_5304DC + 5 * i;
      else
        v4 = (char *)&unk_4F5488 + 180 * dword_5304D8 + 5 * i + 165;
    }
    switch ( *v4 )
    {
      case 0:
        sprintf(globBuf, "%d %s", *(_WORD *)(v4 + 3), resourceNames[*(_WORD *)(v4 + 1)]);
        break;
      case 1:
        switch ( *(_WORD *)(v4 + 1) )
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
          default:
            sprintf(globBuf, "%s", artifactNames[*(_WORD *)(v4 + 1)]);
            break;
        }
        break;
      case 2:
        if ( *(_WORD *)(v4 + 1) == 43 )
          sprintf(globBuf, "Summon Earth");
        else
          sprintf(globBuf, "%s", spell_names[*(_WORD *)(v4 + 1)]);
        break;
      case 3:
        sprintf(globBuf, "%s %s", secondarySkillLevels[*(_WORD *)(v4 + 3)], secondary_skill_names[*(_WORD *)(v4 + 1)]);
        break;
      case 4:
        strcpy(&v9, creaturePluralNames[*(_WORD *)(v4 + 1)]);
        v9 -= 32;
        sprintf(globBuf, "%d %s", *(_WORD *)(v4 + 3), &v9);
        break;
      case 5:
        sprintf(globBuf, "%d %s", *(_WORD *)(v4 + 1), "Puzzle Pieces");
        break;
      case 6:
        sprintf(globBuf, "%d %s", *(_WORD *)(v4 + 1), "Experience");
        break;
      case 7:
        sprintf(globBuf, "n/a");
        break;
      case 8:
        sprintf(globBuf, (&off_4F5AF8)[4 * *(_WORD *)(v4 + 1)]);
        break;
      default:
        break;
    }
    v7 = i + 806;
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  }
  for ( i = 0; i < 3; ++i )
  {
    v7 = i + 810;
    v6 = 4;
    if ( dword_5304D4 || !*(&gameObject->_1[12 * dword_5304D8 + 157] + dword_5304DC) )
      v8 = 9;
    else
      v8 = 8;
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
    if ( *((_BYTE *)v2 + 12 * dword_5304D8 + dword_5304DC + 138) == i )
      v6 = 5;
    else
      v6 = 6;
    v8 = 4;
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  }
  if ( a2 )
    GUIWindow::repaintAndUpdateScreen(dword_51D158);
}
