{
  if ( a1 >= 20 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    _unlock(a1 + 28);
}