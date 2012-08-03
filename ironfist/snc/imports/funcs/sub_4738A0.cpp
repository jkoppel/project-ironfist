{
  UCHAR result; // al@1
  const void *v1; // ST04_4@2
  int v2; // eax@2

  result = byte_52FA59;
  if ( (unsigned __int8)byte_52FA59 != 255 )
  {
    strcpy(Dest, off_512ED0);
    v1 = &dword_52FA68[16 * (unsigned __int8)byte_512EBC];
    v2 = strlen((int)off_512ED0);
    memcpy(&Dest[v2], v1, 0x10u);
    memset(&pncb, 0, 0x40u);
    pncb.ncb_command = -94;
    byte_52FA2B = byte_512EC0;
    word_52FA30 = strlen((int)off_512ED0) + 16;
    dword_52FA2C = (int)Dest;
    byte_52FA58 = byte_512EB4;
    result = thunk_Netbios(&pncb);
  }
  return result;
}