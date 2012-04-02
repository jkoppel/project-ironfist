int __cdecl fflush(int a1)
{
  int result; // eax@2
  int v2; // edi@3

  if ( a1 )
  {
    _lock_file(a1);
    v2 = _fflush_lk(a1);
    _unlock_file(a1);
    result = v2;
  }
  else
  {
    result = flsall(0);
  }
  return result;
}
