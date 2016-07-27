{
  if ( a1 >= 20 )
    EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    _lock(a1 + 28);
}
