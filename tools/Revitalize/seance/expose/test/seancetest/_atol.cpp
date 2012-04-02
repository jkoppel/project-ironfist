int __cdecl atol(int *a1)
{
  int *i; // esi@1
  int v2; // eax@3
  __int16 v3; // ax@4
  int v4; // ebx@7
  int v5; // esi@7
  int v6; // edi@7
  int v7; // ebp@10
  int v8; // eax@12
  __int16 v9; // ax@13
  int result; // eax@16

  for ( i = a1; ; i = (int *)((char *)i + 1) )
  {
    if ( cchMultiByte <= 1 )
    {
      v3 = *((_WORD *)off_520FE0 + *(_BYTE *)i);
      v2 = v3 & 8;
    }
    else
    {
      v2 = _isctype(*(_BYTE *)i, 8);
    }
    if ( !v2 )
      break;
  }
  v4 = *(_BYTE *)i;
  v5 = (int)((char *)i + 1);
  v6 = v4;
  if ( v4 == 45 || v4 == 43 )
    v4 = *(_BYTE *)v5++;
  v7 = 0;
  while ( 1 )
  {
    if ( cchMultiByte <= 1 )
    {
      v9 = *((_WORD *)off_520FE0 + v4);
      v8 = v9 & 4;
    }
    else
    {
      v8 = _isctype(v4, 4);
    }
    if ( !v8 )
      break;
    ++v5;
    v7 = v4 + 10 * v7 - 48;
    v4 = *(_BYTE *)(v5 - 1);
  }
  result = v7;
  if ( v6 == 45 )
    result = -v7;
  return result;
}
