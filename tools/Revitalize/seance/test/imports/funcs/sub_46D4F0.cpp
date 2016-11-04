{
  char *v1; // edi@44
  int v2; // esi@44
  void *v3; // [sp+14h] [bp-6Ch]@1
  signed int v4; // [sp+1Ch] [bp-64h]@39
  char v5[8]; // [sp+20h] [bp-60h]@39
  void *v6; // [sp+28h] [bp-58h]@41
  int v7; // [sp+2Ch] [bp-54h]@44
  void *v8; // [sp+34h] [bp-4Ch]@56
  int i; // [sp+38h] [bp-48h]@1
  int a2; // [sp+7Ch] [bp-4h]@5

  v3 = this;
  dword_512584 = 1;
  dword_526ED4 = 0;
  debugLog("In Remote Main");
  debugLog("RM 1");
  for ( i = 0; i < 6; ++i )
  {
    dword_526DB0[i] = 1999999999;
    sprintf((char *)&dword_526CE0 + 34 * i + 4, "Player %d", i + 1);
  }
  debugLog("RM 2");
  dword_524A6C = 1;
  if ( dword_51F6EC )
    a2 = dword_51F6F0;
  else
    a2 = dword_4F19B0;
  sub_4CEB90(mouseManager, 0);
  debugLog("RM 3");
  byte_512594 = 1;
  if ( dword_4F31B4 == 1 )
  {
    dword_512598 = 1;
  }
  else
  {
    if ( dword_4F31B4 == 2 )
    {
      dword_51259C = 1;
    }
    else
    {
      dword_51259C = 0;
      dword_512598 = 0;
    }
  }
  debugLog("RM 4");
  memset(&byte_523660, 0, 0x86Cu);
  for ( i = 0; i < 128; ++i )
    dword_527438[i] = 0;
  debugLog("RM 5");
  memset(&dword_527660, 0, 0x1Eu);
  byte_51257C = (char)v3;
  debugLog("RM 6");
  memset(&dword_526CE0, 0, 0xCCu);
  memset(&unk_526CB8, 0, 0x22u);
  debugLog("RM 7");
  if ( dword_52340C == -1 )
  {
    sub_4CAEF0(
      "Please enter a 'handle' by which you will be known.",
      (int)&unk_526CBC,
      20,
      (const char *)&computerWalkSpeed + 392,
      1u,
      0);
  }
  else
  {
    if ( strlen(byte_524828) )
      strcpy((char *)&unk_526CB8 + 4, byte_524828);
    else
      strcpy((char *)&unk_526CB8 + 4, (const char *)&computerWalkSpeed + 392);
  }
  strcpy((char *)&computerWalkSpeed + 392, (const char *)&unk_526CB8 + 4);
  propagateSettingChanges();
  strcpy((char *)&unk_526CB8, (const char *)&computerWalkSpeed + 290);
  byte_526CD1 = 2;
  byte_526CD2 = 1;
  byte_526CD3 = 1;
  byte_526CD4 = 1;
  byte_51AC64 = 0;
  switch ( v3 )
  {
    case 1u:
      memcpy(&dword_526CE0, &unk_526CB8, 0x22u);
      dword_523F14 = 0;
      goto LABEL_24;
    case 2u:
      dword_523F14 = 1;
LABEL_24:
      if ( dword_512598 )
      {
        dword_4F7494 = 1;
        sub_404760();
      }
      else
      {
        if ( dword_51259C )
        {
          sub_45EF50();
          dword_4F7494 = 1;
        }
        else
        {
          sub_40EBF0();
          dword_4F7494 = 1;
        }
      }
      break;
    case 3u:
      debugLog("MH1");
      dword_4F7494 = 1;
      memcpy(&dword_526CE0, &unk_526CB8, 0x22u);
      dword_523F14 = 0;
      sub_463E60(v3);
      debugLog("MH2");
      break;
    case 4u:
      dword_4F7494 = 1;
      dword_523F14 = 1;
      sub_463E60(v3);
      break;
    default:
      break;
  }
  if ( !dword_512598 && !dword_51259C )
    dword_5235D4 = 2;
  dword_51258C = 100000000 * (dword_523F14 + 1);
  byte_512594 = 0;
  sub_4CEB90(mouseManager, a2);
  if ( !dword_512598 && !dword_51259C )
  {
    debugLog("RM 2");
    if ( dword_523F14 )
    {
      debugLog("RM 5");
      sub_46E1D0(&unk_526CB8, 0, 0x22u, 34, 1, 1, -1);
      debugLog("RM 6");
    }
    else
    {
      v4 = 1;
      memset(v5, 0, 6u);
      while ( v4 )
      {
        yieldToGlobalUpdater();
        debugLog("RM 3");
        v6 = sub_46E3F0(1);
        debugLog("RM 4");
        if ( v6 )
        {
          if ( *((_BYTE *)v6 + 5) == 2 )
          {
            if ( *((_BYTE *)v6 + 6) == 34 )
            {
              v7 = *(_BYTE *)v6;
              v1 = (char *)&dword_526CE0 + 34 * v7;
              v2 = (int)((char *)v6 + 9);
              memcpy(v1, (char *)v6 + 9, 0x20u);
              *((_WORD *)v1 + 16) = *(_WORD *)(v2 + 32);
              v5[v7] = 1;
              if ( !byte_526CFC[34 * v7] )
                byte_51AC64 = 1;
            }
          }
        }
        v4 = 0;
        for ( i = 1; dword_5235D4 > i; ++i )
        {
          if ( !v5[i] )
            v4 = 1;
        }
      }
    }
  }
  v8 = 0;
  if ( dword_523F14 )
  {
    while ( !dword_526ED4 )
    {
      yieldToGlobalUpdater();
      v8 = sub_46E3F0(1);
      if ( v8 && *((_BYTE *)v8 + 5) == 2 && *((_BYTE *)v8 + 6) == 62 )
      {
        dword_526ED4 = 1;
        byte_523004 = 1;
      }
      if ( v8 && *((_BYTE *)v8 + 5) == 2 && *((_BYTE *)v8 + 6) == 61 )
      {
        dword_526ED4 = 1;
        byte_523004 = 0;
      }
    }
  }
  else
  {
    sub_46E1D0(0, 127, 0, ((unsigned int)(unsigned __int8)byte_523004 - 1 < 1) + 61, 1, 1, -1);
  }
  debugLog("Out Remote Main");
  dword_512584 = 0;
}
