signed int __cdecl _callnewh(int a1)
{
  signed int result; // eax@3

  _lock(9);
  if ( dword_537D4C && dword_537D4C(a1) )
  {
    _unlock(9);
    result = 1;
  }
  else
  {
    _unlock(9);
    result = 0;
  }
  return result;
}
