{
  unsigned int v2; // kr04_4@2
  void *result; // eax@2

  if ( a2 )
  {
    v2 = strlen(a4) + 1;
    result = memmove((void *)v2, (int)&a4[a2], (void *)&a4[a2], a4, v2);
  }
  return result;
}