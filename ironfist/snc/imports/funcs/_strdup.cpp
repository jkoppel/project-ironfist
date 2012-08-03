{
  int v1; // eax@1
  char *result; // eax@1

  v1 = strlen(a1);
  result = (char *)malloc(v1 + 1);
  if ( result )
    strcpy(result, (char *)a1);
  return result;
}