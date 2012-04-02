void __cdecl doexit(UINT uExitCode, int a2, int a3)
{
  HANDLE v3; // eax@2
  int i; // edi@5

  _lockexit();
  if ( dword_520B80 == 1 )
  {
    v3 = GetCurrentProcess();
    TerminateProcess(v3, uExitCode);
  }
  dword_520B7C = 1;
  byte_520B78 = a3;
  if ( !a2 )
  {
    if ( dword_538F2C )
    {
      for ( i = dword_538F28 - 4; (unsigned int)dword_538F2C <= i; i -= 4 )
      {
        if ( *(_DWORD *)i )
          (*(void (**)(void))i)();
      }
    }
    _initterm(&unk_4ED020, &unk_4ED028);
  }
  _initterm(&unk_4ED02C, &unk_4ED030);
  if ( a3 )
  {
    _unlockexit();
  }
  else
  {
    dword_520B80 = 1;
    ExitProcess(uExitCode);
  }
}
