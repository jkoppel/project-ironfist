{
  signed int result; // eax@3

  _lock(9);
  if ( _pnhHeap && _pnhHeap(a1) )
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