int __cdecl fopen(char *a1, int a2)
{
  return _fsopen(a1, a2, 64);
}
