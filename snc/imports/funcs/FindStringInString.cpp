{
  const char *v2; // ebp@1
  unsigned int v3; // kr04_4@1
  unsigned int v4; // kr0C_4@1
  int v5; // edi@1
  int v6; // ebx@1
  int result; // eax@4
  int v8; // [sp+10h] [bp-4h]@1

  v8 = (int)a2;
  v2 = a1;
  v3 = strlen(a1) + 1;
  v4 = strlen(a2) + 1;
  v5 = 0;
  v6 = v3 - 1 - (v4 - 1) + 1;
  if ( v6 <= 0 )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( strncmp((int)&v2[v5], v8, v4 - 1) )
    {
      ++v5;
      if ( v5 >= v6 )
        goto LABEL_4;
    }
    result = (int)&v2[v5];
  }
  return result;
}