void __usercall start(int a1<eax>, int a2<ebx>, int a3<edi>, int a4<esi>)
{
  unsigned int v4; // eax@1
  LPSTR v5; // esi@6
  signed int v6; // eax@20
  HINSTANCE v7; // eax@23
  UINT v8; // eax@23
  int v9; // [sp-10h] [bp-80h]@22
  int v10; // [sp-Ch] [bp-7Ch]@1
  struct _STARTUPINFOA StartupInfo; // [sp+0h] [bp-70h]@20
  int *v12; // [sp+58h] [bp-18h]@1
  int v13; // [sp+60h] [bp-10h]@1
  int (__cdecl *v14)(int, int, int); // [sp+64h] [bp-Ch]@1
  _UNKNOWN *v15; // [sp+68h] [bp-8h]@1
  int v16; // [sp+6Ch] [bp-4h]@1

  v16 = -1;
  v15 = &unk_4EB020;
  v14 = unknown_libname_81;
  v13 = a1;
  v12 = &v10;
  v4 = ((int (__cdecl *)(int, int, int))GetVersion)(a3, a4, a2);
  dword_520B44 = v4;
  dword_520B50 = BYTE1(dword_520B44);
  dword_520B44 = v4 >> 16;
  dword_520B4C = (unsigned __int8)v4;
  dword_520B48 = dword_520B50 + ((unsigned __int8)v4 << 8);
  _heap_init();
  if ( !_mtinit() )
    _amsg_exit(16);
  v16 = 0;
  _ioinit();
  __initmbctable();
  lpCmdLine = GetCommandLineA();
  dword_520D00 = (void *)__crtGetEnvironmentStringsA();
  if ( !dword_520D00 || !lpCmdLine )
    exit(0xFFFFFFFFu);
  _setargv();
  _setenvp();
  _cinit();
  v5 = lpCmdLine;
  if ( *lpCmdLine == 34 )
  {
    v5 = lpCmdLine + 1;
    if ( lpCmdLine[1] == 34 )
      goto LABEL_26;
    do
    {
      if ( !*v5 )
        break;
      if ( _ismbblead((unsigned __int8)*v5) )
        ++v5;
      ++v5;
    }
    while ( *v5 != 34 );
    if ( *v5 == 34 )
LABEL_26:
      ++v5;
  }
  else
  {
    if ( (unsigned __int8)*lpCmdLine > 0x20u )
    {
      do
        ++v5;
      while ( (unsigned __int8)*v5 > 0x20u );
    }
  }
  for ( ; *v5; ++v5 )
  {
    if ( (unsigned __int8)*v5 > 0x20u )
      break;
  }
  StartupInfo.dwFlags = 0;
  GetStartupInfoA(&StartupInfo);
  v6 = 10;
  if ( StartupInfo.dwFlags & 1 )
    v6 = StartupInfo.wShowWindow;
  v9 = v6;
  v7 = GetModuleHandleA(0);
  v8 = WinMain(v7, 0, v5, v9);
  exit(v8);
}
