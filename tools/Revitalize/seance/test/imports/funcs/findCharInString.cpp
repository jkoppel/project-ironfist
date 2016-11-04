{
  const char *s; // esi@1
  unsigned int v3; // kr04_4@1
  int i; // eax@1
  char *result; // eax@4

  s = str;
  v3 = strlen(str) + 1;
  i = 0;
  if ( (signed int)(v3 - 1) <= 0 )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( s[i] != chr )
    {
      ++i;
      if ( (signed int)(v3 - 1) <= i )
        goto LABEL_4;
    }
    result = (char *)&s[i];
  }
  return result;
}
