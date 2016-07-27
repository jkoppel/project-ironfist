{
  signed int v1; // [sp+Ch] [bp-4h]@5

  if ( dword_5252AC > 4092 )
  {
    debugLog("OverFlow1");
    dword_5252AC = 0;
    dword_512304 = 1;
  }
LABEL_3:
  if ( dword_512304 )
  {
    dword_512308 = 0;
    dword_512304 = 0;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v1 = sub_464520();
      if ( v1 < 0 )
        return 0;
      if ( dword_512300 )
        break;
      if ( v1 != 112 )
        goto LABEL_15;
      dword_512300 = 1;
    }
    dword_512300 = 0;
    if ( v1 == 1 )
      break;
    if ( !v1 )
    {
      dword_512304 = 1;
      goto LABEL_3;
    }
LABEL_15:
    if ( dword_512308 >= 256 )
    {
      dword_512304 = 1;
      debugLog("OverFlow2");
      goto LABEL_3;
    }
    byte_526DC8[dword_512308++] = v1;
  }
  dword_512304 = 1;
  return 1;
}
