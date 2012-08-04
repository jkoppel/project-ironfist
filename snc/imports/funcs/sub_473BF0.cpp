{
  int v1; // eax@7
  int v2; // eax@8
  int i; // [sp+Ch] [bp-4h]@1

  for ( i = 0; i < 7 && (char *)&byte_52F868 + 64 * i != a1; ++i )
    ;
  if ( i < 7 )
  {
    if ( byte_52F869[64 * i] )
    {
      if ( (unsigned __int8)byte_52F869[64 * i] != 11 && (unsigned __int8)byte_52F869[64 * i] != 36 )
        thunk_Netbios((PNCB)&byte_52F868 + i);
    }
    else
    {
      v1 = strlen((int)off_512ED0);
      if ( !memcmp((int)((char *)&unk_527850 + 4096 * i), (int)off_512ED0, v1) )
      {
        v2 = strlen((int)off_512ED0);
        memcpy(&dword_52FA68[16 * i], (char *)&unk_527850 + 4096 * i + v2, 0x10u);
        sub_473D40(i, &dword_52FA68[16 * i]);
      }
      else
      {
        thunk_Netbios((PNCB)&byte_52F868 + i);
      }
    }
  }
}