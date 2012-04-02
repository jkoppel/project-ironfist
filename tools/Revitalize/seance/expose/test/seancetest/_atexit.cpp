int __cdecl atexit(int a1)
{
  return -((unsigned int)_onexit(a1) < 1);
}
