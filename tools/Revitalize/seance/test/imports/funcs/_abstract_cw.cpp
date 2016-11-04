{
  signed int result; // eax@1
  int v2; // ecx@13

  result = 0;
  if ( a1 & 1 )
    result = 16;
  if ( a1 & 4 )
    result |= 8u;
  if ( a1 & 8 )
    result |= 4u;
  if ( a1 & 0x10 )
    result |= 2u;
  if ( a1 & 0x20 )
    result |= 1u;
  if ( a1 & 2 )
    result |= 0x80000u;
  v2 = a1 & 0xC00;
  switch ( v2 )
  {
    case 1024:
      result |= 0x100u;
      break;
    case 2048:
      result |= 0x200u;
      break;
    case 3072:
      result |= 0x300u;
      break;
  }
  if ( a1 & 0x300 )
  {
    if ( (a1 & 0x300) == 512 )
      result |= 0x10000u;
  }
  else
  {
    result |= 0x20000u;
  }
  if ( HIBYTE(a1) & 0x10 )
    result |= 0x40000u;
  return result;
}
