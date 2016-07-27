{
  void *result; // eax@4

  if ( a3 == 101 || a3 == 69 )
  {
    result = (void *)_cftoe(a1, a2, a4, a5);
  }
  else
  {
    if ( a3 == 102 )
      result = _cftof(a1, (void *)a2, a4);
    else
      result = _cftog(a1, a2, a4, a5);
  }
  return result;
}
