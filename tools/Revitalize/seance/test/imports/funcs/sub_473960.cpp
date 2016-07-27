{
  UCHAR result; // al@2
  signed int i; // [sp+10h] [bp-4h]@3

  assertTrue(
    (char *)&byte_52F868 + 64 * (unsigned __int8)byte_512EBC == (void *)pncb,
    "F:\\h2xsrc\\Source\\netwin.cpp",
    word_512FF8 + 3);
  result = *(_BYTE *)(pncb + 1);
  switch ( 0 )
  {
    case 0:
    case 36:
      byte_512EC0 = *(_BYTE *)(pncb + 3);
      memcpy(&dword_52FA68[16 * (unsigned __int8)byte_512EBC], (const void *)(pncb + 26), 0x10u);
      result = byte_512EBC;
      byte_512EC4[(unsigned __int8)byte_512EBC] |= 2u;
      break;
    case 13:
    case 22:
    case 25:
    case 48:
      for ( i = 15; ; --i )
      {
        if ( i >= 0 )
        {
          ++*(_BYTE *)(i + pncb + 26);
          if ( *(&dword_52FA68[16 * (unsigned __int8)byte_512EBC] + i) == *(_BYTE *)(i + pncb + 26) )
            continue;
        }
        break;
      }
      result = Netbios((PNCB)pncb);
      break;
    case 11:
      return result;
    default:
      sprintf(globBuf, "Add Name Error %02x\n", *(_BYTE *)(pncb + 1));
      terminate(globBuf);
      result = byte_512EBC;
      byte_512EC4[(unsigned __int8)byte_512EBC] |= 0x80u;
      break;
  }
  return result;
}
