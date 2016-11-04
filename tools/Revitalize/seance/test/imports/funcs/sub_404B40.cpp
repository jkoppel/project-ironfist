{
  char v0; // [sp+Ch] [bp-68h]@4

  dword_4F7494 = 0;
  if ( dword_4ED2D0 )
    (*(void (__cdecl **)(int, int))(*(_DWORD *)dword_4ED2CC + 32))(dword_4ED2CC, dword_4ED2D0);
  (*(void (__cdecl **)(int))(*(_DWORD *)dword_4ED2CC + 16))(dword_4ED2CC);
  (*(void (__cdecl **)(int))(*(_DWORD *)dword_4ED2CC + 8))(dword_4ED2CC);
  dword_4ED2CC = 0;
  while ( sub_404DB0(&v0) )
    ;
  if ( dword_4ED2E8 )
    KBFree(dword_4ED2E8, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED4E0 + 14);
  dword_4ED2E8 = 0;
  if ( dword_4ED2EC )
    KBFree(dword_4ED2EC, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED4E0 + 18);
  dword_4ED2EC = 0;
  if ( hModule )
    FreeLibrary(hModule);
  hModule = 0;
  _cfltcvt_init();
}
