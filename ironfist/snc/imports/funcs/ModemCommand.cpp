{
  const char *v2; // [sp+Ch] [bp-D4h]@1
  int v3; // [sp+D8h] [bp-8h]@1
  int i; // [sp+DCh] [bp-4h]@1

  v2 = this;
  v3 = strlen((int)this);
  for ( i = 0; v3 > i; ++i )
  {
    write_buffer(&v2[i], 1);
    DelayMilli(100);
  }
  return write_buffer(L"\r", 1);
}