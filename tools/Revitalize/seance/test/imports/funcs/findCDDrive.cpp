{
  int v0; // eax@1
  signed int result; // eax@3
  DWORD v2; // esi@6
  signed int v3; // ebx@6
  int v4; // eax@12
  signed int v5; // ebx@15
  int v6; // eax@18
  int v7; // edi@18
  int v8; // eax@26
  char v9; // [sp+13h] [bp-2EDh]@11
  signed int v10; // [sp+14h] [bp-2ECh]@14
  HKEY hKey; // [sp+18h] [bp-2E8h]@9
  char v12[28]; // [sp+1Ch] [bp-2E4h]@6
  _DWORD buf[64]; // [sp+38h] [bp-2C8h]@6
  CHAR String; // [sp+138h] [bp-1C8h]@26
  CHAR strCommand; // [sp+19Ch] [bp-164h]@16
  const CHAR SubKey; // [sp+29Ch] [bp-64h]@25

  sprintf(globBuf, ".\\DATA\\HEROES2.AGG");
  v0 = _open(globBuf, 32768);
  if ( v0 != -1 )
    goto LABEL_30;
  if ( _chdir((const char *)&byte_5245D0) == -1 )
    return 3;
  v0 = _open(globBuf, 32768);
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
        sprintf(globBuf, "A:\\");
        globBuf[0] += v3;
        if ( GetDriveTypeA(globBuf) == 5 )
        {
          ++buf[0];
          *((_BYTE *)&hKey + buf[0] + 3) = v3;
        }
      }
      ++v3;
    }
    while ( v3 < 26 );
    v9 = LOBYTE(buf[0]);
    if ( strlen((const char *)&byte_524A80) == 0
      || (sprintf(globBuf, "%s\\heroes2\\anim\\voy24.smk", &byte_524A80), v4 = _open(globBuf, 32768), v4 == -1) )
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
        wsprintfA(&strCommand, "open %c: type cdaudio alias CD", v12[v5] + 65);
        if ( !mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0) )
        {
          wsprintfA(&strCommand, "info CD UPC wait");
          mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0);
          wsprintfA(&strCommand, "close CD");
          mciSendStringA(&strCommand, (LPSTR)buf, 0xFFu, 0);
        }
        sprintf(globBuf, "%c:\\heroes2\\anim\\voy24.smk", v12[v5] + 65);
        v6 = _open(globBuf, 32768);
        v7 = v6;
        if ( v6 != -1 )
          break;
        ++v5;
        if ( v9 <= v5 )
          goto LABEL_20;
      }
      if ( _lseek(v6, 0, 2) != -1 && _lseek(v7, -100, 1) != -1 )
        _read(v7, buf, 0x64u);
      _close(v7);
      strcpy((char *)&SubKey, "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0");
      hKey = 0;
      if ( !RegOpenKeyExA(HKEY_LOCAL_MACHINE, &SubKey, 0, 0x20006u, &hKey) )
      {
        wsprintfA(&String, "%c:", v12[v5] + 65);
        v8 = lstrlen(&String);
        RegSetValueExA(hKey, "CDDrive", 0, 1u, (const BYTE *)&String, v8 + 1);
        RegCloseKey(hKey);
      }
      sprintf(globBuf, "%c:%s", v12[v5] + 65, "\\HEROES2\\ANIM\\");
      strcpy("\\HEROES2\\ANIM\\", globBuf);
      result = 0;
    }
    else
    {
      _close(v4);
      sprintf(&globBuf[2], "%s", "\\HEROES2\\ANIM\\");
      strcpy("\\HEROES2\\ANIM\\", globBuf);
      result = 0;
    }
  }
  else
  {
    result = 4;
  }
  return result;
}
