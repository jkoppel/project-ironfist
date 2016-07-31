{
  char result; // al@1
  void *v3; // [sp+Ch] [bp-Ch]@1
  int v4; // [sp+10h] [bp-8h]@1
  unsigned int i; // [sp+14h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  result = (unsigned int)memset(a2, 0, 0x10u);
  for ( i = 0; i < 0xF; *((_BYTE *)v3 + i++) = *(_BYTE *)v4++ )
  {
    result = *(_BYTE *)v4;
    if ( !*(_BYTE *)v4 )
      break;
    result = *(_BYTE *)v4;
  }
  while ( i < 0xF )
  {
    result = i;
    *((_BYTE *)v3 + i++) = 32;
  }
  return result;
}
