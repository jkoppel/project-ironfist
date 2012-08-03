{
  int v1; // [sp+Ch] [bp-28h]@43
  int v2; // [sp+10h] [bp-24h]@12
  signed int v3; // [sp+14h] [bp-20h]@69
  int k; // [sp+18h] [bp-1Ch]@69
  signed int v5; // [sp+1Ch] [bp-18h]@61
  int j; // [sp+20h] [bp-14h]@61
  int v7; // [sp+24h] [bp-10h]@54
  int i; // [sp+28h] [bp-Ch]@1
  signed int l; // [sp+28h] [bp-Ch]@81
  signed int m; // [sp+28h] [bp-Ch]@85
  signed int v11; // [sp+2Ch] [bp-8h]@1
  int v12; // [sp+30h] [bp-4h]@1

  gbTCPFirstTime = 1;
  giTCPType = -1;
  giTCPHostStatus = -1;
  giTCPNumPlayers = -1;
  strcpy(gcTCPAddress, byte_50D014);
  strcpy(gcTCPName, byte_50D018);
  gbUseWaveout = 0;
  giDebugLevel = 0;
  giShowIntro = 1;
  gbNoSound = 0;
  gbCheatMenus = 0;
  giScreenScroll = 1;
  giLimitPlayer = 0;
  gbBlackoutPlayer = 1;
  v11 = 0;
  strcpy(gMapName, "Chaos.mp2");
  strcpy(gFullMapName, "Chaos");
  v12 = strlen((int)gcCommandLine);
  for ( i = 0; v12 > i; ++i )
  {
    if ( gcCommandLine[i] == ' '
      && i + 1 < v12
      && (gcCommandLine[i + 1] == '?' || gcCommandLine[i + 1] == 'h' || gcCommandLine[i + 1] == 'H') )
      v11 = 1;
    if ( gcCommandLine[i] == '/' && i + 1 < v12 )
    {
      v2 = toupper(gcCommandLine[i + 1]) - 68;
      switch ( v2 )
      {
        case 22:
          dword_4F746C = 0;
          break;
        case 19:
          gbUseWaveout = 1;
          if ( i + 2 < v12 )
            gbUseWaveout = gcCommandLine[i + 2] - 48;
          break;
        case 18:
          *(_DWORD *)&slowVideo = 1;
          WritePrefs();
          break;
        case 10:
          if ( i + 3 < v12 && toupper(gcCommandLine[i + 2]) == 'W' && toupper(gcCommandLine[i + 3]) == 'C' )
            gbCheatMenus = 1;
          break;
        case 9:
          if ( i + 2 < v12 )
            gbDontTryMIDI = 1 - (gcCommandLine[i + 2] - 48);
          break;
        case 14:
          if ( i + 2 < v12 )
            gbDontTryRedbook = 1 - (gcCommandLine[i + 2] - 48);
          break;
        case 0:
          if ( i + 2 < v12 )
            gbDontTryDigital = 1 - (gcCommandLine[i + 2] - 48);
          break;
        case 15:
          if ( i + 2 < v12 )
            gbNoSound = 1 - (gcCommandLine[i + 2] - 48);
          break;
        case 5:
          if ( i + 2 < v12 )
            giShowIntro = gcCommandLine[i + 2] - 48;
          break;
        case 12:
          if ( i + 2 < v12 )
            giDebugLevel = gcCommandLine[i + 2] - 48;
          break;
        case 20:
          byte_4F74B8 = 1;
          break;
        case 16:
          if ( i + 2 < v12 )
          {
            v1 = toupper(gcCommandLine[i + 2]) - 65;
            switch ( v1 )
            {
              case 19:
                giTCPType = i + 3 < v12 && toupper(gcCommandLine[i + 3]) == 76;
                break;
              case 18:
                giTCPHostStatus = i + 3 < v12 && toupper(gcCommandLine[i + 3]) == 72;
                break;
              case 15:
                v7 = 0;
                if ( i + 3 < v12 )
                  v7 = gcCommandLine[i + 3] - 48;
                if ( v7 >= 2 && v7 <= 6 )
                  giTCPNumPlayers = v7;
                break;
              case 0:
                if ( i + 3 < v12 )
                {
                  v5 = 0;
                  for ( j = i + 3;
                        v5 < 20 && gcCommandLine[j] && gcCommandLine[j] != 32;
                        gcTCPAddress[v5++] = gcCommandLine[j++] )
                    ;
                  gcTCPAddress[v5] = 0;
                }
                break;
              case 13:
                if ( i + 3 < v12 )
                {
                  v3 = 0;
                  for ( k = i + 3;
                        v3 < 20 && gcCommandLine[k] && gcCommandLine[k] != 32;
                        gcTCPName[v3++] = gcCommandLine[k++] )
                    ;
                  gcTCPName[v3] = 0;
                }
                break;
              default:
                continue;
            }
          }
          continue;
        default:
          continue;
      }
    }
  }
  if ( v11 )
  {
    sprintf(gText, byte_50D030);
    for ( l = 0; l < 14; ++l )
      strcat(gText, (&gcCommandLineHelp)[4 * l]);
    ShutDown(gText);
  }
  sprintf(cAggPathName, "%s%s", ".\\DATA\\", "heroes2.agg");
  DEFAULT_AGGREGATE_NAME = cAggPathName;
  sprintf(cExpAggPathName, "%s%s", ".\\DATA\\", "heroes2x.agg");
  EXPANSION_AGGREGATE_NAME = cExpAggPathName;
  giFrameStep = 6;
  for ( m = 0; m < 4; ++m )
    gbHumanPlayer[m] = iLastMsgNumHumanPlayers > m;
  if ( iLastMsgNumHumanPlayers == 1 )
    gbBlackoutPlayer = 0;
  if ( giTCPHostStatus != -1 )
  {
    if ( giTCPType == -1 || giTCPNumPlayers == -1 || !giTCPHostStatus && (unsigned int)strlen((int)gcTCPAddress) < 1 )
      ShutDown("Incomplete TCP/IP command line information");
    giShowIntro = 0;
  }
  return 1;
}