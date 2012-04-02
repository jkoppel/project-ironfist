int _open(const char *a1, int a2, ...)
{
  va_start(va, a2);
  return _sopen(a1, a2, 64, *(int *)va);
}
