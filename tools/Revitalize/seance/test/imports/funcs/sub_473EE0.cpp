{
  char *v1; // eax@3
  int v3; // [sp+Ch] [bp-8h]@6
  int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    if ( i < 7 )
    {
      v1 = (char *)&byte_52F868 + 64 * i;
      if ( v1 != a1 )
        continue;
    }
    break;
  }
  if ( i < 7 )
  {
    LOBYTE(v1) = (_BYTE)i << 6;
    v3 = (unsigned __int8)byte_52F869[64 * i];
    if ( byte_52F869[64 * i] )
    {
      if ( v3 != 11 )
      {
        if ( v3 != 36 )
        {
          ++byte_512EAC;
          LOBYTE(v1) = byte_512EAC;
          if ( (signed int)(unsigned __int8)byte_512EAC < 20 )
          {
            Sleep(0x64u);
            LOBYTE(v1) = Netbios((PNCB)&byte_52F868 + i);
          }
        }
      }
    }
    else
    {
      *((_BYTE *)&byte_527840 + i) = byte_52F86A[64 * i];
      memcpy(&dword_52FA68[16 * i], (char *)&byte_52F868 + 64 * i + 10, 0x10u);
      byte_512EC4[i] |= 9u;
      LOBYTE(v1) = sub_474010(i);
    }
  }
  return (char)v1;
}
