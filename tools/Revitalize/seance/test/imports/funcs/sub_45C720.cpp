{
  signed int result; // eax@8
  size_t v2; // eax@30
  int v3; // [sp+10h] [bp-3B4h]@74
  int v4; // [sp+14h] [bp-3B0h]@73
  int v5; // [sp+1Ch] [bp-3A8h]@1
  char v6; // [sp+20h] [bp-3A4h]@146
  char v7; // [sp+5Ch] [bp-368h]@146
  char v8; // [sp+14Ch] [bp-278h]@136
  int v9; // [sp+1C0h] [bp-204h]@135
  int v10; // [sp+1C4h] [bp-200h]@135
  int v11; // [sp+1C8h] [bp-1FCh]@135
  int v12; // [sp+1D8h] [bp-1ECh]@135
  int v13; // [sp+1DCh] [bp-1E8h]@36
  int v14; // [sp+1E0h] [bp-1E4h]@15
  char v15; // [sp+1E4h] [bp-1E0h]@12
  int v16; // [sp+388h] [bp-3Ch]@13
  void *v17; // [sp+38Ch] [bp-38h]@4
  int evt; // [sp+390h] [bp-34h]@2
  int v19; // [sp+394h] [bp-30h]@2
  int v20; // [sp+398h] [bp-2Ch]@2
  int v21; // [sp+3A8h] [bp-1Ch]@2
  int v22; // [sp+3ACh] [bp-18h]@1
  int v23; // [sp+3B0h] [bp-14h]@106
  int j; // [sp+3B4h] [bp-10h]@103
  int i; // [sp+3B8h] [bp-Ch]@16
  int v26; // [sp+3BCh] [bp-8h]@30
  int v27; // [sp+3C0h] [bp-4h]@1

  v5 = (int)this;
  v22 = 0;
  v27 = 0;
  if ( !dword_524F24 )
  {
    dword_524F24 = 1;
    evt = 512;
    v19 = 6;
    v20 = 73;
    v21 = 6;
    GUIWindow::processMessage(*(GUIWindow **)&gameObject->_10[27], (Event *)&evt);
  }
  if ( !*(_DWORD *)v5 )
  {
    v17 = sub_46E3F0(1);
    if ( v17 && (*((_BYTE *)v17 + 5) == 2 || *((_BYTE *)v17 + 5) == 3) )
    {
      switch ( *((_BYTE *)v17 + 6) )
      {
        case 53:
          HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(v5 + 8);
          HeroWindowManager::instance->buttonPressedCode = 30722;
          *(_DWORD *)v5 = 512;
          *(_DWORD *)(v5 + 8) = 10;
          *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 8);
          return 2;
        case 54:
          display_message_window("The host has canceled the game.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          terminate(0);
          break;
        case 51:
          if ( !strcmp((const char *)v17 + 9, &gameObject->_3[13]) )
          {
            memcpy(&gameObject->_3[375], (char *)v17 + 69, 0x41u);
            v22 = 1;
          }
          break;
        case 52:
          memset(&v15, 0, 0x1A4u);
          memcpy(&v15, (char *)v17 + 9, 0x74u);
          sub_45A980((int)gameObject, &v15);
          break;
        case 11:
          v22 = 1;
          v16 = *(_BYTE *)v17;
          if ( v16 < 0 )
            v14 = 0;
          else
            sprintf(globBuf, "%s:  %s", (char *)&dword_526CE0 + 34 * v16 + 4, (char *)v17 + 9);
          globBuf[100] = 0;
          for ( i = 0; i < 2; ++i )
            strcpy((&dword_524F28)[4 * i], (&dword_524F2C)[4 * i]);
          strcpy(dword_524F30, globBuf);
          break;
        default:
          break;
      }
    }
    if ( getTickCount() > animationFrameSwitchTime )
    {
      sub_45DA80(dword_524F34, dword_524F20);
      sub_45DBA0(1);
    }
  }
  if ( *(_DWORD *)v5 == 1 )
  {
    if ( dword_5235D4 > 1 )
    {
      if ( dword_524778 != 2 )
      {
        if ( sub_45D660(v5) )
        {
          v22 = 1;
          for ( i = 0; i < 2; ++i )
            strcpy((&dword_524F28)[4 * i], (&dword_524F2C)[4 * i]);
          strcpy(dword_524F30, dword_524F34);
          strcpy(dword_524F34, byte_51140C);
          strcpy(dword_524F3C, byte_511410);
          dword_524F20 = 0;
          v2 = strlen(dword_524F30);
          v26 = sub_46E1D0(dword_524F30, 127, v2 + 1, 11, 1, 1, -1);
          if ( !v26 )
            terminate(0);
        }
      }
    }
  }
  if ( *(_DWORD *)v5 != 512 )
    goto LABEL_142;
  if ( *(_BYTE *)(v5 + 13) & 2 )
  {
    if ( *(_DWORD *)(v5 + 4) == 12 || *(_DWORD *)(v5 + 4) == 14 )
    {
      v13 = -1;
      if ( *(_DWORD *)(v5 + 8) >= 1 && *(_DWORD *)(v5 + 8) <= 5
        || *(_DWORD *)(v5 + 8) >= 67 && *(_DWORD *)(v5 + 8) <= 71 )
        v13 = 0;
      if ( *(_DWORD *)(v5 + 8) >= 48 && *(_DWORD *)(v5 + 8) <= 53
        || *(_DWORD *)(v5 + 8) >= 42 && *(_DWORD *)(v5 + 8) <= 47 )
        v13 = 1;
      if ( *(_DWORD *)(v5 + 8) >= 12 && *(_DWORD *)(v5 + 8) <= 17
        || *(_DWORD *)(v5 + 8) >= 6 && *(_DWORD *)(v5 + 8) <= 11
        || *(_DWORD *)(v5 + 8) >= 18 && *(_DWORD *)(v5 + 8) <= 24
        || *(_DWORD *)(v5 + 8) >= 24 && *(_DWORD *)(v5 + 8) <= 30 )
        v13 = 2;
      if ( *(_DWORD *)(v5 + 8) >= 36 && *(_DWORD *)(v5 + 8) <= 41
        || *(_DWORD *)(v5 + 8) >= 30 && *(_DWORD *)(v5 + 8) <= 35 )
        v13 = 3;
      if ( *(_DWORD *)(v5 + 8) == 54 || *(_DWORD *)(v5 + 8) == 72 || *(_DWORD *)(v5 + 8) == 64 )
        v13 = 4;
      if ( *(_DWORD *)(v5 + 8) == 66 )
        v13 = 5;
      if ( *(_DWORD *)(v5 + 8) == 30722 )
        v13 = 6;
      if ( *(_DWORD *)(v5 + 8) == 30721 )
        v13 = 7;
      if ( v13 != -1 )
        display_message_window((&off_4F6768)[4 * v13], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    goto LABEL_142;
  }
  v4 = *(_DWORD *)(v5 + 4);
  if ( v4 == 12 )
  {
    switch ( *(_DWORD *)(v5 + 8) )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        i = *(_DWORD *)(v5 + 8) - 1;
        goto LABEL_88;
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        i = *(_DWORD *)(v5 + 8) - 67;
LABEL_88:
        gameObject->difficulty = i;
        v27 = 1;
        v22 = 1;
        goto LABEL_142;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
        i = *(_DWORD *)(v5 + 8) - 48;
        goto LABEL_91;
      case 0x2A:
      case 0x2B:
      case 0x2C:
      case 0x2D:
      case 0x2E:
      case 0x2F:
        i = *(_DWORD *)(v5 + 8) - 42;
LABEL_91:
        v27 = 1;
        v22 = 1;
        if ( gameObject->_4[i + 6] != 10 )
          gameObject->playerHandicap[i] = (gameObject->playerHandicap[i] + 1) % 3;
        goto LABEL_142;
      case 6:
      case 7:
      case 8:
      case 9:
      case 0xA:
      case 0xB:
        i = *(_DWORD *)(v5 + 8) - 6;
        goto LABEL_98;
      case 0xC:
      case 0xD:
      case 0xE:
      case 0xF:
      case 0x10:
      case 0x11:
        i = *(_DWORD *)(v5 + 8) - 12;
        goto LABEL_98;
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        i = *(_DWORD *)(v5 + 8) - 18;
        goto LABEL_98;
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
      case 0x1C:
      case 0x1D:
        i = *(_DWORD *)(v5 + 8) - 24;
LABEL_98:
        v27 = 1;
        v22 = 1;
        if ( gameObject->_5[i + 13] || dword_5235D4 > 1 && gameObject->_4[i + 6] != 10 )
        {
          if ( dword_5235D4 == 1 )
          {
            if ( gameObject->_4[i + 6] == 10 )
            {
              for ( j = 0; gameObject->_1[702] > j; ++j )
              {
                if ( gameObject->_4[j + 6] != 10 )
                {
                  v23 = gameObject->_4[j + 6];
                  gameObject->_4[j + 6] = gameObject->_4[i + 6];
                  gameObject->_4[i + 6] = v23;
                  j = 999;
                }
              }
            }
          }
          else
          {
            if ( gameObject->_5[19] == -1 )
            {
              gameObject->_5[19] = i;
            }
            else
            {
              if ( gameObject->_5[19] != i
                && (gameObject->_4[i + 6] != 10 || gameObject->_4[gameObject->_5[19] + 6] != 10) )
              {
                if ( gameObject->_5[i + 13] && gameObject->_5[gameObject->_5[19] + 13]
                  || gameObject->_4[i + 6] != 10 && gameObject->_4[gameObject->_5[19] + 6] != 10 )
                {
                  j = gameObject->_4[i + 6];
                  gameObject->_4[i + 6] = gameObject->_4[gameObject->_5[19] + 6];
                  gameObject->_4[gameObject->_5[19] + 6] = j;
                }
                else
                {
                  display_message_window(
                    "The two positions selected can not be swapped.",
                    1,
                    -1,
                    -1,
                    -1,
                    0,
                    -1,
                    0,
                    -1,
                    0);
                }
                gameObject->_5[19] = -1;
              }
              else
              {
                gameObject->_5[19] = -1;
              }
            }
          }
        }
        goto LABEL_142;
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x27:
      case 0x28:
      case 0x29:
        i = *(_DWORD *)(v5 + 8) - 36;
        goto LABEL_125;
      case 0x1E:
      case 0x1F:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
        i = *(_DWORD *)(v5 + 8) - 30;
LABEL_125:
        if ( gameObject->_2[gameObject->_3[i + 375] + 4] == 7 )
        {
          if ( gameObject->_4[i] == 7 )
          {
            gameObject->_4[i] = 0;
          }
          else
          {
            if ( gameObject->_4[i] == 5 )
              gameObject->_4[i] = 7;
            else
              ++gameObject->_4[i];
          }
          v27 = 1;
          v22 = 1;
        }
        break;
      case 0x40:
      case 0x48:
        goto LABEL_133;
      default:
        goto LABEL_142;
    }
    goto LABEL_142;
  }
  if ( v4 != 13 )
  {
LABEL_142:
    if ( v22 )
    {
      sub_45C180((int)gameObject);
      GUIWindow::repaintAndUpdateScreen(*(GUIWindow **)&gameObject->_10[27]);
    }
    if ( v27 && dword_4F7494 )
    {
      memcpy(&v6, &gameObject->_3[13], 0x3Cu);
      memcpy(&v7, &gameObject->_3[375], 0x41u);
      v26 = sub_46E1D0(&v6, 127, 0x7Du, 51, 1, 1, -1);
      if ( !v26 )
        terminate(0);
    }
    return 1;
  }
  v3 = *(_DWORD *)(v5 + 8);
  if ( v3 == 54 )
  {
LABEL_133:
    if ( !dword_4F7494 || !dword_523F14 )
    {
      v9 = 512;
      v10 = 6;
      v11 = 30721;
      v12 = 2;
      GUIWindow::processMessage(*(GUIWindow **)&gameObject->_10[27], (Event *)&v9);
      sub_45A7A0(gameObject);
      v9 = 512;
      v10 = 5;
      v11 = 30721;
      v12 = 2;
      GUIWindow::processMessage(*(GUIWindow **)&gameObject->_10[27], (Event *)&v9);
      if ( dword_4F7494 )
      {
        memcpy(&v8, &gameObject->_1[676], 0x74u);
        v26 = sub_46E1D0(&v8, 127, 0x74u, 52, 1, 1, -1);
      }
    }
    goto LABEL_142;
  }
  if ( v3 == 30721 )
  {
    if ( dword_4F7494 )
    {
      v26 = sub_46E1D0(0, 127, 0, 54, 1, 1, -1);
      terminate(0);
    }
    HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(v5 + 8);
    *(_DWORD *)(v5 + 8) = 10;
    *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 8);
    dword_5110CC = 1;
    result = 2;
  }
  else
  {
    if ( v3 != 30722 )
      goto LABEL_142;
    if ( dword_4F7494 )
      v26 = sub_46E1D0(0, 127, 0, 53, 1, 1, -1);
    HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(v5 + 8);
    *(_DWORD *)(v5 + 8) = 10;
    *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 8);
    dword_5110CC = 1;
    result = 2;
  }
  return result;
}
