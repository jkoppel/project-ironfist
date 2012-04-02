int __cdecl fread(int a1, int a2, int a3, FILE *a4)
{
  int v4; // edi@1

  _lock_file(a4);
  v4 = _fread_lk(a1, a2, a3, a4);
  _unlock_file(a4);
  return v4;
}
