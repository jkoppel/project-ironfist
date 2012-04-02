int __cdecl _strdup(int a1)
{
  int v1; // eax@1
  int result; // eax@1

  v1 = strlen(a1);
  result = malloc(v1 + 1);
  if ( result )
    strcpy(result);
  return result;
}
