unsigned int __cdecl _strrev(unsigned int a1)
{
  unsigned int v1; // edi@1
  unsigned int v2; // esi@1
  signed int v3; // ecx@1
  char v4; // zf@3
  int i; // edi@5
  char v6; // ah@7

  v1 = a1;
  v2 = a1;
  v3 = -1;
  do
  {
    if ( !v3 )
      break;
    v4 = *(_BYTE *)v1++ == 0;
    --v3;
  }
  while ( !v4 );
  if ( v3 != -2 )
  {
    for ( i = v1 - 2; v2 < i; --i )
    {
      v6 = *(_BYTE *)v2;
      *(_BYTE *)v2 = *(_BYTE *)i;
      *(_BYTE *)i = v6;
      ++v2;
    }
  }
  return a1;
}
