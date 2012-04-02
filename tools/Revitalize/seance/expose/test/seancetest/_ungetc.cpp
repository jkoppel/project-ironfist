int __cdecl ungetc(int a1, FILE *a2)
{
  int v2; // esi@1

  _lock_file(a2);
  v2 = ungetc_0(a1, a2);
  _unlock_file(a2);
  return v2;
}
