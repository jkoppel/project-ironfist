{
  const char *v1; // edx@1
  int v2; // ebx@1
  unsigned int v3; // esi@1
  unsigned int i; // ecx@1
  char v5; // al@2
  int v6; // eax@5

  v1 = this;
  v2 = 0;
  v3 = 0;
  for ( i = strlen(this) - 1; (signed int)i >= 0; --i )
  {
    v5 = v1[i];
    if ( v5 >= 'a' && v5 <= 'z' )
      v1[i] = v5 & 0xDF;
    v6 = v1[i];
    v2 += v6;
    v3 = v2 + v6 + 32 * v3 + (v3 >> 25);
  }
  return v3;
}
