{
  __int16 result; // ax@2
  char v1; // [sp+10h] [bp-2Ch]@19
  char v2; // [sp+11h] [bp-2Bh]@21
  char v3; // [sp+12h] [bp-2Ah]@19
  FARPROC v4; // [sp+2Ch] [bp-10h]@5
  int i; // [sp+30h] [bp-Ch]@19
  int v6; // [sp+34h] [bp-8h]@14
  FARPROC v7; // [sp+38h] [bp-4h]@5

  if ( dword_4ED2CC )
  {
    result = 0;
  }
  else
  {
    dword_4ED2E8 = KBAlloc(0x320u, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 7);
    dword_4ED2EC = KBAlloc(0x320u, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 8);
    memset(dword_4ED2E8, 0, 0x320u);
    memset(dword_4ED2EC, 0, 0x320u);
    hModule = LoadLibraryA("DPLAYX.DLL");
    if ( !hModule )
      terminate("Can't load 'DPLAYX.DLL'");
    v7 = 0;
    v4 = GetProcAddress(hModule, "DirectPlayCreate");
    if ( !v4 )
      terminate("Can't load 'DPLAYX.DLL'");
    v7 = GetProcAddress(hModule, "DirectPlayEnumerateA");
    if ( !v7 )
      terminate("Can't load 'DPLAYX.DLL'");
    ((void (__cdecl *)(int (__stdcall *)(int, char *, int, int, int), _DWORD))v7)(sub_404640, 0);
    if ( dword_4F31B4 == 1 )
    {
      dword_522B90 = dword_4ED2D4;
    }
    else
    {
      if ( dword_4F31B4 == 2 )
        dword_522B90 = dword_4ED2D8;
    }
    v6 = ((int (__cdecl *)(SOCKET, int *, _DWORD))v4)(dword_522B90, &dword_4ED2CC, 0);
    if ( v6 )
      sub_4057C0(v6, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED340 + 41);
    if ( (unsigned __int8)byte_51257C == 1 )
    {
      dword_524A6C = 1;
      dword_524750 = 8;
      sprintf(globBuf, "Waiting On Guest.\n\n  Press 'CANCEL' to abort.");
      display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !dword_523018 )
        terminate(0);
      dword_4ED314 = dword_5235D4;
      dword_524750 = 9;
      sprintf(
        globBuf,
        "You have %d guest(s) now logged in.  Click 'OK' to move on, or wait for additional guests.",
        dword_5235D4 - 1);
      display_message_window(globBuf, 5, -1, -1, -1, 0, -1, 0, -1, 0);
      dword_524A6C = 0;
      v1 = dword_5235D4;
      memcpy(&v3, &dword_522B78, 0x18u);
      for ( i = 1; i < dword_5235D4; ++i )
      {
        v2 = i;
        sub_404C60(*((_DWORD *)&dword_522B78 + i), 3, 0x1Au, &v1);
      }
    }
    else
    {
      dword_524750 = 10;
      sprintf(globBuf, "Waiting for other remote player to set up game.");
      display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !dword_523018 )
        terminate(0);
    }
    result = 0;
  }
  return result;
}
