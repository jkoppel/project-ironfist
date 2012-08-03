{
  signed __int16 result; // ax@2
  char v3; // [sp+Ch] [bp-54h]@1
  UCHAR *a1a; // [sp+14h] [bp-4Ch]@10
  struct _NCB pncb; // [sp+18h] [bp-48h]@10
  int i; // [sp+58h] [bp-8h]@4

  v3 = a2;
  memset(&byte_527840, 0, 7u);
  memset(&::pncb, 0, 0x40u);
  memset(&byte_52F868, 0, 0x1C0u);
  memset(Dest, 0xFFu, 0x1000u);
  memset(&unk_527850, 0xFFu, 0x7000u);
  memset(&hObject, 0, 0x24u);
  if ( is_netbios_avail() )
  {
    if ( byte_512EB0 )
    {
      byte_512EBC = v3;
      for ( i = 0; i < 7; ++i )
      {
        byte_512EC4[i] = 0;
        *((_BYTE *)&byte_527840 + i) = -1;
        memset((char *)&byte_52F868 + 64 * i, 0, 0x40u);
      }
      memset(dword_52FA68, 0, 0x70u);
      InitializeCriticalSection(&CriticalSection);
      InitializeCriticalSection(&stru_52FAD8);
      init_anchor((int)&unk_527838, 0);
      init_anchor((int)&unk_527848, 0);
      init_anchor((int)&unk_527808, 0);
      for ( i = 0; i < 9; ++i )
        *(&hObject + i) = CreateEventA(0, 1, 0, 0);
      memset(&pncb, 0, 0x40u);
      a1a = (UCHAR *)BaseAlloc(0x400u, "F:\\h2xsrc\\Source\\netwin.cpp", word_512EE8 + 40);
      pncb.ncb_command = 51;
      pncb.ncb_length = 1024;
      pncb.ncb_buffer = a1a;
      pncb.ncb_lana_num = byte_512EB4;
      if ( thunk_Netbios(&pncb) == 52 )
      {
        memset(&pncb, 0, 0x40u);
        pncb.ncb_command = 50;
        pncb.ncb_lana_num = byte_512EB4;
        pncb.ncb_callname[0] = 20;
        pncb.ncb_callname[2] = 10;
        thunk_Netbios(&pncb);
      }
      BaseFree(a1a, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512EE8 + 54);
      byte_512EB8 = 0;
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}