signed int __thiscall FileRequester::handleInput(int this, int a2)
{
  int v2; // eax@6
  int v3; // eax@98
  int v4; // eax@165
  int v5; // eax@166
  signed int result; // eax@174
  signed int v7; // [sp+1Ch] [bp-410h]@47
  signed int v8; // [sp+20h] [bp-40Ch]@25
  int v9; // [sp+24h] [bp-408h]@24
  int v10; // [sp+28h] [bp-404h]@2
  int v11; // [sp+2Ch] [bp-400h]@1
  int v12; // [sp+30h] [bp-3FCh]@1
  char v13; // [sp+3Ch] [bp-3F0h]@95
  int v14; // [sp+168h] [bp-2C4h]@125
  int evt; // [sp+16Ch] [bp-2C0h]@102
  int v16; // [sp+170h] [bp-2BCh]@102
  int v17; // [sp+174h] [bp-2B8h]@102
  char *v18; // [sp+184h] [bp-2A8h]@124
  int v19; // [sp+188h] [bp-2A4h]@47
  char a2a; // [sp+18Ch] [bp-2A0h]@3
  int v21; // [sp+2B8h] [bp-174h]@102
  int i; // [sp+2BCh] [bp-170h]@4
  int v23; // [sp+2C0h] [bp-16Ch]@127
  int v24; // [sp+2C4h] [bp-168h]@127
  int v25; // [sp+2C8h] [bp-164h]@1
  char chr[4]; // [sp+2CCh] [bp-160h]@102

  v12 = this;
  v25 = 0;
  v11 = *(_DWORD *)a2;
  if ( v11 == 1 )
  {
    v10 = *(_DWORD *)(a2 + 4);
    if ( v10 == 64 )
    {
      strcpy((int)&a2a);
      dword_4EDE90 = (dword_4EDE90 + 1) % 5;
      sub_40BF30(v12);
      if ( strlen((int)&a2a) )
      {
        for ( i = 0; *(_DWORD *)(v12 + 1042) > i; ++i )
        {
          LOBYTE(v2) = _strcmpi((char *)(351 * i + *(_DWORD *)(v12 + 670)), &a2a);
          if ( !v2 )
            *(_DWORD *)(v12 + 1050) = i;
        }
      }
      sub_40DA80(v12, 1);
    }
    else
    {
      if ( v10 == 72 )
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
        if ( v10 == 80 && *(_DWORD *)(this + 1042) - 1 > *(_DWORD *)(this + 1050) )
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
    if ( v11 != 512 )
      goto LABEL_161;
    v9 = *(_DWORD *)(a2 + 4);
    if ( v9 != 12 )
    {
      if ( v9 == 13 )
      {
        v8 = *(_DWORD *)(a2 + 8);
        if ( v8 > 30721 )
        {
          if ( v8 == 30722 )
          {
            if ( *(_DWORD *)(this + 1050) != -1 || *(_BYTE *)(this + 691) )
            {
              *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 8);
              v25 = 1;
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
          if ( v8 == 30721 )
          {
            *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 8);
            v25 = 1;
          }
          else
          {
            if ( v8 == 1 )
            {
              if ( *(_DWORD *)(this + 1046) > 0 )
              {
                --*(_DWORD *)(this + 1046);
                sub_40DA80(this, 1);
              }
            }
            else
            {
              if ( v8 == 2 && dword_522BF4 + *(_DWORD *)(this + 1046) < *(_DWORD *)(this + 1042) )
              {
                ++*(_DWORD *)(this + 1046);
                if ( dword_522BF4 + *(_DWORD *)(this + 1046) - 1 >= *(_DWORD *)(this + 1042) )
                  *(_DWORD *)(this + 1046) = *(_DWORD *)(this + 1042) - dword_522BF4;
                sub_40DA80(this, 1);
              }
            }
          }
        }
        goto LABEL_161;
      }
      if ( v9 != 14 )
        goto LABEL_161;
    }
    if ( *(_BYTE *)(a2 + 13) & 2 )
    {
      v19 = -1;
      v7 = *(_DWORD *)(a2 + 8);
      if ( v7 > 80 )
      {
        if ( v7 <= 30721 )
        {
          if ( v7 == 30721 )
          {
            v19 = 7;
          }
          else
          {
            switch ( v7 )
            {
              case 100:
                v19 = 0;
                break;
              case 101:
                v19 = 1;
                break;
              case 102:
                v19 = 2;
                break;
              case 103:
                v19 = 3;
                break;
              case 104:
                v19 = 4;
                break;
              case 82:
                v19 = 8;
                break;
              case 81:
                v19 = 9;
                break;
              case 86:
                v19 = 10;
                break;
              case 87:
                v19 = 11;
                break;
              case 85:
                v19 = 13;
                break;
              case 83:
                v19 = 14;
                break;
              case 84:
                v19 = 14;
                break;
              default:
                goto LABEL_64;
            }
          }
          goto LABEL_86;
        }
        if ( v7 != 30722 )
          goto LABEL_64;
        v19 = 6;
      }
      else
      {
        if ( v7 == 80 )
        {
          v19 = 12;
        }
        else
        {
          if ( v7 != 15 )
          {
LABEL_64:
            if ( *(_DWORD *)(a2 + 8) < 200 || *(_DWORD *)(a2 + 8) >= 220 )
            {
              if ( *(_DWORD *)(a2 + 8) < 220 || *(_DWORD *)(a2 + 8) >= 240 )
              {
                if ( *(_DWORD *)(a2 + 8) < 240 || *(_DWORD *)(a2 + 8) >= 260 )
                {
                  if ( *(_DWORD *)(a2 + 8) >= 260 && *(_DWORD *)(a2 + 8) < 280 )
                    v19 = 11;
                }
                else
                {
                  v19 = 10;
                }
              }
              else
              {
                v19 = 9;
              }
            }
            else
            {
              v19 = 8;
            }
            goto LABEL_86;
          }
          v19 = 5;
        }
      }
LABEL_86:
      if ( v19 >= 0 )
        display_message_window((&off_4F6FE8)[4 * v19], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      goto LABEL_161;
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
          strcpy((int)&v13);
          sub_40BF30(v12);
          if ( strlen((int)&v13) )
          {
            for ( i = 0; *(_DWORD *)(v12 + 1042) > i; ++i )
            {
              LOBYTE(v3) = _strcmpi((char *)(351 * i + *(_DWORD *)(v12 + 670)), &v13);
              if ( !v3 )
                *(_DWORD *)(v12 + 1050) = i;
            }
          }
          sub_40DA80(v12, 1);
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
        v16 = 7;
        v17 = 15;
        GUIWindow::processMessage(*(GUIWindow **)(this + 54), (Event *)&evt);
        memset(chr, 0, 9u);
        strcpy((int)chr);
        v21 = strlen((int)chr);
        for ( i = 0; i < v21; ++i )
        {
          if ( (chr[i] < 65 || chr[i] > 90)
            && (chr[i] < 97 || chr[i] > 122)
            && (chr[i] < 48 || chr[i] > 57)
            && chr[i] != 95
            && chr[i] != 32
            && !findCharInString("$%'-_@~`!(){}^#&+,;=[].", *(_DWORD *)&chr[i]) )
            chr[i] = 0;
        }
        for ( i = strlen((int)chr) - 1; i >= 0; --i )
        {
          if ( chr[i] == 32 )
            chr[i] = 0;
          else
            i = -1;
        }
        if ( strlen((int)chr) && chr[0] > 32 )
        {
          *(_DWORD *)(v12 + 1050) = -1;
          strcpy(v12 + 691);
          sub_40C570(v12, 1);
        }
        v16 = 3;
        v17 = 15;
        v18 = (char *)(v12 + 691);
        GUIWindow::processMessage(*(GUIWindow **)(v12 + 54), (Event *)&evt);
        sub_40DA80(v12, 1);
        break;
      case 3:
        v14 = *(_DWORD *)(this + 1042) - (dword_522BF4 - 1);
        if ( v14 < 1 )
          v14 = 1;
        v24 = *(_DWORD *)(a2 + 16);
        v23 = (unsigned __int64)(signed __int64)((double)*(signed int *)(a2 + 20)
                                               - ((double)*(signed int *)(this + 62)
                                                + *(float *)&dword_522BEC))
            - 9;
        *(_DWORD *)(this + 1046) = 100
                                 * v23
                                 / (signed int)(signed __int64)(*(float *)&dword_522BF0 * 100.0 / (double)v14);
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
                  goto LABEL_161;
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
          v25 = 1;
        }
        else
        {
          if ( i + *(_DWORD *)(this + 1046) < *(_DWORD *)(this + 1042) )
          {
            *(_DWORD *)(this + 1050) = i + *(_DWORD *)(this + 1046);
            sub_40C570(this, 1);
            sub_40DA80(v12, 1);
          }
        }
        break;
    }
  }
  if ( v25 != 1 )
    goto LABEL_178;
LABEL_161:
  if ( *(_DWORD *)(v12 + 66) == 2 )
  {
    if ( *(_DWORD *)(v12 + 1050) >= 0 )
    {
      if ( *(_DWORD *)(a2 + 24) != 30721 )
      {
        LOBYTE(v4) = _strcmpi((char *)(*(_DWORD *)(v12 + 674) + 5 * *(_DWORD *)(v12 + 1050)), ".GMC");
        if ( v4 )
        {
          LOBYTE(v5) = _strcmpi((char *)(*(_DWORD *)(v12 + 674) + 5 * *(_DWORD *)(v12 + 1050)), ".GXC");
          if ( v5 )
          {
            i = *(_BYTE *)(5 * *(_DWORD *)(v12 + 1050) + *(_DWORD *)(v12 + 674) + 3) - 48;
            if ( i < dword_5235D4 && debugLogLevel < 2 )
            {
              sprintf(
                globBuf,
                "The game you have chosen only has slots for %d human(s).  You need one with room for at least %d humans.",
                i,
                dword_5235D4);
              display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
              v25 = 0;
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
                v25 = 0;
            }
          }
        }
      }
    }
  }
  if ( v25 )
  {
    *(_DWORD *)a2 = 16384;
    *(_DWORD *)(a2 + 4) = 4;
    result = 2;
  }
  else
  {
LABEL_178:
    result = 1;
  }
  return result;
}
