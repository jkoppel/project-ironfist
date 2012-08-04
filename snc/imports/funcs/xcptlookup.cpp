{
  unsigned int v2; // esi@1

  v2 = a2;
  do
  {
    if ( *(_DWORD *)v2 == a1 )
      break;
    v2 += 12;
  }
  while ( a2 + 12 * _XcptActTabCount > v2 );
  return (unsigned int)(*(_DWORD *)v2 - a1) < 1 ? v2 : 0;
}