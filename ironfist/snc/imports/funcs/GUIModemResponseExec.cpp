{
  char result; // al@2
  int v1; // eax@11

  GUIMRc = read_byte();
  if ( GUIMRc == -1 )
  {
    result = 0;
  }
  else if ( GUIMRc != 10 && GUIMRrespptr != 79 )
  {
    if ( GUIMRc >= 32 )
      *((_BYTE *)&GUIMRresponse + GUIMRrespptr++) = GUIMRc;
    result = 0;
  }
  else
  {
    *((_BYTE *)&GUIMRresponse + GUIMRrespptr) = 0;
    if ( GUIMRrespptr > 17 )
      byte_526329 = 0;
    v1 = strlen((int)GUIMRresp);
    if ( !strncmp((int)&GUIMRresponse, (int)GUIMRresp, v1) )
    {
      result = 1;
    }
    else
    {
      GUIMRrespptr = 0;
      result = 0;
    }
  }
  return result;
}