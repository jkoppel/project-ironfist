{
  char result; // al@1
  int v2; // edx@1

  result = 0;
  v2 = a1;
  if ( a1 & 0x10 )
    result = 1;
  if ( a1 & 8 )
    result |= 4u;
  if ( a1 & 4 )
    result |= 8u;
  if ( a1 & 2 )
    result |= 0x10u;
  if ( a1 & 1 )
    result |= 0x20u;
  if ( v2 & 0x80000 )
    result |= 2u;
  return result;
}
