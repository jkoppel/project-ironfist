{
  UINT v0; // eax@1
  signed int result; // eax@3
  DWORD v2; // esi@6
  signed int v3; // ebx@6
  UINT v4; // eax@12
  signed int v5; // ebx@15
  int v6; // eax@18
  unsigned int v7; // edi@18
  int v8; // eax@26
  char v9; // [sp+13h] [bp-2EDh]@11
  signed int v10; // [sp+14h] [bp-2ECh]@14
  HKEY hKey; // [sp+18h] [bp-2E8h]@9
  char v12[28]; // [sp+1Ch] [bp-2E4h]@6
  _DWORD buf[64]; // [sp+38h] [bp-2C8h]@6
  CHAR String; // [sp+138h] [bp-1C8h]@26
  CHAR strCommand; // [sp+19Ch] [bp-164h]@16
  const CHAR SubKey; // [sp+29Ch] [bp-64h]@25

  sprintf(gText, ".\\DATA\\HEROES2.AGG");
  v0 = open(gText, 32768);
  if ( v0 != -1 )
    goto LABEL_30;
  if ( _chdir((const char *)&gcRegAppPath) == -1 )
    return 3;
  v0 = open(gText, 32768);
  if ( v0 != -1 )
  {
LABEL_30:
    _close(v0);
    v2 = GetLogicalDrives();
    buf[0] = 0;
    memset(v12, 0, 0x18u);
    *(_WORD *)&v12[24] = 0;
    v3 = 2;
    do
    {
      if ( (1 << v3) & v2 )
      {
        sprintf(gText, "A:\\");
        gText[0] += v3;
        if ( GetDriveTypeA(gText) == 5 )
        {
          ++buf[0];
          *((_BYTE *)&hKey + buf[0] + 3) = v3;
        }
      }
      ++v3;
    }
    while ( v3 < 26 );
    v9 = LOBYTE(buf[0]);
    if ( strlen((const char *)&gcRegCDRomPath) == 0
      || (sprintf(gText, "%s\\heroes2\\anim\\voy24.smk", &gcRegCDRomPath), v4 = open(gText, 32768), v4 == -1) )
    {
      v10 = 0;
      while ( 1 )
      {
        v5 = 0;
        if ( v9 > 0 )
          break;
LABEL_20:
        Sleep(0xBB8u);
        ++v10;
        if ( v10 >= 2 )
          return 2;
      }
      while ( 1 )
      {
        _wsprintfA(&strCommand, "open %c: type cdaudio alias CD", v12[v5] + 65);
        if ( !mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0) )
        {
          _wsprintfA(&strCommand, "info CD UPC wait");
          mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0);
          _wsprintfA(&strCommand, "close CD");
          mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0);
        }
        sprintf(gText, "%c:\\heroes2\\anim\\voy24.smk", v12[v5] + 65);
        v6 = open(gText, 32768);
        v7 = v6;
        if ( v6 != -1 )
          break;
        ++v5;
        if ( v9 <= v5 )
          goto LABEL_20;
      }
      if ( _lseek(v6, 0, 2u) != -1 && _lseek(v7, -100, 1u) != -1 )
        _read(v7, buf, 0x64u);
      _close(v7);
      strcpy((char *)&SubKey, "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0");
      hKey = 0;
      if ( !RegOpenKeyExA(HKEY_LOCAL_MACHINE, &SubKey, 0, 0x20006u, &hKey) )
      {
        _wsprintfA(&String, "%c:", v12[v5] + 65);
        v8 = lstrlenA(&String);
        RegSetValueExA(hKey, "CDDrive", 0, 1u, (const BYTE *)&String, v8 + 1);
        RegCloseKey(hKey);
      }
      sprintf(gText, "%c:%s", v12[v5] + 65, "\\HEROES2\\ANIM\\");
      strcpy("\\HEROES2\\ANIM\\", gText);
      result = 0;
    }
    else
    {
      _close(v4);
      sprintf(&gText[2], "%s", "\\HEROES2\\ANIM\\");
      strcpy("\\HEROES2\\ANIM\\", gText);
      result = 0;
    }
  }
  else
  {
    result = 4;
  }
  return result;
}