int __cdecl xcptlookup(int a1, unsigned int a2)
{
  unsigned int v2; // esi@1

  v2 = a2;
  do
  {
    if ( *(_DWORD *)v2 == a1 )
      break;
    v2 += 12;
  }
  while ( a2 + 12 * dword_521574 > v2 );
  return (unsigned int)(*(_DWORD *)v2 - a1) < 1 ? v2 : 0;
}
