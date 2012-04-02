signed int __cdecl strncmp(int a1, int a2, signed int a3)
{
  signed int v3; // ecx@1
  int v4; // edi@2
  char v5; // zf@4
  int v6; // ecx@5
  int v7; // edi@5
  int v8; // esi@5
  unsigned __int8 v9; // al@8

  v3 = a3;
  if ( a3 )
  {
    v4 = a1;
    do
    {
      if ( !v3 )
        break;
      v5 = *(_BYTE *)v4++ == 0;
      --v3;
    }
    while ( !v5 );
    v6 = a3 - v3;
    v7 = a1;
    v8 = a2;
    do
    {
      if ( !v6 )
        break;
      v5 = *(_BYTE *)v8++ == *(_BYTE *)v7++;
      --v6;
    }
    while ( v5 );
    v9 = *(_BYTE *)(v8 - 1);
    v3 = 0;
    if ( v9 > *(_BYTE *)(v7 - 1) )
      return ~v3;
    if ( v9 != *(_BYTE *)(v7 - 1) )
    {
      v3 = -2;
      return ~v3;
    }
  }
  return v3;
}
