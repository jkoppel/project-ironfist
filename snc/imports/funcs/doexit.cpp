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
  _exitflag = a3;
  if ( !a2 )
  {
    if ( __onexitbegin )
    {
      for ( i = __onexitend - 4; (unsigned int)__onexitbegin <= i; i -= 4 )
      {
        if ( *(_DWORD *)i )
          (*(void (**)(void))i)();
      }
    }
    _initterm((unsigned int)&__xp_a, (unsigned int)&unk_4ED028);
  }
  _initterm((unsigned int)&__xt_a, (unsigned int)&unk_4ED030);
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