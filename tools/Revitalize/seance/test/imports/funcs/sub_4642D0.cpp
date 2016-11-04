{
  const char *v2; // [sp+Ch] [bp-D4h]@1
  size_t v3; // [sp+D8h] [bp-8h]@1
  signed int i; // [sp+DCh] [bp-4h]@1

  v2 = this;
  v3 = strlen(this);
  for ( i = 0; (signed int)v3 > i; ++i )
  {
    sub_4644D0(&v2[i], 1);
    sleep(100);
  }
  return sub_4644D0(L"\r", 1);
}
