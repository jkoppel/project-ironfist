{
  unsigned int result; // eax@1
  const char *v4; // edi@1
  char *v5; // ebp@1
  char *v6; // esi@1
  char v7; // bl@2
  int i; // esi@8

  result = a2;
  v4 = (char *)a1 + 1;
  v5 = *(char **)(a3 + 12);
  v6 = (char *)a1 + 1;
  *(_BYTE *)a1 = 48;
  if ( (signed int)a2 > 0 )
  {
    do
    {
      v7 = *v5;
      if ( *v5 )
      {
        ++v5;
        *v6 = v7;
      }
      else
      {
        *v6 = 48;
      }
      ++v6;
      --result;
    }
    while ( result );
  }
  *v6 = 0;
  if ( (signed int)result >= 0 && *v5 >= 53 )
  {
    for ( i = (int)(v6 - 1); *(_BYTE *)i == 57; --i )
      *(_BYTE *)i = 48;
    ++*(_BYTE *)i;
  }
  if ( *(_BYTE *)a1 == 49 )
  {
    ++*(_DWORD *)(a3 + 4);
  }
  else
  {
    result = strlen(v4) + 1;
    memcpy(a1, v4, result);
  }
  return result;
}