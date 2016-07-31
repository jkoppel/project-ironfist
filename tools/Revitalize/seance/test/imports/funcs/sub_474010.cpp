{
  UCHAR result; // al@2
  int v2; // [sp+10h] [bp-8h]@1
  UCHAR v3; // [sp+14h] [bp-4h]@2

  v2 = a1;
  while ( 1 )
  {
    assertTrue((unsigned __int8)byte_52F869[64 * v2] != 255, "F:\\h2xsrc\\Source\\netwin.cpp", word_513030 + 5);
    memset((char *)&byte_52F868 + 64 * v2, 0, 0x40u);
    *((_BYTE *)&byte_52F868 + 64 * v2) = -107;
    byte_52F86A[64 * v2] = *((_BYTE *)&byte_527840 + v2);
    dword_52F86C[16 * v2] = (int)((char *)&unk_527850 + 4096 * v2);
    word_52F870[32 * v2] = 4096;
    byte_52F898[64 * v2] = byte_512EB4;
    dword_52F8A4[16 * v2] = (int)*(&hHandle + v2);
    v3 = Netbios((PNCB)&byte_52F868 + v2);
    result = v3;
    if ( (signed int)v3 > 8 )
      break;
    if ( v3 == 8 || !v3 )
      return result;
LABEL_3:
    Sleep(0x32u);
  }
  if ( v3 != 10 && v3 != 24 && v3 != 255 )
    goto LABEL_3;
  return result;
}
