void __cdecl _initterm(unsigned int a1, unsigned int a2)
{
  unsigned int i; // esi@1

  for ( i = a1; a2 > i; i += 4 )
  {
    if ( *(_DWORD *)i )
      (*(void (**)(void))i)();
  }
}
