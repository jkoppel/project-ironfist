{
  signed int result; // eax@6
  struct _NCB pncb; // [sp+Ch] [bp-40h]@1

  memset(&pncb, 0, 0x40u);
  for ( byte_512EB4 = 0; ; ++byte_512EB4 )
  {
    if ( (signed int)(unsigned __int8)byte_512EB4 < 254 )
    {
      memset(&pncb, 0, 0x40u);
      pncb.ncb_command = 127;
      pncb.ncb_lana_num = byte_512EB4;
      if ( Netbios(&pncb) != 3 )
        continue;
    }
    break;
  }
  if ( (signed int)(unsigned __int8)byte_512EB4 >= 254 )
  {
    result = 0;
  }
  else
  {
    byte_512EB0 = 1;
    result = 1;
  }
  return result;
}
