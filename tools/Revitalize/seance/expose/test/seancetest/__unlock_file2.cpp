void __cdecl _unlock_file2(signed int a1, int a2)
{
  if ( a1 >= 20 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    _unlock(a1 + 28);
}
