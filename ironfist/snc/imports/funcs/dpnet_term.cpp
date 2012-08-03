{
  char v0; // [sp+Ch] [bp-68h]@4

  gbRemoteOn = 0;
  if ( dcoID )
    (*(void (__cdecl **)(int, int))(*(_DWORD *)lpIDC + 32))(lpIDC, dcoID);
  (*(void (__cdecl **)(int))(*(_DWORD *)lpIDC + 16))(lpIDC);
  (*(void (__cdecl **)(int))(*(_DWORD *)lpIDC + 8))(lpIDC);
  lpIDC = 0;
  while ( dpnet_rcv(&v0) )
    ;
  if ( ppDPRcvBuffer )
    BaseFree(ppDPRcvBuffer, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED4E0 + 14);
  ppDPRcvBuffer = 0;
  if ( piDPRcvBufferSize )
    BaseFree(piDPRcvBufferSize, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED4E0 + 18);
  piDPRcvBufferSize = 0;
  if ( hinstDplayx )
    FreeLibrary(hinstDplayx);
  hinstDplayx = 0;
  _cfltcvt_init();
}