{
  int *v3; // [sp+14h] [bp-14h]@1
  int *v4; // [sp+18h] [bp-10h]@1
  int v5; // [sp+20h] [bp-8h]@1
  char v6; // [sp+24h] [bp-4h]@4

  v4 = a1;
  v3 = a2;
  v5 = 0;
  while ( 1 )
  {
    ++v5;
    if ( v5 == 10 )
      return 1;
    v6 = toupper(*(_BYTE *)v4);
    if ( v6 != (char)toupper(*(_BYTE *)v3) )
      break;
    if ( !v6 )
      return 1;
    v4 = (int *)((char *)v4 + 1);
    v3 = (int *)((char *)v3 + 1);
  }
  return 0;
}
