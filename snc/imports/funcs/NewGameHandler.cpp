{
  signed int result; // eax@8
  int v3; // eax@30
  int v4; // [sp+10h] [bp-3B4h]@74
  int v5; // [sp+14h] [bp-3B0h]@73
  int v6; // [sp+1Ch] [bp-3A8h]@1
  char v7; // [sp+20h] [bp-3A4h]@146
  char v8; // [sp+5Ch] [bp-368h]@146
  char v9; // [sp+14Ch] [bp-278h]@136
  int v10; // [sp+1C0h] [bp-204h]@135
  int v11; // [sp+1C4h] [bp-200h]@135
  int v12; // [sp+1C8h] [bp-1FCh]@135
  int v13; // [sp+1D8h] [bp-1ECh]@135
  int v14; // [sp+1DCh] [bp-1E8h]@36
  int v15; // [sp+1E0h] [bp-1E4h]@15
  char v16; // [sp+1E4h] [bp-1E0h]@12
  int v17; // [sp+388h] [bp-3Ch]@13
  void *v18; // [sp+38Ch] [bp-38h]@4
  int evt; // [sp+390h] [bp-34h]@2
  int v20; // [sp+394h] [bp-30h]@2
  int v21; // [sp+398h] [bp-2Ch]@2
  int v22; // [sp+3A8h] [bp-1Ch]@2
  int v23; // [sp+3ACh] [bp-18h]@1
  int v24; // [sp+3B0h] [bp-14h]@106
  int j; // [sp+3B4h] [bp-10h]@103
  int i; // [sp+3B8h] [bp-Ch]@16
  int v27; // [sp+3BCh] [bp-8h]@30
  int v28; // [sp+3C0h] [bp-4h]@1

  v6 = (int)this;
  v23 = 0;
  v28 = 0;
  if ( !gbNewGameShadowHidden )
  {
    gbNewGameShadowHidden = 1;
    evt = 512;
    v20 = 6;
    v21 = 73;
    v22 = 6;
    heroWindow::BroadcastMessage(*(heroWindow **)&gpGame->_10[27], (Event *)&evt);
  }
  if ( !*(_DWORD *)v6 )
  {
    v18 = GetRemoteData(1, (int)a2);
    if ( v18 && (*((_BYTE *)v18 + 5) == 2 || *((_BYTE *)v18 + 5) == 3) )
    {
      switch ( *((_BYTE *)v18 + 6) )
      {
        case 53:
          gpWindowManager->buttonPressedCode = *(_DWORD *)(v6 + 8);
          gpWindowManager->buttonPressedCode = 30722;
          *(_DWORD *)v6 = 512;
          *(_DWORD *)(v6 + 8) = 10;
          *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 8);
          return 2;
        case 54:
          NormalDialog("The host has canceled the game.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          ShutDown(0);
          break;
        case 51:
          if ( !strcmp((int)((char *)v18 + 9), (int)&gpGame->_3[13]) )
          {
            memcpy(&gpGame->_3[375], (char *)v18 + 69, 0x41u);
            v23 = 1;
          }
          break;
        case 52:
          memset(&v16, 0, 0x1A4u);
          memcpy(&v16, (char *)v18 + 9, 0x74u);
          game::ProcessNewMap((int)gpGame, &v16);
          break;
        case 11:
          v23 = 1;
          v17 = *(_BYTE *)v18;
          if ( v17 < 0 )
            v15 = 0;
          else
            sprintf(gText, "%s:  %s", (char *)&gsNetPlayerInfo + 34 * v17 + 4, (char *)v18 + 9);
          gText[100] = 0;
          for ( i = 0; i < 2; ++i )
            strcpy((&cTextReceivedBuffer)[4 * i], (&dword_524F2C)[4 * i]);
          strcpy(dword_524F30, gText);
          break;
        default:
          break;
      }
    }
    if ( KBTickCount() > glTimers )
    {
      game::NGKPSetupDisplayString(cNGKPCore, NGKPcursorIndex);
      game::DrawNGKPDisplayString(1);
    }
  }
  if ( *(_DWORD *)v6 == 1 )
  {
    if ( iLastMsgNumHumanPlayers > 1 )
    {
      if ( iMPBaseType != 2 )
      {
        if ( game::ProcessNGKeyPress(v6) )
        {
          v23 = 1;
          for ( i = 0; i < 2; ++i )
            strcpy((&cTextReceivedBuffer)[4 * i], (&dword_524F2C)[4 * i]);
          strcpy(dword_524F30, cNGKPCore);
          strcpy(cNGKPCore, byte_51140C);
          strcpy(cNGKPDisplay, byte_511410);
          NGKPcursorIndex = 0;
          v3 = strlen((int)dword_524F30);
          v27 = TransmitRemoteData(dword_524F30, 127, v3 + 1, 11, 1, 1, -1);
          if ( !v27 )
            ShutDown(0);
        }
      }
    }
  }
  if ( *(_DWORD *)v6 != 512 )
    goto LABEL_142;
  if ( *(_BYTE *)(v6 + 13) & 2 )
  {
    if ( *(_DWORD *)(v6 + 4) == 12 || *(_DWORD *)(v6 + 4) == 14 )
    {
      v14 = -1;
      if ( *(_DWORD *)(v6 + 8) >= 1 && *(_DWORD *)(v6 + 8) <= 5
        || *(_DWORD *)(v6 + 8) >= 67 && *(_DWORD *)(v6 + 8) <= 71 )
        v14 = 0;
      if ( *(_DWORD *)(v6 + 8) >= 48 && *(_DWORD *)(v6 + 8) <= 53
        || *(_DWORD *)(v6 + 8) >= 42 && *(_DWORD *)(v6 + 8) <= 47 )
        v14 = 1;
      if ( *(_DWORD *)(v6 + 8) >= 12 && *(_DWORD *)(v6 + 8) <= 17
        || *(_DWORD *)(v6 + 8) >= 6 && *(_DWORD *)(v6 + 8) <= 11
        || *(_DWORD *)(v6 + 8) >= 18 && *(_DWORD *)(v6 + 8) <= 24
        || *(_DWORD *)(v6 + 8) >= 24 && *(_DWORD *)(v6 + 8) <= 30 )
        v14 = 2;
      if ( *(_DWORD *)(v6 + 8) >= 36 && *(_DWORD *)(v6 + 8) <= 41
        || *(_DWORD *)(v6 + 8) >= 30 && *(_DWORD *)(v6 + 8) <= 35 )
        v14 = 3;
      if ( *(_DWORD *)(v6 + 8) == 54 || *(_DWORD *)(v6 + 8) == 72 || *(_DWORD *)(v6 + 8) == 64 )
        v14 = 4;
      if ( *(_DWORD *)(v6 + 8) == 66 )
        v14 = 5;
      if ( *(_DWORD *)(v6 + 8) == 30722 )
        v14 = 6;
      if ( *(_DWORD *)(v6 + 8) == 30721 )
        v14 = 7;
      if ( v14 != -1 )
        NormalDialog((&gNewGameHelp)[4 * v14], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    goto LABEL_142;
  }
  v5 = *(_DWORD *)(v6 + 4);
  if ( v5 == 12 )
  {
    switch ( *(_DWORD *)(v6 + 8) )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        i = *(_DWORD *)(v6 + 8) - 1;
        goto LABEL_88;
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        i = *(_DWORD *)(v6 + 8) - 67;
LABEL_88:
        gpGame->difficulty = i;
        v28 = 1;
        v23 = 1;
        goto LABEL_142;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
        i = *(_DWORD *)(v6 + 8) - 48;
        goto LABEL_91;
      case 0x2A:
      case 0x2B:
      case 0x2C:
      case 0x2D:
      case 0x2E:
      case 0x2F:
        i = *(_DWORD *)(v6 + 8) - 42;
LABEL_91:
        v28 = 1;
        v23 = 1;
        if ( gpGame->_4[i + 6] != 10 )
          gpGame->playerHandicap[i] = (gpGame->playerHandicap[i] + 1) % 3;
        goto LABEL_142;
      case 6:
      case 7:
      case 8:
      case 9:
      case 0xA:
      case 0xB:
        i = *(_DWORD *)(v6 + 8) - 6;
        goto LABEL_98;
      case 0xC:
      case 0xD:
      case 0xE:
      case 0xF:
      case 0x10:
      case 0x11:
        i = *(_DWORD *)(v6 + 8) - 12;
        goto LABEL_98;
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        i = *(_DWORD *)(v6 + 8) - 18;
        goto LABEL_98;
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
      case 0x1C:
      case 0x1D:
        i = *(_DWORD *)(v6 + 8) - 24;
LABEL_98:
        v28 = 1;
        v23 = 1;
        if ( gpGame->_5[i + 13] || iLastMsgNumHumanPlayers > 1 && gpGame->_4[i + 6] != 10 )
        {
          if ( iLastMsgNumHumanPlayers == 1 )
          {
            if ( gpGame->_4[i + 6] == 10 )
            {
              for ( j = 0; gpGame->_1[702] > j; ++j )
              {
                if ( gpGame->_4[j + 6] != 10 )
                {
                  v24 = gpGame->_4[j + 6];
                  gpGame->_4[j + 6] = gpGame->_4[i + 6];
                  gpGame->_4[i + 6] = v24;
                  j = 999;
                }
              }
            }
          }
          else if ( gpGame->_5[19] == -1 )
          {
            gpGame->_5[19] = i;
          }
          else if ( gpGame->_5[19] != i && (gpGame->_4[i + 6] != 10 || gpGame->_4[gpGame->_5[19] + 6] != 10) )
          {
            if ( gpGame->_5[i + 13] && gpGame->_5[gpGame->_5[19] + 13]
              || gpGame->_4[i + 6] != 10 && gpGame->_4[gpGame->_5[19] + 6] != 10 )
            {
              j = gpGame->_4[i + 6];
              gpGame->_4[i + 6] = gpGame->_4[gpGame->_5[19] + 6];
              gpGame->_4[gpGame->_5[19] + 6] = j;
            }
            else
            {
              NormalDialog("The two positions selected can not be swapped.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            gpGame->_5[19] = -1;
          }
          else
          {
            gpGame->_5[19] = -1;
          }
        }
        goto LABEL_142;
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x27:
      case 0x28:
      case 0x29:
        i = *(_DWORD *)(v6 + 8) - 36;
        goto LABEL_125;
      case 0x1E:
      case 0x1F:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
        i = *(_DWORD *)(v6 + 8) - 30;
LABEL_125:
        if ( gpGame->_2[gpGame->_3[i + 375] + 4] == 7 )
        {
          if ( gpGame->_4[i] == 7 )
          {
            gpGame->_4[i] = 0;
          }
          else if ( gpGame->_4[i] == 5 )
          {
            gpGame->_4[i] = 7;
          }
          else
          {
            ++gpGame->_4[i];
          }
          v28 = 1;
          v23 = 1;
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
  if ( v5 != 13 )
  {
LABEL_142:
    if ( v23 )
    {
      game::UpdateNewGameWindow((int)gpGame);
      heroWindow::DrawWindow(*(heroWindow **)&gpGame->_10[27]);
    }
    if ( v28 && gbRemoteOn )
    {
      memcpy(&v7, &gpGame->_3[13], 0x3Cu);
      memcpy(&v8, &gpGame->_3[375], 0x41u);
      v27 = TransmitRemoteData(&v7, 127, 0x7Du, 51, 1, 1, -1);
      if ( !v27 )
        ShutDown(0);
    }
    return 1;
  }
  v4 = *(_DWORD *)(v6 + 8);
  if ( v4 == 54 )
  {
LABEL_133:
    if ( !gbRemoteOn || !giThisNetPos )
    {
      v10 = 512;
      v11 = 6;
      v12 = 30721;
      v13 = 2;
      heroWindow::BroadcastMessage(*(heroWindow **)&gpGame->_10[27], (Event *)&v10);
      game::GetMap(gpGame);
      v10 = 512;
      v11 = 5;
      v12 = 30721;
      v13 = 2;
      heroWindow::BroadcastMessage(*(heroWindow **)&gpGame->_10[27], (Event *)&v10);
      if ( gbRemoteOn )
      {
        memcpy(&v9, &gpGame->_1[676], 0x74u);
        v27 = TransmitRemoteData(&v9, 127, 0x74u, 52, 1, 1, -1);
      }
    }
    goto LABEL_142;
  }
  if ( v4 == 30721 )
  {
    if ( gbRemoteOn )
    {
      v27 = TransmitRemoteData(0, 127, 0, 54, 1, 1, -1);
      ShutDown(0);
    }
    gpWindowManager->buttonPressedCode = *(_DWORD *)(v6 + 8);
    *(_DWORD *)(v6 + 8) = 10;
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 8);
    gbNewGameDialogOver = 1;
    result = 2;
  }
  else
  {
    if ( v4 != 30722 )
      goto LABEL_142;
    if ( gbRemoteOn )
      v27 = TransmitRemoteData(0, 127, 0, 53, 1, 1, -1);
    gpWindowManager->buttonPressedCode = *(_DWORD *)(v6 + 8);
    *(_DWORD *)(v6 + 8) = 10;
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 8);
    gbNewGameDialogOver = 1;
    result = 2;
  }
  return result;
}