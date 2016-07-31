{
  struct _NCB pncb; // [sp+Ch] [bp-48h]@5
  void *a1; // [sp+4Ch] [bp-8h]@9
  int i; // [sp+50h] [bp-4h]@1

  for ( i = 0; i < 7; ++i )
    sub_474160(i);
  if ( (unsigned __int8)byte_52FA59 == 255 )
  {
    memset(&pncb, 0, 0x40u);
    pncb.ncb_command = 53;
    pncb.ncb_lana_num = byte_512EB4;
    pncb.ncb_buffer = (PUCHAR)&::pncb;
    Netbios(&pncb);
  }
  if ( byte_512EC4[(unsigned __int8)byte_512EBC] & 2 )
  {
    memset(&pncb, 0, 0x40u);
    memcpy(pncb.ncb_name, &dword_52FA68[16 * (unsigned __int8)byte_512EBC], 0x10u);
    pncb.ncb_command = 49;
    pncb.ncb_lana_num = byte_512EB4;
    Netbios(&pncb);
  }
  EnterCriticalSection(&stru_52FAD8);
  while ( 1 )
  {
    a1 = (void *)sub_4BC830((int)&unk_527848);
    if ( !a1 )
      break;
    KBFree(a1, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512F24 + 31);
  }
  while ( 1 )
  {
    a1 = (void *)sub_4BC830((int)&unk_527808);
    if ( !a1 )
      break;
    KBFree(a1, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512F24 + 35);
  }
  LeaveCriticalSection(&stru_52FAD8);
  DeleteCriticalSection(&stru_52FAD8);
  for ( i = 0; i < 9; ++i )
  {
    CloseHandle(*(&dword_527810 + i));
    *(&dword_527810 + i) = 0;
  }
  byte_512EB8 |= 1u;
  SetEvent(dword_527810);
  EnterCriticalSection(&CriticalSection);
  while ( 1 )
  {
    a1 = (void *)sub_4BC830((int)&unk_527838);
    if ( !a1 )
      break;
    KBFree(a1, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512F24 + 50);
  }
  LeaveCriticalSection(&CriticalSection);
  DeleteCriticalSection(&CriticalSection);
}
