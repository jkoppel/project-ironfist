BOOL __cdecl _setenvp()
{
  int v0; // edx@1
  const char *v1; // esi@1
  int v2; // ebx@5
  const char *v3; // ebp@7
  DWORD v4; // ecx@8
  int v5; // eax@9
  char *v6; // edi@11
  BOOL result; // eax@13
  DWORD v8; // [sp+10h] [bp-4h]@8

  v0 = 0;
  v1 = (const char *)dword_520D00;
  if ( *(_BYTE *)dword_520D00 )
  {
    do
    {
      if ( *v1 != 61 )
        ++v0;
      v1 += strlen(v1) + 1;
    }
    while ( *v1 );
  }
  dword_520B60 = malloc(4 * v0 + 4);
  v2 = dword_520B60;
  if ( !dword_520B60 )
    _amsg_exit(9);
  v3 = (const char *)dword_520D00;
  if ( *(_BYTE *)dword_520D00 )
  {
    do
    {
      v4 = strlen(v3) + 1;
      v8 = v4;
      if ( *v3 != 61 )
      {
        v5 = malloc(v4);
        *(_DWORD *)v2 = v5;
        if ( !v5 )
          _amsg_exit(9);
        v6 = *(char **)v2;
        v2 += 4;
        strcpy(v6, v3);
      }
      v3 += v8;
    }
    while ( *v3 );
  }
  result = free((BOOL)dword_520D00);
  *(_DWORD *)v2 = 0;
  return result;
}
