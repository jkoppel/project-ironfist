{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 6; ++i )
  {
    if ( (void *)*((_BYTE *)&gbGamePosToNetPos + i) == this )
      return i;
  }
  return -1;
}