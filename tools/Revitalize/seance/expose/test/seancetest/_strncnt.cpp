int __cdecl strncnt(int a1, int a2)
{
  int result; // eax@1
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@3

  result = a2;
  v3 = a1;
  v4 = a2 - 1;
  if ( a2 )
  {
    while ( *(_BYTE *)v3 )
    {
      ++v3;
      v5 = v4--;
      if ( !v5 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    if ( *(_BYTE *)v3 )
      return result;
  }
  return v3 - a1;
}
