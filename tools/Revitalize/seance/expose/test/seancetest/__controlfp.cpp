unsigned int __cdecl _controlfp(unsigned int a1, int a2)
{
  return _control87(a1, a2 & 0xFFF7FFFF);
}
