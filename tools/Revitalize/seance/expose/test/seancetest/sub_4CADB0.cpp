__int32 __thiscall sub_4CADB0(const char *this)
{
  void *v1; // esi@1
  FILE *v2; // edi@1
  __int32 v3; // esi@3

  v1 = (void *)this;
  v2 = fopen(this, "r+b");
  if ( !v2 )
    sub_436DF0(v1);
  fseek(v2, 0, 2);
  v3 = ftell(v2);
  fseek(v2, 0, 0);
  fclose(v2);
  return v3;
}
