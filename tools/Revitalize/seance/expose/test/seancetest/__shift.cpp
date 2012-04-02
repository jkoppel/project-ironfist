void *__cdecl _shift(const char *a4, int a2)
{
  unsigned int v2; // kr04_4@2
  void *result; // eax@2

  if ( a2 )
  {
    v2 = strlen(a4) + 1;
    result = memcpy_0((void *)v2, (int)&a4[a2], (void *)&a4[a2], a4, v2);
  }
  return result;
}
