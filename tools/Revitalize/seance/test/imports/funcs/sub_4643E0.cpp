{
  char result; // al@2
  size_t v1; // eax@11

  dword_526310 = sub_464520();
  if ( dword_526310 == -1 )
  {
    result = 0;
  }
  else
  {
    if ( dword_526310 != 10 && dword_526300 != 79 )
    {
      if ( dword_526310 >= 32 )
        *((_BYTE *)&byte_526318 + dword_526300++) = dword_526310;
      result = 0;
    }
    else
    {
      *((_BYTE *)&byte_526318 + dword_526300) = 0;
      if ( dword_526300 > 17 )
        byte_526329 = 0;
      v1 = strlen(byte_5262B0);
      if ( strncmp((const char *)&byte_526318, byte_5262B0, v1) )
      {
        dword_526300 = 0;
        result = 0;
      }
      else
      {
        result = 1;
      }
    }
  }
  return result;
}
