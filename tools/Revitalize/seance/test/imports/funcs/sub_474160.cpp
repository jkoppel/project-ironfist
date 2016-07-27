{
  int result; // eax@3
  int v2; // [sp+Ch] [bp-44h]@1
  struct _NCB pncb; // [sp+10h] [bp-40h]@2

  v2 = a1;
  if ( (unsigned __int8)byte_52F899[64 * a1] == 255 )
  {
    memset(&pncb, 0, 0x40u);
    pncb.ncb_command = 53;
    pncb.ncb_lana_num = byte_512EB4;
    pncb.ncb_buffer = (PUCHAR)((char *)&byte_52F868 + 64 * v2);
    Netbios(&pncb);
  }
  result = v2;
  if ( *((_BYTE *)&byte_527840 + v2) != 255 )
  {
    memset(&pncb, 0, 0x40u);
    pncb.ncb_lsn = *((_BYTE *)&byte_527840 + v2);
    pncb.ncb_command = 18;
    pncb.ncb_lana_num = byte_512EB4;
    Netbios(&pncb);
    result = v2;
    byte_512EC4[v2] &= 0xFEu;
  }
  return result;
}
