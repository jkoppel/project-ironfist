{
  signed int v1; // [sp+Ch] [bp-4h]@5

  if ( dword_5252AC > 4092 )
  {
    LogStr("OverFlow1");
    dword_5252AC = 0;
    newpacket = 1;
  }
LABEL_3:
  if ( newpacket )
  {
    packetlen = 0;
    newpacket = 0;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v1 = read_byte();
      if ( v1 < 0 )
        return 0;
      if ( inescape )
        break;
      if ( v1 != 112 )
        goto LABEL_15;
      inescape = 1;
    }
    inescape = 0;
    if ( v1 == 1 )
      break;
    if ( !v1 )
    {
      newpacket = 1;
      goto LABEL_3;
    }
LABEL_15:
    if ( packetlen >= 256 )
    {
      newpacket = 1;
      LogStr("OverFlow2");
      goto LABEL_3;
    }
    packet[packetlen++] = v1;
  }
  newpacket = 1;
  return 1;
}