int __cdecl fputs(const char *a1, FILE *a2)
{
  unsigned int v2; // kr04_4@1
  int v3; // edi@1
  int v4; // ebx@1

  v2 = strlen(a1) + 1;
  _lock_file(a2);
  v3 = _stbuf(a2);
  v4 = _fwrite_lk(a1, 1, v2 - 1, a2) - (v2 - 1);
  _ftbuf(v3, a2);
  _unlock_file(a2);
  return ((unsigned int)v4 < 1) - 1;
}
