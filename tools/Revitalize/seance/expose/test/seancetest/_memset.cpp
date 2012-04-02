void *__cdecl memset(void *a1, unsigned __int8 a2, unsigned int a3)
{
  int v3; // edx@1
  int v4; // eax@2
  void *v5; // edi@2
  int v6; // ecx@3
  unsigned int v7; // ecx@6
  unsigned int v8; // ecx@6
  void *result; // eax@9

  v3 = a3;
  if ( a3 )
  {
    LOBYTE(v4) = a2;
    v5 = a1;
    if ( a3 < 4 )
      goto LABEL_13;
    v6 = -(signed int)a1 & 3;
    if ( v6 )
    {
      v3 = a3 - v6;
      do
      {
        *(_BYTE *)v5 = a2;
        v5 = (char *)v5 + 1;
        --v6;
      }
      while ( v6 );
    }
    v4 = 16843009 * a2;
    v7 = v3;
    v3 &= 3u;
    v8 = v7 >> 2;
    if ( !v8 || (memset32(v5, v4, v8), v5 = (char *)v5 + 4 * v8, v3) )
    {
LABEL_13:
      do
      {
        *(_BYTE *)v5 = v4;
        v5 = (char *)v5 + 1;
        --v3;
      }
      while ( v3 );
    }
    result = a1;
  }
  else
  {
    result = a1;
  }
  return result;
}
