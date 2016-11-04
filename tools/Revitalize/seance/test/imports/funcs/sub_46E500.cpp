{
  int v0; // ST40_4@29
  int v1; // eax@29
  int v2; // ST34_4@43
  int v3; // eax@43
  int a2; // [sp+Ch] [bp-30h]@18
  __int16 v5; // [sp+18h] [bp-24h]@0
  char v6; // [sp+1Ah] [bp-22h]@0
  signed int v7; // [sp+1Ch] [bp-20h]@33
  __int16 v8; // [sp+24h] [bp-18h]@0
  char v9; // [sp+26h] [bp-16h]@0
  char v10; // [sp+28h] [bp-14h]@12
  void *i; // [sp+2Ch] [bp-10h]@22
  signed int j; // [sp+2Ch] [bp-10h]@48
  signed int k; // [sp+2Ch] [bp-10h]@69
  signed int l; // [sp+2Ch] [bp-10h]@74
  signed int m; // [sp+2Ch] [bp-10h]@78
  int v16; // [sp+30h] [bp-Ch]@12
  signed int v17; // [sp+34h] [bp-8h]@55
  int v18; // [sp+38h] [bp-4h]@12

  if ( dword_4F7494 && !dword_512588 )
  {
    if ( dword_524778 )
    {
      if ( dword_524778 == 1 )
      {
        if ( dword_512598 )
        {
          sub_404EA0();
        }
        else
        {
          if ( dword_51259C )
            sub_45F910();
          else
            sub_473630();
        }
      }
    }
    else
    {
      sub_4BD380();
    }
    if ( !byte_512594 )
    {
      v16 = 0;
      v18 = lockUsedInGlobalUpdatesOnTimer;
      v10 = 0;
      if ( getTickCount() - dword_512580 > 5000 )
      {
        byte_527108 = dword_523F14;
        byte_52710D = 4;
        word_52710F = 0;
        if ( dword_523ED4 )
          byte_52710E = qword_50EAA8 | (unsigned __int8)(16 * (curPlayerIdx + 1)) | 0x80;
        else
          byte_52710E = 0;
        if ( dword_523F14 && !dword_523ED4 )
          a2 = 0;
        else
          a2 = 127;
        sub_46DEE0((int)&byte_527108, a2, 0xAu);
        dword_512580 = getTickCount();
      }
      if ( dword_523F14 )
      {
        v7 = 60000;
        if ( dword_523F14 != 1 )
          v7 = 90000;
        if ( getTickCount() > v7 + dword_526DB0[0] && !byte_5125A0 )
        {
          byte_5125A0 = 1;
          lockUsedInGlobalUpdatesOnTimer = 0;
          if ( dword_523F14 == 1 )
            sprintf(
              globBuf,
              "%s's computer is not responding.  Do you wish to keep waiting for a response?",
              (char *)&dword_526CE0 + 4);
          else
            sprintf(
              globBuf,
              "Your remote connection to the other players appears to be broken.  Do you wish to keep waiting for a response?");
          display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          {
            dword_526DB0[0] = getTickCount();
          }
          else
          {
            if ( dword_523F14 == 1 )
            {
              LOBYTE(v2) = 0;
              v3 = sub_435DC0(0);
              BYTE1(v2) = v3;
              HIWORD(v2) = 257;
              LOBYTE(v5) = 0;
              LOBYTE(v3) = v6;
              v3 <<= 16;
              LOWORD(v3) = v5;
              sub_439380(v2, v3);
            }
            else
            {
              GameInfo::saveGame(gameObject, "PLYREXIT", 1, 0);
              sprintf(
                globBuf,
                "The current game has been saved as 'PLYREXIT'. Do you wish to keep playing with the computer filling in for the other humans?");
              display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
              if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
                sub_438F30();
              else
                terminate(byte_5128E8);
            }
          }
          lockUsedInGlobalUpdatesOnTimer = v18;
          byte_5125A0 = 1;
        }
      }
      else
      {
        for ( i = 0; dword_5235D4 > (signed int)i; i = (char *)i + 1 )
        {
          if ( (void *)dword_523F14 != i && dword_526DB0[(signed int)i] + 60000 < getTickCount() && !byte_5125A0 )
          {
            byte_5125A0 = 1;
            lockUsedInGlobalUpdatesOnTimer = 0;
            sprintf(
              globBuf,
              "%s's computer is not responding.  Do you wish to keep waiting for a response?",
              (char *)&dword_526CE0 + 34 * (_DWORD)i + 4);
            display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
            {
              dword_526DB0[(signed int)i] = getTickCount();
            }
            else
            {
              LOBYTE(v0) = (_BYTE)i;
              v1 = sub_435DC0(i);
              BYTE1(v0) = v1;
              HIWORD(v0) = 257;
              LOBYTE(v8) = 0;
              LOBYTE(v1) = v9;
              v1 <<= 16;
              LOWORD(v1) = v8;
              sub_439380(v0, v1);
            }
            lockUsedInGlobalUpdatesOnTimer = v18;
            byte_5125A0 = 0;
          }
        }
      }
      for ( j = 0; j < 128; ++j )
      {
        if ( dword_527438[j] )
          ++v16;
      }
      if ( v16 == 128 )
        v10 = 1;
      v17 = 1;
      while ( v17 )
      {
LABEL_57:
        v17 = sub_46E070(0, buf, 127);
        if ( v17 && buf[0] != dword_523F14 )
        {
          if ( byte_52732D == 1 )
          {
            dword_512578 = dword_527329;
            return;
          }
          if ( byte_52732D == 4 )
          {
            dword_526DB0[buf[0]] = getTickCount();
            if ( byte_52732E & 0x80 && !dword_523ED4 )
              LODWORD(qword_50EAA8) = byte_52732E & 0xF;
            return;
          }
          if ( v10 )
            return;
          if ( byte_52732D == 2 )
          {
            byte_527108 = dword_523F14;
            dword_527109 = dword_527329;
            byte_52710D = 1;
            word_52710F = 0;
            sub_46DEE0((int)&byte_527108, buf[0], 9u);
          }
          for ( k = 0; k < 128; ++k )
          {
            if ( dword_527438[k] && *(_DWORD *)(dword_527438[k] + 1) == dword_527329 )
              goto LABEL_57;
          }
          for ( l = 0; l < 30; ++l )
          {
            if ( *((_DWORD *)&dword_527660 + l) == dword_527329 )
              goto LABEL_57;
          }
          for ( m = 0; m < 128; ++m )
          {
            if ( !dword_527438[m] )
            {
              dword_527438[m] = (int)KBAlloc(0x100u, "F:\\h2xsrc\\Source\\REMOTE.CPP", word_512748 + 235);
              dword_526EE0[m] = dword_512570++;
              memcpy((void *)dword_527438[m], buf, 0x100u);
              ++v16;
              *((_DWORD *)&dword_527660 + dword_512574) = dword_527329;
              dword_512574 = (dword_512574 + 1) % 30;
              if ( v16 == 128 )
                return;
              goto LABEL_57;
            }
          }
        }
      }
    }
  }
}
