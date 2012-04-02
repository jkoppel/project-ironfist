void __cdecl _lock_file2(signed int a1, int a2)
{
  if ( a1 >= 20 )
    EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    _lock(a1 + 28);
}
