{
  char result; // al@2

  if ( *(_WORD *)a3 <= a1 )
  {
    if ( *(_WORD *)a3 + (signed int)*(_WORD *)(a3 + 4) > a1 )
    {
      if ( *(_WORD *)(a3 + 2) <= a2 )
        result = *(_WORD *)(a3 + 6) + (signed int)*(_WORD *)(a3 + 2) > a2;
      else
        result = 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
