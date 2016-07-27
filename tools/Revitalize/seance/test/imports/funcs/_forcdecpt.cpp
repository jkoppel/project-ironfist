{
  int *v1; // esi@1
  int v2; // eax@3
  __int16 v3; // ax@4
  char v4; // cl@6
  int v5; // esi@6
  char v6; // dl@7
  char result; // al@7

  v1 = a1;
  if ( tolower(*(_BYTE *)a1) != 101 )
  {
    do
    {
      v1 = (int *)((char *)v1 + 1);
      if ( cchMultiByte <= 1 )
      {
        v3 = *((_WORD *)off_520FE0 + *(_BYTE *)v1);
        v2 = v3 & 4;
      }
      else
      {
        v2 = _isctype(*(_BYTE *)v1, 4);
      }
    }
    while ( v2 );
  }
  v4 = *(_BYTE *)v1;
  *(_BYTE *)v1 = byte_5211F0;
  v5 = (int)((char *)v1 + 1);
  do
  {
    v6 = *(_BYTE *)v5;
    result = v4;
    *(_BYTE *)v5 = v4;
    v4 = v6;
    ++v5;
  }
  while ( result );
  return result;
}
