{
  signed int result; // eax@180
  signed int v3; // [sp+1Ch] [bp-410h]@50
  signed int v4; // [sp+20h] [bp-40Ch]@28
  int v5; // [sp+24h] [bp-408h]@27
  int v6; // [sp+28h] [bp-404h]@2
  int v7; // [sp+2Ch] [bp-400h]@1
  int v8; // [sp+30h] [bp-3FCh]@1
  char v9; // [sp+3Ch] [bp-3F0h]@99
  int v10; // [sp+168h] [bp-2C4h]@131
  int evt; // [sp+16Ch] [bp-2C0h]@108
  int v12; // [sp+170h] [bp-2BCh]@108
  int v13; // [sp+174h] [bp-2B8h]@108
  char *v14; // [sp+184h] [bp-2A8h]@108
  int v15; // [sp+188h] [bp-2A4h]@50
  char v16; // [sp+18Ch] [bp-2A0h]@4
  size_t v17; // [sp+2B8h] [bp-174h]@108
  int i; // [sp+2BCh] [bp-170h]@7
  int v19; // [sp+2C0h] [bp-16Ch]@133
  int v20; // [sp+2C4h] [bp-168h]@133
  int v21; // [sp+2C8h] [bp-164h]@1
  char chr[4]; // [sp+2CCh] [bp-160h]@108

  v8 = this;
  v21 = 0;
  v7 = *(_DWORD *)a2;
  if ( v7 == 1 )
  {
    v6 = *(_DWORD *)(a2 + 4);
    if ( v6 == 64 )
    {
      if ( *(_DWORD *)(this + 1050) == -1 )
        strcpy(&v16, byte_4EDF2C);
      else
        strcpy(&v16, (const char *)(*(_DWORD *)(this + 670) + 351 * *(_DWORD *)(this + 1050)));
      dword_4EDE90 = (dword_4EDE90 + 1) % 5;
      sub_40BF30(v8);
      if ( strlen(&v16) )
      {
        for ( i = 0; *(_DWORD *)(v8 + 1042) > i; ++i )
        {
          if ( !_strcmpi((const char *)(351 * i + *(_DWORD *)(v8 + 670)), &v16) )
            *(_DWORD *)(v8 + 1050) = i;
        }
      }
      sub_40DA80(v8, 1);
    }
    else
    {
      if ( v6 == 72 )
      {
        if ( *(_DWORD *)(this + 1050) > 0 )
        {
          --*(_DWORD *)(this + 1050);
          if ( *(_DWORD *)(this + 1046) > *(_DWORD *)(this + 1050) )
            --*(_DWORD *)(this + 1046);
          sub_40DA80(this, 1);
        }
      }
      else
      {
        if ( v6 == 80 && *(_DWORD *)(this + 1042) - 1 > *(_DWORD *)(this + 1050) )
        {
          ++*(_DWORD *)(this + 1050);
          if ( dword_522BF4 + *(_DWORD *)(this + 1046) <= *(_DWORD *)(this + 1050) )
            ++*(_DWORD *)(this + 1046);
          sub_40DA80(this, 1);
        }
      }
    }
  }
  else
  {
    if ( v7 != 512 )
      goto LABEL_167;
    v5 = *(_DWORD *)(a2 + 4);
    if ( v5 != 12 )
    {
      if ( v5 == 13 )
      {
        v4 = *(_DWORD *)(a2 + 8);
        if ( v4 > 30721 )
        {
          if ( v4 == 30722 )
          {
            if ( *(_DWORD *)(this + 1050) != -1 || *(_BYTE *)(this + 691) )
            {
              *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 8);
              v21 = 1;
            }
            else
            {
              display_message_window(
                "Please make a selection from the list, or press cancel.",
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
          }
        }
        else
        {
          if ( v4 == 30721 )
          {
            *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 8);
            v21 = 1;
          }
          else
          {
            if ( v4 == 1 )
            {
              if ( *(_DWORD *)(this + 1046) > 0 )
              {
                --*(_DWORD *)(this + 1046);
                sub_40DA80(this, 1);
              }
            }
            else
            {
              if ( v4 == 2 && dword_522BF4 + *(_DWORD *)(this + 1046) < *(_DWORD *)(this + 1042) )
              {
                ++*(_DWORD *)(this + 1046);
                if ( dword_522BF4 + *(_DWORD *)(this + 1046) - 1 >= *(_DWORD *)(this + 1042) )
                  *(_DWORD *)(this + 1046) = *(_DWORD *)(this + 1042) - dword_522BF4;
                sub_40DA80(this, 1);
              }
            }
          }
        }
        goto LABEL_167;
      }
      if ( v5 != 14 )
        goto LABEL_167;
    }
    if ( *(_BYTE *)(a2 + 13) & 2 )
    {
      v15 = -1;
      v3 = *(_DWORD *)(a2 + 8);
      if ( v3 > 80 )
      {
        if ( v3 <= 30721 )
        {
          if ( v3 == 30721 )
          {
            v15 = 7;
          }
          else
          {
            switch ( v3 )
            {
              case 100:
                v15 = 0;
                break;
              case 101:
                v15 = 1;
                break;
              case 102:
                v15 = 2;
                break;
              case 103:
                v15 = 3;
                break;
              case 104:
                v15 = 4;
                break;
              case 82:
                v15 = 8;
                break;
              case 81:
                v15 = 9;
                break;
              case 86:
                v15 = 10;
                break;
              case 87:
                v15 = 11;
                break;
              case 85:
                v15 = 13;
                break;
              case 83:
                v15 = 14;
                break;
              case 84:
                v15 = 14;
                break;
              default:
                goto LABEL_67;
            }
          }
          goto LABEL_89;
        }
        if ( v3 != 30722 )
          goto LABEL_67;
        v15 = 6;
      }
      else
      {
        if ( v3 == 80 )
        {
          v15 = 12;
        }
        else
        {
          if ( v3 != 15 )
          {
LABEL_67:
            if ( *(_DWORD *)(a2 + 8) < 200 || *(_DWORD *)(a2 + 8) >= 220 )
            {
              if ( *(_DWORD *)(a2 + 8) < 220 || *(_DWORD *)(a2 + 8) >= 240 )
              {
                if ( *(_DWORD *)(a2 + 8) < 240 || *(_DWORD *)(a2 + 8) >= 260 )
                {
                  if ( *(_DWORD *)(a2 + 8) >= 260 && *(_DWORD *)(a2 + 8) < 280 )
                    v15 = 11;
                }
                else
                {
                  v15 = 10;
                }
              }
              else
              {
                v15 = 9;
              }
            }
            else
            {
              v15 = 8;
            }
            goto LABEL_89;
          }
          v15 = 5;
        }
      }
LABEL_89:
      if ( v15 >= 0 )
        display_message_window((&off_4F6FE8)[4 * v15], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      goto LABEL_167;
    }
    switch ( *(_DWORD *)(a2 + 8) )
    {
      case 0x64:
      case 0x65:
      case 0x66:
      case 0x67:
      case 0x68:
        i = *(_DWORD *)(a2 + 8) - 100;
        if ( sub_40BEC0((void *)this, i) )
        {
          dword_4EDE90 = i;
          if ( *(_DWORD *)(v8 + 1050) == -1 )
            strcpy(&v9, byte_4EDFCC);
          else
            strcpy(&v9, (const char *)(*(_DWORD *)(v8 + 670) + 351 * *(_DWORD *)(v8 + 1050)));
          sub_40BF30(v8);
          if ( strlen(&v9) )
          {
            for ( i = 0; *(_DWORD *)(v8 + 1042) > i; ++i )
            {
              if ( !_strcmpi((const char *)(351 * i + *(_DWORD *)(v8 + 670)), &v9) )
                *(_DWORD *)(v8 + 1050) = i;
            }
          }
          sub_40DA80(v8, 1);
        }
        else
        {
          if ( dword_5235D4 == 1 )
            sprintf(globBuf, "No maps exist for %d human player at that size.", dword_5235D4);
          else
            sprintf(globBuf, "No maps exist for %d human players at that size.", dword_5235D4);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
        break;
      case 0xF:
        evt = 512;
        v12 = 7;
        v13 = 15;
        GUIWindow::processMessage(*(GUIWindow **)(this + 54), (Event *)&evt);
        memset(chr, 0, 9u);
        strcpy(chr, v14);
        v17 = strlen(chr);
        for ( i = 0; i < (signed int)v17; ++i )
        {
          if ( (chr[i] < 65 || chr[i] > 90)
            && (chr[i] < 97 || chr[i] > 122)
            && (chr[i] < 48 || chr[i] > 57)
            && chr[i] != 95
            && chr[i] != 32
            && !findCharInString("$%'-_@~`!(){}^#&+,;=[].", *(_DWORD *)&chr[i]) )
            chr[i] = 0;
        }
        for ( i = strlen(chr) - 1; i >= 0; --i )
        {
          if ( chr[i] == 32 )
            chr[i] = 0;
          else
            i = -1;
        }
        if ( strlen(chr) && chr[0] > 32 )
        {
          *(_DWORD *)(v8 + 1050) = -1;
          strcpy((char *)(v8 + 691), chr);
          sub_40C570(v8, 1);
        }
        v12 = 3;
        v13 = 15;
        v14 = (char *)(v8 + 691);
        GUIWindow::processMessage(*(GUIWindow **)(v8 + 54), (Event *)&evt);
        sub_40DA80(v8, 1);
        break;
      case 3:
        v10 = *(_DWORD *)(this + 1042) - (dword_522BF4 - 1);
        if ( v10 < 1 )
          v10 = 1;
        v20 = *(_DWORD *)(a2 + 16);
        v19 = (unsigned __int64)(signed __int64)((double)*(signed int *)(a2 + 20)
                                               - ((double)*(signed int *)(this + 62)
                                                + *(float *)&dword_522BEC))
            - 9;
        *(_DWORD *)(this + 1046) = 100
                                 * v19
                                 / (signed int)(signed __int64)(*(float *)&dword_522BF0 * 100.0 / (double)v10);
        if ( dword_522BF4 + *(_DWORD *)(this + 1046) - 1 >= *(_DWORD *)(this + 1042) )
          *(_DWORD *)(this + 1046) = *(_DWORD *)(this + 1042) - dword_522BF4;
        if ( *(_DWORD *)(this + 1046) < 0 )
          *(_DWORD *)(this + 1046) = 0;
        sub_40DA80(this, 1);
        break;
      case 0xE:
        sub_40D7C0(this);
        break;
      default:
        if ( *(_DWORD *)(a2 + 8) < 200 || *(_DWORD *)(a2 + 8) > 219 )
        {
          if ( *(_DWORD *)(a2 + 8) < 220 || *(_DWORD *)(a2 + 8) > 239 )
          {
            if ( *(_DWORD *)(a2 + 8) < 240 || *(_DWORD *)(a2 + 8) > 259 )
            {
              if ( *(_DWORD *)(a2 + 8) < 260 || *(_DWORD *)(a2 + 8) > 279 )
              {
                if ( *(_DWORD *)(a2 + 8) < 20 || *(_DWORD *)(a2 + 8) > 39 )
                  goto LABEL_167;
                i = *(_DWORD *)(a2 + 8) - 20;
              }
              else
              {
                i = *(_DWORD *)(a2 + 8) - 260;
              }
            }
            else
            {
              i = *(_DWORD *)(a2 + 8) - 240;
            }
          }
          else
          {
            i = *(_DWORD *)(a2 + 8) - 220;
          }
        }
        else
        {
          i = *(_DWORD *)(a2 + 8) - 200;
        }
        if ( i + *(_DWORD *)(this + 1046) == *(_DWORD *)(this + 1050) )
        {
          *(_DWORD *)(a2 + 24) = 30722;
          *(_DWORD *)(a2 + 8) = 30722;
          v21 = 1;
        }
        else
        {
          if ( i + *(_DWORD *)(this + 1046) < *(_DWORD *)(this + 1042) )
          {
            *(_DWORD *)(this + 1050) = i + *(_DWORD *)(this + 1046);
            sub_40C570(this, 1);
            sub_40DA80(v8, 1);
          }
        }
        break;
    }
  }
  if ( v21 != 1 )
    goto LABEL_184;
LABEL_167:
  if ( *(_DWORD *)(v8 + 66) == 2
    && *(_DWORD *)(v8 + 1050) >= 0
    && *(_DWORD *)(a2 + 24) != 30721
    && _strcmpi((const char *)(*(_DWORD *)(v8 + 674) + 5 * *(_DWORD *)(v8 + 1050)), ".GMC")
    && _strcmpi((const char *)(*(_DWORD *)(v8 + 674) + 5 * *(_DWORD *)(v8 + 1050)), ".GXC") )
  {
    i = *(_BYTE *)(5 * *(_DWORD *)(v8 + 1050) + *(_DWORD *)(v8 + 674) + 3) - 48;
    if ( i < dword_5235D4 && debugLogLevel < 2 )
    {
      sprintf(
        globBuf,
        "The game you have chosen only has slots for %d human(s).  You need one with room for at least %d humans.",
        i,
        dword_5235D4);
      display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      v21 = 0;
    }
    if ( i > dword_5235D4 )
    {
      sprintf(
        globBuf,
        "The game you have chosen was being played with %d humans. Is it OK if the computer takes the place of the last %d human(s)?",
        i,
        i - dword_5235D4);
      display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
        v21 = 0;
    }
  }
  if ( v21 )
  {
    *(_DWORD *)a2 = 16384;
    *(_DWORD *)(a2 + 4) = 4;
    result = 2;
  }
  else
  {
LABEL_184:
    result = 1;
  }
  return result;
}
