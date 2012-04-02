signed int __cdecl _unwind_handler(int a1, int a2, int a3, int a4)
{
  signed int result; // eax@1

  result = 1;
  if ( *(_DWORD *)(a1 + 4) & 6 )
  {
    *(_DWORD *)a4 = a2;
    result = 3;
  }
  return result;
}
