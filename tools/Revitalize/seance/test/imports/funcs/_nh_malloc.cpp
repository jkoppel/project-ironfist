{
  DWORD v2; // esi@1
  int result; // eax@2

  v2 = dwBytes;
  if ( (unsigned int)dwBytes <= 0xFFFFFFE0 )
  {
    if ( !dwBytes )
      v2 = 1;
    while ( 1 )
    {
      result = _heap_alloc(v2);
      if ( result || !a2 )
        break;
      if ( !_callnewh(v2) )
        return 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
