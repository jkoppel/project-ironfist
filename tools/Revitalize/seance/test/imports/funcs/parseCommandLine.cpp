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

  dword_524BE0 = 1;
  dword_523EE0 = -1;
  dword_52340C = -1;
  dword_523410 = -1;
  strcpy(byte_5235B8, byte_50D014);
  strcpy(byte_524828, byte_50D018);
  dword_4F1CCC = 0;
  debugLogLevel = 0;
  dword_52409C = 1;
  soundDisabled = 0;
  debug_mode = 0;
  dword_4F19A4 = 1;
  dword_524794 = 0;
  dword_52473C = 1;
  v11 = 0;
  strcpy(byte_524740, "Chaos.mp2");
  strcpy(byte_523EF0, "Chaos");
  v12 = strlen(command_line);
  for ( i = 0; v12 > i; ++i )
  {
    if ( command_line[i] == ' '
      && i + 1 < v12
      && (command_line[i + 1] == '?' || command_line[i + 1] == 'h' || command_line[i + 1] == 'H') )
      v11 = 1;
    if ( command_line[i] == '/' && i + 1 < v12 )
    {
      v2 = charToUpper(command_line[i + 1]) - 68;
      switch ( v2 )
      {
        case 22:
          dword_4F746C = 0;
          break;
        case 19:
          dword_4F1CCC = 1;
          if ( i + 2 < v12 )
            dword_4F1CCC = command_line[i + 2] - 48;
          break;
        case 18:
          *(_DWORD *)&slowVideo = 1;
          propagateSettingChanges();
          break;
        case 10:
          if ( i + 3 < v12 && charToUpper(command_line[i + 2]) == 'W' && charToUpper(command_line[i + 3]) == 'C' )
            debug_mode = 1;
          break;
        case 9:
          if ( i + 2 < v12 )
            dword_4F1C94 = 1 - (command_line[i + 2] - 48);
          break;
        case 14:
          if ( i + 2 < v12 )
            dword_4F1C90 = 1 - (command_line[i + 2] - 48);
          break;
        case 0:
          if ( i + 2 < v12 )
            disableSound = 1 - (command_line[i + 2] - 48);
          break;
        case 15:
          if ( i + 2 < v12 )
            soundDisabled = 1 - (command_line[i + 2] - 48);
          break;
        case 5:
          if ( i + 2 < v12 )
            dword_52409C = command_line[i + 2] - 48;
          break;
        case 12:
          if ( i + 2 < v12 )
            debugLogLevel = command_line[i + 2] - 48;
          break;
        case 20:
          byte_4F74B8 = 1;
          break;
        case 16:
          if ( i + 2 < v12 )
          {
            v1 = charToUpper(command_line[i + 2]) - 65;
            switch ( v1 )
            {
              case 19:
                dword_523EE0 = i + 3 < v12 && charToUpper(command_line[i + 3]) == 76;
                break;
              case 18:
                dword_52340C = i + 3 < v12 && charToUpper(command_line[i + 3]) == 72;
                break;
              case 15:
                v7 = 0;
                if ( i + 3 < v12 )
                  v7 = command_line[i + 3] - 48;
                if ( v7 >= 2 && v7 <= 6 )
                  dword_523410 = v7;
                break;
              case 0:
                if ( i + 3 < v12 )
                {
                  v5 = 0;
                  for ( j = i + 3;
                        v5 < 20 && command_line[j] && command_line[j] != 32;
                        byte_5235B8[v5++] = command_line[j++] )
                    ;
                  byte_5235B8[v5] = 0;
                }
                break;
              case 13:
                if ( i + 3 < v12 )
                {
                  v3 = 0;
                  for ( k = i + 3;
                        v3 < 20 && command_line[k] && command_line[k] != 32;
                        byte_524828[v3++] = command_line[k++] )
                    ;
                  byte_524828[v3] = 0;
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
    sprintf(globBuf, byte_50D030);
    for ( l = 0; l < 14; ++l )
      strcat(globBuf, (&off_4F6F58)[4 * l]);
    terminate(globBuf);
  }
  sprintf(byte_524470, "%s%s", ".\\DATA\\", "heroes2.agg");
  heroes2agg_path = byte_524470;
  sprintf(byte_523458, "%s%s", ".\\DATA\\", "heroes2x.agg");
  heroes2xagg_path = byte_523458;
  dword_524CB4 = 6;
  for ( m = 0; m < 4; ++m )
    dword_524810[m] = dword_5235D4 > m;
  if ( dword_5235D4 == 1 )
    dword_52473C = 0;
  if ( dword_52340C != -1 )
  {
    if ( dword_523EE0 == -1 || dword_523410 == -1 || !dword_52340C && strlen(byte_5235B8) < 1 )
      terminate("Incomplete TCP/IP command line information");
    dword_52409C = 0;
  }
  return 1;
}
