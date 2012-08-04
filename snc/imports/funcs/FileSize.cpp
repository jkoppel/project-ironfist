{
  void *v1; // esi@1
  int v2; // edi@1
  int v3; // esi@3

  v1 = (void *)this;
  v2 = fopen((char *)this, (int)"r+b");
  if ( !v2 )
    FileError(v1);
  fseek(v2, 0, 2);
  v3 = ftell(v2);
  fseek(v2, 0, 0);
  fclose(v2);
  return v3;
}