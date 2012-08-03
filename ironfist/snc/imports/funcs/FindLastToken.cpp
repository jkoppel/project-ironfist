{
  const char *v2; // esi@1
  unsigned int v3; // ecx@1
  int result; // eax@4

  v2 = a1;
  v3 = strlen(a1) - 1;
  if ( (signed int)v3 < 0 )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( v2[v3] != a2 )
    {
      --v3;
      if ( (signed int)v3 < 0 )
        goto LABEL_4;
    }
    result = (int)&v2[v3];
  }
  return result;
}